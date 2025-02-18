/*
 * iqjson.h
 *
 *  Created on: 25-May-2014
 *      Author: sachin
 */

#ifndef IQJSON_H_
#define IQJSON_H_

//#include "bangdb.h"
#include <iostream>
#include <string.h>

namespace bangdb
{

enum bangdb_json_data_type
{
	NULLTYPE = 0,
	FALSETYPE = 1,
	TRUETYPE = 2,
	OBJECTTYPE = 3,
	ARRAYTYPE = 4,
	STRINGTYPE = 5,
	NUMBERTYPE = 6,
	INTTYPE = 7,
	UINTTYPE = 8,
	LONGTYPE = 9,
	ULONGTYPE = 10,
	DOUBLETYPE = 11,
	BOOLTYPE = 12,
	INVALIDTYPE = 13,
};
struct query_value;
class iqjson
{
public:
	virtual void reset() = 0;

	virtual void setJson(char *_json) = 0;

	virtual bool parseOutPlace(char *_json) = 0;

	virtual bool parseInPlace(char jbuf[]) = 0;

	virtual char* getValueString(const char *key, int *len) = 0;

	virtual bool getValueLength(char *key, int *val) = 0;

	virtual bool getValueLong(const char *key, long *val) = 0;

	virtual bool getValueULong(char *key, unsigned long *val) = 0;

	virtual bool getValueDouble(char *key, double *val) = 0;

	virtual bool getValueInt(char *key, int *val) = 0;

	virtual bool getValueUInt(char *key, unsigned int *val) = 0;

	virtual bool getValueBool(char *key, bool *val) = 0;

	virtual int getArraySize(void *arr) = 0;

	virtual int getSize() = 0;

	virtual bangdb_json_data_type getElementType(void *e) = 0;

	virtual void getArrayElement(void *arr, int idx, const char *key , query_value *jval) = 0;

	virtual void getObjectElement(void *obj, char *key, query_value *jval) = 0;

	virtual bangdb_json_data_type getValue(const char *key, void **val, unsigned int *len) = 0;

	virtual bangdb_json_data_type getNestedValueVA(void **name, unsigned int *l, char *obj, ...) = 0;

	virtual bangdb_json_data_type getNestedValue(char *keys[], int nkeys, void **name, unsigned int *l) = 0;

	virtual void createNewDoc() = 0;

	virtual void addMemberNumber(char *key) = 0;

	virtual void setMemberNumber(char *key, double val) = 0;

	virtual void addMemberString(char *key) = 0;

	virtual void setMemberString(char *key, char *val, bool copy=false) = 0;

	virtual void addMember(char *key, char *val, bool copy=false) = 0;

	virtual void addMember(char *key, double val) = 0;

	virtual void addMember(char *key, long val) = 0;

	virtual void addObject(char *key) = 0;

	virtual void addObjectToObject(char *obj, char *key) = 0;

	virtual void addKeyValueToObject(char *objname, char *key, char *val, bool copy=false) = 0;

	virtual void addKeyToObject(char *objname, char *key) = 0;

	virtual void setValueToObject(char *objname, char *key, char *val, bool copy=false) = 0;

	virtual void addEmptyArray(char *key) = 0;

	virtual void addEmptyArrayToObject(char *objname, char *key) = 0;

	//void* is Value
	//virtual void pushObjectToObject(char *obj1, void *obj2) = 0;

	virtual void pushToArray(char *arr, char *val, bool copy) = 0;

	virtual void pushToArray(char *arr, double val) = 0;

	virtual void pushArrayToObject(char *objname, char *arr, char *val, bool copy=false) = 0;

	virtual void pushArrayToObject(char *objname, char *arr, double val) = 0;

	virtual int getArrSize(char *arrname) = 0;

	virtual int getArrSize(char *obj, char *arrname) = 0;

	virtual const char *getString() = 0;

	virtual const char *getString(void *val_arr) = 0;

	virtual const char *getString(void *val_arr, int idx) = 0;

	virtual char *getNewString() = 0;

	virtual bangdb_json_data_type getType(const char *keyName) = 0;

	virtual bangdb_json_data_type getValueType(void *_value) = 0;

	virtual bangdb_json_data_type getBaseType(char *keyName) = 0;

	virtual bool hasMember(char *key) = 0;

	virtual void print() = 0;

	virtual void print(void *val) = 0;

	virtual void print(void *val_arr, int idx) = 0;

	virtual ~iqjson() { }
};

class iqjson_object
{
public:

	virtual void addMember(char *key, char *val, bool copy=false) = 0;

	virtual void addMember(char *key, char *val, int vallen, bool copy=false) = 0;

	virtual void addMember(char *key, double val) = 0;

	virtual void addMember(char *key, long val) = 0;

#ifdef _MAC_OS_COMPILE_
	//just for compile under mac
	void addMember(char *key, long val);
#endif

	virtual void putObject(char *name) = 0;

	virtual void putObjectToObject(char *objname, char *obj) = 0;

	virtual void putObjectToObjects(char *objname, char *obj, ...) = 0;

	virtual void pushToArray(char *arr) = 0;

	virtual void pushArrayToObject(char *arr, char *obj) = 0;

	virtual void pushArrayToObjects(char *arrname, char *obj, ...) = 0;

	virtual ~iqjson_object() { }
};
}

#endif /* IQJSON_H_ */
