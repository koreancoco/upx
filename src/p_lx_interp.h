/* p_lx_interp.h --

   This file is part of the UPX executable compressor.

   Copyright (C) 1996-2004 Markus Franz Xaver Johannes Oberhumer
   Copyright (C) 1996-2004 Laszlo Molnar
   Copyright (C) 2000-2004 John F. Reiser
   All Rights Reserved.

   UPX and the UCL library are free software; you can redistribute them
   and/or modify them under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.
   If not, write to the Free Software Foundation, Inc.,
   59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

   Markus F.X.J. Oberhumer   Laszlo Molnar           John F. Reiser
   markus@oberhumer.com      ml1050@cdata.tvnet.hu   jreiser@BitWagon.com
 */


#ifndef __UPX_P_LX_INTERP_H  //{
#define __UPX_P_LX_INTERP_H


/*************************************************************************
// linux/interp386
**************************************************************************/

class PackLinuxI386interp : public PackLinuxI386elf
{
    typedef PackLinuxI386elf super;
public:
    PackLinuxI386interp(InputFile *f);
    virtual ~PackLinuxI386interp();
    virtual int getVersion() const { return 13; }
    virtual int getFormat() const { return UPX_F_LINUX_ELFI_i386; }
    virtual const char *getName() const { return "linux/elfi386"; }

    virtual bool canPack();
    virtual void unpack(OutputFile *fo);

protected:
    virtual void pack1(OutputFile *, Filter &);  // generate executable header
    virtual void pack2(OutputFile *, Filter &);  // append compressed data
    virtual void pack3(OutputFile *, Filter &);  // build loader
};


#endif /*} already included */


/*
vi:ts=4:et
*/

