Sie finden diese Aufgabe auf github:
<https://classroom.github.com/g/GBlMdMbp>.

Vergleichen Sie die Häufigkeit der Zahlen in **datensumme.txt** mit den
Vorhersagen der Poissonverteilung. Bitte schreiben Sie Ihren Code in die
Datei: **poisson.cc**

Zählen Sie mit einem **std::vector\<int\>**, wie oft die Werte $k$ von 0
bis 10 in der Datei vorkommen. Binden Sie dafür die entsprechende
Include-Datei mit

    #include<vector>
    using namespace std;

ein. Erzeugen Sie ein vector-Objekt mit elf
Einträgen:`vector<int> zaehler(11);` Lesen Sie dann alle $N = 234$
Zahlenwerte $n_i$ aus **datensumme.txt** und erhöhen Sie immer den
entsprechenden Eintrag im Vektor:

    zaehler[zahl] += 1;

Geben Sie am Ende alle Einträge im Vektor `zaehler` aus.

Erzeugen Sie nun eine Datei **hist.txt** mit den Ergebnissen aus a) im
Format:

    0 12
    1 23
    2 53
    ...

Stellen Sie die Werte als Histogramm da, indem Sie im Terminal
**gnuplot** starten und im Programm

    plot "./hist.txt"  smooth freq with boxes

eingeben. (Mit `quit` beenden Sie **gnuplot**.) Altnativ können Sie eine
Online-Version von gnuplot nutzen: <http://gnuplot.respawned.com/>.
Kopieren Sie Ihre Datenwerte in das obere Textfenster und geben im
darunter liegenden folgendes ein:

    set terminal svg size 400,300 enhanced fname 'arial'  fsize 10 butt solid
    set output 'out.svg'
    plot  "data.txt" using 1:2 smooth freq with boxes

Schreiben Sie eine Funktion `double poisson(double mu, int k)`, die die
Poissonwahrscheinlichkeit $P(k,\mu) =  \frac{\mu^ke^{-\mu}}{k!}$
berechnet. Benutzen Sie als Implementation der Exponentialfunktion die
Funktion `double exp(double x)` aus **cmath** und die Funktion
`double pow(double x, double k)` für $x^k$. Die Fakultät können Sie über
die Gammafunktion $k! = \Gamma(k+1)$ (`double tgamma(double x)` in
**cmath**) berechnen.\
Schreiben Sie eine neue Datei **histpoi.txt**, die in einer dritten
Spalte die Erwartung aus der Poissonverteilung $N \cdot P(k, \mu)$
enthält. Verwenden Sie den Mittelwert aus Blatt 2 als $\mu$ der
Poissonverteilung (3,11538).\
Vergleichen Sie die Werte und die Vorhersagen mit **gnuplot**:\
`plot "./histpoi.txt" using 1:2, ''./histpoi.txt" using 1:3 smooth freq with boxes`

