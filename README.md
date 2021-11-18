# Hướng dẫn cài đặt môi trường
#### Tải XAMPP:<pre> https://www.apachefriends.org/download.html </pre>
Tại đây bạn có thể thay đổi thư mục cài đặt của XAMPP tùy theo mục đích sử dụng của bạn. Khuyến khích bạn tạo thư mục "xampp" tại ổ đĩa khác. VD: D
#
#### Tải Composer: <pre> https://getcomposer.org/download/ </pre>
- Quá trình không mất tới vài phút. Bạn có thể bỏ qua developer mode trong quá trình và nhấn nút <i>Next</i>
- Một cửa sổ hiện lên và hỏi vị trí PHP command line. 
  + Nếu bạn cài đặt XAMPP mặc định thì nó sẽ là trong C:/xampp/php/php.exe. Sau khi xác định vị trí, nhấn nút <i>Next</i>.
  + Nếu bạn cài đặt XAMPP theo thư mục của bạn. Bạn cần đi đến thư mục cài đặt của XAMPP. Sau đó tìm thư mục <i>php</i> và tìm file "php.exe"
- Bạn sẽ được hỏi <i>Proxy Settings</i>. Để ô này mặc định không check và nhấn <i>Next</i>. Rồi nhấn <i>Install</i>.
- Sau khi hoàn tất cài đặt, mở command prompt và gõ: <pre>composer</pre>
- Nếu được kết quả như sau thì bạn đã cài đặt thành công composer

![image](https://user-images.githubusercontent.com/87531241/141424442-0bb1b646-3820-4582-8706-0564c119c29a.png)
#
#### Hướng dẫn tạo Project khi sử dụng XAMPP
- Mở XAMPP và truy cập vào Explorer. LƯU Ý: Nhớ <b>start</b> Apache nhé ![image](https://user-images.githubusercontent.com/87531241/141424755-5fab6c2c-f9c6-45b4-b45b-05c938d80c92.png)
- Truy cập thư mục htdocs, xóa tất cả mọi thứ để cho thư mục này hoàn toàn trống. (Tiện cho việc sử dụng sau này)

![image](https://user-images.githubusercontent.com/87531241/141422329-9ab43d6e-a92d-4819-824a-9f490f02bcc9.png)
- Tại thanh đường dẫn thư mục gõ: cmd 


![image](https://user-images.githubusercontent.com/87531241/141424875-3fbb3074-4475-4f7c-88fc-ae24f310888f.png)

- Cửa sổ cmd xuất hiện, gõ: <pre> composer create-project --prefer-dist laravel/laravel ten-project "5.8.*" </pre>
  + <b> composer </b>: yêu cầu ứng dụng composer thực hiện
  + <b> create-project </b>: tùy chọn của câu lệnh composer nhằm tạo dự án mới
  + <b> --prefer-dist </b>: thực hiện cài đặt từ dist trên respository
  + <b> laravel/laravel </b> : cấu trúc vendor/package tham chiếu đến gói phần mềm tên laravel của vendor laravel.
  + <b> ten-project </b> : Tên Project mà bạn tạo
  + <b> "5.8.*" </b>: Là phiên bản package bạn muốn cài đặt. Có thể bỏ trống và hệ thống sẽ cài đặt theo gói mới nhất
- Mình tạo như sau: 

![image](https://user-images.githubusercontent.com/87531241/141423288-1a3142af-65b4-478e-af3a-d7a2ed53fda2.png)
- Enter và được kết quả sau:

![image](https://user-images.githubusercontent.com/87531241/141423420-c63a296d-7ea7-44b6-8e33-550d4109116d.png)
- Mở powershell trên thư mục bằng cách sử dụng "SHIFT" + "Right-Click" 
- Nhập lệnh: <pre> php artisan serve </pre>

![image](https://user-images.githubusercontent.com/87531241/142377365-c6a63f09-2459-4ba9-980e-73c0e737c276.png)

- Sau đó copy đường dẫn và dán vào trình duyệt

![image](https://user-images.githubusercontent.com/87531241/142377493-6e881abb-4da8-46bf-8345-cf3d59317372.png)


- Hình trên là các project mình đã tạo

![image](https://user-images.githubusercontent.com/87531241/142377718-2a788d17-0615-4e4b-9e27-237b33844d49.png)


- Nếu được kết quả như hình trên thì bạn đã tạo thành công một project với <b>famework lavarel</b>
