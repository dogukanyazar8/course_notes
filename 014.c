/*

Ders14

<ctype.h> küütphanesi - karakter test fonksiyonları ve karakter dönüşüm fonksiyonları var.

int isupper(int ch); //evet gonderilen karakter büyük harf karakteri, non-zero değer döndürecek, hayır değilse, 0 döndürecek. 
int islower(int ch); //küçük harf mi?
int isalpha(int ch); //harf karakterleri
int isdigit(int ch); //rakam karakterleri
int isalnum(int ch); //rakam ya da harf karakterleri
int isxdigit(int ch); //0123456789ABCDEFabcdef
int ispunct(int ch); //Görüntüsü var fakat harf veya rakam karakteri değil.
int isspace(int ch); //space tuşu, yatay ve dikey tab, form feed, new line, carriage return bunlar boşluk karakterleri
int isblank(int ch); // boşluk ve tab karakterleri
int isprint(int ch); //görüntüsü olan tüm karakterler
int isgraph(int ch); //isprintin aynısı, tek fark 32. numaralı space karakteri ' ' printable fakat grafik karakteri değil.
int iscntrl(int ch); //kontrol karakterleri, görüntüsünü olmayan. ilk 32 karakter. 0 - 31 ve 127 numaralı karakter.

#include <stdio.h>
#include <ctype.h>

int main(){

    int ch;

    printf("Bir karakter girin: ");
    ch = getchar();

    if(isupper(ch)) // if(isupper(ch) != 0) iki if deyimini de aynı anlama geliyor.
        printf("isupper ok\n");
    else
        printf("isupper not ok\n");

    if(islower(ch)) //
        printf("islower ok\n");
    else
        printf("islower not ok\n");

    if(islower(ch)) //
        printf("islower ok\n");
    else
        printf("islower not ok\n");

    if(isalpha(ch)) //
        printf("isalpha ok\n");
    else
        printf("isalpha not ok\n");

    if(isdigit(ch)) //
        printf("isdigit ok\n");
    else
        printf("isdigit not ok\n");
    
    if(isxdigit(ch)) //
        printf("isxdigit ok\n");
    else
        printf("isxdigit not ok\n");

    if(ispunct(ch)) //
        printf("ispunct ok\n");
    else
        printf("ispunct not ok\n");
    
    if(isspace(ch)) //
        printf("isspace ok\n");
    else
        printf("isspace not ok\n");

    if(isblank(ch)) //
        printf("isblank ok\n");
    else
        printf("isblank not ok\n");

    if(isprint(ch)) //
        printf("isprint ok\n");
    else
        printf("isprint not ok\n");

    if(isgraph(ch)) //
        printf("isgraph ok\n");
    else
        printf("isgraph not ok\n");

    if(iscntrl(ch)) //
        printf("iscntrl ok\n");
    else
        printf("iscntrl not ok\n");
}

-----------------------------------------------------------------------------------------

#include <stdio.h>
#include <ctype.h>

int isleap(int y){
    return y % 4 == 0 & (y % 100 != 0 || y % 400 == 0);
}

int main(){

    printf("isupper\n");
    for(int i = 0; i < 128; ++i){
        if(isupper(i))
            putchar(i);
    }

    printf("\n\n");

    printf("islower\n");
    for(int i = 0; i < 128; ++i){
        if(islower(i))
            putchar(i);
    }

    printf("\n\n");

    printf("isalpha\n");
    for(int i = 0; i < 128; ++i){
        if(isalpha(i))
            putchar(i);
    }

    printf("\n\n");

    printf("isdigit\n");
    for(int i = 0; i < 128; ++i){
        if(isdigit(i))
            putchar(i);
    }

    printf("\n\n");

    printf("isxdigit\n");
    for(int i = 0; i < 128; ++i){
        if(isxdigit(i))
            putchar(i);
    }

    printf("\n\n");

    printf("ispunct\n");
    for(int i = 0; i < 128; ++i){
        if(ispunct(i))
            putchar(i);
    }

    printf("\n\n");

    printf("isspace\n");
    for(int i = 0; i < 128; ++i){
        if(isspace(i))
            printf("%d ", i);
    }

    printf("\n\n");

    printf("isblank\n");
    for(int i = 0; i < 128; ++i){
        if(isblank(i))
            printf("%d ", i);
    }

    printf("\n\n");

    printf("isprint\n");
    for(int i = 0; i < 128; ++i){
        if(isprint(i))
            putchar(i);
    }

    printf("\n\n");

    printf("isgraph\n");
    for(int i = 0; i < 128; ++i){
        if(isgraph(i))
            putchar(i);
    }

    printf("\n\n");

    printf("iscntrl\n");
    for(int i = 0; i < 128; ++i){
        if(iscntrl(i))
            printf("%d ", i);
    }
}

-----------------------------------------------------------------------------------------

#include <stdio.h>
#include <ctype.h>
#include <windows.h>

int get_random_char(){

    int c;

    while(!isprint(c = rand() % 128))
        ;

    return c;
}

int main(){

    for (;;){
        putchar(get_random_char());
        putchar(' ');
        Sleep(50);
    }
}

-----------------------------------------------------------------------------------------

ctype başlık dosyasında iki farklı fonksiyon daha var. toupper - tolower.
Bu fonksiyonlar karakter dönüşüm fonksiyonları.
Küçük harften büyük harfte, büyük harften küçük harfe.

toupper: bir karakterin kodunu alıyor ve küçük harfinin kodunu gönderiyor. 
eğer gönderdiğimiz karakter küçük harf karakteri değilse, gönderilen karakterin aynısını gönderir.

tolower: bir karakterin kodunu alıyor ve büyük harfinin kodunu gönderiyor. 
eğer gönderdiğimiz karakter büyük harf karakteri değilse, gönderilen karakterin aynısını gönderir.

#include <stdio.h>
#include <ctype.h>
#include <windows.h>


int main(){
    int c;

    printf("Bir karakter giriniz: ");
    c = getchar();

    printf("TOLOWER: %c ---> %c\n", c, tolower(c));
    printf("TOUPPER: %c ---> %c\n", c, toupper(c));
}

-----------------------------------------------------------------------------------------

//Harf karakterleri söz konusu olduğunda bazı durumlarda aynı harf karakterinin büyüğünü ve küçüğünü eşit kabul etmemiz gerekebiliyor.

//case-insensitive karşılaştırma. 

toupper(c1) == toupper(c2)

#include <stdio.h>
#include <ctype.h>
#include <windows.h>


int main(){
    int c1, c2;

    printf("iki karakter giriniz: ");
    c1 = getchar();
    c2 = getchar();

    if (toupper(c1) == toupper(c2)) {
        printf("%c ve %c ayni karakterler\n", c1, c2);
    }
    else {
        printf("%c ve %c farkli karakterler\n", c1, c2);
    }
}

-----------------------------------------------------------------------------------------

#include <stdio.h>
#include <ctype.h>
#include <windows.h>


int main(){

    int ch;

    printf("Beni seviyor musun (e)(E) (h)(H): ");
    // ch = getchar(); bunu yazmak yerine

    ch = toupper(getchar());

    if(ch == 'E')
        printf("ben de seni seviyorum\n");
    else if (ch == 'H')
        printf("cehenneme kadar yolun var\n");
    else{
        printf("Bu cevabi anlayamadim.\n");
    }
}

-----------------------------------------------------------------------------------------

Java, C# gibi dillerde test fonksiyonlarının geri dönüş türü tipik olarak bool türü.
Dolayısıyla bu dillerde bu şekilde bir kod yazabilirz.

bool isprime(int val); //asal sayı test fonksiyonu, geri dönüş değeri bool

x ve y'nin asal durumu eşitse, primality

    if (isprime(x) == isprime(y))

Fakat C dilinde bu şekilde kullanamayız, return değerleri farklı olabilir.

    if (!!isprime(x) == !!isprime(y))

-----------------------------------------------------------------------------------------

Koşul Operatörü (Ternary Operator)

ternary operator
unary - tek operand
binary - iki operand
ternary - uc operand

Bu kesinlikle bir operatör. Bu operatör 3 operand alıyor.
İki atomu var. 13. öncelik seviyesindedir. Öncelik yönü, sağdan sola.

operand1 ? operand2 : operand3

Koşul operatörünün 1. operandı, lojik yorumlamaya tabii tutuluyor.
Operatörümüz 2. operandının değerini üretiyor. Aksi halde, 3. operandının değerini üretiyor.

Bir ifadenin doğru ya da yanlış olarak yorumlanmasına bağlı olarak 2. veye 3. operandının değerini üretiyor.

lojik ve,
lojik veya,
lojik değil,
if parantezi
while parantezi
for döngü deyiminin arasında kalan ifade

bunlar lojik yorumlamaya tabii tutuluyor.
non zero doğru, zero yanlış.

Bu operatör if deyiminin farklı bir biçimi değildir. If bir kontrol deyimidir, bu ise bir operatör.
Lojik açıdan bir yakınlık var fakat bu bir operatör.

int main(){
    int x, y;
    printf("Iki tam sayi giriniz: ");
    scanf("%d%d", &x, &y);

    printf("max = %d", x > y ? x : y);// bu ifadenin değeri, x ve y'den büyük olanın değeri. x y'den büyükse, x'in değeri, aksi halde y'nin değeri.
}

a > 10 ? b : c // bu ifadenin değeri, a 10'dan büyükse b, değilse c.

x > 0 ? x : -x // bu ifadenin değeri, x'in mutlak değeri.

isleap(y) ? 366 : 365 // yılın gün sayısı, eğer artık yılsa, 366. aksi halde 365.

isleap(y) ? 29 : 28

Bir koşula bağlı olarak iki farklı değerden birini kullanma şansını elde ediyoruz.

x > y ? x : y + 10 // bu ifade koşul doğruysa, değeri x, yanlışsa ifadenin değeri y + 10

if (mdays > isleap(y) ? 29 : 28) -> eğer bu ifadeyi,
mdaysin değeri, artık yıllar için 29dan büyükse, artık yıl olmayan yıllar için 28den küçükse olarak yazmışsak, bu ifade yanlış.

Çünkü bu durumda tam tersi mdays > isleap(y) bu ifade koşul operatörünün 1. operandı olacak.
Eğer mdaysi büyük operatörünün sol operandı yapmak istiyorsak bunu öncelik parantezine almalıyız.

if (mdays > (isleap(y) ? 29 : 28))

Kısacası, koşul operatörünün ürettiği değeri bir başka operatörün operandı yapacaksak, 
koşul operatörü daha düşük öncelikte olduğundan dolayı koşul operatörünün oluşturduğu ifadeyi öncelik parantez içine almalıyız.

Koşul operatörünün 1. operandının önce yapılması garantisi var.
Koşul operatörünün 1. operandın sonra bir yan etkisi vardır. sequence point.

Örnek olarak burada x, f(46) değeriyle kullanılacak.

x++ ? f(x) : g(x)

Koşul operatörünün kullanıldığı tipik temalar.

1- koşul operatörünün ürettiği değeri bir değişkene atamak;

min = a < b ? a : b;

bunu bir if deyimiyle yazabilirdik,

if (a < b)
    min = a;
else
    min = b;

Koşul operatörünün kodun daha kolay okunmasını, anlaşılmasını sağlıyor.
Bazı durumlarda da derleyicinin daha iyi kod üretmesini sağlıyor olabilir.

val = x > 0 ? x : -x

mdays = isleap(y) ? 29 : 28

2- koşul operatörünün ürettiği değerle bir fonksiyon çağırmak.

if (a > 10)
    f(x);
else
    f(y);

f(a > 10 ? x : y);

3- fonksiyonların geri dönüş değeri üretmesini sağlayan return deyimi

if (x > y)
    return x;
else
    return y;

return x > y ? x : y

int get_abs(int x)
{
    return x > 0 ? x : -x;
}

int max2(int a, int b)
{
    return a > b ? a : b;
}

a > b ? a : b
(a > b) ? a : b

yukarıdaki iki ifade arasında bir fark yok.

c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c    //toupper fonksiyonuna alternatif.

İfade de bir sürü operatör olduğu için, görsel bir karmaşıklık yaratıyor. Parantez içerisinde almak kodun okunmasını kolaştırabilir.

(c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c

Koşul operatörü ön işlemci komutlarındaki makrolarda sıklıkla kullanılıyor.

Bazı durumlarda da koşul operatörünün ürettiği değeri bir başka operatörün operandı yapıyoruz.

totaldays += isleap(y) ? 29 : 28 //burada koşul operatörü, += operatörünün sağ operandı.

if (val > (isprime(x) ? a : b) //val a'dan ya da b'den büyükse, a mı b mi, bunu da belirleyen x'in asal olup olmadığı.
    fx();
else
    gx();

yukarıdaki ifadeyi, if deyimi ile yazalım.

if (isprime(x)){
    if (val > x)
        fx();
}
else if (val > b){
    gx;
}

-----------------------------------------------------------------------------------------

if (x > 10)
    a = y;
else
    b = y;

-----------------------------------------------------------------------------------------

C dilinde koşul operatörünün 2. ve 3. operandları L value expression olsalar da, 
Koşul operatörü ile oluşturulan ifade R value expressiondır.

Dolayısıyla aşağıdaki ifade C dilinin kurallarına göre sentaks hatasıdır.
C++'da bu kod geçerlidir.

x > 10 ? a : b = y;

int main(){

    int x;
    int y = 15;
    int a = 0, b = 0;

    if (x > 10)
        a = y;
    else
        b = y;

    //Yukarıdaki ifadeyi, aşağıdaki gibi yazabilir miyiz? Dilin kuralına göre değişir.
    //Öncelik açısından bir problem yok çünkü atama operatörünün sol operandı olan ifade x > 10 ? a : b
    //Atama operatörüyle oluşturulan ifadenin L value expression, yani sol taraf değeri ifadesi olması gerekiyor.

    //Atama operatörünün sol operandı olan ifade, bir L value expression mı? C dilinde hayır, C++'da evet.
    //Bu kod C dilinde sentaks hatasıdır.

    //x > 10 ? a : b = y;
}

x > 10 ? a : b = y;

C'de bunu yapmak için idiyomatik bir yapı var. Koşul operandının 2. ve 3. ifadesini adres operatörünün operandı yapıyoruz.

x > 10 ? &a : &b = y;

Böylece bu ifadenin değeri, x > 10 koşulu doğruysa a'nın adresi, bu koşul yanlışsa b'nin adresi.

*(x > 10 ? &a : &b) = 0;

* derefencing operatörü, operand olarak bir nesneyi aldığında, operand olarak bir adresi aldığında,
bizi o adresteki nesneye eriştiriyor. 

x > 10 ? a : b = 0

*(x > 10 ? &a : &b) = 0

-----------------------------------------------------------------------------------------

Eğer koşul operatörünün ürettiği değerden faydalanmıyorsanız,
koşul operatörünü kullanmayın. Bunun yerine if deyimi kullanın!

a > 0 ? f1() : f2(); // burada koşul operatörünün ürettiği değerden faydalanmadık, bunun yerine if deyimi yazabiliriz.

if (a > 0)
    f1();
else
    f2();

-----------------------------------------------------------------------------------------
Burada x'in değeri bir koşula bağlı bir durum var, o yüzden ilk değer veremiyoruz.
Bunu if deyimiyle yazmak yerine koşul operatörünün ürettiği değerden faydalanabiliriz.
    int x;

    if (foo() > 100)
        x = 2;
    else
        x = 0;   


    int x = foo() > 100 ? 2 : 0;

-----------------------------------------------------------------------------------------

Bazen de koşul operatörünü tıpkı bir else if merdiveni gibi birden fazla koşula bağlamak isteyebiliriz.

int main(){
    int x;
    int y;
    printf("Iki tam sayi girin: ");
    scanf("%d%d", &x, &y);

    x == 5 ? 13 : //bu ifadenin değeri doğru ise, x'in değeri 13. aksi halde alttaki ifadenin değerine bakılır.
    x == 7 ? 29 : 67; //bu ifadenin değeri doğru ise, x'in değeri 29, aksi halde 67.

    printf("Y: %d", y);
}

Else if merdiveni mantığıyla, koşul operatörüyle bir değer üretilmesini sağlayabiliyoruz.

    y = x == 5 ? 13 : x == 7 ? 29 : x == 15 ? 30 : 67;

-----------------------------------------------------------------------------------------

Döngü Deyimleri - Loop Statements 

3 tane ayrı döngü deyimimiz var. 3 tane ayrı döngü deyiminin olmamasının sebebi farklı işler yaptığından dolayı değildir.
Sadece duruma göre kodun daha kolay okunmasını ya da yazılmasını, veya her ikisini sağlıyor.
Tamamen kodun daha kolay yazılması, okunması.

while statement
do while statement
for statement

İstatistiksel olarak bu üç döngü deyiminden en sık kullanılan döngü deyimi uzak ara for döngü deyimi en sık kullanılan deyimdir.

for         %75
while       %24
do while    %1

Döngü deyimi: Bir kod parçasının, yinelemeli, tekrarlamalı yürütülmesini sağlayan kontrol deyimi.
Tipik olarak koşul doğru olduğu sürece, bir kod parçasının birden fazla kes yürütülmesini sağlamak.
Döngü deyimlerinin ortak özelliği budur.

Programlama dillerinin sentaksında döngü deyimlerinin sentaksı neredeyse birebir aynıdır. Küçük farklılıklar vardır.

Java, C# gibi dillerde foreach gibi bir döngü deyimi daha var. Bunun C'de karşılığı yok.
C++ ise bu üç döngü deyiminin dışında, range-based for loop isminde for döngünün ayrı bir kategorisi var.

for (int x : vec) gibi. C++'da olan ayrı bir kontrol deyimi.


coding idiom - kod kalıbı, kalıp kod.
Öyle kodlar

pattern (örüntü) -> pattern programlama dilinden bağımsız, özellikle nesne yönelimli programlamayla ilgili. programlama paradigmasıyla ilgili.
idiom (kalıp kod, kod kalıbı) -> programlama diline bağlı, örneğin c dilinde bir idiom, java'da olmayabilir ya da geçerli olmayabilir

idiom şu anlama geliyor aslında, "herkes böyle yazıyor, sen de böyle yaz"
programcıların ya çok büyük çoğunluğunun yazmayı sevdiği ve kodlarda çok sık karşılaşılan tekrar tekrar aynı kod yapısını kullanabileceğimiz kalıplar.

programlama dilinin bu idiomatik yapısına hakim olmak profesyonel düzeyde çok dikkat edilen bir nokta.

-----------------------------------------------------------------------------------------

while döngü deyimi

while bir anahtar sözcük.

while () -> bu parantezin içinde bir ifade olması zorunlu. boş olmamalı. ardından döngü deyiminin gövdesi.

while(expr){ -> (control expression)
    statement;
}

while parantezi içerisindeki ifade if deyimindeki gibi lojik yorumlamaya tabii tutuluyor.
doğru mu yanlış mı. ifadenin aritmetik değerine bakılır, non zero bir değerse, ifade doğru. ifadenin değeri 0'sa, yanlış olarak yorumlanır.
ifade doğruysa, döngünün gövdesinde deyim yapılacak. sonra programın akışı, bu ifadenin tekrar sınanmasıyla devam edecek.
ta ki, bu ifade yanlış olarak yorumlanırsa, o zaman döngüden çıkılacak ve while döngü deyiminden sonraki ifadeyle devam edecek.

doğru yap, doğru yap, doğru yap, yanlış -> döngüden çık.

burada kritik olan, kontrol ifadesinin daha ilk sınanmasında bile yanlış olması durumunda, gövdedeki deyimin hiç yürütülmeden döngüden çıkılması.

döngünün gövdesinki deyim, tıpkı if deyimindeki gibi, 
bir ifade deyimi olabilir, bloklanmış bir bileşik deyim olabilir, 
bir başka kontrol deyimi olabilir, ya da bir boş deyim olabilir.

while (exp)
    ; -> null statement.

boş deyimin kullanıldığı senaryo, sentaks döngünün gövdesinde bir deyim olmasını istiyor fakat biz hiçbir şey yapılmasını istiyoruz.
bunun için null statementi kullanıyoruz. ; 

c ve c++'da bir kural olarak, boş deyim yazabileceğimiz bir yere, içi boş bir blok da koyabiliriz.

döngünün gövdesinde hiçbir şey yapılmamasını istiyorsak, bunu yapmanın 3 yolu var.

while (exp)
    ;

while (exp)
{

}

while (exp)
    continue;

-----------------------------------------------------------------------------------------
x 100'den küçük olduğu ve y 1000'den küçük olduğu sürece dönen bir döngü

while (x < 100 && y < 1000) {

}

isprime bir test fonksiyonu olsun. x asal sayı olduğu sürece dönen bir döngü.

while (isprime(x)) {

}

isupper. x büyük harf olduğu sürece dönen bir döngü.

while (isupper(x)) {

}
-----------------------------------------------------------------------------------------

While döngü deyiminde parantez içindeki ifadenin atama operatörü ile oluşturulmuş bir ifade olması en sık kullanılan idiomlar arasında.


    int ch;
    printf("Bir yazi giriniz: ");
    ch = getchar(); // hem döngünün dışında hem de döngünün içinde döngüyü ilgilendiren bir atama var.

    while(ch != '\n'){
        printf("%c  %d\n", ch, ch);
        ch = getchar();
    }

Yukarıdaki gibi yazmak yerine, bütün C programcıları aşağıdaki gibi tercih eder.

    int ch;

    printf("Bir yazi giriniz: ");
    
    while((ch = getchar()) != '\n'){
        printf("%c  %d\n", ch, ch);
    }

-----------------------------------------------------------------------------------------

    int i = 0;

    while(i <= 100) {
        printf("%03d\n", i);
        ++i;
    }

-----------------------------------------------------------------------------------------

#include <stdio.h>

int reverse_digit(int val)
{
    int reverse = 0;

    while (val != 0){
        reverse = reverse * 10 + val % 10;
        val /= 10;
    }

    return reverse;
}

int sum_digit(int val)
{
    int sum = 0;

    while (val != 0){
        sum += val % 10;
        val /= 10;
    }

    return sum;
}

int ndigit(int val)
{
    int digit_count = 0;

    while (val != 0){
        ++digit_count;
        val /= 10;
    }

    return digit_count;
}

int main(){

    int x;
    printf("Bir tam sayi giriniz: ");
    scanf("%d", &x);

    printf("%d sayisinin basamak sayisi: %d\n", x, ndigit(x));
    printf("%d sayisinin basamaklari toplami: %d\n", x, sum_digit(x));
    printf("%d sayisinin basamaksal tersi: %d\n", x, reverse_digit(x));   
}

-----------------------------------------------------------------------------------------

Matematikte armstrong sayıları var.

Bir amstrong sayısı, sayının kendisi sayının basamaklarının küplerine eşit olacak

153 

1^3 -> 1
5^3 -> 125
3^3 -> 27

1 + 125 + 27 = 153

370

3^3 -> 27
7^3 -> 343
0^3 -> 0

27 + 343 + 0 = 370

370

3^3 -> 27
7^3 -> 343
1^3 -> 1

27 + 343 + 1 = 371

407

4^3 -> 64
0^3 -> 0
7^3 -> 343

64 + 0 + 343 = 407

-----------------------------------------------------------------------------------------

#include <stdio.h>

// Üç basamaklı armstrong sayılarını ekrana yazdır.

int main(){

    int i = 100;

    while (i < 1000){
        int d1 = i / 100;       //yuzler basamagi
        int d2 = i / 10 % 10;   //onlar basamagi
        int d3 = i % 10;        //birler basamagi
        if(i == (d1 * d1 * d1) + (d2 * d2 * d2) + (d3 * d3 * d3))
        {
            printf("%d\n", i);
        }
        ++i;
    } 
}

-----------------------------------------------------------------------------------------

#include <stdio.h>

// Dört basamaklı armstrong sayılarını ekrana yazdır.

int main(){

    int i = 1000;

    while (i < 10000){
        int d1 = i / 1000;       //binler basamagi
        int d2 = i / 100 % 10;   //yuzler basamagi
        int d3 = i / 10 % 10;    //onlar basamagi
        int d4 = i % 10;         //birler basamagi
        if(i == (d1 * d1 * d1 * d1) + (d2 * d2 * d2 * d2) + (d3 * d3 * d3 * d3) + (d4 * d4 * d4 * d4))
        {
            printf("%d\n", i);
        }
        ++i;
    } 
}

-----------------------------------------------------------------------------------------

*/
