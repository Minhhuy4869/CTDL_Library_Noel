# CTDL_Library_Noel

# 📚 PROJECT QUẢN LÝ THƯ VIỆN

## 👥 Thành viên nhóm
| STT | Họ và tên | Nhiệm vụ chính |
|-----|------------|----------------|
| 1 | Trịnh Minh Huy (leader) | Xây dựng lớp `Sach`, lớp `BanDoc`, viết báo cáo tổng kết |
| 2 | Nguyễn Khắc Trung | Thiết kế giao diện đăng nhập, xây dựng lớp `PhieuMuon`, video demo |

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
S001
Rung Na Uy
Haruki Murakami
NXB Tre
75000
2020
350
10/10/2024
0
```
### 2. **Lớp `BanDoc`**
Mỗi bạn đọc có các thông tin:
- Mã bạn đọc (duy nhất)  
- Họ tên  
- Ngày đăng ký  

**File dữ liệu:** `BanDoc.txt`

Ví dụ:
```plaintext
BD001
Nguyen Van Minh
10/10/2024
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

```markdown
### 🧩 Cấu trúc thư mục dự án

📁 LibraryManagement/
│
├── 📄 main.cpp              → Chương trình chính
│
├── 📂 include/
│   ├── 📄 Sach.h
│   ├── 📄 BanDoc.h
│   └── 📄 MuonTra.h
│
├── 📂 src/
│   ├── 📄 Sach.cpp
│   ├── 📄 BanDoc.cpp
│   └── 📄 MuonTra.cpp
│
├── 📂 data/
│   ├── 📄 Sach.txt
│   └── 📄 BanDoc.txt
│
└── 📄 README.md
```

---

## 💾 Ghi chú về file dữ liệu
- Mỗi đối tượng được ngăn cách bằng dòng `"---"`.
- Dữ liệu có thể lưu ở **phiên bản có dấu** hoặc **không dấu** tùy theo yêu cầu.
- Khi chương trình khởi động, dữ liệu sẽ được đọc từ file vào cấu trúc dữ liệu tương ứng.

---

## 🚀 Hướng phát triển
- Xây dựng giao diện người dùng bằng console hoặc Qt.  
- Mở rộng quản lý thêm: nhân viên thư viện, thống kê sách mượn nhiều nhất.  
- Chuyển đổi sang lưu trữ dữ liệu dạng `.csv` hoặc `.json` để thuận tiện hơn.

---

