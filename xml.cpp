#include "xml.h"
#include <QDebug>

Xml::Xml()
{

}

int Xml::parse_xml(xmlDocPtr doc, xmlNodePtr cur)
{
    xmlChar *key;
    char *str;
    cur = cur->xmlChildrenNode;
    while(cur != NULL){
        if(xmlStrcmp(cur->name, (const xmlChar *)"rawtext") == 0){
            key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            str = (char *)key;
            qDebug() << "name: " << key;
            if(!strcmp(str, "进入家电控制")) return 1;
            else if(!strcmp(str, "进入环境检测")) return 2;
            else if(!strcmp(str, "进入视频监控")) return 3;
            else if(!strcmp(str, "返回菜单")) return 4;
            else if(!strcmp(str, "打开客厅灯")) return 5;
            else if(!strcmp(str, "关闭客厅灯")) return 6;
            else if(!strcmp(str, "打开卧室灯")) return 7;
            else if(!strcmp(str, "关闭卧室灯")) return 8;
            else return 0;
            xmlFree(key);
        }
        cur = cur->next;
    }
    return 0;
}

int Xml::parse_book(const char *filename)
{
    int flag = 0;
    xmlDocPtr doc;
    xmlNodePtr cur;

    doc = xmlParseFile(filename);
    if(doc == NULL){
        qDebug() << "failed to parse xml file";
        goto FAILED;
    }

    cur = xmlDocGetRootElement(doc);
    if(cur == NULL){
        qDebug() << "root is empty";
        goto FAILED;
    }
    flag = parse_xml(doc, cur);
    xmlFreeDoc(doc);
    return flag;

FAILED:
    if(doc) xmlFreeDoc(doc);
    return -1;
}


