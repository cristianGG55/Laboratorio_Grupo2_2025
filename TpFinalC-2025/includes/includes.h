#include <string.h>
#include <errno.h>
#include "../config/config.h"
#include "../lib/orm/orm.h"
#include "../lib/orm/query.h"
#include "../lib/utils/utils.h"
/* incluir los archivos que representen las entidades */

#include "../src/localidad/localidad.h"
#include "../src/banco/banco.h"
#include "../src/categoria/categoria.h"
#include "../src/marca/marca.h"
#include "../src/sucursal/sucursal.h"
#include "../src/sucursal_dest/sucursal_dest.h"
#include "../src/medio_pago/medio_pago.h"
#include "../src/cliente/cliente.h"
#include "../src/producto/producto.h"
#include "../src/factura/factura.h"
#include "../src/det_factura/det_factura.h"
#include "../src/compra/compra.h"
#include "../src/bulto/bulto.h"
#include "../src/track_viaje/track_viaje.h"

#include "../view/view.h"



