/*

Ders13

If kontrol deyiminin doğru kısmındaki deyim bir boş deyim olabilir, 
bir ifade deyimi olabilir, başka bir kontrol deyimi olabilir, ya da bloklanmış bir bileşik deyim olabilir.

if (x != 0)
if (x)

Diğer dillerde bu şekilde kullanmak sorun olabilir fakat 
C dilinde bu iki koşul deyimi arasında bir fark yoktur.

if (x == 0)
if (!x)

if(isupper(c) != 0)
if(isupper(c))

if(isupper(c) == 0)
if(!isupper(c))

---------------------------------------------------------------------------------------

Çok sık kullanılan bir C idiyomu. If koşul parantezinin içinde ilk önce x'e atama yapılmış,
atama operatörünün ürettiği değer nesnenin değeri, ardından karşılaştırılma yapılmış.

x = func();
if (x == -1) {

}

if ((x = func()) == -1)

---------------------------------------------------------------------------------------

If parantezi içinde atama operatörüyle oluşturulmuş bir ifade.

    FILE* f;
    if((f = fopen("dogukan.txt", "r")) == NULL) {
        fprintf(stderr, "cannot open file\n");
        return 1;
    }

---------------------------------------------------------------------------------------

if((c = getchar()) != '\n) {} -> Atama operatörünün ürettiği değerden faydalanan if deyimi

if(c = getchar(), c != '\n') {} -> Virgül operatörü kullanılan if deyimi (yan etki oluşturuluyor)

Yukarıdaki iki if deyimi de pratikte aynı. Her ikisinin de yaptığı iş aynı.

---------------------------------------------------------------------------------------

Yanlış kısmı olan if deyimi

Buradaki amaç koşul doğruysa bir iş, koşul yanlışsa başka bir iş.

if (expr)
    statement_1;
else
    statement_2;

---------------------------------------------------------------------------------------

    int age;
    printf("Yasinizi giriniz: ");
    scanf("%d", &age);

    if (age >= 18){
        printf("Evet giris yapabilirsiniz.\n");
    }
    else{
        printf("Bu mekana girmek icin 18 yasinizi doldurmus olmalisiniz.\n");
    }

---------------------------------------------------------------------------------------

if (10 < x < 20) {} -> Bu if koşul parantezi always true. 

if (x > 10 && x < 20)

if (x = 10)     //karşılaştırma operatörü yerine atama operatörünü kullandık. 
                //atama operatörünün ürettiği değer nesneye atanan değer olduğu için, lojik yorumlandığında true olacak.
    dothis();

Böyle durumlarda, eskiden beri kullanılan idiyomatik yapı, sağ taraf değeri olan ifadeyi karşılaştırma operatörnün sol operandı yapıyorduk.

if (10 == x)
    dothis();

Lojik hata ya da çalışma zamanı hatası olacağına sentaks hatası olsun!

if (x = 0)      //atama operatörünün ürettiği değer nesneye atanan değer olduğu için, lojik yorumlandığında false olacak.
    dothis();

if (exp1 & exp2) //lojik ve operatörü yerine bitsel ve operatörünü yanlışlıkla kullanmak. dikkat edilmesi gerekir.

if (exp1 | exp2) //lojik veya operatörü yerine bitsel veya operatörünü yanlışlıkla kullanmak. dikkat edilmesi gerekir.

if (dval > 7,5) //gerçek sayı sabitini ifade eden . yerine , yazmak. Virgül operatörünün ürettiği değer sağ operandın değeridir. Lojik yorumlamaya tabi tutulduğunda, always true olacak.
    dothis();

if (dval > 7,0) //always false. 
    dothis();


---------------------------------------------------------------------------------------

int func(void)
{
    printf("func cagrildi!\n");
    return 0; // return 1; olsaydı, if'in doğru kısmına girecekti programın akışı.
}

int main(){

    if(func()) { //fonksiyon çağrı ifadesinin değeri, fonksiyonun geri dönüş değeri. burada geri dönüş değeri 0. bu yüzden lojik yorumlamaya tabi tutuldu ve if'in yanlış kısmına girdi.
        printf("evet evet evet\n");
    }
    else {
        printf("hayir hayir hayir\n");
    } 
}

---------------------------------------------------------------------------------------

int func(void)
{
    printf("func cagrildi!\n");
    return 0; // 
}

int main(){

    if(func) { //programcı fonksiyon çağrı operatörünü yazmayı unutmuş. () Bu kod sentaks hatası değil. Çalıştırdığımızda if'in doğru kısmına girecek. Always true.
        printf("evet evet evet\n");
    }
    else {
        printf("hayir hayir hayir\n");
    } 
}

Fonksiyon ismi, dilin kurallarına göre bir ifade içinde kullanıldığında, bu fonksiyonun adresine dönüştürülecek
ve fonksiyon adresi lojik yorumlamaya tabi tutulduğunda, lojik doğru olarak yorumlanacak.

Yani biz istemeden fonksiyonun çağrılmamasına yol açtık. Hem de bu ifade artık always true oldu.

regex - regular expression

Kodlama editörlerinin hepsi regex ile arama yapmaya izin verir.
if parantezinden sonra noktalı virgül olup olmadığını kontrol edebiliriz, sınayabiliriz.

---------------------------------------------------------------------------------------
x 10'a ya da 23'e eşit değilse, func fonskiyonunu çağır.

if (x != 10 || x != 23) always true. dilin kullanımında "veya" "ya da" geçtiği için ifade yanlış kurulmuş.
    func();
---------------------------------------------------------------------------------------

Bu iki ifadenin denkliğini sağlayan lojik ve operatörünün kısa devre davranışıdır.

if (x > 10)
    if (y < 30)
        ++m;

if (x > 10 && y < 30) // x > 10 ifadesi yanlışsa, diğer sınama yapılmayacak.
    ++m;
---------------------------------------------------------------------------------------

if kontrol deyiminin doğru kısmı mutlaka olmak zorundadır.

Eğer gerçekten if'in doğru kısmında bir şey yapılmasını istemiyorsak bunu yapmanın iki yolu var.

Kötü yol:

if (x > 10)
    ;
else
    ++m;

İyi yol:

if(!(x > 10))

if (x <= 10)
    ++m;

Her türlü aşağıdaki kullanım türünden kaçınmalıyz.

//Kötü yol
if (exp)
    ;
else
    dothis();

//İyi yol
if(!exp)
    dothis();

---------------------------------------------------------------------------------------

dangling else - her iki if deyimine de aitmiş gibi duran else deyimi. bu tür durumlarda else, içteki if'in else'dir.

if (x > 10)
    if (y > 20)
        ++m;
else
    --z;

---------------------------------------------------------------------------------------

Gereksiz if deyimi kullanımı. Derleyici optimizasyonu düzgün yapmazsa verimlilik sorunu olur.

if (x == 10) //eğer x'in değeri 10 ise, alttaki if'lerin doğru sonuçlanması ihtimali yok. birbirinden bağımsız if'ler. 
    func1();

if (x == 20)
    func2();

if (x == 30)
    func3();

if (x == 40)
    func4();

Else if merdiveni:

if (x == 10)
    func1();

else if (x == 20)
    func2();

else if (x == 30)
    func3();

else if (x == 40)
    func4();

else if merdiveni kullanmamız gereken yerde ayrık if deyimleri yazmamamız lazım.

a) kodun okunmasını zorlaştırabiliriz.
b) kodu okuyanı yanıltabiliriz.
c) derleyicinin bir optimazyon yapmaması durumunda daha verimsiz bir kod oluşmasına yol açabiliriz.
d) ilerde öğreneceğimiz switch deyiminin bariz kullanabileceği yerlerde, else if merdiveni yerine switch deyimini kullanmalıyız.
    i) kodun okunmasını kolaylaştırırız
    ii) duruma göre else if merdivenine göre derleyici switch deyimi için daha etkin bir kod oluşturabilir.

Bir else if merdiveninde, en sonda else deyiminin olup olmaması kodun anlamını tamamen değiştiriyor. Hayati bir önem taşıyor.
Eğer else if merdiveninin son basamağında else yok ise, bu merdivenden hiçbir şey yapılmadan çıkılabilir.

if (x == 10)
    func1();

else if (x == 20)
    func2();

else if (x == 30)
    func3();

else if (x == 40)
    func4();
else
    dothis();

---------------------------------------------------------------------------------------

Else if merdiveninde oluşma sıklığı ya da olasılığı yüksek olan durumları başa yazmalıyız.
Aynı şey switch deyimi için de geçerlidir.

Örnek olarak, bu fonksiyon daha çok aralık ayı için çağrılıyor diyelim.
Bu yüzden oluşma olasalığı daha yüksek olan koşulları başa taşımalıyız.

Switch deyiminde de bu koşulun karşılığı default case.

void func(int m)

if (m == 1)

if (m == 2)

if (m == 12)

---------------------------------------------------------------------------------------

if (++x > 10) //if parantezi, bir sequence point oluşturuyor. yan etki noktası.

bu koşuldan sonra ister doğru kısmına girsin, ister yanlış kısmına girsin, x'i ilk kullandığım yerde x'in artmış değerini kullanacağımın garantisi var.

---------------------------------------------------------------------------------------

redundant else

Öyle yerler var ki, else anahtar sözcüğünü koymamız gerekiyor ama contexte baktığımızda else anahtar sözcüğünü koymakla koymamak arasında bir fark yok.
Bu tamamen kişisel bir seçim. Else olsa da, olmasa da bir anlam farkı yok.

int getabs(int x){
    if (x >= 0)
        return x;
    else //buradaki else olsa da, olmasa da, kodun anlamında bir değişiklik yok.
        return -x;
}

while (expr){
    statement1;
    statement2;
    if (c_ex)
        break;
    else { //buradaki else hiç olmasaydı, kodun anlamında hiçbir değişiklik olmayacaktı.
        statement3;
        statement4;
        statement5;
    }
}

while (expr){
    statement1;
    statement2;
    if (c_ex)
        continue;
    else { //buradaki else hiç olmasaydı, kodun anlamında hiçbir değişiklik olmayacaktı.
        statement3;
        statement4;
        statement5;
    }
}

---------------------------------------------------------------------------------------

if (x != 0)
    y = x;
else
    y = 0;

Bu kod, y = x anlamına geliyor. Gereksiz if deyimi kullanımı.

x'in değeri 0'a eşit olmadığı zaman, y değişkenine x'in değeri atanacak.
aksi hâlde, y değişkenine 0 değeri atanacak.

Zaten x'in değeri 0 olsa, y değişkenine 0 atanacak.

Yani her koşulda x'in değeri y'ye atanacak.

Sentaks hatalarından korkmaya gerek yok, sentaks hatası bizim en büyük dostumuz.
Önemli olan lojik hatalar, tanımsız davranışlar.

else bir if'e ait olmalı.
if'i olmayan bir else her zaman sentaks hatasıdır.

if (x > 10); //buraya yanlışlıkla noktalı virgül atomunu koyarsak, if deyiminin else ile ilişkisi kesilir ve sentaks hatası alırız.
    bunuyap();
else
    sunuyap();

---------------------------------------------------------------------------------------
Başlangıç seviyesinde olan programcıların yaptıkları sentaks hataları;

    int x;
    int y;

    y = x; // Çöp değerle, otomatik ömürlü bir nesnenin değerini kullanmak. Undefined Behavior - Tanımsız Davranış

---------------------------------------------------------------------------------------

    int x;
    printf("Bir tam sayi girin: ");
    scanf("%d", x); //adres operatörünü yazmayı unuttuk. & operatörünü yazsaydık, bu call by reference olacağı için uyarı mesajı vermeyecekti.
                    //ama burada, scanf fonksiyonuna x'in çöp değerini gönderdik. otomatik ömürlü bir nesnenin çöp değerini kullanmak

---------------------------------------------------------------------------------------

Bir değişken tanımlamak ama kod içerisinde kullanmamak. Derleyicilerin hemen hepsi bu durumu yakalar.
unreference local variable / derleyici uyarı mesajlarında bu sözel yapı farklı olabilir.

---------------------------------------------------------------------------------------

Yan etkisi olmayan bir ifade deyimi yazmak, yani öyle bir deyim ki, derleyiciye göre onun olmasıyla olmaması arasında bir fark yok.

int x = 5;
int y = 15;

x == y //yanlışlıkla atama operatörü yerine karşılaştırma operatörü kullanılmış. bir sentaks hatası yok.

C'nin kurallına göre bir ifade geçerliyse, o ifadenin sonuna ; atomunu koyarak oluşturduğumuz ifade deyimi de geçerlidir.

result of expression not used; did you intend '='?

---------------------------------------------------------------------------------------

int x = 5;
int y = 15;

x + y; // işlemli atama operatörü yerine sadece toplama operatörü olan +'yı yanlışıkla yazdık.

'+' result of expression not used

---------------------------------------------------------------------------------------

Programcı burada abs fonksiyonunun geri dönüş değerini kullanmamış, discard etmiş.
Bu örnekte bu fonksiyonun geri dönüş değerini kullanmamak lojik hata. Derleyici herhangi bir uyarı vermeyebilir.

Her fonksiyonun geri dönüş değerini kullanmak zorunda mıyız? Hayır. 
Bazı fonksiyonlar içsel olarak derleyici tarafından etiketleniyorlar. Böyle fonksiyonlara popüler olarak no-discard fonksiyonlar diyoruz.

C++ ise bu zaten dilin aracı ile belirliyoruz. Attribute
Bu fonksiyonun kullanılmadığını saptarsan, sentaks hatası ver.

[[nodiscard]] int foo(int x)
{
    return x + 5;
}

C de ise standart değil, derleyicilerin extensionları.

    int x;
    printf("bir tam sayi girin: ");
    scanf("%d", &x);

    abs(x);

---------------------------------------------------------------------------------------

Örnek olarak scanf fonksiyonunun geri dönüş değerini discard ediyorsak, bunu okuyucuya anlatmak için bu şekilde yazabiliriz.
Derleyici bu durumda hiçbir uyarı mesajı vermeyecek.

int ival;
printf("Bir tam sayi giriniz: ");
(void)scanf("%d", &ival);

---------------------------------------------------------------------------------------

Standart getchar ve putchar fonksiyonları

getchar fonksiyonu formatsız bir giriş fonksiyonudur. Bu fonksiyon standart giriş akımının bufferından bir karakteri alıyor, extract ediyor.
Geri dönüş değeriyle o karakterin kodunu dönderiyor. Standart inputun bufferındaki ilk karakteri alan, bufferdan çıkartan, geri dönüş değeri olarak onun kod değerini, tam sayı değerini veren fonksiyon.

Bu fonksiyonu çağırdığımızda, standart giriş akımının bufferı boş ise, bir giriş yapmamız istenilecek. Son derece önemli bir fonksiyon.
scanf fonksiyonu gibi, line buffered bir fonksiyondur. Yani girişin tamamlanması için standart inputa new line verilmesi gerekiyor.

scanf ve getchar fonksiyonları aynı bufferı paylaşıyorlar.

getchar fonksiyonunun geri dönüş tipi int türden.


    printf("Bir giris yapin: ");
    int c = getchar(); //Yapilan giris "BABACIM". Fonksiyon geri dönüş değeri, B'nin kodu olan 66 değeridir. Bu B harfi, artık standart inputun bufferından çıkartıldı.
    printf("%d", c);

---------------------------------------------------------------------------------------

    printf("Bir giris yapin: "); //Yapılan giris "dogukan". 100 111 103 d o g harflerinin karakter kodlarını yazdırdı, bu karakterler bufferdan çıkartıldı. diğer karakterler bufferda kaldı.
    int c1 = getchar();
    int c2 = getchar();
    int c3 = getchar();
    printf("%d %d %d\n", c1, c2, c3);

---------------------------------------------------------------------------------------

    int x = 777;

    printf("Bir tam sayi giriniz: ");
    int c = getchar(); //scanf ile getchar fonksiyonları aynı bufferı kullanırlar.
    scanf("%d", &x); //Giriş bu şekilde yapılacak: "a456"

    printf("x = %d", x);

---------------------------------------------------------------------------------------

    int c;
    
    printf("Evet mi (e) hayir mi (h) : ");
    c = getchar(); // Bu noktada standart giriş akımının bufferının boş olduğuna dikkat etmeliyiz. Boş olmalı.
    
    if(c == 'e')
        printf("Evet secildi!");
    else if (c == 'h')
        printf("Hayir secildi!");
    else
        printf("Hatali secim!");

---------------------------------------------------------------------------------------

//getchar fonksiyonunun geri dönüş değerini %d ile kullandığımızda, o karakterin kod numarasını elde ederiz. ASCII Kodu. Conding Place.
// c - '0' ifadesinde ise, ASCII karakter kodlamasında karakterler ardışık bir sıralamada olduğundan dolayı girilen karakterin gerçek değerini kullanmak için 0 karakterini girilen karakterden çıkarttık.
// örnek olarak, eğer 9 girilseydi, 9'un ASCII karakter kodlamasındaki karşılığı 39. 0'ın ise 30. 39-30 = 9 karakterinin değeri sonucuna ulaşırdık.

    int c;
    int x;

    printf("Bir tam sayi giriniz: "); //2048
    
    x = 0;
    while((c = getchar()) != '\n'){
        x = x * 10 + c - '0'; 
    }

    printf("Girilen sayi: %d", x);
}

x = 0 * 10 + 32 - 30 = 2

x = 2 * 10 + 30 - 30 = 20

x = 20 * 10 + 34 - 30 = 204

x = 204 * 10 + 38 - 30 = 2048

---------------------------------------------------------------------------------------

Aşağıdaki fonksiyon ile standart inputun bufferını boşaltabiliriz.

void clear_input_buffer(void) 
{
    int c;

    while((c = getchar()) != '\n' && c != EOF)
}

---------------------------------------------------------------------------------------

void clear_input_buffer(void) 
{
    int c;

    while((c = getchar()) != '\n' && c != EOF)
    ;
}

int main(){
    int x;
    int y;

    printf("Bir tam sayi girin: "); // giris: 1984dogukan, 1984'u standart inputun bufferından aldık, extract ettik. dogukan harfleri kaldı.
    scanf("%d", &x);

    printf("Bir tam sayi daha girin: ");
    clear_input_buffer();   // standart inputun bufferını temizledik. 
    scanf("%d", &y);

    printf("%d\n", x);
    printf("%d\n", y);

---------------------------------------------------------------------------------------
   
    int c;
    int sum = 0;

    printf("Bir tam sayi giriniz: ");
    
    while ((c = getchar()) != '\n') {
        sum += c - '0';
    }

    if (sum % 3 == 0)
        printf("Evet bolunur!");
    else
        printf("Hayir bolunmez!");

---------------------------------------------------------------------------------------
    
    int c;
    int sum = 0;

    printf("Bir tam sayi giriniz: ");

    while((c = getchar()) != '\n'){
        sum += c - '0';
        printf("SUM: %d\n", sum);
    }

---------------------------------------------------------------------------------------

int main()
{
    for(int i = 0; i < 1000; ++i){
        if(i && i % 100 == 0){
            printf("\n devam etmek icin enter tusuna basin: ");
            (void)getchar();
        }
        printf("%3d ", rand() % 1000);
    }
}

---------------------------------------------------------------------------------------

getchar line-buffered bir giriş fonskiyondur. aynı scanfde olduğu gibi,
standart inputun bufferı boşsa, getchar çağrıldığı zaman new line karakterinin gelmesi zorunlu.
aksi halde, getchar programı kullanan kişiyi bekletecek.

getchar ve scanf aynı bufferı paylaşıyor.

getchar echoing bir fonksiyondur. echo veren fonksiyon.
programı kullanan bir tuşa basıyor ama standart outputda da o karakter görünüyor.
bu bazı durumlarda istenmeyebilir. bu yüzden maalesef standart kütüphanede getchar benzeri, echo vermeyen bir fonksiyon yok.

    int c;

    printf("Bir tusa basin: ");
    c = getchar();

Derleyiciler standart olmayan fonksiyonlar verebiliyor.

_getch() bu şekilde standart olmayan bir fonksiyon var.

int getchar(void);
int _getch(void);

Bu fonksiyon getchar ile aynı işi yapıyor, line-buffered değil. Karakteri de standart outputa yazdırmıyor.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //standart değil.

int main()
{
    int c;
    printf("Bir karakter girin: ");
    c = _getch(); //standart değil. line-buffered değil. girilen karakteri göstermiyor.

    printf("c = %d", c);
}

---------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //standart değil.

int main()
{
    int c;
    printf("Bir karakter girin: ");
    c = _getche();

    printf("\nc = %d", c);
}

---------------------------------------------------------------------------------------

int getchar(void);  standart, new line istiyor, echo veriyor.
int _getch(void);   standart değil, new line istemiyor, echo vermiyor.
int _getche(void);  standart değil, new line istemiyor, echo veriyor.

---------------------------------------------------------------------------------------

standart putchar fonksiyonu
stdio kütüphane dosyasının bir fonksiyonu.

putchar kendisine argüman olarak gelen karakteri bunu bir karakterin kodu olarak alıyor,
o koda sahip olan karakteri standart outputa veriyor.

putchar(65);  //Bu şekilde kullanırsak karakter kodu 65'e denk gelen karakteri yazdıracak.
putchar('A'); //Bu şekilde kullanırsak A karakter sabitinin kodunu yazacak. Her yerde A yazdıracak.

putchar fonksiyonunun geri dönüş değeri verdiğimiz karakterin kendisi, eğer bir hata olursa -1
ekrana A karakterini yazdırırsak, A karakterinin kodunu yazdıracak.
Bir hata olursa -1. 

printf'in %c ile çalıştırılmış hali gibi. ama bu variadic bir fonksiyon değil.

    int ch;

    printf("bir karakter kodu girin: ");
    scanf("%d", &ch);

    putchar(ch);

---------------------------------------------------------------------------------------

ASCII'de kontrol karakteri olmayan karakterler 33'den başlayarak 127 hariç karakterler.
Görüntüsü olan bütün karakterleri ekrana yazdırmış olduk.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //standart değil.

int main()
{
    for(int i = 33; i < 127; ++i){
        putchar(i);
    }
}

Bu programı putchar fonksiyonu yerine, printf ile de yapabilirdik.

int main()
{
    for(int i = 33; i < 127; ++i){
        printf("%c", i);
    }
}

---------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //standart değil.

int main()
{
    for(;;){
        putchar(rand() % 26 + 'A');
        _sleep(rand() % 20 * 10);
    }

}

---------------------------------------------------------------------------------------

Test Fonksiyonları

Bazı fonksiyonların geri dönüş değeri hesaplanan değer, bazılarının geri dönüş değeri tamamlayıcı bir bilgi, bazılarının ise başarı bilgisi.
Test fonksiyonlarının geri dönüş değerleri, evet hayır, doğru yanlış, geçerli geçersiz.
Aslında programlama dillerinde böyle fonksiyonların geri dönüş değeri boolean türü seçiliyor, C dilinde ise int türden yapılıyor.

Karakter Test Fonksiyonları

int isprime(int); -> buradaki int, boolean int anlamına geliyor.
int is_valid_card(int);

Fonksiyonun geri dönüş değeri 0'dan farklı bir değerse DOĞRU
0'a YANLIŞ olarak yorumlanıyor.

geri dönüş değeri olan fonksiyonlar
test function
query function
predicate

---------------------------------------------------------------------------------------

x asal sayi ise
if (isprime(x) != 0)
if(isprime(x))

x asal sayı değilse

if (isprime(x) == 0)
if (!isprime(x))

Böyle fonksiyonlar doğrudan one-liner olarak yazılabiliyorlar.
Öyle bir fonksiyon ki, kodu sadece bir return deyimi.

int iseven(int x)
{
    return x % 2 == 0;
}

int main()
{
    int x;
    printf("Bir tam sayi girini: ");
    scanf("%d", &x);

    if(iseven(x) != 0){
        printf("cift sayi\n");
    }

    else {
        printf("tek sayi\n");
    }
}

---------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //standart değil.

//eğer geri dönüş değeri non-zero ise sayı asal,
//eğer geri dönüş değeri zero ise sayı asal değil.
//c++ olsaydı
//bool isprime(int val);


int isprime(int val);

int main()
{
    int x;
    printf("Bir tam sayi girini: ");
    scanf("%d", &x);

    if (isprime(x) != 0)
    if (isprime(x))
        printf("%d asal sayi\n", x);
    else
        printf("%d asal sayi degil\n", x);
}

---------------------------------------------------------------------------------------

Artık yıl testini asla 4'e tam bölünme biçiminde yapmayın! Bu matematiksel olarak yanlıştır.

4'e tam bölünmesi gerekiyor,
    ya 100'e tam bolunmeyecek
    ya da 400'e tam bolunecek

1977 artık yıl değil
1984 artık yıl. 4'e tam bolunuyor, 100'e tam bolunuyor
2000 artık yıl. 4'tam bolunuyor, 400'e tam bolunuyor.

1900 artik yil, 4'e tam bolunuyor, 100e tam bolunmuyor

#include <stdio.h>

int isleap(int y)
{
    return y % 4 == 0 && (y % 100 != 0 && y % 400 == 0);
}

int main(){
    int y;
    printf("Bir yil girin: ");
    scanf("%d", &y);

    if(isleap(y)){
        printf("%d artik yil\n", y);
    }
    else {
        printf("%d artik yil degil\n", y);
    }
}

---------------------------------------------------------------------------------------

Standart kütüphanenin önemli bir modülü.

<ctype.h>

Bu başlık dosyasında bildirilen fonksiyonların önemli bir kısmı test fonksiyonları.

Karakter test fonksiyonları. Bir çok programlama dili de bu kütüphanedeki fonksiyonların isimlerini almış.

Bu fonksiyonlar karakterlerin kod numaralarını alıyorlar ve bu karakterlerin belirli özellikleri sağlayıp sağlamadıklarını kontrol ediyorlar.

Hepsinin geri dönüş tipi int.

int is... (int ch);

int isupper(int ch); //evet gonderilen karakter büyük harf karakteri, non-zero değer döndürecek, hayır değilse, 0 döndürecek. 
int islower(int ch);
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

*/


