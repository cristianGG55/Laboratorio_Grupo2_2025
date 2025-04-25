#ifndef SUCURSAL_INCLUDED
	#define SUCURSAL_INCLUDED
	#define CNT_COL_SUCURSAL 5
	#define POS_CODIGO_SUC 0
	#define POS_NOMBRE_SUC 1
	#define POS_DIRECCION_SUC 2
	#define POS_TELEFONO_SUC 3
	#define POS_COD_POSTAL_SUC 4

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodigo;
        
	getPropertyCharPtr   getNombre;
        
	getPropertyCharPtr   getDireccion;
        
	getPropertyCharPtr   getTelefono;
        
	getPropertyIntPtr   getCodPostal;

	    //-- setters
        
	setPropertyIntPtr   setCodigo;
        
	setPropertyCharPtr   setNombre;
        
	setPropertyCharPtr   setDireccion;
        
	setPropertyCharPtr   setTelefono;
        
	setPropertyIntPtr   setCodPostal;

// getter de objeto relacionado
        getLocalidadObjPtr  getLocalidadObj;
        obj_Localidad *localidad;

	}obj_Sucursal;
	// funcionalidad publica que se implementa en Sucursal.c
	extern obj_Sucursal *Sucursal_new ();
	// meta data para acceder a las Sucursals - definicion de las columnas de la tabla
	static Column cols_Sucursal[CNT_COL_SUCURSAL]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codigo",t_int,sizeof(int),true,true},
    
	{"nombre",t_varchar,(sizeof(char)*MAX50)+1,false,false},    
	{"direccion",t_varchar,(sizeof(char)*MAX120)+1,false,false},    
	{"telefono",t_varchar,(sizeof(char)*MAX25)+1,false,false},    
	{"cod_postal",t_int,sizeof(int),false,false},

	};
	// plantilla para la Sucursal.
	static Table table_Sucursal={"sucursal",CNT_COL_SUCURSAL,0, cols_Sucursal,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Sucursal
	typedef obj_Sucursal *(*getSucursalObjPtr)(void *self);
#endif
