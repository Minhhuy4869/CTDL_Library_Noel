# CTDL_Library_Noel

# 📚 PROJECT QUẢN LÝ THƯ VIỆN

## 👥 Thành viên nhóm
| STT | Họ và tên | Nhiệm vụ chính |
|-----|------------|----------------|
| 1 | [Tên bạn 1] | Thiết kế cấu trúc dữ liệu, xử lý file, xây dựng lớp `Sach` |
| 2 | [Tên bạn 2] | Xây dựng lớp `BanDoc`, chức năng mượn/trả sách, giao diện menu |

---

## 🎯 Mục tiêu dự án
Dự án **Quản lý thư viện** giúp lưu trữ, quản lý thông tin sách và bạn đọc một cách hiệu quả.  
Chương trình cho phép:
- Quản lý danh sách sách và bạn đọc.
- Thực hiện mượn – trả sách.
- Cập nhật tình trạng sách theo thời gian thực.
- Lưu trữ dữ liệu ra file `.txt` để sử dụng lâu dài.

---

## 🧩 Cấu trúc dữ liệu chính

### 1. **Lớp `Sach`**
Mỗi quyển sách có các thông tin:
- Mã sách (duy nhất)  
- Tên sách  
- Tác giả  
- Nhà xuất bản  
- Giá bán  
- Năm phát hành  
- Số trang  
- Ngày nhập kho  
- Tình trạng sách  
  - `0`: Sách đang có sẵn  
  - `n`: Số thứ tự phiếu mượn nếu đang được mượn  

**File dữ liệu:** `Sach.txt`

Ví dụ: 
```plaintext
Ma sach: S001
Ten sach: Lap trinh C++ co ban
Tac gia: Nguyen Van A
Nha xuat ban: NXB Tre
Gia ban: 75000
Nam phat hanh: 2020
So trang: 350
Ngay nhap kho: 10/10/2024
Tinh trang: 0
```
### 2. **Lớp `BanDoc`**
Mỗi bạn đọc có các thông tin:
- Mã bạn đọc (duy nhất)  
- Họ tên  
- Ngày đăng ký  

**File dữ liệu:** `BanDoc.txt`

Ví dụ:
```plaintext
Ma ban doc: BD001
Ho ten: Nguyen Van Minh
Ngay dang ky: 10/10/2024
```

---

## ⚙️ Chức năng chính

| Chức năng | Mô tả |
|------------|-------|
| 1️⃣ | Thêm, sửa, xóa thông tin sách |
| 2️⃣ | Thêm, sửa, xóa thông tin bạn đọc |
| 3️⃣ | Tìm kiếm sách hoặc bạn đọc theo mã/tên |
| 4️⃣ | Ghi và đọc dữ liệu từ file |
| 5️⃣ | Mượn sách – cập nhật tình trạng sách |
| 6️⃣ | Trả sách – khôi phục tình trạng ban đầu |
| 7️⃣ | Hiển thị danh sách hiện có |

---

## 🏗️ Cấu trúc thư mục

>📁 LibraryManagement
>├── 📄 main.cpp
>├── 📄 Sach.h / Sach.cpp
>├── 📄 BanDoc.h / BanDoc.cpp
>├── 📄 MuonTra.h / MuonTra.cpp
>├── 📄 Sach.txt
>├── 📄 BanDoc.txt
>└── 📄 README.md
