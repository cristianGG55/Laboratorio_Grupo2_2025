#ifndef CATEGORIA_INCLUDED
	#define CATEGORIA_INCLUDED
	#define CNT_COL_CATEGORIA 2
	#define POS_CODIGO_CAT 0
	#define POS_DESCRIPCION_CAT 1

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodigo;
        
	getPropertyCharPtr   getDescripcion;

	    //-- setters
        
	setPropertyIntPtr   setCodigo;
        
	setPropertyCharPtr   setDescripcion;

// getter de objeto relacionado

	}obj_Categoria;
	// funcionalidad publica que se implementa en Categoria.c
	extern obj_Categoria *Categoria_new ();
	// meta data para acceder a las Categorias - definicion de las columnas de la tabla
	static Column cols_Categoria[CNT_COL_CATEGORIA]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codigo",t_int,sizeof(int),true,true},
    
	{"descripcion",t_varchar,(sizeof(char)*MAX80)+1,false,false},
	};
	// plantilla para la Categoria.
	static Table table_Categoria={"categoria",CNT_COL_CATEGORIA,0, cols_Categoria,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Categoria
	typedef obj_Categoria *(*getCategoriaObjPtr)(void *self);
#endif
