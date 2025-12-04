#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V>
class TableEntry {
public:
    std::string key;
    V value;

    // Constructor clave-valor
    TableEntry(std::string key, V value)
        : key(key), value(value) {}

    // Constructor solo clave
    TableEntry(std::string key)
        : key(key), value() {}   // value se inicializa por defecto

    // Constructor por defecto: clave vacía
    TableEntry()
        : key(""), value() {}

    // Operador ==
    // Dos entradas son iguales si su clave es igual (ignora el valor)
    friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        return te1.key == te2.key;
    }

    // Operador !=
    friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        return te1.key != te2.key;
    }

    // Operador <<
    friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te) {
        out << "('" << te.key << "' => " << te.value << ")";
        return out;
    }
};

#endif

