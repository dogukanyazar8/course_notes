/*

Ders10

Operatörler (OPERATORS)

Operator
Operand
Operand Sayısı (Unary, Binary, Turnary)
Operator ile Operand Konumsal İlişkisi (Prefix, Postfix, Infix)
Operator Kısıtlamaları (Constraints)
C dilinde her operatör bir değer üretir.
Operatör Önceliği

Operatör önceliği bir işlemin bir işleme göre fiziksel olarak daha önce ya da daha sonra yapılacağı anlamına gelmiyor!

int func(void)
{
    printf("func cagrildi\n");
}

int foo(void)
{
    printf("foo cagrildi\n");
}

int main()
{
    int x;

    x = func() + 5 * foo(); //Burada hangisi daha önce çağrılacak, func mı foo mu?
}

Yukarıdaki x'e yapılan atama ifadesinde, hangi fonksiyonun daha önce çağrılacağı unspecified behavior, derleyici istediği kodu üretebilir.

x = func() + 5 * foo();

(5 * foo()) bu işlemden elde edilen değer, toplama operatörünün sağ operandı olacak.

func() + (5 * foo())

C dilinde operatör önceliği nasıldır?

Operatör Öncelik Tablosu

! ->> Logical Not
~ ->> Bitwise Not

--------------------------------------------------------------------------------------
1   ()  []  .   ->                                                              
--------------------------------------------------------------------------------------
2   +   -   !   ~   &   *   sizeof (type)   ++  -- (* dereference)      RIGHT TO LEFT
--------------------------------------------------------------------------------------
3   *   %   /
--------------------------------------------------------------------------------------
4   +   -   (toplama ve çıkartma operatörleri)
--------------------------------------------------------------------------------------
5   >>  << (bitwise right and left shift)
--------------------------------------------------------------------------------------
6   <   <=  >   >=
--------------------------------------------------------------------------------------
7   ==  !=
--------------------------------------------------------------------------------------
8   & (bitsel ve)
--------------------------------------------------------------------------------------
9   ^ (bitsel xor)
--------------------------------------------------------------------------------------
10  | (bitsel veya)
--------------------------------------------------------------------------------------
11  && (logical and)
--------------------------------------------------------------------------------------
12  || (logical or)
--------------------------------------------------------------------------------------
13  ? (turnary operator)                                                RIGHT TO LEFT                                                   
--------------------------------------------------------------------------------------
14 = += -= *= /= %= >>= <<= &= ^= |=                                    RIGHT TO LEFT
--------------------------------------------------------------------------------------
15  , (comma operator)
--------------------------------------------------------------------------------------

Her öncelik seviyesinin bir öncelik yönü vardır. Associativity

Left Associative    Soldan Sağa
Right Associative   Sağdan Sola

3 tane öncelik seviyesi dışından, bütün öncelik seviyelerinin yönü soldan sağa.
Unary operatörlerini koyduğumuz 2. öncelik seviyesi.
Koşul operatörünün bulunduğu 13. öncelik seviyesi.
Atama operatörlerinin bulunduğu 14. öncelik seviyesi.

Associative ne demektir?

x++ * y - 10 / 5 < z % 2

Derleyici, biz hiç öncelik parantezi kullanmamış olsak da, bu ifadeyi aşağıdaki gibi yorumlayacak. Operatör önceliğine göre.

(((x++) * y) - (10 / 5)) < (z % 2)

a * b - 5 > 10

((a * b) - 5) > 10

x * y / z % t

((x * y) / z) % t

x * (y / z) % t ->>>>>>> Aynı öncelik seviyesinde olan operatörlerde, öncelik parantezi kullanarak kendimiz önceliği belirleyebiliriz.

!~x++ 

! ~ ve ++ 2. öncelik seviyesinde. sağdan solda. right associative. Öncelik bu şekildedir -> !(~(x++)) 

+ - * & gibi tokenları derleyici nasıl ayırt ediyor?

Bu operatörlerin unary veya binary olmasından dolayı anlıyor. Operand sayısına göre yani.

a = *ptr * 5;

*ptr ifadesindeki * derefencing operatorü. unary, tek operandlı.

*ptr * 5 ifadesindeki * ise binary, multiplication operatörü, binary, iki operandlı.

a = ((*ptr) * 5);

x *= y += z %= t; //buradaki operatörlerin hepsi aynı seviyede, operatör öncelik yönü ise sağdan sola.

x *= (y += (z %= t))

Operator Önceliği -> Operator Presedence / Operator Priority
Operator Öncelik Yönü -> Associativity 

-----------------------------------------------------------------------------------------

Side Effect (Yan Etki)

Yan etki, programda bir durum değişikli demektir.

Mesela bir değişkenin değerinin değişmesi bir yan etkidir.
Dışsal bir aygıta bir çıkış işleminin yapılması, bir yan etkidir. (Giriş çıkış işlemleri)

Tüm operatörler bir değer üretir fakat bazı operatörlerin yaptırdığı işlem sonucunda bir nesneni değeri değişir.

!x //bu operatörün yan etkisi var mıdır? logic değil operatörünün yan etkisi yoktur. bu işlemden sonra nesneni değerini değiştirmez

a + b //bu operatörün yan etkisi var mıdır? toplama operatörünün yan etkisi yoktur, a veya b değişkeninin değerini değiştirmiyor.

x++ // bu operatörün yan etkisi vardır. ++ operatörü, operandı olan nesnenin değerini 1 arttırıyor.


Neden bu durum için side effect, yan etki terimi kullanılmış?

Çünkü operatörün asıl işlevi bir değer üretmek. 
Operatörün bir değer üretmesi başka bir durum
bu işlem esnasında bir değişkenin değerinin değişmesi başka bir durum.

Yan Etkisi Olan Operatörler

++
--
=
*= += -= /= (tüm işlemli atama operatörleri)

//Aşağıdaki programda x'in değeri değişmez. Yan etki yoktur. Logic değil operatörü yan etki üretmez.

int x = 248;

!x;

printf("X = %d", x);

//Aşağıdaki programda x'in değeri değişir. Yan etki vardır. ++ Operatörü yan etki üretir.

int x = 248;

++x;

printf("X = %d", x);

//Aşağıdaki programdaki x'in değeri değişir. Yan etki vardır. İşlemli atama operatörü yan etki üretir.

int x = 24;

x /= 2;

printf("X = %d", x);

-------------------------------------------------------------------

Value Category (Değer Kategorisi)
    L Value Category
    R Value Category

Değer kategorisi, C dilinde bir ifade nitelendiriyor. 
Ya sol taraf değeri olacak ya da sağ taraf değeri olacak. İkisi birden olamaz.

Bir ifadenin hangi değer kategorisinde olduğunu anlamak için, o ifadeyi adres operatörünün operandı yapabiliriz.
Hata vermiyorsa, o ifade sol taraf değeridir. Hata veriyorsa sağ taraf değeridir.

C dilinde bazı operatörlerle oluşturulan ifadeler R taraf değeri olabilir,
C++ dilinde sol taraf değeri olabiliyor.

    int x;

    x + 5;  -> R Value Expression / Sağ Taraf Değeri

    +x;     -> R Value Expression / Sağ Taraf Değeri

    ++x;    -> R Value Expression / Sağ Taraf Değeri

    x = 5;  -> R Value Expression / Sağ Taraf Değeri

Operatörlerin Gruplandırılması

Aritmetik Operatörler
    C dilinde aritmetik işlem yapılmasını sağlıyorlar.
        + - (işaret operatörleri) ++ --
        * / %
        + - (toplama çıkarma operatörleri)
-------------------------------------------------------------------
İlişkisel Operatörler (Relational Operators)
    C dilinde karşılaştırma yapılmasını sağlıyorlar.
        > >= < <=
        == !=
-------------------------------------------------------------------
Mantıksal Operatörler (Logical Operators)
    C dilinde mantıksal işlemlerin yapılmasını sağlıyorlar.
        !   &&  ||
-------------------------------------------------------------------
Atama Operatörleri (Assignment Operators)
    C dilinde atama işlemlerinin yapılmasını sağlıyorlar.
        = += -=
Pointer Operatörleri
        & address of
        * [] dereferencing
        index / subscript
        -> (member selection - arrow operator)
-------------------------------------------------------------------
ternary operator
sizeof
type-cast

, virgül operatörü (comma operator)
 
+= veya -= gibi operatörlere compound assignment operators deniliyor.
İşlemli Atama Operatörleri
-------------------------------------------------------------------
                            OPERATÖRLER
-------------------------------------------------------------------
Topalama ve Çıkarma Operatörü

Binary Infix (iki operand, orta operatör konumunda)
Operandları L value veya R value expression olabilir.
Oluşturulan ifadenin kendisi de R value expressiondır.
Her iki operatör de 4. öncelik seviyesinde ve SOLDAN SAĞA öncelik yönüne sahiptir.
Her iki operatörün de yan etkisi yoktur.

İşaretli tam sayı türlerinde taşma, tanımsız davranıştır.

Dolayısıyla bu operatörleri kullanırken dikkat edilmesi gerekiyor. 
İşlemden elde edilecek değer, ilgili türün taşıyabileceği değer aralığı içinde değilse, taşma olacak.

İşaretsiz türlerde taşma tanımsız davranış değildir.

    int x, y;
    printf("iki tam sayi giriniz: ");
    scanf("%d%d", &x, &y);

    printf("%d + %d + %d\n", x, y, x + y);
    printf("%d + %d = %d\n", x, y, x - y);

Bir de işaret operatörleri var. Unary olarak kullanıldıklarında bunlar işaret operatörüdür.
2. öncelik seviyesindedir.
İşaret operatörleri yan etkiye sahip değildir.
Nesnenin değerini değiştirmez fakat value kategorisini değiştirir.

-x ->>> 0 - x
+x ->>> 0 + x 

    int ival;

    +ival;  ->>> Burada L value olan ival, işaret operatörünün operandı yaptığımızda R value kategorisinde oluyor.

    +ival = 24; ->>> Bu geçersiz bir ifadedir.

- İşaret Operatörü

    int x;

    printf("bir tam sayi girin: ");
    scanf("%d", &x);

    x = -x;

    printf("X = %d", x);

        int x, y;

        printf("bir tam sayi girin: ");
        scanf("%d", &x);

        y = -x - 5; ->>> -x işaret operatörü -, diğer - ise çıkartma operatörü olan -.

        printf("Y = %d", y);

Çarpma, Bölme, Mod Operatörler (Multiplication, Division, Modulus(Remainder))

Bu operatörler 3. öncelik seviyesindedirler.
Bu 3 operatör de 3. öncelik seviyesinde ve SOLDAN SAĞA öncelik yönüne sahiptir.
Binary Infix Operatörlerdir (iki operand, orta operatör konumunda)
Oluşturulan ifadenin kendisi de R value expressiondır.
Bu 3 operatörün de yan etkisi yoktur.

x * y
x / y
x % y

C dilinde, tam sayıyı tam sayıya bölerek, gerçek sayı elde edemeyiz.

int x = 10;
int y = 3;

x / y -> sonuç bir tam sayı olmak zorundadır. 3. int.

Yuvarlama yapılmaz. Ondalık kısım kaybedilir. (Truncation)

Tam sayı işlemlerinde 0'a bölmek, tanımsız davranıştır. Sağdaki operandın 0 olmamasından biz sorumluyuz.

Mod operatörü bazı programlama dillerinden farklı olarak, C dilinde bir tam sayı operatörüdür. 
Mod operatörünün sol veya sağ operandının gerçek sayı olması sentaks hatasıdır.

C dilinde bir gerçek sayının bir gerçek sayıya bölümünden kalanı operatör seviyesinde bir işlemle elde edemiyoruz.
Bu işlemi yerine getirmek için ideal olan yol standart bir c fonksiyonu kullanmaktır. fmod fonksiyonu.

x % y

    float x, y;

    printf("Iki sayi giriniz: ");
    scanf("%f%f", &x, &y);

    printf("%f / %f = %lf", x, y, fmod(x, y));

Mod operatörü de özünde bir bölme işlemi içerdiğinden sağ operandının 0 olması tanımsız davranıştır.

Kodlama Editörlerine Dair Ek
CTRL - D tuş kombinasyonu imlecin bulunduğu satırın bir kopyasını çıkartır.
CTRL - SHIFT - L tuş kombinasyonu imlecin bulunduğu satırı siler.

    int x, y;

    printf("Iki tam sayi giriniz: ");
    scanf("%d%d", &x, &y);

    printf("%d * %d = %d\n", x, y, x * y);
    printf("%d / %d = %d\n", x, y, x / y);
    printf("%d %% %d = %d\n", x, y, x % y);

    int x;

    printf("4 basamakli bir tam sayi girin: ");
    scanf("%d", &x);

    printf("binler basamagi = %d\n", x / 1000);
    printf("yuzler basamagi = %d\n", x % 1000 / 100); //veya x / 100 % 10
    printf("onlar basamagi = %d\n", x % 100 / 10); //veya x / 10 % 10
    printf("birler basamagi = %d\n", x % 10);

Öncelik parantezi kullanmasak da, bu operatörlerin yönü soldan sağa olduğu için derleyici bunu bu şekilde algılayacak.
    
    int x;

    printf("4 basamakli bir tam sayi girin: "); // 1234
    scanf("%d", &x);

    printf("%d sayisinin basamaksal tersi %d\n", x, 
    x / 1000 + 
    x / 100 % 10 * 10 + 
    x / 10 % 10 * 100 + 
    x % 10 * 1000);

    int hour, n;

    printf("Saat kac? ");
    scanf("%d", &hour);
    printf("Kac saat sonrasi? ");
    scanf("%d", &n);

    printf("saat %d ve %d saat sonra %d olacak.\n", hour, n, (hour + n) % 12);

Arttırma ve Eksiltme Operatörleri (Increment & Decrement Operators) plusplus & minusminus

Operatör öncelik tablosunda 2. öncelik seviyesindir.
Operandları L value ifadeleri olmak zorundadır. Sol taraf değeri olmalıdır.
Unary operatörlerdir. Tek operand alırlar. Prefix ve Postfix konumları vardır.
Bu operatörler ister ön ek ister son ek olarak kullanılsınlar, yan etkileri vardır. Side Effect.

++x ön ek   (prefix ++)
x++ son ek  (postfix ++)

--x ön ek   (prefix --)
x-- son ek  (postfix --)

++ -> Operandı olarak aldığı nesnenin değerini 1 arttırıyor.
-- -> Operandı olarak aldığı nesnenin değerini 1 azaltıyor.

x++
x = x + 1;
x += 1;

Bir nesnenin değerini değiştirmek için ön ek veya son ek ++ operatörünü kullanmanın hiçbir farkı yoktur.
ÖNERİ: Bu tür durumlarda ön ek konumunu kullanmak kodun okunması ve göz aşinalığı açısından daha sağlıklı olur.

    int x = 20;
    printf("x = %d\n", x);
    x++;
    printf("x = %d\n", x);
    ++x;
    printf("x = %d\n", x);
    x--;
    printf("x = %d\n", x);
    --x;
    printf("x = %d\n", x);

++ ve -- operatörleri son ek (postfix) konumunda kullanıldıkları zaman operandı olan nesnenin değerini üretiyorlar.

    int x = 20;
    printf("X: %d", x++);

    int x = 20;
    int y;

    y = x++;

    //yukarıdaki deyimi aşağıdaki şekilde de yazabiliriz. ama yukarıdaki deyim çok daha sık kullanılan bir idiom.
    //y = x;
    //x = x + 1;

    printf("y = %d\n", y);
    printf("x = %d\n", x);

Sonuç açısından ikisinin de bir farkı yok. Ama ikinci ifade daha sık kullanılıyor.

    func(x);
    x = x + 1;

    func(x++)

ön ek ++ ve -- operatörlerinin ürettiği değer nesnenin değerinin 1 fazlası veya 1 eksiğidir.

    int x = 20, y = 20;
    printf("%d\n", ++x);
    printf("%d\n", --y);

    printf("X = %d\n", x);
    printf("Y = %d\n", y);

    int x = 20;
    int y;

    y = ++x;

    Yukarıdaki deyimi aşağıdaki gibi de yazabiliriz.
    x = x + 1;
    y = x;

    int a[100] = { 0 };
    int idx = 34;

    a[idx++];    // dizinin 34 numaralı elemanına erişeceğiz. 
                 //arttırma operatörü son ek konumunda, operandı olan nesnenin değerini üretir.
    
    int a[100] = { 0 };
    int idx = 34;

    a[++idx];    // dizinin 35 numaralı elemanına erişeceğiz. 
                 //arttırma operatörü ön ek konumunda, operandı olan nesnenin bir fazlasını üretir.
  
    int x = 12, y = 7;

    printf("%d\n", ++x % y--); // 13 % 7 = 6
    // x -> 13 y -> 6
    printf("%d\n", x++ % --y); // 13 % 5 = 3

    int x = 12;

    printf("%d\n", x++); //12 yazılır ekrana
    printf("%d\n", ++x); //14 yazılır ekrana
    printf("%d\n", x);  //14 yazılır

KARŞILAŞTIRMA OPERATÖRLERİ

6. Öncelik seviyesi -> < <= > >=        SOLDAN SAĞA ÖNCELİK YÖNÜ
7. Öncelik seviyesi == !=               SOLDAN SAĞA ÖNCELİK YÖNÜ

C++, Java gibi dillerde karşılaştırma operatörleriyle oluşturulmuş veri türü dilin lojik veri türüdür.
Boolean, bool.

a > b -> ifadenin türü bool. ifadenin değeri true veya false

Fakat C dilinde karşılaştırma operatörleri işaretli int türünden değer üretir.

a > b -> ifadesinin türü int. ifadenin değeri ise eğer önerme doğru ise ifadenin değeri 1, eğer önerme yanlışsa ifadenin değeri 0

Bu kural bütün karşılaştırma operatörleri için geçerlidir.

Peki diller arasındaki bu konuda fark nedir, fark eden C dilinde karşılaştırma operatörlerinin ürettiği 1 veya 0 değeri, bir çok C idiomunda aritmetik ifadelerde de kullanılıyor.

x = y == z; = -> atama operatörü == karşılaştırma operatörü

Yukarıdaki ifadede eğer y, z'ye eşitse, x'e 1 atanacak, eşit değilse 0 atanacak.

x = y == z;

Aşağıdaki ve yukarıdaki ifadeler aynı anlamdalar.

if(y == z)
    x = 1;
else
    x = 0;

-----------------------------------------------

    int x, y;
    printf("Iki tam sayi giriniz: ");
    scanf("%d%d", &x, &y);

    printf("%d > %d = %d\n", x, y, x > y);
    printf("%d >= %d = %d\n", x, y, x >= y);
    printf("%d < %d = %d\n", x, y, x < y);
    printf("%d <= %d = %d\n", x, y, x <= y);
    printf("%d == %d = %d\n", x, y, x == y);
    printf("%d != %d = %d\n", x, y, x != y);

İşaret Fonksiyonu

x > 0  -> 1 
x < 0  -> -1
x == 0 -> 0

    int x;
    printf("Bir tam sayi giriniz: ");
    scanf("%d", &x);

    printf("sign (%d) = %d\n", x, (x > 0) - (x < 0));

-----------------------------------------------

    int x, y, z, t;
    int pos_cnt = 0;
    printf("4 sayi giriniz: ");
    scanf("%d%d%d%d", &x, &y, &z, &t);

    if(x > 0)
        ++pos_cnt;
    
    if(y > 0)
        ++pos_cnt;
        
    if(z > 0)
        ++pos_cnt;

    if(t > 0)
        ++pos_cnt;

    //pos_cnt = (x > 0) + (y > 0) + (z > 0) + (t > 0); Yukarıdaki kodu bu şekilde de yapabiliriz.
  
    printf("pos_cnt = %d", pos_cnt);

C dili matematiksel notasyona yakın olduğundan dolayı yeni başlayan bir ifade yazarken yanlış yazabilir.

-b / 2a ifadesi. 

-b / 2 * a ->  c dilinde yukarıdaki ifadeyi bu şekilde yazamayız, operatör önceliğinden dolayı.

-b / (2 * a) veya -b / 2 / a

if (10 < x < 20) //bu ifade C dilinde her zaman doğrudur. always true. aralık testini bu şekilde yazamayız.

10 < x => 1 olduğunda veya 0 olduğunda 20 den küçük olacağı, always true.

if(x > 10 && x < 20) bu şekilde yazılabilir.

if (x = 5)  //x değişkenine 5 atadık. always true.
if (x == 5) //karşılaştırma operatörü olan ==, burada üretilen değer 0 veya 1.

Gerçek sayıları birbirleriyle eşitlik karşılaştırmasına sokmayın!
Gerçek sayıları == ile karşılaştıramayız.

d1 == 1.0 //yanlış bir ifade

    double dval = 0.;

    for(int i = 0; i <10; ++i){
        dval += 0.1;
    }

    printf("dval = %f\n", dval);

    if(dval == 1.)
        printf("Evet dogrudur\n");
    else
        printf("Hayir yanlistir\n");
        

float, 4 bytelık. mantissa kısmı 23 bit.
0.1 sabiti ise double türden bir sabit. mantissa kısmı daha fazla. 
double türden float türüne kopyalama yaptığımızda hassasiyet farkı oluyor.
0.1 f'ye atandığında, ondalık kısmı daha az bitle temsil edildiği için değer kaybı oluyor.

    float f = 0.1;

    if(f == 0.1)
        printf("Evet dogru.");
    else
        printf("Hayir yanlis.");

İki gerçek sayıyı nasıl karşılaştıracağız?

Bu gerçek sayılar yeteri kadar birbirine yakınsa, bunları eşit kabul edeceğiz.

dx == dy yapmak yerine 

fabs(dx - dy) < e

-----------------------------------------------

Lojik Operatörler

Lojik işlemlerin operandları normalde önermelerdir.

p       doğru   yanlış
değil   yanlış  doğru
---------------------------
p   q     p ve q
D   D       D
Y   D       Y
D   Y       Y
Y   Y       Y 
---------------------------
p   q    p veya q
D   D       D
Y   D       D
D   Y       D
Y   Y       Y 

*/