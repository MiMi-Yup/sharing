# # IT008.M11 - VISUAL PROGRAMMING 
**© 2021 University of Information Technology / autoStudent Project**
------------
## THÀNH VIÊN THAM GIA
<details>
  <summary>Thông tin chi tiết các thành viên</summary>

| No. | Student ID | Full name | Class | Role |
| --- | --- | --- | --- | --- |
| 1 | 20521008 | [Phan Xuân Quang](https://github.com/phanxuanquang "Phan Xuân Quang") | KTPM2020 | Trưởng nhóm |
| 2 | 20521956 | [Trần Văn Thiệt](https://github.com/MiMi-Yup "Trần Văn Thiệt") | KTPM2020 | Thành viên |
| 3 | 20521768 | [Nguyễn Hoàng Phúc](https://github.com/phucnh20521768 "Nguyễn Hoàng Phúc") | KTPM2020 | Thành viên |
| 4 | 20521205 | [Dín Hiền Dũng](https://github.com/dung-ovl "Dín Hiền Dũng") | KTPM2020 | Thành viên |

</details>

###  **1. TỔNG QUAN**
<details>
  <summary>Bài toán thực tế</summary>

Trong thực tế đời sống và công việc, chúng ta thường sẽ gặp các tình huống sau:

- *Trường đại học muốn tự thiết lập hệ thống các phần mềm cần thiết trong máy tính Windows của các sinh viên.*
- *Sinh viên không hiểu biết nhiều về công nghệ thông tin hoặc sinh viên năm nhất cần xây dựng tập hợp phần mềm cần thiết cho chương trình học một cách tiện lợi nhất.*
- *Người dùng muốn cài một tập hợp nhiều phần mềm một cách nhanh nhất.*
- *Một tổ chức muốn tiết kiệm thời gian và nhân lực cho việc thiết lập hệ thống phần mềm trong máy tính Windows của toàn bộ nhân viên hoặc chỉ đơn giản là muốn cài thêm một số lượng phần mềm cho máy tính của các nhân viên mà không muốn phải ghost Windows hay để nhân viên tự cài đặt.*
- . . .

</details>

<details>
  <summary>Mục tiêu ứng dụng</summary>

- Chọn lọc những phần mềm có thể hỗ trợ (hơn 150 phần mềm).
- Tự động hóa quá trình cài đặt và gỡ cài đặt.
- Chia sẻ những phần mềm cho nhiều người khác.
- Các tiện tích như hẹn giờ, chạy ngầm, .v.v

</details>

### **2. YÊU CẦU CHỨC NĂNG CHI TIẾT**

### **3. YÊU CẦU HỆ THỐNG**

| No. |  | Tối thiểu | Khuyến nghị |
| --- | --- | --- | --- |
| 1 | Hệ điều hành | Windows 7 32-bit | Windows 10 64-bit trở lên |
| 2 | RAM | 2 GB | 4 GB trở lên |
| 3 | Dung lượng trống trong ổ cứng | 1GB trên mỗi 10 phần mềm được chọn | 2GB trên mỗi 10 phần mềm được chọn | 
| 5 | Kết nối mạng | Chỉ cần cho tác vụ cài đặt | Chỉ cần cho tác vụ cài đặt |

### **4. Công nghệ sử dụng**

<details>
  <summary>Các công nghệ sử dụng</summary>

- Nền tảng: .Net Framework, version 4.7.2
- Thư viện đồ họa: Windows Forms, GunaUI
- IDE: Microsoft Visual Studio 2019
- Thư viện hỗ trợ khác: Newtonsoft.Json, Microsoft.WindowsAPICodePack

</details>

### **5. CÁC CHỨC NĂNG CHÍNH - HƯỚNG DẪN CÀI ĐẶT**

**3.1. Tự động cài đặt phần mềm hàng loạt.**

**3.2. Tự động GỠ cài đặt phần mềm hàng loạt.**

**3.3. Dọn dẹp và cập nhật nhanh chóng.**

**3.4. Thiết lập hành động.**
- Xuất danh sách phần mềm được chọn sau khi cài đặt hoặc gỡ cài đặt hoàn tất. 
- Nhập danh sách phần mềm muốn cài đặt hoặc gỡ cài đặt.
- Hẹn giờ khởi chạy trình cài đặt hoặc gỡ cài đặt.
- Thiết lập hành động sau khi hoàn tất quá trình cài đặt hoặc gỡ cài đặt.
- Chạy ngầm và khởi động cùng hệ điều hành.