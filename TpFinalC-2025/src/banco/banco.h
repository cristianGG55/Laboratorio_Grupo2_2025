#ifndef BANCO_INCLUDED
	#define BANCO_INCLUDED
	#define CNT_COL_BANCO 4
	#define POS_CODIGO_BAN 0
	#define POS_NOMBRE_BAN 1
	#define POS_DIRECCION_BAN 2
	#define POS_TELEFONO_BAN 3

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodigo;
        
	getPropertyCharPtr   getNombre;
        
	getPropertyCharPtr   getDireccion;
        
	getPropertyCharPtr   getTelefono;

	    //-- setters
        
	setPropertyIntPtr   setCodigo;
        
	setPropertyCharPtr   setNombre;
        
	setPropertyCharPtr   setDireccion;
        
	setPropertyCharPtr   setTelefono;

// getter de objeto relacionado

	}obj_Banco;
	// funcionalidad publica que se implementa en Banco.c
	extern obj_Banco *Banco_new ();
	// meta data para acceder a las Bancos - definicion de las columnas de la tabla
	static Column cols_Banco[CNT_COL_BANCO]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codigo",t_int,sizeof(int),true,true},
    
	{"nombre",t_varchar,(sizeof(char)*MAX50)+1,false,false},    
	{"direccion",t_varchar,(sizeof(char)*MAX90)+1,false,false},    
	{"telefono",t_varchar,(sizeof(char)*MAX25)+1,false,false},
	};
	// plantilla para la Banco.
	static Table table_Banco={"banco",CNT_COL_BANCO,0, cols_Banco,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Banco
	typedef obj_Banco *(*getBancoObjPtr)(void *self);
#endif
