#ifndef XML_H
#define XML_H

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

#define XML_FILE "file.xml"

class Xml
{
public:
    Xml();
    int parse_xml(xmlDocPtr doc, xmlNodePtr cur);
    int parse_book(const char *filename);
};

#endif // XML_H
