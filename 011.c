/*

Ders11

Lojik Operatörler

-----------------------------------------
p       doğru   yanlış
değil   yanlış  doğru
-----------------------------------------
p   q       p ve q

D   D         D
D   Y         Y
Y   D         Y
Y   Y         Y
-----------------------------------------  
p   q      p veya q

D   D         D
D   Y         D
Y   D         D
Y   Y         Y
-----------------------------------------
C dilinde özel veya (xor) doğrudan operatör seviyesinde bir işlem değildir.
Özel veya işleminde sonucun doğru çıkması için operandların birbirinden farklı olması gerekiyor.
  
p   q    p özel veya q

D   D         Y
D   Y         D
Y   D         D
Y   Y         Y
-----------------------------------------

Bu operatörlerden özel veya haricinde diğer 3 işlemin C dilinde operatör karşılığı var.
C dilinde özel veyanın bitsel operatör olarak karşılığı var. Lojik operatör olarak karşılığı yok.

C dilinde lojik operatörlerin operandlarının bir çok programlama dilinden farklı olarak bool türünden olma zorunluluğu yok.
C dilinde lojik operatörlerin operandları herhangi bir türden olabiliyor.


! Logical Not - Lojik Değil Operatörü
2. öncelik seviyesinde.
Tek operand alır, Unary Prefix konumunda.
Öncelik yönü SAĞDAN SOLA. (RIGHT ASSOCIATIVE)

&& Logical And - Lojik Ve Operatörü
11. Öncelik seviyesinde.
İki operand alır. Binary Infix.

|| Logical Or - Lojik veya Operatörü
12. Öncelik seviyesinde.
İki operand alır. Binary Infix.

Bu tarz programlama dillerinde bazı yerlerde lojik ifade bekleniyor. (boolean bir ifade)
Aşağıdaki yerlerde ifadelerin lojik türden olması bekleniyor.

!expr
exp1 && exp2
exp1 || exp2
expr ? :
if (expr)
while (expr)
do ... while (expr)
for (;expr;)

if(1) -> Java dilinde bu sentaks hatası olur. Fakat C dilinde böyle değildir.

C dilinde lojik ifade beklenen yerlerde herhangi türden bir ifade kullanılabiliyor.
Ve bu ifade öncelikle bir lojik yorumlamaya tabi tutuluyor.
Çünkü işleme sokulabilmesi için doğru veya yanlış anlamında bir değer elde edilmesi gerekiliyor.

Lojik Yorumlama -> D Y

C dilinde, ifadenin aritmetik değerine bakılıyor.

Sıfır olmayan bütün değerler DOĞRU. TRUE. biçiminde yorumlanıyor.
Sıfır FALSE biçiminde yorumlanıyor.

non-zero -> TRUE
zero     -> FALSE

if (ival)
if (ival != 0)

Yukarıdaki iki ifadenin bir farkı yoktur. İkisi de aynı yorumlanıyor. 

Lojik ifade beklenen yerde, ifadenin aritmetik değerine bakılıyor. 
Non-zero bir değer DOĞRU olarak, zero bir değer YANLIŞ olarak yorumlanıyor.
Buna negatif değerler de dahildir. 
Önemli olan sıfır olmaması. Sıfırdan farklı tüm değerler DOĞRU olarak yorumlanacak.

    int ival = -5;
    if (ival)
        printf("DOGRU");
    else
        printf("YANLIS");

Tıpkı karşılaştırma operatörlerinde olduğu gibi lojik operatörlerin de ürettikleri değer
int türden 0 veya 1 değerini üretir.
-----------------------------------------

Lojik Değil Operatörü (!)

Yan Etkisi Yoktur. Nesnenin değeri yapılan işlemden etkilenmeyecektir.

İlk öncelikle operandının lojik yorumlanmasını sağlıyor,
Non-zero değeri doğru olarak kabul ediyor, 
ve doğrunun değili olarak yanlış anlamında 0 değerini üretiyor.

Operand 0 ise, yanlışın değeri olarak doğru değerini üretiyor.

!x

    int ival;
    printf("Bir tam sayi giriniz: ");
    scanf("%d", &ival);

    printf("!(%d) ---> %d", ival, !ival);

Bir ifadenin lojik değilinin değili, o ifadenin lojik değeridir.

x = 45

!!x -> 1

x = 0

!!x = 0

    int ival;
    printf("Bir tam sayi giriniz: ");
    scanf("%d", &ival);

    printf("!!(%d) ---> %d", ival, !!ival);

Lojik Ve Operatörü

11. Öncelik seviyesindedir. exp1 && exp2
Binary Infix operatörler. Operandları lojik olarak yorumlanıyor. int türden 1 veya 0 değerini üretiyor.

Bir de 8. öncelik seviyesindeki & operatörü var. (bitwise and - bitsel ve)

    int x, y;
    printf("Iki tam sayi girin: "); // 
    scanf("%d%d", &x, &y);

    printf("%d && %d = %d", x, y, x && y);
    //12 ve 9 -> 12 non zero doğru. 9 non zero doğru. doğru ve doğru -> doğru
    //12 ve 0 -> 12 non zero doğru. 0 zero yanlış. doğru ve yanlış -> yanlış

    int x, y;
    printf("Iki tam sayi giriniz: ");
    scanf("%d%d", &x, &y);  // 10 ve 20 degerleri
    if (x && y) //10 non zero 20 non zero - Dogru Dogru -> Dogru
        printf("lojik ve dogru\n");
    else 
        printf("lojik ve yanlis\n");

    if (x & y)  //burada ise işleme koyulan bizim tamsayilarimizin karşılıklı bitleri
        printf("bitsel ve dogru\n");
    else
        printf("bitsel ve yanlis\n");

    0000 1010 -> 10
    0001 0100 -> 20
    0000 0000 -> 0

    Bitsel ve bu durumda tam sayılarımızın karşılıklarını bitlerini karşılaştırıyor. 
    Bitsel operatörler operand olarak tam sayı türden operand alırlar. Double olamaz. Sentaks hatasıdır.

Lojik Veya Operatörü
11. Öncelik Seviyesindedir. exp1 || exp2
Binary Infix operatördür.
Operandlarını lojik olarak yorumlayacak. Veya işleminin işlem tablosuna göre int türden 0 veya 1 değerini üretecek.
exp1 | exp2 -> bir tane pipe karakteri yazarsak bitsel veya operatörü olur. Dikkat edilmesi gerekir.

    int x, y;
    printf("Iki tam sayi giriniz: ");
    scanf("%d%d", &x, &y);

    printf("%d && %d -> %d\n", x, y, x && y);
    printf("%d || %d -> %d\n", x, y, x || y);

    int x, y;
    printf("Iki tam sayi giriniz: ");
    scanf("%d%d", &x, &y);

    printf("%d ozel veya %d -> %d\n", x, y, !!x != !!y);


De Morgan Kuralları

!(exp1 && exp2) -> !exp1 || !exp2
!(exp1 || exp2) -> !exp1 && !exp2

Lojik ve operatörünün kullanılması gereken bir yerde programcının yanlışlıkla lojik veya operatörünü kullanması

if (x != 5 || x != 13) -> bu ifade always true. her zaman doğru olur. yanlış olma ihtimali yok.
    ///

yapılmak istenilen: x'in değeri 5 veya 10 değilse, 
dilde veya sözcüğü geçtiği için operatör olarak da veya operatörü kullanıyor.

ifadenin doğrusu: if (x != 5 && x != 13)

if (x != 5 ||x != 13)  -> always true bir ifadenin lojik değili always false.
if (x == 5 && x == 13) -> always false. 


Strict Ordering Rules

&& || ! < (sadece bu operatörlerle karşılaştırma yapmak)

!(a < b) -> bu ifade a >= b demektir.

    int x, y;
    printf("Iki tam sayi girin: ");
    scanf("%d%d", &x, &y);

    printf("(%d) < (%d) = %d\n", x, y, x < y);
    printf("(%d) > (%d) = %d\n", x, y, y < x);
    printf("(%d) >= (%d) = %d\n", x, y, !(x < y));
    printf("(%d) <= (%d) = %d\n", x, y, !(y < x));
    printf("(%d) == (%d) = %d\n", x, y, !(x < y) && !(y < x));
    printf("(%d) != (%d) = %d\n", x, y, (x < y) || (y < x));

-----------------------------------------------------------------------------------------

int get_mid(int a, int b, int c)
{
    // a ortancaysa demekle, a ortanca değilse demek arasında hiçbir fark yok.
    // a ortancaysa, a max ya da min değildir. 

    if (!(a > b && a > c || a < b && a < c))
        return a;
    if (!(b > a && b > c || b < a && b < c))
        return b;
    if (!(c > a && c > b || c < a && c < b))
        return c;
}

int main(){

    int x, y, z;
    printf("Uc tam sayi giriniz: ");
    scanf("%d%d%d", &x, &y, &z);

    printf("%d %d ve %d sayilarinin ortancasi -> %d", x, y, z, get_mid(x, y, z));
}

Bir ifade doğruysa demekle, bir ifade demek arasında bir fark yok. 
Bunlar birbirlerinin lojik değili.

Kısa Devre Davranışı
Short Circuit Behavior

if (x < 10) // bu if deyimi yanlış ise, alttaki if deyimi yapılmaz. oraya bakılmaz.
    if (y < 20)
        ++a;


if (x < 10 && y < 20)

Lojik Ve operatörünün ilk önce sol operandının işlemi yapılır, 
eğer yanlış ise, sağ operandı olan ifade hiç yapılmaz.

    ++a;

if (x < 10 || y < 20) 

Lojik Veya operatörünün ilk önce sol operandının işlemi yapılır, 
eğer doğruysa, sağ operandı olan ifade hiç yapılmıyor.

    int x = 0;
    int y = 23; 
    int z;
    
    z = x && ++y; // x'in değeri 0 olduğu için, sağ operandı olan ifadeye hiç bakılmayacak. kısa devre davranışı.
    
    printf("z = %d\n", z);
    printf("y = %d\n", y);

    ----------------------

    int x = 10, y = 23, z;
    
    z = x || ++y;
    
    printf("z = %d\n", z);
    printf("y = %d\n", y);

    ----------------------

    int func()
{
    printf("func cagrildi!\n");
    return 20;
}

int foo()
{
    printf("foo cagrildi!\n");
    return 10;
}

int main(){

    func() || foo(); // func geri dönüş değer 20. yani non zero bir değer. doğru. foo çağrılmayacak, kısa devre davranışı.
}

Bu arada, parametre değişkeni olmayan bir fonksiyona void yazmakla yazmamak arasında ne fark var.
Eğer fonksiyon tanımında void yazmazsak, fonksiyonun parametre değişkenin olmadığını değil,
Fonksiyonun parametrik yapısı hakkında bilgi vermediğimiz anlamına geliyor.


    int a[100];

    for (int i = 0; i < 100 && a[i] != 0; ++i)
        ; // bu kodun bu diziyi taşırma ihtimali yoktur. 
          // çünkü i'nin değeri 100 olduğunda i < 100 ifadesi yanlış olacak, kısa devre davranışı olacak.
          // ve operatörünün diğer operandındaki ifade hiç yürütülmeyecek.

Aritmetik Operatörler
Karşılaştırma Operatörleri
Lojik Operatörler
Atama Operatörleri

Atama Operatörleri (Assignment Operator)

to assign.

int x = 10; İlk değer verme sentaksındaki = operatörü atama değil, başlatma.

x'i 10 ilk değeriyle başlattım. Initialization.

= -> yalın atama operatörü

compoun assignment operator (işlemli atama operatörleri)

+= -= *= /= %= 

>>= bitsel sağa kaydırma =

<<= bitsel sola kaydırma = 

&= bitsel ve =

|= bitsel veya =

^= bitsel özel veya = 

= Atama Operatörü

14. Öncelik Seviyesindedir. Öncelik yönü Sağdan Sola.
Binary Infix. Iki operand alır, infix yani orta konumdadır.

Bir ifade içerisinde birden fazla atama operatörü olabilir.

Atama operatörlerinin sol operandı olan ifade L Value expression olmak zorundadır.

int x;

x = 5;
5 = x; //gecersiz
+x = 45; //gecersiz
x + 3 = 10 //gecersiz

Atama operatörlerinin de ürettiği bir değer vardır.
Kullanıp, kullanmamak bizim elimizde, discard da edebiliriz.
Atama operatörlerinin yan etkisi vardır. Side Effect.

x = 10; x'in değeri atama operatörünün nesneye atadığı değeri alır.

C ve C++ dillerinde atama operatörü nesneye atanan değeri üretir. 

x = y ifadesinin değeri, y ifadesinin değeridir.

int x = 10;

x = 7; bu ifadenin değeri 7'dir. x = 7 ifadesinin değeri 7. 

    int x = 10;

    printf("x = %d\n", x);
    printf("%d\n", x = 7);
    printf("x = %d\n", x);

Atama operatörünün ürettiği değer neden bizim için önemli?

Atama operatörünün ürettiği değeri kullanmıyorsak, 
discard ediyorsak, burada üretilen değer bizi ilgilendirmiyor.

C dilinde yazılan bir çok idiyomatik ifade atama operatörünün ürettiği değerden faydalanır.


    int x;

    x = func();
    if (x == -1){
        print("hata, func islevini yapamadı\n");
    }

    Yukarıdaki ifadeyi aşağıdaki şekilde yazabiliriz.
    ----------------------

    int x;

    if ((x = func()) == -1){ //Atama operatörünün ürettiği değerden faydalanıyoruz.
        print("hata, func islevini yapamadı\n");
    }

    ----------------------

    int ch;

    printf("Bir yazi girin: ");

    while((ch = getchar()) != '\n'){ //Atama operatörünün ürettiği değerden faydalanıyoruz.
        printf("%c %d\n", ch, ch);A
    }

    Yukarıdaki ifadeyi aşağıdaki şekillerde de yazabiliriz. 
    Fakat bu sefer gereksiz olur. Yukarıdaki daha anlamlı.
    ----------------------

    int ch;

    printf("Bir yazi girin: ");

    ch = getchar();
    while( ch != '\n') {
        printf("%c %d\n", ch, ch);
        ch = getchar();
    }

    ----------------------
    
    int ch;

    printf("Bir yazi girin: ");

    while(1) {
        ch = getchar();
        if (ch == '\n')
            break;
        printf("%c %d\n", ch, ch);
    }

Atama operatörünün ürettiği değerden faydalanmak C dilinde en sık karşılaşılan idiyomlar arasındadır.

int foo(void);

int main(){
    int x, y, z, t;

    t = foo();
    z = t;
    y = z;
    x = y;

    Atama operatörünün öncelik yönü sağdan sola, aşağıdaki şekilde de yapabiliriz.
    ----------------------

    int x, y, z, t;

    x = y = z = t = foo();
}

Atama operatörünün ürettiği değer nesneye atanmış olan değerdir.

    int x;
    double dval = 4.24;

    x = dval;   //Atama operatörünün ürettiği değer sağ operandın değeri değildir! 
                //Nesneye atanmış olan değerdir.

Atama operatörünü kullanırken karşılaştırma operatörü ile karıştırmak.

x == y (x'in değeri değişmeyecek)
x = y (x'in değeri değişecek)

    int x;
    printf("bir tamsayi girin: ");
    scanf("%d", &x);

    if(x = 5) // burada == kullanmak yerine = operatörünü kulladık. x'yi karşılaştırmadık, atama yaptık.
              // x = 5 lojik yorumlandığında non zero bir değer olacağı için, if deyiminin evet doğru kısmına girecek.
    {
        printf("Evet dogru. x = %d", x);
    }
    else 
    {
        printf("Hayir yanlis. x = %d", x);
    }

    ----------------------

    int x;
    printf("Bir tamsayi giriniz: ");
    scanf("%d", &x);

    if (x = 0) // 0 girdiğimizde, lojik yorumlanacak ve if deyiminin else kısmına girecek.
    {
        printf("Evet dogru. x = %d", x);
    }
    else
    {
        printf("Hayir yanlis. x = %d", x);
    }

Eğer bir L value ifadesiyle, bir R value ifadesini == operatörü ile karşılaştıracaksak,

Lval == Rval yazmak yerine,

Rval == Lval yazmamız lazım. Anlam açısından hiçbir fark yok. 

Fakat = kullanımında operatörü istediğimiz gibi yazmak için bu yolu kullanabiliriz.

İşlemli Atama Operatörleri - Compound Assignment Operators

x = x + 5; // bu ifade x'in 5 artmasını sağlıyor.
x = x * 2; // x'i 2 katına çıkart.
y = y / 3; // y'i 3'e böl.
z = z % 10; // z'nin mod10'u.

x += 2;
x *= 2;
x /= 3;
z %= 10;

Aradaki farkı nedir, daha mı iyi kod üretiliyor. HAYIR!
Asla bir programda, mikro düzeyde kod yazarken, bir optimizasyon yapmaya çalışmayın.
Kodu yazarken kodu optimize etmeye çalışmayın.

Early Optimization is evil!

Mikro düzeyde optimazyon yapmaya çalışırken kodu daha kötü daha kalitesiz, 
hata yapılabilir bir biçime getiriyoruz.

Programda bir darboğaz varsa, öncelikle programımızın nerede vakit kaybettiğini bulup,
o kısımlarda işlem yapmamız gerekiyor. Bunun için de araçlar var, toolar var.
Profiler.

Bunun ideali, kodun derleyici tarafından optimize edilmesini sağlamak.
Derleyiciler bu konuda çok becerikli.

x = x + 5; // bu şekilde yazmayın!

x += 5;
x *= 3;

İşlemli atama operatörlerinde de ürettiği değer atanan değerdir.

----------------------

int sum_digit(int val)
{
    int sum = 0;

    while(val != 0){
        sum += val % 10;
        val /= 10;
    }

    return sum;
}

int main(){

    int ival;
    printf("Bir tam sayi girin: ");
    scanf("%d", &ival);

    printf("Basamaklari toplami: %d", sum_digit(ival));
}

----------------------

#include <stdio.h>

int main(){

    int day, hour, min, sec;
    printf("sureyi gun saat dakika ve saniye olarak giriniz: ");
    scanf("%d%d%d%d", &day, &hour, &min, &sec);

    //2 gün 54 saat 135 dakika 189 saniye

    min += sec / 60;
    sec %= 60;

    hour += min / 60;
    min %= 60;

    day += hour /24;
    hour %= 24;

    printf("%d gun %d saat %d dakika %d saniye", day, hour, min, sec);
}

*/
