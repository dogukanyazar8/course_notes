/*

Ders15

While Döngü Deyimi

While parantezi içerisindeki ifade, doğru olduğu sürece döngü gövdesindeki deyimin yapılmasını sağlıyordu.

--------------------------------------------------------------------------

n kez dönen, C idiomu.

Burada, bir döngü oluşturucaz ve bu döngünün kaç kez dönmesi gerektiği belli.

    int n;
    printf("Bir tam sayi giriniz: ");
    scanf("%d", &n);

    while (n-- > 0){ // son ek -- operatörünün ürettiği değer, nesnenin kendi değeri. while (n--) yazsaydık da sonuç aynı olurdu. n = 0 olduğunda lojik yorumlamaya tabii tutulduğunda, döngüden çıkılacaktı.
        printf("Dogukan Yazar\n");
    }

--------------------------------------------------------------------------

    int n;
    printf("Bir tam sayi giriniz: ");
    scanf("%d", &n);

    while (n --> 0){ // programcıları kandırmak için --> böyle bir operatör varmış gibi gösteriyorlar. Aslında böyle bir operatör yok, ifade bu şekilde: n-- > 0
                    // derleyici kaynak kodu atomlarına ayırırken maximum munch kuralını uyguluyor ve olabilecek en uzun atomu seçiyor.
        printf("Dogukan Yazar\n");
    }

--------------------------------------------------------------------------

#include <stdio.h>

//eğer daha anlamlı bir isim mevcut değilse, değişkenin tek varlık nedeni fonksiyonun geri dönüş değerini tutmak ise, bu isimleri kullanabiliriz.
// result - ret
int power(int base, int exp){

    int result = 1;

    while (exp--){ //Döngü deyimini gövdesi sadece bir deyimden oluşuyorsa, bu deyimini bloklamak veya bloklamamak arasında bir fark yok.
        result *= base;
    }

    return result;
}

int main(){
    int x, y;
    printf("Iki tam sayi giriniz: "); // 3 ve 3
    scanf("%d%d", &x, &y);

    printf("%d ==> %d = %d\n", x, y, power(x, y));
}

--------------------------------------------------------------------------

Microsoft Visual Studio IDEsini kullanıyorsak, 
Project -> project_name Properties -> Code Analysis -> Enable Microsoft Code Analysis [NO] 
scanf gibi fonksiyonlarda uyarı vermemesi için.

--------------------------------------------------------------------------

sonsuz döngü - infinite loop

sonsuz döngü terimi iki ayrı anlamda kullanılabiliyor.
birincisi bir kodlama hatasını işaretlemek için kullanılıyor.

int main(){
    int low, high;
    int n;
    int i;

    printf("Bir aralik girin: [low high]: ");
    scanf("%d%d", &low, &high);
    printf("Kaca tam bolunenler yazilsin: ");
    scanf("%d", &n);

    i = low;

    while (i < high){
        if (i % n == 0) {
            printf("%d", i);
            ++i;    //programcı burada i'nin arttırılma yerini yanlış yere yazmış.
        }           //burada sonsuz bir döngü var.
    }
}

//sonsuz döngü idiomu
bir de öyle durumlar var ki, biz bilerek bir döngüden, döngünün kontrol ifadesinin yanlış olması nedeniyle döngüden çıkılsın istemiyoruz.

while (1) {

}

Döngüden zaten çıkılmayacak. Program açık kaldığı sürece bu döngünün gövdesindeki deyimler yapılacak.
Mesela embedded programlarının bir kısmı bu şekilde. Main fonksiyonları içinde böyle bir döngü deyimi var.

Bu tarz programlama dillerinde standart kütüphanenin programları sonlandıran fonksiyon ya da fonksiyonları oluyor.
exit
abort

Döngüden başka bir yolla çıkmak.
Bir döngüden çıkış yolları:

i)   döngünün kontrol ifadesinin yanlış olması ile
ii)  break statement ile
iii) return statement ile
iv)  goto deyimi ile (goto deyiminin zaten varlık nedeni programın akışını koşulsuz belirli bir noktaya yönlendirmek. döngünün içinden döngünün dışındaki bir noktaya)
v)   programın sonlanması (exit - abort -> bir fonksiyon çağrısı ile programın sonlandırılmasını sağlayıp, döngüden çıkabiliriz.)

while (expr) {
    //statement
    //statement
    if (c_ex)
        return 1;
    //statement
    //statement

while (expr) {
    //statement
    //statement
    if (c_ex)
        break;
    //statement
    //statement
}

while (expr) {
    //statement
    //statement
    if (c_ex)
        exit(EXIT_FAILURE);
    //statement
    //statement
}

while döngü deyimi oluştururken döngünün kontrol ifadesini hemen yazmak istemek.
a) bu döngünün başında belli olmayabilir. dinamik olarak döngünün gövdesinde belirli oluyor olabilir.
b) evet böyle bir ifade yazılabilir ama böyle bir ifadeyi yazmak görece olarak zor olabilir.

Ama biz döngünün gövdesinde diğer yollardan biriyle döngüden çıkabiliriz.

while (1) { //sonsuz döngü deyimi

    if(????)
}

--------------------------------------------------------------------------

Break Statement - Break Deyimi

Break deyimi sentaks açısından C'nin en basit deyimlerinden biri.
break bir anahtar sözcük. ve bu anahtar sözcüğü doğrudan sonlandırıcı atomu izliyor ve bu break deyimi oluyor.
break;

Break deyiminin geçerli olabilmesi için:

a) bir döngü deyiminin gövdesinde,
b) bir switch deyiminin gövdesinde,

Eğer bu noktalardan birinde değilse, sentaks hatasıdır.

Break deyiminin yürütülmesi programın akışını döngüden sonraki ilk deyime yönlendiriyor.

while (expr) {
    statement;
    statement;
    statement;
    statement;
    if (c_exp)  //eğer programın akışında, if ifadesi doğru olursa, break deyimi çalışır ve programın akışı döngüden sonraki ilk deyime yönlendirilir.
        break;
    statement;
    statement;
}
    statement_after_loop;

Bu döngüden, hangi noktada çıkmak istiyorsak, 

while (1) {
    if (!c_exp)  
        break;
    statement;
    statement;
    statement;
    statement;
    statement;
    statement;
}
    statement_after_loop;

Yukarıdaki döngü deyimi ile aşağıdaki döngü deyiminin hiçbir farkı yoktur.

while (c_exp) {
    statement;
    statement;
    statement;
    statement;
    statement;
    statement;
}
    statement_after_loop;


Örnek, aşağıdaki döngünün gövdesinde, if deyimindeki koşul ifadesi doğru olduğu sürece bu döngüdeki deyimler yapılacak.

while (1) {
    statement;
    statement;
    statement;
    statement;
    statement;
    statement;
    if (!c_exp)
        break;
}

Bu da aslında do-while döngü deyiminin bir örneği. Döngünün koşul ifadesi döngünün başında kontrol edilmiyor, döngünün sonunda kontrol ediliyor.

Döngüyü kontrol eden ifade döngünün başındaysa, bu normal while döngüsü.
Döngüyü kontrol eden ifade döngünün sonundaysa, bu do while döngüsü.

Bu IF - BREAK yapısı döngünün içerisinde sadece bir noktada değil, birden fazla noktada da kullanılabilir.

--------------------------------------------------------------------------

#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int c;
    int ival;
    int cnt = 0;
    int sum = 0;
    int max = INT_MIN; //Ön işlemci komutlarını kullanarak, max değişkenine olabilecek en küçük değeri verdik. makro konusuyla ilgili.
    int min = INT_MAX; //Ön işlemci komutlarını kullanarak, max değişkenine olabilecek en büyük değeri verdik. makro konusuyla ilgili.

    while (1) {
        printf("Tam sayi girecek misiniz [e] [h] : ");
        while ((c = getch()) != 'e' && c != 'h') //atama operatörünün ürettiği değer nesneye atanan değerdir. ayrıca kısa devre davranışı var. burada girişi e ve h tuşlarına kitledik.
        ;                                        //null statement - döngünün gövdesinde bir şey yapılmayacak.
        printf("%c\n", c);
        if (c == 'h')
            break;
        printf("Tam sayiyi giriniz: ");
        //scanf("%d", &ival);
        ival = (rand() % 2 ? 1 : -1) * rand();

        if(cnt == 0)
            min = max = ival;
        else if (ival > max)
            max = ival;
        else if (ival < min)
            min = ival;

        sum += ival;
        ++cnt;

        printf("%d\n [Giris Sayisi: %d]", ival, cnt);
    }

    if (cnt != 0){
        printf("Toplam %d sayi girdiniz.\n", cnt);
        printf("Ortalama = %f\n", (double)sum/cnt); //(double) tür dönüştürme operatörü. derleyic sum değişkenini double olarak işleme sokacak. 
        printf("Max = %d\n", max);
        printf("Min = %d\n", min);
    }
    else {
        printf("Hic sayi girmediniz.\n");
    }
}
--------------------------------------------------------------------------

Döngülerde en tipik durumlardan biri de, döngünün gövdesinde başka bir döngünün bulunması.
Nested Loops

while (exp1) {

    ////
    while (exp2) {

        break; //programın akışı buraya geldiğinde programın akışı /xxx buraya gelecek.
    }

    /xxx programın akışı buraya gelecek.
}
    /yyy


Break deyimi sadece içinde kullanıldığı döngüyü kırar, o döngüden çıkışı sağlar.
İç içe döngü deyimlerinde, go to deyimini kullanabiliriz.

--------------------------------------------------------------------------

continue statement

continue bir anahtar sözcük, ardından sonlandırıcı atomu.

continue;

bu deyimin geçerli olabilmesi için döngünün gövdesinde kullanılması gerekiyor.

Bir döngünün akışı, programın akışı continue deyimine gelirse, programın akışı döngünün bir sonraki turuna geçecek. 
Yani kendisinden sonraki deyimler, yürütülmeyecek.

while (expr) {
    statement1;
    statement2;
    statement3;
    if (c_exp)
        continue; //programın akışı buraya geldiğinde, döngünün bir sonraki turuna geçilecek. alttaki deyimler yapılmayacak.
    statement4;
    statement5;
    statement6;
}

Aşağıdaki iki while deyimi arasında bir farkı yok. Anlam açısından ikisi de aynı.

while (expr) {
    statement1;
    statement2;
    statement3;
    if (c_exp) {
        statement4;
        statement5;
        statement6;
    }
}

while (expr) {
    statement1;
    statement2;
    statement3;
    if (!c_exp)
        continue;

    statement4;
    statement5;
    statement6;   
}

--------------------------------------------------------------------------

#include <stdio.h>

int main(){

    unsigned long long uval = 23;

    while (1) {
        printf("%llu ", uval);
        if (uval == 1)
            break;
        
        if (uval % 2 == 0)
            uval /= 2;
        else
            uval = uval * 3 + 1;
    }
     printf("\n"); 
}

--------------------------------------------------------------------------

while (1)
for (;;)

while (n-- -> 0)
while (n--)

while ((c = getch()) != 'e' && c != 'h')

--------------------------------------------------------------------------

#include <stdio.h>

int main(){

    int c;

    while ((c = getchar()) != '\n') //bunu virgül operatörü ile de yapabilirdik. while (c = getchar(), c != '\n')
        printf("%c %d\n", c, c);

}

--------------------------------------------------------------------------

#include <stdio.h>

int main(){

    int i = 0;

    while (i++ < 10);
        printf("%d", i); //ekran çıktısı 11.
}

--------------------------------------------------------------------------

do while döngü deyimi (en az kullanılan döngü deyimi)

bazen ihtiyaç olarak, döngünün gövdesindeki deyimler en az bir kez yapılsın fakat tekrar yapılıp yapılmayacağı, daha sonradan belli olsun.

yani döngüden çıkış kontrolü döngünün başında değil, döngünün sonunda yapılsın.

while (1) {
    statement1;
    statement2;
    statement3;
    statement4;
    if (!exp) //bu ifade ne zaman yanlış olursa, döngüden çıkılacak. do while ile bunu yapabiliriz.
        break;
}

do {
    statement1; //bunu yap
    statement2; //bunu yap
    statement3; //bunu yap
    statement4; //bunu yap
} while (exp) //burası doğruysa, tekrar yap, başa dön (statement1)

Bu yukarıdaki while ile do while döngü deyimlerinin arasında hiçbir fark yok.

--------------------------------------------------------------------------

#include <stdio.h>

int main(){

    int ival; 

    do {
        printf("Bir sayi giriniz: ");
        scanf("%d", &ival);
    } while (ival < 0 || ival > 100); // 0 ile 100 aralığında bir sayı girildiğinde, döngüden çıkılacak.

    printf("Girilen sayi: %d", ival);
}

--------------------------------------------------------------------------

#include <stdio.h>

int main(){

    int i = 1;

    do{
        printf("%d\n", i);
        i++;
        if(i < 15)
            continue;
    } while (0); // programın akışı buraya geldiğinde, 0 false olarak yorumlandığı için, ekrana sadece 1 yazacak.
}

--------------------------------------------------------------------------

For Döngü Deyimi

Programcıların döngü deyimi tercihi

Döngüyü kontrol eden bir değişken yoksa, while döngü deyimi tercih edilebilir, eğer varsa for tercih edilir.

Programcılar while döngüsünden mümkün olduğunca kaçınırlar, mümkün olduğunca sadece for döngü deyimini kullanmak için.

for (;;) sadece iki tane noktalı virgül olabilir.

for (1;2;3) for (exp1; exp2; exp3) buralarda ifade olabilir ama olmak zorunda  da değil.

for (exp1; exp2; exp3)
    statement;

for döngüsünün paratezleri içerisinde ifadelerin farklı işlevleri var.

exp1 -> döngüye girişte sadece bir defa yapılıyor. bu ifade yapılıyor, daha işimiz kalmıyor. eğer exp1 olmasaydı, burada hiçbir şey yapılmayacaktı.
exp2 -> döngüyü kontrol eden ifade. control expression. while parantezi içerisinde ifade neyse, for döngüsünün de iki noktalı virgül arasındaki ifade o. bu ifade doğru olduğu sürece döngünün gövdesindeki deyim yapılacak.
exp3 -> döngünün gövdesindeki deyimin yapılmasından sonra fakat kontrol ifadesinin tekrar sınanmasından önce exp3 yürütülecek.

çalışma şekli.

exp1 -> bunu yap
exp2 -> doğru mu, doğru, statement'i yap.
exp3 -> bunu yap
exp2 -> doğru mu, doğru, statement'i yap.
exp3 -> bunu yap
exp2 -> doğru mu, yanlış, döngüden çık.

Neden böyle bir döngü deyimi var? Yukarıdaki for döngüsüyle aşağıdaki while döngüsünün sonuç açısından hiçbir farkı yok.

exp1;

while(exp) {
    statement;
    exp3;
}

Peki neden for döngü deyimini kullanılıyoruz?

Çoğu zaman döngü deyiminin dışında fakat lojik açıdan döngüyü ilgilendiren bir deyim oluyor.
Buradaki exp1 gibi. 

Şimdi bunun döngü deyiminin dışında olması, kodun okunması sırasında, exp1'in döngüyle lojik ilişkisini vurgulamıyor.

Dolayısıyla, for döngü deyimi biraz daha kompakt, niyetini daha iyi anlatıyor.
Ve döngünün dışında, döngüden önce döngüyü ilgilendiren deyimi de, döngünün sentaksına katıyor.

int main(){

    int i;

    for (i = 0; i < 10; ++i)
        printf("%d ", i);
}

--------------------------------------------------------------------------

int main(){

    int i;

    i = 0;
    for (; i < 10; ++i) // sentaks hatası yok.
        printf("%d ", i);
}

--------------------------------------------------------------------------

int main(){

    int i;

    i = 0;
    for (; i < 10;){ // sentaks hatası yok.
        printf("%d ", i); 
        ++i;
    }
}

--------------------------------------------------------------------------

#include <stdio.h>

int main(){

    int i;

    i = 0;
    for (;;){ // eğer 2. ifade yerinde herhangi bir şey yok ise. buraya lojik doğru sabiti yazılmış etkisi yapıyor. (for ;1;)
        if(i == 10)
            break;
        printf("%d ", i); 
        ++i;
    }
}

--------------------------------------------------------------------------

For döngüsünün sentaksında bir döngü değişkeni de olmak zorunda değil.

for (f1(); f2(); f3())
    f4();

f1 fonksiyonu yapılacak.
f2 fonksiyonunun geri dönüş değeri doğru olduğu sürece f4 fonksiyonu yapılacak.
döngünün kontrol ifadesi tekrar sınanmadan önce f3 fonksiyonu çağrılacak.

--------------------------------------------------------------------------

int main(){

    int ch;

    for (ch = getchar(); ch != '\n'; ch = getchar())
        printf("%c %d\n", ch, ch);
}

--------------------------------------------------------------------------

C dilinin C99 standartlarına kadar for parantezinin birinci kısmında döngü değişkeni tanımlamak mümkün değildi.

Yani aşağıdaki döngü deyimi C99 öncesi geçerli değil.

for (int i = 0; i < 100; ++i)

C99 standartlarıyla bu özellik eklendi.

for (int i = 0; i < 100; ++i) 

Burada tanımlanan değişkenin kapsamı döngünün gövdesiyle sınırlı. Döngü değişkenini for'un içinde tanımlarsak, döngü dışında kullanamayız.

Eğer burada değişkenin tek varlık nedeni döngüyü kontrol etmekse, döngünün çıkışında bu değişkeni kullanmayacaksak, her zaman bu döngü değişkenini for parantezinin birinci kısmından tanımlamak lazım.

Bu aynı zamanda, yanlışlıkla bu ismi kullanma olasılığını ortadan kaldıracak.

Aynı zamanda, döngü değişkenlerinin kapsamları farklı olduğu için aynı blokta birden fazla for döngü deyimi varsa, döngü değişkeninin ismini aynı olması da herhangi bir hataya yol açmaz.

--------------------------------------------------------------------------

C dilinde enterasan bir kural var. Biz döngünün gövdesini bloklasak da, aslında burada görünmeyen bir blok varmış gibi kabul ediyor.

int main(){

    for (int i = 0; i < 100; ++i) {
        int i = 10; // C dilinde geçerli. C++'da geçersiz, sentaks hatası.
    }
}

int main(){

    for (int i = 0; i < 100; ++i) {
        {   
        int i = 10;
        }
    }
}

--------------------------------------------------------------------------

Her iki for döngü deyimi de sonuç açısından aynıdır. Ekrana 10 defa 20 yazdırır.

#include <stdio.h>

int main(){

    for (int i = 0; i < 10; ++i) {
        {
        int i = 20;
        printf("%d ", i);
        }
    }
}

#include <stdio.h>

int main(){

    for (int i = 0; i < 10; ++i) {
        int i = 20;
        printf("%d ", i);   
    }
}

--------------------------------------------------------------------------

#include <stdio.h>

int main(){
    //n kez dönen, döngü idiomu
    for (int i = 0; i < 10; ++i) { // ++i ile i++ yazmak arasında hiçbir fark yok. operatörün ürettiği değerden faydalanmadığımız için hiçbir fark yok.

    }
}

--------------------------------------------------------------------------

#include <stdio.h>

int main(){

    for (int i = 100; i >= 0; --i){ //burada işaretli türü kullandığımıza dikkat etmemiz lazım.
        printf("%d\n", i);
    }
}

--------------------------------------------------------------------------

For'un birinci kısmında birden fazla değişken tanımlayabiliriz.

for döngünün birinci veya üçüncü kısmında yer alan virgül operatörü çok sık kullanılan tipik bir durum.

#include <stdio.h>

int main(){

    for (int i = 10, k = 20; i + k < 1000; ++i, k += i){
        printf("%d\n", i);
    }
}

int main(){

    int i, k;

    for (i = 10, k = 20; i + k < 1000; ++i, k += i){
        printf("%d\n", i);
    }
}

--------------------------------------------------------------------------

#include <stdio.h>

int main(){

    int i;

    for (i = 0; i < 20; ++i)
        ; // null statement. i'nin değeri 20 olduğunda, döngü sonlanacak.
        
    printf("%d ", i); //ekrana 20 yazdırılacak.

}

--------------------------------------------------------------------------

#include <stdio.h>

//factorial hesaplama
// 1 * 2 * 3 * 4 * .... x

//4 byte'lık int türü söz konusu olduğunda, ister işaretli ister işaretsiz olsun, 13! taşar. 
//Yani 13! 4bytelık int türünde tutulamaz. Doğrudan tanımsız davranıştır.

long long factorial(int x) {

    long long result = 1;

    for (int i = 1; i <= x; ++i){
        result *= i;
    }

    return result;
}

int main(){

    for (int i = 0; i < 21; ++i){
        printf("%d! = %lld\n", i, factorial(i));
    }
}

--------------------------------------------------------------------------

#include <stdio.h>

// Bu soruya verilecebilecek en iyi cevap, değerleri bir dizide tutup, istenilen faktoryal değerini göndermektir.

int factorial (int x){

    // böyle dizilere lookup table deniliyor.
    const int af4[] = {
        1,      
        1,     
        2,      
        6,
        24,
        120,
        720,
        5040,
        40320,
        362880,
        3628800,
        39916800,
        479001600,  //12!
    };

    return af4[x];
}

int main(){

    printf("%d", factorial(13));

}

--------------------------------------------------------------------------

#include <stdio.h>

long long factorial (int x){

    const long long af8[] = {
        1,      
        1,     
        2,      
        6,
        24,
        120,
        720,
        5040,
        40320,
        362880,
        3628800,
        39916800,
        479001600,  //12!
        6227020800,
        87178291200,
        1307674368000,
        20922789888000,
        355687428096000,
        6402373705728000,
        121645100408832000,
        2432902008176640000, //20!
    };

    return af8[x];
}

int main(){
    printf("%lld", factorial(19));
}

--------------------------------------------------------------------------

Recursive fonksiyon olarak da yapabiliriz.

#include <stdio.h>

int factorial (int x)
{
    return x < 2 ? 1 : x * factorial(x - 1);
}

int main(){

    for (int i = 0; i < 13; ++i)
        printf("%d! = %d\n", i, factorial(i));
}

--------------------------------------------------------------------------

Taylor serisi
1 + 1 / 1! + 1 / 2! + 1 / 3! 

#include <stdio.h>

int factorial (int x)
{
    return x < 2 ? 1 : x * factorial(x - 1);
}

int main(){
    double sum = 0.;

    for (int i = 0; i < 13; ++i)
        sum += 1. / factorial(i);

    printf("%f\n", sum);
}

--------------------------------------------------------------------------

ÖDEV SORUSU

#include <stdio.h>

int factorial (int x)
{
    return x < 2 ? 1 : x * factorial(x - 1);
}

int combination (int n, int p)
{
    
}

int main(){

}

--------------------------------------------------------------------------

1 - 1/3 + 1/5 - 1/7 + 1/9 ......

#include <stdio.h>

int main(){

    int n;
    double sum = 0.;

    printf("Serinin kac terimi toplansin: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {// her zaman birinci tercihiğimiz kontrol ifadesini küçük ile kullanmak. küçük eşit ile değil. n kez dönen döngü deyimi için.
        if (i % 2 == 0)
            sum += 1. / (2 * i + 1);
        else
            sum -= 1. / (2 * i + 1);
    }

    printf("%.12f\n", 4. * sum);
}


*/
