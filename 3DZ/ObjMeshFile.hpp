/*
 *  ObjMeshFile.hpp
 *  3DZ
 *
 *  Created by David Holm on 2009-06-14.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TDZ_OBJMESHFILE_HPP
#define TDZ_OBJMESHFILE_HPP

#include <string>
#include <map>

#include <3DZ/Mesh.hpp>

/* The classes below are exported */
#pragma GCC visibility push(hidden)

namespace TDZ {
	
	class ObjMeshFile : public Mesh {
	public:
		ObjMeshFile();
		
		bool load(const std::string& path);
		
	private:
		bool loadVertex(const std::string& line);
		bool loadGroup(const std::string& line);
		bool loadFace(const std::string& line);
		
		struct SmoothingGroup {
			int m_id;
			FaceVec m_faces;
		};
		
		typedef std::map<int, SmoothingGroup> IdSmoothingGroupMap;
		struct Group {
			std::string m_name;
			int m_faces;
			
			IdSmoothingGroupMap m_smoothingGroups;
			int m_currentSmoothingGroupKey;
		};
		typedef std::map<std::string, Group> NameGroupMap;
		NameGroupMap m_groups;
	};
	
} // TDZ

#pragma GCC visibility pop
#endif /* TDZ_OBJMESHFILE_HPP */
