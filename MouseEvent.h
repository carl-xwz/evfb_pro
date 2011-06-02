/* Copyright (C) 
 * 2011 - Xu Wenzhang(xwz), carl.xwz@gmail.com, http://xuwenzhang.org
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */
/**
 * @file MouseEvent.h
 * @brief 鼠标事件类
 * @author Xu Wenzhang(xwz), carl.xwz@gmail.com, http://xuwenzhang.org
 * @version 1.0
 * @date 2011-06-02
 */
#include <stdio.h>
class MouseEvent
{
	public:
		MouseEvent ();
		~MouseEvent ();

		void input(int const x, int const y, bool const down);
	private:
		char mouseDate[11];
		int fd;

		MouseEvent ( const MouseEvent &other );
		MouseEvent& operator = ( const MouseEvent &other );
}; /* -----  end of class MouseEvent  ----- */