Wir wollen nun den Wert von $\mu$ aus den Daten mit der
[Maximum-Likelihood-Methode](https://de.wikipedia.org/wiki/Maximum-Likelihood-Methode)
abschätzen. Zudem wollen wir die Übereinstimmung mit der
Poisson-Hypothese quantifizieren. Hierzu nutzen wir die
Log-Likelihood-Funktion
([Likelihood-Quotienten-Test](https://de.wikipedia.org/wiki/Likelihood-Quotienten-Test))
und deren Beziehung zur $\chi^2$-Verteilung. Bitte schreiben Sie Ihren
Code in die Datei: **likelihood.cc**

Berechnen Sie zunächst die Gesamtwahrscheinlichkeit, die 234 Zahlenwerte
$n_i$ erhalten: $\mathcal{L}(\mu) = \prod_{i=1}^{234} P(n_i,\mu)$, wenn
die Annahme der Poissonverteilung stimmt. Speichern Sie hierzu alle
Werte aus "datensumme.txt" in einem Vektor **std::vector\<int\>
daten**.\
Benutzen Sie **daten.push\_back(zahl)**, um den Wert der Variable
**zahl** zum Vektor hinzuzufügen.\
Schreiben Sie nun eine Funktion
`double prob(std::vector<int> daten, double mu)`, die die Likelihood,
also die Wahrscheinlichkeit
$\mathcal{L}(\mu) = \prod_i   \frac{\mu^{k_i}e^{-\mu}}{k_i!}$, die Daten
mit einem bestimmten $\mu$ zu erhalten, berechnet.

Zum Iterieren über die Werte in **daten** nutzen Sie:

    for(int k : daten) {
      ...
    }

Geben Sie die Wahrscheinlichkeit für $\mu = 3{,}11538$ (Mittelwert der
Stichprobe) aus. Es sollte $7{,}76841\cdot 10^{-195}$ herauskommen.

Schreiben Sie nun für $\mu$-Werte zwischen 0 und 6 eine Datei
"likelihood.txt" mit den Wertepaaren $\mu$ und $\mathcal{L}(\mu)$.
Tasten Sie $\mu$ mit einer Schrittweite von 0.1 ab. Stellen Sie die
Werte als Graph da, indem Sie im Terminal **gnuplot** starten und im
Programm `plot "likelihood.txt"  with line` eingeben. (Mit `quit`
beenden Sie **gnuplot**.)\
Verringern Sie die Schrittweite, um ein schöneres Bild zu erhalten. Was
sehen Sie?\
Finden Sie über das Maximum des Likelihood den besten Schätzwert für
$\mu$.\
(Mit `plot [xmin:xmax] "likelihood.txt"  with line` können Sie nur einen
Ausschnitt in $x$ des Graphen darstellen.)

Schreiben Sie nun eine zweite Datei "nll.txt" mit den Wertepaaren $\mu$
und $- 2\ln \mathcal{L}(\mu)$, dem negativen Log-Likelihood. Benutzen
Sie die `log`-Funktion aus **cmath**. Erzeugen Sie auch für diese Werte
einen Graph mit **gnuplot**.

Der Mittelwert der Stichprobe sollte ein guter Schätzwert für $\mu$
sein. Ziehen Sie nun beim Schreiben der Datei "deltanll.txt"
$-2\ln \mathcal{L}(3{,}11538)$ vom negativen Log-Likelihood
$- 2\ln \mathcal{L}(\mu)$ ab. Erzeugen Sie wiederum einen Graph mit
**gnuplot**.\
Mit `plot [xmin:xmax][ymin:ymax] "deltanll.txt"  with line` können Sie
nur einen Ausschnitt des Graphen darstellen.\
Finden Sie über das Minimum des negativen Log-Likelihood den besten
Schätzwert für $\mu$. Bestimmen Sie den Fehler auf den geschätzten
$\mu$-Wert, indem Sie das Intervall finden, in dem
$- \ln \mathcal{L}(\mu)$ um weniger als 1,0 größer als im Minimum ist.

Da diese Gesamtwahrscheinlichkeit immer kleiner wird, je mehr
Zahlenwerte betrachtet werden, teilt man diese Likelihood für eine
Poissonverteilung mit $\mu = 3{,}11538$ durch die bestmögliche
Poissonwahrscheinlichkeit, nämlich jener, wenn für jede einzelne Zahl
$\mu = n_i$ angenommen wird. Berechnen Sie den Likelihood-Quotienten:
$\Lambda = \prod_{i=1}^{234} P(n_i,\mu)/\prod_{i=1}^{234} P(n_i,n_i)$
und geben Sie den Wert aus.\
Wenn die Annahme einer Poissonverteilung stimmt, sollte $-2\ln \Lambda$
gemäß einer
[$\chi^2$-Verteilung](https://de.wikipedia.org/wiki/Chi-Quadrat-Verteilung)
mit $n_\textrm{dof} = 233$ Freiheitsgraden verteilt sein. Für eine Zahl
an Freiheitsgraden größer 100 sollte die $\chi^2$-Verteilung einer
Normalverteilung mit Mittelwert $n_\textrm{dof}$ und Standardabweichung
$\sqrt{2n_\textrm{dof}}$ entsprechen. Berechnen Sie die relative
Abweichung Ihres Likelihood-Quotienten vom Mittelwert:
$z = \frac{2\ln \Lambda - n_\textrm{dof}}{\sqrt{2n_\textrm{dof}}}$.
Benutzen Sie die `sqrt`-Funktion aus **cmath**.
