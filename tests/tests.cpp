//
// Created by marcos on 13/5/20.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Sin Mapa Test") {
    system("rm result.out");
    system("./tp trabajadoresMapaVacio.cfg mapaVacio.txt >> result.out");
    REQUIRE(!system("diff result.out mapaVacio.out"));
}

TEST_CASE("Sin Recolectores Test") {
    system("rm result.out");
    system("./tp trabajadoresSinRecolectores.cfg mapa.txt >> result.out");
    REQUIRE(!system("diff result.out sinRecolectores.out"));
}

TEST_CASE("Sin Productores Test") {
    system("rm result.out");
    system("./tp trabajadoresSinProductores.cfg mapa.txt >> result.out");
    REQUIRE(!system("diff result.out sinProductores.out"));
}

TEST_CASE("Enunciado Completo Test") {
    system("rm result.out");
    system("./tp trabajadores.cfg mapa.txt >> result.out");
    REQUIRE(!system("diff result.out enunciadoCompleto.out"));
}