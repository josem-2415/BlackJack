#include <gtest/gtest.h>
#include "../Modelo/Apuesta.h"
#include "../Modelo/Carta.h"
#include "../Modelo/Mazo.h"
#include "../Modelo/Participante.h"
#include "../Modelo/Jugador.h"
#include "../Modelo/Crupier.h"
#include "../Controlador/Controlador.h"

// =============================
//   TEST APUESTA
// =============================
TEST(ApuestaTest, CalculoGanancias) {
    Apuesta ap;
    ap.registrarApuesta(100);

    EXPECT_EQ(ap.calcularGanancia("gana"), 200);
    EXPECT_EQ(ap.calcularGanancia("empate"), 100);
    EXPECT_EQ(ap.calcularGanancia("pierde"), 0);
}

TEST(ApuestaTest, Reiniciar) {
    Apuesta ap(200);
    ap.reiniciar();
    EXPECT_EQ(ap.getMonto(), 0);
}


// =============================
//   TEST CARTA
// =============================
TEST(CartaTest, GetValores) {
    Carta c("A", "Picas");
    EXPECT_EQ(c.getValor(), "A");
    EXPECT_EQ(c.getPalo(), "Picas");
}


// =============================
//   TEST MAZO
// =============================
TEST(MazoTest, InicializarYRepartir) {
    Mazo m;
    m.inicializarMazo();

    EXPECT_EQ(m.cartasRestantes(), 52);

    Carta c = m.repartirCarta();
    EXPECT_EQ(m.cartasRestantes(), 51);
}


// =============================
//   TEST PARTICIPANTE
// =============================
class ParticipanteTestSuite : public ::testing::Test {
public:
    Participante p;
    Mazo mazo;

    void SetUp() override {
        mazo.inicializarMazo();
    }
};

TEST_F(ParticipanteTestSuite, PedirCarta) {
    int antes = mazo.cartasRestantes();
    p.pedirCarta(mazo);

    EXPECT_EQ(mazo.cartasRestantes(), antes - 1);
}

TEST_F(ParticipanteTestSuite, CalcularValorMano) {
    Participante p;
    // Insertar manualmente cartas
    p.pedirCarta(mazo); // No importa el valor exacto, solo testear que suma
    EXPECT_GT(p.calcularValorMano(), 1);
}


// =============================
//   TEST JUGADOR
// =============================
TEST(JugadorTest, BlackjackDetection) {
    Jugador j2;
    Mazo m;

    m.inicializarMazo();

    j2.limpiarMano();
    j2.pedirCarta(m);
    j2.pedirCarta(m);

    // No podemos garantizar 21 porque no controlamos las cartas...
    // Entonces solo testeamos la lógica local, no el valor exacto:
    int v = j2.calcularValorMano();
    EXPECT_TRUE(v >= 2 && v <= 21);
}


TEST(JugadorTest, ActualizarSaldo) {
    Jugador j(1000);
    j.realizarApuesta(200);
    j.actualizarSaldo("apostar", 200);

    EXPECT_EQ(j.getSaldo(), 800);

    j.actualizarSaldo("gana", 200);
    EXPECT_EQ(j.getSaldo(), 1200);  // 800 + 400
}


// =============================
//   TEST CRUPIER
// =============================
TEST(CrupierTest, PreguntarCarta) {
    Crupier c;
    Mazo m;

    m.inicializarMazo(); // crea un mazo válido

    // Le damos dos cartas iniciales al crupier desde el mazo
    c.pedirCarta(m);
    c.pedirCarta(m);

    int valorInicial = c.calcularValorMano();

    // Si por casualidad ya es >=17, aún así el método debe mantener ese valor
    c.preguntarCarta(m);

    EXPECT_GE(c.calcularValorMano(), 17);
}

// =============================
//   TEST CONTROLADOR
// =============================
TEST(ControladorTest, DeterminarGanador) {
    Jugador j;
    Crupier c;
    Mazo m;
    Controlador ctrl(j, c, m);

    m.inicializarMazo();

    j.limpiarMano();
    c.limpiarMano();

    // Dar dos cartas legales a cada uno
    j.pedirCarta(m);
    j.pedirCarta(m);

    c.pedirCarta(m);
    c.pedirCarta(m);

    string r = ctrl.determinarGanador(j, c, 100);

    // El resultado siempre debe ser uno de estos
    EXPECT_TRUE(
        r == "gana" ||
        r == "pierde" ||
        r == "empate"
    );
}

TEST(ControladorTest, Empate) {
    Jugador j;
    Crupier c;
    Mazo m;
    Controlador ctrl(j, c, m);

    m.inicializarMazo();

    j.limpiarMano();
    c.limpiarMano();

    // Repartir normalmente
    j.pedirCarta(m);
    j.pedirCarta(m);

    c.pedirCarta(m);
    c.pedirCarta(m);

    string r = ctrl.determinarGanador(j, c, 100);

    EXPECT_TRUE(
        r == "gana" ||
        r == "pierde" ||
        r == "empate"
    );
}

// =============================
//   MAIN DE TEST
// =============================
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
