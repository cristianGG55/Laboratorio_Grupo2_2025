#include "../../includes/includelib.h"
#include "../banco/banco.h"

#include "medio_pago.h"

THIS(obj_MedioPago)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_MedioPagoImpl(void *self)
{
     obj_MedioPago *obj=this(self);      
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("\n"); 
}

static int getCodigoMedioPago_Impl(void *self)
{ return  *((int *) getValue(self,POS_CODIGO_MED));}
//----------------------------------------------------

static char * getDescripcionMedioPago_Impl(void *self)
{ return  (char *) getValue(self,POS_DESCRIPCION_MED);}
//----------------------------------------------------

static int getCodBancoMedioPago_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_BANCO_MED));}
//----------------------------------------------------


static void setCodigoMedioPago_Impl(void *self,int val)
{ setValue(self,POS_CODIGO_MED,&val); }
//----------------------------------------------------

static void setDescripcionMedioPago_Impl(void *self,char * val)
{ setValue(self,POS_DESCRIPCION_MED,val); }
//----------------------------------------------------

static void setCodBancoMedioPago_Impl(void *self,int val)
{ setValue(self,POS_COD_BANCO_MED,&val); }
//----------------------------------------------------

//----------------------------------------------------
static void destroyInternalMED_Impl(void *self)
{
	obj_MedioPago *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
obj_Banco *getMedioPago_BancoObj_Impl(void *self)
{
 obj_MedioPago *obj = this(self);        //acceso a la informacion relacionada   return NULL;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_MedioPago(void *self)
{
  obj_MedioPago *obj      = this(self);
  obj->ds  			    = &table_MedioPago;
  obj->constructor 	    = MedioPago_new;
  obj->sizeObj 		    = sizeof(obj_MedioPago*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
    obj->banco   = NULL;

  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_MedioPagoImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodigo = getCodigoMedioPago_Impl;
  
	obj->getDescripcion = getDescripcionMedioPago_Impl;
  
	obj->getCodBanco = getCodBancoMedioPago_Impl;

  /// setters  
    
	obj->setCodigo = setCodigoMedioPago_Impl;
  
	obj->setDescripcion = setDescripcionMedioPago_Impl;
  
	obj->setCodBanco = setCodBancoMedioPago_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalMED_Impl;
  //---- acceso a relaciones  
    obj->getBancoObj  = getMedioPago_BancoObj_Impl;

  return obj;
}
//----------------------------------------------------
//constructor de MedioPago
obj_MedioPago *MedioPago_new()
{
  return (obj_MedioPago *)init_obj(sizeof(obj_MedioPago), init_MedioPago);
}
//----------------------------------------------------

