/* 

Ders12

Sequence Point (Sequencing)
Yan Etki Noktası

Kaynak kodda yazdığımız bazı ifadeler, durum değişikliğine neden oluyordu.
Buna yan etki (side effect) diyoruz.
Dışsal bir aygıta, bir çıkış işleminin yapılması, bir side effect.

Bazı programlama dillerinde hiçbir yan etki yok. (immutable)

Kaynak kodda öyle bir nokta ki, bu noktadan önceki kodlardan oluşan yan etkiler, 
bu noktadan sonra gerçekleşmiş olmak zorundadır. Bu noktalara sequence point denir.

Bir değişkenin değerinin değişmesi bir yan etkidir. Side Effect.
Eğer yan etkiye uğramış bir nesneyi bu yan yetkinin gerçekleşmiş olmak garantisi olmadan 
yeniden kullanmak tanımsız davranıştır. UB

Tanımsız Davranış: Programın çalışma zamanında, ne şekilde davranacağının hiçbir garantisi yok.
Buna programcının beklentisi de dahil.

int x = 10;

++x;

(peki yukarıdaki kodda, x'in değeri tam olarak ne zaman değişecek?)

C dilinde sequence point olan noktalar:

1) Deyim Sonu

x = y;
func(x);

int a = 56;
++a;
b = a;

2) 4 Tane Operatör

Bu operatörlerin hepsi bir yan etki noktası oluşturuyor. Sequence point.

exp1 && exp2    (Logical And)
exp1 || exp2    (Logical Or)
a > 10 ? b : c  (Turnary Operator)
++x, y = x;     (Comma Operator)

x++ && func(x) -> kısa devre yapmazsa, func fonksiyonu x'in artmış değeriyle çağrılır.
x++ || func(x) -> aynı durum veya operatörü için de geçerli.

İlk değer verme listesindeki virgül de bir yan etki noktası oluşturuyor.

    int x = 10, y = x++, z = x + y;
    printf("%d - %d - %d", x, y, z);

    ------------------------------

    int x = 10, a;

    if (x++ > 9)
        a = x; //burada x'e 10 mu atanacak, yoksa 11 mi?
                 Burada yan etki noktası if parantezi. 11 atanacak.

Aynı durum while döngüsünün kontrol parantezi içinde de geçerli.

    n = 5;
    while(n-- > 0)
    func(n);

For döngüsünün de noktalı virgülle ayrılan ifadelerde yan etki noktaları var.

    for (int i = 10; i++ < 20; )

    ------------------------------

    int x = 10;
    int y = x + ++x;    // UB - Tanımsız davranış. 
                        //Yan etkiye uğramış, yan etki noktası gerçekleşme garantisini olmadan kullandık

    printf("y = %d", y);

    ------------------------------

    int x = 10;

    int y = x + (x = 90); // UB - Tanımsız Davranış

    printf("Y : %d", y);

    ------------------------------

    x++ + y

    x: 11
    y: 5
    z: 15

Tokenizing
Maximum Munch Kuralı
Derleyici derleme zamanında ilk olarak kaynak kodu atomlarına ayırıyor.
Boşluk yani whitespace karakterler doğal bir atom ayırıcıdır.

Bir ifadede boşluk karakteri yoksa, bu durumda atomlarına ayırma - tokenizing nasıl yapılıyor?

Atomlarına ayırma kuralı şu şekilde, 
Derleyici kaynak dosyadan boşluk karakteriyle karşılaşmadığı sürece teker teker karakterleri çekiyor.
Derleyici olabilecek en uzun atomu elde etmeye çalışıyor. Maximum Munch kuralı.

sum++>>=nec--;

tokenizing
1. atom -> sum
2. atom -> ++
3. atom -> >>=
4. atom -> nec
5. atom -> --

    ------------------------------

    int x = 10, y = 5, z;

    z = x+++y; //Burada derleyici tokenizing yaparken, x++ + y şeklinde tokenlarına ayıracak.

    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);

    x = 11, y = 5, z = 15

Kodlama editörleri kodu yazarken maximum munch kuralını anlık olarak uygulayabilir. 
İfadeye boşluk karakteri ekleyebilir.

Virgül Operatörü (Comma Operator)

C dilinde virgül opetörü problemli bir atomdur. İki ayrı kullanım amacı vardır.
Kaynak koddaki bazı virgül operatörleri ayraç, bazıları operatör.
, Ayraç (delimeter, separator)
, (operator)

Virgül bazı durumlarda sentaksın bir bileşenidir. Sentaks o durumda virgül kullanılmasını istiyor.
Ama bir de ifade içerisinde kullanılan virgül var, oradaki virgül ise virgül operatörüdür.

Virgülün operatör olmadığı durumlar;

int x, y, z; -> buradaki virgüller operatör mü değil mi? değil, hayır değil.
func(x,y) -> hayır operatör değil.
int a[] = {1, 2, 3, 4} -> hayır operator değil. comma seperated list.

------------------------------
Virgül Operatörü
Operatör öncelik tablosunun en sonunda. 15. seviyede.
Virgül operatörü atama operatörlerinden bile daha düşük öncelik seviyesindir.
Binary Infix bir operatördür. İki ek alan, ara operator konumunda.

x++, y--
a = b, b = c
5,7 -> virgül operatörünün sol operandı 5 sabiti, sağ operandı 7 sabiti.

Virgül operatörü bir yan etki noktası oluşturur. Sequence point.
Virgül operatörünün sol operandından sonra bir yan etki noktası vardır.

    int x = 10;
    int y = 20;
    int z;

    x++, y = x, z = x + y; //bu bir ifade
    //ilk öncelikle x++ bu ifade yapılır
    //ardından y = x
    //son olarak z = x + y

    printf("z = %d", z);

    ---------------
Yukarıdaki ifadeyi aşağıdaki şekilde de yazabiliriz. 
Anlamsal olarak hiçbir fark yoktur.
Sonuç açısından hiçbir şey farketmez.

    x++;
    y = x;
    z = x + y;   

    ---------------

a = b, b = c
İlk önce virgül operandın sol operandı olan işlem yapılır, ardından sağdaki.

    ---------------

    int x = 10, y = 20, z = 30;

    ++x;
    ++y;
    ++z;

    //yukarıdaki ifadeyi aşağıdaki şekilde de yazabiliriz.
    //anlamsal olarak hiçbir fark yoktur.

    ++x, ++y, ++z;

Peki neden bu şekilde bir ifade yazıyoruz?
İlk olarak bu tamamen programcının kendi isteği olabilir.
İfadenin arasındaki mantıksal ilişkiyi daha iyi vurgulamak için, kodun okunmasını kolaylaştırmak için.

Öyle yerler var ki, dilin kuralına göre birden fazla ifade deyimi yazamıyoruz.
Bu ifadeleri virgül operatörü ile birleştirip, tek bir ifade yapabiliriz.
Örnek for döngü deyimi.

for (i = 1, k = 2; i * 10000; i++, k += i)

blok eliminasyonu

if (x > 10) 
    ++a; //bu if deyimi sadece a'nın değerini arttırır. 
    ++b; //birden fazla deyim olduğundan dolayı, virgül operatörü ile tek bir ifade de yazabiliriz.
    
if (x > 10)
    ++a, ++b;

if (x = func(), x > 10) gibi bir ifade yazılabilir.

Virgül operatörü bir de ön işlemci komutlarında bazı hilelerin yapılmasında kullanılıyor.

Virgül operatörünün ürettiği değer ise sağ operandın değeridir.

    int x = 10, y = 20, z;

    z = (x, y); // virgül operatörünün ürettiği değer, sağ operandın değeridir.

    printf("z = %d", z); // z = 20

Virgül operatörünün ürettiği değer ile ilgili idiyomlar.

if (x = func(), x > 0) // bu bir ifade. virgül de operatör.
Virgül operatörü yukarıdaki ifadede sequence point oluşturur. önce atamada yapılır. 

if'in doğru kısmına girip girmeyeceğini belirleyen koşul, sağ operandın değeridir. x > 0

bu ifadenin anlamı aşağıdaki şekildedir.

x = func();
if(x > 0){
}

Virgülün bir operatör olması, aynı zamanda çok sık yapılan kodlama hatalarının da kaynağıdır.

    double dval = 3.4;

    if( dval > 2,0) // gerçek sayı sabiti yazarken nokta yerine virgül kullanmak.
                    //bu şekilde yazdığımız için virgül operatörünün sol operandı dval > 2 oldu sağ operandı ise 0.
                    //virgül operatörünün ürettiği değer de sağ operandın değeri, yani bu ifade için 0. hep yanlış kısma girecek.
        printf("Evet dogru!");
    else
        printf("Hayir yanlis!");

Gerçek sayı sabiti yazarken, nokta karakteri yerine virgül karakteri koymak sık yapılan bir hatadır.

7.5 - bir gerçek sayı sabiti. ifadenin türü double
7,5 - bu da bir sabit ifadesi, ifadenin türü int. değeri 5. 
5,0 - bu bir sabit ifadesi, lojik yorumlandığında sağ operandın değeri 0 olduğundan, false olarak yorumlanacak.

programcının dikkatini ölçmek için nokta yerine virgül yazılabilir.

    for (double d = 2.1; d < 3,0; d += 0.2) // d < 3, 0 -> false olacak, döngüye girmeyecek. sağ operand değeri 0.
    printf("*");

Operatör olan virgül ile Ayraç olan virgül atomu

func(x, y)  -> func fonksiyonu x ve y değerleri ile çağrılacak.
foo((x, y)) -> foo fonksiyonu x,y virgül operatörünün sağ operandı olan y değeri ile çağrılacak.

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //diziye ilk değer verme sentaksı. burada virgül operatör değil. comma separated list.
    //diziye ilk değer verme sentaksında, dilin kuralına göre, kullanılan initializer sayısı dizinin belirtilen boyutundan daha az ise,
    //ilk değer verilmeyen bütün değerler 0 olmak zorundadır.

    for(int i = 0; i < 10; ++i){
        printf("%d ", a[i]);
    }

    //bir diziye ilk değer verme sentaksında aşağıdaki gibi comma separated listi parantez içine alırsak,
    //virgül operatörünün ürettiği değer sağdaki operandın değeri olacağından,
    //diziye ilk değer olarak 10 değeri verilir.

    int a[10] = {(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)};

C dilinde virgül operatörü ile oluşturulan ifadenin sağ operandı,
L value expression olsa dahi, ifadenin kendisi R valuedur.

    int x = 45, y = 67;

    (x, y) = 90; //C dilinde geçersiz. C++'da geçerli. C++'da atama y'ye atanmış olacak.

ifade       C           C++
++x         R value     L value
--x         R value     L value
x, y        R value     L value
x ? a : b   R value     L value
a = b       R value     L value

Öncelik Parantezi

Parantez atomu bazı yerlerde sentaksın bir bileşeni. 
Bazı yerlerde ise öncelik parantezi.

void func(int x) -> burada parantez sentaksın bir bileşeni

x * (y + z) burada ise parantez öncelik parantezi

Öncelik parantezi: İfadeye öncelik kazandırmak ve 
ifadenin operandlarına ilişkin gruplamayı değiştirmek için kullanıyoruz.

Öncelik parantezi kullanarak işlemlerin istediğimiz şekilde gruplamanmasını sağlıyoruz.

    int x = 10, y = 5;

    //int z = x * y + 3;  //operatör önceliğine göre ilk olarak x * y ifadesinin işlemi yapılacak.
                        //ama biz istersek öncelik parantezi atomunu kullanarak 
                        //y + 3 ifadesinin daha önce yapılmasını sağlayabiliriz.
    int z = x * (y + 3); // bu şekilde.

    printf("z = %d", z);

-b / 2 * a bu ifadeyi derleyci (-b / 2) - a şeklinde yorumlayacak operatör önceliğine göre.
ve bu ifade -ab / 2 olacak.

Bu ifadeyi gerçekten -b / a yapmak için, -b / (2 * a ) öncelik parantezi kullanarak yapabiliriz.

int x, y, z,;
    printf("Uc tam sayi giriniz: ");
    scanf("%d%d%d", &x, &y, &z);

    ---------------

    int result = x * x * x + y * y * y + z * z * z; 
    //bu ifade için öncelik parantezi ile gruplamaya gerek yok çünkü operatör önceliğine göre istediğimiz işlemleri yapacak.
    //karmaşık ifadelerde kodun okunması için öncelik parantezini kullanmak faydalı olabilir.
    //ifadedeki öğe sayısı ve operatör sayısı fazla ise öncelik parantezi kullanmak faydalıdır.

x >> y & b > 100 bu ifade operatör önceliğine göre şu şekilde gruplanacak: (x >> y) & (b > 100)
Bu ifadeyi bu şekilde yazmak kodun okunmasını zorlaştırabilir, o yüzden öncelik parantezi kullanılabilir.

Özellikle bitsel operatörlerle oluşturulan ifadelerde öncelik operatörünü kullanılması bir konvensiyondur.

    int x = 20;
    (((x))) = 4; //bu kod legal bir koddur. öncelik parantezi ifadenin value kategorisin değiştirmez.

    İfade L value ise, l valuedur, R value ise r valuedur.

    ---------------

    int x = 10;
    (x++)++;    //sentaks hatası

    C dilinde ++ operatörünün sol operandı R value olamaz. L value olması gerekiyor.

    ---------------

    int x = 1;
    int y = -1;
    int z = !--x - !++y;  // !(--x) - !(++y) -> 1 - 1 = 0 z = 0 x = 0 y = 0
    
    //Logic Değil operatörü, non zero değerlerde 1'in değili olan 0
    //zero değerlerde 0'ın değili 1.

    z += x += y; //sağdan sola operatör öncelik yönü  z += (x += y)

    printf("%d - %d - %d", x, y, z);

    ---------------

    int x = 10;
    int y = 20;

    int a = x+++y;  // maximum munch kuralı. a = x++ + y olarak yorumlanır.
                    // a = 30, x = 11, y = 20

    printf("%d\n", -x + y + a); //   -11 + 20 + 30 = -39

KONTROL DEYİMLERİ (Control Statements)

Kontrol deyimler, programın akış yönünü değiştirebilen, 
en az bir anahtar sözcük içeren ve önceden belirlenmiş bir sentaksı olan deyimlerdir.

-> önceden belirlenmiş bir sentaksa uymak zorunda
-> en az bir anahtar sözcük içeriyorlar
-> varlık nedenleri, programın akış yönünü değiştirmek, kontrol etmek, yönlendirmek

Programlama dillerine göre ortak kontrol deyimleri olabilir, farklı kontrol deyimleri olabilir.
C, C++, Java, C# gibi dillerde genel itibariyle büyük ölçüde ortak bir sentaksı var.

C dilinde kontrol deyimleri kümesi:

if statement

while statement         //bu döngü deyimleri bir tane olsaydı,
do while statement      //döngü ile ilgili tüm ihtiyaçlarımızı tek bir döngü deyimiyle görebilirdik.
for statement           //birden fazla döngü deyimi olması, duruma göre okuma yazma kolaylığı sağlıyor.

switch statement        //switch ise if deyiminin bazı özel biçimlerine sahip. switch deyimi olmasaydı, if deyimi ile işlerimizi yapabilirdik.
goto statement          //az kullanılan bir kontrol deyimi, kullanılması tavsiye edilen yerlerin sayısı fazla değil.

break statement (yardımcı kontrol deyimi, döngü deyimleriyle ve switch deyimiyle birlikte kullanılacak)
continue statement (yardımcı kontrol deyimi, döngü deyimleriyle birlikte kullanılacak)

return statement (return tamamen fonksiyon tanımlama sentaksıyla ilgili)

Linux'un çekirdek kodlarına 1500'den fazla goto kontrol deyimi kullanılmış. Kesinlikle gereksiz bir kontrol deyimi değil.

Bizim kontrol deyimi yükümüzü çeken bi if deyimi bir de döngü deyimleri.
Diğerleri önemsiz değil tabiki ama ağırlık if ve döngü deyimlerinde.

if statement (if deyimi)

Aslında if deyiminin 3 ayrı biçiminden bahsetmek mümkün.

1 - Bir koşul var, bu koşul programın çalışma zamanında sınanıyor, koşul doğruysa bir iş yapılacak, koşul yanlışsa o iş yapılmayacak.
Yani bir iş yapılsın mı, yapılmasın mı, bunu belirleyen bir koşul ifadesi var.
Yalın if deyimi diyebiliriz.

2 - Yanlış kısmı da olan if deyimi. Burada da bir koşul var fakat bu sefer farklı olan koşulun doğru ya da yanlış olmasına bağlı olarak farklı işler yapılacak. 
Koşul doğruysa bir iş, koşul doğru değilse başka bir iş yapılacak. 
Burada koşul yapılsın mı değil, o mu yapılsın bu mu yapılsın durumu var.
Selector terimi kullanılır.

3 - else if ladder, cascaded if, else if merdiveni. Burada birden fazla koşul var, bunlar belirli bir sırayla sınanıyor.
Koşullardan birinin doğru olduğu görüldüğü programın çalışma zamanında bir iş yapılıyor.
İlk doğru koşul gerçekleştiğinde yapılacak olan bir iş var.

if anahtar sözcüğü, if parantezi, koşul ifadesi
conditional expression
true path (if'in doğru kısmı)
body (kontrol deyiminin gövdesi)

if (expr) -> if deyiminin sentaksı
    statement; -> true path.

Parantez içerisinde ifade lojik yorumlamaya tabi tutuluyor. Parantez içerisindeki ifadenin aritmetik değeri hesaplanıyor.
0'dan farklı bütün değerlere sahip bütün değerler, doğru olarak yorumlanıyor.
0 olan bütün değerler, yanlış olarak yorumlanıyor.

if parantezinden sonraki ilk deyim, if'in doğru kısmı.

if (expr)
    x++; //sadece bu deyimin işlemi yapılır. if'in doğru kısmı
    func();
    foo();

Eğer if deyimine diğer ifadeleri de dahil etmek istiyorsak, birleşik deyim yapmamız gerekir.

if (expr) {
    x++;
    func();
    foo();
}

if'in doğru kısmında tek bir deyim varsa, bloklamak mı daha iyi bloklamamak mı?
Tamamen kişiden kişiye, şirketten şirkete göre değişir.

if (a > 10) // bu parantezin içinin boş bırakılması her zaman sentaks hatasıdır. burada bir ifade olması gerekiyor.

if (a > 10;) // sentaks hatasıdır. ; biri ifadeyi deyim halinde getirir. if parantezinin içinde bir ifade olması gerkeiyor.


int x;

if (x != 0) //C dilinde iki şekilde de yazmanın anlam açısından hiçbir farkı yoktur.
if (x)      //C# ve Java gibi programlama dillerde geçerli değildir. Çünkü o dillerde parantez içerisinde boolean türünden bir ifade gerekiyor.


Özellikle if deyiminin koşul ifadesinde, bir fonksiyon çağrısından elde edilen geri dönüş değerinin 0 olup olmadığı kontrol ediliyorsa,
örnek olarak test fonksiyonları, != 0 yazmamak daha yaygın bir kullanım şekli.

if (isprime(x) != 0)
if (isprime(x)) gibi. bu if deyimi ifadesi daha çok tercih ediliyor.

if (expr != 0)
if (expr)

if (x == 0) //örnek olarak eğer bir nesnenin değerinin 0'a eşit olduğunda bir iş yapılacak, == operatörü ile 0'a eşitliğini sınamakla, 
if (!x)    //bu ifadenin lojik değilini almak arasında hiçbir fark yok.

Lojik değil operatörü 0 olduğunda 1 değerini üretir.

Yaptırmak istediğimiz için birden fazla koşul gerekiyorsa, lojik ve operatörünü kullanmamız gerekir.

if (x > 10 && y > 20) //lojik ve ile lojik veya operatörleriyle oluşturulan ifadelerde, kısa devre davranışına dikkat edilmesi gerekiyor.

if (x < SIZE && a[x] != 0) // sol operand daha önce yapılacak ve bu ifadenin yanlış olması durumunda sağ operandakki ifade yapılmayacak.
                           // kısa devre davranışı. eğer sol operanddaki ifade yanlış olduğunda, sağ operandın ifadesi yapılsaydı, x SIZE'dan küçük olmamasına rağmen ifadeyi gerçekleştirseydik, diziyi taşırmış olacaktık

if (expr1 && expr2 && expr3 && exp4) // birden fazla ifade yazabiliriz.

if deyiminin parantezine birden fazla koşul ifadesi yazarken, en düşük maliyetli işlemi en başa almamız daha sağlıklıdır. 

if (f1() > 10 && f2() < 20 && f3() > 0 && x != 0)
if (x != 0 && f1() > 10 && f2() < 20 && f3() > 0)
Eğer bu ifadelerin hepsinin doğru olması gerekiyorsa, belirli bir sıranın oluşması gibi bir zorunluluk yoksa,
derleyicinin daha etkin bir kod üretmesi ve daha temiz bir kod üretmesi için maliyeti daha düşük olan bir koşul ifadesini en başa yazabiliriz.

Eğer koşullardan herhangi bir doğru olduğunda o iş yapılacak, lojik veya operatörünü kullanıyoruz.

if (exp1 || exp2 || exp3) //düşük maliyetli karşılaştırmaları, işlemleri en başa almak daha sağlıklı.
{

}

*/
