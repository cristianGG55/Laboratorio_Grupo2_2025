#include "../../includes/includelib.h"
#include "../localidad/localidad.h"
#include "../sucursal/sucursal.h"

#include "sucursal_dest.h"          

THIS(obj_SucursalDest)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_SucursalDestImpl(void *self)
{
     obj_SucursalDest *obj=this(self);      
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("\n"); 
}

static int getCodSucOSucursalDest_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_SUC_O_SUC));}
//----------------------------------------------------

static int getCodSucDSucursalDest_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_SUC_D_SUC));}
//----------------------------------------------------


static void setCodSucOSucursalDest_Impl(void *self,int val)
{ setValue(self,POS_COD_SUC_O_SUC,&val); }
//----------------------------------------------------

static void setCodSucDSucursalDest_Impl(void *self,int val)
{ setValue(self,POS_COD_SUC_D_SUC,&val); }
//----------------------------------------------------

static void setKmSucursalDest_Impl(void *self,int val)
{ setValue(self,POS_KM_SUC,&val); }
//----------------------------------------------------

//----------------------------------------------------
static void destroyInternalSUC_Impl(void *self)
{
	obj_SucursalDest *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
obj_Sucursal *getSucursalDest_SucursalObjO_Impl(void *self)
{
 obj_SucursalDest *obj = this(self);        //acceso a la informacion relacionada   
 return NULL;
}
obj_Sucursal *getSucursalDest_SucursalObjD_Impl(void *self)
{
 obj_SucursalDest *obj = this(self);        //acceso a la informacion relacionada   
 return NULL;
}
//----------------------------------------------------
int getKmSucursalDest_Impl(void *self)
 { return  *((int *) getValue(self,POS_KM_SUC));}

//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_SucursalDest(void *self)
{
  obj_SucursalDest *obj      = this(self);
  obj->ds  			    = &table_SucursalDest;
  obj->constructor 	    = SucursalDest_new;
  obj->sizeObj 		    = sizeof(obj_SucursalDest*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
  obj->sucursal_o   = NULL;
  obj->sucursal_d   = NULL;

  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_SucursalDestImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodSucO = getCodSucOSucursalDest_Impl;
  
	obj->getCodSucD = getCodSucDSucursalDest_Impl;

  /// setters  
    
	obj->setCodSucO = setCodSucOSucursalDest_Impl;
  
	obj->setCodSucD = setCodSucDSucursalDest_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalSUC_Impl;
  //---- acceso a relaciones  
  obj->getSucursalObjO  = getSucursalDest_SucursalObjO_Impl;
  obj->getSucursalObjD  = getSucursalDest_SucursalObjD_Impl;
  obj->getKm            = getKmSucursalDest_Impl;
  obj->setKm            = setKmSucursalDest_Impl;

  return obj;
}
//----------------------------------------------------
//constructor de SucursalDest
obj_SucursalDest *SucursalDest_new()
{
  return (obj_SucursalDest *)init_obj(sizeof(obj_SucursalDest), init_SucursalDest);
}
//----------------------------------------------------

