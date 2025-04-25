#ifndef MARCA_INCLUDED
	#define MARCA_INCLUDED
	#define CNT_COL_MARCA 2
	#define POS_CODIGO_MAR 0
	#define POS_DESCRIPCION_MAR 1

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

	}obj_Marca;
	// funcionalidad publica que se implementa en Marca.c
	extern obj_Marca *Marca_new ();
	// meta data para acceder a las Marcas - definicion de las columnas de la tabla
	static Column cols_Marca[CNT_COL_MARCA]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codigo",t_int,sizeof(int),true,true},
    
	{"descripcion",t_varchar,(sizeof(char)*MAX50)+1,false,false},
	};
	// plantilla para la Marca.
	static Table table_Marca={"marca",CNT_COL_MARCA,0, cols_Marca,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Marca
	typedef obj_Marca *(*getMarcaObjPtr)(void *self);
#endif
