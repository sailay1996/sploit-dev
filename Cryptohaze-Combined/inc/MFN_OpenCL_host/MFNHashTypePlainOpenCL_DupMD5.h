/*
Cryptohaze Multiforcer & Wordyforcer - low performance GPU password cracking
Copyright (C) 2011  Bitweasil (http://www.cryptohaze.com/)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef __MFNHASHTYPEPLAINOPENCL_DUPMD5_H
#define __MFNHASHTYPEPLAINOPENCL_DUPMD5_H

#include "MFN_OpenCL_host/MFNHashTypePlainOpenCL.h"

class MFNHashTypePlainOpenCL_DupMD5 : public MFNHashTypePlainOpenCL {

public:
    MFNHashTypePlainOpenCL_DupMD5();
protected:
    std::vector<uint8_t> preProcessHash(std::vector<uint8_t> rawHash);

    std::vector<uint8_t> postProcessHash(std::vector<uint8_t> processedHash);

    void copyConstantDataToDevice();

    void launchKernel();

    std::vector<std::string> getHashFileNames();
    std::string getKernelSourceString();
    std::string getHashKernelName();
    std::string getDefineStrings();

    /**
     * For DupMD5, the password is always doubled.  Therefore, the max found
     * plain length is always twice the generated password length.
     */
    void setMaxFoundPlainLength() {
        this->maxFoundPlainLength = this->passwordLength * 2;
    }
};

#endif
