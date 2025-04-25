#include "../../config/config.h"
#include "../utils/utils.h"
#include "query.h"
#include "orm.h"
#include <string.h>
#include <malloc.h>

THIS(obj_Query)// crea definicion de funcion this para este modulo. .. Macro en config.h
// modulo en desarrollo - incompleto :-(

//al crear objeto de criterio, se debe tener una nombre de tabla del modelo, un alias
// addAnd 
// addOr 
// addJoin 
// list

static void addAndQuery_Impl(void *self,char *cr)
{ 
 obj_Query *obj = this(self);
 
 printf("%s - %s\n",obj->sql,cr);
}

static void addOrQuery_Impl(void *self,char *cr)
{ 
 obj_Query *obj = this(self);
}
static char *getSQL_Impl(void *self)
{
	obj_Query *obj = this(self);
	return obj->sql;
}
// crear funcion que destruya el objeto criterio
obj_Query *Query_new(void *Theobj)
{
	// crear la instancia a devolver para generar la consulta SQL con metodos 
	obj_Query *obj = malloc(sizeof(obj_Query));	
	Object *Obj = (Object *)(Theobj);
	obj->sql = (char *)malloc(sizeof(char)*MAX_SQL); // dar espacio para crear la sentencia SQL
	
	obj->addAnd = addAndQuery_Impl;
	obj->addOr = addOrQuery_Impl;
	obj->getSQL = getSQL_Impl;
	CLEAR(obj->sql,MAX_SQL);
	obj->t = Obj->getTableName(Obj);
	// crear los metodos que permita agregar condiciones y opciones de la consulta.
	char str_where[MAX_WHERE_SQL],fields[MAX_SQL];
	obj->sql = (char*)malloc(MAX_SQL*sizeof(char));
	  //blanquear cadenas
	  CLEAR(obj->sql,MAX_SQL);
	  CLEAR(fields,MAX_SQL);
	  
	  //ver si hay criterio para agregar 
	  strcpy(obj->sql,SQL_STR);	  
	  
	return obj;
}

void destroyObjQuery(void *objFree)
{
	int i;
	obj_Query *obj = (obj_Query *)objFree;	 
    free(obj->sql);	
	free(obj);
}
