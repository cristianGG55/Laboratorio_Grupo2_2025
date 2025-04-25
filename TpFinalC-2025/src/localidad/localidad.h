#ifndef LOCALIDAD_INCLUDED
	#define LOCALIDAD_INCLUDED
	#define CNT_COL_LOCALIDAD 2
	#define POS_CODPOSTAL_LOC 0
	#define POS_NOMBRE_LOC 1

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodpostal;
        
	getPropertyCharPtr   getNombre;

	    //-- setters
        
	setPropertyIntPtr   setCodpostal;
        
	setPropertyCharPtr   setNombre;

// getter de objeto relacionado

	}obj_Localidad;
	// funcionalidad publica que se implementa en Localidad.c
	extern obj_Localidad *Localidad_new ();
	// meta data para acceder a las Localidads - definicion de las columnas de la tabla
	static Column cols_Localidad[CNT_COL_LOCALIDAD]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codpostal",t_int,sizeof(int),true,false},
    
	{"nombre",t_varchar,(sizeof(char)*MAX60)+1,false,false},
	};
	// plantilla para la Localidad.
	static Table table_Localidad={"localidad",CNT_COL_LOCALIDAD,0, cols_Localidad,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Localidad
	typedef obj_Localidad *(*getLocalidadObjPtr)(void *self);
	// opcion de interfaz visual para leer informacion de una localidad existente en el sistema. 
	int leerOpcionLoc(char *msj,bool clear, bool cancela);
#endif
