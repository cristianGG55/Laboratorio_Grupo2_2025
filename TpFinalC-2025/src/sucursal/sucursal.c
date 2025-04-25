#include "../../includes/includelib.h"
#include "../localidad/localidad.h"

#include "sucursal.h"

THIS(obj_Sucursal)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_SucursalImpl(void *self)
{
     obj_Sucursal *obj=this(self);      
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("\n"); 
}

static int getCodigoSucursal_Impl(void *self)
{ return  *((int *) getValue(self,POS_CODIGO_SUC));}
//----------------------------------------------------

static char * getNombreSucursal_Impl(void *self)
{ return  (char *) getValue(self,POS_NOMBRE_SUC);}
//----------------------------------------------------

static char * getDireccionSucursal_Impl(void *self)
{ return  (char *) getValue(self,POS_DIRECCION_SUC);}
//----------------------------------------------------

static char * getTelefonoSucursal_Impl(void *self)
{ return  (char *) getValue(self,POS_TELEFONO_SUC);}
//----------------------------------------------------

static int getCodPostalSucursal_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_POSTAL_SUC));}
//----------------------------------------------------


static void setCodigoSucursal_Impl(void *self,int val)
{ setValue(self,POS_CODIGO_SUC,&val); }
//----------------------------------------------------

static void setNombreSucursal_Impl(void *self,char * val)
{ setValue(self,POS_NOMBRE_SUC,val); }
//----------------------------------------------------

static void setDireccionSucursal_Impl(void *self,char * val)
{ setValue(self,POS_DIRECCION_SUC,val); }
//----------------------------------------------------

static void setTelefonoSucursal_Impl(void *self,char * val)
{ setValue(self,POS_TELEFONO_SUC,val); }
//----------------------------------------------------

static void setCodPostalSucursal_Impl(void *self,int val)
{ setValue(self,POS_COD_POSTAL_SUC,&val); }
//----------------------------------------------------

//----------------------------------------------------
static void destroyInternalSUC_Impl(void *self)
{
	obj_Sucursal *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
obj_Localidad *getSucursal_LocalidadObj_Impl(void *self)
{
 obj_Sucursal *obj = this(self);        //acceso a la informacion relacionada   return NULL;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Sucursal(void *self)
{
  obj_Sucursal *obj      = this(self);
  obj->ds  			    = &table_Sucursal;
  obj->constructor 	    = Sucursal_new;
  obj->sizeObj 		    = sizeof(obj_Sucursal*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
    obj->localidad   = NULL;

  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_SucursalImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodigo = getCodigoSucursal_Impl;
  
	obj->getNombre = getNombreSucursal_Impl;
  
	obj->getDireccion = getDireccionSucursal_Impl;
  
	obj->getTelefono = getTelefonoSucursal_Impl;
  
	obj->getCodPostal = getCodPostalSucursal_Impl;

  /// setters  
    
	obj->setCodigo = setCodigoSucursal_Impl;
  
	obj->setNombre = setNombreSucursal_Impl;
  
	obj->setDireccion = setDireccionSucursal_Impl;
  
	obj->setTelefono = setTelefonoSucursal_Impl;
  
	obj->setCodPostal = setCodPostalSucursal_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalSUC_Impl;
  //---- acceso a relaciones  
    obj->getLocalidadObj  = getSucursal_LocalidadObj_Impl;

  return obj;
}
//----------------------------------------------------
//constructor de Sucursal
obj_Sucursal *Sucursal_new()
{
  return (obj_Sucursal *)init_obj(sizeof(obj_Sucursal), init_Sucursal);
}
//----------------------------------------------------

