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
