#include "../../includes/includelib.h"
#include "../categoria/categoria.h"
#include "../marca/marca.h"

#include "producto.h"

THIS(obj_Producto)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_ProductoImpl(void *self)
{
     obj_Producto *obj=this(self);      
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("\n"); 
}

static int getCodigoProducto_Impl(void *self)
{ return  *((int *) getValue(self,POS_CODIGO_PRO));}
//----------------------------------------------------

static char * getDescripcionProducto_Impl(void *self)
{ return  (char *) getValue(self,POS_DESCRIPCION_PRO);}
//----------------------------------------------------

static int getCodCategoriaProducto_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_CATEGORIA_PRO));}
//----------------------------------------------------

static int getCodMarcaProducto_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_MARCA_PRO));}
//----------------------------------------------------

static float getPrecioProducto_Impl(void *self)
{ return  *((float *) getValue(self,POS_PRECIO_PRO));}
//----------------------------------------------------

static float getStockProducto_Impl(void *self)
{ return  *((float *) getValue(self,POS_STOCK_PRO));}
//----------------------------------------------------

static bool getDisponibleProducto_Impl(void *self)
{ return  *((bool *) getValue(self,POS_DISPONIBLE_PRO));}
//----------------------------------------------------


static void setCodigoProducto_Impl(void *self,int val)
{ setValue(self,POS_CODIGO_PRO,&val); }
//----------------------------------------------------

static void setDescripcionProducto_Impl(void *self,char * val)
{ setValue(self,POS_DESCRIPCION_PRO,val); }
//----------------------------------------------------

static void setCodCategoriaProducto_Impl(void *self,int val)
{ setValue(self,POS_COD_CATEGORIA_PRO,&val); }
//----------------------------------------------------

static void setCodMarcaProducto_Impl(void *self,int val)
{ setValue(self,POS_COD_MARCA_PRO,&val); }
//----------------------------------------------------

static void setPrecioProducto_Impl(void *self,float val)
{ setValue(self,POS_PRECIO_PRO,&val); }
//----------------------------------------------------

static void setStockProducto_Impl(void *self,float val)
{ setValue(self,POS_STOCK_PRO,&val); }
//----------------------------------------------------

static void setDisponibleProducto_Impl(void *self,bool val)
{ setValue(self,POS_DISPONIBLE_PRO,&val); }
//----------------------------------------------------

//----------------------------------------------------
static void destroyInternalPRO_Impl(void *self)
{
	obj_Producto *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
obj_Categoria *getProducto_CategoriaObj_Impl(void *self)
{
 obj_Producto *obj = this(self);        //acceso a la informacion relacionada   return NULL;
}obj_Marca *getProducto_MarcaObj_Impl(void *self)
{
 obj_Producto *obj = this(self);        //acceso a la informacion relacionada   return NULL;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Producto(void *self)
{
  obj_Producto *obj      = this(self);
  obj->ds  			    = &table_Producto;
  obj->constructor 	    = Producto_new;
  obj->sizeObj 		    = sizeof(obj_Producto*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
    obj->categoria   = NULL;
  obj->marca   = NULL;

  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_ProductoImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodigo = getCodigoProducto_Impl;
  
	obj->getDescripcion = getDescripcionProducto_Impl;
  
	obj->getCodCategoria = getCodCategoriaProducto_Impl;
  
	obj->getCodMarca = getCodMarcaProducto_Impl;
  
	obj->getPrecio = getPrecioProducto_Impl;
  
	obj->getStock = getStockProducto_Impl;
  
	obj->getDisponible = getDisponibleProducto_Impl;

  /// setters  
    
	obj->setCodigo = setCodigoProducto_Impl;
  
	obj->setDescripcion = setDescripcionProducto_Impl;
  
	obj->setCodCategoria = setCodCategoriaProducto_Impl;
  
	obj->setCodMarca = setCodMarcaProducto_Impl;
  
	obj->setPrecio = setPrecioProducto_Impl;
  
	obj->setStock = setStockProducto_Impl;
  
	obj->setDisponible = setDisponibleProducto_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalPRO_Impl;
  //---- acceso a relaciones  
    obj->getCategoriaObj  = getProducto_CategoriaObj_Impl;
  obj->getMarcaObj  = getProducto_MarcaObj_Impl;

  return obj;
}
//----------------------------------------------------
//constructor de Producto
obj_Producto *Producto_new()
{
  return (obj_Producto *)init_obj(sizeof(obj_Producto), init_Producto);
}
//----------------------------------------------------

