#include "TinyxmlEngine.h"

CTinyxmlEngine::CTinyxmlEngine(void)
{
}


CTinyxmlEngine::~CTinyxmlEngine(void)
{
}

void CTinyxmlEngine::Erase_Param_1AMP(_STL_1MAP_PARAM&m_param)
{
	m_param.v_param.clear();
	m_param.m_param.clear();
}

void CTinyxmlEngine::Erase_Param_2AMP(_STL_2MAP_PARAM&m_param)
{
	m_param.v_param.clear();
	m_param.m_param.clear();
}

void CTinyxmlEngine::Erase_Param_3AMP(_STL_3MAP_PARAM&m_param)
{
	m_param.v_param.clear();
	m_param.m_param.clear();
}

/*
<?xml version="1.0" encoding="utf-8" tandalone="yes"?>
*/
bool CTinyxmlEngine::Read_XML_Declaration(const char*pszPath, _STL_1MAP_PARAM& m_param)
{
	TiXmlDocument doc(pszPath);
	if (!doc.LoadFile())
	{
		return false;
	}
	TiXmlNode* pFirstNode = doc.FirstChild();
	if (pFirstNode != NULL)
	{
		TiXmlDeclaration *pXmlDecl = pFirstNode->ToDeclaration();
		if (pXmlDecl != NULL)
		{
			m_param.v_param.push_back("version");
			m_param.m_param.insert(make_pair("version", pXmlDecl->Version()));

			m_param.v_param.push_back("encoding");
			m_param.m_param.insert(make_pair("encoding", pXmlDecl->Encoding()));

			m_param.v_param.push_back("standalone");
			m_param.m_param.insert(make_pair("standalone", pXmlDecl->Standalone()));
		}
	}
	return true;
}

