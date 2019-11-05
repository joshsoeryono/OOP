#include "Headers.h"

void loading()
{
	short load_percent=0;
	srand(time(NULL));
	
	while(load_percent<=100)
	{
		std::cout << "Loading... " << load_percent << " completed.";
		timer(0.07);
		load_percent+=rand()%5;
		cls();
	}
	std::cout << "Completed.";
	beep();
	timer(1);
	cls();
}

void recolor(Menu *&display, Rect_Out rect_out, Rect_In rect_in, Layout layout, Title title, SubTitle subtitle, Answer answer)
{
	display=&rect_out;
	display->draw();
	
	display=&rect_in;
	display->draw();
	
	display=&layout;
	display->draw();
	
	display=&title;
	display->draw();
	
	display=&subtitle;
	display->draw();
}

void display_help(Answer answer)
{
	cursor_position(7, 8); std::cout << "                                                                                        ";
	cursor_position(7, 8); std::cout << "> " << answer.get_answer();
	cursor_position(7, 9); std::cout << "Ketik end untuk mengganti mode ketik menjadi mode hotkeys.";
	cursor_position(7, 10); std::cout << "Klik tombol TAB pada keyboard (dalam mode hotkeys) untuk mengganti mode hotkeys menjadi mode ketik.";
	cursor_position(7, 11); std::cout << "Untuk mengganti warna desain tampilan, gunakan hotkeys 1 hingga 5 dalam mode hotkeys.";
	cursor_position(7, 12); std::cout << "Ketik exit untuk keluar dari program.";
}

int main()
{
	title("LOADING...");
	loading();
	
	title("Vacationpedia, Libur Tanpa Bingung");
	resize_window(70, 70, 700, 1222);
	set_color(240 | 0);
	cls();
	
	Menu *display;
	Rect_Out rect_out;
	Rect_In rect_in;
	Layout layout;
	Title title;
	SubTitle subtitle;
	
	Answer answer;
	std::string this_str; // simpan chat yang baru saja diketik pengguna dalam variabel ini.
	int temp_position;
	DWORD state; // variabel untuk menyimpan status pengetikan pada keyboard.
	
	Human human;
	
	recolor(display, rect_out, rect_in, layout, title, subtitle, answer);
	display_help(answer);
	temp_position=12+2;
	
	cursor_position(7, 29);
	std::getline(std::cin, this_str);
	do
	{
		human.set_content(this_str);
		
		cursor_position(7, 29);
		std::cout << "                                                                                        ";
		
		if(temp_position>=26)
		{
			display=&layout;
			display->draw();
			
			display_help(answer);
			temp_position=12+2;
		}
		
		if(human.get_content()=="wisata" || human.get_content()=="WISATA" || human.get_content()=="Wisata")
		{
			if(answer.get_state()==0)
			{
				cursor_position(7, temp_position+2);
					answer.set_state(1);
					std::cout << "> " << answer.get_answer();
				temp_position+=2;
			}
		}
		else if(human.get_content()=="batu" || human.get_content()=="BATU" || human.get_content()=="Batu")
		{
			if(answer.get_state()==1)
			{
				cursor_position(7, ++temp_position);
					answer.set_state(2);
					std::cout << "> " << answer.get_answer();
					answer.set_state(0);
			}
		}
		else if(human.get_content()=="malang" || human.get_content()=="MALANG" || human.get_content()=="Malang")
		{
			if(answer.get_state()==1)
			{
				cursor_position(7, ++temp_position);
					answer.set_state(3);
					std::cout << "> " << answer.get_answer();
					answer.set_state(0);
			}
		}
		else if(human.get_content()=="end" || human.get_content()=="END" || human.get_content()=="End")
		{
			enable_keypress(state);
			do
			{
				while
				(
					!KEY_TAB &&
					!KEY_ONE &&
					!KEY_TWO &&
					!KEY_THREE &&
					!KEY_FOUR &&
					!KEY_FIVE
				);
				
				if(KEY_TAB)
				{
					disable_keypress(state);
					break;
				}
				else if(KEY_ONE)
				{
					set_color(0 | 7);
					recolor(display, rect_out, rect_in, layout, title, subtitle, answer);
					display_help(answer);
					temp_position=12+2;
				}
				else if(KEY_TWO)
				{
					set_color(64 | 15);
					recolor(display, rect_out, rect_in, layout, title, subtitle, answer);
					display_help(answer);
					temp_position=12+2;
				}
				else if(KEY_THREE)
				{
					set_color(112 | 4);
					recolor(display, rect_out, rect_in, layout, title, subtitle, answer);
					display_help(answer);
					temp_position=12+2;
				}
				else if(KEY_FOUR)
				{
					set_color(240 | 0);
					recolor(display, rect_out, rect_in, layout, title, subtitle, answer);
					display_help(answer);
					temp_position=12+2;
				}
				else if(KEY_FIVE)
				{
					set_color(0 | 10);
					recolor(display, rect_out, rect_in, layout, title, subtitle, answer);
					display_help(answer);
					temp_position=12+2;
				}
			}
			while(1);
		}
		else if(human.get_content()=="exit" || human.get_content()=="EXIT" || human.get_content()=="Exit") break;
		else
		{
			cursor_position(7, ++temp_position);
			std::cout << "> " << "Maaf, terdapat kesalahan bot dalam memahami pesan anda. Ulangi kembali percakapan.";
			answer.set_state(0);
		}
		
		cursor_position(7, 29);
	}
	while(std::getline(std::cin, this_str));
	
	message("Terima kasih telah menggunakan Vacationpedia.\nKami berharap, kunjungan anda di Batu, Malang, dan sekitarnya menjadi sangat mudah dan menyenangkan.\nSelamat berwisata!", "LIBUR TANPA BINGUNG!");
	return EXIT_SUCCESS;
}
