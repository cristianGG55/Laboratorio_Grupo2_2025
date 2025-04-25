#include "../../includes/includelib.h"
#include "../localidad/localidad.h"

#include "cliente.h"

THIS(obj_Cliente)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_ClienteImpl(void *self)
{
     obj_Cliente *obj=this(self);      
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     obj_Localidad *loc = obj->getLocalidadObj(obj);
	 printf("%s - %s - %s\n",obj->getCuil(obj),obj->getUsuario(obj),loc->getNombre(loc)); 
}

static int getCodigoCliente_Impl(void *self)
{ return  *((int *) getValue(self,POS_CODIGO_CLI));}
//----------------------------------------------------

static char * getUsuarioCliente_Impl(void *self)
{ return  (char *) getValue(self,POS_USUARIO_CLI);}
//----------------------------------------------------

static char * getClaveCliente_Impl(void *self)
{ return  (char *) getValue(self,POS_CLAVE_CLI);}
//----------------------------------------------------

static char * getCuilCliente_Impl(void *self)
{ return  (char *) getValue(self,POS_CUIL_CLI);}
//----------------------------------------------------

static char * getRazonSocialCliente_Impl(void *self)
{ return  (char *) getValue(self,POS_RAZON_SOCIAL_CLI);}
//----------------------------------------------------

static char * getDireccionCliente_Impl(void *self)
{ return  (char *) getValue(self,POS_DIRECCION_CLI);}
//----------------------------------------------------

static int getCodPostalCliente_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_POSTAL_CLI));}
//----------------------------------------------------

static char * getEmailCliente_Impl(void *self)
{ return  (char *) getValue(self,POS_EMAIL_CLI);}
//----------------------------------------------------

static char * getCelularCliente_Impl(void *self)
{ return  (char *) getValue(self,POS_CELULAR_CLI);}
//----------------------------------------------------


static void setCodigoCliente_Impl(void *self,int val)
{ setValue(self,POS_CODIGO_CLI,&val); }
//----------------------------------------------------

static void setUsuarioCliente_Impl(void *self,char * val)
{ setValue(self,POS_USUARIO_CLI,val); }
//----------------------------------------------------

static void setClaveCliente_Impl(void *self,char * val)
{ setValue(self,POS_CLAVE_CLI,val); }
//----------------------------------------------------

static void setCuilCliente_Impl(void *self,char * val)
{ setValue(self,POS_CUIL_CLI,val); }
//----------------------------------------------------

static void setRazonSocialCliente_Impl(void *self,char * val)
{ setValue(self,POS_RAZON_SOCIAL_CLI,val); }
//----------------------------------------------------

static void setDireccionCliente_Impl(void *self,char * val)
{ setValue(self,POS_DIRECCION_CLI,val); }
//----------------------------------------------------

static void setCodPostalCliente_Impl(void *self,int val)
{ setValue(self,POS_COD_POSTAL_CLI,&val); }
//----------------------------------------------------

static void setEmailCliente_Impl(void *self,char * val)
{ setValue(self,POS_EMAIL_CLI,val); }
//----------------------------------------------------

static void setCelularCliente_Impl(void *self,char * val)
{ setValue(self,POS_CELULAR_CLI,val); }
//----------------------------------------------------

//----------------------------------------------------
static void destroyInternalCLI_Impl(void *self)
{
	obj_Cliente *obj = this(self);	
	if(obj->localidad!=NULL)
	  destroyObj(obj->localidad);
	obj->localidad = NULL;
	// finalizar cada referencia inicializada - no NULL
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
obj_Localidad *getCliente_LocalidadObj_Impl(void *self)
{
 obj_Cliente *obj = this(self);        //acceso a la informacion relacionada   
 obj->localidad = Localidad_new();
 
 if(obj->localidad->findbykey(obj->localidad,obj->getCodPostal(obj))==NOT_FOUND)
   return NULL;
 return obj->localidad ;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Cliente(void *self)
{
  obj_Cliente *obj      = this(self);
  obj->ds  			    = &table_Cliente;
  obj->constructor 	    = Cliente_new;
  obj->sizeObj 		    = sizeof(obj_Cliente*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
    obj->localidad   = NULL;

  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_ClienteImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodigo = getCodigoCliente_Impl;
  
	obj->getUsuario = getUsuarioCliente_Impl;
  
	obj->getClave = getClaveCliente_Impl;
  
	obj->getCuil = getCuilCliente_Impl;
  
	obj->getRazonSocial = getRazonSocialCliente_Impl;
  
	obj->getDireccion = getDireccionCliente_Impl;
  
	obj->getCodPostal = getCodPostalCliente_Impl;
  
	obj->getEmail = getEmailCliente_Impl;
  
	obj->getCelular = getCelularCliente_Impl;

  /// setters  
    
	obj->setCodigo = setCodigoCliente_Impl;
  
	obj->setUsuario = setUsuarioCliente_Impl;
  
	obj->setClave = setClaveCliente_Impl;
  
	obj->setCuil = setCuilCliente_Impl;
  
	obj->setRazonSocial = setRazonSocialCliente_Impl;
  
	obj->setDireccion = setDireccionCliente_Impl;
  
	obj->setCodPostal = setCodPostalCliente_Impl;
  
	obj->setEmail = setEmailCliente_Impl;
  
	obj->setCelular = setCelularCliente_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalCLI_Impl;
  //---- acceso a relaciones  
    obj->getLocalidadObj  = getCliente_LocalidadObj_Impl;

  return obj;
}
//----------------------------------------------------
//constructor de Cliente
obj_Cliente *Cliente_new()
{
  return (obj_Cliente *)init_obj(sizeof(obj_Cliente), init_Cliente);
}
//----------------------------------------------------

