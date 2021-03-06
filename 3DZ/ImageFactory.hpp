/*
 *  ImageFactory.hpp
 *  3DZ
 *
 *  Created by David Holm on 2009-07-10.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TDZ_IMAGEFACTORY_HPP
#define TDZ_IMAGEFACTORY_HPP

#include <3DZ/Image.hpp>

namespace TDZ {
	
	class ImageFactory {
	public:
		static bool load(const std::string& path, Image::Pointer& outImage);
		
	private:
		ImageFactory() { }
	};
	
} // TDZ

#endif /* TDZ_IMAGEFACTORY_HPP */
