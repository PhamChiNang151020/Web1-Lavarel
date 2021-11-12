# Hướng dẫn cài đặt môi trường
#### Tải XAMPP:<pre> https://www.apachefriends.org/download.html </pre>
#### Tải Composer: <pre> https://getcomposer.org/download/ </pre>
- Quá trình không mất tới vài phút. Bạn có thể bỏ qua developer mode trong quá trình và nhấn nút <i>Next</i>
- Một cửa sổ hiện lên và hỏi vị trí PHP command line. Mặc định nó là trong C:/xampp/php/php.exe. Sau khi xác định vị trí, nhấn nút <i>Next</i>.
- Bạn sẽ được hỏi <i>Proxy Settings</i>. Để ô này mặc định không check và nhấn <i>Next</i>. Rồi nhấn <i>Install</i>.
- Sau khi hoàn tất cài đặt, mở command prompt và gõ: <pre>composer</pre>
#### Tạo Project
- Truy cập vào nơi cần tạo project
- Trên thanh đường dẫn gõ: <b>cmd</b>
- Cửa sổ cmd xuất hiện và gõ: <pre> composer create-project --prefer-dist laravel/laravel ten-project "5.8.*" </pre>
  + <b> composer </b>: yêu cầu ứng dụng composer thực hiện
  + <b> create-project </b>: tùy chọn của câu lệnh composer nhằm tạo dự án mới
  + <b> --prefer-dist </b>: thực hiện cài đặt từ dist trên respository
  + <b> laravel/laravel </b> : cấu trúc vendor/package tham chiếu đến gói phần mềm tên laravel của vendor laravel.
  + <b> ten-project </b> : Tên Project mà bạn tạo
  + <b> "5.8.*" </b>: Là phiên bản package bạn muốn cài đặt. Có thể bỏ trống và hệ thống sẽ cài đặt theo gói mới nhất
#### Test
- Vào thư mục <i>ten-project</i> mà bạn đã tạo trước đó.
- Trên thanh đường dẫn gõ: <b>cmd</b>
- Cửa sổ cmd xuất hiện và gõ: <pre>php artisan serve</pre>
- Sau đó sẽ xuất hiện ![image](https://user-images.githubusercontent.com/87531241/141393342-a5498853-e9df-4c2e-bafc-3a269fff2e00.png)
- Copy đường dẫn và dán vào trình duyệt web.
