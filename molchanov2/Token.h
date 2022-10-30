#include <vector>
#include <cctype>
#include <locale>
#include <iostream>
#include <regex>
#include <algorithm>
#pragma once

public enum TOKEN
{
	TKN_UNKNOWN,
	TKN_NONE,
	TKN_ERROR_COMMENT_NOT_CLOSED,
	TKN_ERROR_BRACKET_DONT_CLOSE,
	TKN_VAR,
	TKN_SPLITTER,
	TKN_NUMBER,
	TKN_ASSIGN,
	TKN_ADD,
	TKN_SUB,
	TKN_MUL,
	TKN_DIV,
	TKN_BRACKET_OPEN,
	TKN_BRACKET_CLOSE,
	TKN_COMMENT_OPEN,
	TKN_COMMENT_CLOSE
};


public struct TokenNode
{
public:
	TOKEN type;
	std::string value;
	std::vector<TokenNode> child;
	TokenNode() {}
	TokenNode(TOKEN _type) {
		type = _type;
	}
	TokenNode(TOKEN _type, TokenNode firstChild) {
		type = _type;
		child.push_back(firstChild);
	}
	TokenNode(TOKEN _type, std::string _value) {
		type = _type;
		value = _value;
	}
	TokenNode(TOKEN _type, char _value) : TokenNode(_type, std::string(1, _value))
	{

	}
	std::string getString() {
		std::string s = "";
		if (child.size() > 0)
		{
			for each(TokenNode t in child)
			{
				s += t.getString();
			}
		}
		else
		{
			s += value;
		}
		return s;
	}
};

//tokenNode keys[] = { };
TokenNode spliters[] = { TokenNode(TKN_BRACKET_OPEN, '('), TokenNode(TKN_BRACKET_CLOSE, ')'), TokenNode(TKN_ASSIGN, ":="), TokenNode(TKN_SPLITTER, ';') };
TokenNode spaces[] = { TokenNode(TKN_NONE, '\r'), TokenNode(TKN_NONE, '\n'), TokenNode(TKN_NONE, ' ') };
TokenNode comments[] = { TokenNode(TKN_COMMENT_OPEN, '{'), TokenNode(TKN_COMMENT_CLOSE, '}') };
TokenNode operators[] = { TokenNode(TKN_ADD, '+'), TokenNode(TKN_SUB, '-'), TokenNode(TKN_MUL, '*'), TokenNode(TKN_DIV, '/') };


std::regex varRegex("^[a-z]+$");
std::regex numberRegex("^[0-9]*\.?[0-9]+(E[-+]?[0-9]+)?$");

std::string _toPrint(TOKEN token) {
	switch (token)
	{
	case TKN_UNKNOWN:
		return "ОШИБКА";
	case TKN_NONE:
		return "TKN_NONE";
	case TKN_ERROR_COMMENT_NOT_CLOSED:
		return "Ошибка: комментарий не закончен";
	case TKN_ERROR_BRACKET_DONT_CLOSE:
		return "Ошибка: скобка не закрыта";
	case TKN_VAR:
		return "Идентификатор";
	case TKN_SPLITTER:
		return "Разделитель выражений";
	case TKN_NUMBER:
		return "Число";
	case TKN_ASSIGN:
		return "Оператор присвоения";
	case TKN_ADD:
		return "Оператор сложения";
	case TKN_SUB:
		return "Оператор вычитания";
	case TKN_MUL:
		return "Оператор умножения";
	case TKN_DIV:
		return "Оператор деления";
	case TKN_BRACKET_OPEN:
		return "Открывающая скобка";
	case TKN_BRACKET_CLOSE:
		return "Закрывающая скобка";
	case TKN_COMMENT_OPEN:
		return "Знак начала комментария";
	case TKN_COMMENT_CLOSE:
		return "Знак конца комментария";
	default:
		return "ERROR";
	}
}

std::string _toPrint(TokenNode node) {
	return node.getString();
}

std::vector<TokenNode> sliceWith(std::vector<TokenNode> in, std::vector<TokenNode> splitters)
{
	std::vector<TokenNode> out;
	repeat:
	bool replaced = false;
	for each(TokenNode t in in)
	{
		if (t.type == TKN_UNKNOWN)
		{
			bool replacedLocal = false;
			for each (TokenNode s in splitters)
			{
				std::string tstr = t.getString();
				std::string sstr = s.getString();
				size_t pos = tstr.find(sstr);
				if (pos != std::string::npos)
				{
					std::string before = tstr.substr(0, pos);
					if (before.size() > 0)
					{
						out.push_back(TokenNode(TKN_UNKNOWN, before));
					}
					std::cout << pos << std::endl;
					out.push_back(s);
					std::string after = tstr.substr(pos + sstr.size());
					if (after.size() > 0)
					{
						out.push_back(TokenNode(TKN_UNKNOWN, after));
					}
					replaced = true;
					replacedLocal = true;
					if (replacedLocal)
					{
						break;
					}
				}
			}
			if (!replacedLocal)
			{
				out.push_back(t);
			}
		}
		else
		{
			out.push_back(t);
		}
	}
	if (replaced)
	{
		in = out;
		out.clear();
		goto repeat;
	}
	return in;
}

