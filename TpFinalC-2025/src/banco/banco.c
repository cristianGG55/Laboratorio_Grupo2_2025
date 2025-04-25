#include "../../includes/includelib.h"

#include "banco.h"

THIS(obj_Banco)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_BancoImpl(void *self)
{
     obj_Banco *obj=this(self);      
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("\n"); 
}

static int getCodigoBanco_Impl(void *self)
{ return  *((int *) getValue(self,POS_CODIGO_BAN));}
//----------------------------------------------------

static char * getNombreBanco_Impl(void *self)
{ return  (char *) getValue(self,POS_NOMBRE_BAN);}
//----------------------------------------------------

static char * getDireccionBanco_Impl(void *self)
{ return  (char *) getValue(self,POS_DIRECCION_BAN);}
//----------------------------------------------------

static char * getTelefonoBanco_Impl(void *self)
{ return  (char *) getValue(self,POS_TELEFONO_BAN);}
//----------------------------------------------------


static void setCodigoBanco_Impl(void *self,int val)
{ setValue(self,POS_CODIGO_BAN,&val); }
//----------------------------------------------------

static void setNombreBanco_Impl(void *self,char * val)
{ setValue(self,POS_NOMBRE_BAN,val); }
//----------------------------------------------------

static void setDireccionBanco_Impl(void *self,char * val)
{ setValue(self,POS_DIRECCION_BAN,val); }
//----------------------------------------------------

static void setTelefonoBanco_Impl(void *self,char * val)
{ setValue(self,POS_TELEFONO_BAN,val); }
//----------------------------------------------------

//----------------------------------------------------
static void destroyInternalBAN_Impl(void *self)
{
	obj_Banco *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------

//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Banco(void *self)
{
  obj_Banco *obj      = this(self);
  obj->ds  			    = &table_Banco;
  obj->constructor 	    = Banco_new;
  obj->sizeObj 		    = sizeof(obj_Banco*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
  
  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_BancoImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodigo = getCodigoBanco_Impl;
  
	obj->getNombre = getNombreBanco_Impl;
  
	obj->getDireccion = getDireccionBanco_Impl;
  
	obj->getTelefono = getTelefonoBanco_Impl;

  /// setters  
    
	obj->setCodigo = setCodigoBanco_Impl;
  
	obj->setNombre = setNombreBanco_Impl;
  
	obj->setDireccion = setDireccionBanco_Impl;
  
	obj->setTelefono = setTelefonoBanco_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalBAN_Impl;
  //---- acceso a relaciones  
  
  return obj;
}
//----------------------------------------------------
//constructor de Banco
obj_Banco *Banco_new()
{
  return (obj_Banco *)init_obj(sizeof(obj_Banco), init_Banco);
}
//----------------------------------------------------

