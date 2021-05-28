/* 

Ders19

predefined symbolic constants
ön tanımlı sembolik sabitler

#include <stdio.h>

int main()
{
  printf("%d", __LINE__);
}

Biz herhangi bir başlık dosyası eklemedik, ona rağmen bir sentaks hatası oluşmadı.
Öyle makrolar var ki, bunların bir define komutu yok. Dilin kuralı gereği önişlemci program bunları bir yer değiştirme işlemine tabi tutuyor.
Dil tarafından önceden tanımlandığı kabul edilen makrolara predefined symbolic constants deniliyor.

İki alt tire ile başlayıp iki alt tire ile biterler.

__LINE__
__FILE__
__DATE__
__TIME__
__STDC__
__func__ (C99'da eklenmiş)

-----------------------------------------------------

__LINE__

Editörün kaçıncı kod satırında kullanılmışsa, o kod satırın tam sayı numarasıyla yer değiştiriyor.

Özellikle kullanım amacı, debug sürecinde bir hatayı yakaladığımız noktada satır numarasını kullanmak.

int main(){
    
    printf("%d", __LINE__);
}

-----------------------------------------------------

__FILE__

Kullandığı kaynak dosyanın ismiyle yer değiştiriyor.

int main(){
    
    printf("%s", __FILE__);
}

-----------------------------------------------------

__DATE__

Derleme işleminin yapıldığı tarih ile yer değiştiriyor.

int main(){
    
    printf("%s", __DATE__);
}

-----------------------------------------------------

__TIME__

Derleme işleminin yapıldığı saat ile yer değiştiriyor.

int main(){
    
    printf("%s", __TIME__);
}

-----------------------------------------------------

#include <stdio.h>

void foo(void)
{
    printf("Bu fonksiyonun ismi: %s\n", __func__);
}

int main(){
    
    printf("%s dosyasinin %d. satiri\n", __FILE__, __LINE__);
    printf("Derleme tarihi: %s\n", __DATE__);
    printf("Derleme zamani: %s\n", __TIME__);
    foo();
}

-----------------------------------------------------

__STDC__

C dilinde derleme yapan bir derleyici için, eğer derleyicinin eklentileri kapalıysa STDC makrosu tanımlı kabul ediliyor.

Önişlemci programı, eğer standart bir C derleyicisi ise, aşağıdaki koşullu derleme komutunun içine girecek.

#ifdef __SDTC__
#endif

Bir de bunun C++ karşılığı var.

#ifdef __cplusplus
#endif

Mesela bu şekilde bir komut yazdığımızda, sadece C++ derleyicisi bunun içine girecek. C derleyicisi bunun içine girmeyecek.

__SDTC__    -> C derleyicileri tarafından defined kabul ediliyor.
__cplusplus -> C++ derleyicileri tarafından defined kabul ediliyor.

-----------------------------------------------------

#define komutunu hatırlayalım.

#define DOGUKAN

1 - Bu makronun tanımlanmasının tek amacı koşullu derleme komutlarını yönlendirmek olabilir.
Yani kodda bazı yerlerde koşullu derleme blokları var, dolayısıyla önişlemci program bunun içine girecek mi girmeyecek mi.
Bu makroyu tanımlarsak bunu sağlayabiliriz.

#ifdef DOGUKAN

#endif

BUNUNLA İLGİLİ ÖRNEK:

Mesela card.h başlık dosyasında kart türlerini gösteren aşağıdaki gibi bir kod yazdık.

enum Suit {Club, Diamond, Heart, Spade};

Bridge tarzı oyunlarda Maça, Kupadan daha kıymetlidir.
Ama Poker tarzı oyunlarda Kupa, Maçadan daha kıymetlidir.

Şimdi oluşturduğumuz card.h başlık dosyası bu iki oyuna da hizmet verecek. Ama ortada bir sorun var.

enum Suit {Club, Diamond, Heart, Spade}; //Bridge tarzı oyunlara uygun.

enum Suit {Club, Diamond, Spade, Heart}; //Poker tarzı oyunlara uygun.

Bu sorunu koşullu derleme komutlarıyla çözebiliriz.

card.h başlık dosyası:

#ifdef BRIDGE
enum Suit {Club, Diamond, Heart, Spade};
#else
enum Suit {Club, Diamond, Spade, Heart};
#endif

Mesela biz kodumuzu BRIDGE tarzı oyunlar için derlemek istiyoruz. 

#define BRIDGE yaptığımızda BRIDGE tarzı oyunlar için derlenecek. Koşullu derleme komutlarının yönünü değiştirmek.

2 - Basit yer değiştirme işlemleri. Çoğunlukla da sembolik sabit dediğimiz kodsal varlıkların oluşturulması. 
Sembolik sabitlerin kendileri isim görüntüsünde ama önişlemci program bunları bir yer değiştirme işlemine tabi tutuyor.

#define SIZE 100

Sembolik sabit, manifesto sabiti.

3 - Kompleks yer değiştirme işlemleri. Fonksiyonel makrolar. Yazılan kodda fonksiyon çağrısı görüntüsü oluşacak fakat fiilen bir fonksiyon değil.

#define square(x) ((x) * (x))

4 - Sildirmek. PUBLIC sözcüğünü görüyoruz fakat sıra derleyiciye geldiğinde derleyici PUBLIC sözcüğünü görmeyecek. 
Önişlemci program tarafından derleyiciden önce siliniyor.

#define PUBLIC

PUBLIC int get_x(void)
{
    //...
}

-----------------------------------------------------

Switch kontrol deyimi.

Bu kontrol deyimi kullanılan hiçbir zorunlu senaryo yok. 
Bu deyim else if merdiveninin bazı biçimlerine, kodun okunabilirliğini veya kodun kolay yazılabilirliğini arttırmak amacıyla kullanıyoruz.
Bazı durumlarda derleyici, else if merdiveni oluşturmak yerine, duruma göre switch deyiminde daha etkili kod üretiyor. 

case labels

switch (integer expression) {
    case 5: 
}

Gerçek sayı türünden ifade sentaks hatasıdır. Tam sayı ifadesi olmak zorundadır.
Bu deyimde lojik açıdan neredeyse mecburi olacak şekilde, bir bileşik deyim, gövde olacak.
Deyimin gövdesinde özel anahtar sözcüklerle oluşturulmuş etiket dediğimiz varlıklar var.
case labels. case etikletleri. case bir anahtar sözcük, bunun ardından bir tam sayı sabit ifadesi, sonrasında iki nokta
case etiketleri switch deyiminde bir yer belirtiyorlar.
case etiketleri unique olmak zorundadır. bu deyimin gövdesinde n tane deyim olabilir.

Daha sonra koda bir ekleme yapıldığında bir problem oluşmasın diye, son break deyimini kullanmak faydalı olabilir.

#include <stdio.h>

int main(){

    int n;

    printf("Haftanin kacinci gunu? : ");
    scanf("%d", &n);

    switch (n) {
        case 1: printf("Pazartesi\n"); break;
        case 2: printf("Sali\n"); break;
        case 3: printf("Carsamba\n"); break;
        case 4: printf("Persembe\n"); break;
        case 5: printf("Cuma\n"); break;
        case 6: printf("Cumartesi\n"); break;
        case 7: printf("Pazar\n"); break;
    }
}

Switch deyimi olmasaydı, biz aynı işi else if merdiveniyle yapabilirdik.

#include <stdio.h>

int main(){

    int n;

    printf("Haftanin kacinci gunu? : ");
    scanf("%d", &n);

    if (n == 1)
        printf("Pazartesi\n");
    else if (n == 2)
        printf("Sali\n");
    else if (n == 3)
        printf("Carsamba\n");
    else if (n == 4)
        printf("Persembe\n");
    else if (n == 5) 
        printf("Cuma\n");
    else if (n == 6) 
        printf("Cumartesi\n");
    else if (n == 7)
        printf("Pazar\n"); 
}

Her else if merdiveni için switch yazamayız. Mesela aşağıdaki örnek için.

if (d > 2.3) {

}

else if (d < 5)

veya

if (x == y) {

}

else if (x == z)

-----------------------------------------------------

Aşağıdaki kullanım geçerli bir kullanımdır. Çünkü case etiketinde karakter sabiti kullanılıyor.

#include <stdio.h>

int main(){

    int n = 65;

    switch (n) {
        case 'A': printf("65"); break;
        case 'B': printf("66"); break;
    }
}

-----------------------------------------------------

Aşağıdaki kullanım geçerli bir kullanım değildir. Çünkü case etiketinde bir sabit yerine karakter sabitlerinden oluşan bir dizi kullanılıyor.

#include <stdio.h>

int main(){

    int n = 65;

    switch (n) {
        case "dogukan": printf("65"); break;
        case "yazar": printf("66"); break;
    }
}

-----------------------------------------------------

Aşağıdaki kullanım geçerli bir kullanım değildir. Çünkü case etiketinde bir değişken kullanılmış.

#include <stdio.h>

int main(){

    int n = 65, x = 10, y = 20, z = 30;

    switch (n) {
        case x: printf("x");
        case y: printf("y");
        case z: printf("z");
    }
}

-----------------------------------------------------

Switch deyiminin case etiketinde const anahtar sözcüğü ile tanımlanmış bir değişkenin kullanımında C ile C++ arasındaki bir fark.

#include <stdio.h>

int main(){

    const int x = 10; //const anahtar sözcüğü ile tanımlanmış ve bir sabit ifadesiyle ilk değer verilmiş değişkenler C dilinde sabit ifadesi gereken yerde kullanılamıyorlar.

    switch (1) {
        case x: printf("Case 1\n"); //C dilinde derleyici burada sentaks hatası verecektir. Çünkü case etiketinde bir sabit ifade, constant expression olması gerekiyor.
    }
}

Bu kod C dilinde sentaks hatası fakat C++ dilinde bu kod sentaks hatası değil.

-----------------------------------------------------

Aşağıdaki kullanım geçerli bir kullanım değildir. Evet case etiketindeki ifade sabit ifadesi fakat tam sayı değil, gerçek sayı.

#include <stdio.h>

int main(){

    int x = 10;

    switch (x) {
        case 1: printf("Case 1\n");
        case 2.2: printf("Case 2.2\n");
    }
}

-----------------------------------------------------

Aşağıdaki kullanım geçerli bir kullanım olabilir çünkü eğer bu case etiketleri birer makroysa ve bu makrolar sabit ifadesine define edilmişse, geçerli olacaktır. 

#include <stdio.h>

#define LOW 100
#define HIGH 200

int main(){

    int x = 10;

    switch (x) {
        case LOW: printf("Case 1\n");
        case HIGH: printf("Case 2\n");
    }
}

-----------------------------------------------------

Ayrıca switch deyiminin kullanımında case ifadelerinin, en az %50sinde kodun okunmasını kolaylaştırmak için makroları göreceğiz.

Mesela daha öncesinde koşullu derleme komutlarında örnek verdiğimiz kart oyununun kodunun bir kısmını yazdığımızı düşünelim.

switch (get_card_suit(c)) {
    case CLUB:
    case DIAMOND:
    case HEART:
    case SPADE:
}

-----------------------------------------------------

if (n == 1) {

}

else if (n == 2) {

}

else if (n == 3) {
    
}

else if (n == 4) {
    
}

else {

}

Else if merdivenindeki koşulları yazarken, doğru olma olasılığı fazla olan, en yüksek ihtimali başa alabiliriz.
Gerek else if merdiveninde, gerek switch deyiminde, oluşma olasılığı yüksek olan caseleri başa almamız gerekir.

Else if merdivenin, sondaki else'i, aslında bütün koşulların dışlayan kümesi. 
Yani else if merdivenin her basamağındaki koşul yanlış ise, o zaman programın akışı en son if'in else'ine girer. 
Eğer bu else olmasa, bu else if merdiveninden hiçbir şey yapılmadan çıkılabilir.

Else if merdiveninin sonundaki else'i, switch deyiminde default etiketiyle gerçekleştirebiliyoruz.
Tıpkı diğer case'ler gibi kullanılıyor. Eğer switch parantezi içindeki ifadenin değerine eşit bir case ifadesi yoksa, programın akışı default case'i izleyen ilk ifadeyi izleyecek.

Ayrıca bu case etiketleri, herhangi bir sırada olabilir. Sırasının bir önemi yoktur.

int main(){

    int n;

    printf("Haftanin kacinci gunu? : ");
    scanf("%d", &n);

    switch (n) {
        case 1: printf("Pazartesi\n"); break;
        case 2: printf("Sali\n"); break;
        case 3: printf("Carsamba\n"); break;
        case 4: printf("Persembe\n"); break;
        case 5: printf("Cuma\n"); break;
        case 6: printf("Cumartesi\n"); break;
        case 7: printf("Pazar\n"); break;
        default: printf("Gecersiz gun!\n"); break;
    }
}

-----------------------------------------------------

Bir program yazacağız, bu program ekrana Merhaba Dunya yazdiracak fakat printf çağrısının sonunda ; olmayacak.

1

#include <stdio.h>

int main(){

    if (printf("Merhaba"))
        { }
}

printf fonksiyonunun geri dönüş değeri ekrana yazdırdığı karakter sayısı. if'in doğru kısmına girecek, 
doğru kısmında da bir şey yapılmadığı için, ekrana merhaba yazılacak.

-----------------------------------------------------

2

#include <stdio.h>

int main(){
    
    while (!printf("Merhaba"))
    { }
}

while parantezi içerisindeki ifadenin değilini alıyoruz, 7 karakter. !7 = 0; Yanlış olduğu için döngüden çıkacak ve sadece bir kez Merhaba yazılacak.

-----------------------------------------------------

3

#include <stdio.h>

int main(){

    switch (printf("Merhaba")) {
        
    }
}

switch parantezi içerisindeki ifade bir tam sayı ifadesi. Bu yüzden geçerli. printf geri dönüş değeri 7.

-----------------------------------------------------

Bir case'i izleyen, deyimlerin sayısı 2'den fazla ise, okumayı kolaylaştırmak için o işi bir fonksiyon haline getirip, 
sadece fonksiyona çağrı yapmak daha iyi bir kod yapısını oluşturur.

int main(){

    switch (option)
        case ADD_RECORD :
            addRecord();
            break;
        case DELETE_RECORD :
            deleteRecord();
            break;
        case FIND_RECORD :
            deleteRecord();
            break;
}

-----------------------------------------------------

#include <stdio.h>

void display_date(int day, int month, int year){

    printf("%d", day);

    switch (day) {
        case 1:
        case 21:
        case 31: printf("st "); break;
        case 2:
        case 22: printf("nd "); break;
        case 3:
        case 23: printf("rd "); break;
        default: printf("th ");
    }

    switch (month) {
        case 1: printf("Jan "); break;
        case 2: printf("Feb "); break;
        case 3: printf("Mar "); break;
        case 4: printf("Apr "); break;
        case 5: printf("May "); break;
        case 6: printf("Jun "); break;
        case 7: printf("Jul "); break;
        case 8: printf("Aug "); break;
        case 9: printf("Sep "); break;
        case 10: printf("Oct "); break;
        case 11: printf("Nov "); break;
        case 12: printf("Dec "); break;
    }

    printf("%d", year);
}

int main()
{
    int dval, mval, yval;
    int n = 20;

    while (n-- > 0) {
        
        printf("[Gun] [Ay] [Yil] bilgilerini giriniz: ");
        scanf("%d%d%d", &dval, &mval, &yval);
        display_date(dval, mval, yval);
        putchar('\n');
    }
}

-----------------------------------------------------

C dilinde switch deyiminde break kullanma zorunluluğu yoktur. Buna bir örnek.

#include <stdio.h>

int isLeap(int y) {
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

int dayOfYear(int day, int month, int year) {
    int sum = day;

    switch (month - 1) {
        case 11: sum += 30;
        case 10: sum += 31;
        case 9: sum += 30;
        case 8: sum += 31;
        case 7: sum += 31;
        case 6: sum += 30;
        case 5: sum += 31;
        case 4: sum += 30;
        case 3: sum += 31;
        case 2: sum += 28 + isLeap(year);
        case 1: sum += 31;
    }

    return sum;
}

int main()
{
    int dval, mval, yval;
    int n = 20;

    while (n-- > 0) {
        printf("[Gun] [Ay] [Yil] bilgilerini giriniz: ");        
        scanf("%d%d%d", &dval, &mval, &yval);
        printf("%d. gundesiniz", dayOfYear(dval, mval, yval));
    }
}

-----------------------------------------------------

Derleyiciler ya da statik kod analizi yapan programlar (yardımcı programlar - koddaki hataları compile-timeda yakalamaya çalışıyor)

Lint
Cppcheck
Clang Static Analyzer

Gerek derleyiciler, gerekse bu yardımcı programlar switch deyimleriyle ilgili aşağıdaki gibi bir kontrol yapma eğilimdeler.

switch (x) { 
    case 1:
    case 2: statement;
}

Yukarıdaki kod gayet doğru. Fakat aşağıdaki ilk case etiketinde, break kodunun yazılması unutulmuş.
Bir sentaks hatası olmaz fakat kodun anlamı değişir. Derleyiciler ve bu yardımcı programlar uyarı verebilir.

switch (x) { 
    case 1: statement_1;
    case 2: statement_2; break;
}

Eğer bu durum kodu yazarken bilerek yapılmışsa, yorum satırı ile kodu okuyan bilgilendirilebilir.

switch (x) { 
    case 1: statement_1; //fallthrough
    case 2: statement_2; break;
}

C++'da ise bu durum için aşağıdaki gibi bir attribute kullanılıyor. 

#include <stdio.h>

int main()
{
    int x = 1;

    switch (x) {
        case 1: printf("Case 1!"); [[fallthrough]]
        case 2: printf("Case 2!"); break;
    }
}

-----------------------------------------------------

Derleyicinin etkin kod üretmesi olayı

switch deyiminde case etiketleri ardışıksa, 

case 1:
case 2:
case 3:
case 4:

derleyici: "x'in değerinin 1 olup olmadığına bak",
derleyici: "x'in değerinin 2 olup olmadığına bak",
derleyici: "x'in değerinin 3 olup olmadığına bak",
derleyici: "x'in değerinin 4 olup olmadığına bak",

derleyici böyle bir kod üretse, 20 tane case olsa, çalışma zamanında 20 tane sorgulama yapılması gerekiyor.
Arkaplanda derleyici jump table denilen bir veri yapısı oluşturuyor ve direkt olarak ilgili yere yönlendiriyor.
Tabi bunu yapabilmesi için kodu net analiz edebilmesi gerekiyor ve bu case'lerin anlaşılır bir şekilde büyükten küçüğe veya küçükten büyüğe dizili olması gerekiyor.

Aynısını else if merdiveni ile kurduğumuzda, tabi derleyiciden derleyiciye değişir. 
Bu jump table oluşturulamayabiliyor.

-----------------------------------------------------

goto statement

Yazdığımız C kodu karşılığı, bir assembly kodu üretiliyor, assembler denilen program makine kodunu üretiyor.
Ama derleyici doğrudan makine kodunu da üretiyor olabilir.

Derleyicinin ürettiği kodda, bir çok yerde jump statement dediğimiz deyimler var. Programın akışının bir noktadan başka bir noktaya yönlendirilmesi.
Aslında bir çok yerde jump statement var.

while (x < 100) {
    //statement;
    //statement;
    ++x;
}

Jump statementları iki gruba ayırabiliriz.

a) long jump
b) local jump (near jump)

long jump, programın akışının bir fonksiyonunun kod alanından, başka bir fonksiyona geçmesi.

f1 => f2 => f3 => f4

f1 fonksiyonu f2'yi çağırmış
f2 fonksiyonu f3'ü çağırmış
f3 fonksiyonu f4'ü çağırmış

f4'ün kodu çalışıp sonlandığında, programın akışı f3'e geri dönecek.
f3'ün kodu çalışıp sonlandığında, programın akışı f2'ye geri dönecek.
f2'nin kodu çalışıp sonlandığında, programın akışı f1'e geri dönecek.

Ama biz istiyoruz ki, programın akışı, f4'de bir koşul gerçekleştiğinde, 
yukarıdaki sırayı değil de, doğrudan f4'den f1'e geçsin.

İşte bu tür sıçrama, programın akışı bir fonksiyondan başka bir fonksiyona gidiyor. Long Jump.

local jump ise programın akışının aynı fonksiyonun içinde bir noktadan bir noktaya yönlendirilmesi.

Programlama dillerinde long ve local jump sağlayan araçlar olabilir. C dilinde goto deyimi local jump yapıyor.
Yani bir fonksiyonun içinden, başka bir fonksiyona programın akışını yönlendirebiliyoruz.

C dilinde programın akışının bir fonksiyondan başka bir fonksiyona geçmesini sağlayan standart fonksiyonlar var.
longjmp - setjmp isimli standart fonksiyonlarla yapılıyor.

Ama goto deyimi, C'de local jump yapıyor. 

Yaygın bir söylem var goto kullanımı ile alakalı. goto kullanmayın diye.
Hiçbir kontrol kontrol deyimi gereksiz değil. goto deyiminin kötüye kullanımı, yerinde kullanılması, kullanılmaması gereken bir yerde kullanılması şüphesiz kod kalitesini düşürür.

Öyle yerler var ki, goto deyimini kullanmak, diğer alternatiflere göre daha iyi bir kod yapısı oluşturabiliyor.
Eğer goto deyiminin kullanımı kötü olsaydı, Linux çekirdeğinde 1000den fazla goto kullanımı olmazdı.

---------------------------------------------

Programın akışını keyfi bir şekilde oradan oraya, oradan oraya yönlendirirsek, kodu test etmek, değiştirmek, anlamak zorlaşır.
Dolayısıyla goto deyimini programın akışını keyfi bir şekilde yönlendirmek için kullanmak iyi bir fikir değil.

Her zaman, örneğin bir fonksiyon söz konusu olduğunda, fonksiyonun tek bir girişinin, tek bir çıkışının olması işleri kolaylaştırıyor.
Ama biz fonksiyonun bir yerinden programın akışını başka bir yere yönlendirirsek, kodun okunmasını zorlaştırıyor.

Kullanımı önerilen yerlerin dışında goto kullanımı, gerçekten kod kalitesini düşürüyor.

goto deyiminin sentaksı

C ve C++ dilinde etiket adında kavramlar var.
label'lar birer identifier. 

Nasıl bir değişkenin ismi bir identifier veya fonksiyonun ismi bir identifier ise, etiketler de ismi olan varlıklar.

Bir etiketin tanımlanması aşağıdaki gibi oluyor. Bu arada etiketler sadece lokal isim alanında oluşturabiliyor.

labelAdi:

Etiketler goto deyiminin dışında da kullanılabilir. Bir sentaks hatası değil fakat tek kural, etiketten sonra bir deyim gelmesi gerekiyor.
Null statement, boş deyim koyabiliriz eğer istersek.

labelAdi: ;

Etiketler ayrı bir kapsam kuralına tabii tutuluyor.

kapsam kategorileri

file scope
block scope

function prototype scope

sadece fonksiyon bildirimleriyle ilgili. bir fonksiyon bildiriminde, bildirimin parametre parantezi içinde, 
parametre değişkenlerine isim verebiliriz fakat isim verirsek, bu isim sadece bu parantezin içinde bilinir.
yani derleyici herhangi bir ismi ararken bu parantezin içine bakmaz.

function scope

function scope ise label'lara ilişkindir. bir label tanımlanır fakat fonksiyonun içinde her yerde bilinir.

void func()
{
    ////burada da kullanılabilir
    label:
    ////burada da kullanılabilir
}

Label'ların bir başka özelliği, ayrı bir scope kabul edildikleri için, diğer block scopedaki isimlerle çakışma durumu yok.
Yani aşağıdaki örnekte, hem yerel değişkenin isminin out olması, hem dem label'a verilen isminin out olması bir sentaks hatası değil.

void func()
{
    int out = 5;
    out:
        ;
}

-----------------------------------------

goto bir anahtar sözcük. goto anahtar sözcüğünü bir etiket ismi takip etmek zorunda.

goto error;

error:
    statement;

---------------

void func()
{
    //statement
    //statement
    if (1)
        goto error;
    //statement
    //statement
error: 
    printf("Test basarili!");
}

--------------

goto deyiminin kullanımında, çok ekstrem bir söz konusu değilse, fonksiyon içinde daha yukarıdaki bir noktaya yönlendirme yok.
Her ne kadar bir sentaks hatası olmasa da, daha çok goto deyiminin, faydalı kullanımlarında programın akışı goto anahtar sözcüğünden daha yukarıya değil, daha aşağıya yönlendirilir.

goto deyiminin tipik kullanımları

Bir tanesi, iç içe döngü deyimlerinde, içteki ya da en içteki döngü deyiminden bir koşul gerçekleştiğinde sadece içinde bulunduğumuz döngüden değil,
onu sarmalayan döngüden de çıkmak.

bool flag = false;

for (;;) {
    statement1;
    statement2;
    for (;;) {
    statement3;
        while (exp) {
            statement4;
            if (c_exp) {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
        statement5;        
    }
        if (flag)
            break;
    statement6;
}

statement7;


Yukarıdaki kodda, if deyiminin içindeki koşul doğru ise, programın akışının statement7'ye yönlendirilmesini istiyoruz.
Bunu bir bayrak değişken ile yapabiliriz. Başlangıçta bool flag = false değerini veririz, bütün döngüleri kırmak istediğimiz yerde flag = true yaparız ve break komutu ile döngüyü kırmış oluruz.

Ama bu kodda bunu sağlamak için bir tane bayrak değişken aldık, ilgili yerlerde set ettik, döngü çıkışlarında bayrağı kontrol ettik.

goto deyimi ile, doğrudan, if'in doğru kısmında goto deyimi kullanarak bunu rahatlıkla yapabiliriz.
Kod çok daha iyi okunur hâle geldi.

for (;;) {
    statement1;
    statement2;
    for (;;) {
    statement3;
        while (exp) {
            statement4;
            if (c_exp) {
                goto out;
            }
        }
        statement5;        
    }
    statement6;
}
out:
statement7;


-----------------------------------------

Yine senaryo aynı. Fakat döngü yerine switch deyimi olabilir. Switch deyiminde de, döngü deyiminde de break deyimi kullanılıyor.

while (expr) {
    ///
    switch (iex) {
        break; //buradaki break deyimi, döngünün break deyimi değil, switch'in break deyimi.
    }
}

Ama biz burada, switchi sarmalayan döngü deyiminden de çıkılmasını istiyorsak goto deyimiyle bunu kullanabiliriz.

while (expr) {
    ///
    switch (iex) {
        goto out;
    }
}

out:
    statement;

-----------------------------------------

Bir fonksiyon var, fonksiyonun içinde fonksiyon çağrıları veya bir takım işlemler var. 
Fakat belirli koşullar oluştuğunda, hata koşulu oluştuğunda, programın akışının bir noktaya yönlendirilmesi gerekiyor fakat bu birden fazla kez tekrar ediliyor.

void func()
{
    if (do_something() == ERR) // Bu fonksiyonu çağır, geri dönüş değeri hata koduysa programın akışını hatayı işlediği yere yönlendirecek.
        goto error;
    if (do_something2() == ERR)
        goto error;
    if (do_something3() == ERR)
        goto error;
    if (do_something4() == ERR)
        goto error;

error:
    ///

}

-----------------------------------------

Mülakatlarda sorulan sorulardan biri, default anahtar sözcüğünü bilerek yanlış yazıyorlar.
Bir sentaks hatası oluşmuyor çünkü bir label oluşturmuş oluyoruz.

Dolayısıyla default case ortada olmuyor.

switch (x) {
    case 1: statement1; break;
    case 2: statement2; break;
    case 3: statement3; break;
    case 4: statement4; break;
    defualt: statement; break;
}

-----------------------------------------

#line

#line önişlemci komutu line ve file makrosunun değerini değiştirmek için kullanılıyor.
Genellikle kod üreten kodlar için kullanılıyor.

__LINE__
__FILE__

int main()
{
    #line 1000
        printf("%s dosyasinin %d satiri\n", __FILE__, __LINE__);
}

int main()
{
    #line 1000 "dogukan"
        printf("%s dosyasinin %d satiri\n", __FILE__, __LINE__);
}

-------------------------------

#error

Programın derleme sürecini daha önişlemci aşamasında durduruyor.
Öyle durumlar var ki, kaynak dosyamızın derlenmesi aşamasında derleme zamanında kontrol edilebilecek bazı koşulların sağlanmaması durumunda,
daha karmaşık bir durum oluşmadan, error direktifi ile programın derlenmesi sonlandırılıyor.
#include <stdio.h>

int main()
{
    #error "Burada bir hata var"
}

Mesela, bizim bir C++ programımız var, kaynak dosyamız var. Fakat bu kaynak dosyanın C derleyicisi tarafından derlenme girişimini engelleyebiliriz.

#ifndef __cplusplus
#error Bu kaynak dosya sadece CPP derleyicisi ile derlenmeli
#endif

-------------------------------

#pragma

bu önişlemci komutu belirli bir işi yapmıyor. 
C standartları, önişlemci programın farklı amaçlarla da kullanımına olanak sağlamak için,
derleyici yazanlara bu şekilde bir olanak sağlamak.

#pragma önişlemci komutu standart fakat bununla neler yapılacağı tamamen derleyiciye bağlı.
yani bir derleyicisinin pragmasıyla, başka bir derleyicinin pragması aynı olmak zorunda değil.

#pragma once        //multiple inclusion guard
#pragma pack(1)     //alignment - hizalama amaçla kullanılıyor

Mesela aşağıdaki koddaki gibi if deyiminin içinde atama yaptık, bununla alakalı olarak derleyici uyarı - warning mesajları verebilir.
Bunun olmasını istemiyorsak için aşağıdaki pragma önişlemci komutunu kullanabiliriz, tabiki bu durum tamamen kullanılan derleyiciye bağlı.

int main()
{
    int x = 5;

    if (x = 7)
        ;
}

//warning C4706: assignment within conditional expression

#pragma warning (disable: 4706)

pragma'lar derleyiciye özgü.

*/