std::vector<TokenNode> comment(std::vector<TokenNode> in)
{
	std::vector<TokenNode> out;
	bool commentOpened = false;
	for each (TokenNode t in in)
	{
		if (t.type == TKN_COMMENT_OPEN)
		{
			if (!commentOpened)
			{
				commentOpened = true;
				out.push_back(t);
			}
		}
		else if (t.type == TKN_COMMENT_CLOSE)
		{
			if (commentOpened)
			{
				commentOpened = false;
			}
			else
			{
				t.type = TKN_UNKNOWN;
			}
			out.push_back(t);
		}
		else
		{
			if (!commentOpened)
			{
				out.push_back(t);
			}
		}
	}
	if (commentOpened)
	{
		out.push_back(TKN_ERROR_COMMENT_NOT_CLOSED);
	}
	return out;
}

std::vector<TokenNode> findWith(std::vector<TokenNode> in, std::vector<TokenNode> keys)
{
	std::vector<TokenNode> out;
	for each (TokenNode t in in)
	{
		if (t.type == TKN_UNKNOWN)
		{
			for each(TokenNode k in keys)
			{
				if (t.getString() == k.getString())
				{
					t.type = k.type;
				}
			}
		}
		out.push_back(t);
	}
	return out;
}

std::vector<TokenNode> varAndNumber(std::vector<TokenNode> in)
{
	std::vector<TokenNode> out;
	for each (TokenNode t in in)
	{
		if (t.type == TKN_UNKNOWN)
		{
			std::string str = t.getString();
			if (regex_match(str.begin(), str.end(), varRegex))
			{
				t.type = TKN_VAR;
			}
			if (regex_match(str.begin(), str.end(), numberRegex))
			{
				t.type = TKN_NUMBER;
			}
		}
		out.push_back(t);
	}
	return out;
}

std::vector<TokenNode> bracket(std::vector<TokenNode> in)
{
	std::vector<TokenNode> out;
	int bracketCount = 0;
	for each (TokenNode t in in)
	{
		if (t.type == TKN_BRACKET_OPEN)
		{
			bracketCount++;
		}
		else if (t.type == TKN_BRACKET_CLOSE)
		{
			if (bracketCount > 0)
			{
				bracketCount --;
			}
			else
			{
				t.type = TKN_UNKNOWN;
			}
		}
		else if (t.type == TKN_SPLITTER)
		{
			if (bracketCount > 0)
			{
				out.push_back(TKN_ERROR_BRACKET_DONT_CLOSE);
				bracketCount = 0;
			}
		}
		out.push_back(t);
	}
	if (bracketCount > 0)
	{
		out.push_back(TKN_ERROR_BRACKET_DONT_CLOSE);
	}
	return out;
}

std::vector<TokenNode> noSpace(std::vector<TokenNode> in)
{
	std::vector<TokenNode> out;
	for each (TokenNode t in in)
	{
		if (t.type != TKN_NONE)
		{
			out.push_back(t);
		}
	}
	return out;
}

std::vector<TokenNode> noDouble(std::vector<TokenNode> in, std::vector<TokenNode> keys)
{
	std::vector<TokenNode> out;
	std::vector<TOKEN> tkns;
	for each(TokenNode t in keys)
	{
		tkns.push_back(t.type);
	}
	for (int i = 0; i < in.size(); i++)
	{
		if (std::find(tkns.begin(), tkns.end(), in[i].type) != tkns.end())
		{
			std::string value = in[i].getString();
			bool hasNext = false;
			while (i < in.size() - 1)
			{
				if (std::find(tkns.begin(), tkns.end(), in[i + 1].type) != tkns.end())
				{
					value += in[i + 1].getString();
					i++;
					hasNext = true;
				}
				else
				{
					break;
				}
			}
			if (hasNext)
			{
				out.push_back(TokenNode(TKN_UNKNOWN, value));
			}
			else
			{
				out.push_back(in[i]);
			}
		}
		else
		{
			out.push_back(in[i]);
		}
	}
	return out;
}

std::vector<TokenNode> tokenize(std::string str) {
	std::vector<TokenNode> ret;
	ret.push_back(TokenNode(TKN_UNKNOWN, str));
	//Комментарии
	ret = sliceWith(ret, std::vector<TokenNode>(std::begin(comments), std::end(comments)));
	ret = comment(ret);
	//Разделители
	ret = sliceWith(ret, std::vector<TokenNode>(std::begin(spliters), std::end(spliters)));
	//Пробелы
	ret = sliceWith(ret, std::vector<TokenNode>(std::begin(spaces), std::end(spaces)));
	//Операторы
	ret = sliceWith(ret, std::vector<TokenNode>(std::begin(operators), std::end(operators)));
	//Ключевые слова
	//ret = findWith(ret, std::vector<TokenNode>(std::begin(keys), std::end(keys)));
	//Переменные и цифры
	ret = varAndNumber(ret);
	//Скобки
	ret = bracket(ret);
	//Удаление пробелов
	ret = noSpace(ret);
	//Запрет на двойные операторы
	ret = noDouble(ret, std::vector<TokenNode>(std::begin(operators), std::end(operators)));
	return ret;
}