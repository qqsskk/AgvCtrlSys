#pragma once
#include "tinyxml.h"
#include <Windows.h>
#include <map>
#include <vector>
#include <string>
using namespace std;

typedef struct
{
	vector<string> v_param;
}_STL_1VEC_PARAM, *_pSTL_1VEC_PARAM;

typedef struct
{
	vector<string> v_param;
	multimap<string, string> m_param;
}_STL_1MAP_PARAM, *_pSTL_1MAP_PARAM;

typedef struct
{
	vector<string> v_param;
	multimap<string, _STL_1MAP_PARAM> m_param;
}_STL_2MAP_PARAM, *_pSTL_2MAP_PARAM;

typedef struct
{
	vector<string> v_param;
	multimap<string, _STL_2MAP_PARAM> m_param;
}_STL_3MAP_PARAM, *_pSTL_3MAP_PARAM;

class CTinyxmlEngine
{
public:
	CTinyxmlEngine(void);
	virtual ~CTinyxmlEngine(void);

public:
	void Erase_Param_1AMP(_STL_1MAP_PARAM&m_param);
	void Erase_Param_2AMP(_STL_2MAP_PARAM&m_param);
	void Erase_Param_3AMP(_STL_3MAP_PARAM&m_param);

	bool Read_XML_Declaration(const char*pszPath, _STL_1MAP_PARAM& m_param);
	//ReadText
	bool Read_XML_1Floor_Text(const char*pszPath, _STL_1MAP_PARAM&m_param);
	bool Read_XML_1Floor_Text(const char*pszPath, const char*pszNode/*Floor1*/, _STL_1MAP_PARAM&m_param);//1MAP
	bool Read_XML_1Floor_Text(const char*pszPath, const char*pszNode/*Floor2*/, const char*pszNode1/*Floor1*/, _STL_1MAP_PARAM&m_param);//2MAP
	bool Read_XML_1Floor_Text(const char*pszPath, const char*pszNode/*Floor3*/, const char*pszNode1/*Floor2*/, const char*pszNode2/*Floor1*/, _STL_1MAP_PARAM&m_param);//3MAP

	bool Read_XML_2Floor_Text(const char*pszPath, _STL_2MAP_PARAM&m_param);//1MAP
	bool Read_XML_2Floor_Text(const char*pszPath, const char*pszNode/*Floor2*/, _STL_2MAP_PARAM&m_param);//2MAP
	bool Read_XML_2Floor_Text(const char*pszPath, const char*pszNode/*Floor3*/, const char*pszNode1/*Floor2*/, _STL_2MAP_PARAM&m_param);//3MAP

	bool Read_XML_3_Floor_Text(const char*pszPath, _STL_3MAP_PARAM&m_param);
	bool Read_XML_3_Floor_Text(const char*pszPath, const char*pszNode/*Floor3*/, _STL_3MAP_PARAM&m_param);

	//ReadAttr
	bool Read_XML_1Floor_Attr(const char*pszPath, const char*pszNode, _STL_1MAP_PARAM&m_param);
	bool Read_XML_1Floor_Attr(const char*pszPath, const char*pszNode, const char*pszNode1, _STL_1MAP_PARAM&m_param);
	bool Read_XML_1Floor_Attr(const char*pszPath, const char*pszNode, const char*pszNode1, const char*pszNode2, _STL_1MAP_PARAM&m_param);

	bool Read_XML_2Floor_Attr(const char*pszPath, _STL_2MAP_PARAM&m_param);
	bool Read_XML_2Floor_Attr(const char*pszPath, const char*pszNode, _STL_2MAP_PARAM&m_param);
	bool Read_XML_2Floor_Attr(const char*pszPath, const char*pszNode, const char*pszNode1, _STL_2MAP_PARAM&m_param);

	bool Read_XML_3Floor_Attr(const char*pszPath, _STL_3MAP_PARAM&m_param);
	bool Read_XML_3Floor_Attr(const char*pszPath, const char*pszNode, _STL_3MAP_PARAM&m_param);

};
