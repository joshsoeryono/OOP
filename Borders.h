/*
#include <iostream>
#include "Windows.h"
#include "Macros.h"
*/

class Menu
{
	private:
		char border;
	public:
		char get_border()
		{
			return border;
		}
		void set_border(char border)
		{
			this->border=border;
		}
		
		virtual void draw()=0;
};

class Rect_Out: public Menu
{
	public:
		Rect_Out()
		{
			this->set_border(BORDER03);
		}
		
		void draw()
		{
			cursor_position(0, 0);
			
			// bagian atas judul.
			loop(0, 138) std::cout << this->get_border();
			std::cout << std::endl;
			
			// bagian tengah judul.
			loop(0, 2) std::cout << this->get_border();
			loop(0, 138-4) std::cout << ' ';
			loop(0, 2) std::cout << this->get_border();
			std::cout << std::endl;
			
			// bagian bawah judul.
			loop(0, 138) std::cout << this->get_border();
			std::cout << std::endl;
			
			// bagian frame dalam.
			loop(3, 33)
			{
				loop(0, 2) std::cout << this->get_border();
				loop(0, 138-4) std::cout << ' ';
				loop(0, 2) std::cout << this->get_border();
				std::cout << std::endl;
			}
			
			// bagian frame bawah (menutup desain).
			loop(0, 138) std::cout << this->get_border();
			std::cout << std::endl;
		}
};

class Rect_In: public Menu
{
	public:
		Rect_In()
		{
			this->set_border(BORDER02);
		}
		
		void draw()
		{
			// bagian atas.
			cursor_position(2, 3);
			loop(0, 138-4) std::cout << this->get_border();
			
			// bagian tengah.
			loop(4, 32)
			{
				cursor_position(2, index); // index merupakan variabel yang dideklarasikan di "Macros.h" untuk mengambil indeks perulangan.
				
				loop(0, 2) std::cout << this->get_border();
				loop(0, 138-8) std::cout << ' ';
				loop(0, 2) std::cout << this->get_border();
			}
			
			// bagian bawah.
			cursor_position(2, 32);
			loop(0, 138-4) std::cout << this->get_border();
		}
};

class Layout: public Menu
{
	public:
		Layout()
		{
			this->set_border(BORDER01);
		}
		
		void draw()
		{
			// bagian atas judul.
			cursor_position(4, 4);
			loop(0, 138-8) std::cout << this->get_border();
			
			// bagian tengah judul.
			cursor_position(4, 5);
			loop(0, 1) std::cout << this->get_border();
			loop(0, 138-10) std::cout << ' ';
			loop(0, 1) std::cout << this->get_border();
			
			// bagian bawah judul.
			cursor_position(4, 6);
			loop(0, 138-8) std::cout << this->get_border();
			
			// bagian frame sebelum posisi handle untuk menulis chat.
			loop(7, 28)
			{
				cursor_position(4, index); // index merupakan variabel yang dideklarasikan di "Macros.h" untuk mengambil indeks perulangan.
				
				loop(0, 1) std::cout << this->get_border();
				loop(0, 138-10) std::cout << ' ';
				loop(0, 1) std::cout << this->get_border();
			}
			
			// bagian frame pembatas fitur chat.
			cursor_position(4, 28);
			loop(0, 138-8) std::cout << this->get_border();
			
			// bagian frame sesudah posisi handle untuk menulis chat.
			loop(29, 31)
			{
				cursor_position(4, index); // index merupakan variabel yang dideklarasikan di "Macros.h" untuk mengambil indeks perulangan.
				
				loop(0, 1) std::cout << this->get_border();
				loop(0, 138-10) std::cout << ' ';
				loop(0, 1) std::cout << this->get_border();
			}
			
			// bagian frame bawah (menutup desain).
			cursor_position(4, 31);
			loop(0, 138-8) std::cout << this->get_border();
		}
};

class Title: public Menu
{
	private:
		std::string str_title;
	public:
		std::string get_str_title()
		{
			return str_title;
		}
		void set_str_title(std::string str_title)
		{
			this->str_title=str_title;
		}
		
		Title()
		{
			this->set_border(BORDER03);
			this->set_str_title("VACATIONPEDIA, LIBUR TANPA BINGUNG");
		}
		
		void draw()
		{
			// bersihkan baris judul.
			cursor_position(0+2, 1);
			loop(0, 138-4) std::cout << ' ';
			
			// ganti dengan judul yang baru.
			cursor_position((138/2)-(this->get_str_title().size()/2)-2, 1); // -2 di belakang untuk D_ARROW_LEFT dan sebuah spasi.
			std::cout << D_ARROW_LEFT << ' ' << this->get_str_title() << ' ' << D_ARROW_RIGHT;
		}
};

class SubTitle: public Menu
{
	private:
		std::string str_subtitle;
	public:
		std::string get_str_subtitle()
		{
			return str_subtitle;
		}
		void set_str_subtitle(std::string str_subtitle)
		{
			this->str_subtitle=str_subtitle;
		}
		
		SubTitle()
		{
			this->set_border(BORDER01);
			this->set_str_subtitle("RUANG PERCAKAPAN");
		}
		
		void draw()
		{
			// bersihkan baris subjudul.
			cursor_position(4+1, 5);
			loop(0, 138-10) std::cout << ' ';
			
			// ganti dengan subjudul yang baru.
			cursor_position((138/2)-(this->get_str_subtitle().size()/2)-8, 5); // -8 di belakang untuk tujuh buah D_ARROW_LEFT dan sebuah spasi.
			loop(0, 7) std::cout << D_ARROW_LEFT;
			std::cout << ' ' << this->get_str_subtitle() << ' ';
			loop(0, 7) std::cout << D_ARROW_RIGHT;
		}
};