/************************************************************************/
/*	Read_XML_1Floor														*/
/************************************************************************/
/*
<FileRoot>
	<Text1>t1</Text1>
	<Text2>t2</Text2>
	...
</FileRoot>
*/
bool CTinyxmlEngine::Read_XML_1Floor_Text(const char*pszPath, _STL_1MAP_PARAM&m_param)
{
	TiXmlDocument doc(pszPath);
	if (!doc.LoadFile())
	{
		return false;
	}
	const char*pszXmlName, *pszXmlValue;
	TiXmlElement* p_root = doc.RootElement();
	for (TiXmlNode* p_node = p_root->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
	{
		pszXmlName = p_node->Value();
		pszXmlValue = p_node->ToElement()->GetText();
		if (NULL != pszXmlValue)
		{
			m_param.v_param.push_back(pszXmlName);
			m_param.m_param.insert(make_pair(pszXmlName, pszXmlValue));
		}
	}
	return true;
}
/*
<FileRoot>
	<Floor1>
		<Text1>t1</Text1>
		<Text2>t2</Text2>
	</Floor1>
	...
</FileRoot>
*/
bool CTinyxmlEngine::Read_XML_1Floor_Text(const char*pszPath, const char*pszNode, _STL_1MAP_PARAM&m_param)
{
	TiXmlDocument doc(pszPath);
	if (!doc.LoadFile())
	{
		return false;
	}
	const char*pszXmlValue, *pszXmlName;

	TiXmlElement*p_root = doc.RootElement();
	for (TiXmlNode*p_node = p_root->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
	{
		pszXmlName = p_node->Value();
		if (strcmp(pszXmlName, pszNode) == 0)
		{
			TiXmlElement*p_element = p_node->ToElement();
			for (TiXmlNode*p_node = p_element->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
			{
				pszXmlName = p_node->Value();
				pszXmlValue = p_node->ToElement()->GetText();
				if (NULL != pszXmlValue)
				{
					m_param.m_param.insert(map<string, string>::value_type(pszXmlName, pszXmlValue));
					m_param.v_param.push_back(pszXmlName);
				}
			}
			break;
		}
	}
	return true;
}
/*
<FileRoot>
	<Floor2>
		<Floor1_1>
			<Text1>t1</Text1>
			<Text2>t2</Text2>
		</Floor1_1>
		<Floor1_2>
			<Text1>t1</Text1>
			<Text2>t2</Text2>
		</Floor1_2>
	</Floor2>
	...
</FileRoot>
*/
bool CTinyxmlEngine::Read_XML_1Floor_Text(const char*pszPath, const char*pszNode, const char*pszNode1, _STL_1MAP_PARAM&m_param)
{
	_STL_2MAP_PARAM m_param2;
	if (Read_XML_2Floor_Text(pszPath, pszNode, m_param2))
	{
		map<string, _STL_1MAP_PARAM>::iterator it = m_param2.m_param.find(pszNode1);
		if (it != m_param2.m_param.end())
		{
			m_param = it->second;
		}
	}
	else
	{
		return false;
	}
	return true;
}
/*
<FileRoot>
	<Floor3>
		<Floor2_1>
			<Floor1_1>
				<Text1>t1</Text1>
				<Text2>t2</Text2>
			</Floor1_1>
			<Floor1_2>
				<Text1>t1</Text1>
				<Text2>t2</Text2>
			</Floor1_2>
		</Floor2_1>
		<Floor2_2>
			<Floor1_1>
				<Text1>t1</Text1>
				<Text2>t2</Text2>
			</Floor1_1>
			<Floor1_2>
				<Text1>t1</Text1>
				<Text2>t2</Text2>
			</Floor1_2>
		</Floor2_2>
	</Floor3>
	...
</FileRoot>
*/
bool CTinyxmlEngine::Read_XML_1Floor_Text(const char*pszPath, const char*pszNode, const char*pszNode1, const char*pszNode2, _STL_1MAP_PARAM&m_param)
{
	_STL_3MAP_PARAM m_param3;
	if (Read_XML_3_Floor_Text(pszPath, pszNode, m_param3))
	{
		map<string, _STL_2MAP_PARAM>::iterator it = m_param3.m_param.find(pszNode1);
		if (it != m_param3.m_param.end())
		{
			_STL_2MAP_PARAM m_param2;
			m_param2 = it->second;
			map<string, _STL_1MAP_PARAM>::iterator it1 = m_param2.m_param.find(pszNode2);
			if (it1 != m_param2.m_param.end())
			{
				m_param = it1->second;
			}
		}
	}
	if (m_param.v_param.empty())
	{
		return false;
	}
	return true;
}
/*
<FileRoot>
	<Floor1>
		<Text1>t1</Text1>
		<Text2>t2</Text2>
	</Floor1>
</FileRoot>
*/
bool CTinyxmlEngine::Read_XML_2Floor_Text(const char*pszPath, _STL_2MAP_PARAM&m_param)
{
	TiXmlDocument doc(pszPath);
	if (!doc.LoadFile())
	{
		return false;
	}
	_STL_1MAP_PARAM m_param1;
	const char*pszXmlValue, *pszXmlName1, *pszXmlName2;

	TiXmlElement*p_root = doc.RootElement();
	for (TiXmlNode*p_node = p_root->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
	{
		pszXmlName1 = p_node->Value();
		TiXmlElement*p_element = p_node->ToElement();
		m_param1.m_param.clear();
		m_param1.v_param.clear();
		for (TiXmlNode*p_node = p_element->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
		{
			pszXmlName2 = p_node->Value();
			pszXmlValue = p_node->ToElement()->GetText();
			if (NULL != pszXmlValue)
			{
				m_param1.v_param.push_back(pszXmlName2);
				m_param1.m_param.insert(map<string, string>::value_type(pszXmlName2, pszXmlValue));
			}
		}
		if (!m_param1.v_param.empty())
		{
			m_param.v_param.push_back(pszXmlName1);
			m_param.m_param.insert(map<string, _STL_1MAP_PARAM>::value_type(pszXmlName1, m_param1));
		}
	}
	return true;
}
/*
<FileRoot>
	<Floor2>
		<Floor1_1>
			<Text1>t1</Text1>
			<Text2>t2</Text2>
		</Floor1_1>
		<Floor1_2>
			<Text1>t1</Text1>
			<Text2>t2</Text2>
		</Floor1_2>
	</Floor2>
	...
</FileRoot>
*/
bool CTinyxmlEngine::Read_XML_2Floor_Text(const char*pszPath, const char*pszNode, _STL_2MAP_PARAM&m_param)
{
	TiXmlDocument doc(pszPath);
	if (!doc.LoadFile())
	{
		return false;
	}
	_STL_1MAP_PARAM m_param1;
	const char*pszXmlValue, *pszXmlName1, *pszXmlName2;

	TiXmlElement*p_root = doc.RootElement();
	for (TiXmlNode*p_node = p_root->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
	{
		pszXmlName1 = p_node->Value();
		if (strcmp(pszXmlName1, pszNode) == 0)
		{
			TiXmlElement*p_element = p_node->ToElement();
			for (TiXmlNode*p_node = p_element->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
			{
				pszXmlName1 = p_node->Value();
				TiXmlElement*p_element = p_node->ToElement();
				m_param1.m_param.clear();
				m_param1.v_param.clear();
				for (TiXmlNode*p_node = p_element->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
				{
					pszXmlName2 = p_node->Value();
					pszXmlValue = p_node->ToElement()->GetText();
					if (NULL != pszXmlValue)
					{
						m_param1.v_param.push_back(pszXmlName2);
						m_param1.m_param.insert(multimap<string, string>::value_type(pszXmlName2, pszXmlValue));
					}
				}
				if (!m_param1.v_param.empty())
				{
					m_param.v_param.push_back(pszXmlName1);
					m_param.m_param.insert(multimap<string, _STL_1MAP_PARAM>::value_type(pszXmlName1, m_param1));
				}
			}
			break;
		}
	}
	return true;
}
/*
<FileRoot>
	<Floor3>
		<Floor2_1>
			<Floor1_1>
				<Text1>t1</Text1>
				<Text2>t2</Text2>
			</Floor1_1>
			<Floor1_2>
				<Text1>t1</Text1>
				<Text2>t2</Text2>
			</Floor1_2>
		</Floor2_1>
		<Floor2_2>
			<Floor1_1>
				<Text1>t1</Text1>
				<Text2>t2</Text2>
			</Floor1_1>
			<Floor1_2>
				<Text1>t1</Text1>
				<Text2>t2</Text2>
			</Floor1_2>
		</Floor2_2>
	</Floor3>
	...
</FileRoot>
*/
bool CTinyxmlEngine::Read_XML_2Floor_Text(const char*pszPath, const char*pszNode/*Floor3*/, const char*pszNode1/*Floor2*/, _STL_2MAP_PARAM&m_param)
{
	_STL_3MAP_PARAM m_param3;
	if (Read_XML_3_Floor_Text(pszPath, pszNode, m_param3))
	{
		map<string, _STL_2MAP_PARAM>::iterator it = m_param3.m_param.find(pszNode1);
		if (it != m_param3.m_param.end())
		{
			m_param = it->second;
		}
	}
	if (!m_param.v_param.empty())
	{
		return false;
	}
	return true;
}
/*
<FileRoot>
	<Floor2>
		<Floor1_1>
			<Text1>t1</Text1>
			<Text2>t2</Text2>
		</Floor1_1>
		<Floor1_2>
			<Text1>t1</Text1>
			<Text2>t2</Text2>
		</Floor1_2>
	</Floor2>
</FileRoot>
*/
bool CTinyxmlEngine::Read_XML_3_Floor_Text(const char*pszPath, _STL_3MAP_PARAM&m_param)
{
	TiXmlDocument doc(pszPath);
	if (!doc.LoadFile())
	{
		return false;
	}
	_STL_1MAP_PARAM m_param1;
	_STL_2MAP_PARAM m_param2;
	const char*pszXmlValue, *pszXmlName1, *pszXmlName2, *pszXmlName3;

	TiXmlElement*p_root = doc.RootElement();
	for (TiXmlNode*p_node = p_root->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
	{
		pszXmlName1 = p_node->Value();
		TiXmlElement*p_element = p_node->ToElement();
		m_param2.m_param.clear();
		m_param2.v_param.clear();
		for (TiXmlNode*p_node = p_element->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
		{
			pszXmlName2 = p_node->Value();
			TiXmlElement*p_element = p_node->ToElement();
			m_param1.m_param.clear();
			m_param1.v_param.clear();
			for (TiXmlNode*p_node = p_element->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
			{
				pszXmlName3 = p_node->Value();
				pszXmlValue = p_node->ToElement()->GetText();
				if (NULL != pszXmlValue)
				{
					m_param1.v_param.push_back(pszXmlName3);
					m_param1.m_param.insert(map<string, string>::value_type(pszXmlName3, pszXmlValue));
				}
			}
			if (!m_param1.v_param.empty())
			{
				m_param2.v_param.push_back(pszXmlName2);
				m_param2.m_param.insert(map<string, _STL_1MAP_PARAM>::value_type(pszXmlName2, m_param1));
			}
		}
		if (!m_param2.v_param.empty())
		{
			m_param.v_param.push_back(pszXmlName1);
			m_param.m_param.insert(map<string, _STL_2MAP_PARAM>::value_type(pszXmlName1, m_param2));
		}
	}
	return true;
}
/*
<FileRoot>
	<Floor3>
		<Floor2_1>
			<Floor1_1>
				<Text1>t1</Text1>
				<Text2>t2</Text2>
			</Floor1_1>
			<Floor1_2>
				<Text1>t1</Text1>
				<Text2>t2</Text2>
			</Floor1_2>
		</Floor2_1>
		<Floor2_2>
			<Floor1_1>
				<Text1>t1</Text1>
				<Text2>t2</Text2>
			</Floor1_1>
			<Floor1_2>
				<Text1>t1</Text1>
				<Text2>t2</Text2>
			</Floor1_2>
		</Floor2_2>
	</Floor3>
	...
</FileRoot>
*/
bool CTinyxmlEngine::Read_XML_3_Floor_Text(const char*pszPath, const char*pszNode/*Floor3*/, _STL_3MAP_PARAM&m_param)
{
	TiXmlDocument doc(pszPath);
	if (!doc.LoadFile())
	{
		return false;
	}
	_STL_1MAP_PARAM m_param1;
	_STL_2MAP_PARAM m_param2;
	const char*pszXmlValue, *pszXmlName1, *pszXmlName2, *pszXmlName3;

	TiXmlElement*p_root = doc.RootElement();
	for (TiXmlNode*p_node = p_root->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
	{
		pszXmlName1 = p_node->Value();
		if (strcmp(pszXmlName1, pszNode) == 0)
		{
			TiXmlElement*p_element = p_node->ToElement();
			for (TiXmlNode*p_node = p_element->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
			{
				pszXmlName1 = p_node->Value();
				TiXmlElement*p_element = p_node->ToElement();
				m_param2.m_param.clear();
				m_param2.v_param.clear();
				for (TiXmlNode*p_node = p_element->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
				{
					pszXmlName2 = p_node->Value();
					TiXmlElement*p_element = p_node->ToElement();
					m_param1.m_param.clear();
					m_param1.v_param.clear();
					for (TiXmlNode*p_node = p_element->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
					{
						pszXmlName3 = p_node->Value();
						pszXmlValue = p_node->ToElement()->GetText();
						if (NULL != pszXmlValue)
						{
							m_param1.v_param.push_back(pszXmlName3);
							m_param1.m_param.insert(map<string, string>::value_type(pszXmlName3, pszXmlValue));
						}
					}
					if (!m_param1.v_param.empty())
					{
						m_param2.v_param.push_back(pszXmlName2);
						m_param2.m_param.insert(map<string, _STL_1MAP_PARAM>::value_type(pszXmlName2, m_param1));
					}
				}
				if (!m_param2.v_param.empty())
				{
					m_param.v_param.push_back(pszXmlName1);
					m_param.m_param.insert(map<string, _STL_2MAP_PARAM>::value_type(pszXmlName1, m_param2));
				}
			}
			break;
		}
	}
	return true;
}

/************************************************************************/
/*	Read XML Attribute													*/
/************************************************************************/
/*
<FileRoot>
	<Attr1 ip="192.168.0.1" timeout="123.456000"/>
	<Attr2 ip="192.168.0.1" timeout="123.456000"/>
</FileRoot>
*/
bool CTinyxmlEngine::Read_XML_1Floor_Attr(const char*pszPath, const char*pszNode, _STL_1MAP_PARAM&m_param)
{
	TiXmlDocument doc(pszPath);
	if (!doc.LoadFile())
	{
		return false;
	}
	const char*pszXmlName, *pszXmlValue;
	TiXmlElement* p_root = doc.RootElement();
	for (TiXmlNode*p_node = p_root->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
	{
		pszXmlName = p_node->Value();
		if (strcmp(pszXmlName, pszNode) == 0)
		{
			TiXmlElement*p_element = p_node->ToElement();
			for (TiXmlAttribute*p_attribute = p_element->FirstAttribute(); p_attribute; p_attribute = p_attribute->Next())
			{
				pszXmlName = p_attribute->Name();
				pszXmlValue = p_attribute->Value();
				if (NULL != pszXmlValue)
				{
					m_param.v_param.push_back(pszXmlName);
					m_param.m_param.insert(map<string, string>::value_type(pszXmlName, pszXmlValue));
				}
			}
			break;
		}
	}
	return true;
}
/*
<FileRoot>
	<Attr_1Floor>
		<Attr1 name="Attr1" x="5" y="15" w="400" h="250"/>
		<Attr2 name="Attr2" x="5" y="15" w="400" h="250"/>
	</Attr_1Floor>
	...
	...
</FileRoot>
*/
bool CTinyxmlEngine::Read_XML_1Floor_Attr(const char*pszPath, const char*pszNode/*Attr_1Floor*/, const char*pszNode1/*Attr1*/, _STL_1MAP_PARAM&m_param)
{
	TiXmlDocument doc(pszPath);
	if (!doc.LoadFile())
	{
		return false;
	}
	const char*pszXmlName, *pszXmlValue, *pszXmlName1;
	TiXmlElement* p_root = doc.RootElement();
	for (TiXmlNode* p_node = p_root->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
	{
		pszXmlName = p_node->Value();
		if (strcmp(pszXmlName, pszNode) == 0)
		{
			TiXmlElement* p_element = p_node->ToElement();
			for (TiXmlNode*p_node = p_element->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
			{
				pszXmlName = p_node->Value();
				if (strcmp(pszXmlName, pszNode1) == 0)
				{
					TiXmlElement*p_element = p_node->ToElement();
					for (TiXmlAttribute* p_attribute = p_element->FirstAttribute(); p_attribute; p_attribute = p_attribute->Next())
					{
						pszXmlName1 = p_attribute->Name();
						pszXmlValue = p_attribute->Value();
						if (pszXmlValue != NULL)
						{
							m_param.v_param.push_back(pszXmlName1);
							m_param.m_param.insert(make_pair(pszXmlName1, pszXmlValue));
						}
					}
				}
			}
		}
	}
	return true;
}
/*
<FileRoot>
	<Floor2>
		<Attr_1Floor>
			<Attr1 name="Attr1" x="5" y="15" w="400" h="250"/>
			<Attr2 name="Attr2" x="5" y="15" w="400" h="250"/>
		</Attr_1Floor>
	</Floor2>
	...
	...
</FileRoot>
*/
bool CTinyxmlEngine::Read_XML_1Floor_Attr(const char*pszPath, const char*pszNode/*Floor2*/, const char*pszNode1/*Attr_1Floor*/, const char*pszNode2/*Attr1*/, _STL_1MAP_PARAM&m_param)
{
	TiXmlDocument doc(pszPath);
	if (!doc.LoadFile())
	{
		return false;
	}
	const char*pszXmlName, *pszXmlValue, *pszXmlName1;
	TiXmlElement* p_root = doc.RootElement();
	for (TiXmlNode* p_node = p_root->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
	{
		pszXmlName = p_node->Value();
		if (strcmp(pszXmlName, pszNode) == 0)
		{
			TiXmlElement* p_element = p_node->ToElement();
			for (TiXmlNode*p_node = p_element->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
			{
				pszXmlName = p_node->Value();
				if (strcmp(pszXmlName, pszNode1) == 0)
				{
					TiXmlElement* p_element = p_node->ToElement();
					for (TiXmlNode*p_node = p_element->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
					{
						pszXmlName = p_node->Value();
						if (strcmp(pszXmlName, pszNode2) == 0)
						{
							TiXmlElement*p_element = p_node->ToElement();
							for (TiXmlAttribute* p_attribute = p_element->FirstAttribute(); p_attribute; p_attribute = p_attribute->Next())
							{
								pszXmlName1 = p_attribute->Name();
								pszXmlValue = p_attribute->Value();
								if (pszXmlValue != NULL)
								{
									m_param.v_param.push_back(pszXmlName1);
									m_param.m_param.insert(make_pair(pszXmlName1, pszXmlValue));
								}
							}
						}
					}
				}
			}
		}
	}
	return true;
}
/*
<FileRoot>
	<Attr1 ip="192.168.0.1" timeout="123.456000"/>
	<Attr2 ip="192.168.0.1" timeout="123.456000"/>
</FileRoot>
*/
bool CTinyxmlEngine::Read_XML_2Floor_Attr(const char*pszPath, _STL_2MAP_PARAM&m_param)
{
	TiXmlDocument doc(pszPath);
	if (!doc.LoadFile())
	{
		return false;
	}
	const char*pszXmlName, *pszXmlValue, *pszXmlName1;
	_STL_1MAP_PARAM m_param1;
	TiXmlElement* p_root = doc.RootElement();
	for (TiXmlNode* p_node = p_root->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
	{
		pszXmlName = p_node->Value();
		if (pszXmlName != NULL)
		{
			TiXmlElement* p_element = p_node->ToElement();
			m_param1.m_param.clear();
			m_param1.v_param.clear();
			for (TiXmlAttribute* p_attribute = p_element->FirstAttribute(); p_attribute; p_attribute = p_attribute->Next())
			{
				pszXmlName1 = p_attribute->Name();
				pszXmlValue = p_attribute->Value();
				if (pszXmlValue != NULL)
				{
					m_param1.v_param.push_back(pszXmlName1);
					m_param1.m_param.insert(make_pair(pszXmlName1, pszXmlValue));
				}
			}
			if (!m_param1.v_param.empty())
			{
				m_param.v_param.push_back(pszXmlName);
				m_param.m_param.insert(make_pair(pszXmlName, m_param1));
			}
		}
	}
	return true;
}
/*
<FileRoot>
	<Attr_1Floor>
		<Attr1 name="Attr1" x="5" y="15" w="400" h="250"/>
		<Attr2 name="Attr2" x="5" y="15" w="400" h="250"/>
	</Attr_1Floor>
	...
	...
</FileRoot>
*/
bool CTinyxmlEngine::Read_XML_2Floor_Attr(const char*pszPath, const char*pszNode, _STL_2MAP_PARAM&m_param)
{
	TiXmlDocument doc(pszPath);
	if (!doc.LoadFile())
	{
		return false;
	}
	const char*pszXmlName, *pszXmlValue, *pszXmlName1;
	_STL_1MAP_PARAM m_param1;
	TiXmlElement* p_root = doc.RootElement();
	for (TiXmlNode*p_node = p_root->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
	{
		pszXmlName = p_node->Value();
		if (strcmp(pszXmlName, pszNode) == 0)
		{
			TiXmlElement*p_element = p_node->ToElement();
			for (TiXmlNode*p_node = p_element->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
			{
				pszXmlName = p_node->Value();
				TiXmlElement*p_element = p_node->ToElement();
				m_param1.m_param.clear();
				m_param1.v_param.clear();
				for (TiXmlAttribute*p_attribute = p_element->FirstAttribute(); p_attribute; p_attribute = p_attribute->Next())
				{
					pszXmlName1 = p_attribute->Name();
					pszXmlValue = p_attribute->Value();
					if (NULL != pszXmlValue)
					{
						m_param1.v_param.push_back(pszXmlName1);
						m_param1.m_param.insert(map<string, string>::value_type(pszXmlName1, pszXmlValue));
					}
				}
				if (!m_param1.v_param.empty())
				{
					m_param.v_param.push_back(pszXmlName);
					m_param.m_param.insert(map<string, _STL_1MAP_PARAM>::value_type(pszXmlName, m_param1));
				}
			}
			break;
		}
	}
	return true;
}
/*
<FileRoot>
	<Floor2>
		<Attr_1Floor>
			<Attr1 name="Attr1" x="5" y="15" w="400" h="250"/>
			<Attr2 name="Attr2" x="5" y="15" w="400" h="250"/>
		</Attr_1Floor>
	</Floor2>
	...
	...
</FileRoot>
*/
bool CTinyxmlEngine::Read_XML_2Floor_Attr(const char*pszPath, const char*pszNode/*Floor2*/, const char*pszNode1/*Attr_1Floor*/, _STL_2MAP_PARAM&m_param)
{
	TiXmlDocument doc(pszPath);
	if (!doc.LoadFile())
	{
		return false;
	}
	const char*pszXmlName, *pszXmlValue, *pszXmlName1;
	_STL_1MAP_PARAM m_param1;
	TiXmlElement* p_root = doc.RootElement();
	for (TiXmlNode*p_node = p_root->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
	{
		pszXmlName = p_node->Value();
		if (strcmp(pszXmlName, pszNode) == 0)
		{
			TiXmlElement*p_element = p_node->ToElement();
			for (TiXmlNode*p_node = p_element->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
			{
				pszXmlName = p_node->Value();
				if (strcmp(pszXmlName, pszNode1) == 0)
				{
					TiXmlElement*p_element = p_node->ToElement();
					for (TiXmlNode*p_node = p_element->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
					{
						pszXmlName = p_node->Value();
						TiXmlElement*p_element = p_node->ToElement();
						m_param1.m_param.clear();
						m_param1.v_param.clear();
						for (TiXmlAttribute*p_attribute = p_element->FirstAttribute(); p_attribute; p_attribute = p_attribute->Next())
						{
							pszXmlName1 = p_attribute->Name();
							pszXmlValue = p_attribute->Value();
							if (NULL != pszXmlValue)
							{
								m_param1.v_param.push_back(pszXmlName1);
								m_param1.m_param.insert(map<string, string>::value_type(pszXmlName1, pszXmlValue));
							}
						}
						if (!m_param1.v_param.empty())
						{
							m_param.v_param.push_back(pszXmlName);
							m_param.m_param.insert(map<string, _STL_1MAP_PARAM>::value_type(pszXmlName, m_param1));
						}
					}
				}
			}
			break;
		}
	}
	return true;
}
/*
<FileRoot>
	<Attr_1Floor>
		<Attr1 name="Attr1" x="5" y="15" w="400" h="250"/>
		<Attr2 name="Attr2" x="5" y="15" w="400" h="250"/>
	</Attr_1Floor>
	...
	...
</FileRoot>
*/
bool CTinyxmlEngine::Read_XML_3Floor_Attr(const char*pszPath, _STL_3MAP_PARAM&m_param)
{
	TiXmlDocument doc(pszPath);
	if (!doc.LoadFile())
	{
		return false;
	}
	const char*pszXmlName, *pszXmlValue, *pszXmlName1, *pszXmlName2;
	_STL_1MAP_PARAM m_param1;
	_STL_2MAP_PARAM m_param2;
	TiXmlElement* p_root = doc.RootElement();
	for (TiXmlNode*p_node = p_root->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
	{
		pszXmlName = p_node->Value();
		TiXmlElement*p_element = p_node->ToElement();
		m_param2.m_param.clear();
		m_param2.v_param.clear();
		for (TiXmlNode*p_node = p_element->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
		{
			pszXmlName1 = p_node->Value();
			TiXmlElement*p_element = p_node->ToElement();
			m_param1.m_param.clear();
			m_param1.v_param.clear();
			for (TiXmlAttribute*p_attribute = p_element->FirstAttribute(); p_attribute; p_attribute = p_attribute->Next())
			{
				pszXmlName2 = p_attribute->Name();
				pszXmlValue = p_attribute->Value();
				if (NULL != pszXmlValue)
				{
					m_param1.v_param.push_back(pszXmlName2);
					m_param1.m_param.insert(map<string, string>::value_type(pszXmlName2, pszXmlValue));
				}
			}
			if (!m_param1.v_param.empty())
			{
				m_param2.v_param.push_back(pszXmlName1);
				m_param2.m_param.insert(map<string, _STL_1MAP_PARAM>::value_type(pszXmlName1, m_param1));
			}
		}
		if (!m_param2.v_param.empty())
		{
			m_param.v_param.push_back(pszXmlName);
			m_param.m_param.insert(map<string, _STL_2MAP_PARAM>::value_type(pszXmlName, m_param2));
		}
	}
	return true;
}
/*
<FileRoot>
	<Floor2>
		<Attr_1Floor>
			<Attr1 name="Attr1" x="5" y="15" w="400" h="250"/>
			<Attr2 name="Attr2" x="5" y="15" w="400" h="250"/>
		</Attr_1Floor>
	</Floor2>
	...
	...
</FileRoot>
*/
bool CTinyxmlEngine::Read_XML_3Floor_Attr(const char*pszPath, const char*pszNode/*Floor2*/, _STL_3MAP_PARAM&m_param)
{
	TiXmlDocument doc(pszPath);
	if (!doc.LoadFile())
	{
		return false;
	}
	const char*pszXmlName, *pszXmlValue, *pszXmlName1, *pszXmlName2;
	_STL_1MAP_PARAM m_param1;
	_STL_2MAP_PARAM m_param2;
	TiXmlElement* p_root = doc.RootElement();
	for (TiXmlNode*p_node = p_root->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
	{
		pszXmlName = p_node->Value();
		if (strcmp(pszXmlName, pszNode) == 0)
		{
			TiXmlElement *p_element = p_node->ToElement();
			for (TiXmlNode*p_node = p_element->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
			{
				TiXmlElement*p_element = p_node->ToElement();
				m_param2.m_param.clear();
				m_param2.v_param.clear();
				for (TiXmlNode*p_node = p_element->FirstChildElement(); p_node; p_node = p_node->NextSiblingElement())
				{
					pszXmlName1 = p_node->Value();
					TiXmlElement*p_element = p_node->ToElement();
					m_param1.m_param.clear();
					m_param1.v_param.clear();
					for (TiXmlAttribute*p_attribute = p_element->FirstAttribute(); p_attribute; p_attribute = p_attribute->Next())
					{
						pszXmlName2 = p_attribute->Name();
						pszXmlValue = p_attribute->Value();
						if (NULL != pszXmlValue)
						{
							m_param1.v_param.push_back(pszXmlName2);
							m_param1.m_param.insert(map<string, string>::value_type(pszXmlName2, pszXmlValue));
						}
					}
					if (!m_param1.v_param.empty())
					{
						m_param2.v_param.push_back(pszXmlName1);
						m_param2.m_param.insert(map<string, _STL_1MAP_PARAM>::value_type(pszXmlName1, m_param1));
					}
				}
				if (!m_param2.v_param.empty())
				{
					m_param.v_param.push_back(pszXmlName);
					m_param.m_param.insert(map<string, _STL_2MAP_PARAM>::value_type(pszXmlName, m_param2));
				}
			}
		}
	}
	return true;
}
