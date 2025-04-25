#ifndef PRODUCTO_INCLUDED
	#define PRODUCTO_INCLUDED
	#define CNT_COL_PRODUCTO 7
	#define POS_CODIGO_PRO 0
	#define POS_DESCRIPCION_PRO 1
	#define POS_COD_CATEGORIA_PRO 2
	#define POS_COD_MARCA_PRO 3
	#define POS_PRECIO_PRO 4
	#define POS_STOCK_PRO 5
	#define POS_DISPONIBLE_PRO 6

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodigo;
        
	getPropertyCharPtr   getDescripcion;
        
	getPropertyIntPtr   getCodCategoria;
        
	getPropertyIntPtr   getCodMarca;
        
	getPropertyFloatPtr   getPrecio;
        
	getPropertyFloatPtr   getStock;
        
	getPropertyBoolPtr   getDisponible;

	    //-- setters
        
	setPropertyIntPtr   setCodigo;
        
	setPropertyCharPtr   setDescripcion;
        
	setPropertyIntPtr   setCodCategoria;
        
	setPropertyIntPtr   setCodMarca;
        
	setPropertyFloatPtr   setPrecio;
        
	setPropertyFloatPtr   setStock;
        
	setPropertyBoolPtr   setDisponible;

// getter de objeto relacionado
        getCategoriaObjPtr  getCategoriaObj;
        obj_Categoria *categoria;
        getMarcaObjPtr  getMarcaObj;
        obj_Marca *marca;

	}obj_Producto;
	// funcionalidad publica que se implementa en Producto.c
	extern obj_Producto *Producto_new ();
	// meta data para acceder a las Productos - definicion de las columnas de la tabla
	static Column cols_Producto[CNT_COL_PRODUCTO]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codigo",t_int,sizeof(int),true,true},
    
	{"descripcion",t_varchar,(sizeof(char)*MAX80)+1,false,false},    
	{"cod_categoria",t_int,sizeof(int),false,false},
    
	{"cod_marca",t_int,sizeof(int),false,false},
    
	{"precio",t_float,sizeof(float),false,false},
    
	{"stock",t_float,sizeof(float),false,false},
    
	{"disponible",t_bool,sizeof(bool),false,false},

	};
	// plantilla para la Producto.
	static Table table_Producto={"producto",CNT_COL_PRODUCTO,0, cols_Producto,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Producto
	typedef obj_Producto *(*getProductoObjPtr)(void *self);
#endif
