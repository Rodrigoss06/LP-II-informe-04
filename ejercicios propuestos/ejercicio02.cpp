
#include <iostream>
#include <vector>
using namespace std;

class Venta;
class Cliente;
class Producto;

class Pago {
private:
    string metodoPago;
    float monto;
    string fecha;
public:
    Pago(string metodoPago, float monto, string fecha)
        : metodoPago(metodoPago), monto(monto), fecha(fecha) {}

    string getMetodoPago() const {
        return metodoPago;
    }

    float getMonto() const {
        return monto;
    }
    string getFecha() const {
        return fecha;
    }
};

class RegistroPagos {
private:
    vector<Pago> pagos;
public:
    RegistroPagos() {}

    void agregarPago(Pago pago) {
        pagos.push_back(pago);
    }

    vector<Pago> getPagos() const {
        return pagos;
    }
};
class Cliente
{
private:
    string nombre;
    string direccion;
    int telefono;
    vector<Venta> compras;
    RegistroPagos registroPagos;
public:
    Cliente(string nombre,string direccion,int telefono): nombre(nombre),direccion(direccion), telefono(telefono){};
    string getNombre() const {
        return nombre;
    }

    string getDireccion() const {
        return direccion;
    }

    int getTelefono() const {
        return telefono;
    }

    void agregarCompra(Venta& newCompra) {
        compras.push_back(newCompra);
    }

    void agregarPago(Pago pago) {
        registroPagos.agregarPago(pago);
    }

    RegistroPagos getRegistroPagos() const {
        return registroPagos;
    }

    void eliminarCliente() {
        delete this;
    }
};
class Producto
{
private:
    string codigo;
    string descripcion;
    float precio;
    string proveedor;
public:
    Producto(string codigo, string descripcion, float precio, string proveedor): codigo(codigo), descripcion(descripcion), precio(precio), proveedor(proveedor){};

    string getCodigo() const {
        return codigo;
    }

    string getDescripcion() const {
        return descripcion;
    }

    float getPrecio() const {
        return precio;
    }

    string getProveedor() const {
        return proveedor;
    }

    void eliminarProducto() {
        delete this;
    }
};

class Venta
{
private:
    string factura_id;
    string fecha;
    Cliente cliente;
    vector<Producto> productos;
public:
    Venta(string factura_id, string fecha, Cliente cliente, vector<Producto> productos): factura_id(factura_id), fecha(fecha), cliente(cliente), productos(productos){};

    string getFacturaId() const {
        return factura_id;
    }

    string getFecha() const {
        return fecha;
    }

    Cliente getCliente() const {
        return cliente;
    }

    vector<Producto> getProductos() const {
        return productos;
    }

    void eliminarVenta() {
        delete this;
    }

    void imprimir() const {
        cout << "Factura ID: " << factura_id << endl;
        cout << "Fecha: " << fecha << endl;
        cout << "Cliente: " << endl;
        cout << "   -nombre:"<< cliente.getNombre()<<endl;
        cout << "   -direccion:"<< cliente.getDireccion()<<endl;
        cout << "   -telefono:"<< cliente.getTelefono()<<endl;
        cout << "Productos:" << endl;
        for (const Producto& producto : productos) {
            cout << "   -codigo:" << producto.getCodigo() << endl; 
            cout << "   -descripcion:" << producto.getDescripcion() << endl; 
            cout << "   -precio: $/" << producto.getPrecio() << endl; 
            cout << "   -proveedor:" << producto.getProveedor() << endl; 
            cout << endl;
        }
    }
};

int main() {
    Cliente cliente("Juan", "Calle 123", 123456789);

    Producto producto1("001", "Camisa", 29.99, "Proveedor A");
    Producto producto2("002", "Pantalón", 39.99, "Proveedor B");

    vector<Producto> productos = {producto1, producto2};

    Venta venta("F001", "2024-04-14", cliente, productos);

    Pago pago("Efectivo", 100.0, "2024-04-14");
    cliente.agregarPago(pago);

    RegistroPagos registroPagos = cliente.getRegistroPagos();

    vector<Pago> pagos = registroPagos.getPagos();
    cout << "Pagos de "<< cliente.getNombre() <<": " << endl;
    for (const Pago& pago : pagos) {
        cout << "   - Metodo de pago: " << pago.getMetodoPago() << ", Monto: $" << pago.getMonto() <<", Fecha: "<< pago.getFecha() << endl;
    }

    venta.imprimir();

    return 0;
}

