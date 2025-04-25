create table localidad(codpostal int primary key,nombre varchar(60));
create table marca(codigo serial primary key, descripcion varchar(50));
create table categoria(codigo serial primary key,descripcion varchar(80));
create table banco(codigo serial primary key,nombre varchar(50),direccion varchar(90),telefono varchar(25));
create table medio_pago(codigo serial primary key,descripcion varchar(50),cod_banco int);
alter table  medio_pago add constraint fk_mediopago_banco foreign key(cod_banco) references banco(codigo);
create table sucursal(codigo serial primary key,nombre varchar(50), direccion varchar(120),telefono varchar(25), cod_postal int);
alter table  sucursal add constraint fk_sucursal_localidad foreign key(cod_postal) references localidad(codpostal);
create table sucursal_dest(cod_suc_o int,cod_suc_d int, km int);
alter table  sucursal_dest add constraint fk_sucursal_dest_suc_o foreign key(cod_suc_o) references sucursal(codigo);--SucursalO
alter table  sucursal_dest add constraint fk_sucursal_dest_suc_d foreign key(cod_suc_d) references sucursal(codigo);--SucursalD
alter table  sucursal_dest add constraint pk_sucursal_dest primary key(cod_suc_o,cod_suc_d);
create table producto(codigo serial primary key,descripcion varchar(80),cod_categoria int ,cod_marca int,precio float,stock float, disponible bool);
alter table  producto add constraint fk_producto_categoria foreign key(cod_categoria) references categoria(codigo);
alter table  producto add constraint fk_producto_marca foreign key(cod_marca) references marca(codigo);
create table cliente(codigo serial primary key,usuario varchar(90),clave varchar(120),cuil varchar(20),razon_social varchar(90), direccion varchar(120),cod_postal int, email varchar(90), celular varchar(25));
alter table  cliente add constraint fk_cliente_localidad foreign key(cod_postal) references localidad(codpostal);
create table factura(codigo serial primary key,nro int,serie int,letra varchar(1),fecha date,cod_cliente int,cod_mpago int);
alter table  factura add constraint fk_factura_cliente foreign key(cod_cliente) references cliente(codigo);
alter table  factura add constraint fk_factura_mediopago foreign key(cod_mpago) references medio_pago(codigo);
create table det_factura(cod_factura int, renglon int , cod_producto int , precio_unit float, cantidad int);
alter table  det_factura add constraint fk_detfactura_factura foreign key(cod_factura) references factura(codigo);
alter table  det_factura add constraint fk_detfactura_producto foreign key(cod_producto) references producto(codigo);
alter table  det_factura add constraint pk_det_factura primary key(cod_factura,renglon);
create table compra(codigo serial primary key, fecha date, entregado bool,cod_factura int);
alter table  compra add constraint fk_compra_factura foreign key(cod_factura) references factura(codigo);
create table bulto(codigo serial primary key,fecha_despacho date, fecha_llegada date, hora_llegada time, estado int, cod_factura int);
alter table  bulto add constraint fk_bulto_factura foreign key(cod_factura) references factura(codigo);
create table track_viaje(codigo serial primary key, cod_suc_o int ,cod_suc_d int,cod_bulto int, f_ingreso date, h_ingreso time,f_salida date, h_salida time, detalle varchar(150));
alter table  track_viaje add constraint fk_track_viaje_suc_o foreign key(cod_suc_o) references sucursal(codigo);
alter table  track_viaje add constraint fk_track_viaje_suc_d foreign key(cod_suc_d) references sucursal(codigo);
alter table  track_viaje add constraint fk_track_viaje_bulto foreign key(cod_bulto) references bulto(codigo);

-- tabla de auditoria --  registrar altas y actualizaciones de informacion
-- crear estructura en el programa que permita gestionar esta informacion mas una pantalla de listado de consulta de las auditorias de "clientes" "productos" "sucursales"
create table log_audit(codigo serial primary key, detalle varchar(560),objeto varchar(40),fecha_hora timestamp);
ALTER TABLE log_audit ALTER COLUMN fecha_hora SET DEFAULT now();