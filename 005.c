/* 

Ders5

Global Namespace (Global İsim Alanı)
Local Namescape (Lokal İsim Alanı)

Global bütün değişkenler statik ömürlü olmak zorundadır.
Yerel değişkenler biz istersek statik veya otomatik ömürlü olabilirler.

void func(void)
{
    int x;          //automatic storage class
    static int y;   //static storage class
}

, (comma operator veya delimeter(ayıraç) olarak kullanılır)

aynı türden birden fazla değişken tanımlamak istenildiğinde

int x, y, z; //comma separated list

constant expression (sabit ifadesi)
Derleyici programın çalışma zamanında ifadenin değerini tam olarak hesaplayabiliyor.
C dilinin kurallarında bazı yerlerde sabit ifadesi kullanmak gerekiyor.

++statik ömürlü değişkenlere ilk değer veren ifadelerin sabit ifadesi olması gerekir.

int x = 0;
int y = x + 5; (bu bir sabit ifadesi değildir, x değişkendir.)

C dilinde statik ömürlü değişkenlere ilk değer veren ifadenin sabit ifadesi olması gerekir.
C++ dilinde statik ömürlü değişkenlere ilk değer veren ifadenin sabit ifadesi olmasına gerek yoktur.

C89 Standartlarında yerel düzeyde yapılan bildirimlerde bir deyimden sonra bir bildirim yapılamaz.
Aşağıdaki kod bloğu C89 standartlarına göre sentaks hatasıdır.

{
    int x = 10;
    ++x;
    int y = 5;

    veya 

    printf("dogukanyazar");
    int x = 10;
}

// C89 standartlarında bu açıklama satırı biçimi yoktu.

C99 Standartlarında ise kod bloğunun istediğimiz yerinde değişken bildirimi yapabiliriz.

Scope (Bilinirlik Alanı - Kapsam)

Her ismin bir kapsamı (scope) vardır.
Bir ismin kapsamı dışında kullanılması sentaks hatasıdır.
Tanımlanan isimlerin kapsamları dilin kurallarına göre belirlenir.

scope
name lookup

C'nin scope kategorileri.

file scope (dosya kapsamı) //en çok bizi ilgilendiren
block scope (blok kapsamı) //en çok bizi ilgilendiren

function prototype scope (işlev prototip kapsamı)
function scope (işlev kapsamı)

File Scope (dosya kapsamı)
Bir isim global kod alanında bildirilmişse, bu isim bildirildiği noktadan dosyanın sonuna kadar kullanılabilir.

Block Scope (blok kapsamı)

{
    int x = 10;
    //Bu ismi sadece ilgili bloğun sonuna kadar kullanabiliriz.
}

Bloklar iç içe olabilir. Nested block. Aynı kurallar geçerlidir.

İsim Arama Kuralları

Eğer bir isim, bir blok içerisinde kullanılmışsa önce kullanıldığı yerden kullanıldığı bloğun başına kadar olan kod alanında aranır.
Eğer bu alan bulunamaz ise, kapsayan bloğun başından içsel bloğun başladığı yere kadar aranır.
Eğer isim kapsayan blokların hiçbirinde bulunamazsa, global isim alanında dosyanın başından ismin kullanıldığı fonksiyonun tanımına kadar olan kod alanında aranır.


{   
    //2
    {   
        //1
        x;
    }
}

Aynı kapsamda isim birden fazla varlığa verilemez.
Ama farklı kapsamlarda bildirilen varlıkların isimleri aynı olabilir.
Örnek olarak global isim alanında birden farklı varlığa aynı isim verilemez.

Eğer iki ismin kapsamı aynı kapanış paranteziyle sonlanıyorsa, kapsamları aynıdır.
Eğer iki ismin kapsamı farklı kapanış paranteziyle sonlanıyorsa, kapsamları farklıdır.


int x = 10; //1

int main()
{
    int x = 20; //2

    if (x > 5) {
        int x = 30; //3
        
        if(x > 10){
            int x = 40; //4
        }
    }
}


NAME HIDING (İsmin Gizlenmesi)

İsim arama kuralları nedeniyle bir ismin daha dar scope'da aynı ismin bildirilmesi nedeniyle kullanılamaması demek.

name hiding
name masking
name shadowing

// C dilinde bu durumda global ismi kullanmanın hiçbir yolu yok.
// C++ dilinde ise bunun için bir operatör mevcut. :: (scope resolution operator - kapsam çözünürlük operatörü) (unary operator - tek olarak kullanmak)

::x derleyici bu ismi global isim alanında ara.

printf("x = %d", ::x);

int x = 10; (local x hides global x (yerel x, global x ismini gizledi))

int main()
{
    int x = 45; //İlk önce burada aranır.
    
    printf("x = %d", x);
}

İsmin gizlenmesi iç içe bloklarda da olabilir.

int main()
{
    int x = 10; // gizlenmiş, maskelenmiş isim. C dilinde bu ismi kullanmanın bir yolu yoktur. C++'da da yoktur. Sadece global bir isim alanına erişmek için :: operatörü kullanılır.

    if(1) {
        int x = 20;

        x++;
    }
}

Initialization is not assignment!
İlk değer verme, atama değildir!

int x = 10; // x ismine ilk değer vermek, initialize etmek.

int x = 24; // bu bir bildirim, declaration. ilk değer vermek.
x = 48; // bu bir deyim, statement. atama. 

-----------------------------------------------------------------------

Fonksiyonlar (Function, Subroutine)

fonksiyon
işlev
yordam

Fonksiyonlar C dilinde programların temel yapı taşlarıdır.
Fonksiyonlar kod tekrarını önler. Aynı kodu tekrar tekrar yazmaktan kaçınmış oluyoruz.
Kodu fonksiyonlara ayırarak yazmak, kodun test edilmesini ve okunmasını kolaylaştırır.

CODE REUSE (kodun tekrar kullanımı sağlanıyor)

C ve C++ dillerinde bağımsız bir görevi olan, ayrı bir işi olan, programın çalışma zamanında bu kod çalıştırıldığı zaman bu işin yapılmasını sağlayan bir varlık, kod parçası.

to declare a function (fonksiyon bildirimi)
to define a function (fonksiyon tanımlaması)
to call a function (fonksiyon çağrısı)

int main() //fonksiyon tanımı
{
    printf("Merhaba Dünya!\"); //fonksiyon çağrısı
}

ismi main olan fonksiyon tanımlanmış
ismi printf olan fonksiyon çağrılmış

fonksiyon bildirimi ise bu kod için ön işlemci komutlarındadır.


fonksiyon_geri_donus_deger_turu fonksiyon_ismi (fonksiyon parametre parantezi)
{
    //fonksiyonun_ana_blogu
}

double sqrt(double dval)
{
    //...
}

Bir fonksiyonun geri dönüş değer türü olmak zorunda değildir.

a) Fonksiyon bir değer iletiyordur ama geri dönüş değer mekanizması ile iletmiyordur.
b) Fonksiyon zaten bir değer hesaplamaya yönelik değildir. Örnek olarak ekran temizleyen fonksiyon.

Fonksiyon isimlendirilmesi geleneksel olarak küçük harfle yapılır.

Bir fonksiyonun parametre değişkeni olmayabilir, çünkü çağıran koddan bir değer talep etmiyor olabilir.
Bu sebeple parametre değişkeni olarak void anahtar sözcüğü kullanılır.

double func(void)
{

}

double func(int x, int y)
{
    
}
 */
