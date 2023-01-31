/* ------------------------------------------------------------
name: "RITI_AutonomousNetwork_fixedVersion"
Code generated with Faust 2.57.6 (https://faust.grame.fr)
Compilation options: -a /usr/local/share/faust/juce/juce-plugin.cpp -lang cpp -i -scn base_dsp -es 1 -mcd 16 -uim -double -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2016 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 
 ************************************************************************
 ************************************************************************/

#include <algorithm>
#include <assert.h>

#if JUCE_WINDOWS
#define JUCE_CORE_INCLUDE_NATIVE_HEADERS 1
#endif

#include "JuceLibraryCode/JuceHeader.h"

/************************** BEGIN MapUI.h ******************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ***********************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#include <vector>
#include <map>
#include <string>
#include <stdio.h>

/************************** BEGIN UI.h *****************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef __UI_H__
#define __UI_H__

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ***************************************************************************/

#ifndef __export__
#define __export__

#define FAUSTVERSION "2.57.6"

// Use FAUST_API for code that is part of the external API but is also compiled in faust and libfaust
// Use LIBFAUST_API for code that is compiled in faust and libfaust

#ifdef _WIN32
    #pragma warning (disable: 4251)
    #ifdef FAUST_EXE
        #define FAUST_API
        #define LIBFAUST_API
    #elif FAUST_LIB
        #define FAUST_API __declspec(dllexport)
        #define LIBFAUST_API __declspec(dllexport)
    #else
        #define FAUST_API
        #define LIBFAUST_API 
    #endif
#else
    #ifdef FAUST_EXE
        #define FAUST_API
        #define LIBFAUST_API
    #else
        #define FAUST_API __attribute__((visibility("default")))
        #define LIBFAUST_API __attribute__((visibility("default")))
    #endif
#endif

#endif

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust DSP User Interface
 * User Interface as expected by the buildUserInterface() method of a DSP.
 * This abstract class contains only the method that the Faust compiler can
 * generate to describe a DSP user interface.
 ******************************************************************************/

struct Soundfile;

template <typename REAL>
struct FAUST_API UIReal {
    
    UIReal() {}
    virtual ~UIReal() {}
    
    // -- widget's layouts
    
    virtual void openTabBox(const char* label) = 0;
    virtual void openHorizontalBox(const char* label) = 0;
    virtual void openVerticalBox(const char* label) = 0;
    virtual void closeBox() = 0;
    
    // -- active widgets
    
    virtual void addButton(const char* label, REAL* zone) = 0;
    virtual void addCheckButton(const char* label, REAL* zone) = 0;
    virtual void addVerticalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
    virtual void addHorizontalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
    virtual void addNumEntry(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
    
    // -- passive widgets
    
    virtual void addHorizontalBargraph(const char* label, REAL* zone, REAL min, REAL max) = 0;
    virtual void addVerticalBargraph(const char* label, REAL* zone, REAL min, REAL max) = 0;
    
    // -- soundfiles
    
    virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;
    
    // -- metadata declarations
    
    virtual void declare(REAL* /*zone*/, const char* /*key*/, const char* /*val*/) {}

    // To be used by LLVM client
    virtual int sizeOfFAUSTFLOAT() { return sizeof(FAUSTFLOAT); }
};

struct FAUST_API UI : public UIReal<FAUSTFLOAT> {
    UI() {}
    virtual ~UI() {}
};

#endif
/**************************  END  UI.h **************************/
/************************** BEGIN PathBuilder.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __PathBuilder__
#define __PathBuilder__

#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <regex>


/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class FAUST_API PathBuilder {

    protected:
    
        std::vector<std::string> fControlsLevel;
        std::vector<std::string> fFullPaths;
        std::map<std::string, std::string> fFull2Short;  // filled by computeShortNames()
    
        /**
         * @brief check if a character is acceptable for an ID
         *
         * @param c
         * @return true is the character is acceptable for an ID
         */
        bool isIDChar(char c) const
        {
            return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9'));
        }
    
        /**
         * @brief remove all "/0x00" parts
         *
         * @param src
         * @return modified string
         */
        std::string remove0x00(const std::string& src) const
        {
            return std::regex_replace(src, std::regex("/0x00"), "");
        }
    
        /**
         * @brief replace all non ID char with '_' (one '_' may replace several non ID char)
         *
         * @param src
         * @return modified string
         */
        std::string str2ID(const std::string& src) const
        {
            std::string dst;
            bool need_underscore = false;
            for (char c : src) {
                if (isIDChar(c) || (c == '/')) {
                    if (need_underscore) {
                        dst.push_back('_');
                        need_underscore = false;
                    }
                    dst.push_back(c);
                } else {
                    need_underscore = true;
                }
            }
            return dst;
        }
    
        /**
         * @brief Keep only the last n slash-parts
         *
         * @param src
         * @param n : 1 indicates the last slash-part
         * @return modified string
         */
        std::string cut(const std::string& src, int n) const
        {
            std::string rdst;
            for (int i = int(src.length())-1; i >= 0; i--) {
                char c = src[i];
                if (c != '/') {
                    rdst.push_back(c);
                } else if (n == 1) {
                    std::string dst;
                    for (int j = int(rdst.length())-1; j >= 0; j--) {
                        dst.push_back(rdst[j]);
                    }
                    return dst;
                } else {
                    n--;
                    rdst.push_back(c);
                }
            }
            return src;
        }
    
        void addFullPath(const std::string& label) { fFullPaths.push_back(buildPath(label)); }
    
        /**
         * @brief Compute the mapping between full path and short names
         */
        void computeShortNames()
        {
            std::vector<std::string>           uniquePaths;  // all full paths transformed but made unique with a prefix
            std::map<std::string, std::string> unique2full;  // all full paths transformed but made unique with a prefix
            int pnum = 0;
            for (const auto& s : fFullPaths) {
                std::string u = "/P" + std::to_string(pnum++) + str2ID(remove0x00(s));
                uniquePaths.push_back(u);
                unique2full[u] = s;  // remember the full path associated to a unique path
            }
        
            std::map<std::string, int> uniquePath2level;                // map path to level
            for (const auto& s : uniquePaths) uniquePath2level[s] = 1;   // we init all levels to 1
            bool have_collisions = true;
        
            while (have_collisions) {
                // compute collision list
                std::set<std::string>              collisionSet;
                std::map<std::string, std::string> short2full;
                have_collisions = false;
                for (const auto& it : uniquePath2level) {
                    std::string u = it.first;
                    int n = it.second;
                    std::string shortName = cut(u, n);
                    auto p = short2full.find(shortName);
                    if (p == short2full.end()) {
                        // no collision
                        short2full[shortName] = u;
                    } else {
                        // we have a collision, add the two paths to the collision set
                        have_collisions = true;
                        collisionSet.insert(u);
                        collisionSet.insert(p->second);
                    }
                }
                for (const auto& s : collisionSet) uniquePath2level[s]++;  // increase level of colliding path
            }
        
            for (const auto& it : uniquePath2level) {
                std::string u = it.first;
                int n = it.second;
                std::string shortName = replaceCharList(cut(u, n), {'/'}, '_');
                fFull2Short[unique2full[u]] = shortName;
            }
        }
    
        std::string replaceCharList(const std::string& str, const std::vector<char>& ch1, char ch2)
        {
            auto beg = ch1.begin();
            auto end = ch1.end();
            std::string res = str;
            for (size_t i = 0; i < str.length(); ++i) {
                if (std::find(beg, end, str[i]) != end) res[i] = ch2;
            }
            return res;
        }
     
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        // Return true for the first level of groups
        bool pushLabel(const std::string& label) { fControlsLevel.push_back(label); return fControlsLevel.size() == 1;}
    
        // Return true for the last level of groups
        bool popLabel() { fControlsLevel.pop_back(); return fControlsLevel.size() == 0; }
    
        std::string buildPath(const std::string& label)
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res = res + fControlsLevel[i] + "/";
            }
            res += label;
            return replaceCharList(res, {' ', '#', '*', ',', '?', '[', ']', '{', '}', '(', ')'}, '_');
        }
    
};

#endif  // __PathBuilder__
/**************************  END  PathBuilder.h **************************/

/*******************************************************************************
 * MapUI : Faust User Interface.
 *
 * This class creates:
 * - a map of 'labels' and zones for each UI item.
 * - a map of unique 'shortname' (built so that they never collide) and zones for each UI item
 * - a map of complete hierarchical 'paths' and zones for each UI item
 *
 * Simple 'labels', 'shortname' and complete 'paths' (to fully discriminate between possible same
 * 'labels' at different location in the UI hierachy) can be used to access a given parameter.
 ******************************************************************************/

class FAUST_API MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
        // Shortname zone map
        std::map<std::string, FAUSTFLOAT*> fShortnameZoneMap;
    
        // Full path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        void addZoneLabel(const std::string& label, FAUSTFLOAT* zone)
        {
            std::string path = buildPath(label);
            fFullPaths.push_back(path);
            fPathZoneMap[path] = zone;
            fLabelZoneMap[label] = zone;
        }
    
    public:
        
        MapUI() {}
        virtual ~MapUI() {}
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            pushLabel(label);
        }
        void openHorizontalBox(const char* label)
        {
            pushLabel(label);
        }
        void openVerticalBox(const char* label)
        {
            pushLabel(label);
        }
        void closeBox()
        {
            if (popLabel()) {
                // Shortnames can be computed when all fullnames are known
                computeShortNames();
                // Fill 'shortname' map
                for (const auto& it : fFullPaths) {
                    fShortnameZoneMap[fFull2Short[it]] = fPathZoneMap[it];
                }
            }
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addZoneLabel(label, zone);
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addZoneLabel(label, zone);
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            addZoneLabel(label, zone);
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            addZoneLabel(label, zone);
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            addZoneLabel(label, zone);
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            addZoneLabel(label, zone);
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            addZoneLabel(label, zone);
        }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
        
        // -- metadata declarations
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
    
        //-------------------------------------------------------------------------------
        // Public API
        //-------------------------------------------------------------------------------
    
        /**
         * Set the param value.
         *
         * @param str - the UI parameter label/shortname/path
         * @param value - the UI parameter value
         *
         */
        void setParamValue(const std::string& str, FAUSTFLOAT value)
        {
            if (fPathZoneMap.find(str) != fPathZoneMap.end()) {
                *fPathZoneMap[str] = value;
            } else if (fShortnameZoneMap.find(str) != fShortnameZoneMap.end()) {
                *fShortnameZoneMap[str] = value;
            } else if (fLabelZoneMap.find(str) != fLabelZoneMap.end()) {
                *fLabelZoneMap[str] = value;
            } else {
                fprintf(stderr, "ERROR : setParamValue '%s' not found\n", str.c_str());
            }
        }
        
        /**
         * Return the param value.
         *
         * @param str - the UI parameter label/shortname/path
         *
         * @return the param value.
         */
        FAUSTFLOAT getParamValue(const std::string& str)
        {
            if (fPathZoneMap.find(str) != fPathZoneMap.end()) {
                return *fPathZoneMap[str];
            } else if (fShortnameZoneMap.find(str) != fShortnameZoneMap.end()) {
                return *fShortnameZoneMap[str];
            } else if (fLabelZoneMap.find(str) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[str];
            } else {
                fprintf(stderr, "ERROR : getParamValue '%s' not found\n", str.c_str());
                return 0;
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getFullpathMap() { return fPathZoneMap; }
        std::map<std::string, FAUSTFLOAT*>& getShortnameMap() { return fShortnameZoneMap; }
        std::map<std::string, FAUSTFLOAT*>& getLabelMap() { return fLabelZoneMap; }
            
        /**
         * Return the number of parameters in the UI.
         *
         * @return the number of parameters
         */
        int getParamsCount() { return int(fPathZoneMap.size()); }
        
        /**
         * Return the param path.
         *
         * @param index - the UI parameter index
         *
         * @return the param path
         */
        std::string getParamAddress(int index)
        {
            if (index < 0 || index > int(fPathZoneMap.size())) {
                return "";
            } else {
                auto it = fPathZoneMap.begin();
                while (index-- > 0 && it++ != fPathZoneMap.end()) {}
                return it->first;
            }
        }
        
        const char* getParamAddress1(int index)
        {
            if (index < 0 || index > int(fPathZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fPathZoneMap.begin();
                while (index-- > 0 && it++ != fPathZoneMap.end()) {}
                return it->first.c_str();
            }
        }
    
        /**
         * Return the param shortname.
         *
         * @param index - the UI parameter index
         *
         * @return the param shortname
         */
        std::string getParamShortname(int index)
        {
            if (index < 0 || index > int(fShortnameZoneMap.size())) {
                return "";
            } else {
                auto it = fShortnameZoneMap.begin();
                while (index-- > 0 && it++ != fShortnameZoneMap.end()) {}
                return it->first;
            }
        }
        
        const char* getParamShortname1(int index)
        {
            if (index < 0 || index > int(fShortnameZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fShortnameZoneMap.begin();
                while (index-- > 0 && it++ != fShortnameZoneMap.end()) {}
                return it->first.c_str();
            }
        }
    
        /**
         * Return the param label.
         *
         * @param index - the UI parameter index
         *
         * @return the param label
         */
        std::string getParamLabel(int index)
        {
            if (index < 0 || index > int(fLabelZoneMap.size())) {
                return "";
            } else {
                auto it = fLabelZoneMap.begin();
                while (index-- > 0 && it++ != fLabelZoneMap.end()) {}
                return it->first;
            }
        }
        
        const char* getParamLabel1(int index)
        {
            if (index < 0 || index > int(fLabelZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fLabelZoneMap.begin();
                while (index-- > 0 && it++ != fLabelZoneMap.end()) {}
                return it->first.c_str();
            }
        }
    
        /**
         * Return the param path.
         *
         * @param zone - the UI parameter memory zone
         *
         * @return the param path
         */
        std::string getParamAddress(FAUSTFLOAT* zone)
        {
            for (const auto& it : fPathZoneMap) {
                if (it.second == zone) return it.first;
            }
            return "";
        }
    
        /**
         * Return the param memory zone.
         *
         * @param zone - the UI parameter label/shortname/path
         *
         * @return the param path
         */
        FAUSTFLOAT* getParamZone(const std::string& str)
        {
            if (fPathZoneMap.find(str) != fPathZoneMap.end()) {
                return fPathZoneMap[str];
            } else if (fShortnameZoneMap.find(str) != fShortnameZoneMap.end()) {
                return fShortnameZoneMap[str];
            } else if (fLabelZoneMap.find(str) != fLabelZoneMap.end()) {
                return fLabelZoneMap[str];
            }
            return nullptr;
        }
    
        /**
         * Return the param memory zone.
         *
         * @param zone - the UI parameter index
         *
         * @return the param path
         */
        FAUSTFLOAT* getParamZone(int index)
        {
            if (index < 0 || index > int(fPathZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fPathZoneMap.begin();
                while (index-- > 0 && it++ != fPathZoneMap.end()) {}
                return it->second;
            }
        }
    
        static bool endsWith(const std::string& str, const std::string& end)
        {
            size_t l1 = str.length();
            size_t l2 = end.length();
            return (l1 >= l2) && (0 == str.compare(l1 - l2, l2, end));
        }
    
};

#endif // FAUST_MAPUI_H
/**************************  END  MapUI.h **************************/
/************************** BEGIN base_dsp-adapter.h *************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp_adapter__
#define __dsp_adapter__

#ifndef _WIN32
#include <alloca.h>
#endif
#include <string.h>
#include <cmath>
#include <assert.h>
#include <stdio.h>

/************************** BEGIN base_dsp.h ********************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp__
#define __dsp__

#include <string>
#include <vector>


#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

struct FAUST_API UI;
struct FAUST_API Meta;

/**
 * DSP memory manager.
 */

struct FAUST_API dsp_memory_manager {
    
    virtual ~dsp_memory_manager() {}
    
    /**
     * Inform the Memory Manager with the number of expected memory zones.
     * @param count - the number of expected memory zones
     */
    virtual void begin(size_t /*count*/) {}
    
    /**
     * Give the Memory Manager information on a given memory zone.
     * @param size - the size in bytes of the memory zone
     * @param reads - the number of Read access to the zone used to compute one frame
     * @param writes - the number of Write access to the zone used to compute one frame
     */
    virtual void info(size_t /*size*/, size_t /*reads*/, size_t /*writes*/) {}

    /**
     * Inform the Memory Manager that all memory zones have been described,
     * to possibly start a 'compute the best allocation strategy' step.
     */
    virtual void end() {}
    
    /**
     * Allocate a memory zone.
     * @param size - the memory zone size in bytes
     */
    virtual void* allocate(size_t size) = 0;
    
    /**
     * Destroy a memory zone.
     * @param ptr - the memory zone pointer to be deallocated
     */
    virtual void destroy(void* ptr) = 0;
    
};

/**
* Signal processor definition.
*/

class FAUST_API base_dsp {

    public:

        base_dsp() {}
        virtual ~base_dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the ui_interface parameter with instance specific calls
         * to 'openTabBox', 'addButton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Return the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /**
         * Global init, calls the following methods:
         * - static class 'classInit': static tables initialization
         * - 'instanceInit': constants and instance state initialization
         *
         * @param sample_rate - the sampling rate in Hz
         */
        virtual void init(int sample_rate) = 0;

        /**
         * Init instance state
         *
         * @param sample_rate - the sampling rate in Hz
         */
        virtual void instanceInit(int sample_rate) = 0;
    
        /**
         * Init instance constant state
         *
         * @param sample_rate - the sampling rate in Hz
         */
        virtual void instanceConstants(int sample_rate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (like delay lines...) but keep the control parameter values */
        virtual void instanceClear() = 0;
 
        /**
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual base_dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value) metadata.
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with successive in/out audio buffers.
         *
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation: alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (either float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (either float, double or quad)
         *
         */
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class FAUST_API decorator_dsp : public base_dsp {

    protected:

        base_dsp* fDSP;

    public:

        decorator_dsp(base_dsp* base_dsp = nullptr):fDSP(base_dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int sample_rate) { fDSP->init(sample_rate); }
        virtual void instanceInit(int sample_rate) { fDSP->instanceInit(sample_rate); }
        virtual void instanceConstants(int sample_rate) { fDSP->instanceConstants(sample_rate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { fDSP->metadata(m); }
        // Beware: subclasses usually have to overload the two 'compute' methods
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
    
};

/**
 * DSP factory class, used with LLVM and Interpreter backends
 * to create DSP instances from a compiled DSP program.
 */

class FAUST_API dsp_factory {
    
    protected:
    
        // So that to force sub-classes to use deleteDSPFactory(dsp_factory* factory);
        virtual ~dsp_factory() {}
    
    public:
    
        virtual std::string getName() = 0;
        virtual std::string getSHAKey() = 0;
        virtual std::string getDSPCode() = 0;
        virtual std::string getCompileOptions() = 0;
        virtual std::vector<std::string> getLibraryList() = 0;
        virtual std::vector<std::string> getIncludePathnames() = 0;
        virtual std::vector<std::string> getWarningMessages() = 0;
    
        virtual base_dsp* createDSPInstance() = 0;
    
        virtual void setMemoryManager(dsp_memory_manager* manager) = 0;
        virtual dsp_memory_manager* getMemoryManager() = 0;
    
};

// Denormal handling

#if defined (__SSE__)
#include <xmmintrin.h>
#endif

class FAUST_API ScopedNoDenormals {
    
    private:
    
        intptr_t fpsr = 0;
        
        void setFpStatusRegister(intptr_t fpsr_aux) noexcept
        {
        #if defined (__arm64__) || defined (__aarch64__)
            asm volatile("msr fpcr, %0" : : "ri" (fpsr_aux));
        #elif defined (__SSE__)
            // The volatile keyword here is needed to workaround a bug in AppleClang 13.0
            // which aggressively optimises away the variable otherwise
            volatile uint32_t fpsr_w = static_cast<uint32_t>(fpsr_aux);
            _mm_setcsr(fpsr_w);
        #endif
        }
        
        void getFpStatusRegister() noexcept
        {
        #if defined (__arm64__) || defined (__aarch64__)
            asm volatile("mrs %0, fpcr" : "=r" (fpsr));
        #elif defined (__SSE__)
            fpsr = static_cast<intptr_t>(_mm_getcsr());
        #endif
        }
    
    public:
    
        ScopedNoDenormals() noexcept
        {
        #if defined (__arm64__) || defined (__aarch64__)
            intptr_t mask = (1 << 24 /* FZ */);
        #elif defined (__SSE__)
        #if defined (__SSE2__)
            intptr_t mask = 0x8040;
        #else
            intptr_t mask = 0x8000;
        #endif
        #else
            intptr_t mask = 0x0000;
        #endif
            getFpStatusRegister();
            setFpStatusRegister(fpsr | mask);
        }
        
        ~ScopedNoDenormals() noexcept
        {
            setFpStatusRegister(fpsr);
        }

};

#define AVOIDDENORMALS ScopedNoDenormals ftz_scope;

#endif

/************************** END base_dsp.h **************************/

// Adapts a DSP for a different number of inputs/outputs
class dsp_adapter : public decorator_dsp {
    
    private:
    
        FAUSTFLOAT** fAdaptedInputs;
        FAUSTFLOAT** fAdaptedOutputs;
        int fHWInputs;
        int fHWOutputs;
        int fBufferSize;
    
        void adaptBuffers(FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            for (int i = 0; i < fHWInputs; i++) {
                fAdaptedInputs[i] = inputs[i];
            }
            for (int i = 0; i < fHWOutputs; i++) {
                fAdaptedOutputs[i] = outputs[i];
            }
        }
    
    public:
    
        dsp_adapter(base_dsp* base_dsp, int hw_inputs, int hw_outputs, int buffer_size):decorator_dsp(base_dsp)
        {
            fHWInputs = hw_inputs;
            fHWOutputs = hw_outputs;
            fBufferSize = buffer_size;
            
            fAdaptedInputs = new FAUSTFLOAT*[base_dsp->getNumInputs()];
            for (int i = 0; i < base_dsp->getNumInputs() - fHWInputs; i++) {
                fAdaptedInputs[i + fHWInputs] = new FAUSTFLOAT[buffer_size];
                memset(fAdaptedInputs[i + fHWInputs], 0, sizeof(FAUSTFLOAT) * buffer_size);
            }
            
            fAdaptedOutputs = new FAUSTFLOAT*[base_dsp->getNumOutputs()];
            for (int i = 0; i < base_dsp->getNumOutputs() - fHWOutputs; i++) {
                fAdaptedOutputs[i + fHWOutputs] = new FAUSTFLOAT[buffer_size];
                memset(fAdaptedOutputs[i + fHWOutputs], 0, sizeof(FAUSTFLOAT) * buffer_size);
            }
        }
    
        virtual ~dsp_adapter()
        {
            for (int i = 0; i < fDSP->getNumInputs() - fHWInputs; i++) {
                delete [] fAdaptedInputs[i + fHWInputs];
            }
            delete [] fAdaptedInputs;
            
            for (int i = 0; i < fDSP->getNumOutputs() - fHWOutputs; i++) {
                delete [] fAdaptedOutputs[i + fHWOutputs];
            }
            delete [] fAdaptedOutputs;
        }
    
        virtual int getNumInputs() { return fHWInputs; }
        virtual int getNumOutputs() { return fHWOutputs; }
    
        virtual dsp_adapter* clone() { return new dsp_adapter(fDSP->clone(), fHWInputs, fHWOutputs, fBufferSize); }
    
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            adaptBuffers(inputs, outputs);
            fDSP->compute(date_usec, count, fAdaptedInputs, fAdaptedOutputs);
        }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            adaptBuffers(inputs, outputs);
            fDSP->compute(count, fAdaptedInputs, fAdaptedOutputs);
        }
};

// Adapts a DSP for a different sample size
template <typename REAL_INT, typename REAL_EXT>
class dsp_sample_adapter : public decorator_dsp {
    
    private:
    
        REAL_INT** fAdaptedInputs;
        REAL_INT** fAdaptedOutputs;
    
        void adaptInputBuffers(int count, FAUSTFLOAT** inputs)
        {
            for (int chan = 0; chan < fDSP->getNumInputs(); chan++) {
                for (int frame = 0; frame < count; frame++) {
                    fAdaptedInputs[chan][frame] = REAL_INT(reinterpret_cast<REAL_EXT**>(inputs)[chan][frame]);
                }
            }
        }
    
        void adaptOutputsBuffers(int count, FAUSTFLOAT** outputs)
        {
            for (int chan = 0; chan < fDSP->getNumOutputs(); chan++) {
                for (int frame = 0; frame < count; frame++) {
                    reinterpret_cast<REAL_EXT**>(outputs)[chan][frame] = REAL_EXT(fAdaptedOutputs[chan][frame]);
                }
            }
        }
    
    public:
    
        dsp_sample_adapter(base_dsp* base_dsp):decorator_dsp(base_dsp)
        {
            fAdaptedInputs = new REAL_INT*[base_dsp->getNumInputs()];
            for (int i = 0; i < base_dsp->getNumInputs(); i++) {
                fAdaptedInputs[i] = new REAL_INT[4096];
            }
            
            fAdaptedOutputs = new REAL_INT*[base_dsp->getNumOutputs()];
            for (int i = 0; i < base_dsp->getNumOutputs(); i++) {
                fAdaptedOutputs[i] = new REAL_INT[4096];
            }
        }
    
        virtual ~dsp_sample_adapter()
        {
            for (int i = 0; i < fDSP->getNumInputs(); i++) {
                delete [] fAdaptedInputs[i];
            }
            delete [] fAdaptedInputs;
            
            for (int i = 0; i < fDSP->getNumOutputs(); i++) {
                delete [] fAdaptedOutputs[i];
            }
            delete [] fAdaptedOutputs;
        }
    
        virtual dsp_sample_adapter* clone() { return new dsp_sample_adapter(fDSP->clone()); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            assert(count <= 4096);
            adaptInputBuffers(count, inputs);
            // DSP base class uses FAUSTFLOAT** type, so reinterpret_cast has to be used even if the real DSP uses REAL_INT
            fDSP->compute(count, reinterpret_cast<FAUSTFLOAT**>(fAdaptedInputs), reinterpret_cast<FAUSTFLOAT**>(fAdaptedOutputs));
            adaptOutputsBuffers(count, outputs);
        }
    
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            assert(count <= 4096);
            adaptInputBuffers(count, inputs);
            // DSP base class uses FAUSTFLOAT** type, so reinterpret_cast has to be used even if the real DSP uses REAL_INT
            fDSP->compute(date_usec, count, reinterpret_cast<FAUSTFLOAT**>(fAdaptedInputs), reinterpret_cast<FAUSTFLOAT**>(fAdaptedOutputs));
            adaptOutputsBuffers(count, outputs);
        }
};

// Template used to specialize double parameters expressed as NUM/DENOM
template <int NUM, int DENOM>
struct Double {
    static constexpr double value() { return double(NUM)/double(DENOM); }
};

// Base class for filters
template <class fVslider0, int fVslider1>
struct Filter {
    inline int getFactor() { return fVslider1; }
};

// Identity filter: copy input to output
template <class fVslider0, int fVslider1>
struct Identity : public Filter<fVslider0, fVslider1> {
    inline int getFactor() { return fVslider1; }
    
    inline void compute(int count, FAUSTFLOAT* input0, FAUSTFLOAT* output0)
    {
        memcpy(output0, input0, count * sizeof(FAUSTFLOAT));
    }
};

// Generated with process = fi.lowpass(3, ma.SR*hslider("FCFactor", 0.4, 0.4, 0.5, 0.01)/hslider("Factor", 2, 2, 8, 1));
template <class fVslider0, int fVslider1, typename REAL>
struct LowPass3 : public Filter<fVslider0, fVslider1> {
    
    REAL fVec0[2];
    REAL fRec1[2];
    REAL fRec0[3];
    
    inline REAL LowPass3_faustpower2_f(REAL value)
    {
        return (value * value);
    }
    
    LowPass3()
    {
        for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
            fVec0[l0] = 0.0;
        }
        for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
            fRec1[l1] = 0.0;
        }
        for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
            fRec0[l2] = 0.0;
        }
    }
    
    inline void compute(int count, FAUSTFLOAT* input0, FAUSTFLOAT* output0)
    {
        // Computed at template specialization time
        REAL fSlow0 = std::tan((3.1415926535897931 * (REAL(fVslider0::value()) / REAL(fVslider1))));
        REAL fSlow1 = (1.0 / fSlow0);
        REAL fSlow2 = (1.0 / (((fSlow1 + 1.0000000000000002) / fSlow0) + 1.0));
        REAL fSlow3 = (1.0 / (fSlow1 + 1.0));
        REAL fSlow4 = (1.0 - fSlow1);
        REAL fSlow5 = (((fSlow1 + -1.0000000000000002) / fSlow0) + 1.0);
        REAL fSlow6 = (2.0 * (1.0 - (1.0 / LowPass3_faustpower2_f(fSlow0))));
        // Computed at runtime
        for (int i = 0; (i < count); i = (i + 1)) {
            REAL fTemp0 = REAL(input0[i]);
            fVec0[0] = fTemp0;
            fRec1[0] = (0.0 - (fSlow3 * ((fSlow4 * fRec1[1]) - (fTemp0 + fVec0[1]))));
            fRec0[0] = (fRec1[0] - (fSlow2 * ((fSlow5 * fRec0[2]) + (fSlow6 * fRec0[1]))));
            output0[i] = FAUSTFLOAT((fSlow2 * (fRec0[2] + (fRec0[0] + (2.0 * fRec0[1])))));
            fVec0[1] = fVec0[0];
            fRec1[1] = fRec1[0];
            fRec0[2] = fRec0[1];
            fRec0[1] = fRec0[0];
        }
    }
};

// Generated with process = fi.lowpass(4, ma.SR*hslider("FCFactor", 0.4, 0.4, 0.5, 0.01)/hslider("Factor", 2, 2, 8, 1));
template <class fVslider0, int fVslider1, typename REAL>
struct LowPass4 : public Filter<fVslider0, fVslider1> {
    
    REAL fRec1[3];
    REAL fRec0[3];
    
    inline REAL LowPass4_faustpower2_f(REAL value)
    {
        return (value * value);
    }
    
    LowPass4()
    {
        for (int l0 = 0; (l0 < 3); l0 = (l0 + 1)) {
            fRec1[l0] = 0.0f;
        }
        for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
            fRec0[l1] = 0.0f;
        }
    }
    
    inline void compute(int count, FAUSTFLOAT* input0, FAUSTFLOAT* output0)
    {
        // Computed at template specialization time
        REAL fSlow0 = std::tan((3.1415926535897931 * (REAL(fVslider0::value()) / REAL(fVslider1))));
        REAL fSlow1 = (1.0 / fSlow0);
        REAL fSlow2 = (1.0 / (((fSlow1 + 0.76536686473017945) / fSlow0) + 1.0));
        REAL fSlow3 = (1.0 / (((fSlow1 + 1.8477590650225735) / fSlow0) + 1.0));
        REAL fSlow4 = (((fSlow1 + -1.8477590650225735) / fSlow0) + 1.0);
        REAL fSlow5 = (2.0 * (1.0 - (1.0 / LowPass4_faustpower2_f(fSlow0))));
        REAL fSlow6 = (((fSlow1 + -0.76536686473017945) / fSlow0) + 1.0);
        // Computed at runtime
        for (int i = 0; (i < count); i = (i + 1)) {
            fRec1[0] = (REAL(input0[i]) - (fSlow3 * ((fSlow4 * fRec1[2]) + (fSlow5 * fRec1[1]))));
            fRec0[0] = ((fSlow3 * (fRec1[2] + (fRec1[0] + (2.0 * fRec1[1])))) - (fSlow2 * ((fSlow6 * fRec0[2]) + (fSlow5 * fRec0[1]))));
            output0[i] = FAUSTFLOAT((fSlow2 * (fRec0[2] + (fRec0[0] + (2.0 * fRec0[1])))));
            fRec1[2] = fRec1[1];
            fRec1[1] = fRec1[0];
            fRec0[2] = fRec0[1];
            fRec0[1] = fRec0[0];
        }
    }
};

// Generated with process = fi.lowpass3e(ma.SR*hslider("FCFactor", 0.4, 0.4, 0.5, 0.01)/hslider("Factor", 2, 2, 8, 1));
template <class fVslider0, int fVslider1, typename REAL>
struct LowPass3e : public Filter<fVslider0, fVslider1> {
    
    REAL fRec1[3];
    REAL fVec0[2];
    REAL fRec0[2];
    
    inline REAL LowPass3e_faustpower2_f(REAL value)
    {
        return (value * value);
    }
    
    LowPass3e()
    {
        for (int l0 = 0; (l0 < 3); l0 = (l0 + 1)) {
            fRec1[l0] = 0.0;
        }
        for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
            fVec0[l1] = 0.0;
        }
        for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
            fRec0[l2] = 0.0;
        }
    }
    
    inline void compute(int count, FAUSTFLOAT* input0, FAUSTFLOAT* output0)
    {
        // Computed at template specialization time
        REAL fSlow0 = std::tan((3.1415926535897931 * (REAL(fVslider0::value()) / REAL(fVslider1))));
        REAL fSlow1 = (1.0 / fSlow0);
        REAL fSlow2 = (1.0 / (fSlow1 + 0.82244590899881598));
        REAL fSlow3 = (0.82244590899881598 - fSlow1);
        REAL fSlow4 = (1.0 / (((fSlow1 + 0.80263676416103003) / fSlow0) + 1.4122708937742039));
        REAL fSlow5 = LowPass3e_faustpower2_f(fSlow0);
        REAL fSlow6 = (0.019809144837788999 / fSlow5);
        REAL fSlow7 = (fSlow6 + 1.1615164189826961);
        REAL fSlow8 = (((fSlow1 + -0.80263676416103003) / fSlow0) + 1.4122708937742039);
        REAL fSlow9 = (2.0 * (1.4122708937742039 - (1.0 / fSlow5)));
        REAL fSlow10 = (2.0 * (1.1615164189826961 - fSlow6));
        // Computed at runtime
        for (int i = 0; (i < count); i = (i + 1)) {
            fRec1[0] = (REAL(input0[i]) - (fSlow4 * ((fSlow8 * fRec1[2]) + (fSlow9 * fRec1[1]))));
            REAL fTemp0 = (fSlow4 * (((fSlow7 * fRec1[0]) + (fSlow10 * fRec1[1])) + (fSlow7 * fRec1[2])));
            fVec0[0] = fTemp0;
            fRec0[0] = (0.0 - (fSlow2 * ((fSlow3 * fRec0[1]) - (fTemp0 + fVec0[1]))));
            output0[i] = FAUSTFLOAT(fRec0[0]);
            fRec1[2] = fRec1[1];
            fRec1[1] = fRec1[0];
            fVec0[1] = fVec0[0];
            fRec0[1] = fRec0[0];
        }
    }
};

// Generated with process = fi.lowpass6e(ma.SR*hslider("FCFactor", 0.4, 0.4, 0.5, 0.01)/hslider("Factor", 2, 2, 8, 1));
template <class fVslider0, int fVslider1, typename REAL>
struct LowPass6e : public Filter<fVslider0, fVslider1> {
    
    REAL fRec2[3];
    REAL fRec1[3];
    REAL fRec0[3];
    
    inline REAL LowPass6e_faustpower2_f(REAL value)
    {
        return (value * value);
    }
    
    LowPass6e()
    {
        for (int l0 = 0; (l0 < 3); l0 = (l0 + 1)) {
            fRec2[l0] = 0.0;
        }
        for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
            fRec1[l1] = 0.0;
        }
        for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
            fRec0[l2] = 0.0;
        }
    }
    
    inline void compute(int count, FAUSTFLOAT* input0, FAUSTFLOAT* output0)
    {
        // Computed at template specialization time
        REAL fSlow0 = std::tan((3.1415926535897931 * (REAL(fVslider0::value()) / REAL(fVslider1))));
        REAL fSlow1 = (1.0 / fSlow0);
        REAL fSlow2 = (1.0 / (((fSlow1 + 0.16840487111358901) / fSlow0) + 1.0693584077073119));
        REAL fSlow3 = LowPass6e_faustpower2_f(fSlow0);
        REAL fSlow4 = (1.0 / fSlow3);
        REAL fSlow5 = (fSlow4 + 53.536152954556727);
        REAL fSlow6 = (1.0 / (((fSlow1 + 0.51247864188914105) / fSlow0) + 0.68962136448467504));
        REAL fSlow7 = (fSlow4 + 7.6217312988706034);
        REAL fSlow8 = (1.0 / (((fSlow1 + 0.78241304682164503) / fSlow0) + 0.24529150870616001));
        REAL fSlow9 = (9.9999997054999994e-05 / fSlow3);
        REAL fSlow10 = (fSlow9 + 0.00043322720055500002);
        REAL fSlow11 = (((fSlow1 + -0.78241304682164503) / fSlow0) + 0.24529150870616001);
        REAL fSlow12 = (2.0 * (0.24529150870616001 - fSlow4));
        REAL fSlow13 = (2.0 * (0.00043322720055500002 - fSlow9));
        REAL fSlow14 = (((fSlow1 + -0.51247864188914105) / fSlow0) + 0.68962136448467504);
        REAL fSlow15 = (2.0 * (0.68962136448467504 - fSlow4));
        REAL fSlow16 = (2.0 * (7.6217312988706034 - fSlow4));
        REAL fSlow17 = (((fSlow1 + -0.16840487111358901) / fSlow0) + 1.0693584077073119);
        REAL fSlow18 = (2.0 * (1.0693584077073119 - fSlow4));
        REAL fSlow19 = (2.0 * (53.536152954556727 - fSlow4));
        // Computed at runtime
        for (int i = 0; (i < count); i = (i + 1)) {
            fRec2[0] = (REAL(input0[i]) - (fSlow8 * ((fSlow11 * fRec2[2]) + (fSlow12 * fRec2[1]))));
            fRec1[0] = ((fSlow8 * (((fSlow10 * fRec2[0]) + (fSlow13 * fRec2[1])) + (fSlow10 * fRec2[2]))) - (fSlow6 * ((fSlow14 * fRec1[2]) + (fSlow15 * fRec1[1]))));
            fRec0[0] = ((fSlow6 * (((fSlow7 * fRec1[0]) + (fSlow16 * fRec1[1])) + (fSlow7 * fRec1[2]))) - (fSlow2 * ((fSlow17 * fRec0[2]) + (fSlow18 * fRec0[1]))));
            output0[i] = FAUSTFLOAT((fSlow2 * (((fSlow5 * fRec0[0]) + (fSlow19 * fRec0[1])) + (fSlow5 * fRec0[2]))));
            fRec2[2] = fRec2[1];
            fRec2[1] = fRec2[0];
            fRec1[2] = fRec1[1];
            fRec1[1] = fRec1[0];
            fRec0[2] = fRec0[1];
            fRec0[1] = fRec0[0];
        }
    }
};

// A "si.bus(N)" like hard-coded class
struct dsp_bus : public base_dsp {
    
    int fChannels;
    int fSampleRate;
    
    dsp_bus(int channels):fChannels(channels), fSampleRate(-1)
    {}
    
    virtual int getNumInputs() { return fChannels; }
    virtual int getNumOutputs() { return fChannels; }
    
    virtual int getSampleRate() { return fSampleRate; }
    
    virtual void buildUserInterface(UI* ui_interface) {}
    virtual void init(int sample_rate)
    {
        //classInit(sample_rate);
        instanceInit(sample_rate);
    }
    
    virtual void instanceInit(int sample_rate)
    {
        fSampleRate = sample_rate;
        instanceConstants(sample_rate);
        instanceResetUserInterface();
        instanceClear();
    }
    
    virtual void instanceConstants(int sample_rate) {}
    virtual void instanceResetUserInterface() {}
    virtual void instanceClear() {}
    
    virtual base_dsp* clone() { return new dsp_bus(fChannels); }
    
    virtual void metadata(Meta* m) {}
    
    virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        for (int chan = 0; chan < fChannels; chan++) {
            memcpy(outputs[chan], inputs[chan], sizeof(FAUSTFLOAT) * count);
        }
    }
    
    virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        compute(count, inputs, outputs);
    }
    
};

// Base class for sample-rate adapter
template <typename FILTER>
class sr_sampler : public decorator_dsp {
    
    protected:
    
        std::vector<FILTER> fInputLowPass;
        std::vector<FILTER> fOutputLowPass;
    
        inline int getFactor() { return this->fOutputLowPass[0].getFactor(); }
    
    public:
    
        sr_sampler(base_dsp* base_dsp):decorator_dsp(base_dsp)
        {
            for (int chan = 0; chan < fDSP->getNumInputs(); chan++) {
                fInputLowPass.push_back(FILTER());
            }
            for (int chan = 0; chan < fDSP->getNumOutputs(); chan++) {
                fOutputLowPass.push_back(FILTER());
            }
        }
};

// Down sample-rate adapter
template <typename FILTER>
class dsp_down_sampler : public sr_sampler<FILTER> {
    
    public:
    
        dsp_down_sampler(base_dsp* base_dsp):sr_sampler<FILTER>(base_dsp)
        {}
    
        virtual void init(int sample_rate)
        {
            this->fDSP->init(sample_rate / this->getFactor());
        }
    
        virtual void instanceInit(int sample_rate)
        {
            this->fDSP->instanceInit(sample_rate / this->getFactor());
        }
    
        virtual void instanceConstants(int sample_rate)
        {
            this->fDSP->instanceConstants(sample_rate / this->getFactor());
        }
    
        virtual dsp_down_sampler* clone() { return new dsp_down_sampler(decorator_dsp::clone()); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            int real_count = count / this->getFactor();
            
            // Adapt inputs
            FAUSTFLOAT** fInputs = (FAUSTFLOAT**)alloca(this->fDSP->getNumInputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < this->fDSP->getNumInputs(); chan++) {
                // Lowpass filtering in place on 'inputs'
                this->fInputLowPass[chan].compute(count, inputs[chan], inputs[chan]);
                // Allocate fInputs with 'real_count' frames
                fInputs[chan] = (FAUSTFLOAT*)alloca(sizeof(FAUSTFLOAT) * real_count);
                // Decimate
                for (int frame = 0; frame < real_count; frame++) {
                    fInputs[chan][frame] = inputs[chan][frame * this->getFactor()];
                }
            }
            
            // Allocate fOutputs with 'real_count' frames
            FAUSTFLOAT** fOutputs = (FAUSTFLOAT**)alloca(this->fDSP->getNumOutputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < this->fDSP->getNumOutputs(); chan++) {
                fOutputs[chan] = (FAUSTFLOAT*)alloca(sizeof(FAUSTFLOAT) * real_count);
            }
            
            // Compute at lower rate
            this->fDSP->compute(real_count, fInputs, fOutputs);
            
            // Adapt outputs
            for (int chan = 0; chan < this->fDSP->getNumOutputs(); chan++) {
                // Puts zeros
                memset(outputs[chan], 0, sizeof(FAUSTFLOAT) * count);
                for (int frame = 0; frame < real_count; frame++) {
                    // Copy one sample every 'DownFactor'
                    // Apply volume
                    //outputs[chan][frame * this->getFactor()] = fOutputs[chan][frame] * this->getFactor();
                    outputs[chan][frame * this->getFactor()] = fOutputs[chan][frame];
                }
                // Lowpass filtering in place on 'outputs'
                this->fOutputLowPass[chan].compute(count, outputs[chan], outputs[chan]);
            }
        }
    
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

// Up sample-rate adapter
template <typename FILTER>
class dsp_up_sampler : public sr_sampler<FILTER> {
    
    public:
    
        dsp_up_sampler(base_dsp* base_dsp):sr_sampler<FILTER>(base_dsp)
        {}
    
        virtual void init(int sample_rate)
        {
            this->fDSP->init(sample_rate * this->getFactor());
        }
    
        virtual void instanceInit(int sample_rate)
        {
            this->fDSP->instanceInit(sample_rate * this->getFactor());
        }
    
        virtual void instanceConstants(int sample_rate)
        {
            this->fDSP->instanceConstants(sample_rate * this->getFactor());
        }
    
        virtual dsp_up_sampler* clone() { return new dsp_up_sampler(decorator_dsp::clone()); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            int real_count = count * this->getFactor();
            
            // Adapt inputs
            FAUSTFLOAT** fInputs = (FAUSTFLOAT**)alloca(this->fDSP->getNumInputs() * sizeof(FAUSTFLOAT*));
            
            for (int chan = 0; chan < this->fDSP->getNumInputs(); chan++) {
                // Allocate fInputs with 'real_count' frames
                fInputs[chan] = (FAUSTFLOAT*)alloca(sizeof(FAUSTFLOAT) * real_count);
                // Puts zeros
                memset(fInputs[chan], 0, sizeof(FAUSTFLOAT) * real_count);
                for (int frame = 0; frame < count; frame++) {
                    // Copy one sample every 'UpFactor'
                    fInputs[chan][frame * this->getFactor()] = inputs[chan][frame];
                }
                // Lowpass filtering in place on 'fInputs'
                this->fInputLowPass[chan].compute(real_count, fInputs[chan], fInputs[chan]);
            }
            
            // Allocate fOutputs with 'real_count' frames
            FAUSTFLOAT** fOutputs = (FAUSTFLOAT**)alloca(this->fDSP->getNumOutputs() * sizeof(FAUSTFLOAT*));
            
            for (int chan = 0; chan < this->fDSP->getNumOutputs(); chan++) {
                fOutputs[chan] = (FAUSTFLOAT*)alloca(sizeof(FAUSTFLOAT) * real_count);
            }
            
            // Compute at upper rate
            this->fDSP->compute(real_count, fInputs, fOutputs);
            
            // Adapt outputs
            for (int chan = 0; chan < this->fDSP->getNumOutputs(); chan++) {
                // Lowpass filtering in place on 'fOutputs'
                this->fOutputLowPass[chan].compute(real_count, fOutputs[chan], fOutputs[chan]);
                // Decimate
                for (int frame = 0; frame < count; frame++) {
                    // Apply volume
                    //outputs[chan][frame] = fOutputs[chan][frame * this->getFactor()] * this->getFactor();
                    outputs[chan][frame] = fOutputs[chan][frame * this->getFactor()];
                }
            }
        }
    
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

// Create a UP/DS + Filter adapted DSP
template <typename REAL>
base_dsp* createSRAdapter(base_dsp* DSP, int ds = 0, int us = 0, int filter = 0)
{
    if (ds > 0) {
        switch (filter) {
            case 0:
                if (ds == 2) {
                    return new dsp_down_sampler<Identity<Double<1,1>, 2>>(DSP);
                } else if (ds == 3) {
                    return new dsp_down_sampler<Identity<Double<1,1>, 3>>(DSP);
                } else if (ds == 4) {
                    return new dsp_down_sampler<Identity<Double<1,1>, 4>>(DSP);
                } else if (ds == 8) {
                    return new dsp_down_sampler<Identity<Double<1,1>, 8>>(DSP);
                } else if (ds == 16) {
                    return new dsp_down_sampler<Identity<Double<1,1>, 16>>(DSP);
                } else if (ds == 32) {
                    return new dsp_down_sampler<Identity<Double<1,1>, 32>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : ds factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 1:
                if (ds == 2) {
                    return new dsp_down_sampler<LowPass3<Double<45,100>, 2, REAL>>(DSP);
                } else if (ds == 3) {
                    return new dsp_down_sampler<LowPass3<Double<45,100>, 3, REAL>>(DSP);
                } else if (ds == 4) {
                    return new dsp_down_sampler<LowPass3<Double<45,100>, 4, REAL>>(DSP);
                } else if (ds == 8) {
                    return new dsp_down_sampler<LowPass3<Double<45,100>, 8, REAL>>(DSP);
                } else if (ds == 16) {
                    return new dsp_down_sampler<LowPass3<Double<45,100>, 16, REAL>>(DSP);
                } else if (ds == 32) {
                    return new dsp_down_sampler<LowPass3<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : ds factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 2:
                if (ds == 2) {
                    return new dsp_down_sampler<LowPass4<Double<45,100>, 2, REAL>>(DSP);
                } else if (ds == 3) {
                    return new dsp_down_sampler<LowPass4<Double<45,100>, 3, REAL>>(DSP);
                } else if (ds == 4) {
                    return new dsp_down_sampler<LowPass4<Double<45,100>, 4, REAL>>(DSP);
                } else if (ds == 8) {
                    return new dsp_down_sampler<LowPass4<Double<45,100>, 8, REAL>>(DSP);
                } else if (ds == 16) {
                    return new dsp_down_sampler<LowPass4<Double<45,100>, 16, REAL>>(DSP);
                } else if (ds == 32) {
                    return new dsp_down_sampler<LowPass4<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : ds factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 3:
                if (ds == 2) {
                    return new dsp_down_sampler<LowPass3e<Double<45,100>, 2, REAL>>(DSP);
                } else if (ds == 3) {
                    return new dsp_down_sampler<LowPass3e<Double<45,100>, 3, REAL>>(DSP);
                } else if (ds == 4) {
                    return new dsp_down_sampler<LowPass3e<Double<45,100>, 4, REAL>>(DSP);
                } else if (ds == 8) {
                    return new dsp_down_sampler<LowPass3e<Double<45,100>, 8, REAL>>(DSP);
                } else if (ds == 16) {
                    return new dsp_down_sampler<LowPass3e<Double<45,100>, 16, REAL>>(DSP);
                } else if (ds == 32) {
                    return new dsp_down_sampler<LowPass3e<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : ds factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 4:
                if (ds == 2) {
                    return new dsp_down_sampler<LowPass6e<Double<45,100>, 2, REAL>>(DSP);
                } else if (ds == 3) {
                    return new dsp_down_sampler<LowPass6e<Double<45,100>, 3, REAL>>(DSP);
                } else if (ds == 4) {
                    return new dsp_down_sampler<LowPass6e<Double<45,100>, 4, REAL>>(DSP);
                } else if (ds == 8) {
                    return new dsp_down_sampler<LowPass6e<Double<45,100>, 8, REAL>>(DSP);
                } else if (ds == 16) {
                    return new dsp_down_sampler<LowPass6e<Double<45,100>, 16, REAL>>(DSP);
                } else if (ds == 32) {
                    return new dsp_down_sampler<LowPass6e<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : ds factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            default:
                fprintf(stderr, "ERROR : filter type must be in [0..4] range\n");
                assert(false);
                return nullptr;
        }
    } else if (us > 0) {
        
        switch (filter) {
            case 0:
                if (us == 2) {
                    return new dsp_up_sampler<Identity<Double<1,1>, 2>>(DSP);
                } else if (us == 3) {
                    return new dsp_up_sampler<Identity<Double<1,1>, 3>>(DSP);
                } else if (us == 4) {
                    return new dsp_up_sampler<Identity<Double<1,1>, 4>>(DSP);
                } else if (us == 8) {
                    return new dsp_up_sampler<Identity<Double<1,1>, 8>>(DSP);
                } else if (us == 16) {
                    return new dsp_up_sampler<Identity<Double<1,1>, 16>>(DSP);
                } else if (us == 32) {
                    return new dsp_up_sampler<Identity<Double<1,1>, 32>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : us factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 1:
                if (us == 2) {
                    return new dsp_up_sampler<LowPass3<Double<45,100>, 2, REAL>>(DSP);
                } else if (us == 3) {
                    return new dsp_up_sampler<LowPass3<Double<45,100>, 3, REAL>>(DSP);
                } else if (us == 4) {
                    return new dsp_up_sampler<LowPass3<Double<45,100>, 4, REAL>>(DSP);
                } else if (us == 8) {
                    return new dsp_up_sampler<LowPass3<Double<45,100>, 8, REAL>>(DSP);
                } else if (us == 16) {
                    return new dsp_up_sampler<LowPass3<Double<45,100>, 16, REAL>>(DSP);
                } else if (us == 32) {
                    return new dsp_up_sampler<LowPass3<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : us factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 2:
                if (us == 2) {
                    return new dsp_up_sampler<LowPass4<Double<45,100>, 2, REAL>>(DSP);
                } else if (us == 3) {
                    return new dsp_up_sampler<LowPass4<Double<45,100>, 3, REAL>>(DSP);
                } else if (us == 4) {
                    return new dsp_up_sampler<LowPass4<Double<45,100>, 4, REAL>>(DSP);
                } else if (us == 8) {
                    return new dsp_up_sampler<LowPass4<Double<45,100>, 8, REAL>>(DSP);
                } else if (us == 16) {
                    return new dsp_up_sampler<LowPass4<Double<45,100>, 16, REAL>>(DSP);
                } else if (us == 32) {
                    return new dsp_up_sampler<LowPass4<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : us factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 3:
                if (us == 2) {
                    return new dsp_up_sampler<LowPass3e<Double<45,100>, 2, REAL>>(DSP);
                } else if (us == 3) {
                    return new dsp_up_sampler<LowPass3e<Double<45,100>, 3, REAL>>(DSP);
                } else if (us == 4) {
                    return new dsp_up_sampler<LowPass3e<Double<45,100>, 4, REAL>>(DSP);
                } else if (us == 8) {
                    return new dsp_up_sampler<LowPass3e<Double<45,100>, 8, REAL>>(DSP);
                } else if (us == 16) {
                    return new dsp_up_sampler<LowPass3e<Double<45,100>, 16, REAL>>(DSP);
                } else if (us == 32) {
                    return new dsp_up_sampler<LowPass3e<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : us factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 4:
                if (us == 2) {
                    return new dsp_up_sampler<LowPass6e<Double<45,100>, 2, REAL>>(DSP);
                } else if (us == 3) {
                    return new dsp_up_sampler<LowPass6e<Double<45,100>, 3, REAL>>(DSP);
                } else if (us == 4) {
                    return new dsp_up_sampler<LowPass6e<Double<45,100>, 4, REAL>>(DSP);
                } else if (us == 8) {
                    return new dsp_up_sampler<LowPass6e<Double<45,100>, 8, REAL>>(DSP);
                } else if (us == 16) {
                    return new dsp_up_sampler<LowPass6e<Double<45,100>, 16, REAL>>(DSP);
                } else if (us == 32) {
                    return new dsp_up_sampler<LowPass6e<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : us factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            default:
                fprintf(stderr, "ERROR : filter type must be in [0..4] range\n");
                assert(false);
                return nullptr;
        }
    } else {
        return DSP;
    }
}
    
#endif
/************************** END base_dsp-adapter.h **************************/
/************************** BEGIN MidiUI.h ****************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
************************************************************************/

#ifndef FAUST_MIDIUI_H
#define FAUST_MIDIUI_H

#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <cmath>

/************************** BEGIN meta.h *******************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __meta__
#define __meta__


/**
 The base class of Meta handler to be used in base_dsp::metadata(Meta* m) method to retrieve (key, value) metadata.
 */
struct FAUST_API Meta {
    virtual ~Meta() {}
    virtual void declare(const char* key, const char* value) = 0;
};

#endif
/**************************  END  meta.h **************************/
/************************** BEGIN GUI.h **********************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 *************************************************************************/

#ifndef __GUI_H__
#define __GUI_H__

#include <list>
#include <map>
#include <vector>
#include <assert.h>

#ifdef _WIN32
# pragma warning (disable: 4100)
#else
# pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

/************************** BEGIN ValueConverter.h ********************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef __ValueConverter__
#define __ValueConverter__

/***************************************************************************************
 ValueConverter.h
 (GRAME, Copyright 2015-2019)
 
 Set of conversion objects used to map user interface values (for example a gui slider
 delivering values between 0 and 1) to faust values (for example a vslider between
 20 and 20000) using a log scale.
 
 -- Utilities
 
 Range(lo,hi) : clip a value x between lo and hi
 Interpolator(lo,hi,v1,v2) : Maps a value x between lo and hi to a value y between v1 and v2
 Interpolator3pt(lo,mi,hi,v1,vm,v2) : Map values between lo mid hi to values between v1 vm v2
 
 -- Value Converters
 
 ValueConverter::ui2faust(x)
 ValueConverter::faust2ui(x)
 
 -- ValueConverters used for sliders depending of the scale
 
 LinearValueConverter(umin, umax, fmin, fmax)
 LinearValueConverter2(lo, mi, hi, v1, vm, v2) using 2 segments
 LogValueConverter(umin, umax, fmin, fmax)
 ExpValueConverter(umin, umax, fmin, fmax)
 
 -- ValueConverters used for accelerometers based on 3 points
 
 AccUpConverter(amin, amid, amax, fmin, fmid, fmax)        -- curve 0
 AccDownConverter(amin, amid, amax, fmin, fmid, fmax)      -- curve 1
 AccUpDownConverter(amin, amid, amax, fmin, fmid, fmax)    -- curve 2
 AccDownUpConverter(amin, amid, amax, fmin, fmid, fmax)    -- curve 3
 
 -- lists of ZoneControl are used to implement accelerometers metadata for each axes
 
 ZoneControl(zone, valueConverter) : a zone with an accelerometer data converter
 
 -- ZoneReader are used to implement screencolor metadata
 
 ZoneReader(zone, valueConverter) : a zone with a data converter

****************************************************************************************/

#include <float.h>
#include <algorithm>    // std::max
#include <cmath>
#include <vector>
#include <assert.h>


//--------------------------------------------------------------------------------------
// Interpolator(lo,hi,v1,v2)
// Maps a value x between lo and hi to a value y between v1 and v2
// y = v1 + (x-lo)/(hi-lo)*(v2-v1)
// y = v1 + (x-lo) * coef           with coef = (v2-v1)/(hi-lo)
// y = v1 + x*coef - lo*coef
// y = v1 - lo*coef + x*coef
// y = offset + x*coef              with offset = v1 - lo*coef
//--------------------------------------------------------------------------------------
class FAUST_API Interpolator {
    
    private:

        //--------------------------------------------------------------------------------------
        // Range(lo,hi) clip a value between lo and hi
        //--------------------------------------------------------------------------------------
        struct Range
        {
            double fLo;
            double fHi;

            Range(double x, double y) : fLo(std::min<double>(x,y)), fHi(std::max<double>(x,y)) {}
            double operator()(double x) { return (x<fLo) ? fLo : (x>fHi) ? fHi : x; }
        };


        Range fRange;
        double fCoef;
        double fOffset;

    public:

        Interpolator(double lo, double hi, double v1, double v2) : fRange(lo,hi)
        {
            if (hi != lo) {
                // regular case
                fCoef = (v2-v1)/(hi-lo);
                fOffset = v1 - lo*fCoef;
            } else {
                // degenerate case, avoids division by zero
                fCoef = 0;
                fOffset = (v1+v2)/2;
            }
        }
        double operator()(double v)
        {
            double x = fRange(v);
            return  fOffset + x*fCoef;
        }

        void getLowHigh(double& amin, double& amax)
        {
            amin = fRange.fLo;
            amax = fRange.fHi;
        }
};

//--------------------------------------------------------------------------------------
// Interpolator3pt(lo,mi,hi,v1,vm,v2)
// Map values between lo mid hi to values between v1 vm v2
//--------------------------------------------------------------------------------------
class FAUST_API Interpolator3pt {

    private:

        Interpolator fSegment1;
        Interpolator fSegment2;
        double fMid;

    public:

        Interpolator3pt(double lo, double mi, double hi, double v1, double vm, double v2) :
            fSegment1(lo, mi, v1, vm),
            fSegment2(mi, hi, vm, v2),
            fMid(mi) {}
        double operator()(double x) { return  (x < fMid) ? fSegment1(x) : fSegment2(x); }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fSegment1.getLowHigh(amin, amid);
            fSegment2.getLowHigh(amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Abstract ValueConverter class. Converts values between UI and Faust representations
//--------------------------------------------------------------------------------------
class FAUST_API ValueConverter {

    public:

        virtual ~ValueConverter() {}
        virtual double ui2faust(double x) { return x; };
        virtual double faust2ui(double x) { return x; };
};

//--------------------------------------------------------------------------------------
// A converter than can be updated
//--------------------------------------------------------------------------------------

class FAUST_API UpdatableValueConverter : public ValueConverter {
    
    protected:
        
        bool fActive;
        
    public:
        
        UpdatableValueConverter():fActive(true)
        {}
        virtual ~UpdatableValueConverter()
        {}
        
        virtual void setMappingValues(double amin, double amid, double amax, double min, double init, double max) = 0;
        virtual void getMappingValues(double& amin, double& amid, double& amax) = 0;
        
        void setActive(bool on_off) { fActive = on_off; }
        bool getActive() { return fActive; }
    
};

//--------------------------------------------------------------------------------------
// Linear conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class FAUST_API LinearValueConverter : public ValueConverter {
    
    private:
        
        Interpolator fUI2F;
        Interpolator fF2UI;
        
    public:
        
        LinearValueConverter(double umin, double umax, double fmin, double fmax) :
            fUI2F(umin,umax,fmin,fmax), fF2UI(fmin,fmax,umin,umax)
        {}
        
        LinearValueConverter() : fUI2F(0.,0.,0.,0.), fF2UI(0.,0.,0.,0.)
        {}
        virtual double ui2faust(double x) { return fUI2F(x); }
        virtual double faust2ui(double x) { return fF2UI(x); }
    
};

//--------------------------------------------------------------------------------------
// Two segments linear conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class FAUST_API LinearValueConverter2 : public UpdatableValueConverter {
    
    private:
    
        Interpolator3pt fUI2F;
        Interpolator3pt fF2UI;
        
    public:
    
        LinearValueConverter2(double amin, double amid, double amax, double min, double init, double max) :
            fUI2F(amin, amid, amax, min, init, max), fF2UI(min, init, max, amin, amid, amax)
        {}
        
        LinearValueConverter2() : fUI2F(0.,0.,0.,0.,0.,0.), fF2UI(0.,0.,0.,0.,0.,0.)
        {}
    
        virtual double ui2faust(double x) { return fUI2F(x); }
        virtual double faust2ui(double x) { return fF2UI(x); }
    
        virtual void setMappingValues(double amin, double amid, double amax, double min, double init, double max)
        {
            fUI2F = Interpolator3pt(amin, amid, amax, min, init, max);
            fF2UI = Interpolator3pt(min, init, max, amin, amid, amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fUI2F.getMappingValues(amin, amid, amax);
        }
    
};

//--------------------------------------------------------------------------------------
// Logarithmic conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class FAUST_API LogValueConverter : public LinearValueConverter {

    public:

        LogValueConverter(double umin, double umax, double fmin, double fmax) :
            LinearValueConverter(umin, umax, std::log(std::max<double>(DBL_MIN, fmin)), std::log(std::max<double>(DBL_MIN, fmax)))
        {}

        virtual double ui2faust(double x) { return std::exp(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x) { return LinearValueConverter::faust2ui(std::log(std::max<double>(x, DBL_MIN))); }

};

//--------------------------------------------------------------------------------------
// Exponential conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class FAUST_API ExpValueConverter : public LinearValueConverter {

    public:

        ExpValueConverter(double umin, double umax, double fmin, double fmax) :
            LinearValueConverter(umin, umax, std::min<double>(DBL_MAX, std::exp(fmin)), std::min<double>(DBL_MAX, std::exp(fmax)))
        {}

        virtual double ui2faust(double x) { return std::log(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x) { return LinearValueConverter::faust2ui(std::min<double>(DBL_MAX, std::exp(x))); }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up curve (curve 0)
//--------------------------------------------------------------------------------------
class FAUST_API AccUpConverter : public UpdatableValueConverter {

    private:

        Interpolator3pt fA2F;
        Interpolator3pt fF2A;

    public:

        AccUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmid,fmax),
            fF2A(fmin,fmid,fmax,amin,amid,amax)
        {}

        virtual double ui2faust(double x) { return fA2F(x); }
        virtual double faust2ui(double x) { return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin, amid, amax, fmin, fmid, fmax);
            fF2A = Interpolator3pt(fmin, fmid, fmax, amin, amid, amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down curve (curve 1)
//--------------------------------------------------------------------------------------
class FAUST_API AccDownConverter : public UpdatableValueConverter {

    private:

        Interpolator3pt	fA2F;
        Interpolator3pt	fF2A;

    public:

        AccDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmid,fmin),
            fF2A(fmin,fmid,fmax,amax,amid,amin)
        {}

        virtual double ui2faust(double x) { return fA2F(x); }
        virtual double faust2ui(double x) { return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin, amid, amax, fmax, fmid, fmin);
            fF2A = Interpolator3pt(fmin, fmid, fmax, amax, amid, amin);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up-Down curve (curve 2)
//--------------------------------------------------------------------------------------
class FAUST_API AccUpDownConverter : public UpdatableValueConverter {

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccUpDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmax,fmin),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotonic function
        {}

        virtual double ui2faust(double x) { return fA2F(x); }
        virtual double faust2ui(double x) { return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin, amid, amax, fmin, fmax, fmin);
            fF2A = Interpolator(fmin, fmax, amin, amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down-Up curve (curve 3)
//--------------------------------------------------------------------------------------
class FAUST_API AccDownUpConverter : public UpdatableValueConverter {

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccDownUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmin,fmax),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotonic function
        {}

        virtual double ui2faust(double x) { return fA2F(x); }
        virtual double faust2ui(double x) { return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin, amid, amax, fmax, fmin, fmax);
            fF2A = Interpolator(fmin, fmax, amin, amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Base class for ZoneControl
//--------------------------------------------------------------------------------------
class FAUST_API ZoneControl {

    protected:

        FAUSTFLOAT*	fZone;

    public:

        ZoneControl(FAUSTFLOAT* zone) : fZone(zone) {}
        virtual ~ZoneControl() {}

        virtual void update(double v) const {}

        virtual void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max) {}
        virtual void getMappingValues(double& amin, double& amid, double& amax) {}

        FAUSTFLOAT* getZone() { return fZone; }

        virtual void setActive(bool on_off) {}
        virtual bool getActive() { return false; }

        virtual int getCurve() { return -1; }

};

//--------------------------------------------------------------------------------------
//  Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class FAUST_API ConverterZoneControl : public ZoneControl {

    protected:

        ValueConverter* fValueConverter;

    public:

        ConverterZoneControl(FAUSTFLOAT* zone, ValueConverter* converter) : ZoneControl(zone), fValueConverter(converter) {}
        virtual ~ConverterZoneControl() { delete fValueConverter; } // Assuming fValueConverter is not kept elsewhere...

        virtual void update(double v) const { *fZone = FAUSTFLOAT(fValueConverter->ui2faust(v)); }

        ValueConverter* getConverter() { return fValueConverter; }

};

//--------------------------------------------------------------------------------------
// Association of a zone and a four value converter, each one for each possible curve.
// Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class FAUST_API CurveZoneControl : public ZoneControl {

    private:

        std::vector<UpdatableValueConverter*> fValueConverters;
        int fCurve;

    public:

        CurveZoneControl(FAUSTFLOAT* zone, int curve, double amin, double amid, double amax, double min, double init, double max) : ZoneControl(zone), fCurve(0)
        {
            assert(curve >= 0 && curve <= 3);
            fValueConverters.push_back(new AccUpConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccUpDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownUpConverter(amin, amid, amax, min, init, max));
            fCurve = curve;
        }
        virtual ~CurveZoneControl()
        {
            for (const auto& it : fValueConverters) { delete it; }
        }
        void update(double v) const { if (fValueConverters[fCurve]->getActive()) *fZone = FAUSTFLOAT(fValueConverters[fCurve]->ui2faust(v)); }

        void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max)
        {
            fValueConverters[curve]->setMappingValues(amin, amid, amax, min, init, max);
            fCurve = curve;
        }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fValueConverters[fCurve]->getMappingValues(amin, amid, amax);
        }

        void setActive(bool on_off)
        {
            for (const auto& it : fValueConverters) { it->setActive(on_off); }
        }

        int getCurve() { return fCurve; }
};

class FAUST_API ZoneReader {

    private:

        FAUSTFLOAT* fZone;
        Interpolator fInterpolator;

    public:

        ZoneReader(FAUSTFLOAT* zone, double lo, double hi) : fZone(zone), fInterpolator(lo, hi, 0, 255) {}

        virtual ~ZoneReader() {}

        int getValue()
        {
            return (fZone != nullptr) ? int(fInterpolator(*fZone)) : 127;
        }

};

#endif
/**************************  END  ValueConverter.h **************************/
/************************** BEGIN MetaDataUI.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef MetaData_UI_H
#define MetaData_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <map>
#include <set>
#include <string>
#include <string.h>
#include <assert.h>
#include <stdio.h> // We use the lighter fprintf code

/************************** BEGIN SimpleParser.h *********************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef SIMPLEPARSER_H
#define SIMPLEPARSER_H

// ---------------------------------------------------------------------
//                          Simple Parser
// A parser returns true if it was able to parse what it is
// supposed to parse and advance the pointer. Otherwise it returns false
// and the pointer is not advanced so that another parser can be tried.
// ---------------------------------------------------------------------

#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
#include <stdio.h> // We use the lighter fprintf code
#include <ctype.h>
#include <assert.h>

#ifndef _WIN32
# pragma GCC diagnostic ignored "-Wunused-function"
#endif

struct itemInfo {
    std::string type;
    std::string label;
    std::string shortname;
    std::string address;
    std::string url;
    int index;
    double init;
    double fmin;
    double fmax;
    double step;
    std::vector<std::pair<std::string, std::string> > meta;
    
    itemInfo():index(0), init(0.), fmin(0.), fmax(0.), step(0.)
    {}
};

// ---------------------------------------------------------------------
//                          Elementary parsers
// ---------------------------------------------------------------------

// Report a parsing error
static bool parseError(const char*& p, const char* errmsg)
{
    fprintf(stderr, "Parse error : %s here : %s\n", errmsg, p);
    return true;
}

/**
 * @brief skipBlank : advance pointer p to the first non blank character
 * @param p the string to parse, then the remaining string
 */
static void skipBlank(const char*& p)
{
    while (isspace(*p)) { p++; }
}

// Parse character x, but don't report error if fails
static bool tryChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief parseChar : parse a specific character x
 * @param p the string to parse, then the remaining string
 * @param x the character to recognize
 * @return true if x was found at the begin of p
 */
static bool parseChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief parseWord : parse a specific string w
 * @param p the string to parse, then the remaining string
 * @param w the string to recognize
 * @return true if string w was found at the begin of p
 */
static bool parseWord(const char*& p, const char* w)
{
    skipBlank(p);
    const char* saved = p;  // to restore position if we fail
    while ((*w == *p) && (*w)) {++w; ++p;}
    if (*w) {
        p = saved;
        return false;
    } else {
        return true;
    }
}

/**
 * @brief parseDouble : parse number [s]dddd[.dddd] or [s]d[.dddd][E|e][s][dddd] and store the result in x
 * @param p the string to parse, then the remaining string
 * @param x the float number found if any
 * @return true if a float number was found at the begin of p
 */
static bool parseDouble(const char*& p, double& x)
{
    double sign = 1.0;     // sign of the number
    double ipart = 0;      // integral part of the number
    double dpart = 0;      // decimal part of the number before division
    double dcoef = 1.0;    // division factor for the decimal part
    double expsign = 1.0;  // sign of the E|e part
    double expcoef = 0.0;  // multiplication factor of E|e part
    
    bool valid = false;    // true if the number contains at least one digit
    
    skipBlank(p);
    const char* saved = p;  // to restore position if we fail
    
    // Sign
    if (parseChar(p, '+')) {
        sign = 1.0;
    } else if (parseChar(p, '-')) {
        sign = -1.0;
    }
    
    // Integral part
    while (isdigit(*p)) {
        valid = true;
        ipart = ipart*10 + (*p - '0');
        p++;
    }
    
    // Possible decimal part
    if (parseChar(p, '.')) {
        while (isdigit(*p)) {
            valid = true;
            dpart = dpart*10 + (*p - '0');
            dcoef *= 10.0;
            p++;
        }
    }
    
    // Possible E|e part
    if (parseChar(p, 'E') || parseChar(p, 'e')) {
        if (parseChar(p, '+')) {
            expsign = 1.0;
        } else if (parseChar(p, '-')) {
            expsign = -1.0;
        }
        while (isdigit(*p)) {
            expcoef = expcoef*10 + (*p - '0');
            p++;
        }
    }
    
    if (valid)  {
        x = (sign*(ipart + dpart/dcoef)) * std::pow(10.0, expcoef*expsign);
    } else {
        p = saved;
    }
    return valid;
}

/**
 * @brief parseString, parse an arbitrary quoted string q...q and store the result in s
 * @param p the string to parse, then the remaining string
 * @param quote the character used to quote the string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseString(const char*& p, char quote, std::string& s)
{
    std::string str;
    skipBlank(p);
    
    const char* saved = p;  // to restore position if we fail
    if (*p++ == quote) {
        while ((*p != 0) && (*p != quote)) {
            str += *p++;
        }
        if (*p++ == quote) {
            s = str;
            return true;
        }
    }
    p = saved;
    return false;
}

/**
 * @brief parseSQString, parse a single quoted string '...' and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseSQString(const char*& p, std::string& s)
{
    return parseString(p, '\'', s);
}

/**
 * @brief parseDQString, parse a double quoted string "..." and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseDQString(const char*& p, std::string& s)
{
    return parseString(p, '"', s);
}

// ---------------------------------------------------------------------
//
//                          IMPLEMENTATION
// 
// ---------------------------------------------------------------------

/**
 * @brief parseMenuItem, parse a menu item ...'low':440.0...
 * @param p the string to parse, then the remaining string
 * @param name the name found
 * @param value the value found
 * @return true if a nemu item was found
 */
static bool parseMenuItem(const char*& p, std::string& name, double& value)
{
    const char* saved = p;  // to restore position if we fail
    if (parseSQString(p, name) && parseChar(p, ':') && parseDouble(p, value)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

static bool parseMenuItem2(const char*& p, std::string& name)
{
    const char* saved = p;  // to restore position if we fail
    // single quoted
    if (parseSQString(p, name)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

/**
 * @brief parseMenuList, parse a menu list {'low' : 440.0; 'mid' : 880.0; 'hi' : 1760.0}...
 * @param p the string to parse, then the remaining string
 * @param names the vector of names found
 * @param values the vector of values found
 * @return true if a menu list was found
 */
static bool parseMenuList(const char*& p, std::vector<std::string>& names, std::vector<double>& values)
{
    std::vector<std::string> tmpnames;
    std::vector<double> tmpvalues;
    const char* saved = p; // to restore position if we fail

    if (parseChar(p, '{')) {
        do {
            std::string n;
            double v;
            if (parseMenuItem(p, n, v)) {
                tmpnames.push_back(n);
                tmpvalues.push_back(v);
            } else {
                p = saved;
                return false;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            values = tmpvalues;
            return true;
        }
    }
    p = saved;
    return false;
}

static bool parseMenuList2(const char*& p, std::vector<std::string>& names, bool debug)
{
    std::vector<std::string> tmpnames;
    const char* saved = p;  // to restore position if we fail
    
    if (parseChar(p, '{')) {
        do {
            std::string n;
            if (parseMenuItem2(p, n)) {
                tmpnames.push_back(n);
            } else {
                goto error;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            return true;
        }
    }
    
error:
    if (debug) { fprintf(stderr, "parseMenuList2 : (%s) is not a valid list !\n", p); }
    p = saved;
    return false;
}

/// ---------------------------------------------------------------------
// Parse list of strings
/// ---------------------------------------------------------------------
static bool parseList(const char*& p, std::vector<std::string>& items)
{
    const char* saved = p;  // to restore position if we fail
    if (parseChar(p, '[')) {
        do {
            std::string item;
            if (!parseDQString(p, item)) {
                p = saved;
                return false;
            }
            items.push_back(item);
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        p = saved;
        return false;
    }
}

static bool parseMetaData(const char*& p, std::map<std::string, std::string>& metadatas)
{
    const char* saved = p; // to restore position if we fail
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas[metaKey] = metaValue;
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        p = saved;
        return false;
    }
}

static bool parseItemMetaData(const char*& p, std::vector<std::pair<std::string, std::string> >& metadatas)
{
    const char* saved = p; // to restore position if we fail
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas.push_back(std::make_pair(metaKey, metaValue));
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        p = saved;
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse metadatas of the interface:
// "name" : "...", "inputs" : "...", "outputs" : "...", ...
// and store the result as key/value
/// ---------------------------------------------------------------------
static bool parseGlobalMetaData(const char*& p, std::string& key, std::string& value, double& dbl, std::map<std::string, std::string>& metadatas, std::vector<std::string>& items)
{
    const char* saved = p; // to restore position if we fail
    if (parseDQString(p, key)) {
        if (key == "meta") {
            return parseMetaData(p, metadatas);
        } else {
            return parseChar(p, ':') && (parseDQString(p, value) || parseList(p, items) || parseDouble(p, dbl));
        }
    } else {
        p = saved;
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse gui:
// "type" : "...", "label" : "...", "address" : "...", ...
// and store the result in uiItems Vector
/// ---------------------------------------------------------------------
static bool parseUI(const char*& p, std::vector<itemInfo>& uiItems, int& numItems)
{
    const char* saved = p; // to restore position if we fail
    if (parseChar(p, '{')) {
   
        std::string label;
        std::string value;
        double dbl = 0;
        
        do {
            if (parseDQString(p, label)) {
                if (label == "type") {
                    if (uiItems.size() != 0) {
                        numItems++;
                    }
                    if (parseChar(p, ':') && parseDQString(p, value)) {   
                        itemInfo item;
                        item.type = value;
                        uiItems.push_back(item);
                    }
                }
                
                else if (label == "label") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].label = value;
                    }
                }
                
                else if (label == "shortname") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].shortname = value;
                    }
                }
                
                else if (label == "address") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].address = value;
                    }
                }
                
                else if (label == "url") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].url = value;
                    }
                }
                
                else if (label == "index") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].index = int(dbl);
                    }
                }
                
                else if (label == "meta") {
                    if (!parseItemMetaData(p, uiItems[numItems].meta)) {
                        return false;
                    }
                }
                
                else if (label == "init") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].init = dbl;
                    }
                }
                
                else if (label == "min") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].fmin = dbl;
                    }
                }
                
                else if (label == "max") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].fmax = dbl;
                    }
                }
                
                else if (label == "step") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].step = dbl;
                    }
                }
                
                else if (label == "items") {
                    if (parseChar(p, ':') && parseChar(p, '[')) {
                        do {
                            if (!parseUI(p, uiItems, numItems)) {
                                p = saved;
                                return false;
                            }
                        } while (tryChar(p, ','));
                        if (parseChar(p, ']')) {
                            itemInfo item;
                            item.type = "close";
                            uiItems.push_back(item);
                            numItems++;
                        }
                    }
            
                } else {
                    fprintf(stderr, "Parse error unknown : %s \n", label.c_str());
                    assert(false);
                }
            } else {
                p = saved;
                return false;
            }
            
        } while (tryChar(p, ','));
    
        return parseChar(p, '}');
    } else {
        return true; // "items": [] is valid
    }
}

// ---------------------------------------------------------------------
// Parse full JSON record describing a JSON/Faust interface :
// {"metadatas": "...", "ui": [{ "type": "...", "label": "...", "items": [...], "address": "...","init": "...", "min": "...", "max": "...","step": "..."}]}
//
// and store the result in map Metadatas and vector containing the items of the interface. Returns true if parsing was successfull.
/// ---------------------------------------------------------------------
static bool parseJson(const char*& p,
                      std::map<std::string, std::pair<std::string, double> >& metaDatas0,
                      std::map<std::string, std::string>& metaDatas1,
                      std::map<std::string, std::vector<std::string> >& metaDatas2,
                      std::vector<itemInfo>& uiItems)
{
    parseChar(p, '{');
    
    do {
        std::string key;
        std::string value;
        double dbl = 0;
        std::vector<std::string> items;
        if (parseGlobalMetaData(p, key, value, dbl, metaDatas1, items)) {
            if (key != "meta") {
                // keep "name", "inputs", "outputs" key/value pairs
                if (items.size() > 0) {
                    metaDatas2[key] = items;
                    items.clear();
                } else if (value != "") {
                    metaDatas0[key].first = value;
                } else {
                    metaDatas0[key].second = dbl;
                }
            }
        } else if (key == "ui") {
            int numItems = 0;
            parseChar(p, '[') && parseUI(p, uiItems, numItems);
        }
    } while (tryChar(p, ','));
    
    return parseChar(p, '}');
}

#endif // SIMPLEPARSER_H
/**************************  END  SimpleParser.h **************************/

static bool startWith(const std::string& str, const std::string& prefix)
{
    return (str.substr(0, prefix.size()) == prefix);
}

/**
 * Convert a dB value into a scale between 0 and 1 (following IEC standard ?)
 */
static FAUSTFLOAT dB2Scale(FAUSTFLOAT dB)
{
    FAUSTFLOAT scale = FAUSTFLOAT(1.0);
    
    /*if (dB < -70.0f)
     scale = 0.0f;
     else*/
    if (dB < FAUSTFLOAT(-60.0))
        scale = (dB + FAUSTFLOAT(70.0)) * FAUSTFLOAT(0.0025);
    else if (dB < FAUSTFLOAT(-50.0))
        scale = (dB + FAUSTFLOAT(60.0)) * FAUSTFLOAT(0.005) + FAUSTFLOAT(0.025);
    else if (dB < FAUSTFLOAT(-40.0))
        scale = (dB + FAUSTFLOAT(50.0)) * FAUSTFLOAT(0.0075) + FAUSTFLOAT(0.075);
    else if (dB < FAUSTFLOAT(-30.0))
        scale = (dB + FAUSTFLOAT(40.0)) * FAUSTFLOAT(0.015) + FAUSTFLOAT(0.15);
    else if (dB < FAUSTFLOAT(-20.0))
        scale = (dB + FAUSTFLOAT(30.0)) * FAUSTFLOAT(0.02) + FAUSTFLOAT(0.3);
    else if (dB < FAUSTFLOAT(-0.001) || dB > FAUSTFLOAT(0.001))  /* if (dB < 0.0) */
        scale = (dB + FAUSTFLOAT(20.0)) * FAUSTFLOAT(0.025) + FAUSTFLOAT(0.5);
    
    return scale;
}

/*******************************************************************************
 * MetaDataUI : Common class for MetaData handling
 ******************************************************************************/

//============================= BEGIN GROUP LABEL METADATA===========================
// Unlike widget's label, metadata inside group's label are not extracted directly by
// the Faust compiler. Therefore they must be extracted within the architecture file
//-----------------------------------------------------------------------------------

class MetaDataUI {
    
    protected:
        
        std::string                         fGroupTooltip;
        std::map<FAUSTFLOAT*, FAUSTFLOAT>   fGuiSize;            // map widget zone with widget size coef
        std::map<FAUSTFLOAT*, std::string>  fTooltip;            // map widget zone with tooltip strings
        std::map<FAUSTFLOAT*, std::string>  fUnit;               // map widget zone to unit string (i.e. "dB")
        std::map<FAUSTFLOAT*, std::string>  fRadioDescription;   // map zone to {'low':440; ...; 'hi':1000.0}
        std::map<FAUSTFLOAT*, std::string>  fMenuDescription;    // map zone to {'low':440; ...; 'hi':1000.0}
        std::set<FAUSTFLOAT*>               fKnobSet;            // set of widget zone to be knobs
        std::set<FAUSTFLOAT*>               fLedSet;             // set of widget zone to be LEDs
        std::set<FAUSTFLOAT*>               fNumSet;             // set of widget zone to be numerical bargraphs
        std::set<FAUSTFLOAT*>               fLogSet;             // set of widget zone having a log UI scale
        std::set<FAUSTFLOAT*>               fExpSet;             // set of widget zone having an exp UI scale
        std::set<FAUSTFLOAT*>               fHiddenSet;          // set of hidden widget zone
        
        void clearMetadata()
        {
            fGuiSize.clear();
            fTooltip.clear();
            fUnit.clear();
            fRadioDescription.clear();
            fMenuDescription.clear();
            fKnobSet.clear();
            fLedSet.clear();
            fNumSet.clear();
            fLogSet.clear();
            fExpSet.clear();
            fHiddenSet.clear();
            fGroupTooltip = "";
        }
        
        /**
         * rmWhiteSpaces(): Remove the leading and trailing white spaces of a string
         * (but not those in the middle of the string)
         */
        static std::string rmWhiteSpaces(const std::string& s)
        {
            size_t i = s.find_first_not_of(" \t");
            size_t j = s.find_last_not_of(" \t");
            if ((i != std::string::npos) && (j != std::string::npos)) {
                return s.substr(i, 1+j-i);
            } else {
                return "";
            }
        }
        
        /**
         * Format tooltip string by replacing some white spaces by
         * return characters so that line width doesn't exceed n.
         * Limitation : long words exceeding n are not cut.
         */
        std::string formatTooltip(int n, const std::string& tt)
        {
            std::string ss = tt;  // ss string we are going to format
            int lws = 0;          // last white space encountered
            int lri = 0;          // last return inserted
            for (int i = 0; i < (int)tt.size(); i++) {
                if (tt[i] == ' ') lws = i;
                if (((i-lri) >= n) && (lws > lri)) {
                    // insert return here
                    ss[lws] = '\n';
                    lri = lws;
                }
            }
            return ss;
        }
        
    public:
        
        virtual ~MetaDataUI()
        {}
        
        enum Scale {
            kLin,
            kLog,
            kExp
        };
        
        Scale getScale(FAUSTFLOAT* zone)
        {
            if (fLogSet.count(zone) > 0) return kLog;
            if (fExpSet.count(zone) > 0) return kExp;
            return kLin;
        }
        
        bool isKnob(FAUSTFLOAT* zone)
        {
            return fKnobSet.count(zone) > 0;
        }
        
        bool isRadio(FAUSTFLOAT* zone)
        {
            return fRadioDescription.count(zone) > 0;
        }
        
        bool isMenu(FAUSTFLOAT* zone)
        {
            return fMenuDescription.count(zone) > 0;
        }
        
        bool isLed(FAUSTFLOAT* zone)
        {
            return fLedSet.count(zone) > 0;
        }
        
        bool isNumerical(FAUSTFLOAT* zone)
        {
            return fNumSet.count(zone) > 0;
        }
        
        bool isHidden(FAUSTFLOAT* zone)
        {
            return fHiddenSet.count(zone) > 0;
        }
        
        /**
         * Extracts metadata from a label : 'vol [unit: dB]' -> 'vol' + metadata(unit=dB)
         */
        static void extractMetadata(const std::string& fulllabel, std::string& label, std::map<std::string, std::string>& metadata)
        {
            enum {kLabel, kEscape1, kEscape2, kEscape3, kKey, kValue};
            int state = kLabel; int deep = 0;
            std::string key, value;
            
            for (unsigned int i = 0; i < fulllabel.size(); i++) {
                char c = fulllabel[i];
                switch (state) {
                    case kLabel :
                        assert(deep == 0);
                        switch (c) {
                            case '\\' : state = kEscape1; break;
                            case '[' : state = kKey; deep++; break;
                            default : label += c;
                        }
                        break;
                        
                    case kEscape1:
                        label += c;
                        state = kLabel;
                        break;
                        
                    case kEscape2:
                        key += c;
                        state = kKey;
                        break;
                        
                    case kEscape3:
                        value += c;
                        state = kValue;
                        break;
                        
                    case kKey:
                        assert(deep > 0);
                        switch (c) {
                            case '\\':
                                state = kEscape2;
                                break;
                                
                            case '[':
                                deep++;
                                key += c;
                                break;
                                
                            case ':':
                                if (deep == 1) {
                                    state = kValue;
                                } else {
                                    key += c;
                                }
                                break;
                            case ']':
                                deep--;
                                if (deep < 1) {
                                    metadata[rmWhiteSpaces(key)] = "";
                                    state = kLabel;
                                    key = "";
                                    value = "";
                                } else {
                                    key += c;
                                }
                                break;
                            default : key += c;
                        }
                        break;
                        
                    case kValue:
                        assert(deep > 0);
                        switch (c) {
                            case '\\':
                                state = kEscape3;
                                break;
                                
                            case '[':
                                deep++;
                                value += c;
                                break;
                                
                            case ']':
                                deep--;
                                if (deep < 1) {
                                    metadata[rmWhiteSpaces(key)] = rmWhiteSpaces(value);
                                    state = kLabel;
                                    key = "";
                                    value = "";
                                } else {
                                    value += c;
                                }
                                break;
                            default : value += c;
                        }
                        break;
                        
                    default:
                        fprintf(stderr, "ERROR unrecognized state %d\n", state);
                }
            }
            label = rmWhiteSpaces(label);
        }
        
        /**
         * Analyses the widget zone metadata declarations and takes appropriate actions.
         */
        void declare(FAUSTFLOAT* zone, const char* key, const char* value)
        {
            if (zone == 0) {
                // special zone 0 means group metadata
                if (strcmp(key, "tooltip") == 0) {
                    // only group tooltip are currently implemented
                    fGroupTooltip = formatTooltip(30, value);
                } else if ((strcmp(key, "hidden") == 0) && (strcmp(value, "1") == 0)) {
                    fHiddenSet.insert(zone);
                }
            } else {
                if (strcmp(key, "size") == 0) {
                    fGuiSize[zone] = atof(value);
                }
                else if (strcmp(key, "tooltip") == 0) {
                    fTooltip[zone] = formatTooltip(30, value);
                }
                else if (strcmp(key, "unit") == 0) {
                    fUnit[zone] = value;
                }
                else if ((strcmp(key, "hidden") == 0) && (strcmp(value, "1") == 0)) {
                    fHiddenSet.insert(zone);
                }
                else if (strcmp(key, "scale") == 0) {
                    if (strcmp(value, "log") == 0) {
                        fLogSet.insert(zone);
                    } else if (strcmp(value, "exp") == 0) {
                        fExpSet.insert(zone);
                    }
                }
                else if (strcmp(key, "style") == 0) {
                    if (strcmp(value, "knob") == 0) {
                        fKnobSet.insert(zone);
                    } else if (strcmp(value, "led") == 0) {
                        fLedSet.insert(zone);
                    } else if (strcmp(value, "numerical") == 0) {
                        fNumSet.insert(zone);
                    } else {
                        const char* p = value;
                        if (parseWord(p, "radio")) {
                            fRadioDescription[zone] = std::string(p);
                        } else if (parseWord(p, "menu")) {
                            fMenuDescription[zone] = std::string(p);
                        }
                    }
                }
            }
        }
    
};

#endif
/**************************  END  MetaDataUI.h **************************/
/************************** BEGIN ring-buffer.h **************************/
/*
  Copyright (C) 2000 Paul Davis
  Copyright (C) 2003 Rohan Drape
  Copyright (C) 2016 GRAME (renaming for internal use)

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

  ISO/POSIX C version of Paul Davis's lock free ringbuffer C++ code.
  This is safe for the case of one read thread and one write thread.
*/

#ifndef __ring_buffer__
#define __ring_buffer__

#include <stdlib.h>
#include <string.h>

#ifdef WIN32
# pragma warning (disable: 4334)
#else
# pragma GCC diagnostic ignored "-Wunused-function"
#endif

typedef struct {
    char *buf;
    size_t len;
}
ringbuffer_data_t;

typedef struct {
    char *buf;
    volatile size_t write_ptr;
    volatile size_t read_ptr;
    size_t	size;
    size_t	size_mask;
    int	mlocked;
}
ringbuffer_t;

static ringbuffer_t *ringbuffer_create(size_t sz);
static void ringbuffer_free(ringbuffer_t *rb);
static void ringbuffer_get_read_vector(const ringbuffer_t *rb,
                                         ringbuffer_data_t *vec);
static void ringbuffer_get_write_vector(const ringbuffer_t *rb,
                                          ringbuffer_data_t *vec);
static size_t ringbuffer_read(ringbuffer_t *rb, char *dest, size_t cnt);
static size_t ringbuffer_peek(ringbuffer_t *rb, char *dest, size_t cnt);
static void ringbuffer_read_advance(ringbuffer_t *rb, size_t cnt);
static size_t ringbuffer_read_space(const ringbuffer_t *rb);
static int ringbuffer_mlock(ringbuffer_t *rb);
static void ringbuffer_reset(ringbuffer_t *rb);
static void ringbuffer_reset_size (ringbuffer_t * rb, size_t sz);
static size_t ringbuffer_write(ringbuffer_t *rb, const char *src,
                                 size_t cnt);
static void ringbuffer_write_advance(ringbuffer_t *rb, size_t cnt);
static size_t ringbuffer_write_space(const ringbuffer_t *rb);

/* Create a new ringbuffer to hold at least `sz' bytes of data. The
   actual buffer size is rounded up to the next power of two. */

static ringbuffer_t *
ringbuffer_create (size_t sz)
{
	size_t power_of_two;
	ringbuffer_t *rb;

	if ((rb = (ringbuffer_t *) malloc (sizeof (ringbuffer_t))) == NULL) {
		return NULL;
	}

	for (power_of_two = 1u; 1u << power_of_two < sz; power_of_two++);

	rb->size = 1u << power_of_two;
	rb->size_mask = rb->size;
	rb->size_mask -= 1;
	rb->write_ptr = 0;
	rb->read_ptr = 0;
	if ((rb->buf = (char *) malloc (rb->size)) == NULL) {
		free (rb);
		return NULL;
	}
	rb->mlocked = 0;

	return rb;
}

/* Free all data associated with the ringbuffer `rb'. */

static void
ringbuffer_free (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (rb->mlocked) {
		munlock (rb->buf, rb->size);
	}
#endif /* USE_MLOCK */
	free (rb->buf);
	free (rb);
}

/* Lock the data block of `rb' using the system call 'mlock'.  */

static int
ringbuffer_mlock (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (mlock (rb->buf, rb->size)) {
		return -1;
	}
#endif /* USE_MLOCK */
	rb->mlocked = 1;
	return 0;
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

static void
ringbuffer_reset (ringbuffer_t * rb)
{
	rb->read_ptr = 0;
	rb->write_ptr = 0;
    memset(rb->buf, 0, rb->size);
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

static void
ringbuffer_reset_size (ringbuffer_t * rb, size_t sz)
{
    rb->size = sz;
    rb->size_mask = rb->size;
    rb->size_mask -= 1;
    rb->read_ptr = 0;
    rb->write_ptr = 0;
}

/* Return the number of bytes available for reading. This is the
   number of bytes in front of the read pointer and behind the write
   pointer.  */

static size_t
ringbuffer_read_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return w - r;
	} else {
		return (w - r + rb->size) & rb->size_mask;
	}
}

/* Return the number of bytes available for writing. This is the
   number of bytes in front of the write pointer and behind the read
   pointer.  */

static size_t
ringbuffer_write_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		return (r - w) - 1;
	} else {
		return rb->size - 1;
	}
}

/* The copying data reader. Copy at most `cnt' bytes from `rb' to
   `dest'.  Returns the actual number of bytes copied. */

static size_t
ringbuffer_read (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[rb->read_ptr]), n1);
	rb->read_ptr = (rb->read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[rb->read_ptr]), n2);
		rb->read_ptr = (rb->read_ptr + n2) & rb->size_mask;
	}

	return to_read;
}

/* The copying data reader w/o read pointer advance. Copy at most
   `cnt' bytes from `rb' to `dest'.  Returns the actual number of bytes
   copied. */

static size_t
ringbuffer_peek (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;
	size_t tmp_read_ptr;

	tmp_read_ptr = rb->read_ptr;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = tmp_read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - tmp_read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[tmp_read_ptr]), n1);
	tmp_read_ptr = (tmp_read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[tmp_read_ptr]), n2);
	}

	return to_read;
}

/* The copying data writer. Copy at most `cnt' bytes to `rb' from
   `src'.  Returns the actual number of bytes copied. */

static size_t
ringbuffer_write (ringbuffer_t * rb, const char *src, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_write;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_write_space (rb)) == 0) {
		return 0;
	}

	to_write = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->write_ptr + to_write;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->write_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_write;
		n2 = 0;
	}

	memcpy (&(rb->buf[rb->write_ptr]), src, n1);
	rb->write_ptr = (rb->write_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (&(rb->buf[rb->write_ptr]), src + n1, n2);
		rb->write_ptr = (rb->write_ptr + n2) & rb->size_mask;
	}

	return to_write;
}

/* Advance the read pointer `cnt' places. */

static void
ringbuffer_read_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->read_ptr + cnt) & rb->size_mask;
	rb->read_ptr = tmp;
}

/* Advance the write pointer `cnt' places. */

static void
ringbuffer_write_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->write_ptr + cnt) & rb->size_mask;
	rb->write_ptr = tmp;
}

/* The non-copying data reader. `vec' is an array of two places. Set
   the values at `vec' to hold the current readable data at `rb'. If
   the readable data is in one segment the second segment has zero
   length. */

static void
ringbuffer_get_read_vector (const ringbuffer_t * rb,
				 ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = w - r;
	} else {
		free_cnt = (w - r + rb->size) & rb->size_mask;
	}

	cnt2 = r + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = rb->size - r;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;

	} else {

		/* Single part vector: just the rest of the buffer */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

/* The non-copying data writer. `vec' is an array of two places. Set
   the values at `vec' to hold the current writeable data at `rb'. If
   the writeable data is in one segment the second segment has zero
   length. */

static void
ringbuffer_get_write_vector (const ringbuffer_t * rb,
				  ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		free_cnt = (r - w) - 1;
	} else {
		free_cnt = rb->size - 1;
	}

	cnt2 = w + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[w]);
		vec[0].len = rb->size - w;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;
	} else {
		vec[0].buf = &(rb->buf[w]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

#endif // __ring_buffer__
/**************************  END  ring-buffer.h **************************/

/*******************************************************************************
 * GUI : Abstract Graphic User Interface
 * Provides additional mechanisms to synchronize widgets and zones. Widgets
 * should both reflect the value of a zone and allow to change this value.
 ******************************************************************************/

class uiItem;
class GUI;
struct clist;

typedef void (*uiCallback)(FAUSTFLOAT val, void* data);

/**
 * Base class for uiTypedItem: memory zones that can be grouped and synchronized, using an internal cache.
 */
struct uiItemBase
{
    
    uiItemBase(GUI* ui, FAUSTFLOAT* zone)
    {
        assert(ui);
        assert(zone);
    }
    
    virtual ~uiItemBase()
    {}
    
    /**
     * This method will be called when the value changes externally,
     * and will signal the new value to all linked uItem
     * when the value is different from the cached one.
     *
     * @param v - the new value
     */
    virtual void modifyZone(FAUSTFLOAT v) = 0;
    
    /**
     * This method will be called when the value changes externally,
     * and will signal the new value to all linked uItem
     * when the value is different from the cached one.
     *
     * @param date - the timestamp of the received value in usec
     * @param v - the new value
     */
    virtual void modifyZone(double date, FAUSTFLOAT v) {}
    
    /**
     * This method is called by the synchronisation mecanism and is expected
     * to 'reflect' the new value, by changing the Widget layout for instance,
     * or sending a message (OSC, MIDI...)
     */
    virtual void reflectZone() = 0;
    
    /**
     * Return the cached value.
     *
     * @return - the cached value
     */
    virtual double cache() = 0;
    
};

// Declared as 'static' to avoid code duplication at link time
static void deleteClist(clist* cl);

/**
 * A list containing all groupe uiItemBase objects.
 */
struct clist : public std::list<uiItemBase*>
{
    
    virtual ~clist()
    {
        deleteClist(this);
    }
        
};

static void createUiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data);

typedef std::map<FAUSTFLOAT*, clist*> zmap;

typedef std::map<FAUSTFLOAT*, ringbuffer_t*> ztimedmap;

class GUI : public UI
{
		
    private:
     
        static std::list<GUI*> fGuiList;
        zmap fZoneMap;
        bool fStopped;
    
     public:
            
        GUI():fStopped(false)
        {	
            fGuiList.push_back(this);
        }
        
        virtual ~GUI() 
        {   
            // delete all items
            for (const auto& it : fZoneMap) {
                delete it.second;
            }
            // suppress 'this' in static fGuiList
            fGuiList.remove(this);
        }

        // -- registerZone(z,c) : zone management
        
        void registerZone(FAUSTFLOAT* z, uiItemBase* c)
        {
            if (fZoneMap.find(z) == fZoneMap.end()) fZoneMap[z] = new clist();
            fZoneMap[z]->push_back(c);
        }
    
        void updateZone(FAUSTFLOAT* z)
        {
            FAUSTFLOAT v = *z;
            clist* cl = fZoneMap[z];
            for (const auto& c : *cl) {
                if (c->cache() != v) c->reflectZone();
            }
        }
    
        void updateAllZones()
        {
            for (const auto& m : fZoneMap) {
                updateZone(m.first);
            }
        }
    
        static void updateAllGuis()
        {
            for (const auto& g : fGuiList) {
                g->updateAllZones();
            }
        }
    
        void addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data)
        {
            createUiCallbackItem(this, zone, foo, data);
        }

        // Start event or message processing
        virtual bool run() { return false; };
        // Stop event or message processing
        virtual void stop() { fStopped = true; }
        bool stopped() { return fStopped; }
    
        // -- widget's layouts
        
        virtual void openTabBox(const char* label) {}
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
    
        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
    
        // Static global for timed zones, shared between all UI that will set timed values
        static ztimedmap gTimedZoneMap;

};

/**
 * User Interface Item: abstract definition.
 */
template <typename REAL>
class uiTypedItemReal : public uiItemBase
{
    protected:
        
        GUI* fGUI;
        REAL* fZone;
        REAL fCache;
        
        uiTypedItemReal(GUI* ui, REAL* zone):uiItemBase(ui, static_cast<FAUSTFLOAT*>(zone)),
        fGUI(ui), fZone(zone), fCache(REAL(-123456.654321))
        {
            ui->registerZone(zone, this);
        }
        
    public:
        
        virtual ~uiTypedItemReal()
        {}
    
        void modifyZone(REAL v)
        {
            fCache = v;
            if (*fZone != v) {
                *fZone = v;
                fGUI->updateZone(fZone);
            }
        }
    
        double cache() { return fCache; }
    
};

class uiItem : public uiTypedItemReal<FAUSTFLOAT> {
    
    protected:
    
        uiItem(GUI* ui, FAUSTFLOAT* zone):uiTypedItemReal<FAUSTFLOAT>(ui, zone)
        {}

    public:

        virtual ~uiItem() 
        {}

		void modifyZone(FAUSTFLOAT v)
		{
			fCache = v;
			if (*fZone != v) {
				*fZone = v;
				fGUI->updateZone(fZone);
			}
		}

};

/**
 * Base class for items with a value converter.
 */
struct uiConverter {
    
    ValueConverter* fConverter;
    
    uiConverter(MetaDataUI::Scale scale, FAUSTFLOAT umin, FAUSTFLOAT umax, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
    {
        // Select appropriate converter according to scale mode
        if (scale == MetaDataUI::kLog) {
            fConverter = new LogValueConverter(umin, umax, fmin, fmax);
        } else if (scale == MetaDataUI::kExp) {
            fConverter = new ExpValueConverter(umin, umax, fmin, fmax);
        } else {
            fConverter = new LinearValueConverter(umin, umax, fmin, fmax);
        }
    }
    
    virtual ~uiConverter()
    {
        delete fConverter;
    }
};

/**
 * User Interface item owned (and so deleted) by external code.
 */
class uiOwnedItem : public uiItem {
    
    protected:
    
        uiOwnedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
    
     public:
    
        virtual ~uiOwnedItem()
        {}
    
        virtual void reflectZone() {}
};

/**
 * Callback Item.
 */
class uiCallbackItem : public uiItem {
    
    protected:
    
        uiCallback fCallback;
        void* fData;
    
    public:
    
        uiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data)
        : uiItem(ui, zone), fCallback(foo), fData(data) {}
        
        virtual void reflectZone() 
        {		
            FAUSTFLOAT v = *fZone;
            fCache = v; 
            fCallback(v, fData);	
        }
};

/**
 *  For timestamped control.
 */
struct DatedControl {
    
    double fDate;
    FAUSTFLOAT fValue;
    
    DatedControl(double d = 0., FAUSTFLOAT v = FAUSTFLOAT(0)):fDate(d), fValue(v) {}
    
};

/**
 * Base class for timed items.
 */
class uiTimedItem : public uiItem
{
    
    protected:
        
        bool fDelete;
        
    public:
    
        using uiItem::modifyZone;
        
        uiTimedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {
            if (GUI::gTimedZoneMap.find(fZone) == GUI::gTimedZoneMap.end()) {
                GUI::gTimedZoneMap[fZone] = ringbuffer_create(8192);
                fDelete = true;
            } else {
                fDelete = false;
            }
        }
        
        virtual ~uiTimedItem()
        {
            ztimedmap::iterator it;
            if (fDelete && ((it = GUI::gTimedZoneMap.find(fZone)) != GUI::gTimedZoneMap.end())) {
                ringbuffer_free((*it).second);
                GUI::gTimedZoneMap.erase(it);
            }
        }
        
        virtual void modifyZone(double date, FAUSTFLOAT v)
        {
            size_t res;
            DatedControl dated_val(date, v);
            if ((res = ringbuffer_write(GUI::gTimedZoneMap[fZone], (const char*)&dated_val, sizeof(DatedControl))) != sizeof(DatedControl)) {
                fprintf(stderr, "ringbuffer_write error DatedControl\n");
            }
        }
    
};

/**
 * Allows to group a set of zones.
 */
class uiGroupItem : public uiItem
{
    protected:
    
        std::vector<FAUSTFLOAT*> fZoneMap;

    public:
    
        uiGroupItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
        virtual ~uiGroupItem() 
        {}
        
        virtual void reflectZone() 
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            
            // Update all zones of the same group
            for (const auto& it : fZoneMap) {
                *it = v;
            }
        }
        
        void addZone(FAUSTFLOAT* zone) { fZoneMap.push_back(zone); }

};

// Cannot be defined as method in the classes.

static void createUiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data)
{
    new uiCallbackItem(ui, zone, foo, data);
}

static void deleteClist(clist* cl)
{
    for (const auto& it : *cl) {
        // This specific code is only used in JUCE context. TODO: use proper 'shared_ptr' based memory management.
    #if defined(JUCE_32BIT) || defined(JUCE_64BIT)
        uiOwnedItem* owned = dynamic_cast<uiOwnedItem*>(it);
        // owned items are deleted by external code
        if (!owned) {
            delete it;
        }
    #else
        delete it;
    #endif
    }
}

#endif
/**************************  END  GUI.h **************************/
/************************** BEGIN JSONUI.h *****************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_JSONUI_H
#define FAUST_JSONUI_H

#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <limits>


/*******************************************************************************
 * JSONUI : Faust User Interface
 * This class produce a complete JSON decription of the DSP instance.
 *
 * Since 'shortname' can only be computed when all paths have been created,
 * the fAllUI vector is progressively filled with partially built UI items,
 * which are finally created in the JSON(...) method.
 ******************************************************************************/

typedef std::vector<std::tuple<std::string, int, int, int, int, int>> MemoryLayoutType;
typedef std::map<std::string, int> PathTableType;

template <typename REAL>
class FAUST_API JSONUIReal : public PathBuilder, public Meta, public UIReal<REAL> {

    protected:
    
        std::stringstream fUI;
        std::vector<std::string> fAllUI;
        std::stringstream fMeta;
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        std::string fVersion;           // Compiler version
        std::string fCompileOptions;    // Compilation options
        std::vector<std::string> fLibraryList;
        std::vector<std::string> fIncludePathnames;
        std::string fName;
        std::string fFileName;
        std::string fExpandedCode;
        std::string fSHAKey;
        std::string fJSON;
        int fDSPSize;                   // In bytes
        PathTableType fPathTable;
        MemoryLayoutType fMemoryLayout;
        bool fExtended;
    
        char fCloseUIPar;
        char fCloseMetaPar;
        int fTab;
    
        int fInputs, fOutputs, fSRIndex;
         
        void tab(int n, std::ostream& fout)
        {
            fout << '\n';
            while (n-- > 0) {
                fout << '\t';
            }
        }
    
        std::string flatten(const std::string& src)
        {
            std::string dst;
            for (size_t i = 0; i < src.size(); i++) {
                switch (src[i]) {
                    case '\n':
                    case '\t':
                        break;
                    default:
                        dst += src[i];
                        break;
                }
            }
            return dst;
        }
    
        void addMeta(int tab_val, bool quote = true)
        {
            if (fMetaAux.size() > 0) {
                tab(tab_val, fUI); fUI << "\"meta\": [";
                std::string sep = "";
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    fUI << sep;
                    tab(tab_val + 1, fUI); fUI << "{ \"" << fMetaAux[i].first << "\": \"" << fMetaAux[i].second << "\" }";
                    sep = ",";
                }
                tab(tab_val, fUI); fUI << ((quote) ? "],": "]");
                fMetaAux.clear();
            }
        }
    
        int getAddressIndex(const std::string& path)
        {
            return (fPathTable.find(path) != fPathTable.end()) ? fPathTable[path] : -1;
        }
      
     public:
     
        JSONUIReal(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  int sr_index,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& compile_options,
                  const std::vector<std::string>& library_list,
                  const std::vector<std::string>& include_pathnames,
                  int size,
                  const PathTableType& path_table,
                  MemoryLayoutType memory_layout)
        {
            init(name, filename, inputs, outputs, sr_index, sha_key, dsp_code, version, compile_options, library_list, include_pathnames, size, path_table, memory_layout);
        }

        JSONUIReal(const std::string& name, const std::string& filename, int inputs, int outputs)
        {
            init(name, filename, inputs, outputs, -1, "", "", "", "", std::vector<std::string>(), std::vector<std::string>(), -1, PathTableType(), MemoryLayoutType());
        }

        JSONUIReal(int inputs, int outputs)
        {
            init("", "", inputs, outputs, -1, "", "","", "", std::vector<std::string>(), std::vector<std::string>(), -1, PathTableType(), MemoryLayoutType());
        }
        
        JSONUIReal()
        {
            init("", "", -1, -1, -1, "", "", "", "", std::vector<std::string>(), std::vector<std::string>(), -1, PathTableType(), MemoryLayoutType());
        }
 
        virtual ~JSONUIReal() {}
        
        void setInputs(int inputs) { fInputs = inputs; }
        void setOutputs(int outputs) { fOutputs = outputs; }
    
        void setSRIndex(int sr_index) { fSRIndex = sr_index; }
    
        // Init may be called multiple times so fMeta and fUI are reinitialized
        void init(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  int sr_index,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& compile_options,
                  const std::vector<std::string>& library_list,
                  const std::vector<std::string>& include_pathnames,
                  int size,
                  const PathTableType& path_table,
                  MemoryLayoutType memory_layout,
                  bool extended = false)
        {
            fTab = 1;
            fExtended = extended;
            if (fExtended) {
                fUI << std::setprecision(std::numeric_limits<REAL>::max_digits10);
                fMeta << std::setprecision(std::numeric_limits<REAL>::max_digits10);
            }
            
            // Start Meta generation
            fMeta.str("");
            tab(fTab, fMeta); fMeta << "\"meta\": [";
            fCloseMetaPar = ' ';
            
            // Start UI generation
            fUI.str("");
            tab(fTab, fUI); fUI << "\"ui\": [";
            fCloseUIPar = ' ';
            fTab += 1;
            
            fName = name;
            fFileName = filename;
            fInputs = inputs;
            fOutputs = outputs;
            fSRIndex = sr_index;
            fExpandedCode = dsp_code;
            fSHAKey = sha_key;
            fDSPSize = size;
            fPathTable = path_table;
            fVersion = version;
            fCompileOptions = compile_options;
            fLibraryList = library_list;
            fIncludePathnames = include_pathnames;
            fMemoryLayout = memory_layout;
        }
   
        // -- widget's layouts
    
        virtual void openGenericGroup(const char* label, const char* name)
        {
            pushLabel(label);
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            addMeta(fTab);
            tab(fTab, fUI); fUI << "\"items\": [";
            fCloseUIPar = ' ';
            fTab += 1;
        }

        virtual void openTabBox(const char* label)
        {
            openGenericGroup(label, "tgroup");
        }
    
        virtual void openHorizontalBox(const char* label)
        {
            openGenericGroup(label, "hgroup");
        }
    
        virtual void openVerticalBox(const char* label)
        {
            openGenericGroup(label, "vgroup");
        }
    
        virtual void closeBox()
        {
            if (popLabel()) {
                // Shortnames can be computed when all fullnames are known
                computeShortNames();
            }
            fTab -= 1;
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        // -- active widgets
  
        virtual void addGenericButton(const char* label, const char* name)
        {
            std::string path = buildPath(label);
            fFullPaths.push_back(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
        
            // Generate 'shortname' entry
            tab(fTab, fUI); fUI << "\"shortname\": \"";
        
            // Add fUI section
            fAllUI.push_back(fUI.str());
            fUI.str("");
        
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"address\": \"" << path << "\",";
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path) << ((fMetaAux.size() > 0) ? "," : "");
            } else {
                tab(fTab, fUI); fUI << "\"address\": \"" << path << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            }
            addMeta(fTab, false);
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "button");
        }
    
        virtual void addCheckButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "checkbox");
        }

        virtual void addGenericEntry(const char* label, const char* name, REAL init, REAL min, REAL max, REAL step)
        {
            std::string path = buildPath(label);
            fFullPaths.push_back(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
         
            // Generate 'shortname' entry
            tab(fTab, fUI); fUI << "\"shortname\": \"";
        
            // Add fUI section
            fAllUI.push_back(fUI.str());
            fUI.str("");
        
            tab(fTab, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path) << ",";
            }
            addMeta(fTab);
            tab(fTab, fUI); fUI << "\"init\": " << init << ",";
            tab(fTab, fUI); fUI << "\"min\": " << min << ",";
            tab(fTab, fUI); fUI << "\"max\": " << max << ",";
            tab(fTab, fUI); fUI << "\"step\": " << step;
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        virtual void addVerticalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "vslider", init, min, max, step);
        }
    
        virtual void addHorizontalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "hslider", init, min, max, step);
        }
    
        virtual void addNumEntry(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "nentry", init, min, max, step);
        }

        // -- passive widgets
    
        virtual void addGenericBargraph(const char* label, const char* name, REAL min, REAL max) 
        {
            std::string path = buildPath(label);
            fFullPaths.push_back(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
         
            // Generate 'shortname' entry
            tab(fTab, fUI); fUI << "\"shortname\": \"";
        
            // Add fUI section
            fAllUI.push_back(fUI.str());
            fUI.str("");
            
            tab(fTab, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path) << ",";
            }
            addMeta(fTab);
            tab(fTab, fUI); fUI << "\"min\": " << min << ",";
            tab(fTab, fUI); fUI << "\"max\": " << max;
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addHorizontalBargraph(const char* label, REAL* zone, REAL min, REAL max) 
        {
            addGenericBargraph(label, "hbargraph", min, max);
        }
    
        virtual void addVerticalBargraph(const char* label, REAL* zone, REAL min, REAL max)
        {
            addGenericBargraph(label, "vbargraph", min, max);
        }
    
        virtual void addSoundfile(const char* label, const char* url, Soundfile** zone)
        {
            std::string path = buildPath(label);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << "soundfile" << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab, fUI); fUI << "\"url\": \"" << url << "\"" << ",";
            tab(fTab, fUI); fUI << "\"address\": \"" << path << "\"" << ((fPathTable.size() > 0) ? "," : "");
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path);
            }
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        // -- metadata declarations

        virtual void declare(REAL* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
    
        // Meta interface
        virtual void declare(const char* key, const char* value)
        {
            fMeta << fCloseMetaPar;
            // fName found in metadata
            if ((strcmp(key, "name") == 0) && (fName == "")) fName = value;
            // fFileName found in metadata
            if ((strcmp(key, "filename") == 0) && (fFileName == "")) fFileName = value;
            tab(fTab, fMeta); fMeta << "{ " << "\"" << key << "\"" << ": " << "\"" << value << "\" }";
            fCloseMetaPar = ',';
        }
    
        std::string JSON(bool flat = false)
        {
            if (fJSON.empty()) {
                fTab = 0;
                std::stringstream JSON;
                if (fExtended) {
                    JSON << std::setprecision(std::numeric_limits<REAL>::max_digits10);
                }
                JSON << "{";
                fTab += 1;
                tab(fTab, JSON); JSON << "\"name\": \"" << fName << "\",";
                tab(fTab, JSON); JSON << "\"filename\": \"" << fFileName << "\",";
                if (fVersion != "") { tab(fTab, JSON); JSON << "\"version\": \"" << fVersion << "\","; }
                if (fCompileOptions != "") { tab(fTab, JSON); JSON << "\"compile_options\": \"" <<  fCompileOptions << "\","; }
                if (fLibraryList.size() > 0) {
                    tab(fTab, JSON);
                    JSON << "\"library_list\": [";
                    for (size_t i = 0; i < fLibraryList.size(); i++) {
                        JSON << "\"" << fLibraryList[i] << "\"";
                        if (i < (fLibraryList.size() - 1)) JSON << ",";
                    }
                    JSON << "],";
                }
                if (fIncludePathnames.size() > 0) {
                    tab(fTab, JSON);
                    JSON << "\"include_pathnames\": [";
                    for (size_t i = 0; i < fIncludePathnames.size(); i++) {
                        JSON << "\"" << fIncludePathnames[i] << "\"";
                        if (i < (fIncludePathnames.size() - 1)) JSON << ",";
                    }
                    JSON << "],";
                }
                if (fMemoryLayout.size() > 0) {
                    tab(fTab, JSON);
                    JSON << "\"memory_layout\": [";
                    for (size_t i = 0; i < fMemoryLayout.size(); i++) {
                        // DSP or field name, type, size, sizeBytes, reads, writes
                        std::tuple<std::string, int, int, int, int, int> item = fMemoryLayout[i];
                        tab(fTab + 1, JSON);
                        JSON << "{\"size\": " << std::get<3>(item) << ", ";
                        JSON << "\"reads\": " << std::get<4>(item) << ", ";
                        JSON << "\"writes\": " << std::get<5>(item) << "}";
                        if (i < (fMemoryLayout.size() - 1)) JSON << ",";
                    }
                    tab(fTab, JSON);
                    JSON << "],";
                }
                if (fDSPSize != -1) { tab(fTab, JSON); JSON << "\"size\": " << fDSPSize << ","; }
                if (fSHAKey != "") { tab(fTab, JSON); JSON << "\"sha_key\": \"" << fSHAKey << "\","; }
                if (fExpandedCode != "") { tab(fTab, JSON); JSON << "\"code\": \"" << fExpandedCode << "\","; }
                tab(fTab, JSON); JSON << "\"inputs\": " << fInputs << ",";
                tab(fTab, JSON); JSON << "\"outputs\": " << fOutputs << ",";
                if (fSRIndex != -1) { tab(fTab, JSON); JSON << "\"sr_index\": " << fSRIndex << ","; }
                tab(fTab, fMeta); fMeta << "],";
              
                // Add last UI section
                fAllUI.push_back(fUI.str());
                // Finalize UI generation
                fUI.str("");
                // Add N-1 sections
                for (size_t i = 0; i < fAllUI.size()-1; i++) {
                    fUI << fAllUI[i] << fFull2Short[fFullPaths[i]] << "\",";
                }
                // And the last one
                fUI << fAllUI[fAllUI.size()-1];
                // Terminates the UI section
                tab(fTab, fUI); fUI << "]";
            
                fTab -= 1;
                if (fCloseMetaPar == ',') { // If "declare" has been called, fCloseMetaPar state is now ','
                    JSON << fMeta.str() << fUI.str();
                } else {
                    JSON << fUI.str();
                }
                
                tab(fTab, JSON); JSON << "}";
                
                // Keep result in fJSON
                fJSON = JSON.str();
            }
            return (flat) ? flatten(fJSON) : fJSON;
        }
    
};

// Externally available class using FAUSTFLOAT

struct FAUST_API JSONUI : public JSONUIReal<FAUSTFLOAT>, public UI {
    
    JSONUI(const std::string& name,
           const std::string& filename,
           int inputs,
           int outputs,
           int sr_index,
           const std::string& sha_key,
           const std::string& dsp_code,
           const std::string& version,
           const std::string& compile_options,
           const std::vector<std::string>& library_list,
           const std::vector<std::string>& include_pathnames,
           int size,
           const PathTableType& path_table,
           MemoryLayoutType memory_layout):
    JSONUIReal<FAUSTFLOAT>(name, filename,
                          inputs, outputs,
                          sr_index,
                          sha_key, dsp_code,
                          version, compile_options,
                          library_list, include_pathnames,
                          size, path_table, memory_layout)
    {}
    
    JSONUI(const std::string& name, const std::string& filename, int inputs, int outputs):
    JSONUIReal<FAUSTFLOAT>(name, filename, inputs, outputs)
    {}
    
    JSONUI(int inputs, int outputs):JSONUIReal<FAUSTFLOAT>(inputs, outputs)
    {}
    
    JSONUI():JSONUIReal<FAUSTFLOAT>()
    {}

    virtual void openTabBox(const char* label)
    {
        JSONUIReal<FAUSTFLOAT>::openTabBox(label);
    }
    virtual void openHorizontalBox(const char* label)
    {
        JSONUIReal<FAUSTFLOAT>::openHorizontalBox(label);
    }
    virtual void openVerticalBox(const char* label)
    {
        JSONUIReal<FAUSTFLOAT>::openVerticalBox(label);
    }
    virtual void closeBox()
    {
        JSONUIReal<FAUSTFLOAT>::closeBox();
    }
    
    // -- active widgets
    
    virtual void addButton(const char* label, FAUSTFLOAT* zone)
    {
        JSONUIReal<FAUSTFLOAT>::addButton(label, zone);
    }
    virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
    {
        JSONUIReal<FAUSTFLOAT>::addCheckButton(label, zone);
    }
    virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        JSONUIReal<FAUSTFLOAT>::addVerticalSlider(label, zone, init, min, max, step);
    }
    virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        JSONUIReal<FAUSTFLOAT>::addHorizontalSlider(label, zone, init, min, max, step);
    }
    virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        JSONUIReal<FAUSTFLOAT>::addNumEntry(label, zone, init, min, max, step);
    }
    
    // -- passive widgets
    
    virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
    {
        JSONUIReal<FAUSTFLOAT>::addHorizontalBargraph(label, zone, min, max);
    }
    virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
    {
        JSONUIReal<FAUSTFLOAT>::addVerticalBargraph(label, zone, min, max);
    }
    
    // -- soundfiles
    
    virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone)
    {
        JSONUIReal<FAUSTFLOAT>::addSoundfile(label, filename, sf_zone);
    }
    
    // -- metadata declarations
    
    virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
    {
        JSONUIReal<FAUSTFLOAT>::declare(zone, key, val);
    }

    virtual void declare(const char* key, const char* val)
    {
        JSONUIReal<FAUSTFLOAT>::declare(key, val);
    }

    virtual ~JSONUI() {}
    
};

#endif // FAUST_JSONUI_H
/**************************  END  JSONUI.h **************************/
/************************** BEGIN midi.h *******************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
************************************************************************/

#ifndef __midi__
#define __midi__

#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <assert.h>


class FAUST_API MapUI;

/**
 * A timestamped short MIDI message used with SOUL.
 */

// Force contiguous memory layout
#pragma pack (push, 1)
struct MIDIMessage
{
    uint32_t frameIndex;
    uint8_t byte0, byte1, byte2;
};
#pragma pack (pop)

/**
 * For timestamped MIDI messages (in usec).
 */
struct DatedMessage {
    
    double fDate;
    unsigned char fBuffer[3];
    size_t fSize;
    
    DatedMessage(double date, unsigned char* buffer, size_t size)
    :fDate(date), fSize(size)
    {
        assert(size <= 3);
        memcpy(fBuffer, buffer, size);
    }
    
    DatedMessage():fDate(0.0), fSize(0)
    {}
    
};

/**
 * MIDI processor definition.
 *
 * MIDI input or output handling classes will implement this interface,
 * so the same method names (keyOn, keyOff, ctrlChange...) will be used either
 * when decoding MIDI input or encoding MIDI output events.
 * MIDI channel is numbered in [0..15] in this layer.
 */
class midi {

    public:

        midi() {}
        virtual ~midi() {}

        // Additional time-stamped API for MIDI input
        virtual MapUI* keyOn(double, int channel, int pitch, int velocity)
        {
            return keyOn(channel, pitch, velocity);
        }
        
        virtual void keyOff(double, int channel, int pitch, int velocity = 0)
        {
            keyOff(channel, pitch, velocity);
        }
    
        virtual void keyPress(double, int channel, int pitch, int press)
        {
            keyPress(channel, pitch, press);
        }
        
        virtual void chanPress(double date, int channel, int press)
        {
            chanPress(channel, press);
        }
    
        virtual void pitchWheel(double, int channel, int wheel)
        {
            pitchWheel(channel, wheel);
        }
           
        virtual void ctrlChange(double, int channel, int ctrl, int value)
        {
            ctrlChange(channel, ctrl, value);
        }
    
        virtual void ctrlChange14bits(double, int channel, int ctrl, int value)
        {
            ctrlChange14bits(channel, ctrl, value);
        }
    
        virtual void rpn(double, int channel, int ctrl, int value)
        {
            rpn(channel, ctrl, value);
        }

        virtual void progChange(double, int channel, int pgm)
        {
            progChange(channel, pgm);
        }
    
        virtual void sysEx(double, std::vector<unsigned char>& message)
        {
            sysEx(message);
        }

        // MIDI sync
        virtual void startSync(double date)  {}
        virtual void stopSync(double date)   {}
        virtual void clock(double date)  {}

        // Standard MIDI API
        virtual MapUI* keyOn(int channel, int pitch, int velocity)      { return nullptr; }
        virtual void keyOff(int channel, int pitch, int velocity)       {}
        virtual void keyPress(int channel, int pitch, int press)        {}
        virtual void chanPress(int channel, int press)                  {}
        virtual void ctrlChange(int channel, int ctrl, int value)       {}
        virtual void ctrlChange14bits(int channel, int ctrl, int value) {}
        virtual void rpn(int channel, int ctrl, int value)              {}
        virtual void pitchWheel(int channel, int wheel)                 {}
        virtual void progChange(int channel, int pgm)                   {}
        virtual void sysEx(std::vector<unsigned char>& message)         {}

        enum MidiStatus {
            // channel voice messages
            MIDI_NOTE_OFF = 0x80,
            MIDI_NOTE_ON = 0x90,
            MIDI_CONTROL_CHANGE = 0xB0,
            MIDI_PROGRAM_CHANGE = 0xC0,
            MIDI_PITCH_BEND = 0xE0,
            MIDI_AFTERTOUCH = 0xD0,         // aka channel pressure
            MIDI_POLY_AFTERTOUCH = 0xA0,    // aka key pressure
            MIDI_CLOCK = 0xF8,
            MIDI_START = 0xFA,
            MIDI_CONT = 0xFB,
            MIDI_STOP = 0xFC,
            MIDI_SYSEX_START = 0xF0,
            MIDI_SYSEX_STOP = 0xF7
        };

        enum MidiCtrl {
            ALL_NOTES_OFF = 123,
            ALL_SOUND_OFF = 120
        };
    
        enum MidiNPN {
            PITCH_BEND_RANGE = 0
        };

};

/**
 * A class to decode NRPN and RPN messages, adapted from JUCE forum message:
 * https://forum.juce.com/t/14bit-midi-controller-support/11517
 */
class MidiNRPN {
    
    private:
    
        bool ctrlnew;
        int ctrlnum;
        int ctrlval;
        
        int nrpn_lsb, nrpn_msb;
        int data_lsb, data_msb;
        
        enum
        {
            midi_nrpn_lsb = 98,
            midi_nrpn_msb = 99,
            midi_rpn_lsb  = 100,
            midi_rpn_msb  = 101,
            midi_data_lsb = 38,
            midi_data_msb = 6
        };
    
    public:
        
        MidiNRPN(): ctrlnew(false), nrpn_lsb(-1), nrpn_msb(-1), data_lsb(-1), data_msb(-1)
        {}
        
        // return true if the message has been filtered
        bool process(int data1, int data2)
        {
            switch (data1)
            {
                case midi_nrpn_lsb: nrpn_lsb = data2; return true;
                case midi_nrpn_msb: nrpn_msb = data2; return true;
                case midi_rpn_lsb: {
                    if (data2 == 127) {
                        nrpn_lsb = data_lsb = -1;
                    } else {
                        nrpn_lsb = 0;
                        data_lsb = -1;
                    }
                    return true;
                }
                case midi_rpn_msb: {
                    if (data2 == 127) {
                        nrpn_msb = data_msb = -1;
                    } else {
                        nrpn_msb = 0;
                        data_msb = -1;
                    }
                    return true;
                }
                case midi_data_lsb:
                case midi_data_msb:
                {
                    if (data1 == midi_data_msb) {
                        if (nrpn_msb < 0) {
                            return false;
                        }
                        data_msb = data2;
                    } else { // midi_data_lsb
                        if (nrpn_lsb < 0) {
                            return false;
                        }
                        data_lsb = data2;
                    }
                    if (data_lsb >= 0 && data_msb >= 0) {
                        ctrlnum = (nrpn_msb << 7) | nrpn_lsb;
                        ctrlval = (data_msb << 7) | data_lsb;
                        data_lsb = data_msb = -1;
                        nrpn_msb = nrpn_lsb = -1;
                        ctrlnew = true;
                    }
                    return true;
                }
                default: return false;
            };
        }
        
        bool hasNewNRPN() { bool res = ctrlnew; ctrlnew = false; return res; }
        
        // results in [0, 16383]
        int getCtrl() const { return ctrlnum; }
        int getVal() const { return ctrlval; }
    
};

/**
 * A pure interface for MIDI handlers that can send/receive MIDI messages to/from 'midi' objects.
 */
struct midi_interface {
    virtual void addMidiIn(midi* midi_dsp)      = 0;
    virtual void removeMidiIn(midi* midi_dsp)   = 0;
    virtual ~midi_interface() {}
};

/****************************************************
 * Base class for MIDI input handling.
 *
 * Shared common code used for input handling:
 * - decoding Real-Time messages: handleSync
 * - decoding one data byte messages: handleData1
 * - decoding two data byte messages: handleData2
 * - getting ready messages in polling mode
 ****************************************************/
class midi_handler : public midi, public midi_interface {

    protected:

        std::vector<midi*> fMidiInputs;
        std::string fName;
        MidiNRPN fNRPN;
    
        int range(int min, int max, int val) { return (val < min) ? min : ((val >= max) ? max : val); }
  
    public:

        midi_handler(const std::string& name = "MIDIHandler"):midi_interface(), fName(name) {}
        virtual ~midi_handler() {}

        void addMidiIn(midi* midi_dsp) { if (midi_dsp) fMidiInputs.push_back(midi_dsp); }
        void removeMidiIn(midi* midi_dsp)
        {
            std::vector<midi*>::iterator it = std::find(fMidiInputs.begin(), fMidiInputs.end(), midi_dsp);
            if (it != fMidiInputs.end()) {
                fMidiInputs.erase(it);
            }
        }

        // Those 2 methods have to be implemented by subclasses
        virtual bool startMidi() { return true; }
        virtual void stopMidi() {}
    
        void setName(const std::string& name) { fName = name; }
        std::string getName() { return fName; }
    
        // To be used in polling mode
        virtual int recvMessages(std::vector<MIDIMessage>* message) { return 0; }
        virtual void sendMessages(std::vector<MIDIMessage>* message, int count) {}
    
        // MIDI Real-Time
        void handleClock(double time)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->clock(time);
            }
        }
        
        void handleStart(double time)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->startSync(time);
            }
        }
        
        void handleStop(double time)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->stopSync(time);
            }
        }
    
        void handleSync(double time, int type)
        {
            if (type == MIDI_CLOCK) {
                handleClock(time);
            // We can consider start and continue as identical messages
            } else if ((type == MIDI_START) || (type == MIDI_CONT)) {
                handleStart(time);
            } else if (type == MIDI_STOP) {
                handleStop(time);
            }
        }
    
        // MIDI 1 data
        void handleProgChange(double time, int channel, int data1)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->progChange(time, channel, data1);
            }
        }
    
        void handleAfterTouch(double time, int channel, int data1)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->chanPress(time, channel, data1);
            }
        }

        void handleData1(double time, int type, int channel, int data1)
        {
            if (type == MIDI_PROGRAM_CHANGE) {
                handleProgChange(time, channel, data1);
            } else if (type == MIDI_AFTERTOUCH) {
                handleAfterTouch(time, channel, data1);
            }
        }
    
        // MIDI 2 datas
        void handleKeyOff(double time, int channel, int data1, int data2)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->keyOff(time, channel, data1, data2);
            }
        }
        
        void handleKeyOn(double time, int channel, int data1, int data2)
        {
            if (data2 == 0) {
                handleKeyOff(time, channel, data1, data2);
            } else {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOn(time, channel, data1, data2);
                }
            }
        }
    
        void handleCtrlChange(double time, int channel, int data1, int data2)
        {
            // Special processing for NRPN and RPN
            if (fNRPN.process(data1, data2)) {
                if (fNRPN.hasNewNRPN()) {
                    for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                        fMidiInputs[i]->rpn(time, channel, fNRPN.getCtrl(), fNRPN.getVal());
                    }
                }
            } else {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->ctrlChange(time, channel, data1, data2);
                }
            }
        }
        
        void handlePitchWheel(double time, int channel, int data1, int data2)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->pitchWheel(time, channel, (data2 << 7) + data1);
            }
        }
    
        void handlePitchWheel(double time, int channel, int bend)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->pitchWheel(time, channel, bend);
            }
        }
        
        void handlePolyAfterTouch(double time, int channel, int data1, int data2)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->keyPress(time, channel, data1, data2);
            }
        }
  
        void handleData2(double time, int type, int channel, int data1, int data2)
        {
            if (type == MIDI_NOTE_OFF) {
                handleKeyOff(time, channel,  data1, data2);
            } else if (type == MIDI_NOTE_ON) {
                handleKeyOn(time, channel, data1, data2);
            } else if (type == MIDI_CONTROL_CHANGE) {
                handleCtrlChange(time, channel, data1, data2);
            } else if (type == MIDI_PITCH_BEND) {
                handlePitchWheel(time, channel, data1, data2);
            } else if (type == MIDI_POLY_AFTERTOUCH) {
                handlePolyAfterTouch(time, channel, data1, data2);
            }
        }
    
        // SysEx
        void handleSysex(double time, std::vector<unsigned char>& message)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->sysEx(time, message);
            }
        }
    
        void handleMessage(double time, int type, std::vector<unsigned char>& message)
        {
            if (type == MIDI_SYSEX_START) {
                handleSysex(time, message);
            }
        }
  
};

#endif // __midi__
/**************************  END  midi.h **************************/

#ifdef _MSC_VER
#define gsscanf sscanf_s
#else
#define gsscanf sscanf
#endif

/**
 * Helper code for MIDI meta and polyphonic 'nvoices' parsing.
 */
struct MidiMeta : public Meta, public std::map<std::string, std::string> {
    
    void declare(const char* key, const char* value)
    {
        (*this)[key] = value;
    }
    
    const std::string get(const char* key, const char* def)
    {
        return (this->find(key) != this->end()) ? (*this)[key] : def;
    }
    
    static void analyse(base_dsp* mono_dsp, bool& midi_sync, int& nvoices)
    {
        JSONUI jsonui;
        mono_dsp->buildUserInterface(&jsonui);
        std::string json = jsonui.JSON();
        midi_sync = ((json.find("midi") != std::string::npos) &&
                     ((json.find("start") != std::string::npos) ||
                      (json.find("stop") != std::string::npos) ||
                      (json.find("clock") != std::string::npos) ||
                      (json.find("timestamp") != std::string::npos)));
    
    #if defined(NVOICES) && NVOICES!=NUM_VOICES
        nvoices = NVOICES;
    #else
        MidiMeta meta;
        mono_dsp->metadata(&meta);
        bool found_voices = false;
        // If "options" metadata is used
        std::string options = meta.get("options", "");
        if (options != "") {
            std::map<std::string, std::string> metadata;
            std::string res;
            MetaDataUI::extractMetadata(options, res, metadata);
            if (metadata.find("nvoices") != metadata.end()) {
                nvoices = std::atoi(metadata["nvoices"].c_str());
                found_voices = true;
            }
        }
        // Otherwise test for "nvoices" metadata
        if (!found_voices) {
            std::string numVoices = meta.get("nvoices", "0");
            nvoices = std::atoi(numVoices.c_str());
        }
        nvoices = std::max<int>(0, nvoices);
    #endif
    }
    
    static bool checkPolyphony(base_dsp* mono_dsp)
    {
        MapUI map_ui;
        mono_dsp->buildUserInterface(&map_ui);
        bool has_freq = false;
        bool has_gate = false;
        bool has_gain = false;
        for (int i = 0; i < map_ui.getParamsCount(); i++) {
            std::string path = map_ui.getParamAddress(i);
            has_freq |= MapUI::endsWith(path, "/freq");
            has_freq |= MapUI::endsWith(path, "/key");
            has_gate |= MapUI::endsWith(path, "/gate");
            has_gain |= MapUI::endsWith(path, "/gain");
            has_gain |= MapUI::endsWith(path, "/vel");
            has_gain |= MapUI::endsWith(path, "/velocity");
        }
        return (has_freq && has_gate && has_gain);
    }
    
};

/**
 * uiMidi : Faust User Interface
 * This class decodes MIDI meta data and maps incoming MIDI messages to them.
 * Currently ctrlChange, keyOn/keyOff, keyPress, progChange, chanPress, pitchWheel/pitchBend
 * start/stop/clock meta data is handled.
 * MIDI channel is numbered in [1..16] in this layer.
 * Channel 0 means "all channels" when receiving or sending.
 */
class uiMidi {
    
    friend class MidiUI;
    
    protected:
        
        midi* fMidiOut;
        bool fInputCtrl;
        int fChan;
    
        bool inRange(FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT v) { return (min <= v && v <= max); }
    
    public:
        
        uiMidi(midi* midi_out, bool input, int chan = 0):fMidiOut(midi_out), fInputCtrl(input), fChan(chan)
        {}
        virtual ~uiMidi()
        {}

};

/**
 * Base class for MIDI aware UI items.
 */
class uiMidiItem : public uiMidi, public uiItem {
    
    public:
        
        uiMidiItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true, int chan = 0)
            :uiMidi(midi_out, input, chan), uiItem(ui, zone)
        {}
        virtual ~uiMidiItem()
        {}
    
        virtual void reflectZone() {}
    
};

/**
 * Base class for MIDI aware UI items with timestamp support.
 */
class uiMidiTimedItem : public uiMidi, public uiTimedItem {
    
    public:
        
        uiMidiTimedItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true, int chan = 0)
            :uiMidi(midi_out, input, chan), uiTimedItem(ui, zone)
        {}
        virtual ~uiMidiTimedItem()
        {}
    
        virtual void reflectZone() {}
    
};

/**
 * MIDI sync.
 */
class uiMidiStart : public uiMidiTimedItem
{
  
    public:
    
        uiMidiStart(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStart()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->startSync(0);
            }
        }
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(v));
            }
        }
        
};

class uiMidiStop : public uiMidiTimedItem {
  
    public:
    
        uiMidiStop(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStop()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(1)) {
                fMidiOut->stopSync(0);
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(v));
            }
        }
};

class uiMidiClock : public uiMidiTimedItem {

    private:
        
        bool fState;
  
    public:
    
        uiMidiClock(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fState(false)
        {}
        virtual ~uiMidiClock()
        {}
    
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->clock(0);
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                fState = !fState;
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fState));
            }
        }

};

/**
 * Standard MIDI events.
 */

/**
 * uiMidiProgChange uses the [min...max] range.
 */
class uiMidiProgChange : public uiMidiTimedItem {
    
    public:
    
        FAUSTFLOAT fMin, fMax;
    
        uiMidiProgChange(midi* midi_out, GUI* ui, FAUSTFLOAT* zone,
                         FAUSTFLOAT min, FAUSTFLOAT max,
                         bool input = true, int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan), fMin(min), fMax(max)
        {}
        virtual ~uiMidiProgChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (inRange(fMin, fMax, v)) {
                if (fChan == 0) {
                    // Send on [0..15] channels on the MIDI layer
                    for (int chan = 0; chan < 16; chan++) {
                        fMidiOut->progChange(chan, v);
                    }
                } else {
                    fMidiOut->progChange(fChan - 1, v);
                }
            }
        }
    
        void modifyZone(FAUSTFLOAT v)
        {
            if (fInputCtrl && inRange(fMin, fMax, v)) {
                uiItem::modifyZone(v);
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl && inRange(fMin, fMax, v)) {
                uiMidiTimedItem::modifyZone(date, v);
            }
        }
        
};

/**
 * uiMidiChanPress.
 */
class uiMidiChanPress : public uiMidiTimedItem, public uiConverter {
    
    public:
    
        uiMidiChanPress(midi* midi_out, GUI* ui,
                        FAUSTFLOAT* zone,
                        FAUSTFLOAT min, FAUSTFLOAT max,
                        bool input = true,
                        MetaDataUI::Scale scale = MetaDataUI::kLin,
                        int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan), uiConverter(scale, 0., 127., min, max)
        {}
        virtual ~uiMidiChanPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (fChan == 0) {
                // Send on [0..15] channels on the MIDI layer
                for (int chan = 0; chan < 16; chan++) {
                    fMidiOut->chanPress(chan, fConverter->faust2ui(v));
                }
            } else {
                fMidiOut->chanPress(fChan - 1, fConverter->faust2ui(v));
            }
        }
    
        void modifyZone(FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
        
};

/**
 * uiMidiCtrlChange does scale (kLin/kLog/kExp) mapping.
 */
class uiMidiCtrlChange : public uiMidiTimedItem, public uiConverter {
    
    private:
    
        int fCtrl;
 
    public:

        uiMidiCtrlChange(midi* midi_out, int ctrl, GUI* ui,
                     FAUSTFLOAT* zone,
                     FAUSTFLOAT min, FAUSTFLOAT max,
                     bool input = true,
                     MetaDataUI::Scale scale = MetaDataUI::kLin,
                     int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan), uiConverter(scale, 0., 127., min, max), fCtrl(ctrl)
        {}
        virtual ~uiMidiCtrlChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (fChan == 0) {
                // Send on [0..15] channels on the MIDI layer
                for (int chan = 0; chan < 16; chan++) {
                    fMidiOut->ctrlChange(chan, fCtrl, fConverter->faust2ui(v));
                }
            } else {
                fMidiOut->ctrlChange(fChan - 1, fCtrl, fConverter->faust2ui(v));
            }
        }
        
        void modifyZone(FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
};

class uiMidiPitchWheel : public uiMidiTimedItem {

    private:
    
        LinearValueConverter2 fConverter;
    
    public:
    
        uiMidiPitchWheel(midi* midi_out, GUI* ui, FAUSTFLOAT* zone,
                         FAUSTFLOAT min, FAUSTFLOAT max,
                         bool input = true, int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan)
        {
            if (min <= 0 && max >= 0) {
                fConverter = LinearValueConverter2(0., 8191., 16383., double(min), 0., double(max));
            } else {
                // Degenerated case...
                fConverter = LinearValueConverter2(0., 8191., 16383., double(min),double(min + (max - min)/FAUSTFLOAT(2)), double(max));
            }
        }
    
        virtual ~uiMidiPitchWheel()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (fChan == 0) {
                // Send on [0..15] channels on the MIDI layer
                for (int chan = 0; chan < 16; chan++) {
                    fMidiOut->pitchWheel(chan, fConverter.faust2ui(v));
                }
            } else {
                fMidiOut->pitchWheel(fChan - 1, fConverter.faust2ui(v));
            }
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
        void setRange(int val)
        {
            double semi = (val / 128) + ((val % 128) / 100.);
            fConverter.setMappingValues(0., 8191., 16383., -semi, 0., semi);
        }
 
};

/**
 * uiMidiKeyOn does scale (kLin/kLog/kExp) mapping for velocity.
 */
class uiMidiKeyOn : public uiMidiTimedItem, public uiConverter {

    private:
        
        int fKeyOn;
  
    public:
    
        uiMidiKeyOn(midi* midi_out, int key, GUI* ui,
                    FAUSTFLOAT* zone,
                    FAUSTFLOAT min, FAUSTFLOAT max,
                    bool input = true,
                    MetaDataUI::Scale scale = MetaDataUI::kLin,
                    int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan), uiConverter(scale, 0., 127., min, max), fKeyOn(key)
        {}
        virtual ~uiMidiKeyOn()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (fChan == 0) {
                // Send on [0..15] channels on the MIDI layer
                for (int chan = 0; chan < 16; chan++) {
                    fMidiOut->keyOn(chan, fKeyOn, fConverter->faust2ui(v));
                }
            } else {
                fMidiOut->keyOn(fChan - 1, fKeyOn, fConverter->faust2ui(v));
            }
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
};

/**
 * uiMidiKeyOff does scale (kLin/kLog/kExp) mapping for velocity.
 */
class uiMidiKeyOff : public uiMidiTimedItem, public uiConverter {

    private:
        
        int fKeyOff;
  
    public:
    
        uiMidiKeyOff(midi* midi_out, int key, GUI* ui,
                     FAUSTFLOAT* zone,
                     FAUSTFLOAT min, FAUSTFLOAT max,
                     bool input = true,
                     MetaDataUI::Scale scale = MetaDataUI::kLin,
                     int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan), uiConverter(scale, 0., 127., min, max), fKeyOff(key)
        {}
        virtual ~uiMidiKeyOff()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (fChan == 0) {
                // Send on [0..15] channels on the MIDI layer
                for (int chan = 0; chan < 16; chan++) {
                    fMidiOut->keyOn(chan, fKeyOff, fConverter->faust2ui(v));
                }
            } else {
                fMidiOut->keyOn(fChan - 1, fKeyOff, fConverter->faust2ui(v));
            }
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
};

/**
 * uiMidiKeyPress does scale (kLin/kLog/kExp) mapping for velocity.
 */
class uiMidiKeyPress : public uiMidiTimedItem, public uiConverter {

    private:
    
        int fKey;
  
    public:
    
        uiMidiKeyPress(midi* midi_out, int key, GUI* ui,
                       FAUSTFLOAT* zone,
                       FAUSTFLOAT min, FAUSTFLOAT max,
                       bool input = true,
                       MetaDataUI::Scale scale = MetaDataUI::kLin,
                       int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan), uiConverter(scale, 0., 127., min, max), fKey(key)
        {}
        virtual ~uiMidiKeyPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (fChan == 0) {
                // Send on [0..15] channels on the MIDI layer
                for (int chan = 0; chan < 16; chan++) {
                    fMidiOut->keyOn(chan, fKey, fConverter->faust2ui(v));
                }
            } else {
                fMidiOut->keyOn(fChan - 1, fKey, fConverter->faust2ui(v));
            }
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
};

/******************************************************************************************
 * MidiUI : Faust User Interface
 * This class decodes MIDI metadata and maps incoming MIDI messages to them.
 * Currently ctrlChange, keyOn/keyOff, keyPress, progChange, chanPress, pitchWheel/pitchBend
 * start/stop/clock meta data are handled.
 *
 * Maps associating MIDI event ID (like each ctrl number) with all MIDI aware UI items
 * are defined and progressively filled when decoding MIDI related metadata.
 * MIDI aware UI items are used in both directions:
 *  - modifying their internal state when receving MIDI input events
 *  - sending their internal state as MIDI output events
 *******************************************************************************************/

class MidiUI : public GUI, public midi, public midi_interface, public MetaDataUI {

    // Add uiItem subclasses objects are deallocated by the inherited GUI class
    typedef std::map <int, std::vector<uiMidiCtrlChange*> > TCtrlChangeTable;
    typedef std::vector<uiMidiProgChange*>                  TProgChangeTable;
    typedef std::vector<uiMidiChanPress*>                   TChanPressTable;
    typedef std::map <int, std::vector<uiMidiKeyOn*> >      TKeyOnTable;
    typedef std::map <int, std::vector<uiMidiKeyOff*> >     TKeyOffTable;
    typedef std::map <int, std::vector<uiMidiKeyPress*> >   TKeyPressTable;
    typedef std::vector<uiMidiPitchWheel*>                  TPitchWheelTable;
    
    protected:
    
        TCtrlChangeTable fCtrlChangeTable;
        TProgChangeTable fProgChangeTable;
        TChanPressTable  fChanPressTable;
        TKeyOnTable      fKeyOnTable;
        TKeyOffTable     fKeyOffTable;
        TKeyOnTable      fKeyTable;
        TKeyPressTable   fKeyPressTable;
        TPitchWheelTable fPitchWheelTable;
        
        std::vector<uiMidiStart*> fStartTable;
        std::vector<uiMidiStop*>  fStopTable;
        std::vector<uiMidiClock*> fClockTable;
        
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        
        midi_handler* fMidiHandler;
        bool fDelete;
        bool fTimeStamp;
    
        void addGenericZone(FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
        {
            if (fMetaAux.size() > 0) {
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    unsigned num;
                    unsigned chan;
                    if (fMetaAux[i].first == "midi") {
                        if (gsscanf(fMetaAux[i].second.c_str(), "ctrl %u %u", &num, &chan) == 2) {
                            fCtrlChangeTable[num].push_back(new uiMidiCtrlChange(fMidiHandler, num, this, zone, min, max, input, getScale(zone), chan));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "ctrl %u", &num) == 1) {
                            fCtrlChangeTable[num].push_back(new uiMidiCtrlChange(fMidiHandler, num, this, zone, min, max, input, getScale(zone)));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyon %u %u", &num, &chan) == 2) {
                            fKeyOnTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input, getScale(zone), chan));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyon %u", &num) == 1) {
                            fKeyOnTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input, getScale(zone)));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyoff %u %u", &num, &chan) == 2) {
                            fKeyOffTable[num].push_back(new uiMidiKeyOff(fMidiHandler, num, this, zone, min, max, input, getScale(zone), chan));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyoff %u", &num) == 1) {
                            fKeyOffTable[num].push_back(new uiMidiKeyOff(fMidiHandler, num, this, zone, min, max, input, getScale(zone)));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "key %u %u", &num, &chan) == 2) {
                            fKeyTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input, getScale(zone), chan));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "key %u", &num) == 1) {
                            fKeyTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input, getScale(zone)));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keypress %u %u", &num, &chan) == 2) {
                            fKeyPressTable[num].push_back(new uiMidiKeyPress(fMidiHandler, num, this, zone, min, max, input, getScale(zone), chan));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keypress %u", &num) == 1) {
                            fKeyPressTable[num].push_back(new uiMidiKeyPress(fMidiHandler, num, this, zone, min, max, input, getScale(zone)));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "pgm %u", &chan) == 1) {
                            fProgChangeTable.push_back(new uiMidiProgChange(fMidiHandler, this, zone, min, max, input, chan));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "pgm") == 0) {
                            fProgChangeTable.push_back(new uiMidiProgChange(fMidiHandler, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "chanpress %u", &chan) == 1) {
                            fChanPressTable.push_back(new uiMidiChanPress(fMidiHandler, this, zone, min, max, input, getScale(zone), chan));
                        } else if ((fMetaAux[i].second == "chanpress")) {
                            fChanPressTable.push_back(new uiMidiChanPress(fMidiHandler, this, zone, min, max, input, getScale(zone)));
                        } else if ((gsscanf(fMetaAux[i].second.c_str(), "pitchwheel %u", &chan) == 1) || (gsscanf(fMetaAux[i].second.c_str(), "pitchbend %u", &chan) == 1)) {
                            fPitchWheelTable.push_back(new uiMidiPitchWheel(fMidiHandler, this, zone, min, max, input, chan));
                        } else if ((fMetaAux[i].second == "pitchwheel") || (fMetaAux[i].second == "pitchbend")) {
                            fPitchWheelTable.push_back(new uiMidiPitchWheel(fMidiHandler, this, zone, min, max, input));
                        // MIDI sync
                        } else if (fMetaAux[i].second == "start") {
                            fStartTable.push_back(new uiMidiStart(fMidiHandler, this, zone, input));
                        } else if (fMetaAux[i].second == "stop") {
                            fStopTable.push_back(new uiMidiStop(fMidiHandler, this, zone, input));
                        } else if (fMetaAux[i].second == "clock") {
                            fClockTable.push_back(new uiMidiClock(fMidiHandler, this, zone, input));
                        // Explicit metadata to activate 'timestamp' mode
                        } else if (fMetaAux[i].second == "timestamp") {
                            fTimeStamp = true;
                        }
                    }
                }
            }
            fMetaAux.clear();
        }
    
        template <typename TABLE>
        void updateTable1(TABLE& table, double date, int channel, int val1)
        {
            for (size_t i = 0; i < table.size(); i++) {
                int channel_aux = table[i]->fChan;
                // channel_aux == 0 means "all channels"
                if (channel_aux == 0 || channel == channel_aux - 1) {
                    if (fTimeStamp) {
                        table[i]->modifyZone(date, FAUSTFLOAT(val1));
                    } else {
                        table[i]->modifyZone(FAUSTFLOAT(val1));
                    }
                }
            }
        }
        
        template <typename TABLE>
        void updateTable2(TABLE& table, double date, int channel, int val1, int val2)
        {
            if (table.find(val1) != table.end()) {
                for (size_t i = 0; i < table[val1].size(); i++) {
                    int channel_aux = table[val1][i]->fChan;
                    // channel_aux == 0 means "all channels"
                    if (channel_aux == 0 || channel == channel_aux - 1) {
                        if (fTimeStamp) {
                            table[val1][i]->modifyZone(date, FAUSTFLOAT(val2));
                        } else {
                            table[val1][i]->modifyZone(FAUSTFLOAT(val2));
                        }
                    }
                }
            }
        }
    
    public:
    
        MidiUI(midi_handler* midi_handler, bool delete_handler = false)
        {
            fMidiHandler = midi_handler;
            fMidiHandler->addMidiIn(this);
            // TODO: use shared_ptr based implementation
            fDelete = delete_handler;
            fTimeStamp = false;
        }
 
        virtual ~MidiUI() 
        {
            // Remove from fMidiHandler
            fMidiHandler->removeMidiIn(this);
            // TODO: use shared_ptr based implementation
            if (fDelete) delete fMidiHandler;
        }
    
        bool run() { return fMidiHandler->startMidi(); }
        void stop() { fMidiHandler->stopMidi(); }
        
        void addMidiIn(midi* midi_dsp) { fMidiHandler->addMidiIn(midi_dsp); }
        void removeMidiIn(midi* midi_dsp) { fMidiHandler->removeMidiIn(midi_dsp); }
      
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            addGenericZone(zone, min, max, false);
        }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addGenericZone(zone, min, max, false);
        }

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            MetaDataUI::declare(zone, key, val);
            fMetaAux.push_back(std::make_pair(key, val));
        }
        
        // -- MIDI API
    
        void key(double date, int channel, int note, int velocity)
        {
            updateTable2<TKeyOnTable>(fKeyTable, date, channel, note, velocity);
        }
    
        MapUI* keyOn(double date, int channel, int note, int velocity)
        {
            updateTable2<TKeyOnTable>(fKeyOnTable, date, channel, note, velocity);
            // If note is in fKeyTable, handle it as a keyOn
            key(date, channel, note, velocity);
            return nullptr;
        }
        
        void keyOff(double date, int channel, int note, int velocity)
        {
            updateTable2<TKeyOffTable>(fKeyOffTable, date, channel, note, velocity);
            // If note is in fKeyTable, handle it as a keyOff with a 0 velocity
            key(date, channel, note, 0);
        }
        
        void ctrlChange(double date, int channel, int ctrl, int value)
        {
            updateTable2<TCtrlChangeTable>(fCtrlChangeTable, date, channel, ctrl, value);
        }
    
        void rpn(double date, int channel, int ctrl, int value)
        {
            if (ctrl == midi::PITCH_BEND_RANGE) {
                for (size_t i = 0; i < fPitchWheelTable.size(); i++) {
                    // channel_aux == 0 means "all channels"
                    int channel_aux = fPitchWheelTable[i]->fChan;
                    if (channel_aux == 0 || channel == channel_aux - 1) {
                        fPitchWheelTable[i]->setRange(value);
                    }
                }
            }
        }
    
        void progChange(double date, int channel, int pgm)
        {
            updateTable1<TProgChangeTable>(fProgChangeTable, date, channel, pgm);
        }
        
        void pitchWheel(double date, int channel, int wheel) 
        {
            updateTable1<TPitchWheelTable>(fPitchWheelTable, date, channel, wheel);
        }
        
        void keyPress(double date, int channel, int pitch, int press) 
        {
            updateTable2<TKeyPressTable>(fKeyPressTable, date, channel, pitch, press);
        }
        
        void chanPress(double date, int channel, int press)
        {
            updateTable1<TChanPressTable>(fChanPressTable, date, channel, press);
        }
        
        void ctrlChange14bits(double date, int channel, int ctrl, int value) {}
        
        // MIDI sync
        
        void startSync(double date)
        {
            for (size_t i = 0; i < fStartTable.size(); i++) {
                fStartTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
        
        void stopSync(double date)
        {
            for (size_t i = 0; i < fStopTable.size(); i++) {
                fStopTable[i]->modifyZone(date, FAUSTFLOAT(0));
            }
        }
        
        void clock(double date)
        {
            for (size_t i = 0; i < fClockTable.size(); i++) {
                fClockTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
};

#endif // FAUST_MIDIUI_H
/**************************  END  MidiUI.h **************************/
/************************** BEGIN poly-base_dsp.h *************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
*********************************************************************/

#ifndef __poly_dsp__
#define __poly_dsp__

#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
#include <ostream>
#include <sstream>
#include <vector>
#include <limits.h>
#include <float.h>
#include <assert.h>

/************************** BEGIN base_dsp-combiner.h **************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
************************************************************************/

#ifndef __dsp_combiner__
#define __dsp_combiner__

#include <string.h>
#include <string>
#include <assert.h>
#include <sstream>


// Base class and common code for binary combiners

enum Layout { kVerticalGroup, kHorizontalGroup, kTabGroup };

class dsp_binary_combiner : public base_dsp {

    protected:

        base_dsp* fDSP1;
        base_dsp* fDSP2;
        int fBufferSize;
        Layout fLayout;
        std::string fLabel;

        void buildUserInterfaceAux(UI* ui_interface)
        {
            switch (fLayout) {
                case kHorizontalGroup:
                    ui_interface->openHorizontalBox(fLabel.c_str());
                    fDSP1->buildUserInterface(ui_interface);
                    fDSP2->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    break;
                case kVerticalGroup:
                    ui_interface->openVerticalBox(fLabel.c_str());
                    fDSP1->buildUserInterface(ui_interface);
                    fDSP2->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    break;
                case kTabGroup:
                    ui_interface->openTabBox(fLabel.c_str());
                    ui_interface->openVerticalBox("DSP1");
                    fDSP1->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    ui_interface->openVerticalBox("DSP2");
                    fDSP2->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    ui_interface->closeBox();
                    break;
            }
        }

        FAUSTFLOAT** allocateChannels(int num)
        {
            FAUSTFLOAT** channels = new FAUSTFLOAT*[num];
            for (int chan = 0; chan < num; chan++) {
                channels[chan] = new FAUSTFLOAT[fBufferSize];
                memset(channels[chan], 0, sizeof(FAUSTFLOAT) * fBufferSize);
            }
            return channels;
        }

        void deleteChannels(FAUSTFLOAT** channels, int num)
        {
            for (int chan = 0; chan < num; chan++) {
                delete [] channels[chan];
            }
            delete [] channels;
        }

     public:

        dsp_binary_combiner(base_dsp* dsp1, base_dsp* dsp2, int buffer_size, Layout layout, const std::string& label)
        :fDSP1(dsp1), fDSP2(dsp2), fBufferSize(buffer_size), fLayout(layout), fLabel(label)
        {}

        virtual ~dsp_binary_combiner()
        {
            delete fDSP1;
            delete fDSP2;
        }

        virtual int getSampleRate()
        {
            return fDSP1->getSampleRate();
        }
        virtual void init(int sample_rate)
        {
            fDSP1->init(sample_rate);
            fDSP2->init(sample_rate);
        }
        virtual void instanceInit(int sample_rate)
        {
            fDSP1->instanceInit(sample_rate);
            fDSP2->instanceInit(sample_rate);
        }
        virtual void instanceConstants(int sample_rate)
        {
            fDSP1->instanceConstants(sample_rate);
            fDSP2->instanceConstants(sample_rate);
        }

        virtual void instanceResetUserInterface()
        {
            fDSP1->instanceResetUserInterface();
            fDSP2->instanceResetUserInterface();
        }

        virtual void instanceClear()
        {
            fDSP1->instanceClear();
            fDSP2->instanceClear();
        }

        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }

};

// Combine two 'compatible' DSP in sequence

class dsp_sequencer : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Outputs;

    public:

        dsp_sequencer(base_dsp* dsp1, base_dsp* dsp2,
                      int buffer_size = 4096,
                      Layout layout = Layout::kTabGroup,
                      const std::string& label = "Sequencer")
        :dsp_binary_combiner(dsp1, dsp2, buffer_size, layout, label)
        {
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs());
        }

        virtual ~dsp_sequencer()
        {
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface);
        }

        virtual base_dsp* clone()
        {
            return new dsp_sequencer(fDSP1->clone(), fDSP2->clone(), fBufferSize, fLayout, fLabel);
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, fDSP1Outputs);
            fDSP2->compute(count, fDSP1Outputs, outputs);
        }

        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }

};

// Combine two DSP in parallel

class dsp_parallelizer : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP2Inputs;
        FAUSTFLOAT** fDSP2Outputs;

    public:

        dsp_parallelizer(base_dsp* dsp1, base_dsp* dsp2,
                     int buffer_size = 4096,
                     Layout layout = Layout::kTabGroup,
                     const std::string& label = "Parallelizer")
        :dsp_binary_combiner(dsp1, dsp2, buffer_size, layout, label)
        {
            fDSP2Inputs = new FAUSTFLOAT*[fDSP2->getNumInputs()];
            fDSP2Outputs = new FAUSTFLOAT*[fDSP2->getNumOutputs()];
        }

        virtual ~dsp_parallelizer()
        {
            delete [] fDSP2Inputs;
            delete [] fDSP2Outputs;
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs() + fDSP2->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs() + fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface);
        }

        virtual base_dsp* clone()
        {
            return new dsp_parallelizer(fDSP1->clone(), fDSP2->clone(), fBufferSize, fLayout, fLabel);
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, outputs);

            // Shift inputs/outputs channels for fDSP2
            for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                fDSP2Inputs[chan] = inputs[fDSP1->getNumInputs() + chan];
            }
            for (int chan = 0; chan < fDSP2->getNumOutputs(); chan++) {
                fDSP2Outputs[chan] = outputs[fDSP1->getNumOutputs() + chan];
            }

            fDSP2->compute(count, fDSP2Inputs, fDSP2Outputs);
        }

        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }

};

// Combine two 'compatible' DSP in splitter

class dsp_splitter : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Outputs;
        FAUSTFLOAT** fDSP2Inputs;

    public:

        dsp_splitter(base_dsp* dsp1, base_dsp* dsp2,
                     int buffer_size = 4096,
                     Layout layout = Layout::kTabGroup,
                     const std::string& label = "Splitter")
        :dsp_binary_combiner(dsp1, dsp2, buffer_size, layout, label)
        {
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs());
            fDSP2Inputs = new FAUSTFLOAT*[fDSP2->getNumInputs()];
        }

        virtual ~dsp_splitter()
        {
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
            delete [] fDSP2Inputs;
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface);
        }

        virtual base_dsp* clone()
        {
            return new dsp_splitter(fDSP1->clone(), fDSP2->clone(), fBufferSize, fLayout, fLabel);
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, fDSP1Outputs);

            for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                 fDSP2Inputs[chan] = fDSP1Outputs[chan % fDSP1->getNumOutputs()];
            }

            fDSP2->compute(count, fDSP2Inputs, outputs);
        }
};

// Combine two 'compatible' DSP in merger

class dsp_merger : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Inputs;
        FAUSTFLOAT** fDSP1Outputs;
        FAUSTFLOAT** fDSP2Inputs;

        void mix(int count, FAUSTFLOAT* dst, FAUSTFLOAT* src)
        {
            for (int frame = 0; frame < count; frame++) {
                dst[frame] += src[frame];
            }
        }

    public:

        dsp_merger(base_dsp* dsp1, base_dsp* dsp2,
                   int buffer_size = 4096,
                   Layout layout = Layout::kTabGroup,
                   const std::string& label = "Merger")
        :dsp_binary_combiner(dsp1, dsp2, buffer_size, layout, label)
        {
            fDSP1Inputs = allocateChannels(fDSP1->getNumInputs());
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs());
            fDSP2Inputs = new FAUSTFLOAT*[fDSP2->getNumInputs()];
        }

        virtual ~dsp_merger()
        {
            deleteChannels(fDSP1Inputs, fDSP1->getNumInputs());
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
            delete [] fDSP2Inputs;
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface);
        }

        virtual base_dsp* clone()
        {
            return new dsp_merger(fDSP1->clone(), fDSP2->clone(), fBufferSize, fLayout, fLabel);
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, fDSP1Inputs, fDSP1Outputs);

            memset(fDSP2Inputs, 0, sizeof(FAUSTFLOAT*) * fDSP2->getNumInputs());

            for (int chan = 0; chan < fDSP1->getNumOutputs(); chan++) {
                int mchan = chan % fDSP2->getNumInputs();
                if (fDSP2Inputs[mchan]) {
                    mix(count, fDSP2Inputs[mchan], fDSP1Outputs[chan]);
                } else {
                    fDSP2Inputs[mchan] = fDSP1Outputs[chan];
                }
            }

            fDSP2->compute(count, fDSP2Inputs, outputs);
        }
};

// Combine two 'compatible' DSP in a recursive way

class dsp_recursiver : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Inputs;
        FAUSTFLOAT** fDSP1Outputs;

        FAUSTFLOAT** fDSP2Inputs;
        FAUSTFLOAT** fDSP2Outputs;

    public:

        dsp_recursiver(base_dsp* dsp1, base_dsp* dsp2,
                       Layout layout = Layout::kTabGroup,
                       const std::string& label = "Recursiver")
        :dsp_binary_combiner(dsp1, dsp2, 1, layout, label)
        {
            fDSP1Inputs = allocateChannels(fDSP1->getNumInputs());
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs());
            fDSP2Inputs = allocateChannels(fDSP2->getNumInputs());
            fDSP2Outputs = allocateChannels(fDSP2->getNumOutputs());
        }

        virtual ~dsp_recursiver()
        {
            deleteChannels(fDSP1Inputs, fDSP1->getNumInputs());
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
            deleteChannels(fDSP2Inputs, fDSP2->getNumInputs());
            deleteChannels(fDSP2Outputs, fDSP2->getNumOutputs());
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs() - fDSP2->getNumOutputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface);
        }

        virtual base_dsp* clone()
        {
            return new dsp_recursiver(fDSP1->clone(), fDSP2->clone(), fLayout, fLabel);
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            for (int frame = 0; (frame < count); frame++) {

                for (int chan = 0; chan < fDSP2->getNumOutputs(); chan++) {
                    fDSP1Inputs[chan][0] = fDSP2Outputs[chan][0];
                }

                for (int chan = 0; chan < fDSP1->getNumInputs() - fDSP2->getNumOutputs(); chan++) {
                    fDSP1Inputs[chan + fDSP2->getNumOutputs()][0] = inputs[chan][frame];
                }

                fDSP1->compute(1, fDSP1Inputs, fDSP1Outputs);

                for (int chan = 0; chan < fDSP1->getNumOutputs(); chan++) {
                    outputs[chan][frame] = fDSP1Outputs[chan][0];
                }

                for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                    fDSP2Inputs[chan][0] = fDSP1Outputs[chan][0];
                }

                fDSP2->compute(1, fDSP2Inputs, fDSP2Outputs);
            }
        }

        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }

};

/*
 Crossfade between two DSP.
 When fCrossfade = 1, the first DSP only is computed, when fCrossfade = 0,
 the second DSP only is computed, otherwise both DSPs are computed and mixed.
*/

class dsp_crossfader: public dsp_binary_combiner {

    private:
    
        FAUSTFLOAT fCrossfade;
        FAUSTFLOAT** fDSPOutputs1;
        FAUSTFLOAT** fDSPOutputs2;
    
    public:
    
        dsp_crossfader(base_dsp* dsp1, base_dsp* dsp2,
                       Layout layout = Layout::kTabGroup,
                       const std::string& label = "Crossfade")
        :dsp_binary_combiner(dsp1, dsp2, 4096, layout, label),fCrossfade(FAUSTFLOAT(0.5))
        {
            fDSPOutputs1 = allocateChannels(fDSP1->getNumOutputs());
            fDSPOutputs2 = allocateChannels(fDSP1->getNumOutputs());
        }
    
        virtual ~dsp_crossfader()
        {
            deleteChannels(fDSPOutputs1, fDSP1->getNumInputs());
            deleteChannels(fDSPOutputs2, fDSP1->getNumOutputs());
        }
    
        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs(); }

        void buildUserInterface(UI* ui_interface)
        {
            switch (fLayout) {
                case kHorizontalGroup:
                    ui_interface->openHorizontalBox(fLabel.c_str());
                    ui_interface->addHorizontalSlider("Crossfade", &fCrossfade, FAUSTFLOAT(0.5), FAUSTFLOAT(0), FAUSTFLOAT(1), FAUSTFLOAT(0.01));
                    fDSP1->buildUserInterface(ui_interface);
                    fDSP2->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    break;
                case kVerticalGroup:
                    ui_interface->openVerticalBox(fLabel.c_str());
                    ui_interface->addHorizontalSlider("Crossfade", &fCrossfade, FAUSTFLOAT(0.5), FAUSTFLOAT(0), FAUSTFLOAT(1), FAUSTFLOAT(0.01));
                    fDSP1->buildUserInterface(ui_interface);
                    fDSP2->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    break;
                case kTabGroup:
                    ui_interface->openTabBox(fLabel.c_str());
                    ui_interface->openVerticalBox("Crossfade");
                    ui_interface->addHorizontalSlider("Crossfade", &fCrossfade, FAUSTFLOAT(0.5), FAUSTFLOAT(0), FAUSTFLOAT(1), FAUSTFLOAT(0.01));
                    ui_interface->closeBox();
                    ui_interface->openVerticalBox("DSP1");
                    fDSP1->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    ui_interface->openVerticalBox("DSP2");
                    fDSP2->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    ui_interface->closeBox();
                    break;
            }
        }
    
        virtual base_dsp* clone()
        {
            return new dsp_crossfader(fDSP1->clone(), fDSP2->clone(), fLayout, fLabel);
        }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            if (fCrossfade == FAUSTFLOAT(1)) {
                fDSP1->compute(count, inputs, outputs);
            } else if (fCrossfade == FAUSTFLOAT(0)) {
                fDSP2->compute(count, inputs, outputs);
            } else {
                // Compute each effect
                fDSP1->compute(count, inputs, fDSPOutputs1);
                fDSP2->compute(count, inputs, fDSPOutputs2);
                // Mix between the two effects
                FAUSTFLOAT gain1 = fCrossfade;
                FAUSTFLOAT gain2 = FAUSTFLOAT(1) - gain1;
                for (int frame = 0; (frame < count); frame++) {
                    for (int chan = 0; chan < fDSP1->getNumOutputs(); chan++) {
                        outputs[chan][frame] = fDSPOutputs1[chan][frame] * gain1 + fDSPOutputs2[chan][frame] * gain2;
                    }
                }
            }
        }
    
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

#ifndef __dsp_algebra_api__
#define __dsp_algebra_api__

// DSP algebra API
/*
 Each operation takes two DSP and a optional Layout and Label parameters, returns the combined DSPs, or null if failure with an error message.
 */

static base_dsp* createDSPSequencer(base_dsp* dsp1, base_dsp* dsp2,
                               std::string& error,
                               Layout layout = Layout::kTabGroup,
                               const std::string& label = "Sequencer")
{
    if (dsp1->getNumOutputs() != dsp2->getNumInputs()) {
        std::stringstream error_aux;
        error_aux << "Connection error in dsp_sequencer : the number of outputs ("
                  << dsp1->getNumOutputs() << ") of A "
                  << "must be equal to the number of inputs (" << dsp2->getNumInputs() << ") of B" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else {
        return new dsp_sequencer(dsp1, dsp2, 4096, layout, label);
    }
}

static base_dsp* createDSPParallelizer(base_dsp* dsp1, base_dsp* dsp2,
                                  std::string& error,
                                  Layout layout = Layout::kTabGroup,
                                  const std::string& label = "Parallelizer")
{
    return new dsp_parallelizer(dsp1, dsp2, 4096, layout, label);
}

static base_dsp* createDSPSplitter(base_dsp* dsp1, base_dsp* dsp2, std::string& error, Layout layout = Layout::kTabGroup, const std::string& label = "Splitter")
{
    if (dsp1->getNumOutputs() == 0) {
        error = "Connection error in dsp_splitter : the first expression has no outputs\n";
        return nullptr;
    } else if (dsp2->getNumInputs() == 0) {
        error = "Connection error in dsp_splitter : the second expression has no inputs\n";
        return nullptr;
    } else if (dsp2->getNumInputs() % dsp1->getNumOutputs() != 0) {
        std::stringstream error_aux;
        error_aux << "Connection error in dsp_splitter : the number of outputs (" << dsp1->getNumOutputs()
                  << ") of the first expression should be a divisor of the number of inputs ("
                  << dsp2->getNumInputs()
                  << ") of the second expression" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else if (dsp2->getNumInputs() == dsp1->getNumOutputs()) {
        return new dsp_sequencer(dsp1, dsp2, 4096, layout, label);
    } else {
        return new dsp_splitter(dsp1, dsp2, 4096, layout, label);
    }
}

static base_dsp* createDSPMerger(base_dsp* dsp1, base_dsp* dsp2,
                            std::string& error,
                            Layout layout = Layout::kTabGroup,
                            const std::string& label = "Merger")
{
    if (dsp1->getNumOutputs() == 0) {
        error = "Connection error in dsp_merger : the first expression has no outputs\n";
        return nullptr;
    } else if (dsp2->getNumInputs() == 0) {
        error = "Connection error in dsp_merger : the second expression has no inputs\n";
        return nullptr;
    } else if (dsp1->getNumOutputs() % dsp2->getNumInputs() != 0) {
        std::stringstream error_aux;
        error_aux << "Connection error in dsp_merger : the number of outputs (" << dsp1->getNumOutputs()
                  << ") of the first expression should be a multiple of the number of inputs ("
                  << dsp2->getNumInputs()
                  << ") of the second expression" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else if (dsp2->getNumInputs() == dsp1->getNumOutputs()) {
        return new dsp_sequencer(dsp1, dsp2, 4096, layout, label);
    } else {
        return new dsp_merger(dsp1, dsp2, 4096, layout, label);
    }
}

static base_dsp* createDSPRecursiver(base_dsp* dsp1, base_dsp* dsp2,
                                std::string& error,
                                Layout layout = Layout::kTabGroup,
                                const std::string& label = "Recursiver")
{
    if ((dsp2->getNumInputs() > dsp1->getNumOutputs()) || (dsp2->getNumOutputs() > dsp1->getNumInputs())) {
        std::stringstream error_aux;
        error_aux << "Connection error in : dsp_recursiver" << std::endl;
        if (dsp2->getNumInputs() > dsp1->getNumOutputs()) {
            error_aux << "The number of outputs " << dsp1->getNumOutputs()
                      << " of the first expression should be greater or equal to the number of inputs ("
                      << dsp2->getNumInputs()
                      << ") of the second expression" << std::endl;
        }
        if (dsp2->getNumOutputs() > dsp1->getNumInputs()) {
            error_aux << "The number of inputs " << dsp1->getNumInputs()
                      << " of the first expression should be greater or equal to the number of outputs ("
                      << dsp2->getNumOutputs()
                      << ") of the second expression" << std::endl;
        }
        error = error_aux.str();
        return nullptr;
    } else {
        return new dsp_recursiver(dsp1, dsp2, layout, label);
    }
}

static base_dsp* createDSPCrossfader(base_dsp* dsp1, base_dsp* dsp2,
                                 std::string& error,
                                 Layout layout = Layout::kTabGroup,
                                 const std::string& label = "Crossfade")
{
    if (dsp1->getNumInputs() != dsp2->getNumInputs()) {
        std::stringstream error_aux;
        error_aux << "Connection error in dsp_crossfader : the number of inputs ("
        << dsp1->getNumInputs() << ") of A "
        << "must be equal to the number of inputs (" << dsp2->getNumInputs() << ") of B" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else if (dsp1->getNumOutputs() != dsp2->getNumOutputs()) {
        std::stringstream error_aux;
        error_aux << "Connection error in dsp_crossfader : the number of outputs ("
        << dsp1->getNumOutputs() << ") of A "
        << "must be equal to the number of outputs (" << dsp2->getNumOutputs() << ") of B" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else {
        return new dsp_crossfader(dsp1, dsp2, layout, label);
    }
}

#endif

#endif
/************************** END base_dsp-combiner.h **************************/
/************************** BEGIN proxy-base_dsp.h ***************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
***************************************************************************/

#ifndef __proxy_dsp__
#define __proxy_dsp__

#include <vector>
#include <map>

/************************** BEGIN JSONUIDecoder.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 *************************************************************************/

#ifndef __JSONUIDecoder__
#define __JSONUIDecoder__

#include <vector>
#include <map>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <functional>

/************************** BEGIN CGlue.h *****************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
*************************************************************************/

#ifndef CGLUE_H
#define CGLUE_H

/************************** BEGIN CInterface.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 *************************************************************************/

#ifndef CINTERFACE_H
#define CINTERFACE_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
    
struct Soundfile;

/*******************************************************************************
 * UI, Meta and MemoryManager structures for C code.
 ******************************************************************************/

// -- widget's layouts

typedef void (* openTabBoxFun) (void* ui_interface, const char* label);
typedef void (* openHorizontalBoxFun) (void* ui_interface, const char* label);
typedef void (* openVerticalBoxFun) (void* ui_interface, const char* label);
typedef void (* closeBoxFun) (void* ui_interface);

// -- active widgets

typedef void (* addButtonFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone);
typedef void (* addCheckButtonFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone);
typedef void (* addVerticalSliderFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step);
typedef void (* addHorizontalSliderFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step);
typedef void (* addNumEntryFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step);

// -- passive widgets

typedef void (* addHorizontalBargraphFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max);
typedef void (* addVerticalBargraphFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max);

// -- soundfiles
    
typedef void (* addSoundfileFun) (void* ui_interface, const char* label, const char* url, struct Soundfile** sf_zone);

typedef void (* declareFun) (void* ui_interface, FAUSTFLOAT* zone, const char* key, const char* value);

typedef struct {

    void* uiInterface;

    openTabBoxFun openTabBox;
    openHorizontalBoxFun openHorizontalBox;
    openVerticalBoxFun openVerticalBox;
    closeBoxFun closeBox;
    addButtonFun addButton;
    addCheckButtonFun addCheckButton;
    addVerticalSliderFun addVerticalSlider;
    addHorizontalSliderFun addHorizontalSlider;
    addNumEntryFun addNumEntry;
    addHorizontalBargraphFun addHorizontalBargraph;
    addVerticalBargraphFun addVerticalBargraph;
    addSoundfileFun addSoundfile;
    declareFun declare;

} UIGlue;

typedef void (* metaDeclareFun) (void* ui_interface, const char* key, const char* value);

typedef struct {

    void* metaInterface;
    
    metaDeclareFun declare;

} MetaGlue;

/***************************************
 *  Interface for the DSP object
 ***************************************/

typedef char dsp_imp;
    
typedef dsp_imp* (* newDspFun) ();
typedef void (* destroyDspFun) (dsp_imp* base_dsp);
typedef int (* getNumInputsFun) (dsp_imp* base_dsp);
typedef int (* getNumOutputsFun) (dsp_imp* base_dsp);
typedef void (* buildUserInterfaceFun) (dsp_imp* base_dsp, UIGlue* ui);
typedef int (* getSampleRateFun) (dsp_imp* base_dsp);
typedef void (* initFun) (dsp_imp* base_dsp, int sample_rate);
typedef void (* classInitFun) (int sample_rate);
typedef void (* instanceInitFun) (dsp_imp* base_dsp, int sample_rate);
typedef void (* instanceConstantsFun) (dsp_imp* base_dsp, int sample_rate);
typedef void (* instanceResetUserInterfaceFun) (dsp_imp* base_dsp);
typedef void (* instanceClearFun) (dsp_imp* base_dsp);
typedef void (* computeFun) (dsp_imp* base_dsp, int len, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs);
typedef void (* metadataFun) (MetaGlue* meta);
    
/***************************************
 * DSP memory manager functions
 ***************************************/

typedef void* (* allocateFun) (void* manager_interface, size_t size);
typedef void (* destroyFun) (void* manager_interface, void* ptr);

typedef struct {
    
    void* managerInterface;
    
    allocateFun allocate;
    destroyFun destroy;
    
} MemoryManagerGlue;

#ifdef __cplusplus
}
#endif

#endif
/**************************  END  CInterface.h **************************/

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * UI glue code
 ******************************************************************************/
 
class UIFloat
{

    public:

        UIFloat() {}

        virtual ~UIFloat() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, float* zone) = 0;
        virtual void addCheckButton(const char* label, float* zone) = 0;
        virtual void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
        virtual void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
        virtual void addNumEntry(const char* label, float* zone, float init, float min, float max, float step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, float* zone, float min, float max) = 0;
        virtual void addVerticalBargraph(const char* label, float* zone, float min, float max) = 0;
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;

        // -- metadata declarations

        virtual void declare(float* zone, const char* key, const char* val) {}
};

static void openTabBoxGlueFloat(void* cpp_interface, const char* label)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->openTabBox(label);
}

static void openHorizontalBoxGlueFloat(void* cpp_interface, const char* label)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->openHorizontalBox(label);
}

static void openVerticalBoxGlueFloat(void* cpp_interface, const char* label)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->openVerticalBox(label);
}

static void closeBoxGlueFloat(void* cpp_interface)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->closeBox();
}

static void addButtonGlueFloat(void* cpp_interface, const char* label, float* zone)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addButton(label, zone);
}

static void addCheckButtonGlueFloat(void* cpp_interface, const char* label, float* zone)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addCheckButton(label, zone);
}

static void addVerticalSliderGlueFloat(void* cpp_interface, const char* label, float* zone, float init, float min, float max, float step)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addVerticalSlider(label, zone, init, min, max, step);
}

static void addHorizontalSliderGlueFloat(void* cpp_interface, const char* label, float* zone, float init, float min, float max, float step)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addHorizontalSlider(label, zone, init, min, max, step);
}

static void addNumEntryGlueFloat(void* cpp_interface, const char* label, float* zone, float init, float min, float max, float step)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addNumEntry(label, zone, init, min, max, step);
}

static void addHorizontalBargraphGlueFloat(void* cpp_interface, const char* label, float* zone, float min, float max)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addHorizontalBargraph(label, zone, min, max);
}

static void addVerticalBargraphGlueFloat(void* cpp_interface, const char* label, float* zone, float min, float max)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addVerticalBargraph(label, zone, min, max);
}
    
static void addSoundfileGlueFloat(void* cpp_interface, const char* label, const char* url, Soundfile** sf_zone)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addSoundfile(label, url, sf_zone);
}

static void declareGlueFloat(void* cpp_interface, float* zone, const char* key, const char* value)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->declare(zone, key, value);
}

class UIDouble
{

    public:

        UIDouble() {}

        virtual ~UIDouble() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, double* zone) = 0;
        virtual void addCheckButton(const char* label, double* zone) = 0;
        virtual void addVerticalSlider(const char* label, double* zone, double init, double min, double max, double step) = 0;
        virtual void addHorizontalSlider(const char* label, double* zone, double init, double min, double max, double step) = 0;
        virtual void addNumEntry(const char* label, double* zone, double init, double min, double max, double step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, double* zone, double min, double max) = 0;
        virtual void addVerticalBargraph(const char* label, double* zone, double min, double max) = 0;
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;

        // -- metadata declarations

        virtual void declare(double* zone, const char* key, const char* val) {}
};

static void openTabBoxGlueDouble(void* cpp_interface, const char* label)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->openTabBox(label);
}

static void openHorizontalBoxGlueDouble(void* cpp_interface, const char* label)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->openHorizontalBox(label);
}

static void openVerticalBoxGlueDouble(void* cpp_interface, const char* label)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->openVerticalBox(label);
}

static void closeBoxGlueDouble(void* cpp_interface)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->closeBox();
}

static void addButtonGlueDouble(void* cpp_interface, const char* label, double* zone)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addButton(label, zone);
}

static void addCheckButtonGlueDouble(void* cpp_interface, const char* label, double* zone)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addCheckButton(label, zone);
}

static void addVerticalSliderGlueDouble(void* cpp_interface, const char* label, double* zone, double init, double min, double max, double step)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addVerticalSlider(label, zone, init, min, max, step);
}

static void addHorizontalSliderGlueDouble(void* cpp_interface, const char* label, double* zone, double init, double min, double max, double step)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addHorizontalSlider(label, zone, init, min, max, step);
}

static void addNumEntryGlueDouble(void* cpp_interface, const char* label, double* zone, double init, double min, double max, double step)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addNumEntry(label, zone, init, min, max, step);
}

static void addHorizontalBargraphGlueDouble(void* cpp_interface, const char* label, double* zone, double min, double max)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addHorizontalBargraph(label, zone, min, max);
}

static void addVerticalBargraphGlueDouble(void* cpp_interface, const char* label, double* zone, double min, double max)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addVerticalBargraph(label, zone, min, max);
}
    
static void addSoundfileGlueDouble(void* cpp_interface, const char* label, const char* url, Soundfile** sf_zone)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addSoundfile(label, url, sf_zone);
}

static void declareGlueDouble(void* cpp_interface, double* zone, const char* key, const char* value)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->declare(zone, key, value);
}

static void buildUIGlue(UIGlue* glue, UI* ui_interface, bool is_double)
{
    glue->uiInterface = ui_interface;
    
    if (is_double) {
        glue->openTabBox = reinterpret_cast<openTabBoxFun>(openTabBoxGlueDouble);
        glue->openHorizontalBox = reinterpret_cast<openHorizontalBoxFun>(openHorizontalBoxGlueDouble);
        glue->openVerticalBox = reinterpret_cast<openVerticalBoxFun>(openVerticalBoxGlueDouble);
        glue->closeBox = reinterpret_cast<closeBoxFun>(closeBoxGlueDouble);
        glue->addButton = reinterpret_cast<addButtonFun>(addButtonGlueDouble);
        glue->addCheckButton = reinterpret_cast<addCheckButtonFun>(addCheckButtonGlueDouble);
        glue->addVerticalSlider = reinterpret_cast<addVerticalSliderFun>(addVerticalSliderGlueDouble);
        glue->addHorizontalSlider = reinterpret_cast<addHorizontalSliderFun>(addHorizontalSliderGlueDouble);
        glue->addNumEntry = reinterpret_cast<addNumEntryFun>(addNumEntryGlueDouble);
        glue->addHorizontalBargraph = reinterpret_cast<addHorizontalBargraphFun>(addHorizontalBargraphGlueDouble);
        glue->addVerticalBargraph = reinterpret_cast<addVerticalBargraphFun>(addVerticalBargraphGlueDouble);
        glue->addSoundfile = reinterpret_cast<addSoundfileFun>(addSoundfileGlueDouble);
        glue->declare = reinterpret_cast<declareFun>(declareGlueDouble);
    } else {
        glue->openTabBox = reinterpret_cast<openTabBoxFun>(openTabBoxGlueFloat);
        glue->openHorizontalBox = reinterpret_cast<openHorizontalBoxFun>(openHorizontalBoxGlueFloat);
        glue->openVerticalBox = reinterpret_cast<openVerticalBoxFun>(openVerticalBoxGlueFloat);
        glue->closeBox = reinterpret_cast<closeBoxFun>(closeBoxGlueFloat);
        glue->addButton = reinterpret_cast<addButtonFun>(addButtonGlueFloat);
        glue->addCheckButton = reinterpret_cast<addCheckButtonFun>(addCheckButtonGlueFloat);
        glue->addVerticalSlider = reinterpret_cast<addVerticalSliderFun>(addVerticalSliderGlueFloat);
        glue->addHorizontalSlider = reinterpret_cast<addHorizontalSliderFun>(addHorizontalSliderGlueFloat);
        glue->addNumEntry = reinterpret_cast<addNumEntryFun>(addNumEntryGlueFloat);
        glue->addHorizontalBargraph = reinterpret_cast<addHorizontalBargraphFun>(addHorizontalBargraphGlueFloat);
        glue->addVerticalBargraph = reinterpret_cast<addVerticalBargraphFun>(addVerticalBargraphGlueFloat);
        glue->addSoundfile = reinterpret_cast<addSoundfileFun>(addSoundfileGlueFloat);
        glue->declare = reinterpret_cast<declareFun>(declareGlueFloat);
    }
}
    
// Base class
    
struct UIInterface
{
    virtual ~UIInterface() {}
    
    virtual int sizeOfFAUSTFLOAT() = 0;
    
    // -- widget's layouts
    
    virtual void openTabBox(const char* label) = 0;
    virtual void openHorizontalBox(const char* label) = 0;
    virtual void openVerticalBox(const char* label) = 0;
    virtual void closeBox() = 0;
    
    // float version
    
    // -- active widgets
    
    virtual void addButton(const char* label, float* zone) = 0;
    virtual void addCheckButton(const char* label, float* zone) = 0;
    
    virtual void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
    virtual void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
    virtual void addNumEntry(const char* label, float* zone, float init, float min, float max, float step) = 0;
    
    // -- passive widgets
    
    virtual void addHorizontalBargraph(const char* label, float* zone, float min, float max) = 0;
    virtual void addVerticalBargraph(const char* label, float* zone, float min, float max) = 0;
    
    // -- metadata declarations
    
    virtual void declare(float* zone, const char* key, const char* val) = 0;
    
    // double version
    
    virtual void addButton(const char* label, double* zone) = 0;
    virtual void addCheckButton(const char* label, double* zone) = 0;
  
    virtual void addVerticalSlider(const char* label, double* zone, double init, double min, double max, double step) = 0;
    virtual void addHorizontalSlider(const char* label, double* zone, double init, double min, double max, double step) = 0;
    
    virtual void addNumEntry(const char* label, double* zone, double init, double min, double max, double step) = 0;
    
    // -- soundfiles
    
    virtual void addSoundfile(const char* label, const char* url, Soundfile** sf_zone) = 0;
    
    // -- passive widgets
    
    virtual void addHorizontalBargraph(const char* label, double* zone, double min, double max) = 0;
    virtual void addVerticalBargraph(const char* label, double* zone, double min, double max) = 0;
     
    // -- metadata declarations
    
    virtual void declare(double* zone, const char* key, const char* val) = 0;
    
};
    
struct UITemplate : public UIInterface
{
 
    void* fCPPInterface;

    UITemplate(void* cpp_interface):fCPPInterface(cpp_interface)
    {}
    virtual ~UITemplate() {}
    
    int sizeOfFAUSTFLOAT()
    {
        return reinterpret_cast<UI*>(fCPPInterface)->sizeOfFAUSTFLOAT();
    }
    
    // -- widget's layouts
    
    void openTabBox(const char* label)
    {
        openTabBoxGlueFloat(fCPPInterface, label);
    }
    void openHorizontalBox(const char* label)
    {
        openHorizontalBoxGlueFloat(fCPPInterface, label);
    }
    void openVerticalBox(const char* label)
    {
        openVerticalBoxGlueFloat(fCPPInterface, label);
    }
    void closeBox()
    {
        closeBoxGlueFloat(fCPPInterface);
    }
    
    // float version
    
    // -- active widgets
    
    void addButton(const char* label, float* zone)
    {
        addButtonGlueFloat(fCPPInterface, label, zone);
    }
    void addCheckButton(const char* label, float* zone)
    {
        addCheckButtonGlueFloat(fCPPInterface, label, zone);
    }
    
    void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step)
    {
        addVerticalSliderGlueFloat(fCPPInterface, label, zone, init, min, max, step);
    }
    
    void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step)
    {
        addHorizontalSliderGlueFloat(fCPPInterface, label, zone, init, min, max, step);
    }
    
    void addNumEntry(const char* label, float* zone, float init, float min, float max, float step)
    {
        addNumEntryGlueFloat(fCPPInterface, label, zone, init, min, max, step);
    }
    
    // -- passive widgets
    
    void addHorizontalBargraph(const char* label, float* zone, float min, float max)
    {
        addHorizontalBargraphGlueFloat(fCPPInterface, label, zone, min, max);
    }
    
    void addVerticalBargraph(const char* label, float* zone, float min, float max)
    {
        addVerticalBargraphGlueFloat(fCPPInterface, label, zone, min, max);
    }

    // -- metadata declarations
    
    void declare(float* zone, const char* key, const char* val)
    {
        declareGlueFloat(fCPPInterface, zone, key, val);
    }
    
    // double version
    
    void addButton(const char* label, double* zone)
    {
        addButtonGlueDouble(fCPPInterface, label, zone);
    }
    void addCheckButton(const char* label, double* zone)
    {
        addCheckButtonGlueDouble(fCPPInterface, label, zone);
    }
    
    void addVerticalSlider(const char* label, double* zone, double init, double min, double max, double step)
    {
        addVerticalSliderGlueDouble(fCPPInterface, label, zone, init, min, max, step);
    }
    
    void addHorizontalSlider(const char* label, double* zone, double init, double min, double max, double step)
    {
        addHorizontalSliderGlueDouble(fCPPInterface, label, zone, init, min, max, step);
    }
    
    void addNumEntry(const char* label, double* zone, double init, double min, double max, double step)
    {
        addNumEntryGlueDouble(fCPPInterface, label, zone, init, min, max, step);
    }

    // -- soundfiles
    
    void addSoundfile(const char* label, const char* url, Soundfile** sf_zone)
    {
        addSoundfileGlueFloat(fCPPInterface, label, url, sf_zone);
    }

    // -- passive widgets
    
    void addHorizontalBargraph(const char* label, double* zone, double min, double max)
    {
        addHorizontalBargraphGlueDouble(fCPPInterface, label, zone, min, max);
    }
    
    void addVerticalBargraph(const char* label, double* zone, double min, double max)
    {
        addVerticalBargraphGlueDouble(fCPPInterface, label, zone, min, max);
    }

    // -- metadata declarations
    
    void declare(double* zone, const char* key, const char* val)
    {
        declareGlueDouble(fCPPInterface, zone, key, val);
    }

};
    
struct UIGlueTemplate : public UIInterface
{
    
    UIGlue* fGlue;
    
    UIGlueTemplate(UIGlue* glue):fGlue(glue)
    {}
    virtual ~UIGlueTemplate() {}
    
    virtual int sizeOfFAUSTFLOAT() { return sizeof(FAUSTFLOAT); }
    
    // -- widget's layouts
    
    void openTabBox(const char* label)
    {
        fGlue->openTabBox(fGlue->uiInterface, label);
    }
    void openHorizontalBox(const char* label)
    {
        fGlue->openHorizontalBox(fGlue->uiInterface, label);
    }
    void openVerticalBox(const char* label)
    {
        fGlue->openVerticalBox(fGlue->uiInterface, label);
    }
    void closeBox()
    {
        fGlue->closeBox(fGlue->uiInterface);
    }

    // float version
    
    // -- active widgets
    
    void addButton(const char* label, float* zone)
    {
        fGlue->addButton(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone));
    }
    void addCheckButton(const char* label, float* zone)
    {
        fGlue->addCheckButton(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone));
    }
    
    void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step)
    {
        fGlue->addVerticalSlider(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), init, min, max, step);
    }
    void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step)
    {
        fGlue->addHorizontalSlider(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), init, min, max, step);
    }
    void addNumEntry(const char* label, float* zone, float init, float min, float max, float step)
    {
        fGlue->addNumEntry(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), init, min, max, step);
    }
    
    // -- passive widgets
    
    void addHorizontalBargraph(const char* label, float* zone, float min, float max)
    {
        fGlue->addHorizontalBargraph(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), min, max);
    }
    void addVerticalBargraph(const char* label, float* zone, float min, float max)
    {
        fGlue->addVerticalBargraph(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), min, max);
    }
    
    // -- metadata declarations
    
    void declare(float* zone, const char* key, const char* val)
    {
        fGlue->declare(fGlue->uiInterface, reinterpret_cast<FAUSTFLOAT*>(zone), key, val);
    }
    
    // double version
    
    void addButton(const char* label, double* zone)
    {
        fGlue->addButton(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone));
    }
    void addCheckButton(const char* label, double* zone)
    {
        fGlue->addCheckButton(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone));
    }
    
    void addVerticalSlider(const char* label, double* zone, double init, double min, double max, double step)
    {
        fGlue->addVerticalSlider(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), init, min, max, step);
    }
    void addHorizontalSlider(const char* label, double* zone, double init, double min, double max, double step)
    {
        fGlue->addHorizontalSlider(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), init, min, max, step);
    }
    void addNumEntry(const char* label, double* zone, double init, double min, double max, double step)
    {
        fGlue->addNumEntry(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), init, min, max, step);
    }
    // -- soundfiles
    
    void addSoundfile(const char* label, const char* url, Soundfile** sf_zone) {}
    
    // -- passive widgets
    
    void addHorizontalBargraph(const char* label, double* zone, double min, double max)
    {
        fGlue->addHorizontalBargraph(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), min, max);
    }
    void addVerticalBargraph(const char* label, double* zone, double min, double max)
    {
        fGlue->addVerticalBargraph(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), min, max);
    }
    
    // -- metadata declarations
    
    void declare(double* zone, const char* key, const char* val)
    {
        fGlue->declare(fGlue->uiInterface, reinterpret_cast<FAUSTFLOAT*>(zone), key, val);
    }
    
};

/*******************************************************************************
 * Meta glue code
 ******************************************************************************/

static void declareMetaGlue(void* cpp_interface, const char* key, const char* value)
{
    Meta* meta_interface = static_cast<Meta*>(cpp_interface);
    meta_interface->declare(key, value);
}

static void buildMetaGlue(MetaGlue* glue, Meta* meta)
{
    glue->metaInterface = meta;
    glue->declare = declareMetaGlue;
}
    
/*******************************************************************************
 * Memory manager glue code
 ******************************************************************************/

static void* allocateMemoryManagerGlue(void* cpp_interface, size_t size)
{
    dsp_memory_manager* manager_interface = static_cast<dsp_memory_manager*>(cpp_interface);
    return manager_interface->allocate(size);
}
    
static void destroyMemoryManagerGlue(void* cpp_interface, void* ptr)
{
    dsp_memory_manager* manager_interface = static_cast<dsp_memory_manager*>(cpp_interface);
    manager_interface->destroy(ptr);
}

static void buildManagerGlue(MemoryManagerGlue* glue, dsp_memory_manager* manager)
{
    glue->managerInterface = manager;
    glue->allocate = allocateMemoryManagerGlue;
    glue->destroy = destroyMemoryManagerGlue;
}

#ifdef __cplusplus
}
#endif

#endif
/**************************  END  CGlue.h **************************/

#ifdef _WIN32
#include <windows.h>
#define snprintf _snprintf
#endif

//------------------------------------------------------------------------------------------
//  Decode a base_dsp JSON description and implement 'buildUserInterface' and 'metadata' methods
//------------------------------------------------------------------------------------------

#define REAL_UI(ui_interface) reinterpret_cast<UIReal<REAL>*>(ui_interface)
#define REAL_ADR(index)      reinterpret_cast<REAL*>(&memory_block[index])
#define REAL_EXT_ADR(index)  reinterpret_cast<FAUSTFLOAT*>(&memory_block[index])
#define SOUNDFILE_ADR(index) reinterpret_cast<Soundfile**>(&memory_block[index])

typedef std::function<void(FAUSTFLOAT)> ReflectFunction;
typedef std::function<FAUSTFLOAT()> ModifyFunction;

struct FAUST_API ExtZoneParam {

    virtual void reflectZone() = 0;
    virtual void modifyZone() = 0;
    
    virtual void setReflectZoneFun(ReflectFunction reflect) = 0;
    virtual void setModifyZoneFun(ModifyFunction modify) = 0;
    
    virtual ~ExtZoneParam()
    {}
    
};

// Templated decoder

struct FAUST_API JSONUIDecoderBase
{
    virtual ~JSONUIDecoderBase()
    {}
    
    virtual void metadata(Meta* m) = 0;
    virtual void metadata(MetaGlue* glue) = 0;
    virtual int getDSPSize() = 0;
    virtual std::string getName() = 0;
    virtual std::string getLibVersion() = 0;
    virtual std::string getCompileOptions() = 0;
    virtual std::vector<std::string> getLibraryList() = 0;
    virtual std::vector<std::string> getIncludePathnames() = 0;
    virtual int getNumInputs() = 0;
    virtual int getNumOutputs() = 0;
    virtual int getSampleRate(char* memory_block) = 0;
    virtual void setReflectZoneFun(int index, ReflectFunction fun) = 0;
    virtual void setModifyZoneFun(int index, ModifyFunction fun) = 0;
    virtual void setupDSPProxy(UI* ui_interface, char* memory_block) = 0;
    virtual bool hasDSPProxy() = 0;
    virtual std::vector<ExtZoneParam*>& getInputControls() = 0;
    virtual std::vector<ExtZoneParam*>& getOutputControls() = 0;
    virtual void resetUserInterface() = 0;
    virtual void resetUserInterface(char* memory_block, Soundfile* defaultsound = nullptr) = 0;
    virtual void buildUserInterface(UI* ui_interface) = 0;
    virtual void buildUserInterface(UI* ui_interface, char* memory_block) = 0;
    virtual void buildUserInterface(UIGlue* ui_interface, char* memory_block) = 0;
    virtual bool hasCompileOption(const std::string& option) = 0;
};

template <typename REAL>
struct FAUST_API JSONUIDecoderReal : public JSONUIDecoderBase {
    
    struct ZoneParam : public ExtZoneParam {
        
        FAUSTFLOAT fZone;
        ReflectFunction fReflect;
        ModifyFunction fModify;
        
    #if defined(TARGET_OS_IPHONE) || defined(WIN32)
        ZoneParam(ReflectFunction reflect = nullptr, ModifyFunction modify = nullptr)
        :fReflect(reflect), fModify(modify)
        {}
        void reflectZone() { if (fReflect) fReflect(fZone); }
        void modifyZone() { if (fModify) fZone = fModify(); }
    #else
        ZoneParam(ReflectFunction reflect = [](FAUSTFLOAT value) {}, ModifyFunction modify = []() { return FAUSTFLOAT(-1); })
        :fReflect(reflect), fModify(modify)
        {}
        void reflectZone() { fReflect(fZone); }
        void modifyZone() { fZone = fModify(); }
    #endif
        
        void setReflectZoneFun(ReflectFunction reflect) { fReflect = reflect; }
        void setModifyZoneFun(ModifyFunction modify) { fModify = modify; }
        
    };
    
    typedef std::vector<ExtZoneParam*> controlMap;
  
    std::string fName;
    std::string fFileName;
    std::string fJSON;
    std::string fVersion;
    std::string fCompileOptions;
    
    std::map<std::string, std::string> fMetadata;
    std::vector<itemInfo> fUiItems;
    
    std::vector<std::string> fLibraryList;
    std::vector<std::string> fIncludePathnames;
    
    int fNumInputs, fNumOutputs, fSRIndex;
    int fDSPSize;
    bool fDSPProxy;
    
    controlMap fPathInputTable;     // [path, ZoneParam]
    controlMap fPathOutputTable;    // [path, ZoneParam]
    
    bool startWith(const std::string& str, const std::string& prefix)
    {
        return (str.substr(0, prefix.size()) == prefix);
    }

    bool isInput(const std::string& type)
    {
        return (type == "vslider" || type == "hslider" || type == "nentry" || type == "button" || type == "checkbox");
    }
    bool isOutput(const std::string& type) { return (type == "hbargraph" || type == "vbargraph"); }
    bool isSoundfile(const std::string& type) { return (type == "soundfile"); }
    
    std::string getString(std::map<std::string, std::pair<std::string, double> >& map, const std::string& key)
    {
        return (map.find(key) != map.end()) ? map[key].first : "";
    }
    
    int getInt(std::map<std::string, std::pair<std::string, double> >& map, const std::string& key)
    {
        return (map.find(key) != map.end()) ? int(map[key].second) : -1;
    }
    
    void setReflectZoneFun(int index, ReflectFunction fun)
    {
        fPathInputTable[index]->setReflectZoneFun(fun);
    }
    
    void setModifyZoneFun(int index, ModifyFunction fun)
    {
        fPathOutputTable[index]->setModifyZoneFun(fun);
    }

    JSONUIDecoderReal(const std::string& json)
    {
        fJSON = json;
        const char* p = fJSON.c_str();
        std::map<std::string, std::pair<std::string, double> > meta_data1;
        std::map<std::string, std::vector<std::string> > meta_data2;
        parseJson(p, meta_data1, fMetadata, meta_data2, fUiItems);
        
        // meta_data1 contains <name : val>, <inputs : val>, <ouputs : val> pairs etc...
        fName = getString(meta_data1, "name");
        fFileName = getString(meta_data1, "filename");
        fVersion = getString(meta_data1, "version");
        fCompileOptions = getString(meta_data1, "compile_options");
        
        if (meta_data2.find("library_list") != meta_data2.end()) {
            fLibraryList = meta_data2["library_list"];
        } else {
            // 'library_list' is coded as successive 'library_pathN' metadata
            for (const auto& it : fMetadata) {
                if (startWith(it.first, "library_path")) {
                    fLibraryList.push_back(it.second);
                }
            }
        }
        if (meta_data2.find("include_pathnames") != meta_data2.end()) {
            fIncludePathnames = meta_data2["include_pathnames"];
        }
        
        fDSPSize = getInt(meta_data1, "size");
        fNumInputs = getInt(meta_data1, "inputs");
        fNumOutputs = getInt(meta_data1, "outputs");
        fSRIndex = getInt(meta_data1, "sr_index");
        fDSPProxy = false;
        
        // Prepare the fPathTable and init zone
        for (const auto& it : fUiItems) {
            std::string type = it.type;
            // Meta data declaration for input items
            if (isInput(type)) {
                ZoneParam* param = new ZoneParam();
                fPathInputTable.push_back(param);
                param->fZone = it.init;
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                ZoneParam* param = new ZoneParam();
                fPathOutputTable.push_back(param);
                param->fZone = REAL(0);
            }
        }
    }
    
    virtual ~JSONUIDecoderReal()
    {
        for (const auto& it : fPathInputTable) {
            delete it;
        }
        for (const auto& it : fPathOutputTable) {
            delete it;
        }
    }
    
    void metadata(Meta* m)
    {
        for (const auto& it : fMetadata) {
            m->declare(it.first.c_str(), it.second.c_str());
        }
    }
    
    void metadata(MetaGlue* m)
    {
        for (const auto& it : fMetadata) {
            m->declare(m->metaInterface, it.first.c_str(), it.second.c_str());
        }
    }
    
    void resetUserInterface()
    {
        int item = 0;
        for (const auto& it : fUiItems) {
            if (isInput(it.type)) {
                static_cast<ZoneParam*>(fPathInputTable[item++])->fZone = it.init;
            }
        }
    }
    
    void resetUserInterface(char* memory_block, Soundfile* defaultsound = nullptr)
    {
        for (const auto& it : fUiItems) {
            int index = it.index;
            if (isInput(it.type)) {
                *REAL_ADR(index) = it.init;
            } else if (isSoundfile(it.type)) {
                if (*SOUNDFILE_ADR(index) == nullptr) {
                    *SOUNDFILE_ADR(index) = defaultsound;
                }
            }
        }
    }
    
    int getSampleRate(char* memory_block)
    {
        return *reinterpret_cast<int*>(&memory_block[fSRIndex]);
    }
    
    void setupDSPProxy(UI* ui_interface, char* memory_block)
    {
        if (!fDSPProxy) {
            fDSPProxy = true;
            int countIn = 0;
            int countOut = 0;
            for (const auto& it : fUiItems) {
                std::string type = it.type;
                int index = it.index;
                if (isInput(type)) {
                    fPathInputTable[countIn++]->setReflectZoneFun([=](FAUSTFLOAT value) { *REAL_ADR(index) = REAL(value); });
                } else if (isOutput(type)) {
                    fPathOutputTable[countOut++]->setModifyZoneFun([=]() { return FAUSTFLOAT(*REAL_ADR(index)); });
                }
            }
        }
        
        // Setup soundfile in any case
        for (const auto& it : fUiItems) {
            if (isSoundfile(it.type)) {
                ui_interface->addSoundfile(it.label.c_str(), it.url.c_str(), SOUNDFILE_ADR(it.index));
            }
        }
    }
    
    bool hasDSPProxy() { return fDSPProxy; }
  
    void buildUserInterface(UI* ui_interface)
    {
        // MANDATORY: to be sure floats or double are correctly parsed
        char* tmp_local = setlocale(LC_ALL, nullptr);
        if (tmp_local != NULL) {
            tmp_local = strdup(tmp_local);
        }
        setlocale(LC_ALL, "C");
        
        int countIn = 0;
        int countOut = 0;
        int countSound = 0;
        
        for (const auto& it : fUiItems) {
            
            std::string type = it.type;
            REAL init = REAL(it.init);
            REAL min = REAL(it.fmin);
            REAL max = REAL(it.fmax);
            REAL step = REAL(it.step);
            
            // Meta data declaration for input items
            if (isInput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    ui_interface->declare(&static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    ui_interface->declare(&static_cast<ZoneParam*>(fPathOutputTable[countOut])->fZone, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    ui_interface->declare(0, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                ui_interface->openHorizontalBox(it.label.c_str());
            } else if (type == "vgroup") {
                ui_interface->openVerticalBox(it.label.c_str());
            } else if (type == "tgroup") {
                ui_interface->openTabBox(it.label.c_str());
            } else if (type == "vslider") {
                ui_interface->addVerticalSlider(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, init, min, max, step);
            } else if (type == "hslider") {
                ui_interface->addHorizontalSlider(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, init, min, max, step);
            } else if (type == "checkbox") {
                ui_interface->addCheckButton(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone);
            } else if (type == "soundfile") {
                // Nothing
            } else if (type == "hbargraph") {
                ui_interface->addHorizontalBargraph(it.label.c_str(), &static_cast<ZoneParam*>(fPathOutputTable[countOut])->fZone, min, max);
            } else if (type == "vbargraph") {
                ui_interface->addVerticalBargraph(it.label.c_str(), &static_cast<ZoneParam*>(fPathOutputTable[countOut])->fZone, min, max);
            } else if (type == "nentry") {
                ui_interface->addNumEntry(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, init, min, max, step);
            } else if (type == "button") {
                ui_interface->addButton(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone);
            } else if (type == "close") {
                ui_interface->closeBox();
            }
            
            if (isInput(type)) {
                countIn++;
            } else if (isOutput(type)) {
                countOut++;
            } else if (isSoundfile(type)) {
                countSound++;
            }
        }
        
        if (tmp_local != NULL) {
            setlocale(LC_ALL, tmp_local);
            free(tmp_local);
        }
    }
    
    void buildUserInterface(UI* ui_interface, char* memory_block)
    {
        // MANDATORY: to be sure floats or double are correctly parsed
        char* tmp_local = setlocale(LC_ALL, nullptr);
        if (tmp_local != NULL) {
            tmp_local = strdup(tmp_local);
        }
        setlocale(LC_ALL, "C");
        
        for (const auto& it : fUiItems) {
            
            std::string type = it.type;
            int index = it.index;
            REAL init = REAL(it.init);
            REAL min = REAL(it.fmin);
            REAL max = REAL(it.fmax);
            REAL step = REAL(it.step);
            
            // Meta data declaration for input items
            if (isInput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(REAL_ADR(index), it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(REAL_ADR(index), it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(0, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                REAL_UI(ui_interface)->openHorizontalBox(it.label.c_str());
            } else if (type == "vgroup") {
                REAL_UI(ui_interface)->openVerticalBox(it.label.c_str());
            } else if (type == "tgroup") {
                REAL_UI(ui_interface)->openTabBox(it.label.c_str());
            } else if (type == "vslider") {
                REAL_UI(ui_interface)->addVerticalSlider(it.label.c_str(), REAL_ADR(index), init, min, max, step);
            } else if (type == "hslider") {
                REAL_UI(ui_interface)->addHorizontalSlider(it.label.c_str(), REAL_ADR(index), init, min, max, step);
            } else if (type == "checkbox") {
                REAL_UI(ui_interface)->addCheckButton(it.label.c_str(), REAL_ADR(index));
            } else if (type == "soundfile") {
                REAL_UI(ui_interface)->addSoundfile(it.label.c_str(), it.url.c_str(), SOUNDFILE_ADR(index));
            } else if (type == "hbargraph") {
                REAL_UI(ui_interface)->addHorizontalBargraph(it.label.c_str(), REAL_ADR(index), min, max);
            } else if (type == "vbargraph") {
                REAL_UI(ui_interface)->addVerticalBargraph(it.label.c_str(), REAL_ADR(index), min, max);
            } else if (type == "nentry") {
                REAL_UI(ui_interface)->addNumEntry(it.label.c_str(), REAL_ADR(index), init, min, max, step);
            } else if (type == "button") {
                REAL_UI(ui_interface)->addButton(it.label.c_str(), REAL_ADR(index));
            } else if (type == "close") {
                REAL_UI(ui_interface)->closeBox();
            }
        }
        
        if (tmp_local != NULL) {
            setlocale(LC_ALL, tmp_local);
            free(tmp_local);
        }
    }
    
    void buildUserInterface(UIGlue* ui_interface, char* memory_block)
    {
        // MANDATORY: to be sure floats or double are correctly parsed
        char* tmp_local = setlocale(LC_ALL, nullptr);
        if (tmp_local != NULL) {
            tmp_local = strdup(tmp_local);
        }
        setlocale(LC_ALL, "C");
        
        for (const auto& it : fUiItems) {
            
            std::string type = it.type;
            int index = it.index;
            REAL init = REAL(it.init);
            REAL min = REAL(it.fmin);
            REAL max = REAL(it.fmax);
            REAL step = REAL(it.step);
            
            // Meta data declaration for input items
            if (isInput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    ui_interface->declare(ui_interface->uiInterface, REAL_EXT_ADR(index), it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    ui_interface->declare(ui_interface->uiInterface, REAL_EXT_ADR(index), it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    ui_interface->declare(ui_interface->uiInterface, 0, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                ui_interface->openHorizontalBox(ui_interface->uiInterface, it.label.c_str());
            } else if (type == "vgroup") {
                ui_interface->openVerticalBox(ui_interface->uiInterface, it.label.c_str());
            } else if (type == "tgroup") {
                ui_interface->openTabBox(ui_interface->uiInterface, it.label.c_str());
            } else if (type == "vslider") {
                ui_interface->addVerticalSlider(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index), init, min, max, step);
            } else if (type == "hslider") {
                ui_interface->addHorizontalSlider(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index), init, min, max, step);
            } else if (type == "checkbox") {
                ui_interface->addCheckButton(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index));
            } else if (type == "soundfile") {
                ui_interface->addSoundfile(ui_interface->uiInterface, it.label.c_str(), it.url.c_str(), SOUNDFILE_ADR(index));
            } else if (type == "hbargraph") {
                ui_interface->addHorizontalBargraph(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index), min, max);
            } else if (type == "vbargraph") {
                ui_interface->addVerticalBargraph(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index), min, max);
            } else if (type == "nentry") {
                ui_interface->addNumEntry(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index), init, min, max, step);
            } else if (type == "button") {
                ui_interface->addButton(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index));
            } else if (type == "close") {
                ui_interface->closeBox(ui_interface->uiInterface);
            }
        }
        
        if (tmp_local != NULL) {
            setlocale(LC_ALL, tmp_local);
            free(tmp_local);
        }
    }
    
    bool hasCompileOption(const std::string& option)
    {
        std::istringstream iss(fCompileOptions);
        std::string token;
        while (std::getline(iss, token, ' ')) {
            if (token == option) return true;
        }
        return false;
    }
    
    int getDSPSize() { return fDSPSize; }
    std::string getName() { return fName; }
    std::string getLibVersion() { return fVersion; }
    std::string getCompileOptions() { return fCompileOptions; }
    std::vector<std::string> getLibraryList() { return fLibraryList; }
    std::vector<std::string> getIncludePathnames() { return fIncludePathnames; }
    int getNumInputs() { return fNumInputs; }
    int getNumOutputs() { return fNumOutputs; }
    
    std::vector<ExtZoneParam*>& getInputControls()
    {
        return fPathInputTable;
    }
    std::vector<ExtZoneParam*>& getOutputControls()
    {
        return fPathOutputTable;
    }
    
};

// FAUSTFLOAT templated decoder

struct FAUST_API JSONUIDecoder : public JSONUIDecoderReal<FAUSTFLOAT>
{
    JSONUIDecoder(const std::string& json):JSONUIDecoderReal<FAUSTFLOAT>(json)
    {}
};

// Generic factory

static JSONUIDecoderBase* createJSONUIDecoder(const std::string& json)
{
    JSONUIDecoder decoder(json);
    if (decoder.hasCompileOption("-double")) {
        return new JSONUIDecoderReal<double>(json);
    } else {
        return new JSONUIDecoderReal<float>(json);
    }
}

#endif
/**************************  END  JSONUIDecoder.h **************************/

/**
 * Proxy base_dsp definition created from the DSP JSON description.
 * This class allows a 'proxy' base_dsp to control a real base_dsp
 * possibly running somewhere else.
 */
class proxy_dsp : public base_dsp {

    protected:
    
        JSONUIDecoder* fDecoder;
        int fSampleRate;
    
        void init(const std::string& json)
        {
            fDecoder = new JSONUIDecoder(json);
            fSampleRate = -1;
        }
        
    public:
    
        proxy_dsp():fDecoder(nullptr), fSampleRate(-1)
        {}
    
        proxy_dsp(const std::string& json)
        {
            init(json);
        }
          
        proxy_dsp(base_dsp* base_dsp)
        {
            JSONUI builder(base_dsp->getNumInputs(), base_dsp->getNumOutputs());
            base_dsp->metadata(&builder);
            base_dsp->buildUserInterface(&builder);
            fSampleRate = base_dsp->getSampleRate();
            fDecoder = new JSONUIDecoder(builder.JSON());
        }
      
        virtual ~proxy_dsp()
        {
            delete fDecoder;
        }
    
        virtual int getNumInputs() { return fDecoder->fNumInputs; }
        virtual int getNumOutputs() { return fDecoder->fNumOutputs; }
        
        virtual void buildUserInterface(UI* ui) { fDecoder->buildUserInterface(ui); }
        
        // To possibly implement in a concrete proxy base_dsp 
        virtual void init(int sample_rate)
        {
            instanceInit(sample_rate);
        }
        virtual void instanceInit(int sample_rate)
        {
            instanceConstants(sample_rate);
            instanceResetUserInterface();
            instanceClear();
        }
        virtual void instanceConstants(int sample_rate) { fSampleRate = sample_rate; }
        virtual void instanceResetUserInterface() { fDecoder->resetUserInterface(); }
        virtual void instanceClear() {}
    
        virtual int getSampleRate() { return fSampleRate; }
    
        virtual proxy_dsp* clone() { return new proxy_dsp(fDecoder->fJSON); }
        virtual void metadata(Meta* m) { fDecoder->metadata(m); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {}
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {} 
        
};

#endif
/************************** END proxy-base_dsp.h **************************/

/************************** BEGIN DecoratorUI.h **************************
 FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
*************************************************************************/

#ifndef Decorator_UI_H
#define Decorator_UI_H


//----------------------------------------------------------------
//  Generic UI empty implementation
//----------------------------------------------------------------

class FAUST_API GenericUI : public UI
{
    
    public:
        
        GenericUI() {}
        virtual ~GenericUI() {}
        
        // -- widget's layouts
        virtual void openTabBox(const char* label) {}
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* soundpath, Soundfile** sf_zone) {}
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) {}
    
};

//----------------------------------------------------------------
//  Generic UI decorator
//----------------------------------------------------------------

class FAUST_API DecoratorUI : public UI
{
    
    protected:
        
        UI* fUI;
        
    public:
        
        DecoratorUI(UI* ui = 0):fUI(ui) {}
        virtual ~DecoratorUI() { delete fUI; }
        
        // -- widget's layouts
        virtual void openTabBox(const char* label)          { fUI->openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fUI->openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fUI->openVerticalBox(label); }
        virtual void closeBox()                             { fUI->closeBox(); }
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)         { fUI->addButton(label, zone); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)    { fUI->addCheckButton(label, zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addVerticalSlider(label, zone, init, min, max, step); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addHorizontalSlider(label, zone, init, min, max, step); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addNumEntry(label, zone, init, min, max, step); }
        
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addHorizontalBargraph(label, zone, min, max); }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addVerticalBargraph(label, zone, min, max); }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) { fUI->addSoundfile(label, filename, sf_zone); }
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) { fUI->declare(zone, key, val); }
    
};

// Defined here to simplify header #include inclusion 
class FAUST_API SoundUIInterface : public GenericUI {};

#endif
/**************************  END  DecoratorUI.h **************************/
/************************** BEGIN JSONControl.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 *************************************************************************/

#ifndef __JSON_CONTROL__
#define __JSON_CONTROL__

#include <string>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

struct FAUST_API JSONControl {
    
    virtual std::string getJSON() { return ""; }

    virtual void setParamValue(const std::string& path, FAUSTFLOAT value) {}

    virtual FAUSTFLOAT getParamValue(const std::string& path) { return 0; }
    
    virtual ~JSONControl()
    {}
    
};

#endif
/**************************  END  JSONControl.h **************************/

#define kActiveVoice    0
#define kFreeVoice     -1
#define kReleaseVoice  -2
#define kLegatoVoice   -3
#define kNoVoice       -4

#define VOICE_STOP_LEVEL  0.0005    // -70 db
#define MIX_BUFFER_SIZE   4096

/**
 * Allows to control zones in a grouped manner.
 */
class GroupUI : public GUI, public PathBuilder {

    private:

        std::map<std::string, uiGroupItem*> fLabelZoneMap;

        void insertMap(std::string label, FAUSTFLOAT* zone)
        {
            if (!MapUI::endsWith(label, "/gate")
                && !MapUI::endsWith(label, "/freq")
                && !MapUI::endsWith(label, "/key")
                && !MapUI::endsWith(label, "/gain")
                && !MapUI::endsWith(label, "/vel")
                && !MapUI::endsWith(label, "/velocity")) {

                // Groups all controllers except 'freq/key', 'gate', and 'gain/vel|velocity'
                if (fLabelZoneMap.find(label) != fLabelZoneMap.end()) {
                    fLabelZoneMap[label]->addZone(zone);
                } else {
                    fLabelZoneMap[label] = new uiGroupItem(this, zone);
                }
            }
        }

        uiCallbackItem* fPanic;

    public:

        GroupUI(FAUSTFLOAT* zone, uiCallback cb, void* arg)
        {
            fPanic = new uiCallbackItem(this, zone, cb, arg);
        }
    
        virtual ~GroupUI()
        {
            // 'fPanic' is kept and deleted in GUI, so do not delete here
        }

        // -- widget's layouts
        void openTabBox(const char* label)
        {
            pushLabel(label);
        }
        void openHorizontalBox(const char* label)
        {
            pushLabel(label);
        }
        void openVerticalBox(const char* label)
        {
            pushLabel(label);
        }
        void closeBox()
        {
            popLabel();
        }

        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }

        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }

};

/**
 * One voice of polyphony.
 */
struct dsp_voice : public MapUI, public decorator_dsp {
    
    typedef std::function<double(int)> TransformFunction;
  
    static double midiToFreq(double note)
    {
        return 440.0 * std::pow(2.0, (note-69.0)/12.0);
    }
    
    int fCurNote;                       // Playing note pitch
    int fNextNote;                      // In kLegatoVoice state, next note to play
    int fNextVel;                       // In kLegatoVoice state, next velocity to play
    int fDate;                          // KeyOn date
    int fRelease;                       // Current number of samples used in release mode to detect end of note
    FAUSTFLOAT fLevel;                  // Last audio block level
    double fReleaseLengthSec;           // Maximum release length in seconds (estimated time to silence after note release)
    std::vector<std::string> fGatePath; // Paths of 'gate' control
    std::vector<std::string> fGainPath; // Paths of 'gain/vel|velocity' control
    std::vector<std::string> fFreqPath; // Paths of 'freq/key' control
    TransformFunction        fKeyFun;   // MIDI key to freq conversion function
    TransformFunction        fVelFun;   // MIDI velocity to gain conversion function
    
    FAUSTFLOAT** fInputsSlice;
    FAUSTFLOAT** fOutputsSlice;
 
    dsp_voice(base_dsp* base_dsp):decorator_dsp(base_dsp)
    {
        // Default versions
        fVelFun = [](int velocity) { return double(velocity)/127.0; };
        fKeyFun = [](int pitch) { return midiToFreq(pitch); };
        base_dsp->buildUserInterface(this);
        fCurNote = kFreeVoice;
        fNextNote = fNextVel = -1;
        fLevel = FAUSTFLOAT(0);
        fDate = fRelease = 0;
        fReleaseLengthSec = 0.5;  // A half second is a reasonable default maximum release length.
        extractPaths(fGatePath, fFreqPath, fGainPath);
    }
    virtual ~dsp_voice()
    {}
    
    void computeSlice(int offset, int slice, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        FAUSTFLOAT** inputsSlice = static_cast<FAUSTFLOAT**>(alloca(sizeof(FAUSTFLOAT*) * getNumInputs()));
        for (int chan = 0; chan < getNumInputs(); chan++) {
            inputsSlice[chan] = &(inputs[chan][offset]);
        }
        FAUSTFLOAT** outputsSlice = static_cast<FAUSTFLOAT**>(alloca(sizeof(FAUSTFLOAT*) * getNumOutputs()));
        for (int chan = 0; chan < getNumOutputs(); chan++) {
            outputsSlice[chan] = &(outputs[chan][offset]);
        }
        compute(slice, inputsSlice, outputsSlice);
    }
    
    void computeLegato(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        int slice = count/2;
        
        // Reset envelops
        for (size_t i = 0; i < fGatePath.size(); i++) {
            setParamValue(fGatePath[i], FAUSTFLOAT(0));
        }
        
        // Compute current voice on half buffer
        computeSlice(0, slice, inputs, outputs);
         
        // Start next keyOn
        keyOn(fNextNote, fNextVel);
        
        // Compute on second half buffer
        computeSlice(slice, slice, inputs, outputs);
    }

    void extractPaths(std::vector<std::string>& gate, std::vector<std::string>& freq, std::vector<std::string>& gain)
    {
        // Keep gain/vel|velocity, freq/key and gate labels
        for (const auto& it : getFullpathMap()) {
            std::string path = it.first;
            if (endsWith(path, "/gate")) {
                gate.push_back(path);
            } else if (endsWith(path, "/freq")) {
                fKeyFun = [](int pitch) { return midiToFreq(pitch); };
                freq.push_back(path);
            } else if (endsWith(path, "/key")) {
                fKeyFun = [](int pitch) { return pitch; };
                freq.push_back(path);
            } else if (endsWith(path, "/gain")) {
                fVelFun = [](int velocity) { return double(velocity)/127.0; };
                gain.push_back(path);
            } else if (endsWith(path, "/vel") || endsWith(path, "/velocity")) {
                fVelFun = [](int velocity) { return double(velocity); };
                gain.push_back(path);
            }
        }
    }
    
    void reset()
    {
        init(getSampleRate());
    }
 
    void instanceClear()
    {
        decorator_dsp::instanceClear();
        fCurNote = kFreeVoice;
        fNextNote = fNextVel = -1;
        fLevel = FAUSTFLOAT(0);
        fDate = fRelease = 0;
    }
    
    // Keep 'pitch' and 'velocity' to fadeOut the current voice and start next one in the next buffer
    void keyOn(int pitch, int velocity, bool legato = false)
    {
        if (legato) {
            fNextNote = pitch;
            fNextVel = velocity;
        } else {
            keyOn(pitch, fVelFun(velocity));
        }
    }

    // Normalized MIDI velocity [0..1]
    void keyOn(int pitch, double velocity)
    {
        for (size_t i = 0; i < fFreqPath.size(); i++) {
            setParamValue(fFreqPath[i], fKeyFun(pitch));
        }
        for (size_t i = 0; i < fGatePath.size(); i++) {
            setParamValue(fGatePath[i], FAUSTFLOAT(1));
        }
        for (size_t i = 0; i < fGainPath.size(); i++) {
            setParamValue(fGainPath[i], velocity);
        }
        
        fCurNote = pitch;
    }

    void keyOff(bool hard = false)
    {
        // No use of velocity for now...
        for (size_t i = 0; i < fGatePath.size(); i++) {
            setParamValue(fGatePath[i], FAUSTFLOAT(0));
        }
        
        if (hard) {
            // Immediately stop voice
            fCurNote = kFreeVoice;
        } else {
            // Release voice
            fRelease = fReleaseLengthSec * fDSP->getSampleRate();
            fCurNote = kReleaseVoice;
        }
    }
 
    // Change the voice release
    void setReleaseLength(double sec)
    {
        fReleaseLengthSec = sec;
    }

};

/**
 * A group of voices.
 */
struct dsp_voice_group {

    GroupUI fGroups;

    std::vector<dsp_voice*> fVoiceTable; // Individual voices
    base_dsp* fVoiceGroup;                    // Voices group to be used for GUI grouped control

    FAUSTFLOAT fPanic;

    bool fVoiceControl;
    bool fGroupControl;

    dsp_voice_group(uiCallback cb, void* arg, bool control, bool group)
        :fGroups(&fPanic, cb, arg),
        fVoiceGroup(0), fPanic(FAUSTFLOAT(0)),
        fVoiceControl(control), fGroupControl(group)
    {}

    virtual ~dsp_voice_group()
    {
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            delete fVoiceTable[i];
        }
        delete fVoiceGroup;
    }

    void addVoice(dsp_voice* voice)
    {
        fVoiceTable.push_back(voice);
    }

    void clearVoices()
    {
        fVoiceTable.clear();
    }

    void init()
    {
        // Groups all uiItem for a given path
        fVoiceGroup = new proxy_dsp(fVoiceTable[0]);
        fVoiceGroup->buildUserInterface(&fGroups);
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            fVoiceTable[i]->buildUserInterface(&fGroups);
        }
    }
    
    void instanceResetUserInterface()
    {
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            fVoiceTable[i]->instanceResetUserInterface();
        }
    }

    void buildUserInterface(UI* ui_interface)
    {
        if (fVoiceTable.size() > 1) {
            ui_interface->openTabBox("Polyphonic");

            // Grouped voices UI
            ui_interface->openVerticalBox("Voices");
            ui_interface->addButton("Panic", &fPanic);
            fVoiceGroup->buildUserInterface(ui_interface);
            ui_interface->closeBox();

            // If not grouped, also add individual voices UI
            if (!fGroupControl || dynamic_cast<SoundUIInterface*>(ui_interface)) {
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    char buffer[32];
                    snprintf(buffer, 32, ((fVoiceTable.size() < 8) ? "Voice%ld" : "V%ld"), long(i+1));
                    ui_interface->openHorizontalBox(buffer);
                    fVoiceTable[i]->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                }
            }

            ui_interface->closeBox();
        } else {
            fVoiceTable[0]->buildUserInterface(ui_interface);
        }
    }

};

/**
 * Base class for MIDI controllable polyphonic DSP.
 */
#ifdef EMCC
#endif

class dsp_poly : public decorator_dsp, public midi, public JSONControl {

    protected:
    
    #ifdef EMCC
        MapUI fMapUI;
        std::string fJSON;
        midi_handler fMidiHandler;
        MidiUI fMIDIUI;
    #endif
    
    public:
    
    #ifdef EMCC
        dsp_poly(base_dsp* base_dsp):decorator_dsp(base_dsp), fMIDIUI(&fMidiHandler)
        {
            JSONUI jsonui(getNumInputs(), getNumOutputs());
            buildUserInterface(&jsonui);
            fJSON = jsonui.JSON(true);
            buildUserInterface(&fMapUI);
            buildUserInterface(&fMIDIUI);
        }
    #else
        dsp_poly(base_dsp* base_dsp):decorator_dsp(base_dsp)
        {}
    #endif
    
        virtual ~dsp_poly() {}
    
        // Reimplemented for EMCC
    #ifdef EMCC
        virtual int getNumInputs() { return decorator_dsp::getNumInputs(); }
        virtual int getNumOutputs() { return decorator_dsp::getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { decorator_dsp::buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return decorator_dsp::getSampleRate(); }
        virtual void init(int sample_rate) { decorator_dsp::init(sample_rate); }
        virtual void instanceInit(int sample_rate) { decorator_dsp::instanceInit(sample_rate); }
        virtual void instanceConstants(int sample_rate) { decorator_dsp::instanceConstants(sample_rate); }
        virtual void instanceResetUserInterface() { decorator_dsp::instanceResetUserInterface(); }
        virtual void instanceClear() { decorator_dsp::instanceClear(); }
        virtual dsp_poly* clone() { return new dsp_poly(fDSP->clone()); }
        virtual void metadata(Meta* m) { decorator_dsp::metadata(m); }
    
        // Additional API
        std::string getJSON()
        {
            return fJSON;
        }
    
        virtual void setParamValue(const std::string& path, FAUSTFLOAT value)
        {
            fMapUI.setParamValue(path, value);
            GUI::updateAllGuis();
        }
        
        virtual FAUSTFLOAT getParamValue(const std::string& path) { return fMapUI.getParamValue(path); }

        virtual void computeJS(int count, uintptr_t inputs, uintptr_t outputs)
        {
            decorator_dsp::compute(count, reinterpret_cast<FAUSTFLOAT**>(inputs),reinterpret_cast<FAUSTFLOAT**>(outputs));
        }
    #endif
    
        virtual MapUI* keyOn(int channel, int pitch, int velocity)
        {
            return midi::keyOn(channel, pitch, velocity);
        }
        virtual void keyOff(int channel, int pitch, int velocity)
        {
            midi::keyOff(channel, pitch, velocity);
        }
        virtual void keyPress(int channel, int pitch, int press)
        {
            midi::keyPress(channel, pitch, press);
        }
        virtual void chanPress(int channel, int press)
        {
            midi::chanPress(channel, press);
        }
        virtual void ctrlChange(int channel, int ctrl, int value)
        {
            midi::ctrlChange(channel, ctrl, value);
        }
        virtual void ctrlChange14bits(int channel, int ctrl, int value)
        {
            midi::ctrlChange14bits(channel, ctrl, value);
        }
        virtual void pitchWheel(int channel, int wheel)
        {
        #ifdef EMCC
            fMIDIUI.pitchWheel(0., channel, wheel);
            GUI::updateAllGuis();
        #else
            midi::pitchWheel(channel, wheel);
        #endif
        }
        virtual void progChange(int channel, int pgm)
        {
            midi::progChange(channel, pgm);
        }
    
        // Change the voice release
        virtual void setReleaseLength(double seconds)
        {}
    
};

/**
 * Polyphonic DSP: groups a set of DSP to be played together or triggered by MIDI.
 *
 * All voices are preallocated by cloning the single DSP voice given at creation time.
 * Dynamic voice allocation is done in 'getFreeVoice'
 */
class mydsp_poly : public dsp_voice_group, public dsp_poly {

    private:

        FAUSTFLOAT** fMixBuffer;
        FAUSTFLOAT** fOutBuffer;
        midi_interface* fMidiHandler; // The midi_interface the DSP is connected to
        int fDate;
    
        void fadeOut(int count, FAUSTFLOAT** outBuffer)
        {
            // FadeOut on half buffer
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                double factor = 1., step = 1./double(count);
                for (int frame = 0; frame < count; frame++) {
                    outBuffer[chan][frame] *= factor;
                    factor -= step;
                }
            }
        }
    
        FAUSTFLOAT mixCheckVoice(int count, FAUSTFLOAT** mixBuffer, FAUSTFLOAT** outBuffer)
        {
            FAUSTFLOAT level = 0;
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                FAUSTFLOAT* mixChannel = mixBuffer[chan];
                FAUSTFLOAT* outChannel = outBuffer[chan];
                for (int frame = 0; frame < count; frame++) {
                    level = std::max<FAUSTFLOAT>(level, (FAUSTFLOAT)fabs(mixChannel[frame]));
                    outChannel[frame] += mixChannel[frame];
                }
            }
            return level;
        }
    
        void mixVoice(int count, FAUSTFLOAT** mixBuffer, FAUSTFLOAT** outBuffer)
        {
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                FAUSTFLOAT* mixChannel = mixBuffer[chan];
                FAUSTFLOAT* outChannel = outBuffer[chan];
                for (int frame = 0; frame < count; frame++) {
                    outChannel[frame] += mixChannel[frame];
                }
            }
        }
    
        void copy(int count, FAUSTFLOAT** mixBuffer, FAUSTFLOAT** outBuffer)
        {
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                memcpy(outBuffer[chan], mixBuffer[chan], count * sizeof(FAUSTFLOAT));
            }
        }

        void clear(int count, FAUSTFLOAT** outBuffer)
        {
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                memset(outBuffer[chan], 0, count * sizeof(FAUSTFLOAT));
            }
        }
    
        int getPlayingVoice(int pitch)
        {
            int voice_playing = kNoVoice;
            int oldest_date_playing = INT_MAX;
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fCurNote == pitch) {
                    // Keeps oldest playing voice
                    if (fVoiceTable[i]->fDate < oldest_date_playing) {
                        oldest_date_playing = fVoiceTable[i]->fDate;
                        voice_playing = int(i);
                    }
                }
            }
            
            return voice_playing;
        }
    
        int allocVoice(int voice, int type)
        {
            fVoiceTable[voice]->fDate++;
            fVoiceTable[voice]->fCurNote = type;
            return voice;
        }
    
        // Always returns a voice
        int getFreeVoice()
        {
            // Looks for the first available voice
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fCurNote == kFreeVoice) {
                    return allocVoice(i, kActiveVoice);
                }
            }

            // Otherwise steal one
            int voice_release = kNoVoice;
            int voice_playing = kNoVoice;
            int oldest_date_release = INT_MAX;
            int oldest_date_playing = INT_MAX;

            // Scan all voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fCurNote == kReleaseVoice) {
                    // Keeps oldest release voice
                    if (fVoiceTable[i]->fDate < oldest_date_release) {
                        oldest_date_release = fVoiceTable[i]->fDate;
                        voice_release = int(i);
                    }
                } else {
                    // Otherwise keeps oldest playing voice
                    if (fVoiceTable[i]->fDate < oldest_date_playing) {
                        oldest_date_playing = fVoiceTable[i]->fDate;
                        voice_playing = int(i);
                    }
                }
            }
        
            // Then decide which one to steal
            if (oldest_date_release != INT_MAX) {
                fprintf(stderr, "Steal release voice : voice_date = %d cur_date = %d voice = %d \n",
                        fVoiceTable[voice_release]->fDate,
                        fDate,
                        voice_release);
                return allocVoice(voice_release, kLegatoVoice);
            } else if (oldest_date_playing != INT_MAX) {
                fprintf(stderr, "Steal playing voice : voice_date = %d cur_date = %d voice = %d \n",
                        fVoiceTable[voice_playing]->fDate,
                        fDate,
                        voice_release);
                return allocVoice(voice_playing, kLegatoVoice);
            } else {
                assert(false);
                return kNoVoice;
            }
        }

        static void panic(FAUSTFLOAT val, void* arg)
        {
            if (val == FAUSTFLOAT(1)) {
                static_cast<mydsp_poly*>(arg)->allNotesOff(true);
            }
        }

        bool checkPolyphony()
        {
            if (fVoiceTable.size() > 0) {
                return true;
            } else {
                fprintf(stderr, "DSP is not polyphonic...\n");
                return false;
            }
        }

    public:
    
        /**
         * Constructor.
         *
         * @param base_dsp - the base_dsp to be used for one voice. Beware: mydsp_poly will use and finally delete the pointer.
         * @param nvoices - number of polyphony voices, should be at least 1
         * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
         *                If false all voices are always running.
         * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
         *                a given control on all voices, assuming GUI::updateAllGuis() is called.
         *                If false, all voices can be individually controlled.
         *
         */
        mydsp_poly(base_dsp* base_dsp,
                   int nvoices,
                   bool control = false,
                   bool group = true)
        : dsp_voice_group(panic, this, control, group), dsp_poly(base_dsp) // base_dsp parameter is deallocated by ~dsp_poly
        {
            fDate = 0;
            fMidiHandler = nullptr;

            // Create voices
            assert(nvoices > 0);
            for (int i = 0; i < nvoices; i++) {
                addVoice(new dsp_voice(base_dsp->clone()));
            }

            // Init audio output buffers
            fMixBuffer = new FAUSTFLOAT*[getNumOutputs()];
            fOutBuffer = new FAUSTFLOAT*[getNumOutputs()];
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                fMixBuffer[chan] = new FAUSTFLOAT[MIX_BUFFER_SIZE];
                fOutBuffer[chan] = new FAUSTFLOAT[MIX_BUFFER_SIZE];
            }

            dsp_voice_group::init();
        }

        virtual ~mydsp_poly()
        {
            // Remove from fMidiHandler
            if (fMidiHandler) fMidiHandler->removeMidiIn(this);
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                delete[] fMixBuffer[chan];
                delete[] fOutBuffer[chan];
            }
            delete[] fMixBuffer;
            delete[] fOutBuffer;
            
        }

        // DSP API
        void buildUserInterface(UI* ui_interface)
        {
            // MidiUI ui_interface contains the midi_handler connected to the MIDI driver
            if (dynamic_cast<midi_interface*>(ui_interface)) {
                fMidiHandler = dynamic_cast<midi_interface*>(ui_interface);
                fMidiHandler->addMidiIn(this);
            }
            dsp_voice_group::buildUserInterface(ui_interface);
        }

        void init(int sample_rate)
        {
            decorator_dsp::init(sample_rate);
            fVoiceGroup->init(sample_rate);
            fPanic = FAUSTFLOAT(0);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->init(sample_rate);
            }
        }
    
        void instanceInit(int samplingFreq)
        {
            instanceConstants(samplingFreq);
            instanceResetUserInterface();
            instanceClear();
        }

        void instanceConstants(int sample_rate)
        {
            decorator_dsp::instanceConstants(sample_rate);
            fVoiceGroup->instanceConstants(sample_rate);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceConstants(sample_rate);
            }
        }

        void instanceResetUserInterface()
        {
            decorator_dsp::instanceResetUserInterface();
            fVoiceGroup->instanceResetUserInterface();
            fPanic = FAUSTFLOAT(0);
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceResetUserInterface();
            }
        }

        void instanceClear()
        {
            decorator_dsp::instanceClear();
            fVoiceGroup->instanceClear();
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceClear();
            }
        }

        virtual mydsp_poly* clone()
        {
            return new mydsp_poly(fDSP->clone(), int(fVoiceTable.size()), fVoiceControl, fGroupControl);
        }

        void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            assert(count <= MIX_BUFFER_SIZE);

            // First clear the intermediate fOutBuffer
            clear(count, fOutBuffer);

            if (fVoiceControl) {
                // Mix all playing voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    dsp_voice* voice = fVoiceTable[i];
                    if (voice->fCurNote == kLegatoVoice) {
                        // Play from current note and next note
                        voice->computeLegato(count, inputs, fMixBuffer);
                        // FadeOut on first half buffer
                        fadeOut(count/2, fMixBuffer);
                        // Mix it in result
                        voice->fLevel = mixCheckVoice(count, fMixBuffer, fOutBuffer);
                    } else if (voice->fCurNote != kFreeVoice) {
                        // Compute current note
                        voice->compute(count, inputs, fMixBuffer);
                        // Mix it in result
                        voice->fLevel = mixCheckVoice(count, fMixBuffer, fOutBuffer);
                        // Check the level to possibly set the voice in kFreeVoice again
                        voice->fRelease -= count;
                        if ((voice->fCurNote == kReleaseVoice)
                            && (voice->fRelease < 0)
                            && (voice->fLevel < VOICE_STOP_LEVEL)) {
                            voice->fCurNote = kFreeVoice;
                        }
                    }
                }
            } else {
                // Mix all voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    fVoiceTable[i]->compute(count, inputs, fMixBuffer);
                    mixVoice(count, fMixBuffer, fOutBuffer);
                }
            }
            
            // Finally copy intermediate buffer to outputs
            copy(count, fOutBuffer, outputs);
        }

        void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            compute(count, inputs, outputs);
        }
    
        // Terminate all active voices, gently or immediately (depending of 'hard' value)
        void allNotesOff(bool hard = false)
        {
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->keyOff(hard);
            }
        }
 
        // Additional polyphonic API
        MapUI* newVoice()
        {
            return fVoiceTable[getFreeVoice()];
        }

        void deleteVoice(MapUI* voice)
        {
            auto it = find(fVoiceTable.begin(), fVoiceTable.end(), reinterpret_cast<dsp_voice*>(voice));
            if (it != fVoiceTable.end()) {
                dsp_voice* voice = *it;
                voice->keyOff();
                voice->reset();
            } else {
                fprintf(stderr, "Voice not found\n");
            }
        }

        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            if (checkPolyphony()) {
                int voice = getFreeVoice();
                fVoiceTable[voice]->keyOn(pitch, velocity, fVoiceTable[voice]->fCurNote == kLegatoVoice);
                return fVoiceTable[voice];
            } else {
                return 0;
            }
        }

        void keyOff(int channel, int pitch, int velocity = 127)
        {
            if (checkPolyphony()) {
                int voice = getPlayingVoice(pitch);
                if (voice != kNoVoice) {
                    fVoiceTable[voice]->keyOff();
                } else {
                    fprintf(stderr, "Playing pitch = %d not found\n", pitch);
                }
            }
        }

        void ctrlChange(int channel, int ctrl, int value)
        {
            if (ctrl == ALL_NOTES_OFF || ctrl == ALL_SOUND_OFF) {
                allNotesOff();
            }
        }

        // Change the voice release
        void setReleaseLength(double seconds)
        {
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->setReleaseLength(seconds);
            }
        }

};

/**
 * Polyphonic DSP with an integrated effect.
 */
class dsp_poly_effect : public dsp_poly {
    
    private:
    
        // fPolyDSP will respond to MIDI messages.
        dsp_poly* fPolyDSP;
        
    public:
        
        dsp_poly_effect(dsp_poly* voice, base_dsp* combined)
        :dsp_poly(combined), fPolyDSP(voice)
        {}
        
        virtual ~dsp_poly_effect()
        {
            // dsp_poly_effect is also a decorator_dsp, which will free fPolyDSP
        }
    
        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            return fPolyDSP->keyOn(channel, pitch, velocity);
        }
        void keyOff(int channel, int pitch, int velocity)
        {
            fPolyDSP->keyOff(channel, pitch, velocity);
        }
        void keyPress(int channel, int pitch, int press)
        {
            fPolyDSP->keyPress(channel, pitch, press);
        }
        void chanPress(int channel, int press)
        {
            fPolyDSP->chanPress(channel, press);
        }
        void ctrlChange(int channel, int ctrl, int value)
        {
            fPolyDSP->ctrlChange(channel, ctrl, value);
        }
        void ctrlChange14bits(int channel, int ctrl, int value)
        {
            fPolyDSP->ctrlChange14bits(channel, ctrl, value);
        }
        void pitchWheel(int channel, int wheel)
        {
            fPolyDSP->pitchWheel(channel, wheel);
        }
        void progChange(int channel, int pgm)
        {
            fPolyDSP->progChange(channel, pgm);
        }
    
        // Change the voice release
        void setReleaseLength(double sec)
        {
            fPolyDSP->setReleaseLength(sec);
        }
    
};

/**
 * Polyphonic DSP factory class. Helper code to support polyphonic DSP source with an integrated effect.
 */
struct dsp_poly_factory : public dsp_factory {
    
    dsp_factory* fProcessFactory;
    dsp_factory* fEffectFactory;
    
    base_dsp* adaptDSP(base_dsp* base_dsp, bool is_double)
    {
        return (is_double) ? new dsp_sample_adapter<double, float>(base_dsp) : base_dsp;
    }

    dsp_poly_factory(dsp_factory* process_factory = nullptr,
                     dsp_factory* effect_factory = nullptr):
    fProcessFactory(process_factory)
    ,fEffectFactory(effect_factory)
    {}

    virtual ~dsp_poly_factory()
    {}

    std::string getName() { return fProcessFactory->getName(); }
    std::string getSHAKey() { return fProcessFactory->getSHAKey(); }
    std::string getDSPCode() { return fProcessFactory->getDSPCode(); }
    std::string getCompileOptions() { return fProcessFactory->getCompileOptions(); }
    std::vector<std::string> getLibraryList() { return fProcessFactory->getLibraryList(); }
    std::vector<std::string> getIncludePathnames() { return fProcessFactory->getIncludePathnames(); }
    std::vector<std::string> getWarningMessages() { return fProcessFactory->getWarningMessages(); }
   
    std::string getEffectCode(const std::string& dsp_content)
    {
        std::stringstream effect_code;
        effect_code << "adapt(1,1) = _; adapt(2,2) = _,_; adapt(1,2) = _ <: _,_; adapt(2,1) = _,_ :> _;";
        effect_code << "adaptor(F,G) = adapt(outputs(F),inputs(G)); dsp_code = environment{ " << dsp_content << " };";
        effect_code << "process = adaptor(dsp_code.process, dsp_code.effect) : dsp_code.effect;";
        return effect_code.str();
    }

    virtual void setMemoryManager(dsp_memory_manager* manager)
    {
        fProcessFactory->setMemoryManager(manager);
        if (fEffectFactory) {
            fEffectFactory->setMemoryManager(manager);
        }
    }
    virtual dsp_memory_manager* getMemoryManager() { return fProcessFactory->getMemoryManager(); }

    /* Create a new polyphonic DSP instance with global effect, to be deleted with C++ 'delete'
     *
     * @param nvoices - number of polyphony voices, should be at least 1
     * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
     *                If false all voices are always running.
     * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
     *                a given control on all voices, assuming GUI::updateAllGuis() is called.
     *                If false, all voices can be individually controlled.
     * @param is_double - if true, internally allocated DSPs will be adapted to receive 'double' samples.
     */
    dsp_poly* createPolyDSPInstance(int nvoices, bool control, bool group, bool is_double = false)
    {
        dsp_poly* dsp_poly = new mydsp_poly(adaptDSP(fProcessFactory->createDSPInstance(), is_double), nvoices, control, group);
        if (fEffectFactory) {
            // the 'dsp_poly' object has to be controlled with MIDI, so kept separated from new dsp_sequencer(...) object
            return new dsp_poly_effect(dsp_poly, new dsp_sequencer(dsp_poly, adaptDSP(fEffectFactory->createDSPInstance(), is_double)));
        } else {
            return new dsp_poly_effect(dsp_poly, dsp_poly);
        }
    }

    /* Create a new DSP instance, to be deleted with C++ 'delete' */
    base_dsp* createDSPInstance()
    {
        return fProcessFactory->createDSPInstance();
    }

};

#endif // __poly_dsp__
/************************** END poly-base_dsp.h **************************/
#ifndef PLUGIN_MAGIC
/************************** BEGIN JuceGUI.h *****************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef JUCE_GUI_H
#define JUCE_GUI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <stack>

#include "../JuceLibraryCode/JuceHeader.h"


// Definition of the standard size of the different elements

#define kKnobWidth 100
#define kKnobHeight 100

#define kVSliderWidth 80
#define kVSliderHeight 250

#define kHSliderWidth 350
#define kHSliderHeight 50

#define kButtonWidth 100
#define kButtonHeight 50

#define kCheckButtonWidth 60
#define kCheckButtonHeight 40

#define kMenuWidth 100
#define kMenuHeight 50

#define kRadioButtonWidth 100
#define kRadioButtonHeight 55

#define kNumEntryWidth 100
#define kNumEntryHeight 50

#define kNumDisplayWidth 75
#define kNumDisplayHeight 50

#define kVBargraphWidth 60
#define kVBargraphHeight 250

#define kHBargraphWidth 350
#define kHBargraphHeight 50

#define kLedWidth 25
#define kLedHeight 25

#define kNameHeight 14

#define kMargin 4

/**
 * \brief       Custom LookAndFeel class.
 * \details     Define the appearance of all the JUCE widgets.
 */

struct CustomLookAndFeel : public juce::LookAndFeel_V3
{
    void drawRoundThumb (juce::Graphics& g, const float x, const float y,
                         const float diameter, const juce::Colour& colour, float outlineThickness)
    {
        const juce::Rectangle<float> a (x, y, diameter, diameter);
        const float halfThickness = outlineThickness * 0.5f;

        juce::Path p;
        p.addEllipse (x + halfThickness, y + halfThickness, diameter - outlineThickness, diameter - outlineThickness);

        const juce::DropShadow ds (juce::Colours::black, 1, juce::Point<int> (0, 0));
        ds.drawForPath (g, p);

        g.setColour (colour);
        g.fillPath (p);

        g.setColour (colour.brighter());
        g.strokePath (p, juce::PathStrokeType (outlineThickness));
    }

    void drawButtonBackground (juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour,
                               bool isMouseOverButton, bool isButtonDown) override
    {
        juce::Colour baseColour (backgroundColour.withMultipliedSaturation (button.hasKeyboardFocus (true) ? 1.3f : 0.9f)
                           .withMultipliedAlpha (button.isEnabled() ? 0.9f : 0.5f));

        if (isButtonDown || isMouseOverButton)
            baseColour = baseColour.contrasting (isButtonDown ? 0.2f : 0.1f);

        const bool flatOnLeft   = button.isConnectedOnLeft();
        const bool flatOnRight  = button.isConnectedOnRight();
        const bool flatOnTop    = button.isConnectedOnTop();
        const bool flatOnBottom = button.isConnectedOnBottom();

        const float width  = button.getWidth() - 1.0f;
        const float height = button.getHeight() - 1.0f;

        if (width > 0 && height > 0)
        {
            const float cornerSize = juce::jmin(15.0f, juce::jmin(width, height) * 0.45f);
            const float lineThickness = cornerSize * 0.1f;
            const float halfThickness = lineThickness * 0.5f;

            juce::Path outline;
            outline.addRoundedRectangle (0.5f + halfThickness, 0.5f + halfThickness, width - lineThickness, height - lineThickness,
                                         cornerSize, cornerSize,
                                         ! (flatOnLeft  || flatOnTop),
                                         ! (flatOnRight || flatOnTop),
                                         ! (flatOnLeft  || flatOnBottom),
                                         ! (flatOnRight || flatOnBottom));

            const juce::Colour outlineColour (button.findColour (button.getToggleState() ? juce::TextButton::textColourOnId
                                        : juce::TextButton::textColourOffId));

            g.setColour (baseColour);
            g.fillPath (outline);

            if (! button.getToggleState()) {
                g.setColour (outlineColour);
                g.strokePath (outline, juce::PathStrokeType (lineThickness));
            }
        }
    }

    void drawTickBox (juce::Graphics& g, juce::Component& component,
                      float x, float y, float w, float h,
                      bool ticked,
                      bool isEnabled,
                      bool isMouseOverButton,
                      bool isButtonDown) override
    {
        const float boxSize = w * 0.7f;

        bool isDownOrDragging = component.isEnabled() && (component.isMouseOverOrDragging() || component.isMouseButtonDown());
        const juce::Colour colour (component.findColour (juce::TextButton::buttonColourId).withMultipliedSaturation ((component.hasKeyboardFocus (false) || isDownOrDragging) ? 1.3f : 0.9f)
                             .withMultipliedAlpha (component.isEnabled() ? 1.0f : 0.7f));

        drawRoundThumb (g, x, y + (h - boxSize) * 0.5f, boxSize, colour,
                        isEnabled ? ((isButtonDown || isMouseOverButton) ? 1.1f : 0.5f) : 0.3f);

        if (ticked) {
            const juce::Path tick (juce::LookAndFeel_V2::getTickShape (6.0f));
            g.setColour (isEnabled ? findColour (juce::TextButton::buttonOnColourId) : juce::Colours::grey);

            const float scale = 9.0f;
            const juce::AffineTransform trans (juce::AffineTransform::scale (w / scale, h / scale)
                                         .translated (x - 2.5f, y + 1.0f));
            g.fillPath (tick, trans);
        }
    }

    void drawLinearSliderThumb (juce::Graphics& g, int x, int y, int width, int height,
                                float sliderPos, float minSliderPos, float maxSliderPos,
                                const juce::Slider::SliderStyle style, juce::Slider& slider) override
    {
        const float sliderRadius = (float)(getSliderThumbRadius (slider) - 2);

        bool isDownOrDragging = slider.isEnabled() && (slider.isMouseOverOrDragging() || slider.isMouseButtonDown());
        juce::Colour knobColour (slider.findColour (juce::Slider::thumbColourId).withMultipliedSaturation ((slider.hasKeyboardFocus (false) || isDownOrDragging) ? 1.3f : 0.9f)
                           .withMultipliedAlpha (slider.isEnabled() ? 1.0f : 0.7f));

        if (style == juce::Slider::LinearHorizontal || style == juce::Slider::LinearVertical) {
            float kx, ky;

            if (style == juce::Slider::LinearVertical) {
                kx = x + width * 0.5f;
                ky = sliderPos;
            } else {
                kx = sliderPos;
                ky = y + height * 0.5f;
            }

            const float outlineThickness = slider.isEnabled() ? 0.8f : 0.3f;

            drawRoundThumb (g,
                            kx - sliderRadius,
                            ky - sliderRadius,
                            sliderRadius * 2.0f,
                            knobColour, outlineThickness);
        } else {
            // Just call the base class for the demo
            juce::LookAndFeel_V2::drawLinearSliderThumb (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
        }
    }

    void drawLinearSlider (juce::Graphics& g, int x, int y, int width, int height,
                           float sliderPos, float minSliderPos, float maxSliderPos,
                           const juce::Slider::SliderStyle style, juce::Slider& slider) override
    {
        g.fillAll (slider.findColour (juce::Slider::backgroundColourId));

        if (style == juce::Slider::LinearBar || style == juce::Slider::LinearBarVertical) {
            const float fx = (float)x, fy = (float)y, fw = (float)width, fh = (float)height;

            juce::Path p;

            if (style == juce::Slider::LinearBarVertical)
                p.addRectangle (fx, sliderPos, fw, 1.0f + fh - sliderPos);
            else
                p.addRectangle (fx, fy, sliderPos - fx, fh);

            juce::Colour baseColour (slider.findColour (juce::Slider::rotarySliderFillColourId)
                               .withMultipliedSaturation (slider.isEnabled() ? 1.0f : 0.5f)
                               .withMultipliedAlpha (0.8f));

            g.setColour (baseColour);
            g.fillPath (p);

            const float lineThickness = juce::jmin(15.0f, juce::jmin(width, height) * 0.45f) * 0.1f;
            g.drawRect (slider.getLocalBounds().toFloat(), lineThickness);
        } else {
            drawLinearSliderBackground (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
            drawLinearSliderThumb (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
        }
    }

    void drawLinearSliderBackground (juce::Graphics& g, int x, int y, int width, int height,
                                     float /*sliderPos*/,
                                     float /*minSliderPos*/,
                                     float /*maxSliderPos*/,
                                     const juce::Slider::SliderStyle /*style*/, juce::Slider& slider) override
    {
        const float sliderRadius = getSliderThumbRadius (slider) - 5.0f;
        juce::Path on, off;

        if (slider.isHorizontal()) {
            const float iy = y + height * 0.5f - sliderRadius * 0.5f;
            juce::Rectangle<float> r (x - sliderRadius * 0.5f, iy, width + sliderRadius, sliderRadius);
            const float onW = r.getWidth() * ((float)slider.valueToProportionOfLength (slider.getValue()));

            on.addRectangle (r.removeFromLeft (onW));
            off.addRectangle (r);
        } else {
            const float ix = x + width * 0.5f - sliderRadius * 0.5f;
            juce::Rectangle<float> r (ix, y - sliderRadius * 0.5f, sliderRadius, height + sliderRadius);
            const float onH = r.getHeight() * ((float)slider.valueToProportionOfLength (slider.getValue()));

            on.addRectangle (r.removeFromBottom (onH));
            off.addRectangle (r);
        }

        g.setColour (slider.findColour (juce::Slider::rotarySliderFillColourId));
        g.fillPath (on);

        g.setColour (slider.findColour (juce::Slider::trackColourId));
        g.fillPath (off);
    }

    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
                           float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override
    {
        const float radius = juce::jmin(width / 2, height / 2) - 4.0f;
        const float centreX = x + width * 0.5f;
        const float centreY = y + height * 0.5f;
        const float rx = centreX - radius;
        const float ry = centreY - radius;
        const float rw = radius * 2.0f;
        const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        const bool isMouseOver = slider.isMouseOverOrDragging() && slider.isEnabled();

        //Background
        {
            g.setColour(juce::Colours::lightgrey.withAlpha (isMouseOver ? 1.0f : 0.7f));
            juce::Path intFilledArc;
            intFilledArc.addPieSegment(rx, ry, rw, rw, rotaryStartAngle, rotaryEndAngle, 0.8);
            g.fillPath(intFilledArc);
        }

        if (slider.isEnabled()) {
            g.setColour(slider.findColour (juce::Slider::rotarySliderFillColourId).withAlpha (isMouseOver ? 1.0f : 0.7f));
        } else {
            g.setColour(juce::Colour (0x80808080));
        }

        //Render knob value
        {
            juce::Path pathArc;
            pathArc.addPieSegment(rx, ry, rw, rw, rotaryStartAngle, angle, 0.8);
            g.fillPath(pathArc);

            juce::Path cursor, cursorShadow;
            float rectWidth = radius*0.4;
            float rectHeight = rectWidth/2;
            float rectX = centreX + radius*0.9 - rectHeight/2;
            float rectY = centreY - rectWidth/2;

            cursor.addRectangle(rectX, rectY, rectWidth, rectHeight);
            cursorShadow.addRectangle(rectX-1, rectY-1, rectWidth+2, rectHeight+2);

            juce::AffineTransform t = juce::AffineTransform::translation(-rectWidth + 2, rectHeight/2);
            t = t.rotated((angle - MathConstants<float>::pi/2), centreX, centreY);

            cursor.applyTransform(t);
            cursorShadow.applyTransform(t);

            g.setColour(juce::Colours::black);
            g.fillPath(cursor);

            g.setColour(juce::Colours::black .withAlpha(0.15f));
            g.fillPath(cursorShadow);
        }
    }
};

/**
 * \brief   Different kind of slider available
 * \see     uiSlider
 */
enum SliderType {
    HSlider,    /*!< Horizontal Slider      */
    VSlider,    /*!< Vertical Slider        */
    NumEntry,   /*!< Numerical Entry Box    */
    Knob        /*!< Circular Slider        */
};

/**
 * \brief   Different kind of VU-meter available.
 */
enum VUMeterType {
    HVUMeter,   /*!< Horizontal VU-meter    */
    VVUMeter,   /*!< Vertical VU-meter      */
    Led,        /*!< LED VU-meter           */
    NumDisplay  /*!< TextBox VU-meter       */
};

/**
 * \brief   Intern class for all FAUST widgets.
 * \details Every active, passive or box widgets derive from this class.
 */
class uiBase
{
    
    protected:
        
        int fTotalWidth, fTotalHeight;              // Size with margins included (for a uiBox)
        int fDisplayRectWidth, fDisplayRectHeight;  // Size without margin, just the child dimensions, sum on one dimension, max on the other
        float fHRatio, fVRatio;
        
    public:
        
        /**
         * \brief   Constructor.
         * \details Initialize a uiBase with all its sizes.
         *
         * \param   totWidth    Minimal total width.
         * \param   totHeight   Minimal total Height.
         */
        uiBase(int totWidth = 0, int totHeight = 0):
            fTotalWidth(totWidth), fTotalHeight(totHeight),
            fDisplayRectWidth(0), fDisplayRectHeight(0),
            fHRatio(1), fVRatio(1)
        {}
        
        virtual ~uiBase()
        {}
        
        /** Return the size. */
        juce::Rectangle<int> getSize()
        {
            return juce::Rectangle<int>(0, 0, fTotalWidth, fTotalHeight);
        }
        
        /** Return the total height in pixels. */
        int getTotalHeight()
        {
            return fTotalHeight;
        }
        
        /** Return the total width in pixels. */
        int getTotalWidth()
        {
            return fTotalWidth;
        }
        
        /** Return the horizontal ratio, between 0 and 1. */
        float getHRatio()
        {
            return fHRatio;
        }
        
        /** Return the vertical ratio, between 0 and 1. */
        float getVRatio()
        {
            return fVRatio;
        }
        
        /**
         * \brief   Set the uiBase bounds.
         * \details Convert absolute bounds to relative bounds,
         *          used in JUCE Component mechanics.
         *
         * \param r The absolute bounds.
         *
         */
        void setRelativeSize(juce::Component* comp, const juce::Rectangle<int>& r)
        {
            comp->setBounds(r.getX() - comp->getParentComponent()->getX(),
                            r.getY() - comp->getParentComponent()->getY(),
                            r.getWidth(),
                            r.getHeight());
        }
    
        virtual void init(juce::Component* comp = nullptr)
        {
            /** Initialize both vertical and horizontal ratios. */
            assert(comp);
            uiBase* parentBox = comp->findParentComponentOfClass<uiBase>();
            if (parentBox != nullptr) {
                fHRatio = (float)fTotalWidth / (float)parentBox->fDisplayRectWidth;
                fVRatio = (float)fTotalHeight / (float)parentBox->fDisplayRectHeight;
            }
        }
    
        virtual void setRecommendedSize()
        {}
        
        virtual void add(juce::Component* comp)
        {}
    
};

/**
 * \brief   Intern class for all FAUST active or passive widgets.
 * \details Every activ or passive widgets derive from this class.
 */
class uiComponent : public uiBase, public juce::Component, public uiItem
{

    public:
        /**
         * \brief   Constructor.
         * \details Initialize all uiItem, uiBase and the tooltip variables.
         *
         * \param   gui     Current FAUST GUI.
         * \param   zone    Zone of the widget.
         * \param   w       Width of the widget.
         * \param   h       Height of the widget.
         * \param   name    Name of the widget.
         */
        uiComponent(GUI* gui, FAUSTFLOAT* zone, int w, int h, juce::String name):uiBase(w, h), Component(name), uiItem(gui, zone)
        {}

};

/** 
 * \brief   Intern class for all kind of sliders.
 * \see     SliderType
 */
class uiSlider : public uiComponent, public uiConverter, private juce::Slider::Listener
{
    
    private:
        
        juce::Slider::SliderStyle fStyle;
        juce::Label fLabel;
        SliderType fType;
        juce::Slider fSlider;

    public:
        /**
         * \brief   Constructor.
         * \details Initialize all uiComponent variables, and Slider specific ones.
         *          Initialize juce::Slider parameters.
         *
         * \param   gui, zone, w, h, tooltip, name  uiComponent variables.
         * \param   min                             Minimum value of the slider.
         * \param   max                             Maximum value of the slider.
         * \param   cur                             Initial value of the slider.
         * \param   step                            Step of the slider.
         * \param   unit                            Unit of the slider value.
         * \param   scale                           Scale of the slider, exponential, logarithmic, or linear.
         * \param   type                            Type of slider (see SliderType).
         */
        uiSlider(GUI* gui, FAUSTFLOAT* zone, FAUSTFLOAT w, FAUSTFLOAT h, FAUSTFLOAT cur, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step, juce::String name, juce::String unit, juce::String tooltip, MetaDataUI::Scale scale, SliderType type)
            : uiComponent(gui, zone, w, h, name), uiConverter(scale, min, max, min, max), fType(type)
        {
            // Set the JUCE widget initalization variables.
            switch(fType) {
                case HSlider:
                    fStyle = juce::Slider::SliderStyle::LinearHorizontal;
                    break;
                case VSlider:
                    fStyle = juce::Slider::SliderStyle::LinearVertical;
                    fSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 20);
                    break;
                case NumEntry:
                    fSlider.setIncDecButtonsMode(juce::Slider::incDecButtonsDraggable_AutoDirection);
                    fStyle = juce::Slider::SliderStyle::IncDecButtons;
                    break;
                case Knob:
                    fStyle = juce::Slider::SliderStyle::Rotary;
                    fSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 20);
                    break;
                default:
                    break;
            }
            addAndMakeVisible(fSlider);

            // Slider settings
            fSlider.setRange(min, max, step);
            fSlider.setValue(fConverter->faust2ui(cur));
            fSlider.addListener(this);
            fSlider.setSliderStyle(fStyle);
            fSlider.setTextValueSuffix(" " + unit);
            fSlider.setTooltip(tooltip);
            switch (scale) {
                case MetaDataUI::kLog:
                    fSlider.setSkewFactor(0.25);
                    break;
                case MetaDataUI::kExp:
                    fSlider.setSkewFactor(0.75);
                    break;
                default:
                    break;
            }
      
            // Label settings, only happens for a horizontal of numerical entry slider
            // because the method attachToComponent only give the choice to place the
            // slider name on centered top, which is what we want. It's done manually
            // in the paint method.
            if (fType == HSlider || fType == NumEntry) {
                fLabel.setText(getName(), juce::dontSendNotification);
                fLabel.attachToComponent(&fSlider, true);
                fLabel.setTooltip(tooltip);
                addAndMakeVisible(fLabel);
            }
        }

        /** Draw the name of a vertical or circular slider. */
        virtual void paint(juce::Graphics& g) override
        {
            if (fType == VSlider || fType == Knob) {
                g.setColour(juce::Colours::black);
                g.drawText(getName(), getLocalBounds(), juce::Justification::centredTop);
            }
        }

        /** Allow to control the slider when its value is changed, but not by the user. */
        void reflectZone() override
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fSlider.setValue(fConverter->faust2ui(v));
        }

        /** JUCE callback for a slider value change, give the value to the FAUST module. */
        void sliderValueChanged(juce::Slider* slider) override
        {
            float v = slider->getValue();
            modifyZone(FAUSTFLOAT(fConverter->ui2faust(v)));
        }

        /** 
         * Set the good coordinates and size for the juce::Slider object depending 
         * on its SliderType, whenever the layout size changes.
         */
        void resized() override
        {
            int x, y, width, height;
            
            switch (fType) {
                    
                case HSlider: {
                    int nameWidth = juce::Font().getStringWidth(getName()) + kMargin * 2;
                    x = nameWidth;
                    y = 0;
                    width = getWidth() - nameWidth;
                    height = getHeight();
                    break;
                }
                    
                case VSlider:
                    x = 0;
                    y = kNameHeight; // kNameHeight pixels for the name
                    height = getHeight() - kNameHeight;
                    width = getWidth();
                    break;

                case NumEntry:
                    width = kNumEntryWidth;
                    height = kNumEntryHeight;
                    // x position is the top left corner horizontal position of the box
                    // and not the top left of the NumEntry label, so we have to do that
                    x = (getWidth() - width)/2 + (juce::Font().getStringWidth(getName()) + kMargin)/2;
                    y = (getHeight() - height)/2;
                    break;
                    
                case Knob:
                    // The knob name needs to be displayed, kNameHeight pixels
                    height = width = juce::jmin(getHeight() - kNameHeight, kKnobHeight);
                    x = (getWidth() - width)/2;
                    // kNameHeight pixels for the knob name still
                    y = juce::jmax((getHeight() - height)/2, kNameHeight);
                    break;
                    
                default:
                    assert(false);
                    break;
            }
            
            fSlider.setBounds(x, y, width, height);
        }
    
};

/** Intern class for button */
class uiButton : public uiComponent, private juce::Button::Listener
{
    
    private:
        
        juce::TextButton fButton;

    public:
        /**
         * \brief   Constructor.
         * \details Initialize all uiComponent variables and juce::TextButton parameters.
         *
         * \param   gui, zone, w, h, tooltip, label uiComponent variable.
         */
        uiButton(GUI* gui, FAUSTFLOAT* zone, FAUSTFLOAT w, FAUSTFLOAT h, juce::String label, juce::String tooltip) :  uiComponent(gui, zone, w, h, label)
        {
            int x = 0;
            int y = (getHeight() - kButtonHeight)/2;

            fButton.setButtonText(label);
            fButton.setBounds(x, y, kButtonWidth, kButtonHeight);
            fButton.addListener(this);
            fButton.setTooltip(tooltip);
            addAndMakeVisible(fButton);
        }

        /** 
         * Has to be defined because its a pure virtual function of juce::Button::Listener, 
         * which uiButton derives from. Control of user actions is done in buttonStateChanged.
         * \see buttonStateChanged
         */
        void buttonClicked (juce::Button* button) override
        {}

        /** Indicate to the FAUST module when the button is pressed and released. */
        void buttonStateChanged (juce::Button* button) override
        {
            if (button->isDown()) {
                modifyZone(FAUSTFLOAT(1));
            } else {
                modifyZone(FAUSTFLOAT(0));
            }
        }
        
        void reflectZone() override
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v == FAUSTFLOAT(1)) {
                fButton.triggerClick();
            }
        }

        /** Set the good coordinates and size to the juce::TextButton widget whenever the layout size changes. */
        virtual void resized() override
        {
            int x = kMargin;
            int width = getWidth() - 2 * kMargin;
            int height = juce::jmin(getHeight(), kButtonHeight);
            int y = (getHeight()-height)/2;
            fButton.setBounds(x, y, width, height);
        }
    
};

/** Intern class for checkButton */
class uiCheckButton : public uiComponent, private juce::Button::Listener
{
    
    private:
        
        juce::ToggleButton fCheckButton;

    public:
        /**
         * \brief   Constructor.
         * \details Initialize all uiComponent variables and juce::ToggleButton parameters.
         *
         * \param   gui, zone, w, h, label, tooltip  uiComponent variables.
         */
        uiCheckButton(GUI* gui, FAUSTFLOAT* zone, FAUSTFLOAT w, FAUSTFLOAT h, juce::String label, juce::String tooltip) : uiComponent(gui, zone, w, h, label)
        {
            int x = 0;
            int y = (getHeight()-h)/2;
            
            fCheckButton.setButtonText(label);
            fCheckButton.setBounds(x, y, w, h);
            fCheckButton.addListener(this);
            fCheckButton.setTooltip(tooltip);
            addAndMakeVisible(fCheckButton);
        }

        /** Indicate to the FAUST module when the button is toggled or not. */
        void buttonClicked(juce::Button* button) override
        {
            //std::cout << getName() << " : " << button->getToggleState() << std::endl;
            modifyZone(button->getToggleState());
        }

        void reflectZone() override
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fCheckButton.triggerClick();
        }

        /** Set the good coordinates and size to the juce::ToggleButton widget, whenever the layout size changes. */
        virtual void resized() override
        {
            fCheckButton.setBounds(getLocalBounds());
        }
    
};

/** Intern class for Menu */
class uiMenu : public uiComponent, private juce::ComboBox::Listener
{
    
    private:
        
        juce::ComboBox fComboBox;
        std::vector<double> fValues;

    public:
        /**
         * \brief   Constructor.
         * \details Initialize the uiComponent and Menu specific variables, and the juce::ComboBox parameters.
         *          Menu is considered as a slider in the FAUST logic, with a step of one. The first item
         *          would be 0 on a slider, the second 1, etc. Each "slider value" is associated with a 
         *          string.
         *
         * \param   gui, zone, w, h, tooltip, label     uiComponent variables.
         * \param   cur                                 Current "slider value" associated with the current item selected.
         * \param   low                                 Lowest value possible.
         * \param   hi                                  Highest value possible.
         * \param   mdescr                              Menu description. Contains the names of the items associated with their "value".
         */
        uiMenu(GUI* gui, FAUSTFLOAT* zone, juce::String label, FAUSTFLOAT w, FAUSTFLOAT h, FAUSTFLOAT cur, FAUSTFLOAT lo, FAUSTFLOAT hi, juce::String tooltip, const char* mdescr) : uiComponent(gui, zone, w, h, label)
        {
            //Init ComboBox parameters
            fComboBox.setEditableText(false);
            fComboBox.setJustificationType(juce::Justification::centred);
            fComboBox.addListener(this);
            addAndMakeVisible(fComboBox);

            std::vector<std::string> names;
            std::vector<double> values;

            if (parseMenuList(mdescr, names, values)) {

                int defaultitem = -1;
                double mindelta = FLT_MAX;
                int item = 1;

                // Go through all the Menu's items.
                for (int i = 0; i < names.size(); i++) {
                    double v = values[i];
                    if ((v >= lo) && (v <= hi)) {
                        // It is a valid value : add corresponding menu item
                        // item astrating at 1 because index 0 is reserved for a non-defined item.
                        fComboBox.addItem(juce::String(names[i].c_str()), item++);
                        fValues.push_back(v);

                        // Check if this item is a good candidate to represent the current value
                        double delta = fabs(cur-v);
                        if (delta < mindelta) {
                            mindelta = delta;
                            defaultitem = fComboBox.getNumItems();
                        }
                    }
                }
                // check the best candidate to represent the current value
                if (defaultitem > -1) {
                    fComboBox.setSelectedItemIndex(defaultitem);
                }
            }

            *fZone = cur;
        }

        /** Indicate to the FAUST module when the selected items is changed. */
        void comboBoxChanged (juce::ComboBox* cb) override
        {
            //std::cout << getName( )<< " : " << cb->getSelectedId() - 1 << std::endl;
            // -1 because of the starting item  at 1 at the initialization
            modifyZone(fValues[cb->getSelectedId() - 1]);
        }

        virtual void reflectZone() override
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;

            // search closest value
            int defaultitem = -1;
            double mindelta = FLT_MAX;

            for (unsigned int i = 0; i < fValues.size(); i++) {
                double delta = fabs(fValues[i]-v);
                if (delta < mindelta) {
                    mindelta = delta;
                    defaultitem = i;
                }
            }
            if (defaultitem > -1) {
                fComboBox.setSelectedItemIndex(defaultitem);
            }
        }

        /** Set the good coordinates and size to the juce::ComboBox widget whenever the layout get reiszed */
        virtual void resized() override
        {
            fComboBox.setBounds(0, 0 + kMenuHeight/2, getWidth(), kMenuHeight/2);
        }

        /** Display the name of the Menu */
        virtual void paint(juce::Graphics& g) override
        {
            g.setColour(juce::Colours::black);
            g.drawText(getName(), getLocalBounds().withHeight(getHeight()/2), juce::Justification::centredTop);
        }
    
};

/** Intern class for RadioButton */
class uiRadioButton : public uiComponent, private juce::Button::Listener
{
    
    private:
        
        bool fIsVertical;
        juce::OwnedArray<juce::ToggleButton> fButtons;
        std::vector<double> fValues;

    public:
        /**
         * \brief   Constructor.
         * \details Initialize the uiComponent variables, and the RadioButton specific variables
         *          and parameters. Works in a similar way to the Menu, because it is a special
         *          kind of sliders in the faust logic. 
         * \see     uiMenu
         * 
         * \param   gui, zone, tooltip, label   uiComponent variables.
         * \param   w                           uiComponent variable and width of the RadioButton widget.
         * \param   h                           uiComponent variable and height of the RadioButton widget.
         * \param   cur                         Current "value" associated with the item selected.
         * \param   low                         Lowest "value" possible.
         * \param   hi                          Highest "value" possible.
         * \param   vert                        True if vertical, false if horizontal.
         * \param   names                       Contain the names of the different items.
         * \param   values                      Contain the "values" of the different items.
         * \param   fRadioGroupID               RadioButton being multiple CheckButton in JUCE,
         *                                      we need an ID to know which are linked together.
         */
        uiRadioButton(GUI* gui, FAUSTFLOAT* zone, juce::String label, FAUSTFLOAT w, FAUSTFLOAT h, FAUSTFLOAT cur, FAUSTFLOAT lo, FAUSTFLOAT hi, bool vert, std::vector<std::string>& names, std::vector<double>& values, juce::String tooltip, int radioGroupID) : uiComponent(gui, zone, w, h, label), fIsVertical(vert)
        {
            juce::ToggleButton* defaultbutton = 0;
            double mindelta = FLT_MAX;

            for (int i = 0; i < names.size(); i++) {
                double v = values[i];
                if ((v >= lo) && (v <= hi)) {

                    // It is a valid value included in slider's range
                    juce::ToggleButton* tb = new juce::ToggleButton(names[i]);
                    addAndMakeVisible(tb);
                    tb->setRadioGroupId (radioGroupID);
                    tb->addListener(this);
                    tb->setTooltip(tooltip);
                    fValues.push_back(v);
                    fButtons.add(tb);
      
                    // Check if this item is a good candidate to represent the current value
                    double delta = fabs(cur-v);
                    if (delta < mindelta) {
                        mindelta = delta;
                        defaultbutton = tb;
                    }
                }
            }
            // check the best candidate to represent the current value
            if (defaultbutton) {
                defaultbutton->setToggleState (true, juce::dontSendNotification);
            }
        }
     
        virtual void reflectZone() override
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;

            // select closest value
            int defaultitem = -1;
            double mindelta = FLT_MAX;

            for (unsigned int i = 0; i < fValues.size(); i++) {
                double delta = fabs(fValues[i]-v);
                if (delta < mindelta) {
                    mindelta = delta;
                    defaultitem = i;
                }
            }
            if (defaultitem > -1) {
                fButtons.operator[](defaultitem)->setToggleState (true, juce::dontSendNotification);
            }
        }

        /** Handle the placement of each juce::ToggleButton everytime the layout size is changed. */
        virtual void resized() override
        {
            int width, height;
            fIsVertical ? (height = (getHeight() - kNameHeight) / fButtons.size()) : (width = getWidth() / fButtons.size());

            for (int i = 0; i < fButtons.size(); i++) {
                if (fIsVertical) {
                    fButtons.operator[](i)->setBounds(0, i * height + kNameHeight, getWidth(), height);
                } else {
                    // kNameHeight pixels offset for the title
                    fButtons.operator[](i)->setBounds(i * width, kNameHeight, width, getHeight() - kNameHeight);
                }
            }
        }
        
        /** Display the RadioButton name */
        virtual void paint(juce::Graphics& g) override
        {
            g.setColour(juce::Colours::black);
            g.drawText(getName(), getLocalBounds().withHeight(kNameHeight), juce::Justification::centredTop);
        }

        /** Check which button is checked, and give its "value" to the FAUST module */
    void buttonClicked(juce::Button* button) override
        {
            juce::ToggleButton* checkButton = dynamic_cast<juce::ToggleButton*>(button);
            //std::cout << getName() << " : " << fButtons.indexOf(checkButton) << std::endl;
            modifyZone(fButtons.indexOf(checkButton));
        }
    
};

/**
 * \brief   Intern class for VU-meter
 * \details There is no JUCE widgets for VU-meter, so its fully designed in this class.
 */
class uiVUMeter : public uiComponent, public juce::SettableTooltipClient, public juce::Timer
{
    
    private:
    
        FAUSTFLOAT fLevel;               // Current level of the VU-meter.
        FAUSTFLOAT fMin, fMax;           // Linear range of the VU-meter.
        FAUSTFLOAT fScaleMin, fScaleMax; // Range in dB if needed.
        bool fDB;                        // True if it's a dB VU-meter, false otherwise.
        VUMeterType fStyle;
        juce::String fUnit;
        juce::Label fLabel;               // Name of the VU-meter.
    
        bool isNameDisplayed()
        {
            return (!(getName().startsWith("0x")) && getName().isNotEmpty());
        }
        
        /** Give the right coordinates and size to the text of Label depending on the VU-meter style */
        void setLabelPos()
        {
            if (fStyle == VVUMeter) {
                // -22 on the height because of the text box.
                fLabel.setBounds((getWidth()-50)/2, getHeight()-22, 50, 20);
            } else if (fStyle == HVUMeter) {
                isNameDisplayed() ? fLabel.setBounds(63, (getHeight()-20)/2, 50, 20)
                : fLabel.setBounds(3, (getHeight()-20)/2, 50, 20);
            } else if (fStyle == NumDisplay) {
                fLabel.setBounds((getWidth()-kNumDisplayWidth)/2,
                                 (getHeight()-kNumDisplayHeight/2)/2,
                                 kNumDisplayWidth,
                                 kNumDisplayHeight/2);
            }
        }
        
        /** Contain all the initialization need for our Label */
        void setupLabel(juce::String tooltip)
        {
            setLabelPos();
            fLabel.setEditable(false, false, false);
            fLabel.setJustificationType(juce::Justification::centred);
            fLabel.setText(juce::String((int)*fZone) + " " + fUnit, juce::dontSendNotification);
            fLabel.setTooltip(tooltip);
            addAndMakeVisible(fLabel);
        }
        
        /**
         * \brief   Generic method to draw an horizontal VU-meter.
         * \details Draw the background of the bargraph, and the TextBox box, without taking
         *          care of the actual level of the VU-meter
         * \see     drawHBargraphDB
         * \see     drawHBargraphLin
         *
         * \param   g       JUCE graphics context, used to draw components or images.
         * \param   width   Width of the VU-meter widget.
         * \param   height  Height of the VU-meter widget.
         * \param   level   Current level that needs to be displayed.
         * \param   dB      True if it's a db level, false otherwise.
         */
        void drawHBargraph(juce::Graphics& g, int width, int height)
        {
            float x;
            float y = (float)(getHeight()-height)/2;
            if (isNameDisplayed()) {
                x = 120;
                width -= x;
                // VUMeter Name
                g.setColour(juce::Colours::black);
                g.drawText(getName(), 0, y, 60, height, juce::Justification::centredRight);
            } else {
                x = 60;
                width -= x;
            }
            
            // VUMeter Background
            g.setColour(juce::Colours::lightgrey);
            g.fillRect(x, y, (float)width, (float)height);
            g.setColour(juce::Colours::black);
            g.fillRect(x+1.0f, y+1.0f, (float)width-2, (float)height-2);
            
            // Label Window
            g.setColour(juce::Colours::darkgrey);
            g.fillRect((int)x-58, (getHeight()-22)/2, 52, 22);
            g.setColour(juce::Colours::white.withAlpha(0.8f));
            g.fillRect((int)x-57, (getHeight()-20)/2, 50, 20);
            
            // Call the appropriate drawing method for the level.
            fDB ? drawHBargraphDB (g, y, height) : drawHBargraphLin(g, x, y, width, height);
        }
        
        /**
         * Method in charge of drawing the level of a horizontal dB VU-meter.
         *
         * \param   g       JUCE graphics context, used to draw components or images.
         * \param   y       y coordinate of the VU-meter.
         * \param   height  Height of the VU-meter.
         * \param   level   Current level of the VU-meter, in dB.
         */
        void drawHBargraphDB(juce::Graphics& g, int y, int height)
        {
            // Drawing Scale
            g.setFont(9.0f);
            g.setColour(juce::Colours::white);
            for (int i = -10; i > fMin; i -= 10) {
                paintScale(g, i);
            }
            for (int i = -6; i < fMax; i += 3)  {
                paintScale(g, i);
            }
            
            int alpha = 200;
            FAUSTFLOAT dblevel = dB2Scale(fLevel);
            
            // We need to test here every color changing levels, to avoid to mix colors because of the alpha,
            // and so to start the new color rectangle at the end of the previous one.
            
            // Drawing from the minimal range to the current level, or -10dB.
            g.setColour(juce::Colour((juce::uint8)40, (juce::uint8)160, (juce::uint8)40, (juce::uint8)alpha));
            g.fillRect(dB2x(fMin), y+1.0f, juce::jmin(dB2x(fLevel)-dB2x(fMin), dB2x(-10)-dB2x(fMin)), (float)height-2);
            
            // Drawing from -10dB to the current level, or -6dB.
            if (dblevel > dB2Scale(-10)) {
                g.setColour(juce::Colour((juce::uint8)160, (juce::uint8)220, (juce::uint8)20, (juce::uint8)alpha));
                g.fillRect(dB2x(-10), y+1.0f, juce::jmin(dB2x(fLevel)-dB2x(-10), dB2x(-6)-dB2x(-10)), (float)height-2);
            }
            // Drawing from -6dB to the current level, or -3dB.
            if (dblevel > dB2Scale(-6)) {
                g.setColour(juce::Colour((juce::uint8)220, (juce::uint8)220, (juce::uint8)20, (juce::uint8)alpha));
                g.fillRect(dB2x(-6), y+1.0f, juce::jmin(dB2x(fLevel)-dB2x(-6), dB2x(-3)-dB2x(-6)), (float)height-2);
            }
            // Drawing from -3dB to the current level, or 0dB.
            if (dblevel > dB2Scale(-3)) {
                g.setColour(juce::Colour((juce::uint8)240, (juce::uint8)160, (juce::uint8)20, (juce::uint8)alpha));
                g.fillRect(dB2x(-3), y+1.0f, juce::jmin(dB2x(fLevel)-dB2x(-3), dB2x(0)-dB2x(-3)), (float)height-2);
            }
            // Drawing from 0dB to the current level, or the max range.
            if (dblevel > dB2Scale(0)) {
                g.setColour(juce::Colour((juce::uint8)240, (juce::uint8)0, (juce::uint8)20, (juce::uint8)alpha));
                g.fillRect(dB2x(0), y+1.0f, juce::jmin(dB2x(fLevel)-dB2x(0), dB2x(fMax)-dB2x(0)), (float)height-2);
            }
        }
        
        /**
         * Method in charge of drawing the level of a horizontal linear VU-meter.
         *
         * \param   g       JUCE graphics context, used to draw components or images.
         * \param   x       x coordinate of the VU-meter.
         * \param   y       y coordinate of the VU-meter.
         * \param   height  Height of the VU-meter.
         * \param   width   Width of the VU-meter.
         * \param   level   Current level of the VU-meter, in linear logic.
         */
        void drawHBargraphLin(juce::Graphics& g, int x, int y, int width, int height)
        {
            int alpha = 200;
            juce::Colour c = juce::Colour((juce::uint8)255, (juce::uint8)165, (juce::uint8)0, (juce::uint8)alpha);
            
            // Drawing from the minimal range to the current level, or 20% of the VU-meter
            g.setColour(c.brighter());
            g.fillRect(x+1.0f, y+1.0f, juce::jmin<float>(fLevel*(width-2), 0.2f*(width-2)), (float)height-2);
            // Drawing from 20% of the VU-meter to the current level, or 90% of the VU-meter
            if (fLevel > 0.2f) {
                g.setColour(c);
                g.fillRect(x+1.0f + 0.2f*(width-2), y+1.0f, juce::jmin<float>((fLevel-0.2f) * (width-2), (0.9f-0.2f) * (width-2)), (float)height-2);
            }
            // Drawing from 90% of the VU-meter to the current level, or the maximal range of the VU-meter
            if (fLevel > 0.9f) {
                g.setColour(c.darker());
                g.fillRect(x+1.0f + 0.9f*(width-2), y+1.0f, juce::jmin<float>((fLevel-0.9f) * (width-2), (1.0f-0.9f) * (width-2)), (float)height-2);
            }
        }
        /**
         * \brief   Generic method to draw a vertical VU-meter.
         * \details Draw the background of the bargraph, and the TextBox box, without taking
         *          care of the actual level of the VU-meter
         * \see     drawHBargraphDB
         * \see     drawHBargraphLin
         *
         * \param   g       JUCE graphics context, used to draw components or images.
         * \param   width   Width of the VU-meter widget.
         * \param   height  Height of the VU-meter widget.
         * \param   level   Current level that needs to be displayed.
         * \param   dB      True if it's a db level, false otherwise.
         */
        void drawVBargraph(juce::Graphics& g, int width, int height)
        {
            float x = (float)(getWidth()-width)/2;
            float y;
            if (isNameDisplayed()) {
                y = (float)getHeight()-height+15;
                height -= 40;
                // VUMeter Name
                g.setColour(juce::Colours::black);
                g.drawText(getName(), getLocalBounds(), juce::Justification::centredTop);
            } else {
                y = (float)getHeight()-height;
                height -= 25;
            }
            
            // VUMeter Background
            g.setColour(juce::Colours::lightgrey);
            g.fillRect(x, y, (float)width, (float)height);
            g.setColour(juce::Colours::black);
            g.fillRect(x+1.0f, y+1.0f, (float)width-2, (float)height-2);
            
            // Label window
            g.setColour(juce::Colours::darkgrey);
            g.fillRect(juce::jmax((getWidth()-50)/2, 0), getHeight()-23, juce::jmin(getWidth(), 50), 22);
            g.setColour(juce::Colours::white.withAlpha(0.8f));
            g.fillRect(juce::jmax((getWidth()-48)/2, 1), getHeight()-22, juce::jmin(getWidth()-2, 48), 20);
            
            fDB ? drawVBargraphDB (g, x, width) : drawVBargraphLin(g, x, width);
        }
        
        /**
         * Method in charge of drawing the level of a vertical dB VU-meter.
         *
         * \param   g       JUCE graphics context, used to draw components or images.
         * \param   x       x coordinate of the VU-meter.
         * \param   width   Width of the VU-meter.
         * \param   level   Current level of the VU-meter, in dB.
         */
        void drawVBargraphDB(juce::Graphics& g, int x, int width)
        {
            // Drawing Scale
            g.setFont(9.0f);
            g.setColour(juce::Colours::white);
            for (int i = -10; i > fMin; i -= 10) {
                paintScale(g, i);
            }
            for (int i = -6; i < fMax; i += 3)  {
                paintScale(g, i);
            }
            
            int alpha = 200;
            FAUSTFLOAT dblevel = dB2Scale(fLevel);
            
            // We need to test here every color changing levels, to avoid to mix colors because of the alpha,
            // and so to start the new color rectangle at the end of the previous one.
            
            // Drawing from the minimal range to the current level, or -10dB.
            g.setColour(juce::Colour((juce::uint8)40, (juce::uint8)160, (juce::uint8)40, (juce::uint8)alpha));
            g.fillRect(x+1.0f, juce::jmax(dB2y(fLevel), dB2y(-10)), (float)width-2, dB2y(fMin)-juce::jmax(dB2y(fLevel), dB2y(-10)));
            
            // Drawing from -10dB to the current level, or -6dB.
            if (dblevel > dB2Scale(-10)) {
                g.setColour(juce::Colour((juce::uint8)160, (juce::uint8)220, (juce::uint8)20, (juce::uint8)alpha));
                g.fillRect(x+1.0f, juce::jmax(dB2y(fLevel), dB2y(-6)), (float)width-2, dB2y(-10)-juce::jmax(dB2y(fLevel), dB2y(-6)));
            }
            // Drawing from -6dB to the current level, or -3dB.
            if (dblevel > dB2Scale(-6)) {
                g.setColour(juce::Colour((juce::uint8)220, (juce::uint8)220, (juce::uint8)20, (juce::uint8)alpha));
                g.fillRect(x+1.0f, juce::jmax(dB2y(fLevel), dB2y(-3)), (float)width-2, dB2y(-6)-juce::jmax(dB2y(fLevel), dB2y(-3)));
            }
            // Drawing from -3dB to the current level, or 0dB.
            if (dblevel > dB2Scale(-3)) {
                g.setColour(juce::Colour((juce::uint8)240, (juce::uint8)160, (juce::uint8)20, (juce::uint8)alpha));
                g.fillRect(x+1.0f, juce::jmax(dB2y(fLevel), dB2y(0)), (float)width-2, dB2y(-3)-juce::jmax(dB2y(fLevel), dB2y(0)));
            }
            // Drawing from 0dB to the current level, or the maximum range.
            if (dblevel > dB2Scale(0)) {
                g.setColour(juce::Colour((juce::uint8)240, (juce::uint8)0, (juce::uint8)20, (juce::uint8)alpha));
                g.fillRect(x+1.0f, juce::jmax(dB2y(fLevel), dB2y(fMax)), (float)width-2, dB2y(0)-juce::jmax(dB2y(fLevel), dB2y(fMax)));
            }
        }
        
        /**
         * Method in charge of drawing the level of a vertical linear VU-meter.
         *
         * \param   g       JUCE graphics context, used to draw components or images.
         * \param   x       x coordinate of the VU-meter.
         * \param   width   Width of the VU-meter.
         * \param   level   Current level of the VU-meter, in linear logic.
         */
        void drawVBargraphLin(juce::Graphics& g, int x, int width)
        {
            int alpha = 200;
            juce::Colour c = juce::Colour((juce::uint8)255, (juce::uint8)165, (juce::uint8)0, (juce::uint8)alpha);
            
            // Drawing from the minimal range to the current level, or 20% of the VU-meter.
            g.setColour(c.brighter());
            g.fillRect(x+1.0f, juce::jmax(lin2y(fLevel), lin2y(0.2)), (float)width-2, lin2y(fMin)-juce::jmax(lin2y(fLevel), lin2y(0.2)));
            
            // Drawing from 20% of the VU-meter to the current level, or 90% of the VU-meter.
            if (fLevel > 0.2f) {
                g.setColour(c);
                g.fillRect(x+1.0f, juce::jmax(lin2y(fLevel), lin2y(0.9)), (float)width-2, lin2y(0.2)-juce::jmax(lin2y(fLevel), lin2y(0.9)));
            }
            
            // Drawing from 90% of the VU-meter to the current level, or the maximum range.
            if (fLevel > 0.9f) {
                g.setColour(c.darker());
                g.fillRect(x+1.0f, juce::jmax(lin2y(fLevel), lin2y(fMax)), (float)width-2, lin2y(0.9)-juce::jmax(lin2y(fLevel), lin2y(fMax)));
            }
        }
        
        /**
         * Method in charge of drawing the LED VU-meter, dB or not.
         *
         * \param   g       JUCE graphics context, used to draw components or images.
         * \param   width   Width of the LED.
         * \param   height  Height of the LED.
         * \param   level   Current level of the VU-meter, dB or not.
         */
        void drawLed(juce::Graphics& g, int width, int height)
        {
            float x = (float)(getWidth() - width)/2;
            float y = (float)(getHeight() - height)/2;
            g.setColour(juce::Colours::black);
            g.fillEllipse(x, y, width, height);
            
            if (fDB) {
                int alpha = 200;
                FAUSTFLOAT dblevel = dB2Scale(fLevel);
                
                // Adjust the color depending on the current level
                g.setColour(juce::Colour((juce::uint8)40, (juce::uint8)160, (juce::uint8)40, (juce::uint8)alpha));
                if (dblevel > dB2Scale(-10)) {
                    g.setColour(juce::Colour((juce::uint8)160, (juce::uint8)220, (juce::uint8)20, (juce::uint8)alpha));
                }
                if (dblevel > dB2Scale(-6)) {
                    g.setColour(juce::Colour((juce::uint8)220, (juce::uint8)220, (juce::uint8)20, (juce::uint8)alpha));
                }
                if (dblevel > dB2Scale(-3)) {
                    g.setColour(juce::Colour((juce::uint8)240, (juce::uint8)160, (juce::uint8)20, (juce::uint8)alpha));
                }
                if (dblevel > dB2Scale(0))  {
                    g.setColour(juce::Colour((juce::uint8)240, (juce::uint8)0, (juce::uint8)20, (juce::uint8)alpha));
                }
                
                g.fillEllipse(x+1, y+1, width-2, height-2);
            } else {
                // The alpha depend on the level, from 0 to 1
                g.setColour(juce::Colours::red.withAlpha((float)fLevel));
                g.fillEllipse(x+1, y+1, width-2, height-2);
            }
        }
        
        /**
         * Method in charge of drawing the Numerical Display VU-meter, dB or not.
         *
         * \param   g       JUCE graphics context, used to draw components or images.
         * \param   width   Width of the Numerical Display.
         * \param   height  Height of the Numerical Display.
         * \param   level   Current level of the VU-meter.
         */
        void drawNumDisplay(juce::Graphics& g, int width, int height)
        {
            // Centering it
            int x = (getWidth()-width) / 2;
            int y = (getHeight()-height) / 2;
            
            // Draw box.
            g.setColour(juce::Colours::darkgrey);
            g.fillRect(x, y, width, height);
            g.setColour(juce::Colours::white.withAlpha(0.8f));
            g.fillRect(x+1, y+1, width-2, height-2);
            
            // Text is handled by the setLabelPos() function
        }
        
        /** Convert a dB level to a y coordinate, for easier draw methods. */
        FAUSTFLOAT dB2y(FAUSTFLOAT dB)
        {
            FAUSTFLOAT s0 = fScaleMin;      // Minimal range.
            FAUSTFLOAT s1 = fScaleMax;      // Maximum range.
            FAUSTFLOAT sx = dB2Scale(dB);   // Current level.
            
            int h;
            int treshold;   // Value depend if the name is displayed
            
            if (isNameDisplayed()) {
                h = getHeight()-42; // 15 pixels for the VU-Meter name,
                // 25 for the textBox, 2 pixels margin.
                treshold = 16;      // 15 pixels for the VU-Meter name.
            } else {
                h = getHeight()-27; // 25 for the textBox, 2 pixels margin.
                treshold = 1;       // 1 pixel margin.
            }
            
            return (h - h*(s0-sx)/(s0-s1)) + treshold;
        }
        
        /** Convert a linear level to a y coordinate, for easier draw methods. */
        FAUSTFLOAT lin2y(FAUSTFLOAT level)
        {
            int h;
            int treshold;
            
            if (isNameDisplayed()) {
                h = getHeight()-42; // 15 pixels for the VU-Meter name,
                // 25 for the textBox, 2 pixels margin.
                treshold = 16;      // 15 pixels for the VU-Meter name.
            } else {
                h = getHeight()-27; // 25 for the textBox, 2 pixels margin.
                treshold = 1;       // 1 pixel margin.
            }
            
            return h * (1 - level) + treshold;
        }
        
        /** Convert a dB level to a x coordinate, for easier draw methods. */
        FAUSTFLOAT dB2x(FAUSTFLOAT dB)
        {
            FAUSTFLOAT s0 = fScaleMin;      // Minimal range.
            FAUSTFLOAT s1 = fScaleMax;      // Maximal range.
            FAUSTFLOAT sx = dB2Scale(dB);   // Current level.
            
            int w;
            int treshold;
            
            if (isNameDisplayed()) {
                w = getWidth()-122; // 60 pixels for the VU-Meter name,
                // 60 for the TextBox, 2 pixels margin.
                treshold = 121;     // 60 pixels for the VU-Meter name,
                // 60 for the TextBox, and 1 pixel margin.
            } else {
                w = getWidth()-62;  // 60 pixels for the TextBox, 2 pixels margin.
                treshold = 61;      // 60 pixels for the TextBox, 1 pixel margin.
            }
            
            return treshold + w - w*(s1-sx)/(s1-s0);
        }
        
        /** Write the different level included in the VU-Meter range. */
        void paintScale(juce::Graphics& g, float num)
        {
            juce::Rectangle<int> r;
            
            if (fStyle == VVUMeter) {
                r = juce::Rectangle<int>((getWidth()-(kVBargraphWidth/2))/2 + 1,  // Left side of the VU-Meter.
                                         dB2y(num),                               // Vertically centred with 20 height.
                                         (kVBargraphWidth/2)-2,                   // VU-Meter width with margin.
                                         20);                                     // 20 height.
                g.drawText(juce::String(num), r, juce::Justification::centredRight, false);
            } else {
                r = juce::Rectangle<int>(dB2x(num)-10,                            // Horizontally centred with 20 width.
                                        (getHeight()-kHBargraphHeight/2)/2 + 1,  // Top side of the VU-Meter.
                                        20,                                      // 20 width.
                                        (kHBargraphHeight/2)-2);                 // VU-Meter height with margin
                g.drawText(juce::String(num), r, juce::Justification::centredTop, false);
            }
        }
        
        /** Set the level, keep it in the range of the VU-Meter, and set the TextBox text. */
        void setLevel()
        {
            FAUSTFLOAT rawLevel = *fZone;
        #if JUCE_DEBUG
            if (std::isnan(rawLevel)) {
                std::cerr << "uiVUMeter: NAN\n";
            }
        #endif
            if (fDB) {
                fLevel = range(rawLevel);
            } else {
                fLevel = range((rawLevel-fMin)/(fMax-fMin));
            }
            fLabel.setText(juce::String((int)rawLevel) + " " + fUnit, juce::dontSendNotification);
        }
        
        FAUSTFLOAT range(FAUSTFLOAT level) { return (level > fMax) ? fMax : ((level < fMin) ? fMin : level); }
    
    public:
    
        /**
         * \brief   Constructor.
         * \details Initialize the uiComponent variables and the VU-meter specific ones.
         *
         * \param   gui, zone, w, h, tooltip, label     uiComponent variables.
         * \param   mini                                Minimal value of the VU-meter range.
         * \param   maxi                                Maximal value of the VU-meter range.
         * \param   unit                                Unit of the VU-meter (dB or not).
         * \param   style                               Type of the VU-meter (see VUMeterType).
         * \param   vert                                True if vertical, false if horizontal.
         */
        uiVUMeter (GUI* gui, FAUSTFLOAT* zone, FAUSTFLOAT w, FAUSTFLOAT h, juce::String label, FAUSTFLOAT mini, FAUSTFLOAT maxi, juce::String unit, juce::String tooltip, VUMeterType style, bool vert)
            : uiComponent(gui, zone, w, h, label), fMin(mini), fMax(maxi), fStyle(style)
        {
            fLevel = 0;         // Initialization of the level
            startTimer(50);     // Launch a timer that trigger a callback every 50ms
            this->fUnit = unit;
            fDB = (unit == "dB");
            
            if (fDB) {
                // Conversion in dB of the range
                fScaleMin = dB2Scale(fMin);
                fScaleMax = dB2Scale(fMax);
            }
            setTooltip(tooltip);
            
            // No text editor for LEDs
            if (fStyle != Led) {
                setupLabel(tooltip);
            }
        }
        
        /** Method called by the timer every 50ms, to refresh the VU-meter if it needs to */
        void timerCallback() override
        {
            if (isShowing()) {
                //Force painting at the initialisation
                bool forceRepaint = (fLevel == 0);
                FAUSTFLOAT lastLevel = fLevel;   //t-1
                setLevel(); //t
                
                // Following condition means that we're repainting our VUMeter only if
                // there's one or more changing pixels between last state and this one,
                // and if the curent level is included in the VUMeter range. It improves
                // performances a lot in IDLE. It's the same for the other style of VUMeter
                
                if (fDB) {
                    switch (fStyle) {
                        case VVUMeter:
                            if (((int)dB2y(lastLevel) != (int)dB2y(fLevel) && fLevel >= fMin && fLevel <= fMax) || forceRepaint) {
                                repaint();
                            }
                            break;
                        case HVUMeter:
                            if (((int)dB2x(lastLevel) != (int)dB2x(fLevel) && fLevel >= fMin && fLevel <= fMax) || forceRepaint) {
                                repaint();
                            }
                            break;
                        case NumDisplay:
                            if (((int)lastLevel != (int)fLevel && fLevel >= fMin && fLevel <= fMax) || forceRepaint) {
                                repaint();
                            }
                            break;
                        case Led:
                            if ((dB2Scale(lastLevel) != dB2Scale(fLevel) && fLevel >= fMin && fLevel <= fMax) || forceRepaint) {
                                repaint();
                            }
                            break;
                        default:
                            break;
                    }
                } else {
                    switch (fStyle) {
                        case VVUMeter:
                            if (((int)lin2y(lastLevel) != (int)lin2y(fLevel) && fLevel >= fMin && fLevel <= fMax) || forceRepaint) {
                                repaint();
                            }
                            break;
                        case HVUMeter:
                            if ((std::abs(lastLevel-fLevel) > 0.01 && fLevel >= fMin && fLevel <= fMax) || forceRepaint) {
                                repaint();
                            }
                            break;
                        case NumDisplay:
                            if ((std::abs(lastLevel-fLevel) > 0.01 && fLevel >= fMin && fLevel <= fMax) || forceRepaint) {
                                repaint();
                            }
                            break;
                        case Led:
                            if (((int)lastLevel != (int)fLevel && fLevel >= fMin && fLevel <= fMax) || forceRepaint) {
                                repaint();
                            }
                            break;
                        default:
                            break;
                    }
                }
            } else {
                fLevel = 0;
            }
        }
        
        /**
         * Call the appropriate drawing method according to the VU-meter style
         * \see drawLed
         * \see drawNumDisplay
         * \see drawVBargraph
         * \see drawHBargraph
         */
        void paint(juce::Graphics& g) override
        {
            switch (fStyle) {
                case Led:
                    drawLed(g, kLedWidth, kLedHeight);
                    break;
                case NumDisplay:
                    drawNumDisplay(g, kNumDisplayWidth, kNumDisplayHeight/2);
                    break;
                case VVUMeter:
                    drawVBargraph(g, kVBargraphWidth/2, getHeight());
                    break;
                case HVUMeter:
                    drawHBargraph(g, getWidth(), kHBargraphHeight/2);
                    break;
                default:
                    break;
            }
        }
        
        /** Set the Label position whenever the layout size changes. */
        void resized() override
        {
            setLabelPos();
        }
        
        void reflectZone() override
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
        }
    
};

/** Intern class for tab widget */
class uiTabBox : public uiBase, public juce::TabbedComponent
{
    
public:
    /**
     * \brief   Constructor.
     * \details Initalize the juce::TabbedComponent tabs to be at top, and the uiTabBox size at 0
     */
    uiTabBox():uiBase(),juce::TabbedComponent(juce::TabbedButtonBar::TabsAtTop)
    {}
    
    /**
     * Initialize all his child ratios (1 uiBox per tabs), the LookAndFeel
     * and the uiTabBox size to fit the biggest of its child.
     */
    void init(juce::Component* comp = nullptr) override
    {
        for (int i = 0; i < getNumTabs(); i++) {
            Component* comp = getTabContentComponent(i);
            uiBase* base_comp = dynamic_cast<uiBase*>(comp);
            base_comp->init(comp);
            
            // The TabbedComponent size should be as big as its bigger child's dimension, done here
            fTotalWidth = juce::jmax(fTotalWidth, base_comp->getTotalWidth());
            fTotalHeight = juce::jmax(fTotalHeight, base_comp->getTotalHeight());
        }
        
        fTotalHeight += 30;  // 30 height for the TabBar.
    }
    
    void setRecommendedSize() override
    {
        for (int i = 0; i < getNumTabs(); i++) {
            uiBase* comp = dynamic_cast<uiBase*>(getTabContentComponent(i));
            comp->setRecommendedSize();
            
            // The TabbedComponent size should be as big as its bigger child's dimension, done here
            fTotalWidth = juce::jmax(fTotalWidth, comp->getTotalWidth());
            fTotalHeight = juce::jmax(fTotalHeight, comp->getTotalHeight());
        }
        
        fTotalHeight += 30;  // 30 height for the TabBar
    }
    
    void add(Component* comp) override
    {
        // Name of the component is moved in Tab (so removed from component)
        juce::TabbedComponent::addTab(comp->getName(), juce::Colours::white, comp, true);
        comp->setName("");
    }
    
};

/**
 * \brief   Intern class for box widgets
 * \details That's the class where the whole layout is calculated.
 */
class uiBox : public uiBase, public juce::Component
{
  
    private:
    
        bool fIsVertical;
    
        bool isNameDisplayed()
        {
            return (!(getName().startsWith("0x")) && getName().isNotEmpty());
        }
    
        /**
         * \brief   Return the vertical dimension size for a child to be displayed in.
         *
         */
        int getVSpaceToRemove()
        {
            // Checking if the name is displayed, to give to good amount space for child components
            // kNameHeight pixels is the bix name, kMargin pixel per child components for the margins
            if (isNameDisplayed()) {
                return (getHeight() - kNameHeight - kMargin * getNumChildComponents());
            } else {
                return (getHeight() - kMargin * getNumChildComponents());
            }
        }
    
        /**
         * \brief   Return the vertical dimension size for a child to be displayed in.
         *
         */
        int getHSpaceToRemove()
        {
            // Don't need to check for an horizontal box, as it height doesn't matter
            return (getWidth() - kMargin * getNumChildComponents());
        }
    
    public:
        /**
         * \brief   Constructor.
         * \details Initialize uiBase variables and uiBox specific ones.
         *
         * \param   vert        True if it's a vertical box, false otherwise.
         * \param   boxName     Name of the uiBox.
         */
        uiBox(bool vert, juce::String boxName): uiBase(0,0), juce::Component(boxName), fIsVertical(vert)
        {}
    
        /**
         * \brief   Destructor.
         * \details Delete all uiBox recusively, but not the uiComponent,
         *          because it's handled by the uiItem FAUST objects.
         */
        virtual ~uiBox()
        {
            /*
             Deleting boxes, from leaves to root:
             - leaves (uiComponent) are deleted by the uiItem mechanism
             - containers (uiBox and uiTabBox) have to be explicitly deleted
             */
            for (int i = getNumChildComponents()-1; i >= 0; i--) {
                delete dynamic_cast<uiBox*>(getChildComponent(i));
                delete dynamic_cast<uiTabBox*>(getChildComponent(i));
            }
        }

        /**
         * \brief   Initialization of the DisplayRect and Total size.
         * \details Calculate the correct size for each box, depending on its child sizes.
         */
        void setRecommendedSize() override
        {
            // Initialized each time
            fDisplayRectWidth = fDisplayRectHeight = 0;
            
            // Display rectangle size is the sum of a dimension on a side, and the max of the other one
            // on the other side, depending on its orientation (horizontal/vertical).
            // Using child's totalSize, because the display rectangle size need to be as big as
            // all of its child components with their margins included.
            for (int j = 0; j < getNumChildComponents(); j++) {
                uiBase* base_comp = dynamic_cast<uiBase*>(getChildComponent(j));
                if (fIsVertical) {
                    fDisplayRectWidth = juce::jmax(fDisplayRectWidth, base_comp->getTotalWidth());
                    fDisplayRectHeight += base_comp->getTotalHeight();
                } else {
                    fDisplayRectWidth += base_comp->getTotalWidth();
                    fDisplayRectHeight = juce::jmax(fDisplayRectHeight, base_comp->getTotalHeight());
                }
            }
            
            fTotalHeight = fDisplayRectHeight;
            fTotalWidth = fDisplayRectWidth;
            
            // Adding kMargin pixels of margins per child component on a dimension, and just kMargin on
            // the other one, depending on its orientation
            
            if (fIsVertical) {
                fTotalHeight += kMargin * getNumChildComponents();
                fTotalWidth += kMargin;
            } else {
                fTotalWidth += kMargin * getNumChildComponents();
                fTotalHeight += kMargin;
            }
         
            // Adding kNameHeight pixels on its height to allow the name to be displayed
            if (isNameDisplayed()) {
                fTotalHeight += kNameHeight;
            }
        }

        /** Initiate the current box ratio, and its child's ones recursively. */
        void init(juce::Component* comp = nullptr) override
        {
            uiBase::init(this);
            
            // Going through the Component tree recursively
            for (int i = 0; i < getNumChildComponents(); i++) {
                Component* comp = getChildComponent(i);
                uiBase* base_comp = dynamic_cast<uiBase*>(comp);
                base_comp->init(comp);
            }
        }

        /**
         * \brief   Main layout function.
         * \details Allow to place all uiBase child correctly according to their ratios
         *          and the current box size.
         *
         * \param   displayRect    Absolute raw bounds of the current box (with margins
         *                          and space for the title).
         */
        void resized() override
        {
            juce::Rectangle<int> displayRect = getBounds();
            
            // Deleting space for the box name if it needs to be shown
            if (isNameDisplayed()) {
                displayRect.removeFromTop(kNameHeight);
            }
            
            // Putting the margins
            displayRect.reduce(kMargin/2, kMargin/2);
            
            // Give child components an adapt size depending on its ratio and the current box size
            for (int i = 0; i < getNumChildComponents(); i++) {
                juce::Component* comp = getChildComponent(i);
                uiBase* base_comp = dynamic_cast<uiBase*>(comp);
                
                if (fIsVertical) {
                    int heightToRemove = getVSpaceToRemove() * base_comp->getVRatio();
                    // Remove the space needed from the displayRect, and translate it to show the margins
                    base_comp->setRelativeSize(comp, displayRect.removeFromTop(heightToRemove).translated(0, kMargin * i));
                } else {
                    int widthToRemove = getHSpaceToRemove() * base_comp->getHRatio();
                    // Remove the space needed from the displayRect, and translate it to show the margins
                    base_comp->setRelativeSize(comp, displayRect.removeFromLeft(widthToRemove).translated(kMargin * i, 0));
                }
            }
        }

        /** 
         * Fill the uiBox bounds with a grey color, different shades depending on its order.
         * Write the uiBox name if it needs to.
         */
        void paint(juce::Graphics& g) override
        {
            // Fill the box background in gray shades
            g.setColour(juce::Colours::black.withAlpha(0.05f));
            g.fillRect(getLocalBounds());

            // Display the name if it's needed
            if (isNameDisplayed()) {
                g.setColour(juce::Colours::black);
                g.drawText(getName(), getLocalBounds().withHeight(kNameHeight), juce::Justification::centred);
            }
        }
        
        void add(juce::Component* comp) override
        {
            addAndMakeVisible(comp);
        }
    
};

/** Class in charge of doing the glue between FAUST and JUCE */
class JuceGUI : public GUI, public MetaDataUI, public juce::Component
{
    
    private:
    
        std::stack<uiBase*> fBoxStack;
        uiBase* fCurrentBox = nullptr;   // Current box used in buildUserInterface logic.
        
        int fRadioGroupID;               // In case of radio buttons.
        std::unique_ptr<juce::LookAndFeel> fLaf = std::make_unique<juce::LookAndFeel_V4>();
    
        /** Add generic box to the user interface. */
        void openBox(uiBase* box)
        {
            if (fCurrentBox) {
                fCurrentBox->add(dynamic_cast<juce::Component*>(box));
                fBoxStack.push(fCurrentBox);
            }
            fCurrentBox = box;
        }
     
        /** Add a slider to the user interface. */
        void addSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step, int kWidth, int kHeight, SliderType type)
        {
            if (isKnob(zone)) {
                addKnob(label, zone, *zone, min, max, step);
            } else if (isRadio(zone)) {
                addRadioButtons(label, zone, *zone, min, max, step, fRadioDescription[zone].c_str(), false);
            } else if (isMenu(zone)) {
                addMenu(label, zone, *zone, min, max, step, fMenuDescription[zone].c_str());
            } else {
                fCurrentBox->add(new uiSlider(this, zone, kWidth, kHeight, *zone, min, max, step, juce::String(label), juce::String(fUnit[zone]), juce::String(fTooltip[zone]), getScale(zone), type));
            }
        }
        
        /** Add a radio buttons to the user interface. */
        void addRadioButtons(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step, const char* mdescr, bool vert)
        {
            std::vector<std::string> names;
            std::vector<double> values;
            parseMenuList(mdescr, names, values); // Set names and values vectors
            
            // and not just n checkButtons :
            // TODO : check currently unused checkButtonWidth...
            int checkButtonWidth = 0;
            for (int i = 0; i < names.size(); i++) {
                // Checking the maximum of horizontal space needed to display the radio buttons
                checkButtonWidth = juce::jmax(juce::Font().getStringWidth(juce::String(names[i])) + 15, checkButtonWidth);
            }
            
            if (vert) {
                fCurrentBox->add(new uiRadioButton(this, zone, juce::String(label), kCheckButtonWidth, names.size() * (kRadioButtonHeight - 25) + 25, *zone, min, max, true, names, values, juce::String(fTooltip[zone]), fRadioGroupID++));
            } else {
                fCurrentBox->add(new uiRadioButton(this, zone, juce::String(label), kCheckButtonWidth, kRadioButtonHeight, *zone, min, max, false, names, values, juce::String(fTooltip[zone]), fRadioGroupID++));
            }
        }
        
        /** Add a menu to the user interface. */
        void addMenu(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step, const char* mdescr)
        {
            fCurrentBox->add(new uiMenu(this, zone, juce::String(label), kMenuWidth, kMenuHeight, *zone, min, max, juce::String(fTooltip[zone]), mdescr));
        }
        
        /** Add a ciruclar slider to the user interface. */
        void addKnob(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {
            fCurrentBox->add(new uiSlider(this, zone, kKnobWidth, kKnobHeight, *zone, min, max, step, juce::String(label), juce::String(fUnit[zone]), juce::String(fTooltip[zone]), getScale(zone), Knob));
        }
        
        /** Add a bargraph to the user interface. */
        void addBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, int kWidth, int kHeight, VUMeterType type)
        {
            if (isLed(zone)) {
                addLed(juce::String(label), zone, min, max);
            } else if (isNumerical(zone)) {
                addNumericalDisplay(juce::String(label), zone, min, max);
            } else {
                fCurrentBox->add(new uiVUMeter (this, zone, kWidth, kHeight, juce::String(label), min, max, juce::String(fUnit[zone]), juce::String(fTooltip[zone]), type, false));
            }
        }
        
    public:
        /**
         * \brief   Constructor, displaying the *current state* of all controller zones.
         * \details Initialize the JuceGUI specific variables. 
         */
        JuceGUI():fRadioGroupID(1) // fRadioGroupID must start at 1
        {
            setLookAndFeel(fLaf.get());
        }
        
        /**
         * \brief   Destructor.
         * \details Delete root box used in buildUserInterface logic.
         */
        virtual ~JuceGUI()
        {
            setLookAndFeel(nullptr);
            delete fCurrentBox;
        }

        /** Return the size of the FAUST program */
        juce::Rectangle<int> getSize()
        {
            // Mininum size in case of empty GUI
            if (fCurrentBox) {
                juce::Rectangle<int> res = fCurrentBox->getSize();
                res.setSize(std::max<int>(1, res.getWidth()), std::max<int>(1, res.getHeight()));
                return res;
            } else {
                return juce::Rectangle<int>(0, 0, 1, 1);
            }
        }

        /** Initialize the uiTabBox component to be visible. */
        virtual void openTabBox(const char* label) override
        {
            openBox(new uiTabBox());
        }
        
        /** Add a new vertical box to the user interface. */
        virtual void openVerticalBox(const char* label) override
        {
            openBox(new uiBox(true, juce::String(label)));
        }

        /** Add a new horizontal box to the user interface. */
        virtual void openHorizontalBox(const char* label) override
        {
            openBox(new uiBox(false, juce::String(label)));
        }

        /** Close the current box. */
        virtual void closeBox() override
        {
            fCurrentBox->setRecommendedSize();
            
            if (fBoxStack.empty()) {
                // Add root box in JuceGUI component
                addAndMakeVisible(dynamic_cast<juce::Component*>(fCurrentBox));
                fCurrentBox->init();
                // Force correct draw
                resized();
            } else {
                fCurrentBox = fBoxStack.top();
                fBoxStack.pop();
            }
        }
     
        /** Add an horizontal slider to the user interface. */
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override
        {
            if (isHidden(zone)) return;
            addSlider(label, zone, init, min, max, step, kHSliderWidth, kHSliderHeight, HSlider);
        }
        
        /** Add a vertical slider to the user interface. */
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override
        {
            if (isHidden(zone)) return;
            int newWidth = juce::jmax(juce::Font().getStringWidth(juce::String(label)), kVSliderWidth) + kMargin;
            addSlider(label, zone, init, min, max, step, newWidth, kVSliderHeight, VSlider);
        }
        
        /** Add a button to the user interface. */
        virtual void addButton(const char* label, FAUSTFLOAT* zone) override
        {
            if (isHidden(zone)) return;
            fCurrentBox->add(new uiButton(this, zone, kButtonWidth, kButtonHeight, juce::String(label), juce::String(fTooltip[zone])));
        }
        
        /** Add a check button to the user interface. */
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) override
        {
            if (isHidden(zone)) return;
            // newWidth is his text size, plus the check box size
            int newWidth = juce::Font().getStringWidth(juce::String(label)) + kCheckButtonWidth;
            fCurrentBox->add(new uiCheckButton(this, zone, newWidth, kCheckButtonHeight, juce::String(label), juce::String(fTooltip[zone])));
        }
        
        /** Add a numerical entry to the user interface. */
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override
        {
            if (isHidden(zone)) return;
            // kMargin pixels between the slider and his name
            int newWidth = juce::Font().getStringWidth(juce::String(label)) + kNumEntryWidth + kMargin;
            fCurrentBox->add(new uiSlider(this, zone, newWidth, kNumEntryHeight, *zone, min, max, step, juce::String(label), juce::String(fUnit[zone]), juce::String(fTooltip[zone]), getScale(zone), NumEntry));
        }
        
        /** Add a vertical bargraph to the user interface. */
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override
        {
            if (isHidden(zone)) return;
            addBargraph(label, zone, min, max, kVBargraphWidth, kVBargraphHeight, VVUMeter);
        }
        
        /** Add a vertical bargraph to the user interface. */
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override
        {
            if (isHidden(zone)) return;
            addBargraph(label, zone, min, max, kHBargraphWidth, kHBargraphHeight, HVUMeter);
        }
      
        /** Add a LED to the user interface. */
        void addLed(juce::String label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            fCurrentBox->add(new uiVUMeter(this, zone, kLedWidth, kLedHeight, label, min, max, juce::String(fUnit[zone]), juce::String(fTooltip[zone]), Led, false));
        }
        
        /** Add a numerical display to the user interface. */
        void addNumericalDisplay(juce::String label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {
            fCurrentBox->add(new uiVUMeter(this, zone, kNumDisplayWidth, kNumDisplayHeight, label, min, max, juce::String(fUnit[zone]), juce::String(fTooltip[zone]), NumDisplay, false));
        }
        
        /** Declare a metadata. */
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* value) override
        {
            MetaDataUI::declare(zone, key, value);
        }

        /** Resize its child to match the new bounds */
        void resized() override
        {
            if (fCurrentBox) {
                dynamic_cast<Component*>(fCurrentBox)->setBounds(getLocalBounds());
            }
        }
    
};

#endif
/**************************  END  JuceGUI.h **************************/
#endif
/************************** BEGIN JuceParameterUI.h *************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef JuceParameterUI_H
#define JuceParameterUI_H

#include "../JuceLibraryCode/JuceHeader.h"


// Link AudioParameterBool with on/off parameter

struct FaustPlugInAudioParameterBool : public juce::AudioParameterBool, public uiOwnedItem {
    
    FaustPlugInAudioParameterBool(GUI* gui, FAUSTFLOAT* zone, const std::string& path, const std::string& label)
    :juce::AudioParameterBool(path, label, false), uiOwnedItem(gui, zone)
    {}
    
    virtual ~FaustPlugInAudioParameterBool() {}
    
    void reflectZone() override
    {
        FAUSTFLOAT v = *fZone;
        fCache = v;
        setValueNotifyingHost(float(v));
    }
    
    virtual void setValue (float newValue) override
    {
        modifyZone(FAUSTFLOAT(newValue));
    }
    
};

// Link AudioParameterFloat with range parameters

struct FaustPlugInAudioParameterFloat : public juce::AudioParameterFloat, public uiOwnedItem {
    
    FaustPlugInAudioParameterFloat(GUI* gui, FAUSTFLOAT* zone, const std::string& path, const std::string& label, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    :juce::AudioParameterFloat(path, label, float(min), float(max), float(init)), uiOwnedItem(gui, zone)
    {}
    
    virtual ~FaustPlugInAudioParameterFloat() {}
    
    void reflectZone() override
    {
        FAUSTFLOAT v = *fZone;
        fCache = v;
        if (v >= range.start && v <= range.end) {
            setValueNotifyingHost(range.convertTo0to1(float(v)));
        }
    }
    
    virtual void setValue (float newValue) override
    {
        modifyZone(FAUSTFLOAT(range.convertFrom0to1(newValue)));
    }
    
};

// A class to create AudioProcessorParameter objects for each zone

class JuceParameterUI : public GUI, public PathBuilder {
    
    private:
        
        juce::AudioProcessor* fProcessor;
        
    public:
        
        JuceParameterUI(juce::AudioProcessor* processor):fProcessor(processor)
        {}
    
        virtual ~JuceParameterUI() {}
        
        // -- widget's layouts
        
        virtual void openTabBox(const char* label)
        {
            pushLabel(label);
        }
        virtual void openHorizontalBox(const char* label)
        {
            pushLabel(label);
        }
        virtual void openVerticalBox(const char* label)
        {
            pushLabel(label);
        }
        virtual void closeBox()
        {
            popLabel();
        }
        
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            fProcessor->addParameter(new FaustPlugInAudioParameterBool(this, zone, buildPath(label), label));
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            fProcessor->addParameter(new FaustPlugInAudioParameterBool(this, zone, buildPath(label), label));
        }
        
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            fProcessor->addParameter(new FaustPlugInAudioParameterFloat(this, zone, buildPath(label), label, init, min, max, step));
        }
        
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            fProcessor->addParameter(new FaustPlugInAudioParameterFloat(this, zone, buildPath(label), label, init, min, max, step));
        }
        
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            fProcessor->addParameter(new FaustPlugInAudioParameterFloat(this, zone, buildPath(label), label, init, min, max, step));
        }
        
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            fProcessor->addParameter(new FaustPlugInAudioParameterFloat(this, zone, buildPath(label), label, 0, min, max, 0));
        }
        
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            fProcessor->addParameter(new FaustPlugInAudioParameterFloat(this, zone, buildPath(label), label, 0, min, max, 0));
        }
    
};

#endif
/**************************  END  JuceParameterUI.h **************************/
/************************** BEGIN JuceStateUI.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef JuceStateUI_H
#define JuceStateUI_H

#include "../JuceLibraryCode/JuceHeader.h"


// A class to save/restore DSP state using JUCE, which also set default values at construction time.

struct JuceStateUI : public MapUI {
    
    bool fRestored;
    
    JuceStateUI():fRestored(false) {}
    virtual ~JuceStateUI() {}
    
    void getStateInformation (juce::MemoryBlock& destData)
    {
        juce::MemoryOutputStream stream (destData, true);
        
        // Write path and values
        if (sizeof(FAUSTFLOAT) == sizeof(float)) {
            for (const auto& it : getFullpathMap()) {
                stream.writeString(it.first);
                stream.writeFloat(*it.second);
            }
        } else {
            for (const auto& it : getFullpathMap()) {
                stream.writeString(it.first);
                stream.writeDouble(*it.second);
            }
        }
    }
    
    void setStateInformation (const void* data, int sizeInBytes)
    {
        fRestored = true;
        juce::MemoryInputStream stream (data, static_cast<size_t> (sizeInBytes), false);
        std::string path;
        
        // Read path then value and try to restore them
        if (sizeof(FAUSTFLOAT) == sizeof(float)) {
            while ((path = stream.readString().toStdString()) != "") {
                setParamValue(path, stream.readFloat());
            }
        } else {
            while ((path = stream.readString().toStdString()) != "") {
                setParamValue(path, stream.readDouble());
            }
        }
    }
    
    // -- active widgets
    // use MapUI derived methods
    
    // -- passive widgets
    // empty si we don't want to save/restore them
    void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax) {}
    void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax) {}
    
};

#endif
/**************************  END  JuceStateUI.h **************************/

// Always included otherwise -i mode sometimes fails...

#if defined(SOUNDFILE)
/************************** BEGIN SoundUI.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/
 
#ifndef __SoundUI_H__
#define __SoundUI_H__

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <memory>


#if defined(__APPLE__) && !defined(__VCVRACK__) && !defined(JUCE_32BIT) && !defined(JUCE_64BIT)
#include <CoreFoundation/CFBundle.h>
#endif

// Always included otherwise -i mode later on will not always include it (with the conditional includes)
/************************** BEGIN Soundfile.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef __Soundfile__
#define __Soundfile__

#include <string.h>
#include <string>
#include <vector>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#define BUFFER_SIZE 1024
#define SAMPLE_RATE 44100
#define MAX_CHAN 64
#define MAX_SOUNDFILE_PARTS 256

#ifdef _MSC_VER
#define PRE_PACKED_STRUCTURE __pragma(pack(push, 1))
#define POST_PACKED_STRUCTURE \
    ;                         \
    __pragma(pack(pop))
#else
#define PRE_PACKED_STRUCTURE
#define POST_PACKED_STRUCTURE __attribute__((__packed__))
#endif

/*
 The soundfile structure to be used by the DSP code. Soundfile has a MAX_SOUNDFILE_PARTS parts 
 (even a single soundfile or an empty soundfile). 
 The fLength, fOffset and fSR fields are filled accordingly by repeating the actual parts if needed.
 The fBuffers contains MAX_CHAN non-interleaved arrays of samples.
 
 It has to be 'packed' to that the LLVM backend can correctly access it.

 Index computation:
    - p is the current part number [0..MAX_SOUNDFILE_PARTS-1] (must be proved by the type system)
    - i is the current position in the part. It will be constrained between [0..length]
    - idx(p,i) = fOffset[p] + max(0, min(i, fLength[p]));
*/

PRE_PACKED_STRUCTURE
struct Soundfile {
    void* fBuffers; // will correspond to a double** or float** pointer chosen at runtime
    int* fLength;   // length of each part (so fLength[P] contains the length in frames of part P)
    int* fSR;       // sample rate of each part (so fSR[P] contains the SR of part P)
    int* fOffset;   // offset of each part in the global buffer (so fOffset[P] contains the offset in frames of part P)
    int fChannels;  // max number of channels of all concatenated files
    int fParts;     // the total number of loaded parts
    bool fIsDouble; // keep the sample format (float or double)

    Soundfile(int cur_chan, int length, int max_chan, int total_parts, bool is_double)
    {
        fLength   = new int[MAX_SOUNDFILE_PARTS];
        fSR       = new int[MAX_SOUNDFILE_PARTS];
        fOffset   = new int[MAX_SOUNDFILE_PARTS];
        fIsDouble = is_double;
        fChannels = cur_chan;
        fParts    = total_parts;
        if (fIsDouble) {
            fBuffers = allocBufferReal<double>(cur_chan, length, max_chan);
        } else {
            fBuffers = allocBufferReal<float>(cur_chan, length, max_chan);
        }
    }
    
    template <typename REAL>
    void* allocBufferReal(int cur_chan, int length, int max_chan)
    {
        REAL** buffers = new REAL*[max_chan];
        for (int chan = 0; chan < cur_chan; chan++) {
            buffers[chan] = new REAL[length];
            memset(buffers[chan], 0, sizeof(REAL) * length);
        }
        return buffers;
    }
    
    void copyToOut(int size, int channels, int max_channels, int offset, void* buffer)
    {
        if (fIsDouble) {
            copyToOutReal<double>(size, channels, max_channels, offset, buffer);
       } else {
            copyToOutReal<float>(size, channels, max_channels, offset, buffer);
        }
    }
    
    void shareBuffers(int cur_chan, int max_chan)
    {
        // Share the same buffers for all other channels so that we have max_chan channels available
        if (fIsDouble) {
            for (int chan = cur_chan; chan < max_chan; chan++) {
                static_cast<double**>(fBuffers)[chan] = static_cast<double**>(fBuffers)[chan % cur_chan];
            }
        } else {
            for (int chan = cur_chan; chan < max_chan; chan++) {
                static_cast<float**>(fBuffers)[chan] = static_cast<float**>(fBuffers)[chan % cur_chan];
            }
        }
    }
    
    template <typename REAL>
    void copyToOutReal(int size, int channels, int max_channels, int offset, void* buffer)
    {
        for (int sample = 0; sample < size; sample++) {
            for (int chan = 0; chan < channels; chan++) {
                static_cast<REAL**>(fBuffers)[chan][offset + sample] = static_cast<REAL*>(buffer)[sample * max_channels + chan];
            }
        }
    }
    
    template <typename REAL>
    void getBuffersOffsetReal(void* buffers, int offset)
    {
        for (int chan = 0; chan < fChannels; chan++) {
            static_cast<REAL**>(buffers)[chan] = &(static_cast<REAL**>(fBuffers))[chan][offset];
        }
    }
    
    void emptyFile(int part, int& offset)
    {
        fLength[part] = BUFFER_SIZE;
        fSR[part] = SAMPLE_RATE;
        fOffset[part] = offset;
        // Update offset
        offset += fLength[part];
    }
 
    ~Soundfile()
    {
        // Free the real channels only
        if (fIsDouble) {
            for (int chan = 0; chan < fChannels; chan++) {
                delete[] static_cast<double**>(fBuffers)[chan];
            }
            delete[] static_cast<double**>(fBuffers);
        } else {
            for (int chan = 0; chan < fChannels; chan++) {
                delete[] static_cast<float**>(fBuffers)[chan];
            }
            delete[] static_cast<float**>(fBuffers);
        }
        delete[] fLength;
        delete[] fSR;
        delete[] fOffset;
    }

} POST_PACKED_STRUCTURE;

/*
 The generic soundfile reader.
 */

class SoundfileReader {
    
   protected:
    
    int fDriverSR;
   
    // Check if a soundfile exists and return its real path_name
    std::string checkFile(const std::vector<std::string>& sound_directories, const std::string& file_name)
    {
        if (checkFile(file_name)) {
            return file_name;
        } else {
            for (size_t i = 0; i < sound_directories.size(); i++) {
                std::string path_name = sound_directories[i] + "/" + file_name;
                if (checkFile(path_name)) { return path_name; }
            }
            return "";
        }
    }
    
    bool isResampling(int sample_rate) { return (fDriverSR > 0 && fDriverSR != sample_rate); }
 
    // To be implemented by subclasses

    /**
     * Check the availability of a sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     *
     * @return true if the sound resource is available, false otherwise.
     */
    virtual bool checkFile(const std::string& path_name) = 0;
    
    /**
     * Check the availability of a sound resource.
     *
     * @param buffer - the sound buffer
     * @param size - the sound buffer length
     *
     * @return true if the sound resource is available, false otherwise.
     */

    virtual bool checkFile(unsigned char* buffer, size_t size) { return true; }

    /**
     * Get the channels and length values of the given sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param channels - the channels value to be filled with the sound resource number of channels
     * @param length - the length value to be filled with the sound resource length in frames
     *
     */
    virtual void getParamsFile(const std::string& path_name, int& channels, int& length) = 0;
    
    /**
     * Get the channels and length values of the given sound resource.
     *
     * @param buffer - the sound buffer
     * @param size - the sound buffer length
     * @param channels - the channels value to be filled with the sound resource number of channels
     * @param length - the length value to be filled with the sound resource length in frames
     *
     */
    virtual void getParamsFile(unsigned char* buffer, size_t size, int& channels, int& length) {}

    /**
     * Read one sound resource and fill the 'soundfile' structure accordingly
     *
     * @param soundfile - the soundfile to be filled
     * @param path_name - the name of the file, or sound resource identified this way
     * @param part - the part number to be filled in the soundfile
     * @param offset - the offset value to be incremented with the actual sound resource length in frames
     * @param max_chan - the maximum number of mono channels to fill
     *
     */
    virtual void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan) = 0;
    
    /**
     * Read one sound resource and fill the 'soundfile' structure accordingly
     *
     * @param soundfile - the soundfile to be filled
     * @param buffer - the sound buffer
     * @param size - the sound buffer length
     * @param part - the part number to be filled in the soundfile
     * @param offset - the offset value to be incremented with the actual sound resource length in frames
     * @param max_chan - the maximum number of mono channels to fill
     *
     */
    virtual void readFile(Soundfile* soundfile, unsigned char* buffer, size_t size, int part, int& offset, int max_chan) {}

  public:
    
    SoundfileReader() {}
    virtual ~SoundfileReader() {}
    
    void setSampleRate(int sample_rate) { fDriverSR = sample_rate; }
   
    Soundfile* createSoundfile(const std::vector<std::string>& path_name_list, int max_chan, bool is_double)
    {
        try {
            int cur_chan = 1; // At least one channel
            int total_length = 0;
            
            // Compute total length and channels max of all files
            for (int i = 0; i < int(path_name_list.size()); i++) {
                int chan, length;
                if (path_name_list[i] == "__empty_sound__") {
                    length = BUFFER_SIZE;
                    chan = 1;
                } else {
                    getParamsFile(path_name_list[i], chan, length);
                }
                cur_chan = std::max<int>(cur_chan, chan);
                total_length += length;
            }
           
            // Complete with empty parts
            total_length += (MAX_SOUNDFILE_PARTS - path_name_list.size()) * BUFFER_SIZE;
            
            // Create the soundfile
            Soundfile* soundfile = new Soundfile(cur_chan, total_length, max_chan, path_name_list.size(), is_double);
            
            // Init offset
            int offset = 0;
            
            // Read all files
            for (int i = 0; i < int(path_name_list.size()); i++) {
                if (path_name_list[i] == "__empty_sound__") {
                    soundfile->emptyFile(i, offset);
                } else {
                    readFile(soundfile, path_name_list[i], i, offset, max_chan);
                }
            }
            
            // Complete with empty parts
            for (int i = int(path_name_list.size()); i < MAX_SOUNDFILE_PARTS; i++) {
                soundfile->emptyFile(i, offset);
            }
            
            // Share the same buffers for all other channels so that we have max_chan channels available
            soundfile->shareBuffers(cur_chan, max_chan);
            return soundfile;
            
        } catch (...) {
            return nullptr;
        }
    }

    // Check if all soundfiles exist and return their real path_name
    std::vector<std::string> checkFiles(const std::vector<std::string>& sound_directories,
                                        const std::vector<std::string>& file_name_list)
    {
        std::vector<std::string> path_name_list;
        for (size_t i = 0; i < file_name_list.size(); i++) {
            std::string path_name = checkFile(sound_directories, file_name_list[i]);
            // If 'path_name' is not found, it is replaced by an empty sound (= silence)
            path_name_list.push_back((path_name == "") ? "__empty_sound__" : path_name);
        }
        return path_name_list;
    }

};

#endif
/**************************  END  Soundfile.h **************************/

#if defined(JUCE_32BIT) || defined(JUCE_64BIT)
/************************** BEGIN JuceReader.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __JuceReader__
#define __JuceReader__

#include <assert.h>

#include "../JuceLibraryCode/JuceHeader.h"


struct JuceReader : public SoundfileReader {
    
    juce::AudioFormatManager fFormatManager;
    
    JuceReader() { fFormatManager.registerBasicFormats(); }
    virtual ~JuceReader()
    {}
    
    bool checkFile(const std::string& path_name) override
    {
        juce::File file(path_name);
        if (file.existsAsFile()) {
            return true;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name << "'" << std::endl;
            return false;
        }
    }
    
    void getParamsFile(const std::string& path_name, int& channels, int& length) override
    {
        std::unique_ptr<juce::AudioFormatReader> formatReader (fFormatManager.createReaderFor (juce::File (path_name)));
        channels = int(formatReader->numChannels);
        length = int(formatReader->lengthInSamples);
    }
    
    void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan) override
    {
        std::unique_ptr<juce::AudioFormatReader> formatReader (fFormatManager.createReaderFor (juce::File (path_name)));
        
        soundfile->fLength[part] = int(formatReader->lengthInSamples);
        soundfile->fSR[part] = int(formatReader->sampleRate);
        soundfile->fOffset[part] = offset;
        
        void* buffers;
        if (soundfile->fIsDouble) {
            buffers = alloca(soundfile->fChannels * sizeof(double*));
            soundfile->getBuffersOffsetReal<double>(buffers, offset);
        } else {
            buffers = alloca(soundfile->fChannels * sizeof(float*));
            soundfile->getBuffersOffsetReal<float>(buffers, offset);
        }
        
        if (formatReader->read(reinterpret_cast<int *const *>(buffers), int(formatReader->numChannels), 0, int(formatReader->lengthInSamples), false)) {
            
            // Possibly convert samples
            if (!formatReader->usesFloatingPointData) {
                for (int chan = 0; chan < int(formatReader->numChannels); ++chan) {
                    if (soundfile->fIsDouble) {
                        // TODO
                    } else {
                        float* buffer = &(static_cast<float**>(soundfile->fBuffers))[chan][soundfile->fOffset[part]];
                        juce::FloatVectorOperations::convertFixedToFloat(buffer, reinterpret_cast<const int*>(buffer),
                                                                         1.0f/0x7fffffff, int(formatReader->lengthInSamples));
                    }
                }
            }
            
        } else {
            std::cerr << "Error reading the file : " << path_name << std::endl;
        }
            
        // Update offset
        offset += soundfile->fLength[part];
    }
    
};

#endif
/**************************  END  JuceReader.h **************************/
static JuceReader gReader;
#elif defined(ESP32)
/************************** BEGIN Esp32Reader.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 *************************************************************************/

#ifndef FAUST_ESP32READER_H
#define FAUST_ESP32READER_H

#include <stdio.h>
#include "esp_err.h"
#include "esp_log.h"
#include "esp_spi_flash.h"
#include "esp_vfs_fat.h"
#include "driver/sdspi_host.h"
#include "sdmmc_cmd.h"

/************************** BEGIN WaveReader.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef __WaveReader__
#define __WaveReader__

#include <string.h>
#include <assert.h>
#include <stdio.h>


// WAVE file description
typedef struct {
    
    // The canonical WAVE format starts with the RIFF header
    
    /**
     Variable: chunk_id
     Contains the letters "RIFF" in ASCII form (0x52494646 big-endian form).
     **/
    int chunk_id;
    
    /**
     Variable: chunk_size
     36 + SubChunk2Size, or more precisely: 4 + (8 + SubChunk1Size) + (8 + SubChunk2Size)
     This is the size of the rest of the chunk following this number.
     This is the size of the entire file in bytes minus 8 bytes for the
     two fields not included in this count: ChunkID and ChunkSize.
     **/
    int chunk_size;
    
    /**
     Variable: format
     Contains the letters "WAVE" (0x57415645 big-endian form).
     **/
    int format;
    
    // The "WAVE" format consists of two subchunks: "fmt " and "data":
    // The "fmt " subchunk describes the sound data's format:
    
    /**
     Variable: subchunk_1_id
     Contains the letters "fmt " (0x666d7420 big-endian form).
     **/
    int subchunk_1_id;
    
    /**
     Variable: subchunk_1_size
     16 for PCM. This is the size of the rest of the Subchunk which follows this number.
     **/
    int subchunk_1_size;
    
    /**
     Variable: audio_format
     PCM = 1 (i.e. Linear quantization) Values other than 1 indicate some form of compression.
     **/
    short audio_format;
    
    /**
     Variable: num_channels
     Mono = 1, Stereo = 2, etc.
     **/
    short num_channels;
    
    /**
     Variable: sample_rate
     8000, 44100, etc.
     **/
    int sample_rate;
    
    /**
     Variable: byte_rate
     == SampleRate * NumChannels * BitsPerSample/8
     **/
    int byte_rate;
    
    /**
     Variable: block_align
     == NumChannels * BitsPerSample/8
     The number of bytes for one sample including all channels. I wonder what happens
     when this number isn't an integer?
     **/
    short block_align;
    
    /**
     Variable: bits_per_sample
     8 bits = 8, 16 bits = 16, etc.
     **/
    short bits_per_sample;
    
    /**
     Here should come some extra parameters which i will avoid.
     **/
    
    // The "data" subchunk contains the size of the data and the actual sound:
    
    /**
     Variable: subchunk_2_id
     Contains the letters "data" (0x64617461 big-endian form).
     **/
    int subchunk_2_id;
    
    /**
     Variable: subchunk_2_size
     == NumSamples * NumChannels * BitsPerSample/8
     This is the number of bytes in the data. You can also think of this as the size
     of the read of the subchunk following this number.
     **/
    int subchunk_2_size;
    
    /**
     Variable: data
     The actual sound data.
     **/
    char* data;
    
} wave_t;

// Base reader
struct Reader {
    
    wave_t* fWave;

    inline int is_big_endian()
    {
        int a = 1;
        return !((char*)&a)[0];
    }
    
    inline int convert_to_int(char* buffer, int len)
    {
        int a = 0;
        if (!is_big_endian()) {
            for(int i = 0; i < len; i++) {
                ((char*)&a)[i] = buffer[i];
            }
        } else {
            for(int i = 0; i < len; i++) {
                ((char*)&a)[3-i] = buffer[i];
            }
        }
        return a;
    }
    
    Reader()
    {
        fWave = (wave_t*)calloc(1, sizeof(wave_t));
    }

    virtual ~Reader()
    {
        free(fWave->data);
        free(fWave);
    }

    bool load_wave_header()
    {
        char buffer[4];
        
        read(buffer, 4);
        if (strncmp(buffer, "RIFF", 4) != 0) {
            fprintf(stderr, "This is not valid WAV file!\n");
            return false;
        }
        fWave->chunk_id = convert_to_int(buffer, 4);
        
        read(buffer, 4);
        fWave->chunk_size = convert_to_int(buffer, 4);
        
        read(buffer, 4);
        fWave->format = convert_to_int(buffer, 4);
        
        read(buffer, 4);
        fWave->subchunk_1_id = convert_to_int(buffer, 4);
        
        read(buffer, 4);
        fWave->subchunk_1_size = convert_to_int(buffer, 4);
        
        read(buffer, 2);
        fWave->audio_format = convert_to_int(buffer, 2);
        
        read(buffer, 2);
        fWave->num_channels = convert_to_int(buffer, 2);
        
        read(buffer, 4);
        fWave->sample_rate = convert_to_int(buffer, 4);
        
        read(buffer, 4);
        fWave->byte_rate = convert_to_int(buffer, 4);
        
        read(buffer, 2);
        fWave->block_align = convert_to_int(buffer, 2);
        
        read(buffer, 2);
        fWave->bits_per_sample = convert_to_int(buffer, 2);
        
        read(buffer, 4);
        if (strncmp(buffer, "data", 4) != 0) {
            read(buffer, 4);
            int _extra_size = convert_to_int(buffer, 4);
            char _extra_data[_extra_size];
            read(_extra_data, _extra_size);
            read(buffer, 4);
            fWave->subchunk_2_id = convert_to_int(buffer, 4);
        } else {
            fWave->subchunk_2_id = convert_to_int(buffer, 4);
        }
        
        read(buffer, 4);
        fWave->subchunk_2_size = convert_to_int(buffer, 4);
        return true;
    }
    
    void load_wave()
    {
        // Read sound data
        fWave->data = (char*)malloc(fWave->subchunk_2_size);
        read(fWave->data, fWave->subchunk_2_size);
    }

    virtual void read(char* buffer, unsigned int size) = 0;
   
};

struct FileReader : public Reader {
    
    FILE* fFile;
    
    FileReader(const std::string& file_path)
    {
        fFile = fopen(file_path.c_str(), "rb");
        if (!fFile) {
            fprintf(stderr, "FileReader : cannot open file!\n");
            throw -1;
        }
        if (!load_wave_header()) {
            fprintf(stderr, "FileReader : not a WAV file!\n");
            throw -1;
        }
    }
    
    virtual ~FileReader()
    {
        fclose(fFile);
    }
    
    void read(char* buffer, unsigned int size)
    {
        fread(buffer, 1, size, fFile);
    }
    
};

extern const uint8_t file_start[] asm("_binary_FILE_start");
extern const uint8_t file_end[]   asm("_binary_FILE_end");

struct MemoryReader : public Reader {
    
    int fPos;
    const uint8_t* fStart;
    const uint8_t* fEnd;
    
    MemoryReader(const uint8_t* start, const uint8_t* end):fPos(0)
    {
        fStart = start;
        fEnd = end;
        if (!load_wave_header()) {
            fprintf(stderr, "MemoryReader : not a WAV file!\n");
            throw -1;
        }
    }
    
    virtual ~MemoryReader()
    {}
    
    void read(char* buffer, unsigned int size)
    {
        memcpy(buffer, fStart + fPos, size);
        fPos += size;
    }
    
};

// Using a FileReader to implement SoundfileReader

struct WaveReader : public SoundfileReader {
    
    WaveReader() {}
    virtual ~WaveReader() {}
    
    bool checkFile(const std::string& path_name) override
    {
        try {
            FileReader reader(path_name);
            return true;
        } catch (...)  {
            return false;
        }
    }
    
    void getParamsFile(const std::string& path_name, int& channels, int& length) override
    {
        FileReader reader(path_name);
        channels = reader.fWave->num_channels;
        length = (reader.fWave->subchunk_2_size * 8) / (reader.fWave->num_channels * reader.fWave->bits_per_sample);
    }
    
    void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan) override
    {
        FileReader reader(path_name);
        reader.load_wave();
        
        soundfile->fLength[part] = (reader.fWave->subchunk_2_size * 8) / (reader.fWave->num_channels * reader.fWave->bits_per_sample);
        soundfile->fSR[part] = reader.fWave->sample_rate;
        soundfile->fOffset[part] = offset;
        
        // Audio frames have to be written for each chan
        if (reader.fWave->bits_per_sample == 16) {
            float factor = 1.f/32767.f;
            for (int sample = 0; sample < soundfile->fLength[part]; sample++) {
                short* frame = (short*)&reader.fWave->data[reader.fWave->block_align * sample];
                for (int chan = 0; chan < reader.fWave->num_channels; chan++) {
                    soundfile->fBuffers[chan][offset + sample] = frame[chan] * factor;
                }
            }
        } else if (reader.fWave->bits_per_sample == 32) {
            fprintf(stderr, "readFile : not implemented\n");
        }
        
        // Update offset
        offset += soundfile->fLength[part];
    }
};

#endif
/**************************  END  WaveReader.h **************************/

#define TAG "Esp32Reader"

#define SD_PIN_NUM_MISO GPIO_NUM_2
#define SD_PIN_NUM_MOSI GPIO_NUM_15
#define SD_PIN_NUM_CLK  GPIO_NUM_14
#define SD_PIN_NUM_CS   GPIO_NUM_13

struct Esp32Reader : public WaveReader {
    
    void sdcard_init()
    {
        ESP_LOGI(TAG, "Initializing SD card");
        ESP_LOGI(TAG, "Using SPI peripheral");
        
        sdmmc_host_t host = SDSPI_HOST_DEFAULT();
        sdspi_slot_config_t slot_config = SDSPI_SLOT_CONFIG_DEFAULT();
        slot_config.gpio_miso = SD_PIN_NUM_MISO;
        slot_config.gpio_mosi = SD_PIN_NUM_MOSI;
        slot_config.gpio_sck  = SD_PIN_NUM_CLK;
        slot_config.gpio_cs   = SD_PIN_NUM_CS;
        // This initializes the slot without card detect (CD) and write protect (WP) signals.
        // Modify slot_config.gpio_cd and slot_config.gpio_wp if your board has these signals.
        
        // Options for mounting the filesystem.
        // If format_if_mount_failed is set to true, SD card will be partitioned and
        // formatted in case when mounting fails.
        esp_vfs_fat_sdmmc_mount_config_t mount_config = {
            .format_if_mount_failed = false,
            .max_files = 5,
            .allocation_unit_size = 16 * 1024
        };
        
        // Use settings defined above to initialize SD card and mount FAT filesystem.
        // Note: esp_vfs_fat_sdmmc_mount is an all-in-one convenience function.
        // Please check its source code and implement error recovery when developing
        // production applications.
        sdmmc_card_t* card;
        esp_err_t ret = esp_vfs_fat_sdmmc_mount("/sdcard", &host, &slot_config, &mount_config, &card);
        
        if (ret != ESP_OK) {
            if (ret == ESP_FAIL) {
                ESP_LOGE(TAG, "Failed to mount filesystem. "
                         "If you want the card to be formatted, set format_if_mount_failed = true.");
            } else {
                ESP_LOGE(TAG, "Failed to initialize the card (%s). "
                         "Make sure SD card lines have pull-up resistors in place.", esp_err_to_name(ret));
            }
            return;
        }
        
        // Card has been initialized, print its properties
        sdmmc_card_print_info(stdout, card);
        ESP_LOGI(TAG, "SD card initialized");
    }
    
    Esp32Reader()
    {
        sdcard_init();
    }
   
    // Access methods inherited from WaveReader
};

#endif // FAUST_ESP32READER_H
/**************************  END  Esp32Reader.h **************************/
static Esp32Reader gReader;
#elif defined(DAISY)
static WaveReader gReader;
#elif defined(MEMORY_READER)
/************************** BEGIN MemoryReader.h ************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __MemoryReader__
#define __MemoryReader__


/*
 A 'MemoryReader' object can be used to prepare a set of sound resources in memory, to be used by SoundUI::addSoundfile.
 
 A Soundfile* object will have to be filled with a list of sound resources: the fLength, fOffset, fSampleRate and fBuffers fields 
 have to be completed with the appropriate values, and will be accessed in the DSP object while running.
 *
 */

// To adapt for a real case use

#define SOUND_CHAN      2
#define SOUND_LENGTH    4096
#define SOUND_SR        44100

struct MemoryReader : public SoundfileReader {
    
    MemoryReader()
    {}
    virtual ~MemoryReader()
    {}
    
    /**
     * Check the availability of a sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     *
     * @return true if the sound resource is available, false otherwise.
     */
    virtual bool checkFile(const std::string& path_name) override { return true; }
    
    /**
     * Get the channels and length values of the given sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param channels - the channels value to be filled with the sound resource number of channels
     * @param length - the length value to be filled with the sound resource length in frames
     *
     */
    virtual void getParamsFile(const std::string& path_name, int& channels, int& length) override
    {
        channels = SOUND_CHAN;
        length = SOUND_LENGTH;
    }
    
    /**
     * Read one sound resource and fill the 'soundfile' structure accordingly
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param part - the part number to be filled in the soundfile
     * @param offset - the offset value to be incremented with the actual sound resource length in frames
     * @param max_chan - the maximum number of mono channels to fill
     *
     */
    virtual void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan) override
    {
        soundfile->fLength[part] = SOUND_LENGTH;
        soundfile->fSR[part] = SOUND_SR;
        soundfile->fOffset[part] = offset;
        
        // Audio frames have to be written for each chan
        if (soundfile->fIsDouble) {
            for (int sample = 0; sample < SOUND_LENGTH; sample++) {
                for (int chan = 0; chan < SOUND_CHAN; chan++) {
                    static_cast<double**>(soundfile->fBuffers)[chan][offset + sample] = 0.f;
                }
            }
        } else {
            for (int sample = 0; sample < SOUND_LENGTH; sample++) {
                for (int chan = 0; chan < SOUND_CHAN; chan++) {
                    static_cast<float**>(soundfile->fBuffers)[chan][offset + sample] = 0.f;
                }
            }
        }
        
        // Update offset
        offset += SOUND_LENGTH;
    }
    
};

#endif
/**************************  END  MemoryReader.h **************************/
static MemoryReader gReader;
#else
/************************** BEGIN LibsndfileReader.h *********************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __LibsndfileReader__
#define __LibsndfileReader__

#ifdef SAMPLERATE
#include <samplerate.h>
#endif
#include <sndfile.h>
#include <string.h>
#include <assert.h>
#include <iostream>


struct VFLibsndfile {
    
    #define SIGNED_SIZEOF(x) ((int)sizeof(x))
    
    unsigned char* fBuffer;
    size_t fLength;
    size_t fOffset;
    SF_VIRTUAL_IO fVIO;
    
    VFLibsndfile(unsigned char* buffer, size_t length):fBuffer(buffer), fLength(length), fOffset(0)
    {
        fVIO.get_filelen = vfget_filelen;
        fVIO.seek = vfseek;
        fVIO.read = vfread;
        fVIO.write = vfwrite;
        fVIO.tell = vftell;
    }
    
    static sf_count_t vfget_filelen(void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        return vf->fLength;
    }
  
    static sf_count_t vfseek(sf_count_t offset, int whence, void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        switch (whence) {
            case SEEK_SET:
                vf->fOffset = offset;
                break;
                
            case SEEK_CUR:
                vf->fOffset = vf->fOffset + offset;
                break;
                
            case SEEK_END:
                vf->fOffset = vf->fLength + offset;
                break;
                
            default:
                break;
        };
        
        return vf->fOffset;
    }
    
    static sf_count_t vfread(void* ptr, sf_count_t count, void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        
        /*
         **	This will break badly for files over 2Gig in length, but
         **	is sufficient for testing.
         */
        if (vf->fOffset + count > vf->fLength) {
            count = vf->fLength - vf->fOffset;
        }
        
        memcpy(ptr, vf->fBuffer + vf->fOffset, count);
        vf->fOffset += count;
        
        return count;
    }
    
    static sf_count_t vfwrite(const void* ptr, sf_count_t count, void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        
        /*
         **	This will break badly for files over 2Gig in length, but
         **	is sufficient for testing.
         */
        if (vf->fOffset >= SIGNED_SIZEOF(vf->fBuffer)) {
            return 0;
        }
        
        if (vf->fOffset + count > SIGNED_SIZEOF(vf->fBuffer)) {
            count = sizeof (vf->fBuffer) - vf->fOffset;
        }
        
        memcpy(vf->fBuffer + vf->fOffset, ptr, (size_t)count);
        vf->fOffset += count;
        
        if (vf->fOffset > vf->fLength) {
            vf->fLength = vf->fOffset;
        }
        
        return count;
    }
    
    static sf_count_t vftell(void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        return vf->fOffset;
    }
 
};

struct LibsndfileReader : public SoundfileReader {
	
    LibsndfileReader() {}
	
    typedef sf_count_t (* sample_read)(SNDFILE* sndfile, void* buffer, sf_count_t frames);
	
    // Check file
    bool checkFile(const std::string& path_name) override
    {
        SF_INFO snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        return checkFileAux(snd_file, path_name);
    }
    
    bool checkFile(unsigned char* buffer, size_t length) override
    {
        SF_INFO snd_info;
        snd_info.format = 0;
        VFLibsndfile vio(buffer, length);
        SNDFILE* snd_file = sf_open_virtual(&vio.fVIO, SFM_READ, &snd_info, &vio);
        return checkFileAux(snd_file, "virtual file");
    }
    
    bool checkFileAux(SNDFILE* snd_file, const std::string& path_name)
    {
        if (snd_file) {
            sf_close(snd_file);
            return true;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name << "' (" << sf_strerror(NULL) << ")" << std::endl;
            return false;
        }
    }

    // Open the file and returns its length and channels
    void getParamsFile(const std::string& path_name, int& channels, int& length) override
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        getParamsFileAux(snd_file, snd_info, channels, length);
    }
    
    void getParamsFile(unsigned char* buffer, size_t size, int& channels, int& length) override
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        VFLibsndfile vio(buffer, size);
        SNDFILE* snd_file = sf_open_virtual(&vio.fVIO, SFM_READ, &snd_info, &vio);
        getParamsFileAux(snd_file, snd_info, channels, length);
    }
    
    void getParamsFileAux(SNDFILE* snd_file, const SF_INFO& snd_info, int& channels, int& length)
    {
        assert(snd_file);
        channels = int(snd_info.channels);
    #ifdef SAMPLERATE
        length = (isResampling(snd_info.samplerate)) ? ((double(snd_info.frames) * double(fDriverSR) / double(snd_info.samplerate)) + BUFFER_SIZE) : int(snd_info.frames);
    #else
        length = int(snd_info.frames);
    #endif
        sf_close(snd_file);
    }
    
    // Read the file
    void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan) override
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        readFileAux(soundfile, snd_file, snd_info, part, offset, max_chan);
    }
    
    void readFile(Soundfile* soundfile, unsigned char* buffer, size_t length, int part, int& offset, int max_chan) override
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        VFLibsndfile vio(buffer, length);
        SNDFILE* snd_file = sf_open_virtual(&vio.fVIO, SFM_READ, &snd_info, &vio);
        readFileAux(soundfile, snd_file, snd_info, part, offset, max_chan);
    }
	
    // Will be called to fill all parts from 0 to MAX_SOUNDFILE_PARTS-1
    void readFileAux(Soundfile* soundfile, SNDFILE* snd_file, const SF_INFO& snd_info, int part, int& offset, int max_chan)
    {
        assert(snd_file);
        int channels = std::min<int>(max_chan, snd_info.channels);
    #ifdef SAMPLERATE
        if (isResampling(snd_info.samplerate)) {
            soundfile->fLength[part] = int(double(snd_info.frames) * double(fDriverSR) / double(snd_info.samplerate));
            soundfile->fSR[part] = fDriverSR;
        } else {
            soundfile->fLength[part] = int(snd_info.frames);
            soundfile->fSR[part] = snd_info.samplerate;
        }
    #else
        soundfile->fLength[part] = int(snd_info.frames);
        soundfile->fSR[part] = snd_info.samplerate;
    #endif
        soundfile->fOffset[part] = offset;
		
        // Read and fill snd_info.channels number of channels
        sf_count_t nbf;
        
        sample_read reader;
        void* buffer_in = nullptr;
        if (soundfile->fIsDouble) {
            buffer_in = static_cast<double*>(alloca(BUFFER_SIZE * sizeof(double) * snd_info.channels));
            reader = reinterpret_cast<sample_read>(sf_readf_double);
        } else {
            buffer_in = static_cast<float*>(alloca(BUFFER_SIZE * sizeof(float) * snd_info.channels));
            reader = reinterpret_cast<sample_read>(sf_readf_float);
        }
        
    #ifdef SAMPLERATE
        // Resampling
        SRC_STATE* resampler = nullptr;
        float* src_buffer_out = nullptr;
        float* src_buffer_in = nullptr;
        void* buffer_out = nullptr;
        if  (isResampling(snd_info.samplerate)) {
            int error;
            resampler = src_new(SRC_SINC_FASTEST, channels, &error);
            if (error != 0) {
                std::cerr << "ERROR : src_new " << src_strerror(error) << std::endl;
                throw -1;
            }
            if (soundfile->fIsDouble) {
                // Additional buffers for SRC resampling
                src_buffer_in = static_cast<float*>(alloca(BUFFER_SIZE * sizeof(float) * snd_info.channels));
                src_buffer_out = static_cast<float*>(alloca(BUFFER_SIZE * sizeof(float) * snd_info.channels));
                buffer_out = static_cast<double*>(alloca(BUFFER_SIZE * sizeof(double) * snd_info.channels));
            } else {
                buffer_out = static_cast<float*>(alloca(BUFFER_SIZE * sizeof(float) * snd_info.channels));
            }
        }
    #endif
        
        do {
            nbf = reader(snd_file, buffer_in, BUFFER_SIZE);
        #ifdef SAMPLERATE
            // Resampling
            if  (isResampling(snd_info.samplerate)) {
                int in_offset = 0;
                SRC_DATA src_data;
                src_data.src_ratio = double(fDriverSR)/double(snd_info.samplerate);
                if (soundfile->fIsDouble) {
                    for (int frame = 0; frame < (BUFFER_SIZE * snd_info.channels); frame++) {
                        src_buffer_in[frame] = float(static_cast<float*>(buffer_in)[frame]);
                    }
                }
                do {
                    if (soundfile->fIsDouble) {
                        src_data.data_in = src_buffer_in;
                        src_data.data_out = src_buffer_out;
                    } else {
                        src_data.data_in = static_cast<const float*>(buffer_in);
                        src_data.data_out = static_cast<float*>(buffer_out);
                    }
                    src_data.input_frames = nbf - in_offset;
                    src_data.output_frames = BUFFER_SIZE;
                    src_data.end_of_input = (nbf < BUFFER_SIZE);
                    int res = src_process(resampler, &src_data);
                    if (res != 0) {
                        std::cerr << "ERROR : src_process " << src_strerror(res) << std::endl;
                        throw -1;
                    }
                    if (soundfile->fIsDouble) {
                        for (int frame = 0; frame < (BUFFER_SIZE * snd_info.channels); frame++) {
                            static_cast<double*>(buffer_out)[frame] = double(src_buffer_out[frame]);
                        }
                    }
                    soundfile->copyToOut(src_data.output_frames_gen, channels, snd_info.channels, offset, buffer_out);
                    in_offset += src_data.input_frames_used;
                    // Update offset
                    offset += src_data.output_frames_gen;
                } while (in_offset < nbf);
            } else {
                soundfile->copyToOut(nbf, channels, snd_info.channels, offset, buffer_in);
                // Update offset
                offset += nbf;
            }
        #else
            soundfile->copyToOut(nbf, channels, snd_info.channels, offset, buffer_in);
            // Update offset
            offset += nbf;
        #endif
        } while (nbf == BUFFER_SIZE);
		
        sf_close(snd_file);
    #ifdef SAMPLERATE
        if (resampler) src_delete(resampler);
    #endif
    }

};

#endif
/**************************  END  LibsndfileReader.h **************************/
static LibsndfileReader gReader;
#endif

// To be used by DSP code if no SoundUI is used
static std::vector<std::string> path_name_list;
static Soundfile* defaultsound = nullptr;

class SoundUI : public SoundUIInterface
{
		
    protected:
    
        // The soundfile directories
        std::vector<std::string> fSoundfileDir;
        // Map to share loaded soundfiles
        std::map<std::string, std::shared_ptr<Soundfile>> fSoundfileMap;
        // The soundfile reader
        std::shared_ptr<SoundfileReader> fSoundReader;
        bool fIsDouble;

     public:
    
        /**
         * Create a soundfile loader which will typically use a concrete SoundfileReader like LibsndfileReader or JuceReader to load soundfiles.
         *
         * @param sound_directory - the base directory to look for files, which paths will be relative to this one
         * @param sample_rate - the audio driver SR which may be different from the file SR, to possibly resample files
         * @param reader - an alternative soundfile reader
         * @param is_double - whether Faust code has been compiled in -double mode and soundfile buffers have to be in double
         *
         * @return the soundfile loader.
         */
        SoundUI(const std::string& sound_directory = "", int sample_rate = -1, SoundfileReader* reader = nullptr, bool is_double = false)
        {
            fSoundfileDir.push_back(sound_directory);
            fSoundReader = (reader)
                ? std::shared_ptr<SoundfileReader>(reader)
                // the static gReader should not be deleted, so use an empty destructor
                : std::shared_ptr<SoundfileReader>(std::shared_ptr<SoundfileReader>{}, &gReader);
            fSoundReader->setSampleRate(sample_rate);
            fIsDouble = is_double;
            if (!defaultsound) defaultsound = gReader.createSoundfile(path_name_list, MAX_CHAN, is_double);
        }
    
        /**
         * Create a soundfile loader which will typically use a concrete SoundfileReader like LibsndfileReader or JuceReader to load soundfiles.
         *
         * @param sound_directories - a vector of base directories to look for files, which paths will be relative to these ones
         * @param sample_rate - the audio driver SR which may be different from the file SR, to possibly resample files
         * @param reader - an alternative soundfile reader
         * @param is_double - whether Faust code has been compiled in -double mode and soundfile buffers have to be in double
         *
         * @return the soundfile loader.
         */
        SoundUI(const std::vector<std::string>& sound_directories, int sample_rate = -1, SoundfileReader* reader = nullptr, bool is_double = false)
        :fSoundfileDir(sound_directories)
        {
            fSoundReader = (reader)
                ? std::shared_ptr<SoundfileReader>(reader)
                // the static gReader should not be deleted, so use an empty destructor
                : std::shared_ptr<SoundfileReader>(std::shared_ptr<SoundfileReader>{}, &gReader);
            fSoundReader->setSampleRate(sample_rate);
            fIsDouble = is_double;
            if (!defaultsound) defaultsound = gReader.createSoundfile(path_name_list, MAX_CHAN, is_double);
        }
    
        virtual ~SoundUI()
        {}

        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* url, Soundfile** sf_zone)
        {
            const char* saved_url = url; // 'url' is consumed by parseMenuList2
            std::vector<std::string> file_name_list;
            
            bool menu = parseMenuList2(url, file_name_list, true);
            // If not a list, we have as single file
            if (!menu) { file_name_list.push_back(saved_url); }
            
            // Parse the possible list
            std::string saved_url_real = std::string(saved_url) + "_" + std::to_string(fIsDouble); // fIsDouble is used in the key
            if (fSoundfileMap.find(saved_url_real) == fSoundfileMap.end()) {
                // Check all files and get their complete path
                std::vector<std::string> path_name_list = fSoundReader->checkFiles(fSoundfileDir, file_name_list);
                // Read them and create the Soundfile
                Soundfile* sound_file = fSoundReader->createSoundfile(path_name_list, MAX_CHAN, fIsDouble);
                if (sound_file) {
                    fSoundfileMap[saved_url_real] = std::shared_ptr<Soundfile>(sound_file);
                } else {
                    // If failure, use 'defaultsound'
                    std::cerr << "addSoundfile : soundfile for " << saved_url << " cannot be created !" << std::endl;
                    *sf_zone = defaultsound;
                    return;
                }
            }
            
            // Get the soundfile pointer
            *sf_zone = fSoundfileMap[saved_url_real].get();
        }
    
        /**
         * An OS dependant function to get the path of the running executable or plugin.
         * This will typically be used when creating a SoundUI soundfile loader, like new SoundUI(SoundUI::getBinaryPath());
         *
         * @return the running executable or plugin path.
         */
        static std::string getBinaryPath()
        {
            std::string bundle_path_str;
        #if defined(__APPLE__) && !defined(__VCVRACK__) && !defined(JUCE_32BIT) && !defined(JUCE_64BIT)
            CFURLRef bundle_ref = CFBundleCopyBundleURL(CFBundleGetMainBundle());
            if (!bundle_ref) { std::cerr << "getBinaryPath CFBundleCopyBundleURL error\n"; return ""; }
      
            UInt8 bundle_path[1024];
            if (CFURLGetFileSystemRepresentation(bundle_ref, true, bundle_path, 1024)) {
                bundle_path_str = std::string((char*)bundle_path);
            } else {
                std::cerr << "getBinaryPath CFURLGetFileSystemRepresentation error\n";
            }
        #endif
        #ifdef ANDROID_DRIVER
            bundle_path_str = "/data/data/__CURRENT_ANDROID_PACKAGE__/files";
        #endif
            return bundle_path_str;
        }
    
        /**
         * An OS dependant function to get the path of the running executable or plugin.
         * This will typically be used when creating a SoundUI soundfile loader, like new SoundUI(SoundUI::getBinaryPathFrom());
         *
         * @param path - entry point to start getting the path of the running executable or plugin.
         *
         * @return the running executable or plugin path.
         */
        static std::string getBinaryPathFrom(const std::string& path)
        {
            std::string bundle_path_str;
        #if defined(__APPLE__) && !defined(__VCVRACK__) && !defined(JUCE_32BIT) && !defined(JUCE_64BIT)
            CFBundleRef bundle = CFBundleGetBundleWithIdentifier(CFStringCreateWithCString(kCFAllocatorDefault, path.c_str(), CFStringGetSystemEncoding()));
            if (!bundle) { std::cerr << "getBinaryPathFrom CFBundleGetBundleWithIdentifier error '" << path << "'" << std::endl; return ""; }
         
            CFURLRef bundle_ref = CFBundleCopyBundleURL(bundle);
            if (!bundle_ref) { std::cerr << "getBinaryPathFrom CFBundleCopyBundleURL error\n"; return ""; }
            
            UInt8 bundle_path[1024];
            if (CFURLGetFileSystemRepresentation(bundle_ref, true, bundle_path, 1024)) {
                bundle_path_str = std::string((char*)bundle_path);
            } else {
                std::cerr << "getBinaryPathFrom CFURLGetFileSystemRepresentation error\n";
            }
        #endif
        #ifdef ANDROID_DRIVER
            bundle_path_str = "/data/data/__CURRENT_ANDROID_PACKAGE__/files";
        #endif
            return bundle_path_str;
        }
};

#endif
/**************************  END  SoundUI.h **************************/
#endif

#if defined(OSCCTRL)
/************************** BEGIN JuceOSCUI.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __juce_osc__
#define __juce_osc__
 
#include "../JuceLibraryCode/JuceHeader.h"

/************************** BEGIN APIUI.h *****************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
************************************************************************/

#ifndef API_UI_H
#define API_UI_H

#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>


typedef unsigned int uint;

class APIUI : public PathBuilder, public Meta, public UI
{
    public:
        enum ItemType { kButton = 0, kCheckButton, kVSlider, kHSlider, kNumEntry, kHBargraph, kVBargraph };
        enum Type { kAcc = 0, kGyr = 1, kNoType };

    protected:

        enum Mapping { kLin = 0, kLog = 1, kExp = 2 };

        struct Item {
            std::string fLabel;
            std::string fShortname;
            std::string fPath;
            ValueConverter* fConversion;
            FAUSTFLOAT* fZone;
            FAUSTFLOAT fInit;
            FAUSTFLOAT fMin;
            FAUSTFLOAT fMax;
            FAUSTFLOAT fStep;
            ItemType fItemType;
            
            Item(const std::string& label,
                 const std::string& short_name,
                 const std::string& path,
                 ValueConverter* conversion,
                 FAUSTFLOAT* zone,
                 FAUSTFLOAT init,
                 FAUSTFLOAT min,
                 FAUSTFLOAT max,
                 FAUSTFLOAT step,
                 ItemType item_type)
            :fLabel(label), fShortname(short_name), fPath(path), fConversion(conversion),
            fZone(zone), fInit(init), fMin(min), fMax(max), fStep(step), fItemType(item_type)
            {}
        };
        std::vector<Item> fItems;

        std::vector<std::map<std::string, std::string> > fMetaData;
        std::vector<ZoneControl*> fAcc[3];
        std::vector<ZoneControl*> fGyr[3];

        // Screen color control
        // "...[screencolor:red]..." etc.
        bool fHasScreenControl;      // true if control screen color metadata
        ZoneReader* fRedReader;
        ZoneReader* fGreenReader;
        ZoneReader* fBlueReader;

        // Current values controlled by metadata
        std::string fCurrentUnit;
        int fCurrentScale;
        std::string fCurrentAcc;
        std::string fCurrentGyr;
        std::string fCurrentColor;
        std::string fCurrentTooltip;
        std::map<std::string, std::string> fCurrentMetadata;

        // Add a generic parameter
        virtual void addParameter(const char* label,
                                  FAUSTFLOAT* zone,
                                  FAUSTFLOAT init,
                                  FAUSTFLOAT min,
                                  FAUSTFLOAT max,
                                  FAUSTFLOAT step,
                                  ItemType type)
        {
            std::string path = buildPath(label);
            fFullPaths.push_back(path);

            // handle scale metadata
            ValueConverter* converter = nullptr;
            switch (fCurrentScale) {
                case kLin:
                    converter = new LinearValueConverter(0, 1, min, max);
                    break;
                case kLog:
                    converter = new LogValueConverter(0, 1, min, max);
                    break;
                case kExp:
                    converter = new ExpValueConverter(0, 1, min, max);
                    break;
            }
            fCurrentScale = kLin;

            fItems.push_back(Item(label, "", path, converter, zone, init, min, max, step, type));
       
            if (fCurrentAcc.size() > 0 && fCurrentGyr.size() > 0) {
                fprintf(stderr, "warning : 'acc' and 'gyr' metadata used for the same %s parameter !!\n", label);
            }

            // handle acc metadata "...[acc : <axe> <curve> <amin> <amid> <amax>]..."
            if (fCurrentAcc.size() > 0) {
                std::istringstream iss(fCurrentAcc);
                int axe, curve;
                double amin, amid, amax;
                iss >> axe >> curve >> amin >> amid >> amax;

                if ((0 <= axe) && (axe < 3) &&
                    (0 <= curve) && (curve < 4) &&
                    (amin < amax) && (amin <= amid) && (amid <= amax))
                {
                    fAcc[axe].push_back(new CurveZoneControl(zone, curve, amin, amid, amax, min, init, max));
                } else {
                    fprintf(stderr, "incorrect acc metadata : %s \n", fCurrentAcc.c_str());
                }
                fCurrentAcc = "";
            }

            // handle gyr metadata "...[gyr : <axe> <curve> <amin> <amid> <amax>]..."
            if (fCurrentGyr.size() > 0) {
                std::istringstream iss(fCurrentGyr);
                int axe, curve;
                double amin, amid, amax;
                iss >> axe >> curve >> amin >> amid >> amax;

                if ((0 <= axe) && (axe < 3) &&
                    (0 <= curve) && (curve < 4) &&
                    (amin < amax) && (amin <= amid) && (amid <= amax))
                {
                    fGyr[axe].push_back(new CurveZoneControl(zone, curve, amin, amid, amax, min, init, max));
                } else {
                    fprintf(stderr, "incorrect gyr metadata : %s \n", fCurrentGyr.c_str());
                }
                fCurrentGyr = "";
            }

            // handle screencolor metadata "...[screencolor:red|green|blue|white]..."
            if (fCurrentColor.size() > 0) {
                if ((fCurrentColor == "red") && (fRedReader == nullptr)) {
                    fRedReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else if ((fCurrentColor == "green") && (fGreenReader == nullptr)) {
                    fGreenReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else if ((fCurrentColor == "blue") && (fBlueReader == nullptr)) {
                    fBlueReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else if ((fCurrentColor == "white") && (fRedReader == nullptr) && (fGreenReader == nullptr) && (fBlueReader == nullptr)) {
                    fRedReader = new ZoneReader(zone, min, max);
                    fGreenReader = new ZoneReader(zone, min, max);
                    fBlueReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else {
                    fprintf(stderr, "incorrect screencolor metadata : %s \n", fCurrentColor.c_str());
                }
            }
            fCurrentColor = "";

            fMetaData.push_back(fCurrentMetadata);
            fCurrentMetadata.clear();
        }

        int getZoneIndex(std::vector<ZoneControl*>* table, int p, int val)
        {
            FAUSTFLOAT* zone = fItems[uint(p)].fZone;
            for (size_t i = 0; i < table[val].size(); i++) {
                if (zone == table[val][i]->getZone()) return int(i);
            }
            return -1;
        }

        void setConverter(std::vector<ZoneControl*>* table, int p, int val, int curve, double amin, double amid, double amax)
        {
            int id1 = getZoneIndex(table, p, 0);
            int id2 = getZoneIndex(table, p, 1);
            int id3 = getZoneIndex(table, p, 2);

            // Deactivates everywhere..
            if (id1 != -1) table[0][uint(id1)]->setActive(false);
            if (id2 != -1) table[1][uint(id2)]->setActive(false);
            if (id3 != -1) table[2][uint(id3)]->setActive(false);

            if (val == -1) { // Means: no more mapping...
                // So stay all deactivated...
            } else {
                int id4 = getZoneIndex(table, p, val);
                if (id4 != -1) {
                    // Reactivate the one we edit...
                  table[val][uint(id4)]->setMappingValues(curve, amin, amid, amax, fItems[uint(p)].fMin, fItems[uint(p)].fInit, fItems[uint(p)].fMax);
                  table[val][uint(id4)]->setActive(true);
                } else {
                    // Allocate a new CurveZoneControl which is 'active' by default
                    FAUSTFLOAT* zone = fItems[uint(p)].fZone;
                    table[val].push_back(new CurveZoneControl(zone, curve, amin, amid, amax, fItems[uint(p)].fMin, fItems[uint(p)].fInit, fItems[uint(p)].fMax));
                }
            }
        }

        void getConverter(std::vector<ZoneControl*>* table, int p, int& val, int& curve, double& amin, double& amid, double& amax)
        {
            int id1 = getZoneIndex(table, p, 0);
            int id2 = getZoneIndex(table, p, 1);
            int id3 = getZoneIndex(table, p, 2);

            if (id1 != -1) {
                val = 0;
                curve = table[val][uint(id1)]->getCurve();
                table[val][uint(id1)]->getMappingValues(amin, amid, amax);
            } else if (id2 != -1) {
                val = 1;
                curve = table[val][uint(id2)]->getCurve();
                table[val][uint(id2)]->getMappingValues(amin, amid, amax);
            } else if (id3 != -1) {
                val = 2;
                curve = table[val][uint(id3)]->getCurve();
                table[val][uint(id3)]->getMappingValues(amin, amid, amax);
            } else {
                val = -1; // No mapping
                curve = 0;
                amin = -100.;
                amid = 0.;
                amax = 100.;
            }
        }

    public:

        APIUI() : fHasScreenControl(false), fRedReader(nullptr), fGreenReader(nullptr), fBlueReader(nullptr), fCurrentScale(kLin)
        {}

        virtual ~APIUI()
        {
            for (const auto& it : fItems) delete it.fConversion;
            for (int i = 0; i < 3; i++) {
                for (const auto& it : fAcc[i]) delete it;
                for (const auto& it : fGyr[i]) delete it;
            }
            delete fRedReader;
            delete fGreenReader;
            delete fBlueReader;
        }

        // -- widget's layouts

        virtual void openTabBox(const char* label) { pushLabel(label); }
        virtual void openHorizontalBox(const char* label) { pushLabel(label); }
        virtual void openVerticalBox(const char* label) { pushLabel(label); }
        virtual void closeBox()
        {
            if (popLabel()) {
                // Shortnames can be computed when all fullnames are known
                computeShortNames();
                // Fill 'shortname' field for each item
                for (const auto& it : fFull2Short) {
                    int index = getParamIndex(it.first.c_str());
                    fItems[index].fShortname = it.second;
                }
            }
        }

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addParameter(label, zone, 0, 0, 1, 1, kButton);
        }

        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addParameter(label, zone, 0, 0, 1, 1, kCheckButton);
        }

        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addParameter(label, zone, init, min, max, step, kVSlider);
        }

        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addParameter(label, zone, init, min, max, step, kHSlider);
        }

        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addParameter(label, zone, init, min, max, step, kNumEntry);
        }

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addParameter(label, zone, min, min, max, (max-min)/1000.0f, kHBargraph);
        }

        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addParameter(label, zone, min, min, max, (max-min)/1000.0f, kVBargraph);
        }

        // -- soundfiles

        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            // Keep metadata
            fCurrentMetadata[key] = val;

            if (strcmp(key, "scale") == 0) {
                if (strcmp(val, "log") == 0) {
                    fCurrentScale = kLog;
                } else if (strcmp(val, "exp") == 0) {
                    fCurrentScale = kExp;
                } else {
                    fCurrentScale = kLin;
                }
            } else if (strcmp(key, "unit") == 0) {
                fCurrentUnit = val;
            } else if (strcmp(key, "acc") == 0) {
                fCurrentAcc = val;
            } else if (strcmp(key, "gyr") == 0) {
                fCurrentGyr = val;
            } else if (strcmp(key, "screencolor") == 0) {
                fCurrentColor = val; // val = "red", "green", "blue" or "white"
            } else if (strcmp(key, "tooltip") == 0) {
                fCurrentTooltip = val;
            }
        }

        virtual void declare(const char* key, const char* val)
        {}

        //-------------------------------------------------------------------------------
        // Simple API part
        //-------------------------------------------------------------------------------
    
        /**
         * Return the number of parameters in the UI.
         *
         * @return the number of parameters
         */
        int getParamsCount() { return int(fItems.size()); }

        /**
         * Return the param index.
         *
         * @param str - the UI parameter label/shortname/path
         *
         * @return the param index
         */
        int getParamIndex(const char* str)
        {
            std::string path = std::string(str);
            auto it = find_if(fItems.begin(), fItems.end(),
                              [=](const Item& it) { return (it.fLabel == path) || (it.fShortname == path) || (it.fPath == path); });
            return (it != fItems.end()) ? int(it - fItems.begin()) : -1;
        }
    
        /**
         * Return the param label.
         *
         * @param p - the UI parameter index
         *
         * @return the param label
         */
        const char* getParamLabel(int p) { return fItems[uint(p)].fLabel.c_str(); }
    
        /**
         * Return the param shortname.
         *
         * @param p - the UI parameter index
         *
         * @return the param shortname
         */
        const char* getParamShortname(int p) { return fItems[uint(p)].fShortname.c_str(); }
    
        /**
         * Return the param path.
         *
         * @param p - the UI parameter index
         *
         * @return the param path
         */
        const char* getParamAddress(int p) { return fItems[uint(p)].fPath.c_str(); }
    
        /**
         * Return the param metadata.
         *
         * @param p - the UI parameter index
         *
         * @return the param metadata as a map<key, value>
         */
        std::map<const char*, const char*> getMetadata(int p)
        {
            std::map<const char*, const char*> res;
            std::map<std::string, std::string> metadata = fMetaData[uint(p)];
            for (const auto& it : metadata) {
                res[it.first.c_str()] = it.second.c_str();
            }
            return res;
        }

        /**
         * Return the param metadata value.
         *
         * @param p - the UI parameter index
         * @param key - the UI parameter index
         *
         * @return the param metadata value associate to the key
         */
        const char* getMetadata(int p, const char* key)
        {
            return (fMetaData[uint(p)].find(key) != fMetaData[uint(p)].end()) ? fMetaData[uint(p)][key].c_str() : "";
        }
    
        /**
         * Return the param minimum value.
         *
         * @param p - the UI parameter index
         *
         * @return the param minimum value
         */
        FAUSTFLOAT getParamMin(int p) { return fItems[uint(p)].fMin; }
    
        /**
         * Return the param maximum value.
         *
         * @param p - the UI parameter index
         *
         * @return the param maximum value
         */
        FAUSTFLOAT getParamMax(int p) { return fItems[uint(p)].fMax; }
    
        /**
         * Return the param step value.
         *
         * @param p - the UI parameter index
         *
         * @return the param step value
         */
        FAUSTFLOAT getParamStep(int p) { return fItems[uint(p)].fStep; }
    
        /**
         * Return the param init value.
         *
         * @param p - the UI parameter index
         *
         * @return the param init value
         */
        FAUSTFLOAT getParamInit(int p) { return fItems[uint(p)].fInit; }

        /**
         * Return the param memory zone.
         *
         * @param p - the UI parameter index
         *
         * @return the param memory zone.
         */
        FAUSTFLOAT* getParamZone(int p) { return fItems[uint(p)].fZone; }

        /**
         * Return the param value.
         *
         * @param p - the UI parameter index
         *
         * @return the param value.
         */
        FAUSTFLOAT getParamValue(int p) { return *fItems[uint(p)].fZone; }
    
        /**
         * Return the param value.
         *
         * @param str - the UI parameter label/shortname/path
         *
         * @return the param value.
         */
        FAUSTFLOAT getParamValue(const char* str)
        {
            int index = getParamIndex(str);
            if (index >= 0) {
                return getParamValue(index);
            } else {
                fprintf(stderr, "getParamValue : '%s' not found\n", (str == nullptr ? "NULL" : str));
                return FAUSTFLOAT(0);
            }
        }

        /**
         * Set the param value.
         *
         * @param p - the UI parameter index
         * @param v - the UI parameter value
         *
         */
        void setParamValue(int p, FAUSTFLOAT v) { *fItems[uint(p)].fZone = v; }
        
        /**
         * Set the param value.
         *
         * @param p - the UI parameter label/shortname/path
         * @param v - the UI parameter value
         *
         */
        void setParamValue(const char* path, FAUSTFLOAT v)
        {
            int index = getParamIndex(path);
            if (index >= 0) {
                setParamValue(index, v);
            } else {
                fprintf(stderr, "setParamValue : '%s' not found\n", (path == nullptr ? "NULL" : path));
            }
        }

        double getParamRatio(int p) { return fItems[uint(p)].fConversion->faust2ui(*fItems[uint(p)].fZone); }
        void setParamRatio(int p, double r) { *fItems[uint(p)].fZone = FAUSTFLOAT(fItems[uint(p)].fConversion->ui2faust(r)); }

        double value2ratio(int p, double r)    { return fItems[uint(p)].fConversion->faust2ui(r); }
        double ratio2value(int p, double r)    { return fItems[uint(p)].fConversion->ui2faust(r); }

        /**
         * Return the control type (kAcc, kGyr, or -1) for a given parameter.
         *
         * @param p - the UI parameter index
         *
         * @return the type
         */
        Type getParamType(int p)
        {
            if (p >= 0) {
                if (getZoneIndex(fAcc, p, 0) != -1
                    || getZoneIndex(fAcc, p, 1) != -1
                    || getZoneIndex(fAcc, p, 2) != -1) {
                    return kAcc;
                } else if (getZoneIndex(fGyr, p, 0) != -1
                           || getZoneIndex(fGyr, p, 1) != -1
                           || getZoneIndex(fGyr, p, 2) != -1) {
                    return kGyr;
                }
            }
            return kNoType;
        }

        /**
         * Return the Item type (kButton = 0, kCheckButton, kVSlider, kHSlider, kNumEntry, kHBargraph, kVBargraph) for a given parameter.
         *
         * @param p - the UI parameter index
         *
         * @return the Item type
         */
        ItemType getParamItemType(int p)
        {
            return fItems[uint(p)].fItemType;
        }

        /**
         * Set a new value coming from an accelerometer, propagate it to all relevant FAUSTFLOAT* zones.
         *
         * @param acc - 0 for X accelerometer, 1 for Y accelerometer, 2 for Z accelerometer
         * @param value - the new value
         *
         */
        void propagateAcc(int acc, double value)
        {
            for (size_t i = 0; i < fAcc[acc].size(); i++) {
                fAcc[acc][i]->update(value);
            }
        }

        /**
         * Used to edit accelerometer curves and mapping. Set curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param acc - 0 for X accelerometer, 1 for Y accelerometer, 2 for Z accelerometer (-1 means "no mapping")
         * @param curve - between 0 and 3 (0: up, 1: down, 2: up and down, 2: down and up)
         * @param amin - mapping 'min' point
         * @param amid - mapping 'middle' point
         * @param amax - mapping 'max' point
         *
         */
        void setAccConverter(int p, int acc, int curve, double amin, double amid, double amax)
        {
            setConverter(fAcc, p, acc, curve, amin, amid, amax);
        }

        /**
         * Used to edit gyroscope curves and mapping. Set curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param gyr - 0 for X gyroscope, 1 for Y gyroscope, 2 for Z gyroscope (-1 means "no mapping")
         * @param curve - between 0 and 3 (0: up, 1: down, 2: up and down, 2: down and up)
         * @param amin - mapping 'min' point
         * @param amid - mapping 'middle' point
         * @param amax - mapping 'max' point
         *
         */
        void setGyrConverter(int p, int gyr, int curve, double amin, double amid, double amax)
        {
            setConverter(fGyr, p, gyr, curve, amin, amid, amax);
        }

        /**
         * Used to edit accelerometer curves and mapping. Get curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param acc - the acc value to be retrieved (-1 means "no mapping")
         * @param curve - the curve value to be retrieved (between 0 and 3)
         * @param amin - the amin value to be retrieved
         * @param amid - the amid value to be retrieved
         * @param amax - the amax value to be retrieved
         *
         */
        void getAccConverter(int p, int& acc, int& curve, double& amin, double& amid, double& amax)
        {
            getConverter(fAcc, p, acc, curve, amin, amid, amax);
        }

        /**
         * Used to edit gyroscope curves and mapping. Get curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param gyr - the gyr value to be retrieved (-1 means "no mapping")
         * @param curve - the curve value to be retrieved (between 0 and 3)
         * @param amin - the amin value to be retrieved
         * @param amid - the amid value to be retrieved
         * @param amax - the amax value to be retrieved
         *
         */
        void getGyrConverter(int p, int& gyr, int& curve, double& amin, double& amid, double& amax)
        {
            getConverter(fGyr, p, gyr, curve, amin, amid, amax);
        }

        /**
         * Set a new value coming from an gyroscope, propagate it to all relevant FAUSTFLOAT* zones.
         *
         * @param gyr - 0 for X gyroscope, 1 for Y gyroscope, 2 for Z gyroscope
         * @param value - the new value
         *
         */
        void propagateGyr(int gyr, double value)
        {
            for (size_t i = 0; i < fGyr[gyr].size(); i++) {
                fGyr[gyr][i]->update(value);
            }
        }

        /**
         * Get the number of FAUSTFLOAT* zones controlled with the accelerometer.
         *
         * @param acc - 0 for X accelerometer, 1 for Y accelerometer, 2 for Z accelerometer
         * @return the number of zones
         *
         */
        int getAccCount(int acc)
        {
            return (acc >= 0 && acc < 3) ? int(fAcc[acc].size()) : 0;
        }

        /**
         * Get the number of FAUSTFLOAT* zones controlled with the gyroscope.
         *
         * @param gyr - 0 for X gyroscope, 1 for Y gyroscope, 2 for Z gyroscope
         * @param the number of zones
         *
         */
        int getGyrCount(int gyr)
        {
            return (gyr >= 0 && gyr < 3) ? int(fGyr[gyr].size()) : 0;
        }

        /**
         * Get the requested screen color.
         *
         * -1 means no screen color control (no screencolor metadata found)
         * otherwise return 0x00RRGGBB a ready to use color
         *
         */
        int getScreenColor()
        {
            if (fHasScreenControl) {
                int r = (fRedReader) ? fRedReader->getValue() : 0;
                int g = (fGreenReader) ? fGreenReader->getValue() : 0;
                int b = (fBlueReader) ? fBlueReader->getValue() : 0;
                return (r<<16) | (g<<8) | b;
            } else {
                return -1;
            }
        }

};

#endif
/**************************  END  APIUI.h **************************/

class oscItem : public uiItem {
    
    protected:
        
        juce::OSCSender* fSender;
        juce::String fPath;
        
    public:
        
        oscItem(juce::OSCSender* sender, GUI* ui, const juce::String& path, FAUSTFLOAT* zone)
        :uiItem(ui, zone), fSender(sender), fPath(path) {}
        virtual ~oscItem()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fSender->send(fPath, float(v));
        }
    
};

class JuceOSCUI : private juce::OSCReceiver, private juce::OSCReceiver::Listener<juce::OSCReceiver::RealtimeCallback>, public GUI {
    
    private:
        
        juce::OSCSender fSender;
        juce::String fIP;
        int fInputPort, fOutputPort;
        APIUI fAPIUI;
        juce::Array<oscItem*> fOSCItems;  // Pointers are kept and desallocated by the GUI class
        
    public:
        
        JuceOSCUI(const std::string& ip, int in_port, int out_port)
        :fIP(ip), fInputPort(in_port), fOutputPort(out_port)
        {}
        
        virtual ~JuceOSCUI()
        {}
        
        void oscMessageReceived(const juce::OSCMessage& message) override
        {
            juce::String address = message.getAddressPattern().toString();
            
            for (int i = 0; i < message.size(); ++i) {
                if (message[i].isFloat32()) {
                    fAPIUI.setParamValue(address.toStdString().c_str(), FAUSTFLOAT(message[i].getFloat32()));
                    // "get" message with correct address
                } else if (message[i].isString()
                           && message[i].getString().equalsIgnoreCase("get")
                           && juce::String(fAPIUI.getParamAddress(0)).startsWith(address)) {
                    for (int p = 0; p < fAPIUI.getParamsCount(); ++p) {
                        fSender.send(fAPIUI.getParamAddress(p), float(fAPIUI.getParamValue(p)), float(fAPIUI.getParamMin(p)), float(fAPIUI.getParamMax(p)));
                    }
                    // "hello" message
                } else if (message[i].isString()
                           && address.equalsIgnoreCase("/*")
                           && message[i].getString().equalsIgnoreCase("hello")) {
                    juce::String path = fAPIUI.getParamAddress(0);
                    int pos1 = path.indexOfChar('/');
                    int pos2 = path.indexOfChar(pos1 + 1, '/');
                    fSender.send(path.substring(pos1, pos2), fIP, fInputPort, fOutputPort);
                }
            }
        }
        
        bool run() override
        {
            // Keep all zones for update when OSC messages are received
            if (fOSCItems.size() == 0) {
                for (int p = 0; p < fAPIUI.getParamsCount(); ++p) {
                    fOSCItems.add(new oscItem(&fSender, this, fAPIUI.getParamAddress(p), fAPIUI.getParamZone(p)));
                }
            }
            
            if (!fSender.connect(fIP, fOutputPort)) {
                std::cerr << "Error: could not connect to UDP port " << fInputPort << std::endl;
                return false;
            }
            
            if (!connect(fInputPort)) {
                std::cerr << "Error: could not connect to UDP port " << fOutputPort << std::endl;
                return false;
            }
            addListener(this);
            return true;
        }
        
        void stop() override
        {
            fSender.disconnect();
            disconnect();
            removeListener(this);
        }
        
        // -- widget's layouts
        
        void openTabBox(const char* label) override { fAPIUI.openTabBox(label); }
        void openHorizontalBox(const char* label) override { fAPIUI.openHorizontalBox(label); }
        void openVerticalBox(const char* label) override { fAPIUI.openVerticalBox(label); }
        void closeBox() override { fAPIUI.closeBox(); }
        
        // -- active widgets
        
        void addButton(const char* label, FAUSTFLOAT* zone) override { fAPIUI.addButton(label, zone); }
        void addCheckButton(const char* label, FAUSTFLOAT* zone) override { fAPIUI.addCheckButton(label, zone); }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override
        { fAPIUI.addVerticalSlider(label, zone, init, min, max, step); }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override
        { fAPIUI.addHorizontalSlider(label, zone, init, min, max, step); }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override
        { fAPIUI.addNumEntry(label, zone, init, min, max, step); }
        
        // -- passive widgets
        
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override
        { fAPIUI.addHorizontalBargraph(label, zone, min, max); }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override
        { fAPIUI.addVerticalBargraph(label, zone, min, max); }
        
        // -- metadata declarations
        
        void declare(FAUSTFLOAT* zone, const char* key, const char* val) override { fAPIUI.declare(zone, key, val); }
    
};

#endif // __juce_osc__

/**************************  END  JuceOSCUI.h **************************/
#endif

#if defined(MIDICTRL)
/************************** BEGIN juce-midi.h ****************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
***************************************************************************/

#ifndef __juce_midi__
#define __juce_midi__
 

class FAUST_API MapUI;

/**
 *  MIDI input/output handling using JUCE framework: https://juce.com
 */
class juce_midi_handler : public midi_handler {
    
    protected:
    
        juce::MidiBuffer fOutputBuffer;
        juce::CriticalSection fMutex;
    
        void decodeMessage(const juce::MidiMessage& message)
        {
            const juce::uint8* data = message.getRawData();
            int channel = message.getChannel() - 1; // which MIDI channel, 0-15
            double time = message.getTimeStamp();
            
            if (message.isNoteOff()) {
                handleKeyOff(time, channel, data[1], data[2]);
            } else if (message.isNoteOn()) {
                handleKeyOn(time, channel, data[1], data[2]);
            } else if (message.isAftertouch()) {
                handlePolyAfterTouch(time, channel, data[1], data[2]);
            } else if (message.isController()) {
                handleCtrlChange(time, channel, data[1], data[2]);
            } else if (message.isProgramChange()) {
                handleProgChange(time, channel, data[1]);
            } else if (message.isChannelPressure()) {
                handleAfterTouch(time, channel, data[1]);
            } else if (message.isPitchWheel()) {
                handlePitchWheel(time, channel, data[1], data[2]);
            } else if (message.isMidiClock()) {
                handleClock(time);
            // We can consider start and continue as identical messages.
            } else if (message.isMidiStart() || message.isMidiContinue()) {
                handleStart(time);
            } else if (message.isMidiStop()) {
                handleStop(time);
            } else if (message.isSysEx()) {
                std::vector<unsigned char> sysex(data, data + message.getRawDataSize());
                handleSysex(time, sysex);
            } else {
                std::cerr << "Unused MIDI message" << std::endl;
            }
        }
    
    public:
    
        juce_midi_handler():midi_handler("JUCE")
        {}
    
        virtual ~juce_midi_handler() {}
    
        // Used with MidiBuffer (containing several messages)
        void encodeBuffer(juce::MidiBuffer& buffer)
        {
            const juce::ScopedTryLock lock(fMutex);
            if (lock.isLocked()) {
                buffer.swapWith(fOutputBuffer);
                fOutputBuffer.clear();
            } else {
                std::cerr << "encodeBuffer fails..." << std::endl;
            }
        }
        
        void decodeBuffer(juce::MidiBuffer& buffer)
        {
            juce::MidiMessage msg;
            int ignore;
            for (juce::MidiBuffer::Iterator it(buffer); it.getNextEvent(msg, ignore);) {
                decodeMessage(msg);
            }
            buffer.clear();
        }
    
        // MIDI output API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::noteOn(channel + 1, pitch, juce::uint8(velocity)), 0);
            return nullptr;
        }
        
        void keyOff(int channel, int pitch, int velocity)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::noteOff(channel + 1, pitch, juce::uint8(velocity)), 0);
        }
        
        void ctrlChange(int channel, int ctrl, int val)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::controllerEvent(channel + 1, ctrl, juce::uint8(val)), 0);
        }
        
        void chanPress(int channel, int press)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::channelPressureChange(channel + 1, press), 0);
        }
        
        void progChange(int channel, int pgm)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::programChange(channel + 1, pgm), 0);
        }
        
        void keyPress(int channel, int pitch, int press)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::aftertouchChange(channel + 1, pitch, press), 0);
        }
        
        void pitchWheel(int channel, int wheel)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::pitchWheel(channel + 1, range(0, 16383, wheel)), 0);
        }
        
        void ctrlChange14bits(int channel, int ctrl, int value)
        {
            // TODO
        }
        
        void startSync(double date)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::midiStart(), 0);
        }
        
        void stopSync(double date)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::midiStop(), 0);
        }
        
        void clock(double date)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::midiClock(), 0);
        }
    
        void sysEx(double date, std::vector<unsigned char>& message)
        {
            fOutputBuffer.addEvent(juce::MidiMessage(message.data(), (int)message.size()), 0);
        }

};

class juce_midi : public juce_midi_handler, public juce::MidiInputCallback {

    private:
    
        std::unique_ptr<juce::MidiInput> fMidiIn;
        std::unique_ptr<juce::MidiOutput> fMidiOut;
    
        void handleIncomingMidiMessage(juce::MidiInput*, const juce::MidiMessage& message)
        {
            decodeMessage(message);
        }
    
    public:
    
        juce_midi():juce_midi_handler()
        {}
    
        virtual ~juce_midi()
        {
            stopMidi();
        }
        
        bool startMidi()
        {
            if ((fMidiIn = juce::MidiInput::openDevice(juce::MidiInput::getDefaultDeviceIndex(), this)) == nullptr) {
                return false;
            }
            if ((fMidiOut = juce::MidiOutput::openDevice(juce::MidiOutput::getDefaultDeviceIndex())) == nullptr) {
                return false;
            }
            fMidiIn->start();
            return true;
        }
        
        void stopMidi()
        { 
            fMidiIn->stop();
        }
    
        // MIDI output API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::noteOn(channel + 1, pitch, juce::uint8(velocity)));
            return nullptr;
        }
        
        void keyOff(int channel, int pitch, int velocity) 
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::noteOff(channel + 1, pitch, juce::uint8(velocity)));
        }
        
        void ctrlChange(int channel, int ctrl, int val) 
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::controllerEvent(channel + 1, ctrl, juce::uint8(val)));
        }
        
        void chanPress(int channel, int press) 
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::channelPressureChange(channel + 1, press));
        }
        
        void progChange(int channel, int pgm) 
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::programChange(channel + 1, pgm));
        }
          
        void keyPress(int channel, int pitch, int press) 
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::aftertouchChange(channel + 1, pitch, press));
        }
   
        void pitchWheel(int channel, int wheel) 
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::pitchWheel(channel + 1, range(0, 16383, wheel)));
        }
        
        void ctrlChange14bits(int channel, int ctrl, int value)
        {
            // TODO
        }
    
        void startSync(double date) 
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::midiStart());
        }
       
        void stopSync(double date) 
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::midiStop());
        }
        
        void clock(double date) 
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::midiClock());
        }
    
        void sysEx(double date, std::vector<unsigned char>& message)
        {
            fMidiOut->sendMessageNow(juce::MidiMessage(message.data(), (int)message.size()));
        }
    
};

#endif // __juce_midi__

/**************************  END  juce-midi.h **************************/
/************************** BEGIN timed-base_dsp.h *****************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
***************************************************************************/

#ifndef __timed_dsp__
#define __timed_dsp__

#include <set>
#include <float.h>
#include <assert.h>


namespace {
    
#if __APPLE__
#if TARGET_OS_IPHONE
    //inline double GetCurrentTimeInUsec() { return double(CAHostTimeBase::GetCurrentTimeInNanos()) / 1000.; }
    // TODO
    inline double GetCurrentTimeInUsec() { return 0.0; }
#else
    #include <CoreAudio/HostTime.h>
    inline double GetCurrentTimeInUsec() { return double(AudioConvertHostTimeToNanos(AudioGetCurrentHostTime())) / 1000.; }
#endif
#endif

#if __linux__
#include <sys/time.h>
inline double GetCurrentTimeInUsec() 
{
    struct timeval tv;
    (void)gettimeofday(&tv, (struct timezone *)NULL);
    return double((tv.tv_sec * 1000000) + tv.tv_usec);
}
#endif

#if _WIN32
#include <windows.h>
inline double GetCurrentTimeInUsec(void)
{
    LARGE_INTEGER time;
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&time);
    return double(time.QuadPart) / double(frequency.QuadPart) * 1000000.0;
}
#endif
    
}

/**
 * ZoneUI : this class collect zones in a set.
 */

struct ZoneUI : public GenericUI {
    
    std::set<FAUSTFLOAT*> fZoneSet;
    
    ZoneUI():GenericUI() {}
    virtual ~ZoneUI() {}
    
    void insertZone(FAUSTFLOAT* zone) 
    { 
        if (GUI::gTimedZoneMap.find(zone) != GUI::gTimedZoneMap.end()) {
            fZoneSet.insert(zone);
        } 
    }
    
    // -- active widgets
    void addButton(const char* label, FAUSTFLOAT* zone)
    {
        insertZone(zone);
    }
    void addCheckButton(const char* label, FAUSTFLOAT* zone)
    {
        insertZone(zone);
    }
    void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
    {
        insertZone(zone);
    }
    void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
    {
        insertZone(zone);
    }
    void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
    {
        insertZone(zone);
    }
    
    // -- passive widgets
    void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
    {
        insertZone(zone);
    }
    void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
    {
        insertZone(zone);
    }
  
};

/**
 * Timed signal processor that allows to handle the decorated DSP by 'slices'
 * that is, calling the 'compute' method several times and changing control
 * parameters between slices. Timestamps are in usec.
 */

class timed_dsp : public decorator_dsp {

    protected:
        
        double fDateUsec;       // Compute call date in usec
        double fOffsetUsec;     // Compute call offset in usec
        bool fFirstCallback;
        ZoneUI fZoneUI;
    
        FAUSTFLOAT** fInputsSlice;
        FAUSTFLOAT** fOutputsSlice;
    
        void computeSlice(int offset, int slice, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) 
        {
            if (slice > 0) {
                for (int chan = 0; chan < fDSP->getNumInputs(); chan++) {
                    fInputsSlice[chan] = &(inputs[chan][offset]);
                }
                for (int chan = 0; chan < fDSP->getNumOutputs(); chan++) {
                    fOutputsSlice[chan] = &(outputs[chan][offset]);
                }
                fDSP->compute(slice, fInputsSlice, fOutputsSlice);
            } 
        }
        
        double convertUsecToSample(double usec)
        {
            return std::max<double>(0., (double(getSampleRate()) * (usec - fDateUsec)) / 1000000.);
        }
        
        ztimedmap::iterator getNextControl(DatedControl& res)
        {
            DatedControl date1(DBL_MAX, 0);
            ztimedmap::iterator it1, it2 = GUI::gTimedZoneMap.end();
            std::set<FAUSTFLOAT*>::iterator it3;
              
            // Find date of next audio slice to compute
            for (it3 = fZoneUI.fZoneSet.begin(); it3 != fZoneUI.fZoneSet.end(); it3++) {
                // If value list is not empty, get the date and keep the minimal one
                it1 = GUI::gTimedZoneMap.find(*it3);
                if (it1 != GUI::gTimedZoneMap.end()) { // Check if zone still in global GUI::gTimedZoneMap (since MidiUI may have been desallocated)
                    DatedControl date2;
                    if (ringbuffer_peek((*it1).second, (char*)&date2, sizeof(DatedControl)) == sizeof(DatedControl) 
                        && date2.fDate < date1.fDate) {
                        it2 = it1;
                        date1 = date2;
                    }
                }
            }
            
            res = date1;
            return it2;
        }
        
        virtual void computeAux(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs, bool convert_ts)
        {
            int slice, offset = 0;
            ztimedmap::iterator it;
            DatedControl next_control;
             
            // Do audio computation "slice" by "slice"
            while ((it = getNextControl(next_control)) != GUI::gTimedZoneMap.end()) {
                
                // If needed, convert next_control in samples from begining of the buffer, possible moving to 0 (if negative)
                if (convert_ts) {
                    next_control.fDate = convertUsecToSample(next_control.fDate);
                }
                     
                // Compute audio slice
                slice = int(next_control.fDate) - offset;
                computeSlice(offset, slice, inputs, outputs);
                offset += slice;
               
                // Update control
                ringbuffer_t* control_values = (*it).second;
                *((*it).first) = next_control.fValue;
                
                // Move ringbuffer pointer
                ringbuffer_read_advance(control_values, sizeof(DatedControl));
            } 
            
            // Compute last audio slice
            slice = count - offset;
            computeSlice(offset, slice, inputs, outputs);
        }

    public:

        timed_dsp(base_dsp* base_dsp):decorator_dsp(base_dsp), fDateUsec(0), fOffsetUsec(0), fFirstCallback(true)
        {
            fInputsSlice = new FAUSTFLOAT*[base_dsp->getNumInputs()];
            fOutputsSlice = new FAUSTFLOAT*[base_dsp->getNumOutputs()];
        }
        virtual ~timed_dsp() 
        {
            delete [] fInputsSlice;
            delete [] fOutputsSlice;
        }
        
        virtual void init(int sample_rate)
        {
            fDSP->init(sample_rate);
        }
        
        virtual void buildUserInterface(UI* ui_interface)   
        { 
            fDSP->buildUserInterface(ui_interface); 
            // Only keep zones that are in GUI::gTimedZoneMap
            fDSP->buildUserInterface(&fZoneUI);
        }
    
        virtual timed_dsp* clone()
        {
            return new timed_dsp(fDSP->clone());
        }
    
        // Default method take a timestamp at 'compute' call time
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            compute(::GetCurrentTimeInUsec(), count, inputs, outputs);
        }    
        
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            if (date_usec == -1) {
                // Timestamp is expressed in frames
                computeAux(count, inputs, outputs, false);
            } else {
                // Save the timestamp offset in the first callback
                if (fFirstCallback) {
                    fFirstCallback = false;
                    double current_date_usec = ::GetCurrentTimeInUsec();
                    fDateUsec = current_date_usec;
                    fOffsetUsec = current_date_usec - date_usec;
                }
                
                // RtMidi mode: timestamp must be converted in frames
                computeAux(count, inputs, outputs, true);
                
                // Keep call date 
                fDateUsec = date_usec + fOffsetUsec;
            }
        }
        
};

#endif
/************************** END timed-base_dsp.h **************************/
#endif

#if defined(POLY2)
#include "effect.h"
#endif 

// we require macro declarations
#define FAUST_UIMACROS

// but we will ignore most of them
#define FAUST_ADDBUTTON(l,f)
#define FAUST_ADDCHECKBOX(l,f)
#define FAUST_ADDSOUNDFILE(l,s)
#define FAUST_ADDVERTICALSLIDER(l,f,i,a,b,s)
#define FAUST_ADDHORIZONTALSLIDER(l,f,i,a,b,s)
#define FAUST_ADDNUMENTRY(l,f,i,a,b,s)
#define FAUST_ADDVERTICALBARGRAPH(l,f,a,b)
#define FAUST_ADDHORIZONTALBARGRAPH(l,f,a,b)


#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif


class mydsp : public base_dsp {
	
 public:
	
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	FAUSTFLOAT fVslider0;
	double fConst3;
	FAUSTFLOAT fVslider1;
	double fRec8[2];
	double fConst4;
	FAUSTFLOAT fVslider2;
	double fRec11[2];
	FAUSTFLOAT fVslider3;
	double fRec18[2];
	double fVec0[2];
	FAUSTFLOAT fVslider4;
	double fRec27[2];
	double fRec26[2];
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT fVslider5;
	double fRec28[2];
	double fRec29[2];
	FAUSTFLOAT fVbargraph1;
	FAUSTFLOAT fVslider6;
	double fRec30[2];
	FAUSTFLOAT fVslider7;
	double fRec31[2];
	FAUSTFLOAT fVslider8;
	double fRec33[2];
	int IOTA0;
	double fVec1[4194304];
	double fConst5;
	FAUSTFLOAT fVslider9;
	double fRec34[2];
	double fRec35[2];
	double fRec36[2];
	double fRec37[2];
	double fRec32[2];
	double fVec2[2];
	double fRec25[2];
	double fRec24[2];
	FAUSTFLOAT fVbargraph2;
	double fRec23[2];
	FAUSTFLOAT fVbargraph3;
	FAUSTFLOAT fVslider10;
	double fRec38[2];
	FAUSTFLOAT fVslider11;
	double fRec42[2];
	FAUSTFLOAT fVslider12;
	double fRec43[2];
	FAUSTFLOAT fVslider13;
	double fRec44[2];
	FAUSTFLOAT fVslider14;
	double fRec45[2];
	double fRec39[2];
	double fRec40[2];
	double fRec46[2];
	double fRec47[2];
	double fRec49[2];
	double fRec50[2];
	double fRec52[2];
	double fRec53[2];
	double fRec55[2];
	double fRec56[2];
	double fRec58[2];
	double fRec59[2];
	double fRec61[2];
	double fRec62[2];
	double fRec64[2];
	double fRec65[2];
	double fRec67[2];
	double fRec68[2];
	double fRec70[2];
	double fRec71[2];
	double fRec73[2];
	double fRec74[2];
	double fRec76[2];
	double fRec77[2];
	double fRec79[2];
	double fRec80[2];
	double fRec82[2];
	double fRec83[2];
	double fRec85[2];
	double fRec86[2];
	double fRec88[2];
	double fRec89[2];
	double fRec91[2];
	double fRec92[2];
	double fRec94[2];
	double fRec95[2];
	double fRec97[2];
	double fRec98[2];
	double fRec100[2];
	double fRec101[2];
	double fRec103[2];
	double fRec104[2];
	double fRec106[2];
	double fRec107[2];
	double fRec109[2];
	double fRec110[2];
	double fRec112[2];
	double fRec113[2];
	double fRec115[2];
	double fRec116[2];
	double fRec118[2];
	double fRec119[2];
	double fRec121[2];
	double fRec122[2];
	double fRec124[2];
	double fRec125[2];
	double fRec127[2];
	double fRec128[2];
	double fRec130[2];
	double fRec131[2];
	double fRec133[2];
	double fRec134[2];
	double fRec136[2];
	double fRec137[2];
	double fRec22[2];
	FAUSTFLOAT fVbargraph4;
	double fRec19[2];
	double fVec3[2];
	double fRec143[2];
	FAUSTFLOAT fVbargraph5;
	FAUSTFLOAT fVslider15;
	double fRec144[2];
	double fVec4[2];
	double fRec142[2];
	double fRec141[2];
	FAUSTFLOAT fVbargraph6;
	double fRec140[2];
	FAUSTFLOAT fVbargraph7;
	double fRec145[2];
	double fRec146[2];
	double fRec148[2];
	double fRec149[2];
	double fRec151[2];
	double fRec152[2];
	double fRec154[2];
	double fRec155[2];
	double fRec157[2];
	double fRec158[2];
	double fRec160[2];
	double fRec161[2];
	double fRec163[2];
	double fRec164[2];
	double fRec166[2];
	double fRec167[2];
	double fRec169[2];
	double fRec170[2];
	double fRec172[2];
	double fRec173[2];
	double fRec175[2];
	double fRec176[2];
	double fRec178[2];
	double fRec179[2];
	double fRec181[2];
	double fRec182[2];
	double fRec184[2];
	double fRec185[2];
	double fRec187[2];
	double fRec188[2];
	double fRec190[2];
	double fRec191[2];
	double fRec193[2];
	double fRec194[2];
	double fRec196[2];
	double fRec197[2];
	double fRec199[2];
	double fRec200[2];
	double fRec202[2];
	double fRec203[2];
	double fRec205[2];
	double fRec206[2];
	double fRec208[2];
	double fRec209[2];
	double fRec211[2];
	double fRec212[2];
	double fRec214[2];
	double fRec215[2];
	double fRec217[2];
	double fRec218[2];
	double fRec220[2];
	double fRec221[2];
	double fRec223[2];
	double fRec224[2];
	double fRec226[2];
	double fRec227[2];
	double fRec229[2];
	double fRec230[2];
	double fRec232[2];
	double fRec233[2];
	double fRec235[2];
	double fRec236[2];
	double fRec238[2];
	double fRec239[2];
	double fRec139[2];
	FAUSTFLOAT fVbargraph8;
	double fRec20[2];
	double fVec5[2];
	FAUSTFLOAT fVslider16;
	double fRec245[2];
	double fVec6[2];
	double fRec244[2];
	double fRec243[2];
	FAUSTFLOAT fVbargraph9;
	double fRec242[2];
	FAUSTFLOAT fVbargraph10;
	double fRec246[2];
	double fRec247[2];
	double fRec249[2];
	double fRec250[2];
	double fRec252[2];
	double fRec253[2];
	double fRec255[2];
	double fRec256[2];
	double fRec258[2];
	double fRec259[2];
	double fRec261[2];
	double fRec262[2];
	double fRec264[2];
	double fRec265[2];
	double fRec267[2];
	double fRec268[2];
	double fRec270[2];
	double fRec271[2];
	double fRec273[2];
	double fRec274[2];
	double fRec276[2];
	double fRec277[2];
	double fRec279[2];
	double fRec280[2];
	double fRec282[2];
	double fRec283[2];
	double fRec285[2];
	double fRec286[2];
	double fRec288[2];
	double fRec289[2];
	double fRec291[2];
	double fRec292[2];
	double fRec294[2];
	double fRec295[2];
	double fRec297[2];
	double fRec298[2];
	double fRec300[2];
	double fRec301[2];
	double fRec303[2];
	double fRec304[2];
	double fRec306[2];
	double fRec307[2];
	double fRec309[2];
	double fRec310[2];
	double fRec312[2];
	double fRec313[2];
	double fRec315[2];
	double fRec316[2];
	double fRec318[2];
	double fRec319[2];
	double fRec321[2];
	double fRec322[2];
	double fRec324[2];
	double fRec325[2];
	double fRec327[2];
	double fRec328[2];
	double fRec330[2];
	double fRec331[2];
	double fRec333[2];
	double fRec334[2];
	double fRec336[2];
	double fRec337[2];
	double fRec339[2];
	double fRec340[2];
	double fRec241[2];
	FAUSTFLOAT fVbargraph11;
	double fRec21[2];
	double fVec7[4194304];
	FAUSTFLOAT fVslider17;
	double fRec342[2];
	double fRec343[2];
	double fRec344[2];
	double fRec345[2];
	double fRec17[2];
	double fRec354[2];
	FAUSTFLOAT fVbargraph12;
	double fRec355[2];
	FAUSTFLOAT fVbargraph13;
	FAUSTFLOAT fVslider18;
	double fRec357[2];
	double fRec358[2];
	double fRec359[2];
	double fRec360[2];
	double fRec356[2];
	double fVec8[2];
	double fRec353[2];
	double fRec352[2];
	FAUSTFLOAT fVbargraph14;
	double fRec351[2];
	FAUSTFLOAT fVbargraph15;
	double fRec361[2];
	double fRec362[2];
	double fRec364[2];
	double fRec365[2];
	double fRec367[2];
	double fRec368[2];
	double fRec370[2];
	double fRec371[2];
	double fRec373[2];
	double fRec374[2];
	double fRec376[2];
	double fRec377[2];
	double fRec379[2];
	double fRec380[2];
	double fRec382[2];
	double fRec383[2];
	double fRec385[2];
	double fRec386[2];
	double fRec388[2];
	double fRec389[2];
	double fRec391[2];
	double fRec392[2];
	double fRec394[2];
	double fRec395[2];
	double fRec397[2];
	double fRec398[2];
	double fRec400[2];
	double fRec401[2];
	double fRec403[2];
	double fRec404[2];
	double fRec406[2];
	double fRec407[2];
	double fRec409[2];
	double fRec410[2];
	double fRec412[2];
	double fRec413[2];
	double fRec415[2];
	double fRec416[2];
	double fRec418[2];
	double fRec419[2];
	double fRec421[2];
	double fRec422[2];
	double fRec424[2];
	double fRec425[2];
	double fRec427[2];
	double fRec428[2];
	double fRec430[2];
	double fRec431[2];
	double fRec433[2];
	double fRec434[2];
	double fRec436[2];
	double fRec437[2];
	double fRec439[2];
	double fRec440[2];
	double fRec442[2];
	double fRec443[2];
	double fRec445[2];
	double fRec446[2];
	double fRec448[2];
	double fRec449[2];
	double fRec451[2];
	double fRec452[2];
	double fRec454[2];
	double fRec455[2];
	double fRec350[2];
	FAUSTFLOAT fVbargraph16;
	double fRec347[2];
	double fRec461[2];
	FAUSTFLOAT fVbargraph17;
	double fVec9[2];
	double fRec460[2];
	double fRec459[2];
	FAUSTFLOAT fVbargraph18;
	double fRec458[2];
	FAUSTFLOAT fVbargraph19;
	double fRec462[2];
	double fRec463[2];
	double fRec465[2];
	double fRec466[2];
	double fRec468[2];
	double fRec469[2];
	double fRec471[2];
	double fRec472[2];
	double fRec474[2];
	double fRec475[2];
	double fRec477[2];
	double fRec478[2];
	double fRec480[2];
	double fRec481[2];
	double fRec483[2];
	double fRec484[2];
	double fRec486[2];
	double fRec487[2];
	double fRec489[2];
	double fRec490[2];
	double fRec492[2];
	double fRec493[2];
	double fRec495[2];
	double fRec496[2];
	double fRec498[2];
	double fRec499[2];
	double fRec501[2];
	double fRec502[2];
	double fRec504[2];
	double fRec505[2];
	double fRec507[2];
	double fRec508[2];
	double fRec510[2];
	double fRec511[2];
	double fRec513[2];
	double fRec514[2];
	double fRec516[2];
	double fRec517[2];
	double fRec519[2];
	double fRec520[2];
	double fRec522[2];
	double fRec523[2];
	double fRec525[2];
	double fRec526[2];
	double fRec528[2];
	double fRec529[2];
	double fRec531[2];
	double fRec532[2];
	double fRec534[2];
	double fRec535[2];
	double fRec537[2];
	double fRec538[2];
	double fRec540[2];
	double fRec541[2];
	double fRec543[2];
	double fRec544[2];
	double fRec546[2];
	double fRec547[2];
	double fRec549[2];
	double fRec550[2];
	double fRec552[2];
	double fRec553[2];
	double fRec555[2];
	double fRec556[2];
	double fRec457[2];
	FAUSTFLOAT fVbargraph20;
	double fRec348[2];
	double fVec10[2];
	double fRec561[2];
	double fRec560[2];
	FAUSTFLOAT fVbargraph21;
	double fRec559[2];
	FAUSTFLOAT fVbargraph22;
	double fRec562[2];
	double fRec563[2];
	double fRec565[2];
	double fRec566[2];
	double fRec568[2];
	double fRec569[2];
	double fRec571[2];
	double fRec572[2];
	double fRec574[2];
	double fRec575[2];
	double fRec577[2];
	double fRec578[2];
	double fRec580[2];
	double fRec581[2];
	double fRec583[2];
	double fRec584[2];
	double fRec586[2];
	double fRec587[2];
	double fRec589[2];
	double fRec590[2];
	double fRec592[2];
	double fRec593[2];
	double fRec595[2];
	double fRec596[2];
	double fRec598[2];
	double fRec599[2];
	double fRec601[2];
	double fRec602[2];
	double fRec604[2];
	double fRec605[2];
	double fRec607[2];
	double fRec608[2];
	double fRec610[2];
	double fRec611[2];
	double fRec613[2];
	double fRec614[2];
	double fRec616[2];
	double fRec617[2];
	double fRec619[2];
	double fRec620[2];
	double fRec622[2];
	double fRec623[2];
	double fRec625[2];
	double fRec626[2];
	double fRec628[2];
	double fRec629[2];
	double fRec631[2];
	double fRec632[2];
	double fRec634[2];
	double fRec635[2];
	double fRec637[2];
	double fRec638[2];
	double fRec640[2];
	double fRec641[2];
	double fRec643[2];
	double fRec644[2];
	double fRec646[2];
	double fRec647[2];
	double fRec649[2];
	double fRec650[2];
	double fRec652[2];
	double fRec653[2];
	double fRec655[2];
	double fRec656[2];
	double fRec558[2];
	FAUSTFLOAT fVbargraph23;
	double fRec349[2];
	double fVec11[4194304];
	FAUSTFLOAT fVslider19;
	double fRec658[2];
	double fRec659[2];
	double fRec660[2];
	double fRec661[2];
	double fRec346[2];
	FAUSTFLOAT fVslider20;
	double fRec674[2];
	double fRec675[2];
	double fRec676[2];
	double fRec677[2];
	double fRec673[2];
	double fRec678[2];
	FAUSTFLOAT fVbargraph24;
	double fRec679[2];
	FAUSTFLOAT fVbargraph25;
	double fVec12[2];
	double fRec672[2];
	double fRec671[2];
	FAUSTFLOAT fVbargraph26;
	double fRec670[2];
	FAUSTFLOAT fVbargraph27;
	double fRec667[2];
	double fRec668[2];
	double fRec680[2];
	double fRec681[2];
	double fRec683[2];
	double fRec684[2];
	double fRec686[2];
	double fRec687[2];
	double fRec689[2];
	double fRec690[2];
	double fRec692[2];
	double fRec693[2];
	double fRec695[2];
	double fRec696[2];
	double fRec698[2];
	double fRec699[2];
	double fRec701[2];
	double fRec702[2];
	double fRec704[2];
	double fRec705[2];
	double fRec707[2];
	double fRec708[2];
	double fRec710[2];
	double fRec711[2];
	double fRec713[2];
	double fRec714[2];
	double fRec716[2];
	double fRec717[2];
	double fRec719[2];
	double fRec720[2];
	double fRec722[2];
	double fRec723[2];
	double fRec725[2];
	double fRec726[2];
	double fRec728[2];
	double fRec729[2];
	double fRec731[2];
	double fRec732[2];
	double fRec734[2];
	double fRec735[2];
	double fRec737[2];
	double fRec738[2];
	double fRec740[2];
	double fRec741[2];
	double fRec743[2];
	double fRec744[2];
	double fRec746[2];
	double fRec747[2];
	double fRec749[2];
	double fRec750[2];
	double fRec752[2];
	double fRec753[2];
	double fRec755[2];
	double fRec756[2];
	double fRec758[2];
	double fRec759[2];
	double fRec761[2];
	double fRec762[2];
	double fRec764[2];
	double fRec765[2];
	double fRec767[2];
	double fRec768[2];
	double fRec770[2];
	double fRec771[2];
	double fRec666[2];
	FAUSTFLOAT fVbargraph28;
	double fRec663[2];
	double fRec777[2];
	FAUSTFLOAT fVbargraph29;
	double fVec13[2];
	double fRec776[2];
	double fRec775[2];
	FAUSTFLOAT fVbargraph30;
	double fRec774[2];
	FAUSTFLOAT fVbargraph31;
	double fRec778[2];
	double fRec779[2];
	double fRec781[2];
	double fRec782[2];
	double fRec784[2];
	double fRec785[2];
	double fRec787[2];
	double fRec788[2];
	double fRec790[2];
	double fRec791[2];
	double fRec793[2];
	double fRec794[2];
	double fRec796[2];
	double fRec797[2];
	double fRec799[2];
	double fRec800[2];
	double fRec802[2];
	double fRec803[2];
	double fRec805[2];
	double fRec806[2];
	double fRec808[2];
	double fRec809[2];
	double fRec811[2];
	double fRec812[2];
	double fRec814[2];
	double fRec815[2];
	double fRec817[2];
	double fRec818[2];
	double fRec820[2];
	double fRec821[2];
	double fRec823[2];
	double fRec824[2];
	double fRec826[2];
	double fRec827[2];
	double fRec829[2];
	double fRec830[2];
	double fRec832[2];
	double fRec833[2];
	double fRec835[2];
	double fRec836[2];
	double fRec838[2];
	double fRec839[2];
	double fRec841[2];
	double fRec842[2];
	double fRec844[2];
	double fRec845[2];
	double fRec847[2];
	double fRec848[2];
	double fRec850[2];
	double fRec851[2];
	double fRec853[2];
	double fRec854[2];
	double fRec856[2];
	double fRec857[2];
	double fRec859[2];
	double fRec860[2];
	double fRec862[2];
	double fRec863[2];
	double fRec865[2];
	double fRec866[2];
	double fRec868[2];
	double fRec869[2];
	double fRec871[2];
	double fRec872[2];
	double fRec773[2];
	FAUSTFLOAT fVbargraph32;
	double fRec664[2];
	double fVec14[2];
	double fRec877[2];
	double fRec876[2];
	FAUSTFLOAT fVbargraph33;
	double fRec875[2];
	FAUSTFLOAT fVbargraph34;
	double fRec878[2];
	double fRec879[2];
	double fRec881[2];
	double fRec882[2];
	double fRec884[2];
	double fRec885[2];
	double fRec887[2];
	double fRec888[2];
	double fRec890[2];
	double fRec891[2];
	double fRec893[2];
	double fRec894[2];
	double fRec896[2];
	double fRec897[2];
	double fRec899[2];
	double fRec900[2];
	double fRec902[2];
	double fRec903[2];
	double fRec905[2];
	double fRec906[2];
	double fRec908[2];
	double fRec909[2];
	double fRec911[2];
	double fRec912[2];
	double fRec914[2];
	double fRec915[2];
	double fRec917[2];
	double fRec918[2];
	double fRec920[2];
	double fRec921[2];
	double fRec923[2];
	double fRec924[2];
	double fRec926[2];
	double fRec927[2];
	double fRec929[2];
	double fRec930[2];
	double fRec932[2];
	double fRec933[2];
	double fRec935[2];
	double fRec936[2];
	double fRec938[2];
	double fRec939[2];
	double fRec941[2];
	double fRec942[2];
	double fRec944[2];
	double fRec945[2];
	double fRec947[2];
	double fRec948[2];
	double fRec950[2];
	double fRec951[2];
	double fRec953[2];
	double fRec954[2];
	double fRec956[2];
	double fRec957[2];
	double fRec959[2];
	double fRec960[2];
	double fRec962[2];
	double fRec963[2];
	double fRec965[2];
	double fRec966[2];
	double fRec968[2];
	double fRec969[2];
	double fRec971[2];
	double fRec972[2];
	double fRec874[2];
	FAUSTFLOAT fVbargraph35;
	double fRec665[2];
	double fVec15[4194304];
	FAUSTFLOAT fVslider21;
	double fRec974[2];
	double fRec975[2];
	double fRec976[2];
	double fRec977[2];
	double fRec662[2];
	double fRec986[2];
	FAUSTFLOAT fVbargraph36;
	double fRec987[2];
	FAUSTFLOAT fVbargraph37;
	FAUSTFLOAT fVslider22;
	double fRec989[2];
	double fRec990[2];
	double fRec991[2];
	double fRec992[2];
	double fRec988[2];
	double fVec16[2];
	double fRec985[2];
	double fRec984[2];
	FAUSTFLOAT fVbargraph38;
	double fRec983[2];
	FAUSTFLOAT fVbargraph39;
	double fRec993[2];
	double fRec994[2];
	double fRec996[2];
	double fRec997[2];
	double fRec999[2];
	double fRec1000[2];
	double fRec1002[2];
	double fRec1003[2];
	double fRec1005[2];
	double fRec1006[2];
	double fRec1008[2];
	double fRec1009[2];
	double fRec1011[2];
	double fRec1012[2];
	double fRec1014[2];
	double fRec1015[2];
	double fRec1017[2];
	double fRec1018[2];
	double fRec1020[2];
	double fRec1021[2];
	double fRec1023[2];
	double fRec1024[2];
	double fRec1026[2];
	double fRec1027[2];
	double fRec1029[2];
	double fRec1030[2];
	double fRec1032[2];
	double fRec1033[2];
	double fRec1035[2];
	double fRec1036[2];
	double fRec1038[2];
	double fRec1039[2];
	double fRec1041[2];
	double fRec1042[2];
	double fRec1044[2];
	double fRec1045[2];
	double fRec1047[2];
	double fRec1048[2];
	double fRec1050[2];
	double fRec1051[2];
	double fRec1053[2];
	double fRec1054[2];
	double fRec1056[2];
	double fRec1057[2];
	double fRec1059[2];
	double fRec1060[2];
	double fRec1062[2];
	double fRec1063[2];
	double fRec1065[2];
	double fRec1066[2];
	double fRec1068[2];
	double fRec1069[2];
	double fRec1071[2];
	double fRec1072[2];
	double fRec1074[2];
	double fRec1075[2];
	double fRec1077[2];
	double fRec1078[2];
	double fRec1080[2];
	double fRec1081[2];
	double fRec1083[2];
	double fRec1084[2];
	double fRec1086[2];
	double fRec1087[2];
	double fRec982[2];
	FAUSTFLOAT fVbargraph40;
	double fRec979[2];
	double fRec1093[2];
	FAUSTFLOAT fVbargraph41;
	double fVec17[2];
	double fRec1092[2];
	double fRec1091[2];
	FAUSTFLOAT fVbargraph42;
	double fRec1090[2];
	FAUSTFLOAT fVbargraph43;
	double fRec1094[2];
	double fRec1095[2];
	double fRec1097[2];
	double fRec1098[2];
	double fRec1100[2];
	double fRec1101[2];
	double fRec1103[2];
	double fRec1104[2];
	double fRec1106[2];
	double fRec1107[2];
	double fRec1109[2];
	double fRec1110[2];
	double fRec1112[2];
	double fRec1113[2];
	double fRec1115[2];
	double fRec1116[2];
	double fRec1118[2];
	double fRec1119[2];
	double fRec1121[2];
	double fRec1122[2];
	double fRec1124[2];
	double fRec1125[2];
	double fRec1127[2];
	double fRec1128[2];
	double fRec1130[2];
	double fRec1131[2];
	double fRec1133[2];
	double fRec1134[2];
	double fRec1136[2];
	double fRec1137[2];
	double fRec1139[2];
	double fRec1140[2];
	double fRec1142[2];
	double fRec1143[2];
	double fRec1145[2];
	double fRec1146[2];
	double fRec1148[2];
	double fRec1149[2];
	double fRec1151[2];
	double fRec1152[2];
	double fRec1154[2];
	double fRec1155[2];
	double fRec1157[2];
	double fRec1158[2];
	double fRec1160[2];
	double fRec1161[2];
	double fRec1163[2];
	double fRec1164[2];
	double fRec1166[2];
	double fRec1167[2];
	double fRec1169[2];
	double fRec1170[2];
	double fRec1172[2];
	double fRec1173[2];
	double fRec1175[2];
	double fRec1176[2];
	double fRec1178[2];
	double fRec1179[2];
	double fRec1181[2];
	double fRec1182[2];
	double fRec1184[2];
	double fRec1185[2];
	double fRec1187[2];
	double fRec1188[2];
	double fRec1089[2];
	FAUSTFLOAT fVbargraph44;
	double fRec980[2];
	double fVec18[2];
	double fRec1193[2];
	double fRec1192[2];
	FAUSTFLOAT fVbargraph45;
	double fRec1191[2];
	FAUSTFLOAT fVbargraph46;
	double fRec1194[2];
	double fRec1195[2];
	double fRec1197[2];
	double fRec1198[2];
	double fRec1200[2];
	double fRec1201[2];
	double fRec1203[2];
	double fRec1204[2];
	double fRec1206[2];
	double fRec1207[2];
	double fRec1209[2];
	double fRec1210[2];
	double fRec1212[2];
	double fRec1213[2];
	double fRec1215[2];
	double fRec1216[2];
	double fRec1218[2];
	double fRec1219[2];
	double fRec1221[2];
	double fRec1222[2];
	double fRec1224[2];
	double fRec1225[2];
	double fRec1227[2];
	double fRec1228[2];
	double fRec1230[2];
	double fRec1231[2];
	double fRec1233[2];
	double fRec1234[2];
	double fRec1236[2];
	double fRec1237[2];
	double fRec1239[2];
	double fRec1240[2];
	double fRec1242[2];
	double fRec1243[2];
	double fRec1245[2];
	double fRec1246[2];
	double fRec1248[2];
	double fRec1249[2];
	double fRec1251[2];
	double fRec1252[2];
	double fRec1254[2];
	double fRec1255[2];
	double fRec1257[2];
	double fRec1258[2];
	double fRec1260[2];
	double fRec1261[2];
	double fRec1263[2];
	double fRec1264[2];
	double fRec1266[2];
	double fRec1267[2];
	double fRec1269[2];
	double fRec1270[2];
	double fRec1272[2];
	double fRec1273[2];
	double fRec1275[2];
	double fRec1276[2];
	double fRec1278[2];
	double fRec1279[2];
	double fRec1281[2];
	double fRec1282[2];
	double fRec1284[2];
	double fRec1285[2];
	double fRec1287[2];
	double fRec1288[2];
	double fRec1190[2];
	FAUSTFLOAT fVbargraph47;
	double fRec981[2];
	double fVec19[4194304];
	FAUSTFLOAT fVslider23;
	double fRec1290[2];
	double fRec1291[2];
	double fRec1292[2];
	double fRec1293[2];
	double fRec978[2];
	double fRec12[2];
	double fRec9[2];
	double fRec6[2];
	double fRec7[512];
	int iRec4[2];
	double fRec5[2];
	double fConst7;
	double fConst8;
	double fRec2[2];
	double fRec1[2];
	int iConst9;
	FAUSTFLOAT fVslider24;
	double fRec1294[2];
	double fRec0[2];
	FAUSTFLOAT fVbargraph48;
	double fRec1303[2];
	double fRec1301[2];
	double fRec1302[512];
	int iRec1299[2];
	double fRec1300[2];
	double fRec1297[2];
	double fRec1296[2];
	double fRec1295[2];
	FAUSTFLOAT fVbargraph49;
	double fRec1313[2];
	double fRec1311[2];
	double fRec1312[512];
	int iRec1309[2];
	double fRec1310[2];
	double fRec1307[2];
	double fRec1306[2];
	double fRec1305[2];
	FAUSTFLOAT fVbargraph50;
	double fRec1323[2];
	double fRec1321[2];
	double fRec1322[512];
	int iRec1319[2];
	double fRec1320[2];
	double fRec1317[2];
	double fRec1316[2];
	double fRec1315[2];
	FAUSTFLOAT fVbargraph51;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.9");
		m->declare("compile_options", "-a /usr/local/share/faust/juce/juce-plugin.cpp -lang cpp -i -scn base_dsp -es 1 -mcd 16 -uim -double -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "RITI_AutonomousNetwork_fixedVersion.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "RITI_AutonomousNetwork_fixedVersion");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.3");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.3");
	}

	virtual int getNumInputs() {
		return 8;
	}
	virtual int getNumOutputs() {
		return 4;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, double(fSampleRate)));
		fConst1 = std::pow(0.001, 0.1 / fConst0);
		fConst2 = 0.1 * fConst0 + -1.0;
		fConst3 = 1.0 / fConst0;
		fConst4 = 3.141592653589793 / fConst0;
		fConst5 = 12.0 * fConst0;
		double fConst6 = std::tan(1570.7963267948965 / fConst0);
		fConst7 = fConst6 / (fConst6 + 1.0);
		fConst8 = 2.0 * fConst7;
		iConst9 = int(0.002 * fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = FAUSTFLOAT(1.0);
		fVslider1 = FAUSTFLOAT(2e+04);
		fVslider2 = FAUSTFLOAT(1.0);
		fVslider3 = FAUSTFLOAT(5e+01);
		fVslider4 = FAUSTFLOAT(1.0);
		fVslider5 = FAUSTFLOAT(-8e+01);
		fVslider6 = FAUSTFLOAT(0.0);
		fVslider7 = FAUSTFLOAT(1e+01);
		fVslider8 = FAUSTFLOAT(1.0);
		fVslider9 = FAUSTFLOAT(6.9396);
		fVslider10 = FAUSTFLOAT(0.0);
		fVslider11 = FAUSTFLOAT(1.0);
		fVslider12 = FAUSTFLOAT(1.0);
		fVslider13 = FAUSTFLOAT(0.0);
		fVslider14 = FAUSTFLOAT(1.0);
		fVslider15 = FAUSTFLOAT(3.518);
		fVslider16 = FAUSTFLOAT(1.073);
		fVslider17 = FAUSTFLOAT(5.7426);
		fVslider18 = FAUSTFLOAT(4.6264);
		fVslider19 = FAUSTFLOAT(8.613900000000001);
		fVslider20 = FAUSTFLOAT(9.2528);
		fVslider21 = FAUSTFLOAT(2.8713);
		fVslider22 = FAUSTFLOAT(2.3132);
		fVslider23 = FAUSTFLOAT(11.4852);
		fVslider24 = FAUSTFLOAT(-8e+01);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fRec8[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec11[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec18[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fVec0[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec27[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec26[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec28[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec29[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec30[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec31[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec33[l10] = 0.0;
		}
		IOTA0 = 0;
		for (int l11 = 0; l11 < 4194304; l11 = l11 + 1) {
			fVec1[l11] = 0.0;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec34[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			fRec35[l13] = 0.0;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fRec36[l14] = 0.0;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fRec37[l15] = 0.0;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec32[l16] = 0.0;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fVec2[l17] = 0.0;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec25[l18] = 0.0;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fRec24[l19] = 0.0;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fRec23[l20] = 0.0;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec38[l21] = 0.0;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			fRec42[l22] = 0.0;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			fRec43[l23] = 0.0;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			fRec44[l24] = 0.0;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			fRec45[l25] = 0.0;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			fRec39[l26] = 0.0;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec40[l27] = 0.0;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			fRec46[l28] = 0.0;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			fRec47[l29] = 0.0;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			fRec49[l30] = 0.0;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			fRec50[l31] = 0.0;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			fRec52[l32] = 0.0;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			fRec53[l33] = 0.0;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			fRec55[l34] = 0.0;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			fRec56[l35] = 0.0;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			fRec58[l36] = 0.0;
		}
		for (int l37 = 0; l37 < 2; l37 = l37 + 1) {
			fRec59[l37] = 0.0;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			fRec61[l38] = 0.0;
		}
		for (int l39 = 0; l39 < 2; l39 = l39 + 1) {
			fRec62[l39] = 0.0;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			fRec64[l40] = 0.0;
		}
		for (int l41 = 0; l41 < 2; l41 = l41 + 1) {
			fRec65[l41] = 0.0;
		}
		for (int l42 = 0; l42 < 2; l42 = l42 + 1) {
			fRec67[l42] = 0.0;
		}
		for (int l43 = 0; l43 < 2; l43 = l43 + 1) {
			fRec68[l43] = 0.0;
		}
		for (int l44 = 0; l44 < 2; l44 = l44 + 1) {
			fRec70[l44] = 0.0;
		}
		for (int l45 = 0; l45 < 2; l45 = l45 + 1) {
			fRec71[l45] = 0.0;
		}
		for (int l46 = 0; l46 < 2; l46 = l46 + 1) {
			fRec73[l46] = 0.0;
		}
		for (int l47 = 0; l47 < 2; l47 = l47 + 1) {
			fRec74[l47] = 0.0;
		}
		for (int l48 = 0; l48 < 2; l48 = l48 + 1) {
			fRec76[l48] = 0.0;
		}
		for (int l49 = 0; l49 < 2; l49 = l49 + 1) {
			fRec77[l49] = 0.0;
		}
		for (int l50 = 0; l50 < 2; l50 = l50 + 1) {
			fRec79[l50] = 0.0;
		}
		for (int l51 = 0; l51 < 2; l51 = l51 + 1) {
			fRec80[l51] = 0.0;
		}
		for (int l52 = 0; l52 < 2; l52 = l52 + 1) {
			fRec82[l52] = 0.0;
		}
		for (int l53 = 0; l53 < 2; l53 = l53 + 1) {
			fRec83[l53] = 0.0;
		}
		for (int l54 = 0; l54 < 2; l54 = l54 + 1) {
			fRec85[l54] = 0.0;
		}
		for (int l55 = 0; l55 < 2; l55 = l55 + 1) {
			fRec86[l55] = 0.0;
		}
		for (int l56 = 0; l56 < 2; l56 = l56 + 1) {
			fRec88[l56] = 0.0;
		}
		for (int l57 = 0; l57 < 2; l57 = l57 + 1) {
			fRec89[l57] = 0.0;
		}
		for (int l58 = 0; l58 < 2; l58 = l58 + 1) {
			fRec91[l58] = 0.0;
		}
		for (int l59 = 0; l59 < 2; l59 = l59 + 1) {
			fRec92[l59] = 0.0;
		}
		for (int l60 = 0; l60 < 2; l60 = l60 + 1) {
			fRec94[l60] = 0.0;
		}
		for (int l61 = 0; l61 < 2; l61 = l61 + 1) {
			fRec95[l61] = 0.0;
		}
		for (int l62 = 0; l62 < 2; l62 = l62 + 1) {
			fRec97[l62] = 0.0;
		}
		for (int l63 = 0; l63 < 2; l63 = l63 + 1) {
			fRec98[l63] = 0.0;
		}
		for (int l64 = 0; l64 < 2; l64 = l64 + 1) {
			fRec100[l64] = 0.0;
		}
		for (int l65 = 0; l65 < 2; l65 = l65 + 1) {
			fRec101[l65] = 0.0;
		}
		for (int l66 = 0; l66 < 2; l66 = l66 + 1) {
			fRec103[l66] = 0.0;
		}
		for (int l67 = 0; l67 < 2; l67 = l67 + 1) {
			fRec104[l67] = 0.0;
		}
		for (int l68 = 0; l68 < 2; l68 = l68 + 1) {
			fRec106[l68] = 0.0;
		}
		for (int l69 = 0; l69 < 2; l69 = l69 + 1) {
			fRec107[l69] = 0.0;
		}
		for (int l70 = 0; l70 < 2; l70 = l70 + 1) {
			fRec109[l70] = 0.0;
		}
		for (int l71 = 0; l71 < 2; l71 = l71 + 1) {
			fRec110[l71] = 0.0;
		}
		for (int l72 = 0; l72 < 2; l72 = l72 + 1) {
			fRec112[l72] = 0.0;
		}
		for (int l73 = 0; l73 < 2; l73 = l73 + 1) {
			fRec113[l73] = 0.0;
		}
		for (int l74 = 0; l74 < 2; l74 = l74 + 1) {
			fRec115[l74] = 0.0;
		}
		for (int l75 = 0; l75 < 2; l75 = l75 + 1) {
			fRec116[l75] = 0.0;
		}
		for (int l76 = 0; l76 < 2; l76 = l76 + 1) {
			fRec118[l76] = 0.0;
		}
		for (int l77 = 0; l77 < 2; l77 = l77 + 1) {
			fRec119[l77] = 0.0;
		}
		for (int l78 = 0; l78 < 2; l78 = l78 + 1) {
			fRec121[l78] = 0.0;
		}
		for (int l79 = 0; l79 < 2; l79 = l79 + 1) {
			fRec122[l79] = 0.0;
		}
		for (int l80 = 0; l80 < 2; l80 = l80 + 1) {
			fRec124[l80] = 0.0;
		}
		for (int l81 = 0; l81 < 2; l81 = l81 + 1) {
			fRec125[l81] = 0.0;
		}
		for (int l82 = 0; l82 < 2; l82 = l82 + 1) {
			fRec127[l82] = 0.0;
		}
		for (int l83 = 0; l83 < 2; l83 = l83 + 1) {
			fRec128[l83] = 0.0;
		}
		for (int l84 = 0; l84 < 2; l84 = l84 + 1) {
			fRec130[l84] = 0.0;
		}
		for (int l85 = 0; l85 < 2; l85 = l85 + 1) {
			fRec131[l85] = 0.0;
		}
		for (int l86 = 0; l86 < 2; l86 = l86 + 1) {
			fRec133[l86] = 0.0;
		}
		for (int l87 = 0; l87 < 2; l87 = l87 + 1) {
			fRec134[l87] = 0.0;
		}
		for (int l88 = 0; l88 < 2; l88 = l88 + 1) {
			fRec136[l88] = 0.0;
		}
		for (int l89 = 0; l89 < 2; l89 = l89 + 1) {
			fRec137[l89] = 0.0;
		}
		for (int l90 = 0; l90 < 2; l90 = l90 + 1) {
			fRec22[l90] = 0.0;
		}
		for (int l91 = 0; l91 < 2; l91 = l91 + 1) {
			fRec19[l91] = 0.0;
		}
		for (int l92 = 0; l92 < 2; l92 = l92 + 1) {
			fVec3[l92] = 0.0;
		}
		for (int l93 = 0; l93 < 2; l93 = l93 + 1) {
			fRec143[l93] = 0.0;
		}
		for (int l94 = 0; l94 < 2; l94 = l94 + 1) {
			fRec144[l94] = 0.0;
		}
		for (int l95 = 0; l95 < 2; l95 = l95 + 1) {
			fVec4[l95] = 0.0;
		}
		for (int l96 = 0; l96 < 2; l96 = l96 + 1) {
			fRec142[l96] = 0.0;
		}
		for (int l97 = 0; l97 < 2; l97 = l97 + 1) {
			fRec141[l97] = 0.0;
		}
		for (int l98 = 0; l98 < 2; l98 = l98 + 1) {
			fRec140[l98] = 0.0;
		}
		for (int l99 = 0; l99 < 2; l99 = l99 + 1) {
			fRec145[l99] = 0.0;
		}
		for (int l100 = 0; l100 < 2; l100 = l100 + 1) {
			fRec146[l100] = 0.0;
		}
		for (int l101 = 0; l101 < 2; l101 = l101 + 1) {
			fRec148[l101] = 0.0;
		}
		for (int l102 = 0; l102 < 2; l102 = l102 + 1) {
			fRec149[l102] = 0.0;
		}
		for (int l103 = 0; l103 < 2; l103 = l103 + 1) {
			fRec151[l103] = 0.0;
		}
		for (int l104 = 0; l104 < 2; l104 = l104 + 1) {
			fRec152[l104] = 0.0;
		}
		for (int l105 = 0; l105 < 2; l105 = l105 + 1) {
			fRec154[l105] = 0.0;
		}
		for (int l106 = 0; l106 < 2; l106 = l106 + 1) {
			fRec155[l106] = 0.0;
		}
		for (int l107 = 0; l107 < 2; l107 = l107 + 1) {
			fRec157[l107] = 0.0;
		}
		for (int l108 = 0; l108 < 2; l108 = l108 + 1) {
			fRec158[l108] = 0.0;
		}
		for (int l109 = 0; l109 < 2; l109 = l109 + 1) {
			fRec160[l109] = 0.0;
		}
		for (int l110 = 0; l110 < 2; l110 = l110 + 1) {
			fRec161[l110] = 0.0;
		}
		for (int l111 = 0; l111 < 2; l111 = l111 + 1) {
			fRec163[l111] = 0.0;
		}
		for (int l112 = 0; l112 < 2; l112 = l112 + 1) {
			fRec164[l112] = 0.0;
		}
		for (int l113 = 0; l113 < 2; l113 = l113 + 1) {
			fRec166[l113] = 0.0;
		}
		for (int l114 = 0; l114 < 2; l114 = l114 + 1) {
			fRec167[l114] = 0.0;
		}
		for (int l115 = 0; l115 < 2; l115 = l115 + 1) {
			fRec169[l115] = 0.0;
		}
		for (int l116 = 0; l116 < 2; l116 = l116 + 1) {
			fRec170[l116] = 0.0;
		}
		for (int l117 = 0; l117 < 2; l117 = l117 + 1) {
			fRec172[l117] = 0.0;
		}
		for (int l118 = 0; l118 < 2; l118 = l118 + 1) {
			fRec173[l118] = 0.0;
		}
		for (int l119 = 0; l119 < 2; l119 = l119 + 1) {
			fRec175[l119] = 0.0;
		}
		for (int l120 = 0; l120 < 2; l120 = l120 + 1) {
			fRec176[l120] = 0.0;
		}
		for (int l121 = 0; l121 < 2; l121 = l121 + 1) {
			fRec178[l121] = 0.0;
		}
		for (int l122 = 0; l122 < 2; l122 = l122 + 1) {
			fRec179[l122] = 0.0;
		}
		for (int l123 = 0; l123 < 2; l123 = l123 + 1) {
			fRec181[l123] = 0.0;
		}
		for (int l124 = 0; l124 < 2; l124 = l124 + 1) {
			fRec182[l124] = 0.0;
		}
		for (int l125 = 0; l125 < 2; l125 = l125 + 1) {
			fRec184[l125] = 0.0;
		}
		for (int l126 = 0; l126 < 2; l126 = l126 + 1) {
			fRec185[l126] = 0.0;
		}
		for (int l127 = 0; l127 < 2; l127 = l127 + 1) {
			fRec187[l127] = 0.0;
		}
		for (int l128 = 0; l128 < 2; l128 = l128 + 1) {
			fRec188[l128] = 0.0;
		}
		for (int l129 = 0; l129 < 2; l129 = l129 + 1) {
			fRec190[l129] = 0.0;
		}
		for (int l130 = 0; l130 < 2; l130 = l130 + 1) {
			fRec191[l130] = 0.0;
		}
		for (int l131 = 0; l131 < 2; l131 = l131 + 1) {
			fRec193[l131] = 0.0;
		}
		for (int l132 = 0; l132 < 2; l132 = l132 + 1) {
			fRec194[l132] = 0.0;
		}
		for (int l133 = 0; l133 < 2; l133 = l133 + 1) {
			fRec196[l133] = 0.0;
		}
		for (int l134 = 0; l134 < 2; l134 = l134 + 1) {
			fRec197[l134] = 0.0;
		}
		for (int l135 = 0; l135 < 2; l135 = l135 + 1) {
			fRec199[l135] = 0.0;
		}
		for (int l136 = 0; l136 < 2; l136 = l136 + 1) {
			fRec200[l136] = 0.0;
		}
		for (int l137 = 0; l137 < 2; l137 = l137 + 1) {
			fRec202[l137] = 0.0;
		}
		for (int l138 = 0; l138 < 2; l138 = l138 + 1) {
			fRec203[l138] = 0.0;
		}
		for (int l139 = 0; l139 < 2; l139 = l139 + 1) {
			fRec205[l139] = 0.0;
		}
		for (int l140 = 0; l140 < 2; l140 = l140 + 1) {
			fRec206[l140] = 0.0;
		}
		for (int l141 = 0; l141 < 2; l141 = l141 + 1) {
			fRec208[l141] = 0.0;
		}
		for (int l142 = 0; l142 < 2; l142 = l142 + 1) {
			fRec209[l142] = 0.0;
		}
		for (int l143 = 0; l143 < 2; l143 = l143 + 1) {
			fRec211[l143] = 0.0;
		}
		for (int l144 = 0; l144 < 2; l144 = l144 + 1) {
			fRec212[l144] = 0.0;
		}
		for (int l145 = 0; l145 < 2; l145 = l145 + 1) {
			fRec214[l145] = 0.0;
		}
		for (int l146 = 0; l146 < 2; l146 = l146 + 1) {
			fRec215[l146] = 0.0;
		}
		for (int l147 = 0; l147 < 2; l147 = l147 + 1) {
			fRec217[l147] = 0.0;
		}
		for (int l148 = 0; l148 < 2; l148 = l148 + 1) {
			fRec218[l148] = 0.0;
		}
		for (int l149 = 0; l149 < 2; l149 = l149 + 1) {
			fRec220[l149] = 0.0;
		}
		for (int l150 = 0; l150 < 2; l150 = l150 + 1) {
			fRec221[l150] = 0.0;
		}
		for (int l151 = 0; l151 < 2; l151 = l151 + 1) {
			fRec223[l151] = 0.0;
		}
		for (int l152 = 0; l152 < 2; l152 = l152 + 1) {
			fRec224[l152] = 0.0;
		}
		for (int l153 = 0; l153 < 2; l153 = l153 + 1) {
			fRec226[l153] = 0.0;
		}
		for (int l154 = 0; l154 < 2; l154 = l154 + 1) {
			fRec227[l154] = 0.0;
		}
		for (int l155 = 0; l155 < 2; l155 = l155 + 1) {
			fRec229[l155] = 0.0;
		}
		for (int l156 = 0; l156 < 2; l156 = l156 + 1) {
			fRec230[l156] = 0.0;
		}
		for (int l157 = 0; l157 < 2; l157 = l157 + 1) {
			fRec232[l157] = 0.0;
		}
		for (int l158 = 0; l158 < 2; l158 = l158 + 1) {
			fRec233[l158] = 0.0;
		}
		for (int l159 = 0; l159 < 2; l159 = l159 + 1) {
			fRec235[l159] = 0.0;
		}
		for (int l160 = 0; l160 < 2; l160 = l160 + 1) {
			fRec236[l160] = 0.0;
		}
		for (int l161 = 0; l161 < 2; l161 = l161 + 1) {
			fRec238[l161] = 0.0;
		}
		for (int l162 = 0; l162 < 2; l162 = l162 + 1) {
			fRec239[l162] = 0.0;
		}
		for (int l163 = 0; l163 < 2; l163 = l163 + 1) {
			fRec139[l163] = 0.0;
		}
		for (int l164 = 0; l164 < 2; l164 = l164 + 1) {
			fRec20[l164] = 0.0;
		}
		for (int l165 = 0; l165 < 2; l165 = l165 + 1) {
			fVec5[l165] = 0.0;
		}
		for (int l166 = 0; l166 < 2; l166 = l166 + 1) {
			fRec245[l166] = 0.0;
		}
		for (int l167 = 0; l167 < 2; l167 = l167 + 1) {
			fVec6[l167] = 0.0;
		}
		for (int l168 = 0; l168 < 2; l168 = l168 + 1) {
			fRec244[l168] = 0.0;
		}
		for (int l169 = 0; l169 < 2; l169 = l169 + 1) {
			fRec243[l169] = 0.0;
		}
		for (int l170 = 0; l170 < 2; l170 = l170 + 1) {
			fRec242[l170] = 0.0;
		}
		for (int l171 = 0; l171 < 2; l171 = l171 + 1) {
			fRec246[l171] = 0.0;
		}
		for (int l172 = 0; l172 < 2; l172 = l172 + 1) {
			fRec247[l172] = 0.0;
		}
		for (int l173 = 0; l173 < 2; l173 = l173 + 1) {
			fRec249[l173] = 0.0;
		}
		for (int l174 = 0; l174 < 2; l174 = l174 + 1) {
			fRec250[l174] = 0.0;
		}
		for (int l175 = 0; l175 < 2; l175 = l175 + 1) {
			fRec252[l175] = 0.0;
		}
		for (int l176 = 0; l176 < 2; l176 = l176 + 1) {
			fRec253[l176] = 0.0;
		}
		for (int l177 = 0; l177 < 2; l177 = l177 + 1) {
			fRec255[l177] = 0.0;
		}
		for (int l178 = 0; l178 < 2; l178 = l178 + 1) {
			fRec256[l178] = 0.0;
		}
		for (int l179 = 0; l179 < 2; l179 = l179 + 1) {
			fRec258[l179] = 0.0;
		}
		for (int l180 = 0; l180 < 2; l180 = l180 + 1) {
			fRec259[l180] = 0.0;
		}
		for (int l181 = 0; l181 < 2; l181 = l181 + 1) {
			fRec261[l181] = 0.0;
		}
		for (int l182 = 0; l182 < 2; l182 = l182 + 1) {
			fRec262[l182] = 0.0;
		}
		for (int l183 = 0; l183 < 2; l183 = l183 + 1) {
			fRec264[l183] = 0.0;
		}
		for (int l184 = 0; l184 < 2; l184 = l184 + 1) {
			fRec265[l184] = 0.0;
		}
		for (int l185 = 0; l185 < 2; l185 = l185 + 1) {
			fRec267[l185] = 0.0;
		}
		for (int l186 = 0; l186 < 2; l186 = l186 + 1) {
			fRec268[l186] = 0.0;
		}
		for (int l187 = 0; l187 < 2; l187 = l187 + 1) {
			fRec270[l187] = 0.0;
		}
		for (int l188 = 0; l188 < 2; l188 = l188 + 1) {
			fRec271[l188] = 0.0;
		}
		for (int l189 = 0; l189 < 2; l189 = l189 + 1) {
			fRec273[l189] = 0.0;
		}
		for (int l190 = 0; l190 < 2; l190 = l190 + 1) {
			fRec274[l190] = 0.0;
		}
		for (int l191 = 0; l191 < 2; l191 = l191 + 1) {
			fRec276[l191] = 0.0;
		}
		for (int l192 = 0; l192 < 2; l192 = l192 + 1) {
			fRec277[l192] = 0.0;
		}
		for (int l193 = 0; l193 < 2; l193 = l193 + 1) {
			fRec279[l193] = 0.0;
		}
		for (int l194 = 0; l194 < 2; l194 = l194 + 1) {
			fRec280[l194] = 0.0;
		}
		for (int l195 = 0; l195 < 2; l195 = l195 + 1) {
			fRec282[l195] = 0.0;
		}
		for (int l196 = 0; l196 < 2; l196 = l196 + 1) {
			fRec283[l196] = 0.0;
		}
		for (int l197 = 0; l197 < 2; l197 = l197 + 1) {
			fRec285[l197] = 0.0;
		}
		for (int l198 = 0; l198 < 2; l198 = l198 + 1) {
			fRec286[l198] = 0.0;
		}
		for (int l199 = 0; l199 < 2; l199 = l199 + 1) {
			fRec288[l199] = 0.0;
		}
		for (int l200 = 0; l200 < 2; l200 = l200 + 1) {
			fRec289[l200] = 0.0;
		}
		for (int l201 = 0; l201 < 2; l201 = l201 + 1) {
			fRec291[l201] = 0.0;
		}
		for (int l202 = 0; l202 < 2; l202 = l202 + 1) {
			fRec292[l202] = 0.0;
		}
		for (int l203 = 0; l203 < 2; l203 = l203 + 1) {
			fRec294[l203] = 0.0;
		}
		for (int l204 = 0; l204 < 2; l204 = l204 + 1) {
			fRec295[l204] = 0.0;
		}
		for (int l205 = 0; l205 < 2; l205 = l205 + 1) {
			fRec297[l205] = 0.0;
		}
		for (int l206 = 0; l206 < 2; l206 = l206 + 1) {
			fRec298[l206] = 0.0;
		}
		for (int l207 = 0; l207 < 2; l207 = l207 + 1) {
			fRec300[l207] = 0.0;
		}
		for (int l208 = 0; l208 < 2; l208 = l208 + 1) {
			fRec301[l208] = 0.0;
		}
		for (int l209 = 0; l209 < 2; l209 = l209 + 1) {
			fRec303[l209] = 0.0;
		}
		for (int l210 = 0; l210 < 2; l210 = l210 + 1) {
			fRec304[l210] = 0.0;
		}
		for (int l211 = 0; l211 < 2; l211 = l211 + 1) {
			fRec306[l211] = 0.0;
		}
		for (int l212 = 0; l212 < 2; l212 = l212 + 1) {
			fRec307[l212] = 0.0;
		}
		for (int l213 = 0; l213 < 2; l213 = l213 + 1) {
			fRec309[l213] = 0.0;
		}
		for (int l214 = 0; l214 < 2; l214 = l214 + 1) {
			fRec310[l214] = 0.0;
		}
		for (int l215 = 0; l215 < 2; l215 = l215 + 1) {
			fRec312[l215] = 0.0;
		}
		for (int l216 = 0; l216 < 2; l216 = l216 + 1) {
			fRec313[l216] = 0.0;
		}
		for (int l217 = 0; l217 < 2; l217 = l217 + 1) {
			fRec315[l217] = 0.0;
		}
		for (int l218 = 0; l218 < 2; l218 = l218 + 1) {
			fRec316[l218] = 0.0;
		}
		for (int l219 = 0; l219 < 2; l219 = l219 + 1) {
			fRec318[l219] = 0.0;
		}
		for (int l220 = 0; l220 < 2; l220 = l220 + 1) {
			fRec319[l220] = 0.0;
		}
		for (int l221 = 0; l221 < 2; l221 = l221 + 1) {
			fRec321[l221] = 0.0;
		}
		for (int l222 = 0; l222 < 2; l222 = l222 + 1) {
			fRec322[l222] = 0.0;
		}
		for (int l223 = 0; l223 < 2; l223 = l223 + 1) {
			fRec324[l223] = 0.0;
		}
		for (int l224 = 0; l224 < 2; l224 = l224 + 1) {
			fRec325[l224] = 0.0;
		}
		for (int l225 = 0; l225 < 2; l225 = l225 + 1) {
			fRec327[l225] = 0.0;
		}
		for (int l226 = 0; l226 < 2; l226 = l226 + 1) {
			fRec328[l226] = 0.0;
		}
		for (int l227 = 0; l227 < 2; l227 = l227 + 1) {
			fRec330[l227] = 0.0;
		}
		for (int l228 = 0; l228 < 2; l228 = l228 + 1) {
			fRec331[l228] = 0.0;
		}
		for (int l229 = 0; l229 < 2; l229 = l229 + 1) {
			fRec333[l229] = 0.0;
		}
		for (int l230 = 0; l230 < 2; l230 = l230 + 1) {
			fRec334[l230] = 0.0;
		}
		for (int l231 = 0; l231 < 2; l231 = l231 + 1) {
			fRec336[l231] = 0.0;
		}
		for (int l232 = 0; l232 < 2; l232 = l232 + 1) {
			fRec337[l232] = 0.0;
		}
		for (int l233 = 0; l233 < 2; l233 = l233 + 1) {
			fRec339[l233] = 0.0;
		}
		for (int l234 = 0; l234 < 2; l234 = l234 + 1) {
			fRec340[l234] = 0.0;
		}
		for (int l235 = 0; l235 < 2; l235 = l235 + 1) {
			fRec241[l235] = 0.0;
		}
		for (int l236 = 0; l236 < 2; l236 = l236 + 1) {
			fRec21[l236] = 0.0;
		}
		for (int l237 = 0; l237 < 4194304; l237 = l237 + 1) {
			fVec7[l237] = 0.0;
		}
		for (int l238 = 0; l238 < 2; l238 = l238 + 1) {
			fRec342[l238] = 0.0;
		}
		for (int l239 = 0; l239 < 2; l239 = l239 + 1) {
			fRec343[l239] = 0.0;
		}
		for (int l240 = 0; l240 < 2; l240 = l240 + 1) {
			fRec344[l240] = 0.0;
		}
		for (int l241 = 0; l241 < 2; l241 = l241 + 1) {
			fRec345[l241] = 0.0;
		}
		for (int l242 = 0; l242 < 2; l242 = l242 + 1) {
			fRec17[l242] = 0.0;
		}
		for (int l243 = 0; l243 < 2; l243 = l243 + 1) {
			fRec354[l243] = 0.0;
		}
		for (int l244 = 0; l244 < 2; l244 = l244 + 1) {
			fRec355[l244] = 0.0;
		}
		for (int l245 = 0; l245 < 2; l245 = l245 + 1) {
			fRec357[l245] = 0.0;
		}
		for (int l246 = 0; l246 < 2; l246 = l246 + 1) {
			fRec358[l246] = 0.0;
		}
		for (int l247 = 0; l247 < 2; l247 = l247 + 1) {
			fRec359[l247] = 0.0;
		}
		for (int l248 = 0; l248 < 2; l248 = l248 + 1) {
			fRec360[l248] = 0.0;
		}
		for (int l249 = 0; l249 < 2; l249 = l249 + 1) {
			fRec356[l249] = 0.0;
		}
		for (int l250 = 0; l250 < 2; l250 = l250 + 1) {
			fVec8[l250] = 0.0;
		}
		for (int l251 = 0; l251 < 2; l251 = l251 + 1) {
			fRec353[l251] = 0.0;
		}
		for (int l252 = 0; l252 < 2; l252 = l252 + 1) {
			fRec352[l252] = 0.0;
		}
		for (int l253 = 0; l253 < 2; l253 = l253 + 1) {
			fRec351[l253] = 0.0;
		}
		for (int l254 = 0; l254 < 2; l254 = l254 + 1) {
			fRec361[l254] = 0.0;
		}
		for (int l255 = 0; l255 < 2; l255 = l255 + 1) {
			fRec362[l255] = 0.0;
		}
		for (int l256 = 0; l256 < 2; l256 = l256 + 1) {
			fRec364[l256] = 0.0;
		}
		for (int l257 = 0; l257 < 2; l257 = l257 + 1) {
			fRec365[l257] = 0.0;
		}
		for (int l258 = 0; l258 < 2; l258 = l258 + 1) {
			fRec367[l258] = 0.0;
		}
		for (int l259 = 0; l259 < 2; l259 = l259 + 1) {
			fRec368[l259] = 0.0;
		}
		for (int l260 = 0; l260 < 2; l260 = l260 + 1) {
			fRec370[l260] = 0.0;
		}
		for (int l261 = 0; l261 < 2; l261 = l261 + 1) {
			fRec371[l261] = 0.0;
		}
		for (int l262 = 0; l262 < 2; l262 = l262 + 1) {
			fRec373[l262] = 0.0;
		}
		for (int l263 = 0; l263 < 2; l263 = l263 + 1) {
			fRec374[l263] = 0.0;
		}
		for (int l264 = 0; l264 < 2; l264 = l264 + 1) {
			fRec376[l264] = 0.0;
		}
		for (int l265 = 0; l265 < 2; l265 = l265 + 1) {
			fRec377[l265] = 0.0;
		}
		for (int l266 = 0; l266 < 2; l266 = l266 + 1) {
			fRec379[l266] = 0.0;
		}
		for (int l267 = 0; l267 < 2; l267 = l267 + 1) {
			fRec380[l267] = 0.0;
		}
		for (int l268 = 0; l268 < 2; l268 = l268 + 1) {
			fRec382[l268] = 0.0;
		}
		for (int l269 = 0; l269 < 2; l269 = l269 + 1) {
			fRec383[l269] = 0.0;
		}
		for (int l270 = 0; l270 < 2; l270 = l270 + 1) {
			fRec385[l270] = 0.0;
		}
		for (int l271 = 0; l271 < 2; l271 = l271 + 1) {
			fRec386[l271] = 0.0;
		}
		for (int l272 = 0; l272 < 2; l272 = l272 + 1) {
			fRec388[l272] = 0.0;
		}
		for (int l273 = 0; l273 < 2; l273 = l273 + 1) {
			fRec389[l273] = 0.0;
		}
		for (int l274 = 0; l274 < 2; l274 = l274 + 1) {
			fRec391[l274] = 0.0;
		}
		for (int l275 = 0; l275 < 2; l275 = l275 + 1) {
			fRec392[l275] = 0.0;
		}
		for (int l276 = 0; l276 < 2; l276 = l276 + 1) {
			fRec394[l276] = 0.0;
		}
		for (int l277 = 0; l277 < 2; l277 = l277 + 1) {
			fRec395[l277] = 0.0;
		}
		for (int l278 = 0; l278 < 2; l278 = l278 + 1) {
			fRec397[l278] = 0.0;
		}
		for (int l279 = 0; l279 < 2; l279 = l279 + 1) {
			fRec398[l279] = 0.0;
		}
		for (int l280 = 0; l280 < 2; l280 = l280 + 1) {
			fRec400[l280] = 0.0;
		}
		for (int l281 = 0; l281 < 2; l281 = l281 + 1) {
			fRec401[l281] = 0.0;
		}
		for (int l282 = 0; l282 < 2; l282 = l282 + 1) {
			fRec403[l282] = 0.0;
		}
		for (int l283 = 0; l283 < 2; l283 = l283 + 1) {
			fRec404[l283] = 0.0;
		}
		for (int l284 = 0; l284 < 2; l284 = l284 + 1) {
			fRec406[l284] = 0.0;
		}
		for (int l285 = 0; l285 < 2; l285 = l285 + 1) {
			fRec407[l285] = 0.0;
		}
		for (int l286 = 0; l286 < 2; l286 = l286 + 1) {
			fRec409[l286] = 0.0;
		}
		for (int l287 = 0; l287 < 2; l287 = l287 + 1) {
			fRec410[l287] = 0.0;
		}
		for (int l288 = 0; l288 < 2; l288 = l288 + 1) {
			fRec412[l288] = 0.0;
		}
		for (int l289 = 0; l289 < 2; l289 = l289 + 1) {
			fRec413[l289] = 0.0;
		}
		for (int l290 = 0; l290 < 2; l290 = l290 + 1) {
			fRec415[l290] = 0.0;
		}
		for (int l291 = 0; l291 < 2; l291 = l291 + 1) {
			fRec416[l291] = 0.0;
		}
		for (int l292 = 0; l292 < 2; l292 = l292 + 1) {
			fRec418[l292] = 0.0;
		}
		for (int l293 = 0; l293 < 2; l293 = l293 + 1) {
			fRec419[l293] = 0.0;
		}
		for (int l294 = 0; l294 < 2; l294 = l294 + 1) {
			fRec421[l294] = 0.0;
		}
		for (int l295 = 0; l295 < 2; l295 = l295 + 1) {
			fRec422[l295] = 0.0;
		}
		for (int l296 = 0; l296 < 2; l296 = l296 + 1) {
			fRec424[l296] = 0.0;
		}
		for (int l297 = 0; l297 < 2; l297 = l297 + 1) {
			fRec425[l297] = 0.0;
		}
		for (int l298 = 0; l298 < 2; l298 = l298 + 1) {
			fRec427[l298] = 0.0;
		}
		for (int l299 = 0; l299 < 2; l299 = l299 + 1) {
			fRec428[l299] = 0.0;
		}
		for (int l300 = 0; l300 < 2; l300 = l300 + 1) {
			fRec430[l300] = 0.0;
		}
		for (int l301 = 0; l301 < 2; l301 = l301 + 1) {
			fRec431[l301] = 0.0;
		}
		for (int l302 = 0; l302 < 2; l302 = l302 + 1) {
			fRec433[l302] = 0.0;
		}
		for (int l303 = 0; l303 < 2; l303 = l303 + 1) {
			fRec434[l303] = 0.0;
		}
		for (int l304 = 0; l304 < 2; l304 = l304 + 1) {
			fRec436[l304] = 0.0;
		}
		for (int l305 = 0; l305 < 2; l305 = l305 + 1) {
			fRec437[l305] = 0.0;
		}
		for (int l306 = 0; l306 < 2; l306 = l306 + 1) {
			fRec439[l306] = 0.0;
		}
		for (int l307 = 0; l307 < 2; l307 = l307 + 1) {
			fRec440[l307] = 0.0;
		}
		for (int l308 = 0; l308 < 2; l308 = l308 + 1) {
			fRec442[l308] = 0.0;
		}
		for (int l309 = 0; l309 < 2; l309 = l309 + 1) {
			fRec443[l309] = 0.0;
		}
		for (int l310 = 0; l310 < 2; l310 = l310 + 1) {
			fRec445[l310] = 0.0;
		}
		for (int l311 = 0; l311 < 2; l311 = l311 + 1) {
			fRec446[l311] = 0.0;
		}
		for (int l312 = 0; l312 < 2; l312 = l312 + 1) {
			fRec448[l312] = 0.0;
		}
		for (int l313 = 0; l313 < 2; l313 = l313 + 1) {
			fRec449[l313] = 0.0;
		}
		for (int l314 = 0; l314 < 2; l314 = l314 + 1) {
			fRec451[l314] = 0.0;
		}
		for (int l315 = 0; l315 < 2; l315 = l315 + 1) {
			fRec452[l315] = 0.0;
		}
		for (int l316 = 0; l316 < 2; l316 = l316 + 1) {
			fRec454[l316] = 0.0;
		}
		for (int l317 = 0; l317 < 2; l317 = l317 + 1) {
			fRec455[l317] = 0.0;
		}
		for (int l318 = 0; l318 < 2; l318 = l318 + 1) {
			fRec350[l318] = 0.0;
		}
		for (int l319 = 0; l319 < 2; l319 = l319 + 1) {
			fRec347[l319] = 0.0;
		}
		for (int l320 = 0; l320 < 2; l320 = l320 + 1) {
			fRec461[l320] = 0.0;
		}
		for (int l321 = 0; l321 < 2; l321 = l321 + 1) {
			fVec9[l321] = 0.0;
		}
		for (int l322 = 0; l322 < 2; l322 = l322 + 1) {
			fRec460[l322] = 0.0;
		}
		for (int l323 = 0; l323 < 2; l323 = l323 + 1) {
			fRec459[l323] = 0.0;
		}
		for (int l324 = 0; l324 < 2; l324 = l324 + 1) {
			fRec458[l324] = 0.0;
		}
		for (int l325 = 0; l325 < 2; l325 = l325 + 1) {
			fRec462[l325] = 0.0;
		}
		for (int l326 = 0; l326 < 2; l326 = l326 + 1) {
			fRec463[l326] = 0.0;
		}
		for (int l327 = 0; l327 < 2; l327 = l327 + 1) {
			fRec465[l327] = 0.0;
		}
		for (int l328 = 0; l328 < 2; l328 = l328 + 1) {
			fRec466[l328] = 0.0;
		}
		for (int l329 = 0; l329 < 2; l329 = l329 + 1) {
			fRec468[l329] = 0.0;
		}
		for (int l330 = 0; l330 < 2; l330 = l330 + 1) {
			fRec469[l330] = 0.0;
		}
		for (int l331 = 0; l331 < 2; l331 = l331 + 1) {
			fRec471[l331] = 0.0;
		}
		for (int l332 = 0; l332 < 2; l332 = l332 + 1) {
			fRec472[l332] = 0.0;
		}
		for (int l333 = 0; l333 < 2; l333 = l333 + 1) {
			fRec474[l333] = 0.0;
		}
		for (int l334 = 0; l334 < 2; l334 = l334 + 1) {
			fRec475[l334] = 0.0;
		}
		for (int l335 = 0; l335 < 2; l335 = l335 + 1) {
			fRec477[l335] = 0.0;
		}
		for (int l336 = 0; l336 < 2; l336 = l336 + 1) {
			fRec478[l336] = 0.0;
		}
		for (int l337 = 0; l337 < 2; l337 = l337 + 1) {
			fRec480[l337] = 0.0;
		}
		for (int l338 = 0; l338 < 2; l338 = l338 + 1) {
			fRec481[l338] = 0.0;
		}
		for (int l339 = 0; l339 < 2; l339 = l339 + 1) {
			fRec483[l339] = 0.0;
		}
		for (int l340 = 0; l340 < 2; l340 = l340 + 1) {
			fRec484[l340] = 0.0;
		}
		for (int l341 = 0; l341 < 2; l341 = l341 + 1) {
			fRec486[l341] = 0.0;
		}
		for (int l342 = 0; l342 < 2; l342 = l342 + 1) {
			fRec487[l342] = 0.0;
		}
		for (int l343 = 0; l343 < 2; l343 = l343 + 1) {
			fRec489[l343] = 0.0;
		}
		for (int l344 = 0; l344 < 2; l344 = l344 + 1) {
			fRec490[l344] = 0.0;
		}
		for (int l345 = 0; l345 < 2; l345 = l345 + 1) {
			fRec492[l345] = 0.0;
		}
		for (int l346 = 0; l346 < 2; l346 = l346 + 1) {
			fRec493[l346] = 0.0;
		}
		for (int l347 = 0; l347 < 2; l347 = l347 + 1) {
			fRec495[l347] = 0.0;
		}
		for (int l348 = 0; l348 < 2; l348 = l348 + 1) {
			fRec496[l348] = 0.0;
		}
		for (int l349 = 0; l349 < 2; l349 = l349 + 1) {
			fRec498[l349] = 0.0;
		}
		for (int l350 = 0; l350 < 2; l350 = l350 + 1) {
			fRec499[l350] = 0.0;
		}
		for (int l351 = 0; l351 < 2; l351 = l351 + 1) {
			fRec501[l351] = 0.0;
		}
		for (int l352 = 0; l352 < 2; l352 = l352 + 1) {
			fRec502[l352] = 0.0;
		}
		for (int l353 = 0; l353 < 2; l353 = l353 + 1) {
			fRec504[l353] = 0.0;
		}
		for (int l354 = 0; l354 < 2; l354 = l354 + 1) {
			fRec505[l354] = 0.0;
		}
		for (int l355 = 0; l355 < 2; l355 = l355 + 1) {
			fRec507[l355] = 0.0;
		}
		for (int l356 = 0; l356 < 2; l356 = l356 + 1) {
			fRec508[l356] = 0.0;
		}
		for (int l357 = 0; l357 < 2; l357 = l357 + 1) {
			fRec510[l357] = 0.0;
		}
		for (int l358 = 0; l358 < 2; l358 = l358 + 1) {
			fRec511[l358] = 0.0;
		}
		for (int l359 = 0; l359 < 2; l359 = l359 + 1) {
			fRec513[l359] = 0.0;
		}
		for (int l360 = 0; l360 < 2; l360 = l360 + 1) {
			fRec514[l360] = 0.0;
		}
		for (int l361 = 0; l361 < 2; l361 = l361 + 1) {
			fRec516[l361] = 0.0;
		}
		for (int l362 = 0; l362 < 2; l362 = l362 + 1) {
			fRec517[l362] = 0.0;
		}
		for (int l363 = 0; l363 < 2; l363 = l363 + 1) {
			fRec519[l363] = 0.0;
		}
		for (int l364 = 0; l364 < 2; l364 = l364 + 1) {
			fRec520[l364] = 0.0;
		}
		for (int l365 = 0; l365 < 2; l365 = l365 + 1) {
			fRec522[l365] = 0.0;
		}
		for (int l366 = 0; l366 < 2; l366 = l366 + 1) {
			fRec523[l366] = 0.0;
		}
		for (int l367 = 0; l367 < 2; l367 = l367 + 1) {
			fRec525[l367] = 0.0;
		}
		for (int l368 = 0; l368 < 2; l368 = l368 + 1) {
			fRec526[l368] = 0.0;
		}
		for (int l369 = 0; l369 < 2; l369 = l369 + 1) {
			fRec528[l369] = 0.0;
		}
		for (int l370 = 0; l370 < 2; l370 = l370 + 1) {
			fRec529[l370] = 0.0;
		}
		for (int l371 = 0; l371 < 2; l371 = l371 + 1) {
			fRec531[l371] = 0.0;
		}
		for (int l372 = 0; l372 < 2; l372 = l372 + 1) {
			fRec532[l372] = 0.0;
		}
		for (int l373 = 0; l373 < 2; l373 = l373 + 1) {
			fRec534[l373] = 0.0;
		}
		for (int l374 = 0; l374 < 2; l374 = l374 + 1) {
			fRec535[l374] = 0.0;
		}
		for (int l375 = 0; l375 < 2; l375 = l375 + 1) {
			fRec537[l375] = 0.0;
		}
		for (int l376 = 0; l376 < 2; l376 = l376 + 1) {
			fRec538[l376] = 0.0;
		}
		for (int l377 = 0; l377 < 2; l377 = l377 + 1) {
			fRec540[l377] = 0.0;
		}
		for (int l378 = 0; l378 < 2; l378 = l378 + 1) {
			fRec541[l378] = 0.0;
		}
		for (int l379 = 0; l379 < 2; l379 = l379 + 1) {
			fRec543[l379] = 0.0;
		}
		for (int l380 = 0; l380 < 2; l380 = l380 + 1) {
			fRec544[l380] = 0.0;
		}
		for (int l381 = 0; l381 < 2; l381 = l381 + 1) {
			fRec546[l381] = 0.0;
		}
		for (int l382 = 0; l382 < 2; l382 = l382 + 1) {
			fRec547[l382] = 0.0;
		}
		for (int l383 = 0; l383 < 2; l383 = l383 + 1) {
			fRec549[l383] = 0.0;
		}
		for (int l384 = 0; l384 < 2; l384 = l384 + 1) {
			fRec550[l384] = 0.0;
		}
		for (int l385 = 0; l385 < 2; l385 = l385 + 1) {
			fRec552[l385] = 0.0;
		}
		for (int l386 = 0; l386 < 2; l386 = l386 + 1) {
			fRec553[l386] = 0.0;
		}
		for (int l387 = 0; l387 < 2; l387 = l387 + 1) {
			fRec555[l387] = 0.0;
		}
		for (int l388 = 0; l388 < 2; l388 = l388 + 1) {
			fRec556[l388] = 0.0;
		}
		for (int l389 = 0; l389 < 2; l389 = l389 + 1) {
			fRec457[l389] = 0.0;
		}
		for (int l390 = 0; l390 < 2; l390 = l390 + 1) {
			fRec348[l390] = 0.0;
		}
		for (int l391 = 0; l391 < 2; l391 = l391 + 1) {
			fVec10[l391] = 0.0;
		}
		for (int l392 = 0; l392 < 2; l392 = l392 + 1) {
			fRec561[l392] = 0.0;
		}
		for (int l393 = 0; l393 < 2; l393 = l393 + 1) {
			fRec560[l393] = 0.0;
		}
		for (int l394 = 0; l394 < 2; l394 = l394 + 1) {
			fRec559[l394] = 0.0;
		}
		for (int l395 = 0; l395 < 2; l395 = l395 + 1) {
			fRec562[l395] = 0.0;
		}
		for (int l396 = 0; l396 < 2; l396 = l396 + 1) {
			fRec563[l396] = 0.0;
		}
		for (int l397 = 0; l397 < 2; l397 = l397 + 1) {
			fRec565[l397] = 0.0;
		}
		for (int l398 = 0; l398 < 2; l398 = l398 + 1) {
			fRec566[l398] = 0.0;
		}
		for (int l399 = 0; l399 < 2; l399 = l399 + 1) {
			fRec568[l399] = 0.0;
		}
		for (int l400 = 0; l400 < 2; l400 = l400 + 1) {
			fRec569[l400] = 0.0;
		}
		for (int l401 = 0; l401 < 2; l401 = l401 + 1) {
			fRec571[l401] = 0.0;
		}
		for (int l402 = 0; l402 < 2; l402 = l402 + 1) {
			fRec572[l402] = 0.0;
		}
		for (int l403 = 0; l403 < 2; l403 = l403 + 1) {
			fRec574[l403] = 0.0;
		}
		for (int l404 = 0; l404 < 2; l404 = l404 + 1) {
			fRec575[l404] = 0.0;
		}
		for (int l405 = 0; l405 < 2; l405 = l405 + 1) {
			fRec577[l405] = 0.0;
		}
		for (int l406 = 0; l406 < 2; l406 = l406 + 1) {
			fRec578[l406] = 0.0;
		}
		for (int l407 = 0; l407 < 2; l407 = l407 + 1) {
			fRec580[l407] = 0.0;
		}
		for (int l408 = 0; l408 < 2; l408 = l408 + 1) {
			fRec581[l408] = 0.0;
		}
		for (int l409 = 0; l409 < 2; l409 = l409 + 1) {
			fRec583[l409] = 0.0;
		}
		for (int l410 = 0; l410 < 2; l410 = l410 + 1) {
			fRec584[l410] = 0.0;
		}
		for (int l411 = 0; l411 < 2; l411 = l411 + 1) {
			fRec586[l411] = 0.0;
		}
		for (int l412 = 0; l412 < 2; l412 = l412 + 1) {
			fRec587[l412] = 0.0;
		}
		for (int l413 = 0; l413 < 2; l413 = l413 + 1) {
			fRec589[l413] = 0.0;
		}
		for (int l414 = 0; l414 < 2; l414 = l414 + 1) {
			fRec590[l414] = 0.0;
		}
		for (int l415 = 0; l415 < 2; l415 = l415 + 1) {
			fRec592[l415] = 0.0;
		}
		for (int l416 = 0; l416 < 2; l416 = l416 + 1) {
			fRec593[l416] = 0.0;
		}
		for (int l417 = 0; l417 < 2; l417 = l417 + 1) {
			fRec595[l417] = 0.0;
		}
		for (int l418 = 0; l418 < 2; l418 = l418 + 1) {
			fRec596[l418] = 0.0;
		}
		for (int l419 = 0; l419 < 2; l419 = l419 + 1) {
			fRec598[l419] = 0.0;
		}
		for (int l420 = 0; l420 < 2; l420 = l420 + 1) {
			fRec599[l420] = 0.0;
		}
		for (int l421 = 0; l421 < 2; l421 = l421 + 1) {
			fRec601[l421] = 0.0;
		}
		for (int l422 = 0; l422 < 2; l422 = l422 + 1) {
			fRec602[l422] = 0.0;
		}
		for (int l423 = 0; l423 < 2; l423 = l423 + 1) {
			fRec604[l423] = 0.0;
		}
		for (int l424 = 0; l424 < 2; l424 = l424 + 1) {
			fRec605[l424] = 0.0;
		}
		for (int l425 = 0; l425 < 2; l425 = l425 + 1) {
			fRec607[l425] = 0.0;
		}
		for (int l426 = 0; l426 < 2; l426 = l426 + 1) {
			fRec608[l426] = 0.0;
		}
		for (int l427 = 0; l427 < 2; l427 = l427 + 1) {
			fRec610[l427] = 0.0;
		}
		for (int l428 = 0; l428 < 2; l428 = l428 + 1) {
			fRec611[l428] = 0.0;
		}
		for (int l429 = 0; l429 < 2; l429 = l429 + 1) {
			fRec613[l429] = 0.0;
		}
		for (int l430 = 0; l430 < 2; l430 = l430 + 1) {
			fRec614[l430] = 0.0;
		}
		for (int l431 = 0; l431 < 2; l431 = l431 + 1) {
			fRec616[l431] = 0.0;
		}
		for (int l432 = 0; l432 < 2; l432 = l432 + 1) {
			fRec617[l432] = 0.0;
		}
		for (int l433 = 0; l433 < 2; l433 = l433 + 1) {
			fRec619[l433] = 0.0;
		}
		for (int l434 = 0; l434 < 2; l434 = l434 + 1) {
			fRec620[l434] = 0.0;
		}
		for (int l435 = 0; l435 < 2; l435 = l435 + 1) {
			fRec622[l435] = 0.0;
		}
		for (int l436 = 0; l436 < 2; l436 = l436 + 1) {
			fRec623[l436] = 0.0;
		}
		for (int l437 = 0; l437 < 2; l437 = l437 + 1) {
			fRec625[l437] = 0.0;
		}
		for (int l438 = 0; l438 < 2; l438 = l438 + 1) {
			fRec626[l438] = 0.0;
		}
		for (int l439 = 0; l439 < 2; l439 = l439 + 1) {
			fRec628[l439] = 0.0;
		}
		for (int l440 = 0; l440 < 2; l440 = l440 + 1) {
			fRec629[l440] = 0.0;
		}
		for (int l441 = 0; l441 < 2; l441 = l441 + 1) {
			fRec631[l441] = 0.0;
		}
		for (int l442 = 0; l442 < 2; l442 = l442 + 1) {
			fRec632[l442] = 0.0;
		}
		for (int l443 = 0; l443 < 2; l443 = l443 + 1) {
			fRec634[l443] = 0.0;
		}
		for (int l444 = 0; l444 < 2; l444 = l444 + 1) {
			fRec635[l444] = 0.0;
		}
		for (int l445 = 0; l445 < 2; l445 = l445 + 1) {
			fRec637[l445] = 0.0;
		}
		for (int l446 = 0; l446 < 2; l446 = l446 + 1) {
			fRec638[l446] = 0.0;
		}
		for (int l447 = 0; l447 < 2; l447 = l447 + 1) {
			fRec640[l447] = 0.0;
		}
		for (int l448 = 0; l448 < 2; l448 = l448 + 1) {
			fRec641[l448] = 0.0;
		}
		for (int l449 = 0; l449 < 2; l449 = l449 + 1) {
			fRec643[l449] = 0.0;
		}
		for (int l450 = 0; l450 < 2; l450 = l450 + 1) {
			fRec644[l450] = 0.0;
		}
		for (int l451 = 0; l451 < 2; l451 = l451 + 1) {
			fRec646[l451] = 0.0;
		}
		for (int l452 = 0; l452 < 2; l452 = l452 + 1) {
			fRec647[l452] = 0.0;
		}
		for (int l453 = 0; l453 < 2; l453 = l453 + 1) {
			fRec649[l453] = 0.0;
		}
		for (int l454 = 0; l454 < 2; l454 = l454 + 1) {
			fRec650[l454] = 0.0;
		}
		for (int l455 = 0; l455 < 2; l455 = l455 + 1) {
			fRec652[l455] = 0.0;
		}
		for (int l456 = 0; l456 < 2; l456 = l456 + 1) {
			fRec653[l456] = 0.0;
		}
		for (int l457 = 0; l457 < 2; l457 = l457 + 1) {
			fRec655[l457] = 0.0;
		}
		for (int l458 = 0; l458 < 2; l458 = l458 + 1) {
			fRec656[l458] = 0.0;
		}
		for (int l459 = 0; l459 < 2; l459 = l459 + 1) {
			fRec558[l459] = 0.0;
		}
		for (int l460 = 0; l460 < 2; l460 = l460 + 1) {
			fRec349[l460] = 0.0;
		}
		for (int l461 = 0; l461 < 4194304; l461 = l461 + 1) {
			fVec11[l461] = 0.0;
		}
		for (int l462 = 0; l462 < 2; l462 = l462 + 1) {
			fRec658[l462] = 0.0;
		}
		for (int l463 = 0; l463 < 2; l463 = l463 + 1) {
			fRec659[l463] = 0.0;
		}
		for (int l464 = 0; l464 < 2; l464 = l464 + 1) {
			fRec660[l464] = 0.0;
		}
		for (int l465 = 0; l465 < 2; l465 = l465 + 1) {
			fRec661[l465] = 0.0;
		}
		for (int l466 = 0; l466 < 2; l466 = l466 + 1) {
			fRec346[l466] = 0.0;
		}
		for (int l467 = 0; l467 < 2; l467 = l467 + 1) {
			fRec674[l467] = 0.0;
		}
		for (int l468 = 0; l468 < 2; l468 = l468 + 1) {
			fRec675[l468] = 0.0;
		}
		for (int l469 = 0; l469 < 2; l469 = l469 + 1) {
			fRec676[l469] = 0.0;
		}
		for (int l470 = 0; l470 < 2; l470 = l470 + 1) {
			fRec677[l470] = 0.0;
		}
		for (int l471 = 0; l471 < 2; l471 = l471 + 1) {
			fRec673[l471] = 0.0;
		}
		for (int l472 = 0; l472 < 2; l472 = l472 + 1) {
			fRec678[l472] = 0.0;
		}
		for (int l473 = 0; l473 < 2; l473 = l473 + 1) {
			fRec679[l473] = 0.0;
		}
		for (int l474 = 0; l474 < 2; l474 = l474 + 1) {
			fVec12[l474] = 0.0;
		}
		for (int l475 = 0; l475 < 2; l475 = l475 + 1) {
			fRec672[l475] = 0.0;
		}
		for (int l476 = 0; l476 < 2; l476 = l476 + 1) {
			fRec671[l476] = 0.0;
		}
		for (int l477 = 0; l477 < 2; l477 = l477 + 1) {
			fRec670[l477] = 0.0;
		}
		for (int l478 = 0; l478 < 2; l478 = l478 + 1) {
			fRec667[l478] = 0.0;
		}
		for (int l479 = 0; l479 < 2; l479 = l479 + 1) {
			fRec668[l479] = 0.0;
		}
		for (int l480 = 0; l480 < 2; l480 = l480 + 1) {
			fRec680[l480] = 0.0;
		}
		for (int l481 = 0; l481 < 2; l481 = l481 + 1) {
			fRec681[l481] = 0.0;
		}
		for (int l482 = 0; l482 < 2; l482 = l482 + 1) {
			fRec683[l482] = 0.0;
		}
		for (int l483 = 0; l483 < 2; l483 = l483 + 1) {
			fRec684[l483] = 0.0;
		}
		for (int l484 = 0; l484 < 2; l484 = l484 + 1) {
			fRec686[l484] = 0.0;
		}
		for (int l485 = 0; l485 < 2; l485 = l485 + 1) {
			fRec687[l485] = 0.0;
		}
		for (int l486 = 0; l486 < 2; l486 = l486 + 1) {
			fRec689[l486] = 0.0;
		}
		for (int l487 = 0; l487 < 2; l487 = l487 + 1) {
			fRec690[l487] = 0.0;
		}
		for (int l488 = 0; l488 < 2; l488 = l488 + 1) {
			fRec692[l488] = 0.0;
		}
		for (int l489 = 0; l489 < 2; l489 = l489 + 1) {
			fRec693[l489] = 0.0;
		}
		for (int l490 = 0; l490 < 2; l490 = l490 + 1) {
			fRec695[l490] = 0.0;
		}
		for (int l491 = 0; l491 < 2; l491 = l491 + 1) {
			fRec696[l491] = 0.0;
		}
		for (int l492 = 0; l492 < 2; l492 = l492 + 1) {
			fRec698[l492] = 0.0;
		}
		for (int l493 = 0; l493 < 2; l493 = l493 + 1) {
			fRec699[l493] = 0.0;
		}
		for (int l494 = 0; l494 < 2; l494 = l494 + 1) {
			fRec701[l494] = 0.0;
		}
		for (int l495 = 0; l495 < 2; l495 = l495 + 1) {
			fRec702[l495] = 0.0;
		}
		for (int l496 = 0; l496 < 2; l496 = l496 + 1) {
			fRec704[l496] = 0.0;
		}
		for (int l497 = 0; l497 < 2; l497 = l497 + 1) {
			fRec705[l497] = 0.0;
		}
		for (int l498 = 0; l498 < 2; l498 = l498 + 1) {
			fRec707[l498] = 0.0;
		}
		for (int l499 = 0; l499 < 2; l499 = l499 + 1) {
			fRec708[l499] = 0.0;
		}
		for (int l500 = 0; l500 < 2; l500 = l500 + 1) {
			fRec710[l500] = 0.0;
		}
		for (int l501 = 0; l501 < 2; l501 = l501 + 1) {
			fRec711[l501] = 0.0;
		}
		for (int l502 = 0; l502 < 2; l502 = l502 + 1) {
			fRec713[l502] = 0.0;
		}
		for (int l503 = 0; l503 < 2; l503 = l503 + 1) {
			fRec714[l503] = 0.0;
		}
		for (int l504 = 0; l504 < 2; l504 = l504 + 1) {
			fRec716[l504] = 0.0;
		}
		for (int l505 = 0; l505 < 2; l505 = l505 + 1) {
			fRec717[l505] = 0.0;
		}
		for (int l506 = 0; l506 < 2; l506 = l506 + 1) {
			fRec719[l506] = 0.0;
		}
		for (int l507 = 0; l507 < 2; l507 = l507 + 1) {
			fRec720[l507] = 0.0;
		}
		for (int l508 = 0; l508 < 2; l508 = l508 + 1) {
			fRec722[l508] = 0.0;
		}
		for (int l509 = 0; l509 < 2; l509 = l509 + 1) {
			fRec723[l509] = 0.0;
		}
		for (int l510 = 0; l510 < 2; l510 = l510 + 1) {
			fRec725[l510] = 0.0;
		}
		for (int l511 = 0; l511 < 2; l511 = l511 + 1) {
			fRec726[l511] = 0.0;
		}
		for (int l512 = 0; l512 < 2; l512 = l512 + 1) {
			fRec728[l512] = 0.0;
		}
		for (int l513 = 0; l513 < 2; l513 = l513 + 1) {
			fRec729[l513] = 0.0;
		}
		for (int l514 = 0; l514 < 2; l514 = l514 + 1) {
			fRec731[l514] = 0.0;
		}
		for (int l515 = 0; l515 < 2; l515 = l515 + 1) {
			fRec732[l515] = 0.0;
		}
		for (int l516 = 0; l516 < 2; l516 = l516 + 1) {
			fRec734[l516] = 0.0;
		}
		for (int l517 = 0; l517 < 2; l517 = l517 + 1) {
			fRec735[l517] = 0.0;
		}
		for (int l518 = 0; l518 < 2; l518 = l518 + 1) {
			fRec737[l518] = 0.0;
		}
		for (int l519 = 0; l519 < 2; l519 = l519 + 1) {
			fRec738[l519] = 0.0;
		}
		for (int l520 = 0; l520 < 2; l520 = l520 + 1) {
			fRec740[l520] = 0.0;
		}
		for (int l521 = 0; l521 < 2; l521 = l521 + 1) {
			fRec741[l521] = 0.0;
		}
		for (int l522 = 0; l522 < 2; l522 = l522 + 1) {
			fRec743[l522] = 0.0;
		}
		for (int l523 = 0; l523 < 2; l523 = l523 + 1) {
			fRec744[l523] = 0.0;
		}
		for (int l524 = 0; l524 < 2; l524 = l524 + 1) {
			fRec746[l524] = 0.0;
		}
		for (int l525 = 0; l525 < 2; l525 = l525 + 1) {
			fRec747[l525] = 0.0;
		}
		for (int l526 = 0; l526 < 2; l526 = l526 + 1) {
			fRec749[l526] = 0.0;
		}
		for (int l527 = 0; l527 < 2; l527 = l527 + 1) {
			fRec750[l527] = 0.0;
		}
		for (int l528 = 0; l528 < 2; l528 = l528 + 1) {
			fRec752[l528] = 0.0;
		}
		for (int l529 = 0; l529 < 2; l529 = l529 + 1) {
			fRec753[l529] = 0.0;
		}
		for (int l530 = 0; l530 < 2; l530 = l530 + 1) {
			fRec755[l530] = 0.0;
		}
		for (int l531 = 0; l531 < 2; l531 = l531 + 1) {
			fRec756[l531] = 0.0;
		}
		for (int l532 = 0; l532 < 2; l532 = l532 + 1) {
			fRec758[l532] = 0.0;
		}
		for (int l533 = 0; l533 < 2; l533 = l533 + 1) {
			fRec759[l533] = 0.0;
		}
		for (int l534 = 0; l534 < 2; l534 = l534 + 1) {
			fRec761[l534] = 0.0;
		}
		for (int l535 = 0; l535 < 2; l535 = l535 + 1) {
			fRec762[l535] = 0.0;
		}
		for (int l536 = 0; l536 < 2; l536 = l536 + 1) {
			fRec764[l536] = 0.0;
		}
		for (int l537 = 0; l537 < 2; l537 = l537 + 1) {
			fRec765[l537] = 0.0;
		}
		for (int l538 = 0; l538 < 2; l538 = l538 + 1) {
			fRec767[l538] = 0.0;
		}
		for (int l539 = 0; l539 < 2; l539 = l539 + 1) {
			fRec768[l539] = 0.0;
		}
		for (int l540 = 0; l540 < 2; l540 = l540 + 1) {
			fRec770[l540] = 0.0;
		}
		for (int l541 = 0; l541 < 2; l541 = l541 + 1) {
			fRec771[l541] = 0.0;
		}
		for (int l542 = 0; l542 < 2; l542 = l542 + 1) {
			fRec666[l542] = 0.0;
		}
		for (int l543 = 0; l543 < 2; l543 = l543 + 1) {
			fRec663[l543] = 0.0;
		}
		for (int l544 = 0; l544 < 2; l544 = l544 + 1) {
			fRec777[l544] = 0.0;
		}
		for (int l545 = 0; l545 < 2; l545 = l545 + 1) {
			fVec13[l545] = 0.0;
		}
		for (int l546 = 0; l546 < 2; l546 = l546 + 1) {
			fRec776[l546] = 0.0;
		}
		for (int l547 = 0; l547 < 2; l547 = l547 + 1) {
			fRec775[l547] = 0.0;
		}
		for (int l548 = 0; l548 < 2; l548 = l548 + 1) {
			fRec774[l548] = 0.0;
		}
		for (int l549 = 0; l549 < 2; l549 = l549 + 1) {
			fRec778[l549] = 0.0;
		}
		for (int l550 = 0; l550 < 2; l550 = l550 + 1) {
			fRec779[l550] = 0.0;
		}
		for (int l551 = 0; l551 < 2; l551 = l551 + 1) {
			fRec781[l551] = 0.0;
		}
		for (int l552 = 0; l552 < 2; l552 = l552 + 1) {
			fRec782[l552] = 0.0;
		}
		for (int l553 = 0; l553 < 2; l553 = l553 + 1) {
			fRec784[l553] = 0.0;
		}
		for (int l554 = 0; l554 < 2; l554 = l554 + 1) {
			fRec785[l554] = 0.0;
		}
		for (int l555 = 0; l555 < 2; l555 = l555 + 1) {
			fRec787[l555] = 0.0;
		}
		for (int l556 = 0; l556 < 2; l556 = l556 + 1) {
			fRec788[l556] = 0.0;
		}
		for (int l557 = 0; l557 < 2; l557 = l557 + 1) {
			fRec790[l557] = 0.0;
		}
		for (int l558 = 0; l558 < 2; l558 = l558 + 1) {
			fRec791[l558] = 0.0;
		}
		for (int l559 = 0; l559 < 2; l559 = l559 + 1) {
			fRec793[l559] = 0.0;
		}
		for (int l560 = 0; l560 < 2; l560 = l560 + 1) {
			fRec794[l560] = 0.0;
		}
		for (int l561 = 0; l561 < 2; l561 = l561 + 1) {
			fRec796[l561] = 0.0;
		}
		for (int l562 = 0; l562 < 2; l562 = l562 + 1) {
			fRec797[l562] = 0.0;
		}
		for (int l563 = 0; l563 < 2; l563 = l563 + 1) {
			fRec799[l563] = 0.0;
		}
		for (int l564 = 0; l564 < 2; l564 = l564 + 1) {
			fRec800[l564] = 0.0;
		}
		for (int l565 = 0; l565 < 2; l565 = l565 + 1) {
			fRec802[l565] = 0.0;
		}
		for (int l566 = 0; l566 < 2; l566 = l566 + 1) {
			fRec803[l566] = 0.0;
		}
		for (int l567 = 0; l567 < 2; l567 = l567 + 1) {
			fRec805[l567] = 0.0;
		}
		for (int l568 = 0; l568 < 2; l568 = l568 + 1) {
			fRec806[l568] = 0.0;
		}
		for (int l569 = 0; l569 < 2; l569 = l569 + 1) {
			fRec808[l569] = 0.0;
		}
		for (int l570 = 0; l570 < 2; l570 = l570 + 1) {
			fRec809[l570] = 0.0;
		}
		for (int l571 = 0; l571 < 2; l571 = l571 + 1) {
			fRec811[l571] = 0.0;
		}
		for (int l572 = 0; l572 < 2; l572 = l572 + 1) {
			fRec812[l572] = 0.0;
		}
		for (int l573 = 0; l573 < 2; l573 = l573 + 1) {
			fRec814[l573] = 0.0;
		}
		for (int l574 = 0; l574 < 2; l574 = l574 + 1) {
			fRec815[l574] = 0.0;
		}
		for (int l575 = 0; l575 < 2; l575 = l575 + 1) {
			fRec817[l575] = 0.0;
		}
		for (int l576 = 0; l576 < 2; l576 = l576 + 1) {
			fRec818[l576] = 0.0;
		}
		for (int l577 = 0; l577 < 2; l577 = l577 + 1) {
			fRec820[l577] = 0.0;
		}
		for (int l578 = 0; l578 < 2; l578 = l578 + 1) {
			fRec821[l578] = 0.0;
		}
		for (int l579 = 0; l579 < 2; l579 = l579 + 1) {
			fRec823[l579] = 0.0;
		}
		for (int l580 = 0; l580 < 2; l580 = l580 + 1) {
			fRec824[l580] = 0.0;
		}
		for (int l581 = 0; l581 < 2; l581 = l581 + 1) {
			fRec826[l581] = 0.0;
		}
		for (int l582 = 0; l582 < 2; l582 = l582 + 1) {
			fRec827[l582] = 0.0;
		}
		for (int l583 = 0; l583 < 2; l583 = l583 + 1) {
			fRec829[l583] = 0.0;
		}
		for (int l584 = 0; l584 < 2; l584 = l584 + 1) {
			fRec830[l584] = 0.0;
		}
		for (int l585 = 0; l585 < 2; l585 = l585 + 1) {
			fRec832[l585] = 0.0;
		}
		for (int l586 = 0; l586 < 2; l586 = l586 + 1) {
			fRec833[l586] = 0.0;
		}
		for (int l587 = 0; l587 < 2; l587 = l587 + 1) {
			fRec835[l587] = 0.0;
		}
		for (int l588 = 0; l588 < 2; l588 = l588 + 1) {
			fRec836[l588] = 0.0;
		}
		for (int l589 = 0; l589 < 2; l589 = l589 + 1) {
			fRec838[l589] = 0.0;
		}
		for (int l590 = 0; l590 < 2; l590 = l590 + 1) {
			fRec839[l590] = 0.0;
		}
		for (int l591 = 0; l591 < 2; l591 = l591 + 1) {
			fRec841[l591] = 0.0;
		}
		for (int l592 = 0; l592 < 2; l592 = l592 + 1) {
			fRec842[l592] = 0.0;
		}
		for (int l593 = 0; l593 < 2; l593 = l593 + 1) {
			fRec844[l593] = 0.0;
		}
		for (int l594 = 0; l594 < 2; l594 = l594 + 1) {
			fRec845[l594] = 0.0;
		}
		for (int l595 = 0; l595 < 2; l595 = l595 + 1) {
			fRec847[l595] = 0.0;
		}
		for (int l596 = 0; l596 < 2; l596 = l596 + 1) {
			fRec848[l596] = 0.0;
		}
		for (int l597 = 0; l597 < 2; l597 = l597 + 1) {
			fRec850[l597] = 0.0;
		}
		for (int l598 = 0; l598 < 2; l598 = l598 + 1) {
			fRec851[l598] = 0.0;
		}
		for (int l599 = 0; l599 < 2; l599 = l599 + 1) {
			fRec853[l599] = 0.0;
		}
		for (int l600 = 0; l600 < 2; l600 = l600 + 1) {
			fRec854[l600] = 0.0;
		}
		for (int l601 = 0; l601 < 2; l601 = l601 + 1) {
			fRec856[l601] = 0.0;
		}
		for (int l602 = 0; l602 < 2; l602 = l602 + 1) {
			fRec857[l602] = 0.0;
		}
		for (int l603 = 0; l603 < 2; l603 = l603 + 1) {
			fRec859[l603] = 0.0;
		}
		for (int l604 = 0; l604 < 2; l604 = l604 + 1) {
			fRec860[l604] = 0.0;
		}
		for (int l605 = 0; l605 < 2; l605 = l605 + 1) {
			fRec862[l605] = 0.0;
		}
		for (int l606 = 0; l606 < 2; l606 = l606 + 1) {
			fRec863[l606] = 0.0;
		}
		for (int l607 = 0; l607 < 2; l607 = l607 + 1) {
			fRec865[l607] = 0.0;
		}
		for (int l608 = 0; l608 < 2; l608 = l608 + 1) {
			fRec866[l608] = 0.0;
		}
		for (int l609 = 0; l609 < 2; l609 = l609 + 1) {
			fRec868[l609] = 0.0;
		}
		for (int l610 = 0; l610 < 2; l610 = l610 + 1) {
			fRec869[l610] = 0.0;
		}
		for (int l611 = 0; l611 < 2; l611 = l611 + 1) {
			fRec871[l611] = 0.0;
		}
		for (int l612 = 0; l612 < 2; l612 = l612 + 1) {
			fRec872[l612] = 0.0;
		}
		for (int l613 = 0; l613 < 2; l613 = l613 + 1) {
			fRec773[l613] = 0.0;
		}
		for (int l614 = 0; l614 < 2; l614 = l614 + 1) {
			fRec664[l614] = 0.0;
		}
		for (int l615 = 0; l615 < 2; l615 = l615 + 1) {
			fVec14[l615] = 0.0;
		}
		for (int l616 = 0; l616 < 2; l616 = l616 + 1) {
			fRec877[l616] = 0.0;
		}
		for (int l617 = 0; l617 < 2; l617 = l617 + 1) {
			fRec876[l617] = 0.0;
		}
		for (int l618 = 0; l618 < 2; l618 = l618 + 1) {
			fRec875[l618] = 0.0;
		}
		for (int l619 = 0; l619 < 2; l619 = l619 + 1) {
			fRec878[l619] = 0.0;
		}
		for (int l620 = 0; l620 < 2; l620 = l620 + 1) {
			fRec879[l620] = 0.0;
		}
		for (int l621 = 0; l621 < 2; l621 = l621 + 1) {
			fRec881[l621] = 0.0;
		}
		for (int l622 = 0; l622 < 2; l622 = l622 + 1) {
			fRec882[l622] = 0.0;
		}
		for (int l623 = 0; l623 < 2; l623 = l623 + 1) {
			fRec884[l623] = 0.0;
		}
		for (int l624 = 0; l624 < 2; l624 = l624 + 1) {
			fRec885[l624] = 0.0;
		}
		for (int l625 = 0; l625 < 2; l625 = l625 + 1) {
			fRec887[l625] = 0.0;
		}
		for (int l626 = 0; l626 < 2; l626 = l626 + 1) {
			fRec888[l626] = 0.0;
		}
		for (int l627 = 0; l627 < 2; l627 = l627 + 1) {
			fRec890[l627] = 0.0;
		}
		for (int l628 = 0; l628 < 2; l628 = l628 + 1) {
			fRec891[l628] = 0.0;
		}
		for (int l629 = 0; l629 < 2; l629 = l629 + 1) {
			fRec893[l629] = 0.0;
		}
		for (int l630 = 0; l630 < 2; l630 = l630 + 1) {
			fRec894[l630] = 0.0;
		}
		for (int l631 = 0; l631 < 2; l631 = l631 + 1) {
			fRec896[l631] = 0.0;
		}
		for (int l632 = 0; l632 < 2; l632 = l632 + 1) {
			fRec897[l632] = 0.0;
		}
		for (int l633 = 0; l633 < 2; l633 = l633 + 1) {
			fRec899[l633] = 0.0;
		}
		for (int l634 = 0; l634 < 2; l634 = l634 + 1) {
			fRec900[l634] = 0.0;
		}
		for (int l635 = 0; l635 < 2; l635 = l635 + 1) {
			fRec902[l635] = 0.0;
		}
		for (int l636 = 0; l636 < 2; l636 = l636 + 1) {
			fRec903[l636] = 0.0;
		}
		for (int l637 = 0; l637 < 2; l637 = l637 + 1) {
			fRec905[l637] = 0.0;
		}
		for (int l638 = 0; l638 < 2; l638 = l638 + 1) {
			fRec906[l638] = 0.0;
		}
		for (int l639 = 0; l639 < 2; l639 = l639 + 1) {
			fRec908[l639] = 0.0;
		}
		for (int l640 = 0; l640 < 2; l640 = l640 + 1) {
			fRec909[l640] = 0.0;
		}
		for (int l641 = 0; l641 < 2; l641 = l641 + 1) {
			fRec911[l641] = 0.0;
		}
		for (int l642 = 0; l642 < 2; l642 = l642 + 1) {
			fRec912[l642] = 0.0;
		}
		for (int l643 = 0; l643 < 2; l643 = l643 + 1) {
			fRec914[l643] = 0.0;
		}
		for (int l644 = 0; l644 < 2; l644 = l644 + 1) {
			fRec915[l644] = 0.0;
		}
		for (int l645 = 0; l645 < 2; l645 = l645 + 1) {
			fRec917[l645] = 0.0;
		}
		for (int l646 = 0; l646 < 2; l646 = l646 + 1) {
			fRec918[l646] = 0.0;
		}
		for (int l647 = 0; l647 < 2; l647 = l647 + 1) {
			fRec920[l647] = 0.0;
		}
		for (int l648 = 0; l648 < 2; l648 = l648 + 1) {
			fRec921[l648] = 0.0;
		}
		for (int l649 = 0; l649 < 2; l649 = l649 + 1) {
			fRec923[l649] = 0.0;
		}
		for (int l650 = 0; l650 < 2; l650 = l650 + 1) {
			fRec924[l650] = 0.0;
		}
		for (int l651 = 0; l651 < 2; l651 = l651 + 1) {
			fRec926[l651] = 0.0;
		}
		for (int l652 = 0; l652 < 2; l652 = l652 + 1) {
			fRec927[l652] = 0.0;
		}
		for (int l653 = 0; l653 < 2; l653 = l653 + 1) {
			fRec929[l653] = 0.0;
		}
		for (int l654 = 0; l654 < 2; l654 = l654 + 1) {
			fRec930[l654] = 0.0;
		}
		for (int l655 = 0; l655 < 2; l655 = l655 + 1) {
			fRec932[l655] = 0.0;
		}
		for (int l656 = 0; l656 < 2; l656 = l656 + 1) {
			fRec933[l656] = 0.0;
		}
		for (int l657 = 0; l657 < 2; l657 = l657 + 1) {
			fRec935[l657] = 0.0;
		}
		for (int l658 = 0; l658 < 2; l658 = l658 + 1) {
			fRec936[l658] = 0.0;
		}
		for (int l659 = 0; l659 < 2; l659 = l659 + 1) {
			fRec938[l659] = 0.0;
		}
		for (int l660 = 0; l660 < 2; l660 = l660 + 1) {
			fRec939[l660] = 0.0;
		}
		for (int l661 = 0; l661 < 2; l661 = l661 + 1) {
			fRec941[l661] = 0.0;
		}
		for (int l662 = 0; l662 < 2; l662 = l662 + 1) {
			fRec942[l662] = 0.0;
		}
		for (int l663 = 0; l663 < 2; l663 = l663 + 1) {
			fRec944[l663] = 0.0;
		}
		for (int l664 = 0; l664 < 2; l664 = l664 + 1) {
			fRec945[l664] = 0.0;
		}
		for (int l665 = 0; l665 < 2; l665 = l665 + 1) {
			fRec947[l665] = 0.0;
		}
		for (int l666 = 0; l666 < 2; l666 = l666 + 1) {
			fRec948[l666] = 0.0;
		}
		for (int l667 = 0; l667 < 2; l667 = l667 + 1) {
			fRec950[l667] = 0.0;
		}
		for (int l668 = 0; l668 < 2; l668 = l668 + 1) {
			fRec951[l668] = 0.0;
		}
		for (int l669 = 0; l669 < 2; l669 = l669 + 1) {
			fRec953[l669] = 0.0;
		}
		for (int l670 = 0; l670 < 2; l670 = l670 + 1) {
			fRec954[l670] = 0.0;
		}
		for (int l671 = 0; l671 < 2; l671 = l671 + 1) {
			fRec956[l671] = 0.0;
		}
		for (int l672 = 0; l672 < 2; l672 = l672 + 1) {
			fRec957[l672] = 0.0;
		}
		for (int l673 = 0; l673 < 2; l673 = l673 + 1) {
			fRec959[l673] = 0.0;
		}
		for (int l674 = 0; l674 < 2; l674 = l674 + 1) {
			fRec960[l674] = 0.0;
		}
		for (int l675 = 0; l675 < 2; l675 = l675 + 1) {
			fRec962[l675] = 0.0;
		}
		for (int l676 = 0; l676 < 2; l676 = l676 + 1) {
			fRec963[l676] = 0.0;
		}
		for (int l677 = 0; l677 < 2; l677 = l677 + 1) {
			fRec965[l677] = 0.0;
		}
		for (int l678 = 0; l678 < 2; l678 = l678 + 1) {
			fRec966[l678] = 0.0;
		}
		for (int l679 = 0; l679 < 2; l679 = l679 + 1) {
			fRec968[l679] = 0.0;
		}
		for (int l680 = 0; l680 < 2; l680 = l680 + 1) {
			fRec969[l680] = 0.0;
		}
		for (int l681 = 0; l681 < 2; l681 = l681 + 1) {
			fRec971[l681] = 0.0;
		}
		for (int l682 = 0; l682 < 2; l682 = l682 + 1) {
			fRec972[l682] = 0.0;
		}
		for (int l683 = 0; l683 < 2; l683 = l683 + 1) {
			fRec874[l683] = 0.0;
		}
		for (int l684 = 0; l684 < 2; l684 = l684 + 1) {
			fRec665[l684] = 0.0;
		}
		for (int l685 = 0; l685 < 4194304; l685 = l685 + 1) {
			fVec15[l685] = 0.0;
		}
		for (int l686 = 0; l686 < 2; l686 = l686 + 1) {
			fRec974[l686] = 0.0;
		}
		for (int l687 = 0; l687 < 2; l687 = l687 + 1) {
			fRec975[l687] = 0.0;
		}
		for (int l688 = 0; l688 < 2; l688 = l688 + 1) {
			fRec976[l688] = 0.0;
		}
		for (int l689 = 0; l689 < 2; l689 = l689 + 1) {
			fRec977[l689] = 0.0;
		}
		for (int l690 = 0; l690 < 2; l690 = l690 + 1) {
			fRec662[l690] = 0.0;
		}
		for (int l691 = 0; l691 < 2; l691 = l691 + 1) {
			fRec986[l691] = 0.0;
		}
		for (int l692 = 0; l692 < 2; l692 = l692 + 1) {
			fRec987[l692] = 0.0;
		}
		for (int l693 = 0; l693 < 2; l693 = l693 + 1) {
			fRec989[l693] = 0.0;
		}
		for (int l694 = 0; l694 < 2; l694 = l694 + 1) {
			fRec990[l694] = 0.0;
		}
		for (int l695 = 0; l695 < 2; l695 = l695 + 1) {
			fRec991[l695] = 0.0;
		}
		for (int l696 = 0; l696 < 2; l696 = l696 + 1) {
			fRec992[l696] = 0.0;
		}
		for (int l697 = 0; l697 < 2; l697 = l697 + 1) {
			fRec988[l697] = 0.0;
		}
		for (int l698 = 0; l698 < 2; l698 = l698 + 1) {
			fVec16[l698] = 0.0;
		}
		for (int l699 = 0; l699 < 2; l699 = l699 + 1) {
			fRec985[l699] = 0.0;
		}
		for (int l700 = 0; l700 < 2; l700 = l700 + 1) {
			fRec984[l700] = 0.0;
		}
		for (int l701 = 0; l701 < 2; l701 = l701 + 1) {
			fRec983[l701] = 0.0;
		}
		for (int l702 = 0; l702 < 2; l702 = l702 + 1) {
			fRec993[l702] = 0.0;
		}
		for (int l703 = 0; l703 < 2; l703 = l703 + 1) {
			fRec994[l703] = 0.0;
		}
		for (int l704 = 0; l704 < 2; l704 = l704 + 1) {
			fRec996[l704] = 0.0;
		}
		for (int l705 = 0; l705 < 2; l705 = l705 + 1) {
			fRec997[l705] = 0.0;
		}
		for (int l706 = 0; l706 < 2; l706 = l706 + 1) {
			fRec999[l706] = 0.0;
		}
		for (int l707 = 0; l707 < 2; l707 = l707 + 1) {
			fRec1000[l707] = 0.0;
		}
		for (int l708 = 0; l708 < 2; l708 = l708 + 1) {
			fRec1002[l708] = 0.0;
		}
		for (int l709 = 0; l709 < 2; l709 = l709 + 1) {
			fRec1003[l709] = 0.0;
		}
		for (int l710 = 0; l710 < 2; l710 = l710 + 1) {
			fRec1005[l710] = 0.0;
		}
		for (int l711 = 0; l711 < 2; l711 = l711 + 1) {
			fRec1006[l711] = 0.0;
		}
		for (int l712 = 0; l712 < 2; l712 = l712 + 1) {
			fRec1008[l712] = 0.0;
		}
		for (int l713 = 0; l713 < 2; l713 = l713 + 1) {
			fRec1009[l713] = 0.0;
		}
		for (int l714 = 0; l714 < 2; l714 = l714 + 1) {
			fRec1011[l714] = 0.0;
		}
		for (int l715 = 0; l715 < 2; l715 = l715 + 1) {
			fRec1012[l715] = 0.0;
		}
		for (int l716 = 0; l716 < 2; l716 = l716 + 1) {
			fRec1014[l716] = 0.0;
		}
		for (int l717 = 0; l717 < 2; l717 = l717 + 1) {
			fRec1015[l717] = 0.0;
		}
		for (int l718 = 0; l718 < 2; l718 = l718 + 1) {
			fRec1017[l718] = 0.0;
		}
		for (int l719 = 0; l719 < 2; l719 = l719 + 1) {
			fRec1018[l719] = 0.0;
		}
		for (int l720 = 0; l720 < 2; l720 = l720 + 1) {
			fRec1020[l720] = 0.0;
		}
		for (int l721 = 0; l721 < 2; l721 = l721 + 1) {
			fRec1021[l721] = 0.0;
		}
		for (int l722 = 0; l722 < 2; l722 = l722 + 1) {
			fRec1023[l722] = 0.0;
		}
		for (int l723 = 0; l723 < 2; l723 = l723 + 1) {
			fRec1024[l723] = 0.0;
		}
		for (int l724 = 0; l724 < 2; l724 = l724 + 1) {
			fRec1026[l724] = 0.0;
		}
		for (int l725 = 0; l725 < 2; l725 = l725 + 1) {
			fRec1027[l725] = 0.0;
		}
		for (int l726 = 0; l726 < 2; l726 = l726 + 1) {
			fRec1029[l726] = 0.0;
		}
		for (int l727 = 0; l727 < 2; l727 = l727 + 1) {
			fRec1030[l727] = 0.0;
		}
		for (int l728 = 0; l728 < 2; l728 = l728 + 1) {
			fRec1032[l728] = 0.0;
		}
		for (int l729 = 0; l729 < 2; l729 = l729 + 1) {
			fRec1033[l729] = 0.0;
		}
		for (int l730 = 0; l730 < 2; l730 = l730 + 1) {
			fRec1035[l730] = 0.0;
		}
		for (int l731 = 0; l731 < 2; l731 = l731 + 1) {
			fRec1036[l731] = 0.0;
		}
		for (int l732 = 0; l732 < 2; l732 = l732 + 1) {
			fRec1038[l732] = 0.0;
		}
		for (int l733 = 0; l733 < 2; l733 = l733 + 1) {
			fRec1039[l733] = 0.0;
		}
		for (int l734 = 0; l734 < 2; l734 = l734 + 1) {
			fRec1041[l734] = 0.0;
		}
		for (int l735 = 0; l735 < 2; l735 = l735 + 1) {
			fRec1042[l735] = 0.0;
		}
		for (int l736 = 0; l736 < 2; l736 = l736 + 1) {
			fRec1044[l736] = 0.0;
		}
		for (int l737 = 0; l737 < 2; l737 = l737 + 1) {
			fRec1045[l737] = 0.0;
		}
		for (int l738 = 0; l738 < 2; l738 = l738 + 1) {
			fRec1047[l738] = 0.0;
		}
		for (int l739 = 0; l739 < 2; l739 = l739 + 1) {
			fRec1048[l739] = 0.0;
		}
		for (int l740 = 0; l740 < 2; l740 = l740 + 1) {
			fRec1050[l740] = 0.0;
		}
		for (int l741 = 0; l741 < 2; l741 = l741 + 1) {
			fRec1051[l741] = 0.0;
		}
		for (int l742 = 0; l742 < 2; l742 = l742 + 1) {
			fRec1053[l742] = 0.0;
		}
		for (int l743 = 0; l743 < 2; l743 = l743 + 1) {
			fRec1054[l743] = 0.0;
		}
		for (int l744 = 0; l744 < 2; l744 = l744 + 1) {
			fRec1056[l744] = 0.0;
		}
		for (int l745 = 0; l745 < 2; l745 = l745 + 1) {
			fRec1057[l745] = 0.0;
		}
		for (int l746 = 0; l746 < 2; l746 = l746 + 1) {
			fRec1059[l746] = 0.0;
		}
		for (int l747 = 0; l747 < 2; l747 = l747 + 1) {
			fRec1060[l747] = 0.0;
		}
		for (int l748 = 0; l748 < 2; l748 = l748 + 1) {
			fRec1062[l748] = 0.0;
		}
		for (int l749 = 0; l749 < 2; l749 = l749 + 1) {
			fRec1063[l749] = 0.0;
		}
		for (int l750 = 0; l750 < 2; l750 = l750 + 1) {
			fRec1065[l750] = 0.0;
		}
		for (int l751 = 0; l751 < 2; l751 = l751 + 1) {
			fRec1066[l751] = 0.0;
		}
		for (int l752 = 0; l752 < 2; l752 = l752 + 1) {
			fRec1068[l752] = 0.0;
		}
		for (int l753 = 0; l753 < 2; l753 = l753 + 1) {
			fRec1069[l753] = 0.0;
		}
		for (int l754 = 0; l754 < 2; l754 = l754 + 1) {
			fRec1071[l754] = 0.0;
		}
		for (int l755 = 0; l755 < 2; l755 = l755 + 1) {
			fRec1072[l755] = 0.0;
		}
		for (int l756 = 0; l756 < 2; l756 = l756 + 1) {
			fRec1074[l756] = 0.0;
		}
		for (int l757 = 0; l757 < 2; l757 = l757 + 1) {
			fRec1075[l757] = 0.0;
		}
		for (int l758 = 0; l758 < 2; l758 = l758 + 1) {
			fRec1077[l758] = 0.0;
		}
		for (int l759 = 0; l759 < 2; l759 = l759 + 1) {
			fRec1078[l759] = 0.0;
		}
		for (int l760 = 0; l760 < 2; l760 = l760 + 1) {
			fRec1080[l760] = 0.0;
		}
		for (int l761 = 0; l761 < 2; l761 = l761 + 1) {
			fRec1081[l761] = 0.0;
		}
		for (int l762 = 0; l762 < 2; l762 = l762 + 1) {
			fRec1083[l762] = 0.0;
		}
		for (int l763 = 0; l763 < 2; l763 = l763 + 1) {
			fRec1084[l763] = 0.0;
		}
		for (int l764 = 0; l764 < 2; l764 = l764 + 1) {
			fRec1086[l764] = 0.0;
		}
		for (int l765 = 0; l765 < 2; l765 = l765 + 1) {
			fRec1087[l765] = 0.0;
		}
		for (int l766 = 0; l766 < 2; l766 = l766 + 1) {
			fRec982[l766] = 0.0;
		}
		for (int l767 = 0; l767 < 2; l767 = l767 + 1) {
			fRec979[l767] = 0.0;
		}
		for (int l768 = 0; l768 < 2; l768 = l768 + 1) {
			fRec1093[l768] = 0.0;
		}
		for (int l769 = 0; l769 < 2; l769 = l769 + 1) {
			fVec17[l769] = 0.0;
		}
		for (int l770 = 0; l770 < 2; l770 = l770 + 1) {
			fRec1092[l770] = 0.0;
		}
		for (int l771 = 0; l771 < 2; l771 = l771 + 1) {
			fRec1091[l771] = 0.0;
		}
		for (int l772 = 0; l772 < 2; l772 = l772 + 1) {
			fRec1090[l772] = 0.0;
		}
		for (int l773 = 0; l773 < 2; l773 = l773 + 1) {
			fRec1094[l773] = 0.0;
		}
		for (int l774 = 0; l774 < 2; l774 = l774 + 1) {
			fRec1095[l774] = 0.0;
		}
		for (int l775 = 0; l775 < 2; l775 = l775 + 1) {
			fRec1097[l775] = 0.0;
		}
		for (int l776 = 0; l776 < 2; l776 = l776 + 1) {
			fRec1098[l776] = 0.0;
		}
		for (int l777 = 0; l777 < 2; l777 = l777 + 1) {
			fRec1100[l777] = 0.0;
		}
		for (int l778 = 0; l778 < 2; l778 = l778 + 1) {
			fRec1101[l778] = 0.0;
		}
		for (int l779 = 0; l779 < 2; l779 = l779 + 1) {
			fRec1103[l779] = 0.0;
		}
		for (int l780 = 0; l780 < 2; l780 = l780 + 1) {
			fRec1104[l780] = 0.0;
		}
		for (int l781 = 0; l781 < 2; l781 = l781 + 1) {
			fRec1106[l781] = 0.0;
		}
		for (int l782 = 0; l782 < 2; l782 = l782 + 1) {
			fRec1107[l782] = 0.0;
		}
		for (int l783 = 0; l783 < 2; l783 = l783 + 1) {
			fRec1109[l783] = 0.0;
		}
		for (int l784 = 0; l784 < 2; l784 = l784 + 1) {
			fRec1110[l784] = 0.0;
		}
		for (int l785 = 0; l785 < 2; l785 = l785 + 1) {
			fRec1112[l785] = 0.0;
		}
		for (int l786 = 0; l786 < 2; l786 = l786 + 1) {
			fRec1113[l786] = 0.0;
		}
		for (int l787 = 0; l787 < 2; l787 = l787 + 1) {
			fRec1115[l787] = 0.0;
		}
		for (int l788 = 0; l788 < 2; l788 = l788 + 1) {
			fRec1116[l788] = 0.0;
		}
		for (int l789 = 0; l789 < 2; l789 = l789 + 1) {
			fRec1118[l789] = 0.0;
		}
		for (int l790 = 0; l790 < 2; l790 = l790 + 1) {
			fRec1119[l790] = 0.0;
		}
		for (int l791 = 0; l791 < 2; l791 = l791 + 1) {
			fRec1121[l791] = 0.0;
		}
		for (int l792 = 0; l792 < 2; l792 = l792 + 1) {
			fRec1122[l792] = 0.0;
		}
		for (int l793 = 0; l793 < 2; l793 = l793 + 1) {
			fRec1124[l793] = 0.0;
		}
		for (int l794 = 0; l794 < 2; l794 = l794 + 1) {
			fRec1125[l794] = 0.0;
		}
		for (int l795 = 0; l795 < 2; l795 = l795 + 1) {
			fRec1127[l795] = 0.0;
		}
		for (int l796 = 0; l796 < 2; l796 = l796 + 1) {
			fRec1128[l796] = 0.0;
		}
		for (int l797 = 0; l797 < 2; l797 = l797 + 1) {
			fRec1130[l797] = 0.0;
		}
		for (int l798 = 0; l798 < 2; l798 = l798 + 1) {
			fRec1131[l798] = 0.0;
		}
		for (int l799 = 0; l799 < 2; l799 = l799 + 1) {
			fRec1133[l799] = 0.0;
		}
		for (int l800 = 0; l800 < 2; l800 = l800 + 1) {
			fRec1134[l800] = 0.0;
		}
		for (int l801 = 0; l801 < 2; l801 = l801 + 1) {
			fRec1136[l801] = 0.0;
		}
		for (int l802 = 0; l802 < 2; l802 = l802 + 1) {
			fRec1137[l802] = 0.0;
		}
		for (int l803 = 0; l803 < 2; l803 = l803 + 1) {
			fRec1139[l803] = 0.0;
		}
		for (int l804 = 0; l804 < 2; l804 = l804 + 1) {
			fRec1140[l804] = 0.0;
		}
		for (int l805 = 0; l805 < 2; l805 = l805 + 1) {
			fRec1142[l805] = 0.0;
		}
		for (int l806 = 0; l806 < 2; l806 = l806 + 1) {
			fRec1143[l806] = 0.0;
		}
		for (int l807 = 0; l807 < 2; l807 = l807 + 1) {
			fRec1145[l807] = 0.0;
		}
		for (int l808 = 0; l808 < 2; l808 = l808 + 1) {
			fRec1146[l808] = 0.0;
		}
		for (int l809 = 0; l809 < 2; l809 = l809 + 1) {
			fRec1148[l809] = 0.0;
		}
		for (int l810 = 0; l810 < 2; l810 = l810 + 1) {
			fRec1149[l810] = 0.0;
		}
		for (int l811 = 0; l811 < 2; l811 = l811 + 1) {
			fRec1151[l811] = 0.0;
		}
		for (int l812 = 0; l812 < 2; l812 = l812 + 1) {
			fRec1152[l812] = 0.0;
		}
		for (int l813 = 0; l813 < 2; l813 = l813 + 1) {
			fRec1154[l813] = 0.0;
		}
		for (int l814 = 0; l814 < 2; l814 = l814 + 1) {
			fRec1155[l814] = 0.0;
		}
		for (int l815 = 0; l815 < 2; l815 = l815 + 1) {
			fRec1157[l815] = 0.0;
		}
		for (int l816 = 0; l816 < 2; l816 = l816 + 1) {
			fRec1158[l816] = 0.0;
		}
		for (int l817 = 0; l817 < 2; l817 = l817 + 1) {
			fRec1160[l817] = 0.0;
		}
		for (int l818 = 0; l818 < 2; l818 = l818 + 1) {
			fRec1161[l818] = 0.0;
		}
		for (int l819 = 0; l819 < 2; l819 = l819 + 1) {
			fRec1163[l819] = 0.0;
		}
		for (int l820 = 0; l820 < 2; l820 = l820 + 1) {
			fRec1164[l820] = 0.0;
		}
		for (int l821 = 0; l821 < 2; l821 = l821 + 1) {
			fRec1166[l821] = 0.0;
		}
		for (int l822 = 0; l822 < 2; l822 = l822 + 1) {
			fRec1167[l822] = 0.0;
		}
		for (int l823 = 0; l823 < 2; l823 = l823 + 1) {
			fRec1169[l823] = 0.0;
		}
		for (int l824 = 0; l824 < 2; l824 = l824 + 1) {
			fRec1170[l824] = 0.0;
		}
		for (int l825 = 0; l825 < 2; l825 = l825 + 1) {
			fRec1172[l825] = 0.0;
		}
		for (int l826 = 0; l826 < 2; l826 = l826 + 1) {
			fRec1173[l826] = 0.0;
		}
		for (int l827 = 0; l827 < 2; l827 = l827 + 1) {
			fRec1175[l827] = 0.0;
		}
		for (int l828 = 0; l828 < 2; l828 = l828 + 1) {
			fRec1176[l828] = 0.0;
		}
		for (int l829 = 0; l829 < 2; l829 = l829 + 1) {
			fRec1178[l829] = 0.0;
		}
		for (int l830 = 0; l830 < 2; l830 = l830 + 1) {
			fRec1179[l830] = 0.0;
		}
		for (int l831 = 0; l831 < 2; l831 = l831 + 1) {
			fRec1181[l831] = 0.0;
		}
		for (int l832 = 0; l832 < 2; l832 = l832 + 1) {
			fRec1182[l832] = 0.0;
		}
		for (int l833 = 0; l833 < 2; l833 = l833 + 1) {
			fRec1184[l833] = 0.0;
		}
		for (int l834 = 0; l834 < 2; l834 = l834 + 1) {
			fRec1185[l834] = 0.0;
		}
		for (int l835 = 0; l835 < 2; l835 = l835 + 1) {
			fRec1187[l835] = 0.0;
		}
		for (int l836 = 0; l836 < 2; l836 = l836 + 1) {
			fRec1188[l836] = 0.0;
		}
		for (int l837 = 0; l837 < 2; l837 = l837 + 1) {
			fRec1089[l837] = 0.0;
		}
		for (int l838 = 0; l838 < 2; l838 = l838 + 1) {
			fRec980[l838] = 0.0;
		}
		for (int l839 = 0; l839 < 2; l839 = l839 + 1) {
			fVec18[l839] = 0.0;
		}
		for (int l840 = 0; l840 < 2; l840 = l840 + 1) {
			fRec1193[l840] = 0.0;
		}
		for (int l841 = 0; l841 < 2; l841 = l841 + 1) {
			fRec1192[l841] = 0.0;
		}
		for (int l842 = 0; l842 < 2; l842 = l842 + 1) {
			fRec1191[l842] = 0.0;
		}
		for (int l843 = 0; l843 < 2; l843 = l843 + 1) {
			fRec1194[l843] = 0.0;
		}
		for (int l844 = 0; l844 < 2; l844 = l844 + 1) {
			fRec1195[l844] = 0.0;
		}
		for (int l845 = 0; l845 < 2; l845 = l845 + 1) {
			fRec1197[l845] = 0.0;
		}
		for (int l846 = 0; l846 < 2; l846 = l846 + 1) {
			fRec1198[l846] = 0.0;
		}
		for (int l847 = 0; l847 < 2; l847 = l847 + 1) {
			fRec1200[l847] = 0.0;
		}
		for (int l848 = 0; l848 < 2; l848 = l848 + 1) {
			fRec1201[l848] = 0.0;
		}
		for (int l849 = 0; l849 < 2; l849 = l849 + 1) {
			fRec1203[l849] = 0.0;
		}
		for (int l850 = 0; l850 < 2; l850 = l850 + 1) {
			fRec1204[l850] = 0.0;
		}
		for (int l851 = 0; l851 < 2; l851 = l851 + 1) {
			fRec1206[l851] = 0.0;
		}
		for (int l852 = 0; l852 < 2; l852 = l852 + 1) {
			fRec1207[l852] = 0.0;
		}
		for (int l853 = 0; l853 < 2; l853 = l853 + 1) {
			fRec1209[l853] = 0.0;
		}
		for (int l854 = 0; l854 < 2; l854 = l854 + 1) {
			fRec1210[l854] = 0.0;
		}
		for (int l855 = 0; l855 < 2; l855 = l855 + 1) {
			fRec1212[l855] = 0.0;
		}
		for (int l856 = 0; l856 < 2; l856 = l856 + 1) {
			fRec1213[l856] = 0.0;
		}
		for (int l857 = 0; l857 < 2; l857 = l857 + 1) {
			fRec1215[l857] = 0.0;
		}
		for (int l858 = 0; l858 < 2; l858 = l858 + 1) {
			fRec1216[l858] = 0.0;
		}
		for (int l859 = 0; l859 < 2; l859 = l859 + 1) {
			fRec1218[l859] = 0.0;
		}
		for (int l860 = 0; l860 < 2; l860 = l860 + 1) {
			fRec1219[l860] = 0.0;
		}
		for (int l861 = 0; l861 < 2; l861 = l861 + 1) {
			fRec1221[l861] = 0.0;
		}
		for (int l862 = 0; l862 < 2; l862 = l862 + 1) {
			fRec1222[l862] = 0.0;
		}
		for (int l863 = 0; l863 < 2; l863 = l863 + 1) {
			fRec1224[l863] = 0.0;
		}
		for (int l864 = 0; l864 < 2; l864 = l864 + 1) {
			fRec1225[l864] = 0.0;
		}
		for (int l865 = 0; l865 < 2; l865 = l865 + 1) {
			fRec1227[l865] = 0.0;
		}
		for (int l866 = 0; l866 < 2; l866 = l866 + 1) {
			fRec1228[l866] = 0.0;
		}
		for (int l867 = 0; l867 < 2; l867 = l867 + 1) {
			fRec1230[l867] = 0.0;
		}
		for (int l868 = 0; l868 < 2; l868 = l868 + 1) {
			fRec1231[l868] = 0.0;
		}
		for (int l869 = 0; l869 < 2; l869 = l869 + 1) {
			fRec1233[l869] = 0.0;
		}
		for (int l870 = 0; l870 < 2; l870 = l870 + 1) {
			fRec1234[l870] = 0.0;
		}
		for (int l871 = 0; l871 < 2; l871 = l871 + 1) {
			fRec1236[l871] = 0.0;
		}
		for (int l872 = 0; l872 < 2; l872 = l872 + 1) {
			fRec1237[l872] = 0.0;
		}
		for (int l873 = 0; l873 < 2; l873 = l873 + 1) {
			fRec1239[l873] = 0.0;
		}
		for (int l874 = 0; l874 < 2; l874 = l874 + 1) {
			fRec1240[l874] = 0.0;
		}
		for (int l875 = 0; l875 < 2; l875 = l875 + 1) {
			fRec1242[l875] = 0.0;
		}
		for (int l876 = 0; l876 < 2; l876 = l876 + 1) {
			fRec1243[l876] = 0.0;
		}
		for (int l877 = 0; l877 < 2; l877 = l877 + 1) {
			fRec1245[l877] = 0.0;
		}
		for (int l878 = 0; l878 < 2; l878 = l878 + 1) {
			fRec1246[l878] = 0.0;
		}
		for (int l879 = 0; l879 < 2; l879 = l879 + 1) {
			fRec1248[l879] = 0.0;
		}
		for (int l880 = 0; l880 < 2; l880 = l880 + 1) {
			fRec1249[l880] = 0.0;
		}
		for (int l881 = 0; l881 < 2; l881 = l881 + 1) {
			fRec1251[l881] = 0.0;
		}
		for (int l882 = 0; l882 < 2; l882 = l882 + 1) {
			fRec1252[l882] = 0.0;
		}
		for (int l883 = 0; l883 < 2; l883 = l883 + 1) {
			fRec1254[l883] = 0.0;
		}
		for (int l884 = 0; l884 < 2; l884 = l884 + 1) {
			fRec1255[l884] = 0.0;
		}
		for (int l885 = 0; l885 < 2; l885 = l885 + 1) {
			fRec1257[l885] = 0.0;
		}
		for (int l886 = 0; l886 < 2; l886 = l886 + 1) {
			fRec1258[l886] = 0.0;
		}
		for (int l887 = 0; l887 < 2; l887 = l887 + 1) {
			fRec1260[l887] = 0.0;
		}
		for (int l888 = 0; l888 < 2; l888 = l888 + 1) {
			fRec1261[l888] = 0.0;
		}
		for (int l889 = 0; l889 < 2; l889 = l889 + 1) {
			fRec1263[l889] = 0.0;
		}
		for (int l890 = 0; l890 < 2; l890 = l890 + 1) {
			fRec1264[l890] = 0.0;
		}
		for (int l891 = 0; l891 < 2; l891 = l891 + 1) {
			fRec1266[l891] = 0.0;
		}
		for (int l892 = 0; l892 < 2; l892 = l892 + 1) {
			fRec1267[l892] = 0.0;
		}
		for (int l893 = 0; l893 < 2; l893 = l893 + 1) {
			fRec1269[l893] = 0.0;
		}
		for (int l894 = 0; l894 < 2; l894 = l894 + 1) {
			fRec1270[l894] = 0.0;
		}
		for (int l895 = 0; l895 < 2; l895 = l895 + 1) {
			fRec1272[l895] = 0.0;
		}
		for (int l896 = 0; l896 < 2; l896 = l896 + 1) {
			fRec1273[l896] = 0.0;
		}
		for (int l897 = 0; l897 < 2; l897 = l897 + 1) {
			fRec1275[l897] = 0.0;
		}
		for (int l898 = 0; l898 < 2; l898 = l898 + 1) {
			fRec1276[l898] = 0.0;
		}
		for (int l899 = 0; l899 < 2; l899 = l899 + 1) {
			fRec1278[l899] = 0.0;
		}
		for (int l900 = 0; l900 < 2; l900 = l900 + 1) {
			fRec1279[l900] = 0.0;
		}
		for (int l901 = 0; l901 < 2; l901 = l901 + 1) {
			fRec1281[l901] = 0.0;
		}
		for (int l902 = 0; l902 < 2; l902 = l902 + 1) {
			fRec1282[l902] = 0.0;
		}
		for (int l903 = 0; l903 < 2; l903 = l903 + 1) {
			fRec1284[l903] = 0.0;
		}
		for (int l904 = 0; l904 < 2; l904 = l904 + 1) {
			fRec1285[l904] = 0.0;
		}
		for (int l905 = 0; l905 < 2; l905 = l905 + 1) {
			fRec1287[l905] = 0.0;
		}
		for (int l906 = 0; l906 < 2; l906 = l906 + 1) {
			fRec1288[l906] = 0.0;
		}
		for (int l907 = 0; l907 < 2; l907 = l907 + 1) {
			fRec1190[l907] = 0.0;
		}
		for (int l908 = 0; l908 < 2; l908 = l908 + 1) {
			fRec981[l908] = 0.0;
		}
		for (int l909 = 0; l909 < 4194304; l909 = l909 + 1) {
			fVec19[l909] = 0.0;
		}
		for (int l910 = 0; l910 < 2; l910 = l910 + 1) {
			fRec1290[l910] = 0.0;
		}
		for (int l911 = 0; l911 < 2; l911 = l911 + 1) {
			fRec1291[l911] = 0.0;
		}
		for (int l912 = 0; l912 < 2; l912 = l912 + 1) {
			fRec1292[l912] = 0.0;
		}
		for (int l913 = 0; l913 < 2; l913 = l913 + 1) {
			fRec1293[l913] = 0.0;
		}
		for (int l914 = 0; l914 < 2; l914 = l914 + 1) {
			fRec978[l914] = 0.0;
		}
		for (int l915 = 0; l915 < 2; l915 = l915 + 1) {
			fRec12[l915] = 0.0;
		}
		for (int l916 = 0; l916 < 2; l916 = l916 + 1) {
			fRec9[l916] = 0.0;
		}
		for (int l917 = 0; l917 < 2; l917 = l917 + 1) {
			fRec6[l917] = 0.0;
		}
		for (int l918 = 0; l918 < 512; l918 = l918 + 1) {
			fRec7[l918] = 0.0;
		}
		for (int l919 = 0; l919 < 2; l919 = l919 + 1) {
			iRec4[l919] = 0;
		}
		for (int l920 = 0; l920 < 2; l920 = l920 + 1) {
			fRec5[l920] = 0.0;
		}
		for (int l921 = 0; l921 < 2; l921 = l921 + 1) {
			fRec2[l921] = 0.0;
		}
		for (int l922 = 0; l922 < 2; l922 = l922 + 1) {
			fRec1[l922] = 0.0;
		}
		for (int l923 = 0; l923 < 2; l923 = l923 + 1) {
			fRec1294[l923] = 0.0;
		}
		for (int l924 = 0; l924 < 2; l924 = l924 + 1) {
			fRec0[l924] = 0.0;
		}
		for (int l925 = 0; l925 < 2; l925 = l925 + 1) {
			fRec1303[l925] = 0.0;
		}
		for (int l926 = 0; l926 < 2; l926 = l926 + 1) {
			fRec1301[l926] = 0.0;
		}
		for (int l927 = 0; l927 < 512; l927 = l927 + 1) {
			fRec1302[l927] = 0.0;
		}
		for (int l928 = 0; l928 < 2; l928 = l928 + 1) {
			iRec1299[l928] = 0;
		}
		for (int l929 = 0; l929 < 2; l929 = l929 + 1) {
			fRec1300[l929] = 0.0;
		}
		for (int l930 = 0; l930 < 2; l930 = l930 + 1) {
			fRec1297[l930] = 0.0;
		}
		for (int l931 = 0; l931 < 2; l931 = l931 + 1) {
			fRec1296[l931] = 0.0;
		}
		for (int l932 = 0; l932 < 2; l932 = l932 + 1) {
			fRec1295[l932] = 0.0;
		}
		for (int l933 = 0; l933 < 2; l933 = l933 + 1) {
			fRec1313[l933] = 0.0;
		}
		for (int l934 = 0; l934 < 2; l934 = l934 + 1) {
			fRec1311[l934] = 0.0;
		}
		for (int l935 = 0; l935 < 512; l935 = l935 + 1) {
			fRec1312[l935] = 0.0;
		}
		for (int l936 = 0; l936 < 2; l936 = l936 + 1) {
			iRec1309[l936] = 0;
		}
		for (int l937 = 0; l937 < 2; l937 = l937 + 1) {
			fRec1310[l937] = 0.0;
		}
		for (int l938 = 0; l938 < 2; l938 = l938 + 1) {
			fRec1307[l938] = 0.0;
		}
		for (int l939 = 0; l939 < 2; l939 = l939 + 1) {
			fRec1306[l939] = 0.0;
		}
		for (int l940 = 0; l940 < 2; l940 = l940 + 1) {
			fRec1305[l940] = 0.0;
		}
		for (int l941 = 0; l941 < 2; l941 = l941 + 1) {
			fRec1323[l941] = 0.0;
		}
		for (int l942 = 0; l942 < 2; l942 = l942 + 1) {
			fRec1321[l942] = 0.0;
		}
		for (int l943 = 0; l943 < 512; l943 = l943 + 1) {
			fRec1322[l943] = 0.0;
		}
		for (int l944 = 0; l944 < 2; l944 = l944 + 1) {
			iRec1319[l944] = 0;
		}
		for (int l945 = 0; l945 < 2; l945 = l945 + 1) {
			fRec1320[l945] = 0.0;
		}
		for (int l946 = 0; l946 < 2; l946 = l946 + 1) {
			fRec1317[l946] = 0.0;
		}
		for (int l947 = 0; l947 < 2; l947 = l947 + 1) {
			fRec1316[l947] = 0.0;
		}
		for (int l948 = 0; l948 < 2; l948 = l948 + 1) {
			fRec1315[l948] = 0.0;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("RITI_AutonomousNetwork_fixedVersion");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("Mixer");
		ui_interface->openHorizontalBox("Bandpass Filters Bank");
		ui_interface->addVerticalSlider("BP Bypass", &fVslider10, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider14, "unit", "Hz");
		ui_interface->addVerticalSlider("Bandwidth", &fVslider14, FAUSTFLOAT(1.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider13, "unit", "Hz");
		ui_interface->addVerticalSlider("Frequency", &fVslider13, FAUSTFLOAT(0.0), FAUSTFLOAT(-1.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.001));
		ui_interface->addVerticalSlider("Interpolations 1", &fVslider11, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.001));
		ui_interface->addVerticalSlider("Interpolations 2", &fVslider12, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.001));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Feedback Delay Network");
		ui_interface->openHorizontalBox("Input Delays");
		ui_interface->declare(&fVslider20, "2", "");
		ui_interface->declare(&fVslider20, "unit", "Sec");
		ui_interface->addVerticalSlider("Voice_0+1", &fVslider20, FAUSTFLOAT(9.2528), FAUSTFLOAT(0.001), FAUSTFLOAT(12.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider9, "2", "");
		ui_interface->declare(&fVslider9, "unit", "Sec");
		ui_interface->addVerticalSlider("Voice_1+1", &fVslider9, FAUSTFLOAT(6.9396), FAUSTFLOAT(0.001), FAUSTFLOAT(12.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider18, "2", "");
		ui_interface->declare(&fVslider18, "unit", "Sec");
		ui_interface->addVerticalSlider("Voice_2+1", &fVslider18, FAUSTFLOAT(4.6264), FAUSTFLOAT(0.001), FAUSTFLOAT(12.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider22, "2", "");
		ui_interface->declare(&fVslider22, "unit", "Sec");
		ui_interface->addVerticalSlider("Voice_3+1", &fVslider22, FAUSTFLOAT(2.3132), FAUSTFLOAT(0.001), FAUSTFLOAT(12.0), FAUSTFLOAT(0.001));
		ui_interface->closeBox();
		ui_interface->addVerticalSlider("Network FB", &fVslider8, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.001));
		ui_interface->openHorizontalBox("Output Delays");
		ui_interface->declare(&fVslider21, "2", "");
		ui_interface->declare(&fVslider21, "unit", "Sec");
		ui_interface->addVerticalSlider("Voice_0+1", &fVslider21, FAUSTFLOAT(2.8713), FAUSTFLOAT(0.001), FAUSTFLOAT(12.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider17, "2", "");
		ui_interface->declare(&fVslider17, "unit", "Sec");
		ui_interface->addVerticalSlider("Voice_1+1", &fVslider17, FAUSTFLOAT(5.7426), FAUSTFLOAT(0.001), FAUSTFLOAT(12.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider19, "2", "");
		ui_interface->declare(&fVslider19, "unit", "Sec");
		ui_interface->addVerticalSlider("Voice_2+1", &fVslider19, FAUSTFLOAT(8.613900000000001), FAUSTFLOAT(0.001), FAUSTFLOAT(12.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider23, "2", "");
		ui_interface->declare(&fVslider23, "unit", "Sec");
		ui_interface->addVerticalSlider("Voice_3+1", &fVslider23, FAUSTFLOAT(11.4852), FAUSTFLOAT(0.001), FAUSTFLOAT(12.0), FAUSTFLOAT(0.001));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Input-Output");
		ui_interface->declare(&fVslider5, "unit", "dB");
		ui_interface->addVerticalSlider("Externals", &fVslider5, FAUSTFLOAT(-8e+01), FAUSTFLOAT(-8e+01), FAUSTFLOAT(8e+01), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider2, "unit", "Hz");
		ui_interface->addVerticalSlider("HP frequency", &fVslider2, FAUSTFLOAT(1.0), FAUSTFLOAT(1.0), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider1, "unit", "Hz");
		ui_interface->addVerticalSlider("LP frequency", &fVslider1, FAUSTFLOAT(2e+04), FAUSTFLOAT(1.0), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider24, "unit", "dB");
		ui_interface->addVerticalSlider("Master", &fVslider24, FAUSTFLOAT(-8e+01), FAUSTFLOAT(-8e+01), FAUSTFLOAT(0.0), FAUSTFLOAT(0.001));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Interpolation");
		ui_interface->declare(&fVslider0, "unit", "Sec");
		ui_interface->addVerticalSlider("Smooth", &fVslider0, FAUSTFLOAT(1.0), FAUSTFLOAT(0.001), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.001));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Lorenz Equation Parameters");
		ui_interface->addVerticalSlider("Beta", &fVslider16, FAUSTFLOAT(1.073), FAUSTFLOAT(0.2666), FAUSTFLOAT(5.066), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider6, "unit", "dB");
		ui_interface->addVerticalSlider("Dt", &fVslider6, FAUSTFLOAT(0.0), FAUSTFLOAT(-6e+01), FAUSTFLOAT(6e+01), FAUSTFLOAT(0.001));
		ui_interface->addVerticalSlider("Lorenz FB", &fVslider4, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.001));
		ui_interface->addVerticalSlider("Rho", &fVslider15, FAUSTFLOAT(3.518), FAUSTFLOAT(2.8), FAUSTFLOAT(53.2), FAUSTFLOAT(0.001));
		ui_interface->addVerticalSlider("Sigma", &fVslider7, FAUSTFLOAT(1e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(19.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider3, "unit", "TanH");
		ui_interface->addVerticalSlider("TanH", &fVslider3, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(0.001));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openVerticalBox("Inspectors");
		ui_interface->openHorizontalBox("Bandpass Filters");
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("NetworkVoice_0");
		ui_interface->declare(&fVbargraph28, "2", "");
		ui_interface->declare(&fVbargraph28, "style", "numerical");
		ui_interface->addVerticalBargraph("X_1", &fVbargraph28, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph32, "2", "");
		ui_interface->declare(&fVbargraph32, "style", "numerical");
		ui_interface->addVerticalBargraph("Y_1", &fVbargraph32, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph35, "2", "");
		ui_interface->declare(&fVbargraph35, "style", "numerical");
		ui_interface->addVerticalBargraph("Z_1", &fVbargraph35, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("NetworkVoice_1");
		ui_interface->declare(&fVbargraph4, "2", "");
		ui_interface->declare(&fVbargraph4, "style", "numerical");
		ui_interface->addVerticalBargraph("X_2", &fVbargraph4, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph8, "2", "");
		ui_interface->declare(&fVbargraph8, "style", "numerical");
		ui_interface->addVerticalBargraph("Y_2", &fVbargraph8, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph11, "2", "");
		ui_interface->declare(&fVbargraph11, "style", "numerical");
		ui_interface->addVerticalBargraph("Z_2", &fVbargraph11, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("NetworkVoice_2");
		ui_interface->declare(&fVbargraph16, "2", "");
		ui_interface->declare(&fVbargraph16, "style", "numerical");
		ui_interface->addVerticalBargraph("X_3", &fVbargraph16, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph20, "2", "");
		ui_interface->declare(&fVbargraph20, "style", "numerical");
		ui_interface->addVerticalBargraph("Y_3", &fVbargraph20, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph23, "2", "");
		ui_interface->declare(&fVbargraph23, "style", "numerical");
		ui_interface->addVerticalBargraph("Z_3", &fVbargraph23, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("NetworkVoice_3");
		ui_interface->declare(&fVbargraph40, "2", "");
		ui_interface->declare(&fVbargraph40, "style", "numerical");
		ui_interface->addVerticalBargraph("X_4", &fVbargraph40, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph44, "2", "");
		ui_interface->declare(&fVbargraph44, "style", "numerical");
		ui_interface->addVerticalBargraph("Y_4", &fVbargraph44, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph47, "2", "");
		ui_interface->declare(&fVbargraph47, "style", "numerical");
		ui_interface->addVerticalBargraph("Z_4", &fVbargraph47, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("DC Blocker");
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("NetworkVoice_0");
		ui_interface->declare(&fVbargraph26, "2", "");
		ui_interface->declare(&fVbargraph26, "style", "numerical");
		ui_interface->addVerticalBargraph("X_1", &fVbargraph26, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph30, "2", "");
		ui_interface->declare(&fVbargraph30, "style", "numerical");
		ui_interface->addVerticalBargraph("Y_1", &fVbargraph30, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph33, "2", "");
		ui_interface->declare(&fVbargraph33, "style", "numerical");
		ui_interface->addVerticalBargraph("Z_1", &fVbargraph33, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("NetworkVoice_1");
		ui_interface->declare(&fVbargraph2, "2", "");
		ui_interface->declare(&fVbargraph2, "style", "numerical");
		ui_interface->addVerticalBargraph("X_2", &fVbargraph2, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph6, "2", "");
		ui_interface->declare(&fVbargraph6, "style", "numerical");
		ui_interface->addVerticalBargraph("Y_2", &fVbargraph6, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph9, "2", "");
		ui_interface->declare(&fVbargraph9, "style", "numerical");
		ui_interface->addVerticalBargraph("Z_2", &fVbargraph9, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("NetworkVoice_2");
		ui_interface->declare(&fVbargraph14, "2", "");
		ui_interface->declare(&fVbargraph14, "style", "numerical");
		ui_interface->addVerticalBargraph("X_3", &fVbargraph14, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph18, "2", "");
		ui_interface->declare(&fVbargraph18, "style", "numerical");
		ui_interface->addVerticalBargraph("Y_3", &fVbargraph18, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph21, "2", "");
		ui_interface->declare(&fVbargraph21, "style", "numerical");
		ui_interface->addVerticalBargraph("Z_3", &fVbargraph21, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("NetworkVoice_3");
		ui_interface->declare(&fVbargraph38, "2", "");
		ui_interface->declare(&fVbargraph38, "style", "numerical");
		ui_interface->addVerticalBargraph("X_4", &fVbargraph38, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph42, "2", "");
		ui_interface->declare(&fVbargraph42, "style", "numerical");
		ui_interface->addVerticalBargraph("Y_4", &fVbargraph42, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph45, "2", "");
		ui_interface->declare(&fVbargraph45, "style", "numerical");
		ui_interface->addVerticalBargraph("Z_4", &fVbargraph45, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Hyperbolic Tangent");
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("NetworkVoice_0");
		ui_interface->declare(&fVbargraph27, "2", "");
		ui_interface->declare(&fVbargraph27, "style", "numerical");
		ui_interface->addVerticalBargraph("X_1", &fVbargraph27, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph31, "2", "");
		ui_interface->declare(&fVbargraph31, "style", "numerical");
		ui_interface->addVerticalBargraph("Y_1", &fVbargraph31, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph34, "2", "");
		ui_interface->declare(&fVbargraph34, "style", "numerical");
		ui_interface->addVerticalBargraph("Z_1", &fVbargraph34, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("NetworkVoice_1");
		ui_interface->declare(&fVbargraph3, "2", "");
		ui_interface->declare(&fVbargraph3, "style", "numerical");
		ui_interface->addVerticalBargraph("X_2", &fVbargraph3, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph7, "2", "");
		ui_interface->declare(&fVbargraph7, "style", "numerical");
		ui_interface->addVerticalBargraph("Y_2", &fVbargraph7, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph10, "2", "");
		ui_interface->declare(&fVbargraph10, "style", "numerical");
		ui_interface->addVerticalBargraph("Z_2", &fVbargraph10, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("NetworkVoice_2");
		ui_interface->declare(&fVbargraph15, "2", "");
		ui_interface->declare(&fVbargraph15, "style", "numerical");
		ui_interface->addVerticalBargraph("X_3", &fVbargraph15, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph19, "2", "");
		ui_interface->declare(&fVbargraph19, "style", "numerical");
		ui_interface->addVerticalBargraph("Y_3", &fVbargraph19, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph22, "2", "");
		ui_interface->declare(&fVbargraph22, "style", "numerical");
		ui_interface->addVerticalBargraph("Z_3", &fVbargraph22, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("NetworkVoice_3");
		ui_interface->declare(&fVbargraph39, "2", "");
		ui_interface->declare(&fVbargraph39, "style", "numerical");
		ui_interface->addVerticalBargraph("X_4", &fVbargraph39, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph43, "2", "");
		ui_interface->declare(&fVbargraph43, "style", "numerical");
		ui_interface->addVerticalBargraph("Y_4", &fVbargraph43, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph46, "2", "");
		ui_interface->declare(&fVbargraph46, "style", "numerical");
		ui_interface->addVerticalBargraph("Z_4", &fVbargraph46, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Lorenz Feedback");
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("NetworkVoice_0");
		ui_interface->declare(&fVbargraph24, "2", "");
		ui_interface->declare(&fVbargraph24, "style", "numerical");
		ui_interface->addVerticalBargraph("X_1", &fVbargraph24, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph25, "2", "");
		ui_interface->declare(&fVbargraph25, "style", "numerical");
		ui_interface->addVerticalBargraph("Y_1", &fVbargraph25, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph29, "2", "");
		ui_interface->declare(&fVbargraph29, "style", "numerical");
		ui_interface->addVerticalBargraph("Z_1", &fVbargraph29, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("NetworkVoice_1");
		ui_interface->declare(&fVbargraph0, "2", "");
		ui_interface->declare(&fVbargraph0, "style", "numerical");
		ui_interface->addVerticalBargraph("X_2", &fVbargraph0, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph1, "2", "");
		ui_interface->declare(&fVbargraph1, "style", "numerical");
		ui_interface->addVerticalBargraph("Y_2", &fVbargraph1, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph5, "2", "");
		ui_interface->declare(&fVbargraph5, "style", "numerical");
		ui_interface->addVerticalBargraph("Z_2", &fVbargraph5, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("NetworkVoice_2");
		ui_interface->declare(&fVbargraph12, "2", "");
		ui_interface->declare(&fVbargraph12, "style", "numerical");
		ui_interface->addVerticalBargraph("X_3", &fVbargraph12, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph13, "2", "");
		ui_interface->declare(&fVbargraph13, "style", "numerical");
		ui_interface->addVerticalBargraph("Y_3", &fVbargraph13, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph17, "2", "");
		ui_interface->declare(&fVbargraph17, "style", "numerical");
		ui_interface->addVerticalBargraph("Z_3", &fVbargraph17, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("NetworkVoice_3");
		ui_interface->declare(&fVbargraph36, "2", "");
		ui_interface->declare(&fVbargraph36, "style", "numerical");
		ui_interface->addVerticalBargraph("X_4", &fVbargraph36, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph37, "2", "");
		ui_interface->declare(&fVbargraph37, "style", "numerical");
		ui_interface->addVerticalBargraph("Y_4", &fVbargraph37, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->declare(&fVbargraph41, "2", "");
		ui_interface->declare(&fVbargraph41, "style", "numerical");
		ui_interface->addVerticalBargraph("Z_4", &fVbargraph41, FAUSTFLOAT(0.0), FAUSTFLOAT(1e+03));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Output Channels");
		ui_interface->declare(&fVbargraph48, "2", "");
		ui_interface->declare(&fVbargraph48, "style", "numerical");
		ui_interface->addVerticalBargraph("1", &fVbargraph48, FAUSTFLOAT(0.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVbargraph49, "2", "");
		ui_interface->declare(&fVbargraph49, "style", "numerical");
		ui_interface->addVerticalBargraph("2", &fVbargraph49, FAUSTFLOAT(0.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVbargraph50, "2", "");
		ui_interface->declare(&fVbargraph50, "style", "numerical");
		ui_interface->addVerticalBargraph("3", &fVbargraph50, FAUSTFLOAT(0.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVbargraph51, "2", "");
		ui_interface->declare(&fVbargraph51, "style", "numerical");
		ui_interface->addVerticalBargraph("4", &fVbargraph51, FAUSTFLOAT(0.0), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* input2 = inputs[2];
		FAUSTFLOAT* input3 = inputs[3];
		FAUSTFLOAT* input4 = inputs[4];
		FAUSTFLOAT* input5 = inputs[5];
		FAUSTFLOAT* input6 = inputs[6];
		FAUSTFLOAT* input7 = inputs[7];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		FAUSTFLOAT* output2 = outputs[2];
		FAUSTFLOAT* output3 = outputs[3];
		double fSlow0 = std::exp(0.0 - fConst3 / double(fVslider0));
		double fSlow1 = 1.0 - fSlow0;
		double fSlow2 = double(fVslider1) * fSlow1;
		double fSlow3 = double(fVslider2) * fSlow1;
		double fSlow4 = double(fVslider3) * fSlow1;
		double fSlow5 = double(fVslider4) * fSlow1;
		double fSlow6 = std::pow(1e+01, 0.05 * double(fVslider5));
		double fSlow7 = fSlow1 * fSlow6 * double(fSlow6 > 0.0001);
		double fSlow8 = fSlow1 * std::pow(1e+01, 0.05 * double(fVslider6));
		double fSlow9 = double(fVslider7) * fSlow1;
		double fSlow10 = double(fVslider8) * fSlow1;
		double fSlow11 = fConst0 * double(fVslider9) + -1.0;
		double fSlow12 = double(fVslider10) * fSlow1;
		double fSlow13 = double(fVslider11) * fSlow1;
		double fSlow14 = double(fVslider12) * fSlow1;
		double fSlow15 = std::pow(16.0, double(fVslider13)) * fSlow1;
		double fSlow16 = double(fVslider14) * fSlow1;
		double fSlow17 = double(fVslider15) * fSlow1;
		double fSlow18 = double(fVslider16) * fSlow1;
		double fSlow19 = fConst0 * double(fVslider17) + -1.0;
		double fSlow20 = fConst0 * double(fVslider18) + -1.0;
		double fSlow21 = fConst0 * double(fVslider19) + -1.0;
		double fSlow22 = fConst0 * double(fVslider20) + -1.0;
		double fSlow23 = fConst0 * double(fVslider21) + -1.0;
		double fSlow24 = fConst0 * double(fVslider22) + -1.0;
		double fSlow25 = fConst0 * double(fVslider23) + -1.0;
		double fSlow26 = std::pow(1e+01, 0.05 * double(fVslider24));
		double fSlow27 = fSlow1 * fSlow26 * double(fSlow26 > 0.0001);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fRec8[0] = fSlow2 + fSlow0 * fRec8[1];
			double fTemp0 = std::tan(fConst4 * fRec8[0]);
			double fTemp1 = fTemp0 + 1.0;
			fRec11[0] = fSlow3 + fSlow0 * fRec11[1];
			double fTemp2 = std::tan(fConst4 * fRec11[0]);
			double fTemp3 = fTemp2 + 1.0;
			fRec18[0] = fSlow4 + fSlow0 * fRec18[1];
			double fTemp4 = std::max<double>(fRec18[0], 2.220446049250313e-16);
			fVec0[0] = 1.2;
			double fTemp5 = 1.2 - fVec0[1];
			fRec27[0] = fSlow5 + fSlow0 * fRec27[1];
			double fTemp6 = fRec27[0] * fRec19[1];
			fRec26[0] = std::max<double>(fConst1 * fRec26[1], std::fabs(fTemp6));
			fVbargraph0 = FAUSTFLOAT(fRec26[0]);
			double fTemp7 = fTemp6;
			fRec28[0] = fSlow7 + fSlow0 * fRec28[1];
			double fTemp8 = 0.25 * fRec28[0] * (double(input7[i0]) + double(input6[i0]) + double(input5[i0]) + double(input4[i0]) + double(input3[i0]) + double(input2[i0]) + double(input0[i0]) + double(input1[i0]));
			double fTemp9 = fRec27[0] * fRec20[1];
			fRec29[0] = std::max<double>(fConst1 * fRec29[1], std::fabs(fTemp9));
			fVbargraph1 = FAUSTFLOAT(fRec29[0]);
			double fTemp10 = fTemp9;
			fRec30[0] = fSlow8 + fSlow0 * fRec30[1];
			fRec31[0] = fSlow9 + fSlow0 * fRec31[1];
			double fTemp11 = fRec31[0] * fRec30[0];
			double fTemp12 = fTemp11 * (fTemp10 - fTemp7);
			fRec33[0] = fSlow10 + fSlow0 * fRec33[1];
			double fTemp13 = fRec33[0] * fRec12[1];
			fVec1[IOTA0 & 4194303] = fTemp13;
			double fTemp14 = ((fRec34[1] != 0.0) ? (((fRec35[1] > 0.0) & (fRec35[1] < 1.0)) ? fRec34[1] : 0.0) : (((fRec35[1] == 0.0) & (fSlow11 != fRec36[1])) ? 0.0009765625 : (((fRec35[1] == 1.0) & (fSlow11 != fRec37[1])) ? -0.0009765625 : 0.0)));
			fRec34[0] = fTemp14;
			fRec35[0] = std::max<double>(0.0, std::min<double>(1.0, fRec35[1] + fTemp14));
			fRec36[0] = (((fRec35[1] >= 1.0) & (fRec37[1] != fSlow11)) ? fSlow11 : fRec36[1]);
			fRec37[0] = (((fRec35[1] <= 0.0) & (fRec36[1] != fSlow11)) ? fSlow11 : fRec37[1]);
			double fTemp15 = fVec1[(IOTA0 - int(std::min<double>(fConst5, std::max<double>(0.0, fRec36[0])))) & 4194303];
			fRec32[0] = fTemp15 + fRec35[0] * (fVec1[(IOTA0 - int(std::min<double>(fConst5, std::max<double>(0.0, fRec37[0])))) & 4194303] - fTemp15);
			fVec2[0] = fRec32[1] + fTemp12 + fTemp8 + fTemp7 + fTemp5;
			fRec25[0] = fRec32[1] + fTemp12 + fTemp7 + fTemp8 + 0.995 * fRec25[1] + (1.2 - (fVec0[1] + fVec2[1]));
			fRec24[0] = std::max<double>(fConst1 * fRec24[1], std::fabs(fRec25[0]));
			fVbargraph2 = FAUSTFLOAT(fRec24[0]);
			double fTemp16 = fRec18[0] * tanh(fRec25[0] / fTemp4);
			fRec23[0] = std::max<double>(fConst1 * fRec23[1], std::fabs(fTemp16));
			fVbargraph3 = FAUSTFLOAT(fRec23[0]);
			double fTemp17 = fTemp16;
			fRec38[0] = fSlow12 + fSlow0 * fRec38[1];
			fRec42[0] = fSlow13 + fSlow0 * fRec42[1];
			fRec43[0] = fSlow14 + fSlow0 * fRec43[1];
			fRec44[0] = fSlow15 + fSlow0 * fRec44[1];
			double fTemp18 = fRec44[0] * (561.0 * fRec42[0] + fRec43[0] * (562.0 - 1097.0 * fRec42[0]) + 221.0);
			fRec45[0] = fSlow16 + fSlow0 * fRec45[1];
			double fTemp19 = std::max<double>(2.220446049250313e-16, fRec45[0]);
			double fTemp20 = std::tan(fConst4 * fTemp18);
			double fTemp21 = fTemp20 * (fTemp20 + fTemp19 / fTemp18) + 1.0;
			double fTemp22 = fTemp20 * (fTemp17 - fRec40[1]) + fRec39[1];
			fRec39[0] = 2.0 * (fTemp22 / fTemp21) - fRec39[1];
			fRec40[0] = fRec40[1] + 2.0 * (fTemp20 * fTemp22 / fTemp21);
			double fTemp23 = fRec43[0] * (0.20948251265282836 * fRec42[0] + -0.35882756573771113) + (0.883508750371294 - 0.3295246174054942 * fRec42[0]);
			double fRec41 = fTemp23 * fTemp22 / fTemp21;
			double fTemp24 = fRec44[0] * (1048.0 * fRec42[0] + fRec43[0] * (1.07e+03 * fRec42[0] + -787.0) + 1619.0);
			double fTemp25 = std::tan(fConst4 * fTemp24);
			double fTemp26 = fTemp25 * (fTemp25 + fTemp19 / fTemp24) + 1.0;
			double fTemp27 = fTemp25 * (fTemp17 - fRec47[1]) + fRec46[1];
			fRec46[0] = 2.0 * (fTemp27 / fTemp26) - fRec46[1];
			fRec47[0] = fRec47[1] + 2.0 * (fTemp25 * fTemp27 / fTemp26);
			double fTemp28 = fRec43[0] * (0.0016935641831933154 * fRec42[0] + -0.0070591277129707815) + (0.014962909727368317 - 0.007613896970744654 * fRec42[0]);
			double fRec48 = fTemp28 * fTemp27 / fTemp26;
			double fTemp29 = fRec44[0] * (687.0 * fRec42[0] + fRec43[0] * (311.0 - 2032.0 * fRec42[0]) + 2429.0);
			double fTemp30 = std::tan(fConst4 * fTemp29);
			double fTemp31 = fTemp30 * (fTemp30 + fTemp19 / fTemp29) + 1.0;
			double fTemp32 = fTemp30 * (fTemp17 - fRec50[1]) + fRec49[1];
			fRec49[0] = 2.0 * (fTemp32 / fTemp31) - fRec49[1];
			fRec50[0] = fRec50[1] + 2.0 * (fTemp30 * fTemp32 / fTemp31);
			double fTemp33 = fRec43[0] * (0.005227226473626777 * fRec42[0] + -0.010433410102575844) + (0.01934635943322834 - 0.010538363987102131 * fRec42[0]);
			double fRec51 = fTemp33 * fTemp32 / fTemp31;
			double fTemp34 = fRec44[0] * (1422.0 * fRec42[0] + fRec43[0] * (-4.0 - 526.0 * fRec42[0]) + 1178.0);
			double fTemp35 = std::tan(fConst4 * fTemp34);
			double fTemp36 = fTemp35 * (fTemp35 + fTemp19 / fTemp34) + 1.0;
			double fTemp37 = fTemp35 * (fTemp17 - fRec53[1]) + fRec52[1];
			fRec52[0] = 2.0 * (fTemp37 / fTemp36) - fRec52[1];
			fRec53[0] = fRec53[1] + 2.0 * (fTemp35 * fTemp37 / fTemp36);
			double fTemp38 = fRec43[0] * (0.0015990719330448112 * fRec42[0] + -0.009377259975676547) + (0.020502590513884294 - 0.008575258476103987 * fRec42[0]);
			double fRec54 = fTemp38 * fTemp37 / fTemp36;
			double fTemp39 = fRec44[0] * (1005.0 * fRec42[0] + fRec43[0] * (1538.0 - 1969.0 * fRec42[0]) + 1398.0);
			double fTemp40 = std::tan(fConst4 * fTemp39);
			double fTemp41 = fTemp40 * (fTemp40 + fTemp19 / fTemp39) + 1.0;
			double fTemp42 = fTemp40 * (fTemp17 - fRec56[1]) + fRec55[1];
			fRec55[0] = 2.0 * (fTemp42 / fTemp41) - fRec55[1];
			fRec56[0] = fRec56[1] + 2.0 * (fTemp40 * fTemp42 / fTemp41);
			double fTemp43 = fRec43[0] * (-0.004224308163056342 - 0.007247221109719737 * fRec42[0]) + (0.020955020563014883 - 0.004499122746580129 * fRec42[0]);
			double fRec57 = fTemp43 * fTemp42 / fTemp41;
			double fTemp44 = fRec44[0] * (726.0 * fRec42[0] + fRec43[0] * (507.0 - 2138.0 * fRec42[0]) + 2135.0);
			double fTemp45 = std::tan(fConst4 * fTemp44);
			double fTemp46 = fTemp45 * (fTemp45 + fTemp19 / fTemp44) + 1.0;
			double fTemp47 = fTemp45 * (fTemp17 - fRec59[1]) + fRec58[1];
			fRec58[0] = 2.0 * (fTemp47 / fTemp46) - fRec58[1];
			fRec59[0] = fRec59[1] + 2.0 * (fTemp45 * fTemp47 / fTemp46);
			double fTemp48 = fRec43[0] * (0.0009039247818369497 - 0.013893501673791466 * fRec42[0]) + (0.02359690477324046 - 0.005322076674786635 * fRec42[0]);
			double fRec60 = fTemp48 * fTemp47 / fTemp46;
			double fTemp49 = fRec44[0] * (125.0 * fRec42[0] + fRec43[0] * (9e+01 - 7.0 * fRec42[0]) + 2356.0);
			double fTemp50 = std::tan(fConst4 * fTemp49);
			double fTemp51 = fTemp50 * (fTemp50 + fTemp19 / fTemp49) + 1.0;
			double fTemp52 = fTemp50 * (fTemp17 - fRec62[1]) + fRec61[1];
			fRec61[0] = 2.0 * (fTemp52 / fTemp51) - fRec61[1];
			fRec62[0] = fRec62[1] + 2.0 * (fTemp50 * fTemp52 / fTemp51);
			double fTemp53 = fRec43[0] * (0.00789733404453236 - 0.022269972441420545 * fRec42[0]) + (0.024970356245165314 - 0.004948333836676418 * fRec42[0]);
			double fRec63 = fTemp53 * fTemp52 / fTemp51;
			double fTemp54 = fRec44[0] * (74.0 * fRec42[0] + fRec43[0] * (1147.0 - 837.0 * fRec42[0]) + 1104.0);
			double fTemp55 = std::tan(fConst4 * fTemp54);
			double fTemp56 = fTemp55 * (fTemp55 + fTemp19 / fTemp54) + 1.0;
			double fTemp57 = fTemp55 * (fTemp17 - fRec65[1]) + fRec64[1];
			fRec64[0] = 2.0 * (fTemp57 / fTemp56) - fRec64[1];
			fRec65[0] = fRec65[1] + 2.0 * (fTemp55 * fTemp57 / fTemp56);
			double fTemp58 = fRec43[0] * (0.014369998843206975 - 0.03300092964654322 * fRec42[0]) + (0.025519908386620865 - 0.0011683893550737713 * fRec42[0]);
			double fRec66 = fTemp58 * fTemp57 / fTemp56;
			double fTemp59 = fRec44[0] * (fRec43[0] * (241.0 * fRec42[0] + 6.3e+02) + (1914.0 - 1472.0 * fRec42[0]));
			double fTemp60 = std::tan(fConst4 * fTemp59);
			double fTemp61 = fTemp60 * (fTemp60 + fTemp19 / fTemp59) + 1.0;
			double fTemp62 = fTemp60 * (fTemp17 - fRec68[1]) + fRec67[1];
			fRec67[0] = 2.0 * (fTemp62 / fTemp61) - fRec67[1];
			fRec68[0] = fRec68[1] + 2.0 * (fTemp60 * fTemp62 / fTemp61);
			double fTemp63 = fRec43[0] * (0.012092025104768513 - 0.030118723258832435 * fRec42[0]) + (0.034299901561064564 - 0.009167713045154305 * fRec42[0]);
			double fRec69 = fTemp63 * fTemp62 / fTemp61;
			double fTemp64 = fRec44[0] * (403.0 * fRec42[0] + fRec43[0] * (1123.0 - 898.0 * fRec42[0]) + 1.03e+03);
			double fTemp65 = std::tan(fConst4 * fTemp64);
			double fTemp66 = fTemp65 * (fTemp65 + fTemp19 / fTemp64) + 1.0;
			double fTemp67 = fTemp65 * (fTemp17 - fRec71[1]) + fRec70[1];
			fRec70[0] = 2.0 * (fTemp67 / fTemp66) - fRec70[1];
			fRec71[0] = fRec71[1] + 2.0 * (fTemp65 * fTemp67 / fTemp66);
			double fTemp68 = fRec43[0] * (0.021778225322525664 - 0.04184590502930971 * fRec42[0]) + (0.03695324484801036 - 0.00815043374124962 * fRec42[0]);
			double fRec72 = fTemp68 * fTemp67 / fTemp66;
			double fTemp69 = 6.0 * fRec42[0];
			double fTemp70 = fRec44[0] * (fTemp69 + fRec43[0] * (838.0 * fRec42[0] + -812.0) + 1693.0);
			double fTemp71 = std::tan(fConst4 * fTemp70);
			double fTemp72 = fTemp71 * (fTemp71 + fTemp19 / fTemp70) + 1.0;
			double fTemp73 = fTemp71 * (fTemp17 - fRec74[1]) + fRec73[1];
			fRec73[0] = 2.0 * (fTemp73 / fTemp72) - fRec73[1];
			fRec74[0] = fRec74[1] + 2.0 * (fTemp71 * fTemp73 / fTemp72);
			double fTemp74 = fRec43[0] * (0.01054367849960227 - 0.044428922548055166 * fRec42[0]) + (0.04993743413946004 - 0.006818779501746489 * fRec42[0]);
			double fRec75 = fTemp74 * fTemp73 / fTemp72;
			double fTemp75 = fRec44[0] * (209.0 * fRec42[0] + fRec43[0] * (1515.0 - 1507.0 * fRec42[0]) + 442.0);
			double fTemp76 = std::tan(fConst4 * fTemp75);
			double fTemp77 = fTemp76 * (fTemp76 + fTemp19 / fTemp75) + 1.0;
			double fTemp78 = fTemp76 * (fTemp17 - fRec77[1]) + fRec76[1];
			fRec76[0] = 2.0 * (fTemp78 / fTemp77) - fRec76[1];
			fRec77[0] = fRec77[1] + 2.0 * (fTemp76 * fTemp78 / fTemp77);
			double fTemp79 = fRec43[0] * (-0.00836319425786336 - 0.027213728546822337 * fRec42[0]) + (0.07568694217870818 - 0.01847465835663161 * fRec42[0]);
			double fRec78 = fTemp79 * fTemp78 / fTemp77;
			double fTemp80 = fRec44[0] * (675.0 * fRec42[0] + fRec43[0] * (1172.0 - 1989.0 * fRec42[0]) + 883.0);
			double fTemp81 = std::tan(fConst4 * fTemp80);
			double fTemp82 = fTemp81 * (fTemp81 + fTemp19 / fTemp80) + 1.0;
			double fTemp83 = fTemp81 * (fTemp17 - fRec80[1]) + fRec79[1];
			fRec79[0] = 2.0 * (fTemp83 / fTemp82) - fRec79[1];
			fRec80[0] = fRec80[1] + 2.0 * (fTemp81 * fTemp83 / fTemp82);
			double fTemp84 = fRec43[0] * (0.01667332967615094 * fRec42[0] + -0.0754718266524771) + (0.15388399774271314 - 0.05838064149040649 * fRec42[0]);
			double fRec81 = fTemp84 * fTemp83 / fTemp82;
			double fTemp85 = fRec44[0] * (1.36e+03 * fRec42[0] + fRec43[0] * (-1e+02 - 1025.0 * fRec42[0]) + 589.0);
			double fTemp86 = std::tan(fConst4 * fTemp85);
			double fTemp87 = fTemp86 * (fTemp86 + fTemp19 / fTemp85) + 1.0;
			double fTemp88 = fTemp86 * (fTemp17 - fRec83[1]) + fRec82[1];
			fRec82[0] = 2.0 * (fTemp88 / fTemp87) - fRec82[1];
			fRec83[0] = fRec83[1] + 2.0 * (fTemp86 * fTemp88 / fTemp87);
			double fTemp89 = 0.012026367628721973 * fRec42[0] + fRec43[0] * (-0.03484164734028006 - 0.07088469349182304 * fRec42[0]) + 0.15986608084324763;
			double fRec84 = fTemp89 * fTemp88 / fTemp87;
			double fTemp90 = fRec44[0] * (fRec43[0] * (-51.0 - 11.0 * fRec42[0]) + (736.0 - 345.0 * fRec42[0]));
			double fTemp91 = std::tan(fConst4 * fTemp90);
			double fTemp92 = fTemp91 * (fTemp91 + fTemp19 / fTemp90) + 1.0;
			double fTemp93 = fTemp91 * (fTemp17 - fRec86[1]) + fRec85[1];
			fRec85[0] = 2.0 * (fTemp93 / fTemp92) - fRec85[1];
			fRec86[0] = fRec86[1] + 2.0 * (fTemp91 * fTemp93 / fTemp92);
			double fTemp94 = 0.043418834059638534 * fRec42[0] + fRec43[0] * (0.0003590165583120808 - 0.1653942291667907 * fRec42[0]) + 0.2004373971446242;
			double fRec87 = fTemp94 * fTemp93 / fTemp92;
			double fTemp95 = fRec44[0] * (113.0 * fRec42[0] + fRec43[0] * (147.0 - 325.0 * fRec42[0]) + 147.0);
			double fTemp96 = std::tan(fConst4 * fTemp95);
			double fTemp97 = fTemp96 * (fTemp96 + fTemp19 / fTemp95) + 1.0;
			double fTemp98 = fTemp96 * (fTemp17 - fRec89[1]) + fRec88[1];
			fRec88[0] = 2.0 * (fTemp98 / fTemp97) - fRec88[1];
			fRec89[0] = fRec89[1] + 2.0 * (fTemp96 * fTemp98 / fTemp97);
			double fTemp99 = fRec43[0] * (-0.20926865897501318 - 0.10045148502362689 * fRec42[0]) + (0.6105272358722508 - 0.05775171174785887 * fRec42[0]);
			double fRec90 = fTemp99 * fTemp98 / fTemp97;
			double fTemp100 = fRec44[0] * (fRec43[0] * (306.0 * fRec42[0] + -2.7e+02) + (368.0 - 239.0 * fRec42[0]));
			double fTemp101 = std::tan(fConst4 * fTemp100);
			double fTemp102 = fTemp101 * (fTemp101 + fTemp19 / fTemp100) + 1.0;
			double fTemp103 = fTemp101 * (fTemp17 - fRec92[1]) + fRec91[1];
			double fTemp104 = fTemp103 / fTemp102;
			fRec91[0] = 2.0 * fTemp104 - fRec91[1];
			fRec92[0] = fRec92[1] + 2.0 * (fTemp101 * fTemp103 / fTemp102);
			double fRec93 = fTemp104;
			double fTemp105 = fRec44[0] * (fTemp69 + fRec43[0] * (72.0 - 181.0 * fRec42[0]) + 515.0);
			double fTemp106 = std::tan(fConst4 * fTemp105);
			double fTemp107 = fTemp106 * (fTemp106 + fTemp19 / fTemp105) + 1.0;
			double fTemp108 = fTemp106 * (fTemp17 - fRec95[1]) + fRec94[1];
			fRec94[0] = 2.0 * (fTemp108 / fTemp107) - fRec94[1];
			fRec95[0] = fRec95[1] + 2.0 * (fTemp106 * fTemp108 / fTemp107);
			double fTemp109 = 0.1297691905274158 * fRec42[0] + fRec43[0] * (-0.020679500617239138 - 0.26354737961410307 * fRec42[0]) + 0.25009984168236576;
			double fRec96 = fTemp109 * fTemp108 / fTemp107;
			double fTemp110 = fRec44[0] * (968.0 * fRec42[0] + fRec43[0] * (122.0 - 588.0 * fRec42[0]) + 74.0);
			double fTemp111 = std::tan(fConst4 * fTemp110);
			double fTemp112 = fTemp111 * (fTemp111 + fTemp19 / fTemp110) + 1.0;
			double fTemp113 = fTemp111 * (fTemp17 - fRec98[1]) + fRec97[1];
			fRec97[0] = 2.0 * (fTemp113 / fTemp112) - fRec97[1];
			fRec98[0] = fRec98[1] + 2.0 * (fTemp111 * fTemp113 / fTemp112);
			double fTemp114 = fRec43[0] * (-0.00905548290563929 - 0.10407317928289174 * fRec42[0]) + (0.19782531572463796 - 0.011967933866223551 * fRec42[0]);
			double fRec99 = fTemp114 * fTemp113 / fTemp112;
			double fTemp115 = fRec44[0] * (102.0 * fRec42[0] + fRec43[0] * (756.0 - 762.0 * fRec42[0]) + 8.1e+02);
			double fTemp116 = std::tan(fConst4 * fTemp115);
			double fTemp117 = fTemp116 * (fTemp116 + fTemp19 / fTemp115) + 1.0;
			double fTemp118 = fTemp116 * (fTemp17 - fRec101[1]) + fRec100[1];
			fRec100[0] = 2.0 * (fTemp118 / fTemp117) - fRec100[1];
			fRec101[0] = fRec101[1] + 2.0 * (fTemp116 * fTemp118 / fTemp117);
			double fTemp119 = fRec43[0] * (-0.06073025380607225 - 0.02103357250515689 * fRec42[0]) + (0.15408867955329245 - 0.01859664908410899 * fRec42[0]);
			double fRec102 = fTemp119 * fTemp118 / fTemp117;
			double fTemp120 = fRec44[0] * (1784.0 * fRec42[0] + fRec43[0] * (96.0 - 1681.0 * fRec42[0]) + 295.0);
			double fTemp121 = std::tan(fConst4 * fTemp120);
			double fTemp122 = fTemp121 * (fTemp121 + fTemp19 / fTemp120) + 1.0;
			double fTemp123 = fTemp121 * (fTemp17 - fRec104[1]) + fRec103[1];
			fRec103[0] = 2.0 * (fTemp123 / fTemp122) - fRec103[1];
			fRec104[0] = fRec104[1] + 2.0 * (fTemp121 * fTemp123 / fTemp122);
			double fTemp124 = fRec43[0] * (0.00832579588520789 * fRec42[0] + -0.044200755516049905) + (0.12206611629626225 - 0.05880265929429268 * fRec42[0]);
			double fRec105 = fTemp124 * fTemp123 / fTemp122;
			double fTemp125 = fRec44[0] * (1689.0 * fRec42[0] + fRec43[0] * (806.0 - 1597.0 * fRec42[0]) + 662.0);
			double fTemp126 = std::tan(fConst4 * fTemp125);
			double fTemp127 = fTemp126 * (fTemp126 + fTemp19 / fTemp125) + 1.0;
			double fTemp128 = fTemp126 * (fTemp17 - fRec107[1]) + fRec106[1];
			fRec106[0] = 2.0 * (fTemp128 / fTemp127) - fRec106[1];
			fRec107[0] = fRec107[1] + 2.0 * (fTemp126 * fTemp128 / fTemp127);
			double fTemp129 = fRec43[0] * (-0.010952558243701213 - 0.024561127441574723 * fRec42[0]) + (0.0749419685950924 - 0.028820358890550887 * fRec42[0]);
			double fRec108 = fTemp129 * fTemp128 / fTemp127;
			double fTemp130 = fRec44[0] * (1265.0 * fRec42[0] + fRec43[0] * (1.2e+02 - 1.27e+03 * fRec42[0]) + 956.0);
			double fTemp131 = std::tan(fConst4 * fTemp130);
			double fTemp132 = fTemp131 * (fTemp131 + fTemp19 / fTemp130) + 1.0;
			double fTemp133 = fTemp131 * (fTemp17 - fRec110[1]) + fRec109[1];
			fRec109[0] = 2.0 * (fTemp133 / fTemp132) - fRec109[1];
			fRec110[0] = fRec110[1] + 2.0 * (fTemp131 * fTemp133 / fTemp132);
			double fTemp134 = fRec43[0] * (0.016194260220710646 - 0.04017164138792575 * fRec42[0]) + (0.04296305701601583 - 0.009998228849321458 * fRec42[0]);
			double fRec111 = fTemp134 * fTemp133 / fTemp132;
			double fTemp135 = fRec44[0] * (fRec43[0] * (951.0 * fRec42[0] + -618.0) + (2282.0 - 463.0 * fRec42[0]));
			double fTemp136 = std::tan(fConst4 * fTemp135);
			double fTemp137 = fTemp136 * (fTemp136 + fTemp19 / fTemp135) + 1.0;
			double fTemp138 = fTemp136 * (fTemp17 - fRec113[1]) + fRec112[1];
			fRec112[0] = 2.0 * (fTemp138 / fTemp137) - fRec112[1];
			fRec113[0] = fRec113[1] + 2.0 * (fTemp136 * fTemp138 / fTemp137);
			double fTemp139 = fRec43[0] * (0.015993820877451798 - 0.03561073091810513 * fRec42[0]) + (0.035190168499954565 - 0.007711275872944394 * fRec42[0]);
			double fRec114 = fTemp139 * fTemp138 / fTemp137;
			double fTemp140 = fRec44[0] * (fRec43[0] * (803.0 - 1117.0 * fRec42[0]) + (1546.0 - 238.0 * fRec42[0]));
			double fTemp141 = std::tan(fConst4 * fTemp140);
			double fTemp142 = fTemp141 * (fTemp141 + fTemp19 / fTemp140) + 1.0;
			double fTemp143 = fTemp141 * (fTemp17 - fRec116[1]) + fRec115[1];
			fRec115[0] = 2.0 * (fTemp143 / fTemp142) - fRec115[1];
			fRec116[0] = fRec116[1] + 2.0 * (fTemp141 * fTemp143 / fTemp142);
			double fTemp144 = fRec43[0] * (0.012251807773129418 - 0.030545193317676356 * fRec42[0]) + (0.027814420294695608 - 0.002830824883261286 * fRec42[0]);
			double fRec117 = fTemp144 * fTemp143 / fTemp142;
			double fTemp145 = fRec44[0] * (fRec43[0] * (1.34e+03 * fRec42[0] + -102.0) + (1472.0 - 903.0 * fRec42[0]));
			double fTemp146 = std::tan(fConst4 * fTemp145);
			double fTemp147 = fTemp146 * (fTemp146 + fTemp19 / fTemp145) + 1.0;
			double fTemp148 = fTemp146 * (fTemp17 - fRec119[1]) + fRec118[1];
			fRec118[0] = 2.0 * (fTemp148 / fTemp147) - fRec118[1];
			fRec119[0] = fRec119[1] + 2.0 * (fTemp146 * fTemp148 / fTemp147);
			double fTemp149 = fRec43[0] * (0.008006093262504007 - 0.024671130121872657 * fRec42[0]) + (0.025451275008886335 - 0.003130799157219928 * fRec42[0]);
			double fRec120 = fTemp149 * fTemp148 / fTemp147;
			double fTemp150 = fRec44[0] * (fRec43[0] * (861.0 * fRec42[0] + -1231.0) + (2503.0 - 228.0 * fRec42[0]));
			double fTemp151 = std::tan(fConst4 * fTemp150);
			double fTemp152 = fTemp151 * (fTemp151 + fTemp19 / fTemp150) + 1.0;
			double fTemp153 = fTemp151 * (fTemp17 - fRec122[1]) + fRec121[1];
			fRec121[0] = 2.0 * (fTemp153 / fTemp152) - fRec121[1];
			fRec122[0] = fRec122[1] + 2.0 * (fTemp151 * fTemp153 / fTemp152);
			double fTemp154 = fRec43[0] * (0.002393508230319367 - 0.01643892312610763 * fRec42[0]) + (0.02376619002590769 - 0.004291546045942368 * fRec42[0]);
			double fRec123 = fTemp154 * fTemp153 / fTemp152;
			double fTemp155 = fRec44[0] * (1281.0 * fRec42[0] + fRec43[0] * (37.0 * fRec42[0] + -273.0) + 1251.0);
			double fTemp156 = std::tan(fConst4 * fTemp155);
			double fTemp157 = fTemp156 * (fTemp156 + fTemp19 / fTemp155) + 1.0;
			double fTemp158 = fTemp156 * (fTemp17 - fRec125[1]) + fRec124[1];
			fRec124[0] = 2.0 * (fTemp158 / fTemp157) - fRec124[1];
			fRec125[0] = fRec125[1] + 2.0 * (fTemp156 * fTemp158 / fTemp157);
			double fTemp159 = fRec43[0] * (0.001634210217413834 - 0.013674190403903216 * fRec42[0]) + (0.02108580284017779 - 0.003933981224376031 * fRec42[0]);
			double fRec126 = fTemp159 * fTemp158 / fTemp157;
			double fTemp160 = fRec44[0] * (1666.0 * fRec42[0] + fRec43[0] * (436.0 - 1213.0 * fRec42[0]) + 1325.0);
			double fTemp161 = std::tan(fConst4 * fTemp160);
			double fTemp162 = fTemp161 * (fTemp161 + fTemp19 / fTemp160) + 1.0;
			double fTemp163 = fTemp161 * (fTemp17 - fRec128[1]) + fRec127[1];
			fRec127[0] = 2.0 * (fTemp163 / fTemp162) - fRec127[1];
			fRec128[0] = fRec128[1] + 2.0 * (fTemp161 * fTemp163 / fTemp162);
			double fTemp164 = fRec43[0] * (-0.006947658589813211 - 0.0032192382202462302 * fRec42[0]) + (0.02080994218773682 - 0.006343538597854104 * fRec42[0]);
			double fRec129 = fTemp164 * fTemp163 / fTemp162;
			double fTemp165 = fRec44[0] * (81.0 * fRec42[0] + fRec43[0] * (972.0 - 715.0 * fRec42[0]) + 2061.0);
			double fTemp166 = std::tan(fConst4 * fTemp165);
			double fTemp167 = fTemp166 * (fTemp166 + fTemp19 / fTemp165) + 1.0;
			double fTemp168 = fTemp166 * (fTemp17 - fRec131[1]) + fRec130[1];
			fRec130[0] = 2.0 * (fTemp168 / fTemp167) - fRec130[1];
			fRec131[0] = fRec131[1] + 2.0 * (fTemp166 * fTemp168 / fTemp167);
			double fTemp169 = fRec43[0] * (0.0021589052725694453 * fRec42[0] + -0.008904165411473826) + (0.019359564369447416 - 0.008690192954800124 * fRec42[0]);
			double fRec132 = fTemp169 * fTemp168 / fTemp167;
			double fTemp170 = fRec44[0] * (fRec43[0] * (1.02e+03 - 1.62e+03 * fRec42[0]) + (2209.0 - 456.0 * fRec42[0]));
			double fTemp171 = std::tan(fConst4 * fTemp170);
			double fTemp172 = fTemp171 * (fTemp171 + fTemp19 / fTemp170) + 1.0;
			double fTemp173 = fTemp171 * (fTemp17 - fRec134[1]) + fRec133[1];
			fRec133[0] = 2.0 * (fTemp173 / fTemp172) - fRec133[1];
			fRec134[0] = fRec134[1] + 2.0 * (fTemp171 * fTemp173 / fTemp172);
			double fTemp174 = fRec43[0] * (0.005044160613158476 * fRec42[0] + -0.01013056637869131) + (0.018745547950376563 - 0.011232336533809374 * fRec42[0]);
			double fRec135 = fTemp174 * fTemp173 / fTemp172;
			double fTemp175 = fRec44[0] * (805.0 * fRec42[0] + fRec43[0] * (266.0 - 7.7e+02 * fRec42[0]) + 2572.0);
			double fTemp176 = std::tan(fConst4 * fTemp175);
			double fTemp177 = fTemp176 * (fTemp176 + fTemp19 / fTemp175) + 1.0;
			double fTemp178 = fTemp176 * (fTemp17 - fRec137[1]) + fRec136[1];
			fRec136[0] = 2.0 * (fTemp178 / fTemp177) - fRec136[1];
			fRec137[0] = fRec137[1] + 2.0 * (fTemp176 * fTemp178 / fTemp177);
			double fTemp179 = fRec43[0] * (0.0016378452192321808 * fRec42[0] + -0.004344936518553382) + (0.011249397635411025 - 0.006780823623904783 * fRec42[0]);
			double fRec138 = fTemp179 * fTemp178 / fTemp177;
			double fTemp180 = 1.0 - fRec38[0];
			double fTemp181 = 0.03125 * fTemp180 * (fRec138 + fRec135 + fRec132 + fRec129 + fRec126 + fRec123 + fRec120 + fRec117 + fRec114 + fRec111 + fRec108 + fRec105 + fRec102 + fRec99 + fRec96 + fRec93 + fRec90 + fRec87 + fRec84 + fRec81 + fRec78 + fRec75 + fRec72 + fRec69 + fRec66 + fRec63 + fRec60 + fRec57 + fRec54 + fRec51 + fRec48 + fRec41) + fRec38[0] * fTemp17;
			fRec22[0] = std::max<double>(fConst1 * fRec22[1], std::fabs(fTemp181));
			fVbargraph4 = FAUSTFLOAT(fRec22[0]);
			fRec19[0] = fTemp181;
			fVec3[0] = 1.3;
			double fTemp182 = 1.3 - fVec3[1];
			double fTemp183 = fRec32[1] + fTemp8 + fTemp10;
			double fTemp184 = fRec27[0] * fRec21[1];
			fRec143[0] = std::max<double>(fConst1 * fRec143[1], std::fabs(fTemp184));
			fVbargraph5 = FAUSTFLOAT(fRec143[0]);
			double fTemp185 = fTemp184;
			fRec144[0] = fSlow17 + fSlow0 * fRec144[1];
			double fTemp186 = fRec30[0] * (fTemp7 * (fRec144[0] - fTemp185) - fTemp10);
			fVec4[0] = fTemp186 + fTemp183 + fTemp182;
			fRec142[0] = fTemp186 + 0.995 * fRec142[1] + fTemp183 + (1.3 - (fVec3[1] + fVec4[1]));
			fRec141[0] = std::max<double>(fConst1 * fRec141[1], std::fabs(fRec142[0]));
			fVbargraph6 = FAUSTFLOAT(fRec141[0]);
			double fTemp187 = fRec18[0] * tanh(fRec142[0] / fTemp4);
			fRec140[0] = std::max<double>(fConst1 * fRec140[1], std::fabs(fTemp187));
			fVbargraph7 = FAUSTFLOAT(fRec140[0]);
			double fTemp188 = fTemp187;
			double fTemp189 = fTemp20 * (fTemp188 - fRec146[1]) + fRec145[1];
			fRec145[0] = 2.0 * (fTemp189 / fTemp21) - fRec145[1];
			fRec146[0] = fRec146[1] + 2.0 * (fTemp20 * fTemp189 / fTemp21);
			double fRec147 = fTemp23 * fTemp189 / fTemp21;
			double fTemp190 = fTemp25 * (fTemp188 - fRec149[1]) + fRec148[1];
			fRec148[0] = 2.0 * (fTemp190 / fTemp26) - fRec148[1];
			fRec149[0] = fRec149[1] + 2.0 * (fTemp25 * fTemp190 / fTemp26);
			double fRec150 = fTemp28 * fTemp190 / fTemp26;
			double fTemp191 = fTemp30 * (fTemp188 - fRec152[1]) + fRec151[1];
			fRec151[0] = 2.0 * (fTemp191 / fTemp31) - fRec151[1];
			fRec152[0] = fRec152[1] + 2.0 * (fTemp30 * fTemp191 / fTemp31);
			double fRec153 = fTemp33 * fTemp191 / fTemp31;
			double fTemp192 = fTemp35 * (fTemp188 - fRec155[1]) + fRec154[1];
			fRec154[0] = 2.0 * (fTemp192 / fTemp36) - fRec154[1];
			fRec155[0] = fRec155[1] + 2.0 * (fTemp35 * fTemp192 / fTemp36);
			double fRec156 = fTemp38 * fTemp192 / fTemp36;
			double fTemp193 = fTemp40 * (fTemp188 - fRec158[1]) + fRec157[1];
			fRec157[0] = 2.0 * (fTemp193 / fTemp41) - fRec157[1];
			fRec158[0] = fRec158[1] + 2.0 * (fTemp40 * fTemp193 / fTemp41);
			double fRec159 = fTemp43 * fTemp193 / fTemp41;
			double fTemp194 = fTemp45 * (fTemp188 - fRec161[1]) + fRec160[1];
			fRec160[0] = 2.0 * (fTemp194 / fTemp46) - fRec160[1];
			fRec161[0] = fRec161[1] + 2.0 * (fTemp45 * fTemp194 / fTemp46);
			double fRec162 = fTemp48 * fTemp194 / fTemp46;
			double fTemp195 = fTemp50 * (fTemp188 - fRec164[1]) + fRec163[1];
			fRec163[0] = 2.0 * (fTemp195 / fTemp51) - fRec163[1];
			fRec164[0] = fRec164[1] + 2.0 * (fTemp50 * fTemp195 / fTemp51);
			double fRec165 = fTemp53 * fTemp195 / fTemp51;
			double fTemp196 = fTemp55 * (fTemp188 - fRec167[1]) + fRec166[1];
			fRec166[0] = 2.0 * (fTemp196 / fTemp56) - fRec166[1];
			fRec167[0] = fRec167[1] + 2.0 * (fTemp55 * fTemp196 / fTemp56);
			double fRec168 = fTemp58 * fTemp196 / fTemp56;
			double fTemp197 = fTemp60 * (fTemp188 - fRec170[1]) + fRec169[1];
			fRec169[0] = 2.0 * (fTemp197 / fTemp61) - fRec169[1];
			fRec170[0] = fRec170[1] + 2.0 * (fTemp60 * fTemp197 / fTemp61);
			double fRec171 = fTemp63 * fTemp197 / fTemp61;
			double fTemp198 = fTemp65 * (fTemp188 - fRec173[1]) + fRec172[1];
			fRec172[0] = 2.0 * (fTemp198 / fTemp66) - fRec172[1];
			fRec173[0] = fRec173[1] + 2.0 * (fTemp65 * fTemp198 / fTemp66);
			double fRec174 = fTemp68 * fTemp198 / fTemp66;
			double fTemp199 = fTemp71 * (fTemp188 - fRec176[1]) + fRec175[1];
			fRec175[0] = 2.0 * (fTemp199 / fTemp72) - fRec175[1];
			fRec176[0] = fRec176[1] + 2.0 * (fTemp71 * fTemp199 / fTemp72);
			double fRec177 = fTemp74 * fTemp199 / fTemp72;
			double fTemp200 = fTemp76 * (fTemp188 - fRec179[1]) + fRec178[1];
			fRec178[0] = 2.0 * (fTemp200 / fTemp77) - fRec178[1];
			fRec179[0] = fRec179[1] + 2.0 * (fTemp76 * fTemp200 / fTemp77);
			double fRec180 = fTemp79 * fTemp200 / fTemp77;
			double fTemp201 = fTemp81 * (fTemp188 - fRec182[1]) + fRec181[1];
			fRec181[0] = 2.0 * (fTemp201 / fTemp82) - fRec181[1];
			fRec182[0] = fRec182[1] + 2.0 * (fTemp81 * fTemp201 / fTemp82);
			double fRec183 = fTemp84 * fTemp201 / fTemp82;
			double fTemp202 = fTemp86 * (fTemp188 - fRec185[1]) + fRec184[1];
			fRec184[0] = 2.0 * (fTemp202 / fTemp87) - fRec184[1];
			fRec185[0] = fRec185[1] + 2.0 * (fTemp86 * fTemp202 / fTemp87);
			double fRec186 = fTemp89 * fTemp202 / fTemp87;
			double fTemp203 = fTemp91 * (fTemp188 - fRec188[1]) + fRec187[1];
			fRec187[0] = 2.0 * (fTemp203 / fTemp92) - fRec187[1];
			fRec188[0] = fRec188[1] + 2.0 * (fTemp91 * fTemp203 / fTemp92);
			double fRec189 = fTemp94 * fTemp203 / fTemp92;
			double fTemp204 = fTemp96 * (fTemp188 - fRec191[1]) + fRec190[1];
			fRec190[0] = 2.0 * (fTemp204 / fTemp97) - fRec190[1];
			fRec191[0] = fRec191[1] + 2.0 * (fTemp96 * fTemp204 / fTemp97);
			double fRec192 = fTemp99 * fTemp204 / fTemp97;
			double fTemp205 = fTemp101 * (fTemp188 - fRec194[1]) + fRec193[1];
			double fTemp206 = fTemp205 / fTemp102;
			fRec193[0] = 2.0 * fTemp206 - fRec193[1];
			fRec194[0] = fRec194[1] + 2.0 * (fTemp101 * fTemp205 / fTemp102);
			double fRec195 = fTemp206;
			double fTemp207 = fTemp106 * (fTemp188 - fRec197[1]) + fRec196[1];
			fRec196[0] = 2.0 * (fTemp207 / fTemp107) - fRec196[1];
			fRec197[0] = fRec197[1] + 2.0 * (fTemp106 * fTemp207 / fTemp107);
			double fRec198 = fTemp109 * fTemp207 / fTemp107;
			double fTemp208 = fTemp111 * (fTemp188 - fRec200[1]) + fRec199[1];
			fRec199[0] = 2.0 * (fTemp208 / fTemp112) - fRec199[1];
			fRec200[0] = fRec200[1] + 2.0 * (fTemp111 * fTemp208 / fTemp112);
			double fRec201 = fTemp114 * fTemp208 / fTemp112;
			double fTemp209 = fTemp116 * (fTemp188 - fRec203[1]) + fRec202[1];
			fRec202[0] = 2.0 * (fTemp209 / fTemp117) - fRec202[1];
			fRec203[0] = fRec203[1] + 2.0 * (fTemp116 * fTemp209 / fTemp117);
			double fRec204 = fTemp119 * fTemp209 / fTemp117;
			double fTemp210 = fTemp121 * (fTemp188 - fRec206[1]) + fRec205[1];
			fRec205[0] = 2.0 * (fTemp210 / fTemp122) - fRec205[1];
			fRec206[0] = fRec206[1] + 2.0 * (fTemp121 * fTemp210 / fTemp122);
			double fRec207 = fTemp124 * fTemp210 / fTemp122;
			double fTemp211 = fTemp126 * (fTemp188 - fRec209[1]) + fRec208[1];
			fRec208[0] = 2.0 * (fTemp211 / fTemp127) - fRec208[1];
			fRec209[0] = fRec209[1] + 2.0 * (fTemp126 * fTemp211 / fTemp127);
			double fRec210 = fTemp129 * fTemp211 / fTemp127;
			double fTemp212 = fTemp131 * (fTemp188 - fRec212[1]) + fRec211[1];
			fRec211[0] = 2.0 * (fTemp212 / fTemp132) - fRec211[1];
			fRec212[0] = fRec212[1] + 2.0 * (fTemp131 * fTemp212 / fTemp132);
			double fRec213 = fTemp134 * fTemp212 / fTemp132;
			double fTemp213 = fTemp136 * (fTemp188 - fRec215[1]) + fRec214[1];
			fRec214[0] = 2.0 * (fTemp213 / fTemp137) - fRec214[1];
			fRec215[0] = fRec215[1] + 2.0 * (fTemp136 * fTemp213 / fTemp137);
			double fRec216 = fTemp139 * fTemp213 / fTemp137;
			double fTemp214 = fTemp141 * (fTemp188 - fRec218[1]) + fRec217[1];
			fRec217[0] = 2.0 * (fTemp214 / fTemp142) - fRec217[1];
			fRec218[0] = fRec218[1] + 2.0 * (fTemp141 * fTemp214 / fTemp142);
			double fRec219 = fTemp144 * fTemp214 / fTemp142;
			double fTemp215 = fTemp146 * (fTemp188 - fRec221[1]) + fRec220[1];
			fRec220[0] = 2.0 * (fTemp215 / fTemp147) - fRec220[1];
			fRec221[0] = fRec221[1] + 2.0 * (fTemp146 * fTemp215 / fTemp147);
			double fRec222 = fTemp149 * fTemp215 / fTemp147;
			double fTemp216 = fTemp151 * (fTemp188 - fRec224[1]) + fRec223[1];
			fRec223[0] = 2.0 * (fTemp216 / fTemp152) - fRec223[1];
			fRec224[0] = fRec224[1] + 2.0 * (fTemp151 * fTemp216 / fTemp152);
			double fRec225 = fTemp154 * fTemp216 / fTemp152;
			double fTemp217 = fTemp156 * (fTemp188 - fRec227[1]) + fRec226[1];
			fRec226[0] = 2.0 * (fTemp217 / fTemp157) - fRec226[1];
			fRec227[0] = fRec227[1] + 2.0 * (fTemp156 * fTemp217 / fTemp157);
			double fRec228 = fTemp159 * fTemp217 / fTemp157;
			double fTemp218 = fTemp161 * (fTemp188 - fRec230[1]) + fRec229[1];
			fRec229[0] = 2.0 * (fTemp218 / fTemp162) - fRec229[1];
			fRec230[0] = fRec230[1] + 2.0 * (fTemp161 * fTemp218 / fTemp162);
			double fRec231 = fTemp164 * fTemp218 / fTemp162;
			double fTemp219 = fTemp166 * (fTemp188 - fRec233[1]) + fRec232[1];
			fRec232[0] = 2.0 * (fTemp219 / fTemp167) - fRec232[1];
			fRec233[0] = fRec233[1] + 2.0 * (fTemp166 * fTemp219 / fTemp167);
			double fRec234 = fTemp169 * fTemp219 / fTemp167;
			double fTemp220 = fTemp171 * (fTemp188 - fRec236[1]) + fRec235[1];
			fRec235[0] = 2.0 * (fTemp220 / fTemp172) - fRec235[1];
			fRec236[0] = fRec236[1] + 2.0 * (fTemp171 * fTemp220 / fTemp172);
			double fRec237 = fTemp174 * fTemp220 / fTemp172;
			double fTemp221 = fTemp176 * (fTemp188 - fRec239[1]) + fRec238[1];
			fRec238[0] = 2.0 * (fTemp221 / fTemp177) - fRec238[1];
			fRec239[0] = fRec239[1] + 2.0 * (fTemp176 * fTemp221 / fTemp177);
			double fRec240 = fTemp179 * fTemp221 / fTemp177;
			double fTemp222 = 0.03125 * fTemp180 * (fRec240 + fRec237 + fRec234 + fRec231 + fRec228 + fRec225 + fRec222 + fRec219 + fRec216 + fRec213 + fRec210 + fRec207 + fRec204 + fRec201 + fRec198 + fRec195 + fRec192 + fRec189 + fRec186 + fRec183 + fRec180 + fRec177 + fRec174 + fRec171 + fRec168 + fRec165 + fRec162 + fRec159 + fRec156 + fRec153 + fRec150 + fRec147) + fRec38[0] * fTemp188;
			fRec139[0] = std::max<double>(fConst1 * fRec139[1], std::fabs(fTemp222));
			fVbargraph8 = FAUSTFLOAT(fRec139[0]);
			fRec20[0] = fTemp222;
			fVec5[0] = 1.6;
			double fTemp223 = 1.6 - fVec5[1];
			double fTemp224 = fTemp8 + fRec32[1] + fTemp185;
			fRec245[0] = fSlow18 + fSlow0 * fRec245[1];
			double fTemp225 = fRec30[0] * (fTemp7 * fTemp10 - fRec245[0] * fTemp185);
			fVec6[0] = fTemp225 + fTemp224 + fTemp223;
			fRec244[0] = fTemp225 + 0.995 * fRec244[1] + fTemp224 + (1.6 - (fVec5[1] + fVec6[1]));
			fRec243[0] = std::max<double>(fConst1 * fRec243[1], std::fabs(fRec244[0]));
			fVbargraph9 = FAUSTFLOAT(fRec243[0]);
			double fTemp226 = fRec18[0] * tanh(fRec244[0] / fTemp4);
			fRec242[0] = std::max<double>(fConst1 * fRec242[1], std::fabs(fTemp226));
			fVbargraph10 = FAUSTFLOAT(fRec242[0]);
			double fTemp227 = fTemp226;
			double fTemp228 = fTemp20 * (fTemp227 - fRec247[1]) + fRec246[1];
			fRec246[0] = 2.0 * (fTemp228 / fTemp21) - fRec246[1];
			fRec247[0] = fRec247[1] + 2.0 * (fTemp20 * fTemp228 / fTemp21);
			double fRec248 = fTemp23 * fTemp228 / fTemp21;
			double fTemp229 = fTemp25 * (fTemp227 - fRec250[1]) + fRec249[1];
			fRec249[0] = 2.0 * (fTemp229 / fTemp26) - fRec249[1];
			fRec250[0] = fRec250[1] + 2.0 * (fTemp25 * fTemp229 / fTemp26);
			double fRec251 = fTemp28 * fTemp229 / fTemp26;
			double fTemp230 = fTemp30 * (fTemp227 - fRec253[1]) + fRec252[1];
			fRec252[0] = 2.0 * (fTemp230 / fTemp31) - fRec252[1];
			fRec253[0] = fRec253[1] + 2.0 * (fTemp30 * fTemp230 / fTemp31);
			double fRec254 = fTemp33 * fTemp230 / fTemp31;
			double fTemp231 = fTemp35 * (fTemp227 - fRec256[1]) + fRec255[1];
			fRec255[0] = 2.0 * (fTemp231 / fTemp36) - fRec255[1];
			fRec256[0] = fRec256[1] + 2.0 * (fTemp35 * fTemp231 / fTemp36);
			double fRec257 = fTemp38 * fTemp231 / fTemp36;
			double fTemp232 = fTemp40 * (fTemp227 - fRec259[1]) + fRec258[1];
			fRec258[0] = 2.0 * (fTemp232 / fTemp41) - fRec258[1];
			fRec259[0] = fRec259[1] + 2.0 * (fTemp40 * fTemp232 / fTemp41);
			double fRec260 = fTemp43 * fTemp232 / fTemp41;
			double fTemp233 = fTemp45 * (fTemp227 - fRec262[1]) + fRec261[1];
			fRec261[0] = 2.0 * (fTemp233 / fTemp46) - fRec261[1];
			fRec262[0] = fRec262[1] + 2.0 * (fTemp45 * fTemp233 / fTemp46);
			double fRec263 = fTemp48 * fTemp233 / fTemp46;
			double fTemp234 = fTemp50 * (fTemp227 - fRec265[1]) + fRec264[1];
			fRec264[0] = 2.0 * (fTemp234 / fTemp51) - fRec264[1];
			fRec265[0] = fRec265[1] + 2.0 * (fTemp50 * fTemp234 / fTemp51);
			double fRec266 = fTemp53 * fTemp234 / fTemp51;
			double fTemp235 = fTemp55 * (fTemp227 - fRec268[1]) + fRec267[1];
			fRec267[0] = 2.0 * (fTemp235 / fTemp56) - fRec267[1];
			fRec268[0] = fRec268[1] + 2.0 * (fTemp55 * fTemp235 / fTemp56);
			double fRec269 = fTemp58 * fTemp235 / fTemp56;
			double fTemp236 = fTemp60 * (fTemp227 - fRec271[1]) + fRec270[1];
			fRec270[0] = 2.0 * (fTemp236 / fTemp61) - fRec270[1];
			fRec271[0] = fRec271[1] + 2.0 * (fTemp60 * fTemp236 / fTemp61);
			double fRec272 = fTemp63 * fTemp236 / fTemp61;
			double fTemp237 = fTemp65 * (fTemp227 - fRec274[1]) + fRec273[1];
			fRec273[0] = 2.0 * (fTemp237 / fTemp66) - fRec273[1];
			fRec274[0] = fRec274[1] + 2.0 * (fTemp65 * fTemp237 / fTemp66);
			double fRec275 = fTemp68 * fTemp237 / fTemp66;
			double fTemp238 = fTemp71 * (fTemp227 - fRec277[1]) + fRec276[1];
			fRec276[0] = 2.0 * (fTemp238 / fTemp72) - fRec276[1];
			fRec277[0] = fRec277[1] + 2.0 * (fTemp71 * fTemp238 / fTemp72);
			double fRec278 = fTemp74 * fTemp238 / fTemp72;
			double fTemp239 = fTemp76 * (fTemp227 - fRec280[1]) + fRec279[1];
			fRec279[0] = 2.0 * (fTemp239 / fTemp77) - fRec279[1];
			fRec280[0] = fRec280[1] + 2.0 * (fTemp76 * fTemp239 / fTemp77);
			double fRec281 = fTemp79 * fTemp239 / fTemp77;
			double fTemp240 = fTemp81 * (fTemp227 - fRec283[1]) + fRec282[1];
			fRec282[0] = 2.0 * (fTemp240 / fTemp82) - fRec282[1];
			fRec283[0] = fRec283[1] + 2.0 * (fTemp81 * fTemp240 / fTemp82);
			double fRec284 = fTemp84 * fTemp240 / fTemp82;
			double fTemp241 = fTemp86 * (fTemp227 - fRec286[1]) + fRec285[1];
			fRec285[0] = 2.0 * (fTemp241 / fTemp87) - fRec285[1];
			fRec286[0] = fRec286[1] + 2.0 * (fTemp86 * fTemp241 / fTemp87);
			double fRec287 = fTemp89 * fTemp241 / fTemp87;
			double fTemp242 = fTemp91 * (fTemp227 - fRec289[1]) + fRec288[1];
			fRec288[0] = 2.0 * (fTemp242 / fTemp92) - fRec288[1];
			fRec289[0] = fRec289[1] + 2.0 * (fTemp91 * fTemp242 / fTemp92);
			double fRec290 = fTemp94 * fTemp242 / fTemp92;
			double fTemp243 = fTemp96 * (fTemp227 - fRec292[1]) + fRec291[1];
			fRec291[0] = 2.0 * (fTemp243 / fTemp97) - fRec291[1];
			fRec292[0] = fRec292[1] + 2.0 * (fTemp96 * fTemp243 / fTemp97);
			double fRec293 = fTemp99 * fTemp243 / fTemp97;
			double fTemp244 = fTemp101 * (fTemp227 - fRec295[1]) + fRec294[1];
			double fTemp245 = fTemp244 / fTemp102;
			fRec294[0] = 2.0 * fTemp245 - fRec294[1];
			fRec295[0] = fRec295[1] + 2.0 * (fTemp101 * fTemp244 / fTemp102);
			double fRec296 = fTemp245;
			double fTemp246 = fTemp106 * (fTemp227 - fRec298[1]) + fRec297[1];
			fRec297[0] = 2.0 * (fTemp246 / fTemp107) - fRec297[1];
			fRec298[0] = fRec298[1] + 2.0 * (fTemp106 * fTemp246 / fTemp107);
			double fRec299 = fTemp109 * fTemp246 / fTemp107;
			double fTemp247 = fTemp111 * (fTemp227 - fRec301[1]) + fRec300[1];
			fRec300[0] = 2.0 * (fTemp247 / fTemp112) - fRec300[1];
			fRec301[0] = fRec301[1] + 2.0 * (fTemp111 * fTemp247 / fTemp112);
			double fRec302 = fTemp114 * fTemp247 / fTemp112;
			double fTemp248 = fTemp116 * (fTemp227 - fRec304[1]) + fRec303[1];
			fRec303[0] = 2.0 * (fTemp248 / fTemp117) - fRec303[1];
			fRec304[0] = fRec304[1] + 2.0 * (fTemp116 * fTemp248 / fTemp117);
			double fRec305 = fTemp119 * fTemp248 / fTemp117;
			double fTemp249 = fTemp121 * (fTemp227 - fRec307[1]) + fRec306[1];
			fRec306[0] = 2.0 * (fTemp249 / fTemp122) - fRec306[1];
			fRec307[0] = fRec307[1] + 2.0 * (fTemp121 * fTemp249 / fTemp122);
			double fRec308 = fTemp124 * fTemp249 / fTemp122;
			double fTemp250 = fTemp126 * (fTemp227 - fRec310[1]) + fRec309[1];
			fRec309[0] = 2.0 * (fTemp250 / fTemp127) - fRec309[1];
			fRec310[0] = fRec310[1] + 2.0 * (fTemp126 * fTemp250 / fTemp127);
			double fRec311 = fTemp129 * fTemp250 / fTemp127;
			double fTemp251 = fTemp131 * (fTemp227 - fRec313[1]) + fRec312[1];
			fRec312[0] = 2.0 * (fTemp251 / fTemp132) - fRec312[1];
			fRec313[0] = fRec313[1] + 2.0 * (fTemp131 * fTemp251 / fTemp132);
			double fRec314 = fTemp134 * fTemp251 / fTemp132;
			double fTemp252 = fTemp136 * (fTemp227 - fRec316[1]) + fRec315[1];
			fRec315[0] = 2.0 * (fTemp252 / fTemp137) - fRec315[1];
			fRec316[0] = fRec316[1] + 2.0 * (fTemp136 * fTemp252 / fTemp137);
			double fRec317 = fTemp139 * fTemp252 / fTemp137;
			double fTemp253 = fTemp141 * (fTemp227 - fRec319[1]) + fRec318[1];
			fRec318[0] = 2.0 * (fTemp253 / fTemp142) - fRec318[1];
			fRec319[0] = fRec319[1] + 2.0 * (fTemp141 * fTemp253 / fTemp142);
			double fRec320 = fTemp144 * fTemp253 / fTemp142;
			double fTemp254 = fTemp146 * (fTemp227 - fRec322[1]) + fRec321[1];
			fRec321[0] = 2.0 * (fTemp254 / fTemp147) - fRec321[1];
			fRec322[0] = fRec322[1] + 2.0 * (fTemp146 * fTemp254 / fTemp147);
			double fRec323 = fTemp149 * fTemp254 / fTemp147;
			double fTemp255 = fTemp151 * (fTemp227 - fRec325[1]) + fRec324[1];
			fRec324[0] = 2.0 * (fTemp255 / fTemp152) - fRec324[1];
			fRec325[0] = fRec325[1] + 2.0 * (fTemp151 * fTemp255 / fTemp152);
			double fRec326 = fTemp154 * fTemp255 / fTemp152;
			double fTemp256 = fTemp156 * (fTemp227 - fRec328[1]) + fRec327[1];
			fRec327[0] = 2.0 * (fTemp256 / fTemp157) - fRec327[1];
			fRec328[0] = fRec328[1] + 2.0 * (fTemp156 * fTemp256 / fTemp157);
			double fRec329 = fTemp159 * fTemp256 / fTemp157;
			double fTemp257 = fTemp161 * (fTemp227 - fRec331[1]) + fRec330[1];
			fRec330[0] = 2.0 * (fTemp257 / fTemp162) - fRec330[1];
			fRec331[0] = fRec331[1] + 2.0 * (fTemp161 * fTemp257 / fTemp162);
			double fRec332 = fTemp164 * fTemp257 / fTemp162;
			double fTemp258 = fTemp166 * (fTemp227 - fRec334[1]) + fRec333[1];
			fRec333[0] = 2.0 * (fTemp258 / fTemp167) - fRec333[1];
			fRec334[0] = fRec334[1] + 2.0 * (fTemp166 * fTemp258 / fTemp167);
			double fRec335 = fTemp169 * fTemp258 / fTemp167;
			double fTemp259 = fTemp171 * (fTemp227 - fRec337[1]) + fRec336[1];
			fRec336[0] = 2.0 * (fTemp259 / fTemp172) - fRec336[1];
			fRec337[0] = fRec337[1] + 2.0 * (fTemp171 * fTemp259 / fTemp172);
			double fRec338 = fTemp174 * fTemp259 / fTemp172;
			double fTemp260 = fTemp176 * (fTemp227 - fRec340[1]) + fRec339[1];
			fRec339[0] = 2.0 * (fTemp260 / fTemp177) - fRec339[1];
			fRec340[0] = fRec340[1] + 2.0 * (fTemp176 * fTemp260 / fTemp177);
			double fRec341 = fTemp179 * fTemp260 / fTemp177;
			double fTemp261 = 0.03125 * fTemp180 * (fRec341 + fRec338 + fRec335 + fRec332 + fRec329 + fRec326 + fRec323 + fRec320 + fRec317 + fRec314 + fRec311 + fRec308 + fRec305 + fRec302 + fRec299 + fRec296 + fRec293 + fRec290 + fRec287 + fRec284 + fRec281 + fRec278 + fRec275 + fRec272 + fRec269 + fRec266 + fRec263 + fRec260 + fRec257 + fRec254 + fRec251 + fRec248) + fRec38[0] * fTemp227;
			fRec241[0] = std::max<double>(fConst1 * fRec241[1], std::fabs(fTemp261));
			fVbargraph11 = FAUSTFLOAT(fRec241[0]);
			fRec21[0] = fTemp261;
			double fTemp262 = (fRec21[0] + fRec19[0] + fRec20[0]) / fTemp4;
			fVec7[IOTA0 & 4194303] = fTemp262;
			double fTemp263 = ((fRec342[1] != 0.0) ? (((fRec343[1] > 0.0) & (fRec343[1] < 1.0)) ? fRec342[1] : 0.0) : (((fRec343[1] == 0.0) & (fSlow19 != fRec344[1])) ? 0.0009765625 : (((fRec343[1] == 1.0) & (fSlow19 != fRec345[1])) ? -0.0009765625 : 0.0)));
			fRec342[0] = fTemp263;
			fRec343[0] = std::max<double>(0.0, std::min<double>(1.0, fRec343[1] + fTemp263));
			fRec344[0] = (((fRec343[1] >= 1.0) & (fRec345[1] != fSlow19)) ? fSlow19 : fRec344[1]);
			fRec345[0] = (((fRec343[1] <= 0.0) & (fRec344[1] != fSlow19)) ? fSlow19 : fRec345[1]);
			double fTemp264 = fVec7[(IOTA0 - int(std::min<double>(fConst5, std::max<double>(0.0, fRec344[0])))) & 4194303];
			fRec17[0] = 0.3333333333333333 * fTemp264 + fRec343[0] * (0.0 - 0.3333333333333333 * (fTemp264 - fVec7[(IOTA0 - int(std::min<double>(fConst5, std::max<double>(0.0, fRec345[0])))) & 4194303]));
			double fTemp265 = fRec27[0] * fRec347[1];
			fRec354[0] = std::max<double>(fConst1 * fRec354[1], std::fabs(fTemp265));
			fVbargraph12 = FAUSTFLOAT(fRec354[0]);
			double fTemp266 = fTemp265;
			double fTemp267 = fRec27[0] * fRec348[1];
			fRec355[0] = std::max<double>(fConst1 * fRec355[1], std::fabs(fTemp267));
			fVbargraph13 = FAUSTFLOAT(fRec355[0]);
			double fTemp268 = fTemp267;
			double fTemp269 = fTemp11 * (fTemp268 - fTemp266);
			double fTemp270 = ((fRec357[1] != 0.0) ? (((fRec358[1] > 0.0) & (fRec358[1] < 1.0)) ? fRec357[1] : 0.0) : (((fRec358[1] == 0.0) & (fSlow20 != fRec359[1])) ? 0.0009765625 : (((fRec358[1] == 1.0) & (fSlow20 != fRec360[1])) ? -0.0009765625 : 0.0)));
			fRec357[0] = fTemp270;
			fRec358[0] = std::max<double>(0.0, std::min<double>(1.0, fRec358[1] + fTemp270));
			fRec359[0] = (((fRec358[1] >= 1.0) & (fRec360[1] != fSlow20)) ? fSlow20 : fRec359[1]);
			fRec360[0] = (((fRec358[1] <= 0.0) & (fRec359[1] != fSlow20)) ? fSlow20 : fRec360[1]);
			double fTemp271 = fVec1[(IOTA0 - int(std::min<double>(fConst5, std::max<double>(0.0, fRec359[0])))) & 4194303];
			fRec356[0] = fTemp271 + fRec358[0] * (fVec1[(IOTA0 - int(std::min<double>(fConst5, std::max<double>(0.0, fRec360[0])))) & 4194303] - fTemp271);
			fVec8[0] = fRec356[1] + fTemp269 + fTemp8 + fTemp266 + fTemp5;
			fRec353[0] = fRec356[1] + fTemp269 + fTemp266 + fTemp8 + 0.995 * fRec353[1] + (1.2 - (fVec0[1] + fVec8[1]));
			fRec352[0] = std::max<double>(fConst1 * fRec352[1], std::fabs(fRec353[0]));
			fVbargraph14 = FAUSTFLOAT(fRec352[0]);
			double fTemp272 = fRec18[0] * tanh(fRec353[0] / fTemp4);
			fRec351[0] = std::max<double>(fConst1 * fRec351[1], std::fabs(fTemp272));
			fVbargraph15 = FAUSTFLOAT(fRec351[0]);
			double fTemp273 = fTemp272;
			double fTemp274 = fTemp20 * (fTemp273 - fRec362[1]) + fRec361[1];
			fRec361[0] = 2.0 * (fTemp274 / fTemp21) - fRec361[1];
			fRec362[0] = fRec362[1] + 2.0 * (fTemp20 * fTemp274 / fTemp21);
			double fRec363 = fTemp23 * fTemp274 / fTemp21;
			double fTemp275 = fTemp25 * (fTemp273 - fRec365[1]) + fRec364[1];
			fRec364[0] = 2.0 * (fTemp275 / fTemp26) - fRec364[1];
			fRec365[0] = fRec365[1] + 2.0 * (fTemp25 * fTemp275 / fTemp26);
			double fRec366 = fTemp28 * fTemp275 / fTemp26;
			double fTemp276 = fTemp30 * (fTemp273 - fRec368[1]) + fRec367[1];
			fRec367[0] = 2.0 * (fTemp276 / fTemp31) - fRec367[1];
			fRec368[0] = fRec368[1] + 2.0 * (fTemp30 * fTemp276 / fTemp31);
			double fRec369 = fTemp33 * fTemp276 / fTemp31;
			double fTemp277 = fTemp35 * (fTemp273 - fRec371[1]) + fRec370[1];
			fRec370[0] = 2.0 * (fTemp277 / fTemp36) - fRec370[1];
			fRec371[0] = fRec371[1] + 2.0 * (fTemp35 * fTemp277 / fTemp36);
			double fRec372 = fTemp38 * fTemp277 / fTemp36;
			double fTemp278 = fTemp40 * (fTemp273 - fRec374[1]) + fRec373[1];
			fRec373[0] = 2.0 * (fTemp278 / fTemp41) - fRec373[1];
			fRec374[0] = fRec374[1] + 2.0 * (fTemp40 * fTemp278 / fTemp41);
			double fRec375 = fTemp43 * fTemp278 / fTemp41;
			double fTemp279 = fTemp45 * (fTemp273 - fRec377[1]) + fRec376[1];
			fRec376[0] = 2.0 * (fTemp279 / fTemp46) - fRec376[1];
			fRec377[0] = fRec377[1] + 2.0 * (fTemp45 * fTemp279 / fTemp46);
			double fRec378 = fTemp48 * fTemp279 / fTemp46;
			double fTemp280 = fTemp50 * (fTemp273 - fRec380[1]) + fRec379[1];
			fRec379[0] = 2.0 * (fTemp280 / fTemp51) - fRec379[1];
			fRec380[0] = fRec380[1] + 2.0 * (fTemp50 * fTemp280 / fTemp51);
			double fRec381 = fTemp53 * fTemp280 / fTemp51;
			double fTemp281 = fTemp55 * (fTemp273 - fRec383[1]) + fRec382[1];
			fRec382[0] = 2.0 * (fTemp281 / fTemp56) - fRec382[1];
			fRec383[0] = fRec383[1] + 2.0 * (fTemp55 * fTemp281 / fTemp56);
			double fRec384 = fTemp58 * fTemp281 / fTemp56;
			double fTemp282 = fTemp60 * (fTemp273 - fRec386[1]) + fRec385[1];
			fRec385[0] = 2.0 * (fTemp282 / fTemp61) - fRec385[1];
			fRec386[0] = fRec386[1] + 2.0 * (fTemp60 * fTemp282 / fTemp61);
			double fRec387 = fTemp63 * fTemp282 / fTemp61;
			double fTemp283 = fTemp65 * (fTemp273 - fRec389[1]) + fRec388[1];
			fRec388[0] = 2.0 * (fTemp283 / fTemp66) - fRec388[1];
			fRec389[0] = fRec389[1] + 2.0 * (fTemp65 * fTemp283 / fTemp66);
			double fRec390 = fTemp68 * fTemp283 / fTemp66;
			double fTemp284 = fTemp71 * (fTemp273 - fRec392[1]) + fRec391[1];
			fRec391[0] = 2.0 * (fTemp284 / fTemp72) - fRec391[1];
			fRec392[0] = fRec392[1] + 2.0 * (fTemp71 * fTemp284 / fTemp72);
			double fRec393 = fTemp74 * fTemp284 / fTemp72;
			double fTemp285 = fTemp76 * (fTemp273 - fRec395[1]) + fRec394[1];
			fRec394[0] = 2.0 * (fTemp285 / fTemp77) - fRec394[1];
			fRec395[0] = fRec395[1] + 2.0 * (fTemp76 * fTemp285 / fTemp77);
			double fRec396 = fTemp79 * fTemp285 / fTemp77;
			double fTemp286 = fTemp81 * (fTemp273 - fRec398[1]) + fRec397[1];
			fRec397[0] = 2.0 * (fTemp286 / fTemp82) - fRec397[1];
			fRec398[0] = fRec398[1] + 2.0 * (fTemp81 * fTemp286 / fTemp82);
			double fRec399 = fTemp84 * fTemp286 / fTemp82;
			double fTemp287 = fTemp86 * (fTemp273 - fRec401[1]) + fRec400[1];
			fRec400[0] = 2.0 * (fTemp287 / fTemp87) - fRec400[1];
			fRec401[0] = fRec401[1] + 2.0 * (fTemp86 * fTemp287 / fTemp87);
			double fRec402 = fTemp89 * fTemp287 / fTemp87;
			double fTemp288 = fTemp91 * (fTemp273 - fRec404[1]) + fRec403[1];
			fRec403[0] = 2.0 * (fTemp288 / fTemp92) - fRec403[1];
			fRec404[0] = fRec404[1] + 2.0 * (fTemp91 * fTemp288 / fTemp92);
			double fRec405 = fTemp94 * fTemp288 / fTemp92;
			double fTemp289 = fTemp96 * (fTemp273 - fRec407[1]) + fRec406[1];
			fRec406[0] = 2.0 * (fTemp289 / fTemp97) - fRec406[1];
			fRec407[0] = fRec407[1] + 2.0 * (fTemp96 * fTemp289 / fTemp97);
			double fRec408 = fTemp99 * fTemp289 / fTemp97;
			double fTemp290 = fTemp101 * (fTemp273 - fRec410[1]) + fRec409[1];
			double fTemp291 = fTemp290 / fTemp102;
			fRec409[0] = 2.0 * fTemp291 - fRec409[1];
			fRec410[0] = fRec410[1] + 2.0 * (fTemp101 * fTemp290 / fTemp102);
			double fRec411 = fTemp291;
			double fTemp292 = fTemp106 * (fTemp273 - fRec413[1]) + fRec412[1];
			fRec412[0] = 2.0 * (fTemp292 / fTemp107) - fRec412[1];
			fRec413[0] = fRec413[1] + 2.0 * (fTemp106 * fTemp292 / fTemp107);
			double fRec414 = fTemp109 * fTemp292 / fTemp107;
			double fTemp293 = fTemp111 * (fTemp273 - fRec416[1]) + fRec415[1];
			fRec415[0] = 2.0 * (fTemp293 / fTemp112) - fRec415[1];
			fRec416[0] = fRec416[1] + 2.0 * (fTemp111 * fTemp293 / fTemp112);
			double fRec417 = fTemp114 * fTemp293 / fTemp112;
			double fTemp294 = fTemp116 * (fTemp273 - fRec419[1]) + fRec418[1];
			fRec418[0] = 2.0 * (fTemp294 / fTemp117) - fRec418[1];
			fRec419[0] = fRec419[1] + 2.0 * (fTemp116 * fTemp294 / fTemp117);
			double fRec420 = fTemp119 * fTemp294 / fTemp117;
			double fTemp295 = fTemp121 * (fTemp273 - fRec422[1]) + fRec421[1];
			fRec421[0] = 2.0 * (fTemp295 / fTemp122) - fRec421[1];
			fRec422[0] = fRec422[1] + 2.0 * (fTemp121 * fTemp295 / fTemp122);
			double fRec423 = fTemp124 * fTemp295 / fTemp122;
			double fTemp296 = fTemp126 * (fTemp273 - fRec425[1]) + fRec424[1];
			fRec424[0] = 2.0 * (fTemp296 / fTemp127) - fRec424[1];
			fRec425[0] = fRec425[1] + 2.0 * (fTemp126 * fTemp296 / fTemp127);
			double fRec426 = fTemp129 * fTemp296 / fTemp127;
			double fTemp297 = fTemp131 * (fTemp273 - fRec428[1]) + fRec427[1];
			fRec427[0] = 2.0 * (fTemp297 / fTemp132) - fRec427[1];
			fRec428[0] = fRec428[1] + 2.0 * (fTemp131 * fTemp297 / fTemp132);
			double fRec429 = fTemp134 * fTemp297 / fTemp132;
			double fTemp298 = fTemp136 * (fTemp273 - fRec431[1]) + fRec430[1];
			fRec430[0] = 2.0 * (fTemp298 / fTemp137) - fRec430[1];
			fRec431[0] = fRec431[1] + 2.0 * (fTemp136 * fTemp298 / fTemp137);
			double fRec432 = fTemp139 * fTemp298 / fTemp137;
			double fTemp299 = fTemp141 * (fTemp273 - fRec434[1]) + fRec433[1];
			fRec433[0] = 2.0 * (fTemp299 / fTemp142) - fRec433[1];
			fRec434[0] = fRec434[1] + 2.0 * (fTemp141 * fTemp299 / fTemp142);
			double fRec435 = fTemp144 * fTemp299 / fTemp142;
			double fTemp300 = fTemp146 * (fTemp273 - fRec437[1]) + fRec436[1];
			fRec436[0] = 2.0 * (fTemp300 / fTemp147) - fRec436[1];
			fRec437[0] = fRec437[1] + 2.0 * (fTemp146 * fTemp300 / fTemp147);
			double fRec438 = fTemp149 * fTemp300 / fTemp147;
			double fTemp301 = fTemp151 * (fTemp273 - fRec440[1]) + fRec439[1];
			fRec439[0] = 2.0 * (fTemp301 / fTemp152) - fRec439[1];
			fRec440[0] = fRec440[1] + 2.0 * (fTemp151 * fTemp301 / fTemp152);
			double fRec441 = fTemp154 * fTemp301 / fTemp152;
			double fTemp302 = fTemp156 * (fTemp273 - fRec443[1]) + fRec442[1];
			fRec442[0] = 2.0 * (fTemp302 / fTemp157) - fRec442[1];
			fRec443[0] = fRec443[1] + 2.0 * (fTemp156 * fTemp302 / fTemp157);
			double fRec444 = fTemp159 * fTemp302 / fTemp157;
			double fTemp303 = fTemp161 * (fTemp273 - fRec446[1]) + fRec445[1];
			fRec445[0] = 2.0 * (fTemp303 / fTemp162) - fRec445[1];
			fRec446[0] = fRec446[1] + 2.0 * (fTemp161 * fTemp303 / fTemp162);
			double fRec447 = fTemp164 * fTemp303 / fTemp162;
			double fTemp304 = fTemp166 * (fTemp273 - fRec449[1]) + fRec448[1];
			fRec448[0] = 2.0 * (fTemp304 / fTemp167) - fRec448[1];
			fRec449[0] = fRec449[1] + 2.0 * (fTemp166 * fTemp304 / fTemp167);
			double fRec450 = fTemp169 * fTemp304 / fTemp167;
			double fTemp305 = fTemp171 * (fTemp273 - fRec452[1]) + fRec451[1];
			fRec451[0] = 2.0 * (fTemp305 / fTemp172) - fRec451[1];
			fRec452[0] = fRec452[1] + 2.0 * (fTemp171 * fTemp305 / fTemp172);
			double fRec453 = fTemp174 * fTemp305 / fTemp172;
			double fTemp306 = fTemp176 * (fTemp273 - fRec455[1]) + fRec454[1];
			fRec454[0] = 2.0 * (fTemp306 / fTemp177) - fRec454[1];
			fRec455[0] = fRec455[1] + 2.0 * (fTemp176 * fTemp306 / fTemp177);
			double fRec456 = fTemp179 * fTemp306 / fTemp177;
			double fTemp307 = 0.03125 * fTemp180 * (fRec456 + fRec453 + fRec450 + fRec447 + fRec444 + fRec441 + fRec438 + fRec435 + fRec432 + fRec429 + fRec426 + fRec423 + fRec420 + fRec417 + fRec414 + fRec411 + fRec408 + fRec405 + fRec402 + fRec399 + fRec396 + fRec393 + fRec390 + fRec387 + fRec384 + fRec381 + fRec378 + fRec375 + fRec372 + fRec369 + fRec366 + fRec363) + fRec38[0] * fTemp273;
			fRec350[0] = std::max<double>(fConst1 * fRec350[1], std::fabs(fTemp307));
			fVbargraph16 = FAUSTFLOAT(fRec350[0]);
			fRec347[0] = fTemp307;
			double fTemp308 = fRec356[1] + fTemp8 + fTemp268;
			double fTemp309 = fRec27[0] * fRec349[1];
			fRec461[0] = std::max<double>(fConst1 * fRec461[1], std::fabs(fTemp309));
			fVbargraph17 = FAUSTFLOAT(fRec461[0]);
			double fTemp310 = fTemp309;
			double fTemp311 = fRec30[0] * (fTemp266 * (fRec144[0] - fTemp310) - fTemp268);
			fVec9[0] = fTemp311 + fTemp308 + fTemp182;
			fRec460[0] = fTemp311 + 0.995 * fRec460[1] + fTemp308 + (1.3 - (fVec3[1] + fVec9[1]));
			fRec459[0] = std::max<double>(fConst1 * fRec459[1], std::fabs(fRec460[0]));
			fVbargraph18 = FAUSTFLOAT(fRec459[0]);
			double fTemp312 = fRec18[0] * tanh(fRec460[0] / fTemp4);
			fRec458[0] = std::max<double>(fConst1 * fRec458[1], std::fabs(fTemp312));
			fVbargraph19 = FAUSTFLOAT(fRec458[0]);
			double fTemp313 = fTemp312;
			double fTemp314 = fTemp20 * (fTemp313 - fRec463[1]) + fRec462[1];
			fRec462[0] = 2.0 * (fTemp314 / fTemp21) - fRec462[1];
			fRec463[0] = fRec463[1] + 2.0 * (fTemp20 * fTemp314 / fTemp21);
			double fRec464 = fTemp23 * fTemp314 / fTemp21;
			double fTemp315 = fTemp25 * (fTemp313 - fRec466[1]) + fRec465[1];
			fRec465[0] = 2.0 * (fTemp315 / fTemp26) - fRec465[1];
			fRec466[0] = fRec466[1] + 2.0 * (fTemp25 * fTemp315 / fTemp26);
			double fRec467 = fTemp28 * fTemp315 / fTemp26;
			double fTemp316 = fTemp30 * (fTemp313 - fRec469[1]) + fRec468[1];
			fRec468[0] = 2.0 * (fTemp316 / fTemp31) - fRec468[1];
			fRec469[0] = fRec469[1] + 2.0 * (fTemp30 * fTemp316 / fTemp31);
			double fRec470 = fTemp33 * fTemp316 / fTemp31;
			double fTemp317 = fTemp35 * (fTemp313 - fRec472[1]) + fRec471[1];
			fRec471[0] = 2.0 * (fTemp317 / fTemp36) - fRec471[1];
			fRec472[0] = fRec472[1] + 2.0 * (fTemp35 * fTemp317 / fTemp36);
			double fRec473 = fTemp38 * fTemp317 / fTemp36;
			double fTemp318 = fTemp40 * (fTemp313 - fRec475[1]) + fRec474[1];
			fRec474[0] = 2.0 * (fTemp318 / fTemp41) - fRec474[1];
			fRec475[0] = fRec475[1] + 2.0 * (fTemp40 * fTemp318 / fTemp41);
			double fRec476 = fTemp43 * fTemp318 / fTemp41;
			double fTemp319 = fTemp45 * (fTemp313 - fRec478[1]) + fRec477[1];
			fRec477[0] = 2.0 * (fTemp319 / fTemp46) - fRec477[1];
			fRec478[0] = fRec478[1] + 2.0 * (fTemp45 * fTemp319 / fTemp46);
			double fRec479 = fTemp48 * fTemp319 / fTemp46;
			double fTemp320 = fTemp50 * (fTemp313 - fRec481[1]) + fRec480[1];
			fRec480[0] = 2.0 * (fTemp320 / fTemp51) - fRec480[1];
			fRec481[0] = fRec481[1] + 2.0 * (fTemp50 * fTemp320 / fTemp51);
			double fRec482 = fTemp53 * fTemp320 / fTemp51;
			double fTemp321 = fTemp55 * (fTemp313 - fRec484[1]) + fRec483[1];
			fRec483[0] = 2.0 * (fTemp321 / fTemp56) - fRec483[1];
			fRec484[0] = fRec484[1] + 2.0 * (fTemp55 * fTemp321 / fTemp56);
			double fRec485 = fTemp58 * fTemp321 / fTemp56;
			double fTemp322 = fTemp60 * (fTemp313 - fRec487[1]) + fRec486[1];
			fRec486[0] = 2.0 * (fTemp322 / fTemp61) - fRec486[1];
			fRec487[0] = fRec487[1] + 2.0 * (fTemp60 * fTemp322 / fTemp61);
			double fRec488 = fTemp63 * fTemp322 / fTemp61;
			double fTemp323 = fTemp65 * (fTemp313 - fRec490[1]) + fRec489[1];
			fRec489[0] = 2.0 * (fTemp323 / fTemp66) - fRec489[1];
			fRec490[0] = fRec490[1] + 2.0 * (fTemp65 * fTemp323 / fTemp66);
			double fRec491 = fTemp68 * fTemp323 / fTemp66;
			double fTemp324 = fTemp71 * (fTemp313 - fRec493[1]) + fRec492[1];
			fRec492[0] = 2.0 * (fTemp324 / fTemp72) - fRec492[1];
			fRec493[0] = fRec493[1] + 2.0 * (fTemp71 * fTemp324 / fTemp72);
			double fRec494 = fTemp74 * fTemp324 / fTemp72;
			double fTemp325 = fTemp76 * (fTemp313 - fRec496[1]) + fRec495[1];
			fRec495[0] = 2.0 * (fTemp325 / fTemp77) - fRec495[1];
			fRec496[0] = fRec496[1] + 2.0 * (fTemp76 * fTemp325 / fTemp77);
			double fRec497 = fTemp79 * fTemp325 / fTemp77;
			double fTemp326 = fTemp81 * (fTemp313 - fRec499[1]) + fRec498[1];
			fRec498[0] = 2.0 * (fTemp326 / fTemp82) - fRec498[1];
			fRec499[0] = fRec499[1] + 2.0 * (fTemp81 * fTemp326 / fTemp82);
			double fRec500 = fTemp84 * fTemp326 / fTemp82;
			double fTemp327 = fTemp86 * (fTemp313 - fRec502[1]) + fRec501[1];
			fRec501[0] = 2.0 * (fTemp327 / fTemp87) - fRec501[1];
			fRec502[0] = fRec502[1] + 2.0 * (fTemp86 * fTemp327 / fTemp87);
			double fRec503 = fTemp89 * fTemp327 / fTemp87;
			double fTemp328 = fTemp91 * (fTemp313 - fRec505[1]) + fRec504[1];
			fRec504[0] = 2.0 * (fTemp328 / fTemp92) - fRec504[1];
			fRec505[0] = fRec505[1] + 2.0 * (fTemp91 * fTemp328 / fTemp92);
			double fRec506 = fTemp94 * fTemp328 / fTemp92;
			double fTemp329 = fTemp96 * (fTemp313 - fRec508[1]) + fRec507[1];
			fRec507[0] = 2.0 * (fTemp329 / fTemp97) - fRec507[1];
			fRec508[0] = fRec508[1] + 2.0 * (fTemp96 * fTemp329 / fTemp97);
			double fRec509 = fTemp99 * fTemp329 / fTemp97;
			double fTemp330 = fTemp101 * (fTemp313 - fRec511[1]) + fRec510[1];
			double fTemp331 = fTemp330 / fTemp102;
			fRec510[0] = 2.0 * fTemp331 - fRec510[1];
			fRec511[0] = fRec511[1] + 2.0 * (fTemp101 * fTemp330 / fTemp102);
			double fRec512 = fTemp331;
			double fTemp332 = fTemp106 * (fTemp313 - fRec514[1]) + fRec513[1];
			fRec513[0] = 2.0 * (fTemp332 / fTemp107) - fRec513[1];
			fRec514[0] = fRec514[1] + 2.0 * (fTemp106 * fTemp332 / fTemp107);
			double fRec515 = fTemp109 * fTemp332 / fTemp107;
			double fTemp333 = fTemp111 * (fTemp313 - fRec517[1]) + fRec516[1];
			fRec516[0] = 2.0 * (fTemp333 / fTemp112) - fRec516[1];
			fRec517[0] = fRec517[1] + 2.0 * (fTemp111 * fTemp333 / fTemp112);
			double fRec518 = fTemp114 * fTemp333 / fTemp112;
			double fTemp334 = fTemp116 * (fTemp313 - fRec520[1]) + fRec519[1];
			fRec519[0] = 2.0 * (fTemp334 / fTemp117) - fRec519[1];
			fRec520[0] = fRec520[1] + 2.0 * (fTemp116 * fTemp334 / fTemp117);
			double fRec521 = fTemp119 * fTemp334 / fTemp117;
			double fTemp335 = fTemp121 * (fTemp313 - fRec523[1]) + fRec522[1];
			fRec522[0] = 2.0 * (fTemp335 / fTemp122) - fRec522[1];
			fRec523[0] = fRec523[1] + 2.0 * (fTemp121 * fTemp335 / fTemp122);
			double fRec524 = fTemp124 * fTemp335 / fTemp122;
			double fTemp336 = fTemp126 * (fTemp313 - fRec526[1]) + fRec525[1];
			fRec525[0] = 2.0 * (fTemp336 / fTemp127) - fRec525[1];
			fRec526[0] = fRec526[1] + 2.0 * (fTemp126 * fTemp336 / fTemp127);
			double fRec527 = fTemp129 * fTemp336 / fTemp127;
			double fTemp337 = fTemp131 * (fTemp313 - fRec529[1]) + fRec528[1];
			fRec528[0] = 2.0 * (fTemp337 / fTemp132) - fRec528[1];
			fRec529[0] = fRec529[1] + 2.0 * (fTemp131 * fTemp337 / fTemp132);
			double fRec530 = fTemp134 * fTemp337 / fTemp132;
			double fTemp338 = fTemp136 * (fTemp313 - fRec532[1]) + fRec531[1];
			fRec531[0] = 2.0 * (fTemp338 / fTemp137) - fRec531[1];
			fRec532[0] = fRec532[1] + 2.0 * (fTemp136 * fTemp338 / fTemp137);
			double fRec533 = fTemp139 * fTemp338 / fTemp137;
			double fTemp339 = fTemp141 * (fTemp313 - fRec535[1]) + fRec534[1];
			fRec534[0] = 2.0 * (fTemp339 / fTemp142) - fRec534[1];
			fRec535[0] = fRec535[1] + 2.0 * (fTemp141 * fTemp339 / fTemp142);
			double fRec536 = fTemp144 * fTemp339 / fTemp142;
			double fTemp340 = fTemp146 * (fTemp313 - fRec538[1]) + fRec537[1];
			fRec537[0] = 2.0 * (fTemp340 / fTemp147) - fRec537[1];
			fRec538[0] = fRec538[1] + 2.0 * (fTemp146 * fTemp340 / fTemp147);
			double fRec539 = fTemp149 * fTemp340 / fTemp147;
			double fTemp341 = fTemp151 * (fTemp313 - fRec541[1]) + fRec540[1];
			fRec540[0] = 2.0 * (fTemp341 / fTemp152) - fRec540[1];
			fRec541[0] = fRec541[1] + 2.0 * (fTemp151 * fTemp341 / fTemp152);
			double fRec542 = fTemp154 * fTemp341 / fTemp152;
			double fTemp342 = fTemp156 * (fTemp313 - fRec544[1]) + fRec543[1];
			fRec543[0] = 2.0 * (fTemp342 / fTemp157) - fRec543[1];
			fRec544[0] = fRec544[1] + 2.0 * (fTemp156 * fTemp342 / fTemp157);
			double fRec545 = fTemp159 * fTemp342 / fTemp157;
			double fTemp343 = fTemp161 * (fTemp313 - fRec547[1]) + fRec546[1];
			fRec546[0] = 2.0 * (fTemp343 / fTemp162) - fRec546[1];
			fRec547[0] = fRec547[1] + 2.0 * (fTemp161 * fTemp343 / fTemp162);
			double fRec548 = fTemp164 * fTemp343 / fTemp162;
			double fTemp344 = fTemp166 * (fTemp313 - fRec550[1]) + fRec549[1];
			fRec549[0] = 2.0 * (fTemp344 / fTemp167) - fRec549[1];
			fRec550[0] = fRec550[1] + 2.0 * (fTemp166 * fTemp344 / fTemp167);
			double fRec551 = fTemp169 * fTemp344 / fTemp167;
			double fTemp345 = fTemp171 * (fTemp313 - fRec553[1]) + fRec552[1];
			fRec552[0] = 2.0 * (fTemp345 / fTemp172) - fRec552[1];
			fRec553[0] = fRec553[1] + 2.0 * (fTemp171 * fTemp345 / fTemp172);
			double fRec554 = fTemp174 * fTemp345 / fTemp172;
			double fTemp346 = fTemp176 * (fTemp313 - fRec556[1]) + fRec555[1];
			fRec555[0] = 2.0 * (fTemp346 / fTemp177) - fRec555[1];
			fRec556[0] = fRec556[1] + 2.0 * (fTemp176 * fTemp346 / fTemp177);
			double fRec557 = fTemp179 * fTemp346 / fTemp177;
			double fTemp347 = 0.03125 * fTemp180 * (fRec557 + fRec554 + fRec551 + fRec548 + fRec545 + fRec542 + fRec539 + fRec536 + fRec533 + fRec530 + fRec527 + fRec524 + fRec521 + fRec518 + fRec515 + fRec512 + fRec509 + fRec506 + fRec503 + fRec500 + fRec497 + fRec494 + fRec491 + fRec488 + fRec485 + fRec482 + fRec479 + fRec476 + fRec473 + fRec470 + fRec467 + fRec464) + fRec38[0] * fTemp313;
			fRec457[0] = std::max<double>(fConst1 * fRec457[1], std::fabs(fTemp347));
			fVbargraph20 = FAUSTFLOAT(fRec457[0]);
			fRec348[0] = fTemp347;
			double fTemp348 = fTemp8 + fRec356[1] + fTemp310;
			double fTemp349 = fRec30[0] * (fTemp266 * fTemp268 - fRec245[0] * fTemp310);
			fVec10[0] = fTemp349 + fTemp348 + fTemp223;
			fRec561[0] = fTemp349 + 0.995 * fRec561[1] + fTemp348 + (1.6 - (fVec5[1] + fVec10[1]));
			fRec560[0] = std::max<double>(fConst1 * fRec560[1], std::fabs(fRec561[0]));
			fVbargraph21 = FAUSTFLOAT(fRec560[0]);
			double fTemp350 = fRec18[0] * tanh(fRec561[0] / fTemp4);
			fRec559[0] = std::max<double>(fConst1 * fRec559[1], std::fabs(fTemp350));
			fVbargraph22 = FAUSTFLOAT(fRec559[0]);
			double fTemp351 = fTemp350;
			double fTemp352 = fTemp20 * (fTemp351 - fRec563[1]) + fRec562[1];
			fRec562[0] = 2.0 * (fTemp352 / fTemp21) - fRec562[1];
			fRec563[0] = fRec563[1] + 2.0 * (fTemp20 * fTemp352 / fTemp21);
			double fRec564 = fTemp23 * fTemp352 / fTemp21;
			double fTemp353 = fTemp25 * (fTemp351 - fRec566[1]) + fRec565[1];
			fRec565[0] = 2.0 * (fTemp353 / fTemp26) - fRec565[1];
			fRec566[0] = fRec566[1] + 2.0 * (fTemp25 * fTemp353 / fTemp26);
			double fRec567 = fTemp28 * fTemp353 / fTemp26;
			double fTemp354 = fTemp30 * (fTemp351 - fRec569[1]) + fRec568[1];
			fRec568[0] = 2.0 * (fTemp354 / fTemp31) - fRec568[1];
			fRec569[0] = fRec569[1] + 2.0 * (fTemp30 * fTemp354 / fTemp31);
			double fRec570 = fTemp33 * fTemp354 / fTemp31;
			double fTemp355 = fTemp35 * (fTemp351 - fRec572[1]) + fRec571[1];
			fRec571[0] = 2.0 * (fTemp355 / fTemp36) - fRec571[1];
			fRec572[0] = fRec572[1] + 2.0 * (fTemp35 * fTemp355 / fTemp36);
			double fRec573 = fTemp38 * fTemp355 / fTemp36;
			double fTemp356 = fTemp40 * (fTemp351 - fRec575[1]) + fRec574[1];
			fRec574[0] = 2.0 * (fTemp356 / fTemp41) - fRec574[1];
			fRec575[0] = fRec575[1] + 2.0 * (fTemp40 * fTemp356 / fTemp41);
			double fRec576 = fTemp43 * fTemp356 / fTemp41;
			double fTemp357 = fTemp45 * (fTemp351 - fRec578[1]) + fRec577[1];
			fRec577[0] = 2.0 * (fTemp357 / fTemp46) - fRec577[1];
			fRec578[0] = fRec578[1] + 2.0 * (fTemp45 * fTemp357 / fTemp46);
			double fRec579 = fTemp48 * fTemp357 / fTemp46;
			double fTemp358 = fTemp50 * (fTemp351 - fRec581[1]) + fRec580[1];
			fRec580[0] = 2.0 * (fTemp358 / fTemp51) - fRec580[1];
			fRec581[0] = fRec581[1] + 2.0 * (fTemp50 * fTemp358 / fTemp51);
			double fRec582 = fTemp53 * fTemp358 / fTemp51;
			double fTemp359 = fTemp55 * (fTemp351 - fRec584[1]) + fRec583[1];
			fRec583[0] = 2.0 * (fTemp359 / fTemp56) - fRec583[1];
			fRec584[0] = fRec584[1] + 2.0 * (fTemp55 * fTemp359 / fTemp56);
			double fRec585 = fTemp58 * fTemp359 / fTemp56;
			double fTemp360 = fTemp60 * (fTemp351 - fRec587[1]) + fRec586[1];
			fRec586[0] = 2.0 * (fTemp360 / fTemp61) - fRec586[1];
			fRec587[0] = fRec587[1] + 2.0 * (fTemp60 * fTemp360 / fTemp61);
			double fRec588 = fTemp63 * fTemp360 / fTemp61;
			double fTemp361 = fTemp65 * (fTemp351 - fRec590[1]) + fRec589[1];
			fRec589[0] = 2.0 * (fTemp361 / fTemp66) - fRec589[1];
			fRec590[0] = fRec590[1] + 2.0 * (fTemp65 * fTemp361 / fTemp66);
			double fRec591 = fTemp68 * fTemp361 / fTemp66;
			double fTemp362 = fTemp71 * (fTemp351 - fRec593[1]) + fRec592[1];
			fRec592[0] = 2.0 * (fTemp362 / fTemp72) - fRec592[1];
			fRec593[0] = fRec593[1] + 2.0 * (fTemp71 * fTemp362 / fTemp72);
			double fRec594 = fTemp74 * fTemp362 / fTemp72;
			double fTemp363 = fTemp76 * (fTemp351 - fRec596[1]) + fRec595[1];
			fRec595[0] = 2.0 * (fTemp363 / fTemp77) - fRec595[1];
			fRec596[0] = fRec596[1] + 2.0 * (fTemp76 * fTemp363 / fTemp77);
			double fRec597 = fTemp79 * fTemp363 / fTemp77;
			double fTemp364 = fTemp81 * (fTemp351 - fRec599[1]) + fRec598[1];
			fRec598[0] = 2.0 * (fTemp364 / fTemp82) - fRec598[1];
			fRec599[0] = fRec599[1] + 2.0 * (fTemp81 * fTemp364 / fTemp82);
			double fRec600 = fTemp84 * fTemp364 / fTemp82;
			double fTemp365 = fTemp86 * (fTemp351 - fRec602[1]) + fRec601[1];
			fRec601[0] = 2.0 * (fTemp365 / fTemp87) - fRec601[1];
			fRec602[0] = fRec602[1] + 2.0 * (fTemp86 * fTemp365 / fTemp87);
			double fRec603 = fTemp89 * fTemp365 / fTemp87;
			double fTemp366 = fTemp91 * (fTemp351 - fRec605[1]) + fRec604[1];
			fRec604[0] = 2.0 * (fTemp366 / fTemp92) - fRec604[1];
			fRec605[0] = fRec605[1] + 2.0 * (fTemp91 * fTemp366 / fTemp92);
			double fRec606 = fTemp94 * fTemp366 / fTemp92;
			double fTemp367 = fTemp96 * (fTemp351 - fRec608[1]) + fRec607[1];
			fRec607[0] = 2.0 * (fTemp367 / fTemp97) - fRec607[1];
			fRec608[0] = fRec608[1] + 2.0 * (fTemp96 * fTemp367 / fTemp97);
			double fRec609 = fTemp99 * fTemp367 / fTemp97;
			double fTemp368 = fTemp101 * (fTemp351 - fRec611[1]) + fRec610[1];
			double fTemp369 = fTemp368 / fTemp102;
			fRec610[0] = 2.0 * fTemp369 - fRec610[1];
			fRec611[0] = fRec611[1] + 2.0 * (fTemp101 * fTemp368 / fTemp102);
			double fRec612 = fTemp369;
			double fTemp370 = fTemp106 * (fTemp351 - fRec614[1]) + fRec613[1];
			fRec613[0] = 2.0 * (fTemp370 / fTemp107) - fRec613[1];
			fRec614[0] = fRec614[1] + 2.0 * (fTemp106 * fTemp370 / fTemp107);
			double fRec615 = fTemp109 * fTemp370 / fTemp107;
			double fTemp371 = fTemp111 * (fTemp351 - fRec617[1]) + fRec616[1];
			fRec616[0] = 2.0 * (fTemp371 / fTemp112) - fRec616[1];
			fRec617[0] = fRec617[1] + 2.0 * (fTemp111 * fTemp371 / fTemp112);
			double fRec618 = fTemp114 * fTemp371 / fTemp112;
			double fTemp372 = fTemp116 * (fTemp351 - fRec620[1]) + fRec619[1];
			fRec619[0] = 2.0 * (fTemp372 / fTemp117) - fRec619[1];
			fRec620[0] = fRec620[1] + 2.0 * (fTemp116 * fTemp372 / fTemp117);
			double fRec621 = fTemp119 * fTemp372 / fTemp117;
			double fTemp373 = fTemp121 * (fTemp351 - fRec623[1]) + fRec622[1];
			fRec622[0] = 2.0 * (fTemp373 / fTemp122) - fRec622[1];
			fRec623[0] = fRec623[1] + 2.0 * (fTemp121 * fTemp373 / fTemp122);
			double fRec624 = fTemp124 * fTemp373 / fTemp122;
			double fTemp374 = fTemp126 * (fTemp351 - fRec626[1]) + fRec625[1];
			fRec625[0] = 2.0 * (fTemp374 / fTemp127) - fRec625[1];
			fRec626[0] = fRec626[1] + 2.0 * (fTemp126 * fTemp374 / fTemp127);
			double fRec627 = fTemp129 * fTemp374 / fTemp127;
			double fTemp375 = fTemp131 * (fTemp351 - fRec629[1]) + fRec628[1];
			fRec628[0] = 2.0 * (fTemp375 / fTemp132) - fRec628[1];
			fRec629[0] = fRec629[1] + 2.0 * (fTemp131 * fTemp375 / fTemp132);
			double fRec630 = fTemp134 * fTemp375 / fTemp132;
			double fTemp376 = fTemp136 * (fTemp351 - fRec632[1]) + fRec631[1];
			fRec631[0] = 2.0 * (fTemp376 / fTemp137) - fRec631[1];
			fRec632[0] = fRec632[1] + 2.0 * (fTemp136 * fTemp376 / fTemp137);
			double fRec633 = fTemp139 * fTemp376 / fTemp137;
			double fTemp377 = fTemp141 * (fTemp351 - fRec635[1]) + fRec634[1];
			fRec634[0] = 2.0 * (fTemp377 / fTemp142) - fRec634[1];
			fRec635[0] = fRec635[1] + 2.0 * (fTemp141 * fTemp377 / fTemp142);
			double fRec636 = fTemp144 * fTemp377 / fTemp142;
			double fTemp378 = fTemp146 * (fTemp351 - fRec638[1]) + fRec637[1];
			fRec637[0] = 2.0 * (fTemp378 / fTemp147) - fRec637[1];
			fRec638[0] = fRec638[1] + 2.0 * (fTemp146 * fTemp378 / fTemp147);
			double fRec639 = fTemp149 * fTemp378 / fTemp147;
			double fTemp379 = fTemp151 * (fTemp351 - fRec641[1]) + fRec640[1];
			fRec640[0] = 2.0 * (fTemp379 / fTemp152) - fRec640[1];
			fRec641[0] = fRec641[1] + 2.0 * (fTemp151 * fTemp379 / fTemp152);
			double fRec642 = fTemp154 * fTemp379 / fTemp152;
			double fTemp380 = fTemp156 * (fTemp351 - fRec644[1]) + fRec643[1];
			fRec643[0] = 2.0 * (fTemp380 / fTemp157) - fRec643[1];
			fRec644[0] = fRec644[1] + 2.0 * (fTemp156 * fTemp380 / fTemp157);
			double fRec645 = fTemp159 * fTemp380 / fTemp157;
			double fTemp381 = fTemp161 * (fTemp351 - fRec647[1]) + fRec646[1];
			fRec646[0] = 2.0 * (fTemp381 / fTemp162) - fRec646[1];
			fRec647[0] = fRec647[1] + 2.0 * (fTemp161 * fTemp381 / fTemp162);
			double fRec648 = fTemp164 * fTemp381 / fTemp162;
			double fTemp382 = fTemp166 * (fTemp351 - fRec650[1]) + fRec649[1];
			fRec649[0] = 2.0 * (fTemp382 / fTemp167) - fRec649[1];
			fRec650[0] = fRec650[1] + 2.0 * (fTemp166 * fTemp382 / fTemp167);
			double fRec651 = fTemp169 * fTemp382 / fTemp167;
			double fTemp383 = fTemp171 * (fTemp351 - fRec653[1]) + fRec652[1];
			fRec652[0] = 2.0 * (fTemp383 / fTemp172) - fRec652[1];
			fRec653[0] = fRec653[1] + 2.0 * (fTemp171 * fTemp383 / fTemp172);
			double fRec654 = fTemp174 * fTemp383 / fTemp172;
			double fTemp384 = fTemp176 * (fTemp351 - fRec656[1]) + fRec655[1];
			fRec655[0] = 2.0 * (fTemp384 / fTemp177) - fRec655[1];
			fRec656[0] = fRec656[1] + 2.0 * (fTemp176 * fTemp384 / fTemp177);
			double fRec657 = fTemp179 * fTemp384 / fTemp177;
			double fTemp385 = 0.03125 * fTemp180 * (fRec657 + fRec654 + fRec651 + fRec648 + fRec645 + fRec642 + fRec639 + fRec636 + fRec633 + fRec630 + fRec627 + fRec624 + fRec621 + fRec618 + fRec615 + fRec612 + fRec609 + fRec606 + fRec603 + fRec600 + fRec597 + fRec594 + fRec591 + fRec588 + fRec585 + fRec582 + fRec579 + fRec576 + fRec573 + fRec570 + fRec567 + fRec564) + fRec38[0] * fTemp351;
			fRec558[0] = std::max<double>(fConst1 * fRec558[1], std::fabs(fTemp385));
			fVbargraph23 = FAUSTFLOAT(fRec558[0]);
			fRec349[0] = fTemp385;
			double fTemp386 = (fRec349[0] + fRec347[0] + fRec348[0]) / fTemp4;
			fVec11[IOTA0 & 4194303] = fTemp386;
			double fTemp387 = ((fRec658[1] != 0.0) ? (((fRec659[1] > 0.0) & (fRec659[1] < 1.0)) ? fRec658[1] : 0.0) : (((fRec659[1] == 0.0) & (fSlow21 != fRec660[1])) ? 0.0009765625 : (((fRec659[1] == 1.0) & (fSlow21 != fRec661[1])) ? -0.0009765625 : 0.0)));
			fRec658[0] = fTemp387;
			fRec659[0] = std::max<double>(0.0, std::min<double>(1.0, fRec659[1] + fTemp387));
			fRec660[0] = (((fRec659[1] >= 1.0) & (fRec661[1] != fSlow21)) ? fSlow21 : fRec660[1]);
			fRec661[0] = (((fRec659[1] <= 0.0) & (fRec660[1] != fSlow21)) ? fSlow21 : fRec661[1]);
			double fTemp388 = fVec11[(IOTA0 - int(std::min<double>(fConst5, std::max<double>(0.0, fRec660[0])))) & 4194303];
			fRec346[0] = 0.3333333333333333 * fTemp388 + fRec659[0] * (0.0 - 0.3333333333333333 * (fTemp388 - fVec11[(IOTA0 - int(std::min<double>(fConst5, std::max<double>(0.0, fRec661[0])))) & 4194303]));
			double fTemp389 = ((fRec674[1] != 0.0) ? (((fRec675[1] > 0.0) & (fRec675[1] < 1.0)) ? fRec674[1] : 0.0) : (((fRec675[1] == 0.0) & (fSlow22 != fRec676[1])) ? 0.0009765625 : (((fRec675[1] == 1.0) & (fSlow22 != fRec677[1])) ? -0.0009765625 : 0.0)));
			fRec674[0] = fTemp389;
			fRec675[0] = std::max<double>(0.0, std::min<double>(1.0, fRec675[1] + fTemp389));
			fRec676[0] = (((fRec675[1] >= 1.0) & (fRec677[1] != fSlow22)) ? fSlow22 : fRec676[1]);
			fRec677[0] = (((fRec675[1] <= 0.0) & (fRec676[1] != fSlow22)) ? fSlow22 : fRec677[1]);
			double fTemp390 = fVec1[(IOTA0 - int(std::min<double>(fConst5, std::max<double>(0.0, fRec676[0])))) & 4194303];
			fRec673[0] = fTemp390 + fRec675[0] * (fVec1[(IOTA0 - int(std::min<double>(fConst5, std::max<double>(0.0, fRec677[0])))) & 4194303] - fTemp390);
			double fTemp391 = fRec27[0] * fRec663[1];
			fRec678[0] = std::max<double>(fConst1 * fRec678[1], std::fabs(fTemp391));
			fVbargraph24 = FAUSTFLOAT(fRec678[0]);
			double fTemp392 = fTemp391;
			double fTemp393 = fRec27[0] * fRec664[1];
			fRec679[0] = std::max<double>(fConst1 * fRec679[1], std::fabs(fTemp393));
			fVbargraph25 = FAUSTFLOAT(fRec679[0]);
			double fTemp394 = fTemp393;
			double fTemp395 = fTemp11 * (fTemp394 - fTemp392);
			fVec12[0] = fTemp8 + fTemp392 + fTemp395 + fRec673[1] + fTemp5;
			fRec672[0] = fTemp8 + fRec673[1] + fTemp395 + 0.995 * fRec672[1] + fTemp392 + (1.2 - (fVec0[1] + fVec12[1]));
			fRec671[0] = std::max<double>(fConst1 * fRec671[1], std::fabs(fRec672[0]));
			fVbargraph26 = FAUSTFLOAT(fRec671[0]);
			double fTemp396 = fRec18[0] * tanh(fRec672[0] / fTemp4);
			fRec670[0] = std::max<double>(fConst1 * fRec670[1], std::fabs(fTemp396));
			fVbargraph27 = FAUSTFLOAT(fRec670[0]);
			double fTemp397 = fTemp396;
			double fTemp398 = fTemp20 * (fTemp397 - fRec668[1]) + fRec667[1];
			fRec667[0] = 2.0 * (fTemp398 / fTemp21) - fRec667[1];
			fRec668[0] = fRec668[1] + 2.0 * (fTemp20 * fTemp398 / fTemp21);
			double fRec669 = fTemp398 * fTemp23 / fTemp21;
			double fTemp399 = fTemp25 * (fTemp397 - fRec681[1]) + fRec680[1];
			fRec680[0] = 2.0 * (fTemp399 / fTemp26) - fRec680[1];
			fRec681[0] = fRec681[1] + 2.0 * (fTemp25 * fTemp399 / fTemp26);
			double fRec682 = fTemp399 * fTemp28 / fTemp26;
			double fTemp400 = fTemp30 * (fTemp397 - fRec684[1]) + fRec683[1];
			fRec683[0] = 2.0 * (fTemp400 / fTemp31) - fRec683[1];
			fRec684[0] = fRec684[1] + 2.0 * (fTemp30 * fTemp400 / fTemp31);
			double fRec685 = fTemp400 * fTemp33 / fTemp31;
			double fTemp401 = fTemp35 * (fTemp397 - fRec687[1]) + fRec686[1];
			fRec686[0] = 2.0 * (fTemp401 / fTemp36) - fRec686[1];
			fRec687[0] = fRec687[1] + 2.0 * (fTemp35 * fTemp401 / fTemp36);
			double fRec688 = fTemp401 * fTemp38 / fTemp36;
			double fTemp402 = fTemp40 * (fTemp397 - fRec690[1]) + fRec689[1];
			fRec689[0] = 2.0 * (fTemp402 / fTemp41) - fRec689[1];
			fRec690[0] = fRec690[1] + 2.0 * (fTemp40 * fTemp402 / fTemp41);
			double fRec691 = fTemp402 * fTemp43 / fTemp41;
			double fTemp403 = fTemp45 * (fTemp397 - fRec693[1]) + fRec692[1];
			fRec692[0] = 2.0 * (fTemp403 / fTemp46) - fRec692[1];
			fRec693[0] = fRec693[1] + 2.0 * (fTemp45 * fTemp403 / fTemp46);
			double fRec694 = fTemp403 * fTemp48 / fTemp46;
			double fTemp404 = fTemp50 * (fTemp397 - fRec696[1]) + fRec695[1];
			fRec695[0] = 2.0 * (fTemp404 / fTemp51) - fRec695[1];
			fRec696[0] = fRec696[1] + 2.0 * (fTemp50 * fTemp404 / fTemp51);
			double fRec697 = fTemp404 * fTemp53 / fTemp51;
			double fTemp405 = fTemp55 * (fTemp397 - fRec699[1]) + fRec698[1];
			fRec698[0] = 2.0 * (fTemp405 / fTemp56) - fRec698[1];
			fRec699[0] = fRec699[1] + 2.0 * (fTemp55 * fTemp405 / fTemp56);
			double fRec700 = fTemp405 * fTemp58 / fTemp56;
			double fTemp406 = fTemp60 * (fTemp397 - fRec702[1]) + fRec701[1];
			fRec701[0] = 2.0 * (fTemp406 / fTemp61) - fRec701[1];
			fRec702[0] = fRec702[1] + 2.0 * (fTemp60 * fTemp406 / fTemp61);
			double fRec703 = fTemp406 * fTemp63 / fTemp61;
			double fTemp407 = fTemp65 * (fTemp397 - fRec705[1]) + fRec704[1];
			fRec704[0] = 2.0 * (fTemp407 / fTemp66) - fRec704[1];
			fRec705[0] = fRec705[1] + 2.0 * (fTemp65 * fTemp407 / fTemp66);
			double fRec706 = fTemp407 * fTemp68 / fTemp66;
			double fTemp408 = fTemp71 * (fTemp397 - fRec708[1]) + fRec707[1];
			fRec707[0] = 2.0 * (fTemp408 / fTemp72) - fRec707[1];
			fRec708[0] = fRec708[1] + 2.0 * (fTemp71 * fTemp408 / fTemp72);
			double fRec709 = fTemp408 * fTemp74 / fTemp72;
			double fTemp409 = fTemp76 * (fTemp397 - fRec711[1]) + fRec710[1];
			fRec710[0] = 2.0 * (fTemp409 / fTemp77) - fRec710[1];
			fRec711[0] = fRec711[1] + 2.0 * (fTemp76 * fTemp409 / fTemp77);
			double fRec712 = fTemp409 * fTemp79 / fTemp77;
			double fTemp410 = fTemp81 * (fTemp397 - fRec714[1]) + fRec713[1];
			fRec713[0] = 2.0 * (fTemp410 / fTemp82) - fRec713[1];
			fRec714[0] = fRec714[1] + 2.0 * (fTemp81 * fTemp410 / fTemp82);
			double fRec715 = fTemp410 * fTemp84 / fTemp82;
			double fTemp411 = fTemp86 * (fTemp397 - fRec717[1]) + fRec716[1];
			fRec716[0] = 2.0 * (fTemp411 / fTemp87) - fRec716[1];
			fRec717[0] = fRec717[1] + 2.0 * (fTemp86 * fTemp411 / fTemp87);
			double fRec718 = fTemp411 * fTemp89 / fTemp87;
			double fTemp412 = fTemp91 * (fTemp397 - fRec720[1]) + fRec719[1];
			fRec719[0] = 2.0 * (fTemp412 / fTemp92) - fRec719[1];
			fRec720[0] = fRec720[1] + 2.0 * (fTemp91 * fTemp412 / fTemp92);
			double fRec721 = fTemp412 * fTemp94 / fTemp92;
			double fTemp413 = fTemp96 * (fTemp397 - fRec723[1]) + fRec722[1];
			fRec722[0] = 2.0 * (fTemp413 / fTemp97) - fRec722[1];
			fRec723[0] = fRec723[1] + 2.0 * (fTemp96 * fTemp413 / fTemp97);
			double fRec724 = fTemp413 * fTemp99 / fTemp97;
			double fTemp414 = fTemp101 * (fTemp397 - fRec726[1]) + fRec725[1];
			double fTemp415 = fTemp414 / fTemp102;
			fRec725[0] = 2.0 * fTemp415 - fRec725[1];
			fRec726[0] = fRec726[1] + 2.0 * (fTemp101 * fTemp414 / fTemp102);
			double fRec727 = fTemp415;
			double fTemp416 = fTemp106 * (fTemp397 - fRec729[1]) + fRec728[1];
			fRec728[0] = 2.0 * (fTemp416 / fTemp107) - fRec728[1];
			fRec729[0] = fRec729[1] + 2.0 * (fTemp106 * fTemp416 / fTemp107);
			double fRec730 = fTemp416 * fTemp109 / fTemp107;
			double fTemp417 = fTemp111 * (fTemp397 - fRec732[1]) + fRec731[1];
			fRec731[0] = 2.0 * (fTemp417 / fTemp112) - fRec731[1];
			fRec732[0] = fRec732[1] + 2.0 * (fTemp111 * fTemp417 / fTemp112);
			double fRec733 = fTemp417 * fTemp114 / fTemp112;
			double fTemp418 = fTemp116 * (fTemp397 - fRec735[1]) + fRec734[1];
			fRec734[0] = 2.0 * (fTemp418 / fTemp117) - fRec734[1];
			fRec735[0] = fRec735[1] + 2.0 * (fTemp116 * fTemp418 / fTemp117);
			double fRec736 = fTemp418 * fTemp119 / fTemp117;
			double fTemp419 = fTemp121 * (fTemp397 - fRec738[1]) + fRec737[1];
			fRec737[0] = 2.0 * (fTemp419 / fTemp122) - fRec737[1];
			fRec738[0] = fRec738[1] + 2.0 * (fTemp121 * fTemp419 / fTemp122);
			double fRec739 = fTemp419 * fTemp124 / fTemp122;
			double fTemp420 = fTemp126 * (fTemp397 - fRec741[1]) + fRec740[1];
			fRec740[0] = 2.0 * (fTemp420 / fTemp127) - fRec740[1];
			fRec741[0] = fRec741[1] + 2.0 * (fTemp126 * fTemp420 / fTemp127);
			double fRec742 = fTemp420 * fTemp129 / fTemp127;
			double fTemp421 = fTemp131 * (fTemp397 - fRec744[1]) + fRec743[1];
			fRec743[0] = 2.0 * (fTemp421 / fTemp132) - fRec743[1];
			fRec744[0] = fRec744[1] + 2.0 * (fTemp131 * fTemp421 / fTemp132);
			double fRec745 = fTemp421 * fTemp134 / fTemp132;
			double fTemp422 = fTemp136 * (fTemp397 - fRec747[1]) + fRec746[1];
			fRec746[0] = 2.0 * (fTemp422 / fTemp137) - fRec746[1];
			fRec747[0] = fRec747[1] + 2.0 * (fTemp136 * fTemp422 / fTemp137);
			double fRec748 = fTemp422 * fTemp139 / fTemp137;
			double fTemp423 = fTemp141 * (fTemp397 - fRec750[1]) + fRec749[1];
			fRec749[0] = 2.0 * (fTemp423 / fTemp142) - fRec749[1];
			fRec750[0] = fRec750[1] + 2.0 * (fTemp141 * fTemp423 / fTemp142);
			double fRec751 = fTemp423 * fTemp144 / fTemp142;
			double fTemp424 = fTemp146 * (fTemp397 - fRec753[1]) + fRec752[1];
			fRec752[0] = 2.0 * (fTemp424 / fTemp147) - fRec752[1];
			fRec753[0] = fRec753[1] + 2.0 * (fTemp146 * fTemp424 / fTemp147);
			double fRec754 = fTemp424 * fTemp149 / fTemp147;
			double fTemp425 = fTemp151 * (fTemp397 - fRec756[1]) + fRec755[1];
			fRec755[0] = 2.0 * (fTemp425 / fTemp152) - fRec755[1];
			fRec756[0] = fRec756[1] + 2.0 * (fTemp151 * fTemp425 / fTemp152);
			double fRec757 = fTemp425 * fTemp154 / fTemp152;
			double fTemp426 = fTemp156 * (fTemp397 - fRec759[1]) + fRec758[1];
			fRec758[0] = 2.0 * (fTemp426 / fTemp157) - fRec758[1];
			fRec759[0] = fRec759[1] + 2.0 * (fTemp156 * fTemp426 / fTemp157);
			double fRec760 = fTemp426 * fTemp159 / fTemp157;
			double fTemp427 = fTemp161 * (fTemp397 - fRec762[1]) + fRec761[1];
			fRec761[0] = 2.0 * (fTemp427 / fTemp162) - fRec761[1];
			fRec762[0] = fRec762[1] + 2.0 * (fTemp161 * fTemp427 / fTemp162);
			double fRec763 = fTemp427 * fTemp164 / fTemp162;
			double fTemp428 = fTemp166 * (fTemp397 - fRec765[1]) + fRec764[1];
			fRec764[0] = 2.0 * (fTemp428 / fTemp167) - fRec764[1];
			fRec765[0] = fRec765[1] + 2.0 * (fTemp166 * fTemp428 / fTemp167);
			double fRec766 = fTemp428 * fTemp169 / fTemp167;
			double fTemp429 = fTemp171 * (fTemp397 - fRec768[1]) + fRec767[1];
			fRec767[0] = 2.0 * (fTemp429 / fTemp172) - fRec767[1];
			fRec768[0] = fRec768[1] + 2.0 * (fTemp171 * fTemp429 / fTemp172);
			double fRec769 = fTemp429 * fTemp174 / fTemp172;
			double fTemp430 = fTemp176 * (fTemp397 - fRec771[1]) + fRec770[1];
			fRec770[0] = 2.0 * (fTemp430 / fTemp177) - fRec770[1];
			fRec771[0] = fRec771[1] + 2.0 * (fTemp176 * fTemp430 / fTemp177);
			double fRec772 = fTemp430 * fTemp179 / fTemp177;
			double fTemp431 = fTemp397 * fRec38[0] + 0.03125 * fTemp180 * (fRec772 + fRec769 + fRec766 + fRec763 + fRec760 + fRec757 + fRec754 + fRec751 + fRec748 + fRec745 + fRec742 + fRec739 + fRec736 + fRec733 + fRec730 + fRec727 + fRec724 + fRec721 + fRec718 + fRec715 + fRec712 + fRec709 + fRec706 + fRec703 + fRec700 + fRec697 + fRec694 + fRec691 + fRec688 + fRec685 + fRec682 + fRec669);
			fRec666[0] = std::max<double>(fConst1 * fRec666[1], std::fabs(fTemp431));
			fVbargraph28 = FAUSTFLOAT(fRec666[0]);
			fRec663[0] = fTemp431;
			double fTemp432 = fTemp8 + fTemp394 + fRec673[1];
			double fTemp433 = fRec27[0] * fRec665[1];
			fRec777[0] = std::max<double>(fConst1 * fRec777[1], std::fabs(fTemp433));
			fVbargraph29 = FAUSTFLOAT(fRec777[0]);
			double fTemp434 = fTemp433;
			double fTemp435 = fRec30[0] * (fTemp392 * (fRec144[0] - fTemp434) - fTemp394);
			fVec13[0] = fTemp435 + fTemp432 + fTemp182;
			fRec776[0] = fTemp435 + 0.995 * fRec776[1] + fTemp432 + (1.3 - (fVec3[1] + fVec13[1]));
			fRec775[0] = std::max<double>(fConst1 * fRec775[1], std::fabs(fRec776[0]));
			fVbargraph30 = FAUSTFLOAT(fRec775[0]);
			double fTemp436 = fRec18[0] * tanh(fRec776[0] / fTemp4);
			fRec774[0] = std::max<double>(fConst1 * fRec774[1], std::fabs(fTemp436));
			fVbargraph31 = FAUSTFLOAT(fRec774[0]);
			double fTemp437 = fTemp436;
			double fTemp438 = fTemp20 * (fTemp437 - fRec779[1]) + fRec778[1];
			fRec778[0] = 2.0 * (fTemp438 / fTemp21) - fRec778[1];
			fRec779[0] = fRec779[1] + 2.0 * (fTemp20 * fTemp438 / fTemp21);
			double fRec780 = fTemp23 * fTemp438 / fTemp21;
			double fTemp439 = fTemp25 * (fTemp437 - fRec782[1]) + fRec781[1];
			fRec781[0] = 2.0 * (fTemp439 / fTemp26) - fRec781[1];
			fRec782[0] = fRec782[1] + 2.0 * (fTemp25 * fTemp439 / fTemp26);
			double fRec783 = fTemp28 * fTemp439 / fTemp26;
			double fTemp440 = fTemp30 * (fTemp437 - fRec785[1]) + fRec784[1];
			fRec784[0] = 2.0 * (fTemp440 / fTemp31) - fRec784[1];
			fRec785[0] = fRec785[1] + 2.0 * (fTemp30 * fTemp440 / fTemp31);
			double fRec786 = fTemp33 * fTemp440 / fTemp31;
			double fTemp441 = fTemp35 * (fTemp437 - fRec788[1]) + fRec787[1];
			fRec787[0] = 2.0 * (fTemp441 / fTemp36) - fRec787[1];
			fRec788[0] = fRec788[1] + 2.0 * (fTemp35 * fTemp441 / fTemp36);
			double fRec789 = fTemp38 * fTemp441 / fTemp36;
			double fTemp442 = fTemp40 * (fTemp437 - fRec791[1]) + fRec790[1];
			fRec790[0] = 2.0 * (fTemp442 / fTemp41) - fRec790[1];
			fRec791[0] = fRec791[1] + 2.0 * (fTemp40 * fTemp442 / fTemp41);
			double fRec792 = fTemp43 * fTemp442 / fTemp41;
			double fTemp443 = fTemp45 * (fTemp437 - fRec794[1]) + fRec793[1];
			fRec793[0] = 2.0 * (fTemp443 / fTemp46) - fRec793[1];
			fRec794[0] = fRec794[1] + 2.0 * (fTemp45 * fTemp443 / fTemp46);
			double fRec795 = fTemp48 * fTemp443 / fTemp46;
			double fTemp444 = fTemp50 * (fTemp437 - fRec797[1]) + fRec796[1];
			fRec796[0] = 2.0 * (fTemp444 / fTemp51) - fRec796[1];
			fRec797[0] = fRec797[1] + 2.0 * (fTemp50 * fTemp444 / fTemp51);
			double fRec798 = fTemp53 * fTemp444 / fTemp51;
			double fTemp445 = fTemp55 * (fTemp437 - fRec800[1]) + fRec799[1];
			fRec799[0] = 2.0 * (fTemp445 / fTemp56) - fRec799[1];
			fRec800[0] = fRec800[1] + 2.0 * (fTemp55 * fTemp445 / fTemp56);
			double fRec801 = fTemp58 * fTemp445 / fTemp56;
			double fTemp446 = fTemp60 * (fTemp437 - fRec803[1]) + fRec802[1];
			fRec802[0] = 2.0 * (fTemp446 / fTemp61) - fRec802[1];
			fRec803[0] = fRec803[1] + 2.0 * (fTemp60 * fTemp446 / fTemp61);
			double fRec804 = fTemp63 * fTemp446 / fTemp61;
			double fTemp447 = fTemp65 * (fTemp437 - fRec806[1]) + fRec805[1];
			fRec805[0] = 2.0 * (fTemp447 / fTemp66) - fRec805[1];
			fRec806[0] = fRec806[1] + 2.0 * (fTemp65 * fTemp447 / fTemp66);
			double fRec807 = fTemp68 * fTemp447 / fTemp66;
			double fTemp448 = fTemp71 * (fTemp437 - fRec809[1]) + fRec808[1];
			fRec808[0] = 2.0 * (fTemp448 / fTemp72) - fRec808[1];
			fRec809[0] = fRec809[1] + 2.0 * (fTemp71 * fTemp448 / fTemp72);
			double fRec810 = fTemp74 * fTemp448 / fTemp72;
			double fTemp449 = fTemp76 * (fTemp437 - fRec812[1]) + fRec811[1];
			fRec811[0] = 2.0 * (fTemp449 / fTemp77) - fRec811[1];
			fRec812[0] = fRec812[1] + 2.0 * (fTemp76 * fTemp449 / fTemp77);
			double fRec813 = fTemp79 * fTemp449 / fTemp77;
			double fTemp450 = fTemp81 * (fTemp437 - fRec815[1]) + fRec814[1];
			fRec814[0] = 2.0 * (fTemp450 / fTemp82) - fRec814[1];
			fRec815[0] = fRec815[1] + 2.0 * (fTemp81 * fTemp450 / fTemp82);
			double fRec816 = fTemp84 * fTemp450 / fTemp82;
			double fTemp451 = fTemp86 * (fTemp437 - fRec818[1]) + fRec817[1];
			fRec817[0] = 2.0 * (fTemp451 / fTemp87) - fRec817[1];
			fRec818[0] = fRec818[1] + 2.0 * (fTemp86 * fTemp451 / fTemp87);
			double fRec819 = fTemp89 * fTemp451 / fTemp87;
			double fTemp452 = fTemp91 * (fTemp437 - fRec821[1]) + fRec820[1];
			fRec820[0] = 2.0 * (fTemp452 / fTemp92) - fRec820[1];
			fRec821[0] = fRec821[1] + 2.0 * (fTemp91 * fTemp452 / fTemp92);
			double fRec822 = fTemp94 * fTemp452 / fTemp92;
			double fTemp453 = fTemp96 * (fTemp437 - fRec824[1]) + fRec823[1];
			fRec823[0] = 2.0 * (fTemp453 / fTemp97) - fRec823[1];
			fRec824[0] = fRec824[1] + 2.0 * (fTemp96 * fTemp453 / fTemp97);
			double fRec825 = fTemp99 * fTemp453 / fTemp97;
			double fTemp454 = fTemp101 * (fTemp437 - fRec827[1]) + fRec826[1];
			double fTemp455 = fTemp454 / fTemp102;
			fRec826[0] = 2.0 * fTemp455 - fRec826[1];
			fRec827[0] = fRec827[1] + 2.0 * (fTemp101 * fTemp454 / fTemp102);
			double fRec828 = fTemp455;
			double fTemp456 = fTemp106 * (fTemp437 - fRec830[1]) + fRec829[1];
			fRec829[0] = 2.0 * (fTemp456 / fTemp107) - fRec829[1];
			fRec830[0] = fRec830[1] + 2.0 * (fTemp106 * fTemp456 / fTemp107);
			double fRec831 = fTemp109 * fTemp456 / fTemp107;
			double fTemp457 = fTemp111 * (fTemp437 - fRec833[1]) + fRec832[1];
			fRec832[0] = 2.0 * (fTemp457 / fTemp112) - fRec832[1];
			fRec833[0] = fRec833[1] + 2.0 * (fTemp111 * fTemp457 / fTemp112);
			double fRec834 = fTemp114 * fTemp457 / fTemp112;
			double fTemp458 = fTemp116 * (fTemp437 - fRec836[1]) + fRec835[1];
			fRec835[0] = 2.0 * (fTemp458 / fTemp117) - fRec835[1];
			fRec836[0] = fRec836[1] + 2.0 * (fTemp116 * fTemp458 / fTemp117);
			double fRec837 = fTemp119 * fTemp458 / fTemp117;
			double fTemp459 = fTemp121 * (fTemp437 - fRec839[1]) + fRec838[1];
			fRec838[0] = 2.0 * (fTemp459 / fTemp122) - fRec838[1];
			fRec839[0] = fRec839[1] + 2.0 * (fTemp121 * fTemp459 / fTemp122);
			double fRec840 = fTemp124 * fTemp459 / fTemp122;
			double fTemp460 = fTemp126 * (fTemp437 - fRec842[1]) + fRec841[1];
			fRec841[0] = 2.0 * (fTemp460 / fTemp127) - fRec841[1];
			fRec842[0] = fRec842[1] + 2.0 * (fTemp126 * fTemp460 / fTemp127);
			double fRec843 = fTemp129 * fTemp460 / fTemp127;
			double fTemp461 = fTemp131 * (fTemp437 - fRec845[1]) + fRec844[1];
			fRec844[0] = 2.0 * (fTemp461 / fTemp132) - fRec844[1];
			fRec845[0] = fRec845[1] + 2.0 * (fTemp131 * fTemp461 / fTemp132);
			double fRec846 = fTemp134 * fTemp461 / fTemp132;
			double fTemp462 = fTemp136 * (fTemp437 - fRec848[1]) + fRec847[1];
			fRec847[0] = 2.0 * (fTemp462 / fTemp137) - fRec847[1];
			fRec848[0] = fRec848[1] + 2.0 * (fTemp136 * fTemp462 / fTemp137);
			double fRec849 = fTemp139 * fTemp462 / fTemp137;
			double fTemp463 = fTemp141 * (fTemp437 - fRec851[1]) + fRec850[1];
			fRec850[0] = 2.0 * (fTemp463 / fTemp142) - fRec850[1];
			fRec851[0] = fRec851[1] + 2.0 * (fTemp141 * fTemp463 / fTemp142);
			double fRec852 = fTemp144 * fTemp463 / fTemp142;
			double fTemp464 = fTemp146 * (fTemp437 - fRec854[1]) + fRec853[1];
			fRec853[0] = 2.0 * (fTemp464 / fTemp147) - fRec853[1];
			fRec854[0] = fRec854[1] + 2.0 * (fTemp146 * fTemp464 / fTemp147);
			double fRec855 = fTemp149 * fTemp464 / fTemp147;
			double fTemp465 = fTemp151 * (fTemp437 - fRec857[1]) + fRec856[1];
			fRec856[0] = 2.0 * (fTemp465 / fTemp152) - fRec856[1];
			fRec857[0] = fRec857[1] + 2.0 * (fTemp151 * fTemp465 / fTemp152);
			double fRec858 = fTemp154 * fTemp465 / fTemp152;
			double fTemp466 = fTemp156 * (fTemp437 - fRec860[1]) + fRec859[1];
			fRec859[0] = 2.0 * (fTemp466 / fTemp157) - fRec859[1];
			fRec860[0] = fRec860[1] + 2.0 * (fTemp156 * fTemp466 / fTemp157);
			double fRec861 = fTemp159 * fTemp466 / fTemp157;
			double fTemp467 = fTemp161 * (fTemp437 - fRec863[1]) + fRec862[1];
			fRec862[0] = 2.0 * (fTemp467 / fTemp162) - fRec862[1];
			fRec863[0] = fRec863[1] + 2.0 * (fTemp161 * fTemp467 / fTemp162);
			double fRec864 = fTemp164 * fTemp467 / fTemp162;
			double fTemp468 = fTemp166 * (fTemp437 - fRec866[1]) + fRec865[1];
			fRec865[0] = 2.0 * (fTemp468 / fTemp167) - fRec865[1];
			fRec866[0] = fRec866[1] + 2.0 * (fTemp166 * fTemp468 / fTemp167);
			double fRec867 = fTemp169 * fTemp468 / fTemp167;
			double fTemp469 = fTemp171 * (fTemp437 - fRec869[1]) + fRec868[1];
			fRec868[0] = 2.0 * (fTemp469 / fTemp172) - fRec868[1];
			fRec869[0] = fRec869[1] + 2.0 * (fTemp171 * fTemp469 / fTemp172);
			double fRec870 = fTemp174 * fTemp469 / fTemp172;
			double fTemp470 = fTemp176 * (fTemp437 - fRec872[1]) + fRec871[1];
			fRec871[0] = 2.0 * (fTemp470 / fTemp177) - fRec871[1];
			fRec872[0] = fRec872[1] + 2.0 * (fTemp176 * fTemp470 / fTemp177);
			double fRec873 = fTemp179 * fTemp470 / fTemp177;
			double fTemp471 = 0.03125 * fTemp180 * (fRec873 + fRec870 + fRec867 + fRec864 + fRec861 + fRec858 + fRec855 + fRec852 + fRec849 + fRec846 + fRec843 + fRec840 + fRec837 + fRec834 + fRec831 + fRec828 + fRec825 + fRec822 + fRec819 + fRec816 + fRec813 + fRec810 + fRec807 + fRec804 + fRec801 + fRec798 + fRec795 + fRec792 + fRec789 + fRec786 + fRec783 + fRec780) + fRec38[0] * fTemp437;
			fRec773[0] = std::max<double>(fConst1 * fRec773[1], std::fabs(fTemp471));
			fVbargraph32 = FAUSTFLOAT(fRec773[0]);
			fRec664[0] = fTemp471;
			double fTemp472 = fRec673[1] + fTemp8 + fTemp434;
			double fTemp473 = fRec30[0] * (fTemp392 * fTemp394 - fRec245[0] * fTemp434);
			fVec14[0] = fTemp473 + fTemp472 + fTemp223;
			fRec877[0] = fTemp473 + 0.995 * fRec877[1] + fTemp472 + (1.6 - (fVec5[1] + fVec14[1]));
			fRec876[0] = std::max<double>(fConst1 * fRec876[1], std::fabs(fRec877[0]));
			fVbargraph33 = FAUSTFLOAT(fRec876[0]);
			double fTemp474 = fRec18[0] * tanh(fRec877[0] / fTemp4);
			fRec875[0] = std::max<double>(fConst1 * fRec875[1], std::fabs(fTemp474));
			fVbargraph34 = FAUSTFLOAT(fRec875[0]);
			double fTemp475 = fTemp474;
			double fTemp476 = fTemp20 * (fTemp475 - fRec879[1]) + fRec878[1];
			fRec878[0] = 2.0 * (fTemp476 / fTemp21) - fRec878[1];
			fRec879[0] = fRec879[1] + 2.0 * (fTemp20 * fTemp476 / fTemp21);
			double fRec880 = fTemp23 * fTemp476 / fTemp21;
			double fTemp477 = fTemp25 * (fTemp475 - fRec882[1]) + fRec881[1];
			fRec881[0] = 2.0 * (fTemp477 / fTemp26) - fRec881[1];
			fRec882[0] = fRec882[1] + 2.0 * (fTemp25 * fTemp477 / fTemp26);
			double fRec883 = fTemp28 * fTemp477 / fTemp26;
			double fTemp478 = fTemp30 * (fTemp475 - fRec885[1]) + fRec884[1];
			fRec884[0] = 2.0 * (fTemp478 / fTemp31) - fRec884[1];
			fRec885[0] = fRec885[1] + 2.0 * (fTemp30 * fTemp478 / fTemp31);
			double fRec886 = fTemp33 * fTemp478 / fTemp31;
			double fTemp479 = fTemp35 * (fTemp475 - fRec888[1]) + fRec887[1];
			fRec887[0] = 2.0 * (fTemp479 / fTemp36) - fRec887[1];
			fRec888[0] = fRec888[1] + 2.0 * (fTemp35 * fTemp479 / fTemp36);
			double fRec889 = fTemp38 * fTemp479 / fTemp36;
			double fTemp480 = fTemp40 * (fTemp475 - fRec891[1]) + fRec890[1];
			fRec890[0] = 2.0 * (fTemp480 / fTemp41) - fRec890[1];
			fRec891[0] = fRec891[1] + 2.0 * (fTemp40 * fTemp480 / fTemp41);
			double fRec892 = fTemp43 * fTemp480 / fTemp41;
			double fTemp481 = fTemp45 * (fTemp475 - fRec894[1]) + fRec893[1];
			fRec893[0] = 2.0 * (fTemp481 / fTemp46) - fRec893[1];
			fRec894[0] = fRec894[1] + 2.0 * (fTemp45 * fTemp481 / fTemp46);
			double fRec895 = fTemp48 * fTemp481 / fTemp46;
			double fTemp482 = fTemp50 * (fTemp475 - fRec897[1]) + fRec896[1];
			fRec896[0] = 2.0 * (fTemp482 / fTemp51) - fRec896[1];
			fRec897[0] = fRec897[1] + 2.0 * (fTemp50 * fTemp482 / fTemp51);
			double fRec898 = fTemp53 * fTemp482 / fTemp51;
			double fTemp483 = fTemp55 * (fTemp475 - fRec900[1]) + fRec899[1];
			fRec899[0] = 2.0 * (fTemp483 / fTemp56) - fRec899[1];
			fRec900[0] = fRec900[1] + 2.0 * (fTemp55 * fTemp483 / fTemp56);
			double fRec901 = fTemp58 * fTemp483 / fTemp56;
			double fTemp484 = fTemp60 * (fTemp475 - fRec903[1]) + fRec902[1];
			fRec902[0] = 2.0 * (fTemp484 / fTemp61) - fRec902[1];
			fRec903[0] = fRec903[1] + 2.0 * (fTemp60 * fTemp484 / fTemp61);
			double fRec904 = fTemp63 * fTemp484 / fTemp61;
			double fTemp485 = fTemp65 * (fTemp475 - fRec906[1]) + fRec905[1];
			fRec905[0] = 2.0 * (fTemp485 / fTemp66) - fRec905[1];
			fRec906[0] = fRec906[1] + 2.0 * (fTemp65 * fTemp485 / fTemp66);
			double fRec907 = fTemp68 * fTemp485 / fTemp66;
			double fTemp486 = fTemp71 * (fTemp475 - fRec909[1]) + fRec908[1];
			fRec908[0] = 2.0 * (fTemp486 / fTemp72) - fRec908[1];
			fRec909[0] = fRec909[1] + 2.0 * (fTemp71 * fTemp486 / fTemp72);
			double fRec910 = fTemp74 * fTemp486 / fTemp72;
			double fTemp487 = fTemp76 * (fTemp475 - fRec912[1]) + fRec911[1];
			fRec911[0] = 2.0 * (fTemp487 / fTemp77) - fRec911[1];
			fRec912[0] = fRec912[1] + 2.0 * (fTemp76 * fTemp487 / fTemp77);
			double fRec913 = fTemp79 * fTemp487 / fTemp77;
			double fTemp488 = fTemp81 * (fTemp475 - fRec915[1]) + fRec914[1];
			fRec914[0] = 2.0 * (fTemp488 / fTemp82) - fRec914[1];
			fRec915[0] = fRec915[1] + 2.0 * (fTemp81 * fTemp488 / fTemp82);
			double fRec916 = fTemp84 * fTemp488 / fTemp82;
			double fTemp489 = fTemp86 * (fTemp475 - fRec918[1]) + fRec917[1];
			fRec917[0] = 2.0 * (fTemp489 / fTemp87) - fRec917[1];
			fRec918[0] = fRec918[1] + 2.0 * (fTemp86 * fTemp489 / fTemp87);
			double fRec919 = fTemp89 * fTemp489 / fTemp87;
			double fTemp490 = fTemp91 * (fTemp475 - fRec921[1]) + fRec920[1];
			fRec920[0] = 2.0 * (fTemp490 / fTemp92) - fRec920[1];
			fRec921[0] = fRec921[1] + 2.0 * (fTemp91 * fTemp490 / fTemp92);
			double fRec922 = fTemp94 * fTemp490 / fTemp92;
			double fTemp491 = fTemp96 * (fTemp475 - fRec924[1]) + fRec923[1];
			fRec923[0] = 2.0 * (fTemp491 / fTemp97) - fRec923[1];
			fRec924[0] = fRec924[1] + 2.0 * (fTemp96 * fTemp491 / fTemp97);
			double fRec925 = fTemp99 * fTemp491 / fTemp97;
			double fTemp492 = fTemp101 * (fTemp475 - fRec927[1]) + fRec926[1];
			double fTemp493 = fTemp492 / fTemp102;
			fRec926[0] = 2.0 * fTemp493 - fRec926[1];
			fRec927[0] = fRec927[1] + 2.0 * (fTemp101 * fTemp492 / fTemp102);
			double fRec928 = fTemp493;
			double fTemp494 = fTemp106 * (fTemp475 - fRec930[1]) + fRec929[1];
			fRec929[0] = 2.0 * (fTemp494 / fTemp107) - fRec929[1];
			fRec930[0] = fRec930[1] + 2.0 * (fTemp106 * fTemp494 / fTemp107);
			double fRec931 = fTemp109 * fTemp494 / fTemp107;
			double fTemp495 = fTemp111 * (fTemp475 - fRec933[1]) + fRec932[1];
			fRec932[0] = 2.0 * (fTemp495 / fTemp112) - fRec932[1];
			fRec933[0] = fRec933[1] + 2.0 * (fTemp111 * fTemp495 / fTemp112);
			double fRec934 = fTemp114 * fTemp495 / fTemp112;
			double fTemp496 = fTemp116 * (fTemp475 - fRec936[1]) + fRec935[1];
			fRec935[0] = 2.0 * (fTemp496 / fTemp117) - fRec935[1];
			fRec936[0] = fRec936[1] + 2.0 * (fTemp116 * fTemp496 / fTemp117);
			double fRec937 = fTemp119 * fTemp496 / fTemp117;
			double fTemp497 = fTemp121 * (fTemp475 - fRec939[1]) + fRec938[1];
			fRec938[0] = 2.0 * (fTemp497 / fTemp122) - fRec938[1];
			fRec939[0] = fRec939[1] + 2.0 * (fTemp121 * fTemp497 / fTemp122);
			double fRec940 = fTemp124 * fTemp497 / fTemp122;
			double fTemp498 = fTemp126 * (fTemp475 - fRec942[1]) + fRec941[1];
			fRec941[0] = 2.0 * (fTemp498 / fTemp127) - fRec941[1];
			fRec942[0] = fRec942[1] + 2.0 * (fTemp126 * fTemp498 / fTemp127);
			double fRec943 = fTemp129 * fTemp498 / fTemp127;
			double fTemp499 = fTemp131 * (fTemp475 - fRec945[1]) + fRec944[1];
			fRec944[0] = 2.0 * (fTemp499 / fTemp132) - fRec944[1];
			fRec945[0] = fRec945[1] + 2.0 * (fTemp131 * fTemp499 / fTemp132);
			double fRec946 = fTemp134 * fTemp499 / fTemp132;
			double fTemp500 = fTemp136 * (fTemp475 - fRec948[1]) + fRec947[1];
			fRec947[0] = 2.0 * (fTemp500 / fTemp137) - fRec947[1];
			fRec948[0] = fRec948[1] + 2.0 * (fTemp136 * fTemp500 / fTemp137);
			double fRec949 = fTemp139 * fTemp500 / fTemp137;
			double fTemp501 = fTemp141 * (fTemp475 - fRec951[1]) + fRec950[1];
			fRec950[0] = 2.0 * (fTemp501 / fTemp142) - fRec950[1];
			fRec951[0] = fRec951[1] + 2.0 * (fTemp141 * fTemp501 / fTemp142);
			double fRec952 = fTemp144 * fTemp501 / fTemp142;
			double fTemp502 = fTemp146 * (fTemp475 - fRec954[1]) + fRec953[1];
			fRec953[0] = 2.0 * (fTemp502 / fTemp147) - fRec953[1];
			fRec954[0] = fRec954[1] + 2.0 * (fTemp146 * fTemp502 / fTemp147);
			double fRec955 = fTemp149 * fTemp502 / fTemp147;
			double fTemp503 = fTemp151 * (fTemp475 - fRec957[1]) + fRec956[1];
			fRec956[0] = 2.0 * (fTemp503 / fTemp152) - fRec956[1];
			fRec957[0] = fRec957[1] + 2.0 * (fTemp151 * fTemp503 / fTemp152);
			double fRec958 = fTemp154 * fTemp503 / fTemp152;
			double fTemp504 = fTemp156 * (fTemp475 - fRec960[1]) + fRec959[1];
			fRec959[0] = 2.0 * (fTemp504 / fTemp157) - fRec959[1];
			fRec960[0] = fRec960[1] + 2.0 * (fTemp156 * fTemp504 / fTemp157);
			double fRec961 = fTemp159 * fTemp504 / fTemp157;
			double fTemp505 = fTemp161 * (fTemp475 - fRec963[1]) + fRec962[1];
			fRec962[0] = 2.0 * (fTemp505 / fTemp162) - fRec962[1];
			fRec963[0] = fRec963[1] + 2.0 * (fTemp161 * fTemp505 / fTemp162);
			double fRec964 = fTemp164 * fTemp505 / fTemp162;
			double fTemp506 = fTemp166 * (fTemp475 - fRec966[1]) + fRec965[1];
			fRec965[0] = 2.0 * (fTemp506 / fTemp167) - fRec965[1];
			fRec966[0] = fRec966[1] + 2.0 * (fTemp166 * fTemp506 / fTemp167);
			double fRec967 = fTemp169 * fTemp506 / fTemp167;
			double fTemp507 = fTemp171 * (fTemp475 - fRec969[1]) + fRec968[1];
			fRec968[0] = 2.0 * (fTemp507 / fTemp172) - fRec968[1];
			fRec969[0] = fRec969[1] + 2.0 * (fTemp171 * fTemp507 / fTemp172);
			double fRec970 = fTemp174 * fTemp507 / fTemp172;
			double fTemp508 = fTemp176 * (fTemp475 - fRec972[1]) + fRec971[1];
			fRec971[0] = 2.0 * (fTemp508 / fTemp177) - fRec971[1];
			fRec972[0] = fRec972[1] + 2.0 * (fTemp176 * fTemp508 / fTemp177);
			double fRec973 = fTemp179 * fTemp508 / fTemp177;
			double fTemp509 = 0.03125 * fTemp180 * (fRec973 + fRec970 + fRec967 + fRec964 + fRec961 + fRec958 + fRec955 + fRec952 + fRec949 + fRec946 + fRec943 + fRec940 + fRec937 + fRec934 + fRec931 + fRec928 + fRec925 + fRec922 + fRec919 + fRec916 + fRec913 + fRec910 + fRec907 + fRec904 + fRec901 + fRec898 + fRec895 + fRec892 + fRec889 + fRec886 + fRec883 + fRec880) + fRec38[0] * fTemp475;
			fRec874[0] = std::max<double>(fConst1 * fRec874[1], std::fabs(fTemp509));
			fVbargraph35 = FAUSTFLOAT(fRec874[0]);
			fRec665[0] = fTemp509;
			double fTemp510 = (fRec665[0] + fRec663[0] + fRec664[0]) / fTemp4;
			fVec15[IOTA0 & 4194303] = fTemp510;
			double fTemp511 = ((fRec974[1] != 0.0) ? (((fRec975[1] > 0.0) & (fRec975[1] < 1.0)) ? fRec974[1] : 0.0) : (((fRec975[1] == 0.0) & (fSlow23 != fRec976[1])) ? 0.0009765625 : (((fRec975[1] == 1.0) & (fSlow23 != fRec977[1])) ? -0.0009765625 : 0.0)));
			fRec974[0] = fTemp511;
			fRec975[0] = std::max<double>(0.0, std::min<double>(1.0, fRec975[1] + fTemp511));
			fRec976[0] = (((fRec975[1] >= 1.0) & (fRec977[1] != fSlow23)) ? fSlow23 : fRec976[1]);
			fRec977[0] = (((fRec975[1] <= 0.0) & (fRec976[1] != fSlow23)) ? fSlow23 : fRec977[1]);
			double fTemp512 = fVec15[(IOTA0 - int(std::min<double>(fConst5, std::max<double>(0.0, fRec976[0])))) & 4194303];
			fRec662[0] = 0.3333333333333333 * fTemp512 + fRec975[0] * (0.0 - 0.3333333333333333 * (fTemp512 - fVec15[(IOTA0 - int(std::min<double>(fConst5, std::max<double>(0.0, fRec977[0])))) & 4194303]));
			double fTemp513 = fRec27[0] * fRec979[1];
			fRec986[0] = std::max<double>(fConst1 * fRec986[1], std::fabs(fTemp513));
			fVbargraph36 = FAUSTFLOAT(fRec986[0]);
			double fTemp514 = fTemp513;
			double fTemp515 = fRec27[0] * fRec980[1];
			fRec987[0] = std::max<double>(fConst1 * fRec987[1], std::fabs(fTemp515));
			fVbargraph37 = FAUSTFLOAT(fRec987[0]);
			double fTemp516 = fTemp515;
			double fTemp517 = fTemp11 * (fTemp516 - fTemp514);
			double fTemp518 = ((fRec989[1] != 0.0) ? (((fRec990[1] > 0.0) & (fRec990[1] < 1.0)) ? fRec989[1] : 0.0) : (((fRec990[1] == 0.0) & (fSlow24 != fRec991[1])) ? 0.0009765625 : (((fRec990[1] == 1.0) & (fSlow24 != fRec992[1])) ? -0.0009765625 : 0.0)));
			fRec989[0] = fTemp518;
			fRec990[0] = std::max<double>(0.0, std::min<double>(1.0, fRec990[1] + fTemp518));
			fRec991[0] = (((fRec990[1] >= 1.0) & (fRec992[1] != fSlow24)) ? fSlow24 : fRec991[1]);
			fRec992[0] = (((fRec990[1] <= 0.0) & (fRec991[1] != fSlow24)) ? fSlow24 : fRec992[1]);
			double fTemp519 = fVec1[(IOTA0 - int(std::min<double>(fConst5, std::max<double>(0.0, fRec991[0])))) & 4194303];
			fRec988[0] = fTemp519 + fRec990[0] * (fVec1[(IOTA0 - int(std::min<double>(fConst5, std::max<double>(0.0, fRec992[0])))) & 4194303] - fTemp519);
			fVec16[0] = fRec988[1] + fTemp517 + fTemp8 + fTemp514 + fTemp5;
			fRec985[0] = fRec988[1] + fTemp517 + fTemp514 + fTemp8 + 0.995 * fRec985[1] + (1.2 - (fVec0[1] + fVec16[1]));
			fRec984[0] = std::max<double>(fConst1 * fRec984[1], std::fabs(fRec985[0]));
			fVbargraph38 = FAUSTFLOAT(fRec984[0]);
			double fTemp520 = fRec18[0] * tanh(fRec985[0] / fTemp4);
			fRec983[0] = std::max<double>(fConst1 * fRec983[1], std::fabs(fTemp520));
			fVbargraph39 = FAUSTFLOAT(fRec983[0]);
			double fTemp521 = fTemp520;
			double fTemp522 = fTemp20 * (fTemp521 - fRec994[1]) + fRec993[1];
			fRec993[0] = 2.0 * (fTemp522 / fTemp21) - fRec993[1];
			fRec994[0] = fRec994[1] + 2.0 * (fTemp20 * fTemp522 / fTemp21);
			double fRec995 = fTemp23 * fTemp522 / fTemp21;
			double fTemp523 = fTemp25 * (fTemp521 - fRec997[1]) + fRec996[1];
			fRec996[0] = 2.0 * (fTemp523 / fTemp26) - fRec996[1];
			fRec997[0] = fRec997[1] + 2.0 * (fTemp25 * fTemp523 / fTemp26);
			double fRec998 = fTemp28 * fTemp523 / fTemp26;
			double fTemp524 = fTemp30 * (fTemp521 - fRec1000[1]) + fRec999[1];
			fRec999[0] = 2.0 * (fTemp524 / fTemp31) - fRec999[1];
			fRec1000[0] = fRec1000[1] + 2.0 * (fTemp30 * fTemp524 / fTemp31);
			double fRec1001 = fTemp33 * fTemp524 / fTemp31;
			double fTemp525 = fTemp35 * (fTemp521 - fRec1003[1]) + fRec1002[1];
			fRec1002[0] = 2.0 * (fTemp525 / fTemp36) - fRec1002[1];
			fRec1003[0] = fRec1003[1] + 2.0 * (fTemp35 * fTemp525 / fTemp36);
			double fRec1004 = fTemp38 * fTemp525 / fTemp36;
			double fTemp526 = fTemp40 * (fTemp521 - fRec1006[1]) + fRec1005[1];
			fRec1005[0] = 2.0 * (fTemp526 / fTemp41) - fRec1005[1];
			fRec1006[0] = fRec1006[1] + 2.0 * (fTemp40 * fTemp526 / fTemp41);
			double fRec1007 = fTemp43 * fTemp526 / fTemp41;
			double fTemp527 = fTemp45 * (fTemp521 - fRec1009[1]) + fRec1008[1];
			fRec1008[0] = 2.0 * (fTemp527 / fTemp46) - fRec1008[1];
			fRec1009[0] = fRec1009[1] + 2.0 * (fTemp45 * fTemp527 / fTemp46);
			double fRec1010 = fTemp48 * fTemp527 / fTemp46;
			double fTemp528 = fTemp50 * (fTemp521 - fRec1012[1]) + fRec1011[1];
			fRec1011[0] = 2.0 * (fTemp528 / fTemp51) - fRec1011[1];
			fRec1012[0] = fRec1012[1] + 2.0 * (fTemp50 * fTemp528 / fTemp51);
			double fRec1013 = fTemp53 * fTemp528 / fTemp51;
			double fTemp529 = fTemp55 * (fTemp521 - fRec1015[1]) + fRec1014[1];
			fRec1014[0] = 2.0 * (fTemp529 / fTemp56) - fRec1014[1];
			fRec1015[0] = fRec1015[1] + 2.0 * (fTemp55 * fTemp529 / fTemp56);
			double fRec1016 = fTemp58 * fTemp529 / fTemp56;
			double fTemp530 = fTemp60 * (fTemp521 - fRec1018[1]) + fRec1017[1];
			fRec1017[0] = 2.0 * (fTemp530 / fTemp61) - fRec1017[1];
			fRec1018[0] = fRec1018[1] + 2.0 * (fTemp60 * fTemp530 / fTemp61);
			double fRec1019 = fTemp63 * fTemp530 / fTemp61;
			double fTemp531 = fTemp65 * (fTemp521 - fRec1021[1]) + fRec1020[1];
			fRec1020[0] = 2.0 * (fTemp531 / fTemp66) - fRec1020[1];
			fRec1021[0] = fRec1021[1] + 2.0 * (fTemp65 * fTemp531 / fTemp66);
			double fRec1022 = fTemp68 * fTemp531 / fTemp66;
			double fTemp532 = fTemp71 * (fTemp521 - fRec1024[1]) + fRec1023[1];
			fRec1023[0] = 2.0 * (fTemp532 / fTemp72) - fRec1023[1];
			fRec1024[0] = fRec1024[1] + 2.0 * (fTemp71 * fTemp532 / fTemp72);
			double fRec1025 = fTemp74 * fTemp532 / fTemp72;
			double fTemp533 = fTemp76 * (fTemp521 - fRec1027[1]) + fRec1026[1];
			fRec1026[0] = 2.0 * (fTemp533 / fTemp77) - fRec1026[1];
			fRec1027[0] = fRec1027[1] + 2.0 * (fTemp76 * fTemp533 / fTemp77);
			double fRec1028 = fTemp79 * fTemp533 / fTemp77;
			double fTemp534 = fTemp81 * (fTemp521 - fRec1030[1]) + fRec1029[1];
			fRec1029[0] = 2.0 * (fTemp534 / fTemp82) - fRec1029[1];
			fRec1030[0] = fRec1030[1] + 2.0 * (fTemp81 * fTemp534 / fTemp82);
			double fRec1031 = fTemp84 * fTemp534 / fTemp82;
			double fTemp535 = fTemp86 * (fTemp521 - fRec1033[1]) + fRec1032[1];
			fRec1032[0] = 2.0 * (fTemp535 / fTemp87) - fRec1032[1];
			fRec1033[0] = fRec1033[1] + 2.0 * (fTemp86 * fTemp535 / fTemp87);
			double fRec1034 = fTemp89 * fTemp535 / fTemp87;
			double fTemp536 = fTemp91 * (fTemp521 - fRec1036[1]) + fRec1035[1];
			fRec1035[0] = 2.0 * (fTemp536 / fTemp92) - fRec1035[1];
			fRec1036[0] = fRec1036[1] + 2.0 * (fTemp91 * fTemp536 / fTemp92);
			double fRec1037 = fTemp94 * fTemp536 / fTemp92;
			double fTemp537 = fTemp96 * (fTemp521 - fRec1039[1]) + fRec1038[1];
			fRec1038[0] = 2.0 * (fTemp537 / fTemp97) - fRec1038[1];
			fRec1039[0] = fRec1039[1] + 2.0 * (fTemp96 * fTemp537 / fTemp97);
			double fRec1040 = fTemp99 * fTemp537 / fTemp97;
			double fTemp538 = fTemp101 * (fTemp521 - fRec1042[1]) + fRec1041[1];
			double fTemp539 = fTemp538 / fTemp102;
			fRec1041[0] = 2.0 * fTemp539 - fRec1041[1];
			fRec1042[0] = fRec1042[1] + 2.0 * (fTemp101 * fTemp538 / fTemp102);
			double fRec1043 = fTemp539;
			double fTemp540 = fTemp106 * (fTemp521 - fRec1045[1]) + fRec1044[1];
			fRec1044[0] = 2.0 * (fTemp540 / fTemp107) - fRec1044[1];
			fRec1045[0] = fRec1045[1] + 2.0 * (fTemp106 * fTemp540 / fTemp107);
			double fRec1046 = fTemp109 * fTemp540 / fTemp107;
			double fTemp541 = fTemp111 * (fTemp521 - fRec1048[1]) + fRec1047[1];
			fRec1047[0] = 2.0 * (fTemp541 / fTemp112) - fRec1047[1];
			fRec1048[0] = fRec1048[1] + 2.0 * (fTemp111 * fTemp541 / fTemp112);
			double fRec1049 = fTemp114 * fTemp541 / fTemp112;
			double fTemp542 = fTemp116 * (fTemp521 - fRec1051[1]) + fRec1050[1];
			fRec1050[0] = 2.0 * (fTemp542 / fTemp117) - fRec1050[1];
			fRec1051[0] = fRec1051[1] + 2.0 * (fTemp116 * fTemp542 / fTemp117);
			double fRec1052 = fTemp119 * fTemp542 / fTemp117;
			double fTemp543 = fTemp121 * (fTemp521 - fRec1054[1]) + fRec1053[1];
			fRec1053[0] = 2.0 * (fTemp543 / fTemp122) - fRec1053[1];
			fRec1054[0] = fRec1054[1] + 2.0 * (fTemp121 * fTemp543 / fTemp122);
			double fRec1055 = fTemp124 * fTemp543 / fTemp122;
			double fTemp544 = fTemp126 * (fTemp521 - fRec1057[1]) + fRec1056[1];
			fRec1056[0] = 2.0 * (fTemp544 / fTemp127) - fRec1056[1];
			fRec1057[0] = fRec1057[1] + 2.0 * (fTemp126 * fTemp544 / fTemp127);
			double fRec1058 = fTemp129 * fTemp544 / fTemp127;
			double fTemp545 = fTemp131 * (fTemp521 - fRec1060[1]) + fRec1059[1];
			fRec1059[0] = 2.0 * (fTemp545 / fTemp132) - fRec1059[1];
			fRec1060[0] = fRec1060[1] + 2.0 * (fTemp131 * fTemp545 / fTemp132);
			double fRec1061 = fTemp134 * fTemp545 / fTemp132;
			double fTemp546 = fTemp136 * (fTemp521 - fRec1063[1]) + fRec1062[1];
			fRec1062[0] = 2.0 * (fTemp546 / fTemp137) - fRec1062[1];
			fRec1063[0] = fRec1063[1] + 2.0 * (fTemp136 * fTemp546 / fTemp137);
			double fRec1064 = fTemp139 * fTemp546 / fTemp137;
			double fTemp547 = fTemp141 * (fTemp521 - fRec1066[1]) + fRec1065[1];
			fRec1065[0] = 2.0 * (fTemp547 / fTemp142) - fRec1065[1];
			fRec1066[0] = fRec1066[1] + 2.0 * (fTemp141 * fTemp547 / fTemp142);
			double fRec1067 = fTemp144 * fTemp547 / fTemp142;
			double fTemp548 = fTemp146 * (fTemp521 - fRec1069[1]) + fRec1068[1];
			fRec1068[0] = 2.0 * (fTemp548 / fTemp147) - fRec1068[1];
			fRec1069[0] = fRec1069[1] + 2.0 * (fTemp146 * fTemp548 / fTemp147);
			double fRec1070 = fTemp149 * fTemp548 / fTemp147;
			double fTemp549 = fTemp151 * (fTemp521 - fRec1072[1]) + fRec1071[1];
			fRec1071[0] = 2.0 * (fTemp549 / fTemp152) - fRec1071[1];
			fRec1072[0] = fRec1072[1] + 2.0 * (fTemp151 * fTemp549 / fTemp152);
			double fRec1073 = fTemp154 * fTemp549 / fTemp152;
			double fTemp550 = fTemp156 * (fTemp521 - fRec1075[1]) + fRec1074[1];
			fRec1074[0] = 2.0 * (fTemp550 / fTemp157) - fRec1074[1];
			fRec1075[0] = fRec1075[1] + 2.0 * (fTemp156 * fTemp550 / fTemp157);
			double fRec1076 = fTemp159 * fTemp550 / fTemp157;
			double fTemp551 = fTemp161 * (fTemp521 - fRec1078[1]) + fRec1077[1];
			fRec1077[0] = 2.0 * (fTemp551 / fTemp162) - fRec1077[1];
			fRec1078[0] = fRec1078[1] + 2.0 * (fTemp161 * fTemp551 / fTemp162);
			double fRec1079 = fTemp164 * fTemp551 / fTemp162;
			double fTemp552 = fTemp166 * (fTemp521 - fRec1081[1]) + fRec1080[1];
			fRec1080[0] = 2.0 * (fTemp552 / fTemp167) - fRec1080[1];
			fRec1081[0] = fRec1081[1] + 2.0 * (fTemp166 * fTemp552 / fTemp167);
			double fRec1082 = fTemp169 * fTemp552 / fTemp167;
			double fTemp553 = fTemp171 * (fTemp521 - fRec1084[1]) + fRec1083[1];
			fRec1083[0] = 2.0 * (fTemp553 / fTemp172) - fRec1083[1];
			fRec1084[0] = fRec1084[1] + 2.0 * (fTemp171 * fTemp553 / fTemp172);
			double fRec1085 = fTemp174 * fTemp553 / fTemp172;
			double fTemp554 = fTemp176 * (fTemp521 - fRec1087[1]) + fRec1086[1];
			fRec1086[0] = 2.0 * (fTemp554 / fTemp177) - fRec1086[1];
			fRec1087[0] = fRec1087[1] + 2.0 * (fTemp176 * fTemp554 / fTemp177);
			double fRec1088 = fTemp179 * fTemp554 / fTemp177;
			double fTemp555 = 0.03125 * fTemp180 * (fRec1088 + fRec1085 + fRec1082 + fRec1079 + fRec1076 + fRec1073 + fRec1070 + fRec1067 + fRec1064 + fRec1061 + fRec1058 + fRec1055 + fRec1052 + fRec1049 + fRec1046 + fRec1043 + fRec1040 + fRec1037 + fRec1034 + fRec1031 + fRec1028 + fRec1025 + fRec1022 + fRec1019 + fRec1016 + fRec1013 + fRec1010 + fRec1007 + fRec1004 + fRec1001 + fRec998 + fRec995) + fRec38[0] * fTemp521;
			fRec982[0] = std::max<double>(fConst1 * fRec982[1], std::fabs(fTemp555));
			fVbargraph40 = FAUSTFLOAT(fRec982[0]);
			fRec979[0] = fTemp555;
			double fTemp556 = fRec988[1] + fTemp8 + fTemp516;
			double fTemp557 = fRec27[0] * fRec981[1];
			fRec1093[0] = std::max<double>(fConst1 * fRec1093[1], std::fabs(fTemp557));
			fVbargraph41 = FAUSTFLOAT(fRec1093[0]);
			double fTemp558 = fTemp557;
			double fTemp559 = fRec30[0] * (fTemp514 * (fRec144[0] - fTemp558) - fTemp516);
			fVec17[0] = fTemp559 + fTemp556 + fTemp182;
			fRec1092[0] = fTemp559 + 0.995 * fRec1092[1] + fTemp556 + (1.3 - (fVec3[1] + fVec17[1]));
			fRec1091[0] = std::max<double>(fConst1 * fRec1091[1], std::fabs(fRec1092[0]));
			fVbargraph42 = FAUSTFLOAT(fRec1091[0]);
			double fTemp560 = fRec18[0] * tanh(fRec1092[0] / fTemp4);
			fRec1090[0] = std::max<double>(fConst1 * fRec1090[1], std::fabs(fTemp560));
			fVbargraph43 = FAUSTFLOAT(fRec1090[0]);
			double fTemp561 = fTemp560;
			double fTemp562 = fTemp20 * (fTemp561 - fRec1095[1]) + fRec1094[1];
			fRec1094[0] = 2.0 * (fTemp562 / fTemp21) - fRec1094[1];
			fRec1095[0] = fRec1095[1] + 2.0 * (fTemp20 * fTemp562 / fTemp21);
			double fRec1096 = fTemp23 * fTemp562 / fTemp21;
			double fTemp563 = fTemp25 * (fTemp561 - fRec1098[1]) + fRec1097[1];
			fRec1097[0] = 2.0 * (fTemp563 / fTemp26) - fRec1097[1];
			fRec1098[0] = fRec1098[1] + 2.0 * (fTemp25 * fTemp563 / fTemp26);
			double fRec1099 = fTemp28 * fTemp563 / fTemp26;
			double fTemp564 = fTemp30 * (fTemp561 - fRec1101[1]) + fRec1100[1];
			fRec1100[0] = 2.0 * (fTemp564 / fTemp31) - fRec1100[1];
			fRec1101[0] = fRec1101[1] + 2.0 * (fTemp30 * fTemp564 / fTemp31);
			double fRec1102 = fTemp33 * fTemp564 / fTemp31;
			double fTemp565 = fTemp35 * (fTemp561 - fRec1104[1]) + fRec1103[1];
			fRec1103[0] = 2.0 * (fTemp565 / fTemp36) - fRec1103[1];
			fRec1104[0] = fRec1104[1] + 2.0 * (fTemp35 * fTemp565 / fTemp36);
			double fRec1105 = fTemp38 * fTemp565 / fTemp36;
			double fTemp566 = fTemp40 * (fTemp561 - fRec1107[1]) + fRec1106[1];
			fRec1106[0] = 2.0 * (fTemp566 / fTemp41) - fRec1106[1];
			fRec1107[0] = fRec1107[1] + 2.0 * (fTemp40 * fTemp566 / fTemp41);
			double fRec1108 = fTemp43 * fTemp566 / fTemp41;
			double fTemp567 = fTemp45 * (fTemp561 - fRec1110[1]) + fRec1109[1];
			fRec1109[0] = 2.0 * (fTemp567 / fTemp46) - fRec1109[1];
			fRec1110[0] = fRec1110[1] + 2.0 * (fTemp45 * fTemp567 / fTemp46);
			double fRec1111 = fTemp48 * fTemp567 / fTemp46;
			double fTemp568 = fTemp50 * (fTemp561 - fRec1113[1]) + fRec1112[1];
			fRec1112[0] = 2.0 * (fTemp568 / fTemp51) - fRec1112[1];
			fRec1113[0] = fRec1113[1] + 2.0 * (fTemp50 * fTemp568 / fTemp51);
			double fRec1114 = fTemp53 * fTemp568 / fTemp51;
			double fTemp569 = fTemp55 * (fTemp561 - fRec1116[1]) + fRec1115[1];
			fRec1115[0] = 2.0 * (fTemp569 / fTemp56) - fRec1115[1];
			fRec1116[0] = fRec1116[1] + 2.0 * (fTemp55 * fTemp569 / fTemp56);
			double fRec1117 = fTemp58 * fTemp569 / fTemp56;
			double fTemp570 = fTemp60 * (fTemp561 - fRec1119[1]) + fRec1118[1];
			fRec1118[0] = 2.0 * (fTemp570 / fTemp61) - fRec1118[1];
			fRec1119[0] = fRec1119[1] + 2.0 * (fTemp60 * fTemp570 / fTemp61);
			double fRec1120 = fTemp63 * fTemp570 / fTemp61;
			double fTemp571 = fTemp65 * (fTemp561 - fRec1122[1]) + fRec1121[1];
			fRec1121[0] = 2.0 * (fTemp571 / fTemp66) - fRec1121[1];
			fRec1122[0] = fRec1122[1] + 2.0 * (fTemp65 * fTemp571 / fTemp66);
			double fRec1123 = fTemp68 * fTemp571 / fTemp66;
			double fTemp572 = fTemp71 * (fTemp561 - fRec1125[1]) + fRec1124[1];
			fRec1124[0] = 2.0 * (fTemp572 / fTemp72) - fRec1124[1];
			fRec1125[0] = fRec1125[1] + 2.0 * (fTemp71 * fTemp572 / fTemp72);
			double fRec1126 = fTemp74 * fTemp572 / fTemp72;
			double fTemp573 = fTemp76 * (fTemp561 - fRec1128[1]) + fRec1127[1];
			fRec1127[0] = 2.0 * (fTemp573 / fTemp77) - fRec1127[1];
			fRec1128[0] = fRec1128[1] + 2.0 * (fTemp76 * fTemp573 / fTemp77);
			double fRec1129 = fTemp79 * fTemp573 / fTemp77;
			double fTemp574 = fTemp81 * (fTemp561 - fRec1131[1]) + fRec1130[1];
			fRec1130[0] = 2.0 * (fTemp574 / fTemp82) - fRec1130[1];
			fRec1131[0] = fRec1131[1] + 2.0 * (fTemp81 * fTemp574 / fTemp82);
			double fRec1132 = fTemp84 * fTemp574 / fTemp82;
			double fTemp575 = fTemp86 * (fTemp561 - fRec1134[1]) + fRec1133[1];
			fRec1133[0] = 2.0 * (fTemp575 / fTemp87) - fRec1133[1];
			fRec1134[0] = fRec1134[1] + 2.0 * (fTemp86 * fTemp575 / fTemp87);
			double fRec1135 = fTemp89 * fTemp575 / fTemp87;
			double fTemp576 = fTemp91 * (fTemp561 - fRec1137[1]) + fRec1136[1];
			fRec1136[0] = 2.0 * (fTemp576 / fTemp92) - fRec1136[1];
			fRec1137[0] = fRec1137[1] + 2.0 * (fTemp91 * fTemp576 / fTemp92);
			double fRec1138 = fTemp94 * fTemp576 / fTemp92;
			double fTemp577 = fTemp96 * (fTemp561 - fRec1140[1]) + fRec1139[1];
			fRec1139[0] = 2.0 * (fTemp577 / fTemp97) - fRec1139[1];
			fRec1140[0] = fRec1140[1] + 2.0 * (fTemp96 * fTemp577 / fTemp97);
			double fRec1141 = fTemp99 * fTemp577 / fTemp97;
			double fTemp578 = fTemp101 * (fTemp561 - fRec1143[1]) + fRec1142[1];
			double fTemp579 = fTemp578 / fTemp102;
			fRec1142[0] = 2.0 * fTemp579 - fRec1142[1];
			fRec1143[0] = fRec1143[1] + 2.0 * (fTemp101 * fTemp578 / fTemp102);
			double fRec1144 = fTemp579;
			double fTemp580 = fTemp106 * (fTemp561 - fRec1146[1]) + fRec1145[1];
			fRec1145[0] = 2.0 * (fTemp580 / fTemp107) - fRec1145[1];
			fRec1146[0] = fRec1146[1] + 2.0 * (fTemp106 * fTemp580 / fTemp107);
			double fRec1147 = fTemp109 * fTemp580 / fTemp107;
			double fTemp581 = fTemp111 * (fTemp561 - fRec1149[1]) + fRec1148[1];
			fRec1148[0] = 2.0 * (fTemp581 / fTemp112) - fRec1148[1];
			fRec1149[0] = fRec1149[1] + 2.0 * (fTemp111 * fTemp581 / fTemp112);
			double fRec1150 = fTemp114 * fTemp581 / fTemp112;
			double fTemp582 = fTemp116 * (fTemp561 - fRec1152[1]) + fRec1151[1];
			fRec1151[0] = 2.0 * (fTemp582 / fTemp117) - fRec1151[1];
			fRec1152[0] = fRec1152[1] + 2.0 * (fTemp116 * fTemp582 / fTemp117);
			double fRec1153 = fTemp119 * fTemp582 / fTemp117;
			double fTemp583 = fTemp121 * (fTemp561 - fRec1155[1]) + fRec1154[1];
			fRec1154[0] = 2.0 * (fTemp583 / fTemp122) - fRec1154[1];
			fRec1155[0] = fRec1155[1] + 2.0 * (fTemp121 * fTemp583 / fTemp122);
			double fRec1156 = fTemp124 * fTemp583 / fTemp122;
			double fTemp584 = fTemp126 * (fTemp561 - fRec1158[1]) + fRec1157[1];
			fRec1157[0] = 2.0 * (fTemp584 / fTemp127) - fRec1157[1];
			fRec1158[0] = fRec1158[1] + 2.0 * (fTemp126 * fTemp584 / fTemp127);
			double fRec1159 = fTemp129 * fTemp584 / fTemp127;
			double fTemp585 = fTemp131 * (fTemp561 - fRec1161[1]) + fRec1160[1];
			fRec1160[0] = 2.0 * (fTemp585 / fTemp132) - fRec1160[1];
			fRec1161[0] = fRec1161[1] + 2.0 * (fTemp131 * fTemp585 / fTemp132);
			double fRec1162 = fTemp134 * fTemp585 / fTemp132;
			double fTemp586 = fTemp136 * (fTemp561 - fRec1164[1]) + fRec1163[1];
			fRec1163[0] = 2.0 * (fTemp586 / fTemp137) - fRec1163[1];
			fRec1164[0] = fRec1164[1] + 2.0 * (fTemp136 * fTemp586 / fTemp137);
			double fRec1165 = fTemp139 * fTemp586 / fTemp137;
			double fTemp587 = fTemp141 * (fTemp561 - fRec1167[1]) + fRec1166[1];
			fRec1166[0] = 2.0 * (fTemp587 / fTemp142) - fRec1166[1];
			fRec1167[0] = fRec1167[1] + 2.0 * (fTemp141 * fTemp587 / fTemp142);
			double fRec1168 = fTemp144 * fTemp587 / fTemp142;
			double fTemp588 = fTemp146 * (fTemp561 - fRec1170[1]) + fRec1169[1];
			fRec1169[0] = 2.0 * (fTemp588 / fTemp147) - fRec1169[1];
			fRec1170[0] = fRec1170[1] + 2.0 * (fTemp146 * fTemp588 / fTemp147);
			double fRec1171 = fTemp149 * fTemp588 / fTemp147;
			double fTemp589 = fTemp151 * (fTemp561 - fRec1173[1]) + fRec1172[1];
			fRec1172[0] = 2.0 * (fTemp589 / fTemp152) - fRec1172[1];
			fRec1173[0] = fRec1173[1] + 2.0 * (fTemp151 * fTemp589 / fTemp152);
			double fRec1174 = fTemp154 * fTemp589 / fTemp152;
			double fTemp590 = fTemp156 * (fTemp561 - fRec1176[1]) + fRec1175[1];
			fRec1175[0] = 2.0 * (fTemp590 / fTemp157) - fRec1175[1];
			fRec1176[0] = fRec1176[1] + 2.0 * (fTemp156 * fTemp590 / fTemp157);
			double fRec1177 = fTemp159 * fTemp590 / fTemp157;
			double fTemp591 = fTemp161 * (fTemp561 - fRec1179[1]) + fRec1178[1];
			fRec1178[0] = 2.0 * (fTemp591 / fTemp162) - fRec1178[1];
			fRec1179[0] = fRec1179[1] + 2.0 * (fTemp161 * fTemp591 / fTemp162);
			double fRec1180 = fTemp164 * fTemp591 / fTemp162;
			double fTemp592 = fTemp166 * (fTemp561 - fRec1182[1]) + fRec1181[1];
			fRec1181[0] = 2.0 * (fTemp592 / fTemp167) - fRec1181[1];
			fRec1182[0] = fRec1182[1] + 2.0 * (fTemp166 * fTemp592 / fTemp167);
			double fRec1183 = fTemp169 * fTemp592 / fTemp167;
			double fTemp593 = fTemp171 * (fTemp561 - fRec1185[1]) + fRec1184[1];
			fRec1184[0] = 2.0 * (fTemp593 / fTemp172) - fRec1184[1];
			fRec1185[0] = fRec1185[1] + 2.0 * (fTemp171 * fTemp593 / fTemp172);
			double fRec1186 = fTemp174 * fTemp593 / fTemp172;
			double fTemp594 = fTemp176 * (fTemp561 - fRec1188[1]) + fRec1187[1];
			fRec1187[0] = 2.0 * (fTemp594 / fTemp177) - fRec1187[1];
			fRec1188[0] = fRec1188[1] + 2.0 * (fTemp176 * fTemp594 / fTemp177);
			double fRec1189 = fTemp179 * fTemp594 / fTemp177;
			double fTemp595 = 0.03125 * fTemp180 * (fRec1189 + fRec1186 + fRec1183 + fRec1180 + fRec1177 + fRec1174 + fRec1171 + fRec1168 + fRec1165 + fRec1162 + fRec1159 + fRec1156 + fRec1153 + fRec1150 + fRec1147 + fRec1144 + fRec1141 + fRec1138 + fRec1135 + fRec1132 + fRec1129 + fRec1126 + fRec1123 + fRec1120 + fRec1117 + fRec1114 + fRec1111 + fRec1108 + fRec1105 + fRec1102 + fRec1099 + fRec1096) + fRec38[0] * fTemp561;
			fRec1089[0] = std::max<double>(fConst1 * fRec1089[1], std::fabs(fTemp595));
			fVbargraph44 = FAUSTFLOAT(fRec1089[0]);
			fRec980[0] = fTemp595;
			double fTemp596 = fTemp8 + fRec988[1] + fTemp558;
			double fTemp597 = fRec30[0] * (fTemp514 * fTemp516 - fRec245[0] * fTemp558);
			fVec18[0] = fTemp597 + fTemp596 + fTemp223;
			fRec1193[0] = fTemp597 + 0.995 * fRec1193[1] + fTemp596 + (1.6 - (fVec5[1] + fVec18[1]));
			fRec1192[0] = std::max<double>(fConst1 * fRec1192[1], std::fabs(fRec1193[0]));
			fVbargraph45 = FAUSTFLOAT(fRec1192[0]);
			double fTemp598 = fRec18[0] * tanh(fRec1193[0] / fTemp4);
			fRec1191[0] = std::max<double>(fConst1 * fRec1191[1], std::fabs(fTemp598));
			fVbargraph46 = FAUSTFLOAT(fRec1191[0]);
			double fTemp599 = fTemp598;
			double fTemp600 = fTemp20 * (fTemp599 - fRec1195[1]) + fRec1194[1];
			fRec1194[0] = 2.0 * (fTemp600 / fTemp21) - fRec1194[1];
			fRec1195[0] = fRec1195[1] + 2.0 * (fTemp20 * fTemp600 / fTemp21);
			double fRec1196 = fTemp23 * fTemp600 / fTemp21;
			double fTemp601 = fTemp25 * (fTemp599 - fRec1198[1]) + fRec1197[1];
			fRec1197[0] = 2.0 * (fTemp601 / fTemp26) - fRec1197[1];
			fRec1198[0] = fRec1198[1] + 2.0 * (fTemp25 * fTemp601 / fTemp26);
			double fRec1199 = fTemp28 * fTemp601 / fTemp26;
			double fTemp602 = fTemp30 * (fTemp599 - fRec1201[1]) + fRec1200[1];
			fRec1200[0] = 2.0 * (fTemp602 / fTemp31) - fRec1200[1];
			fRec1201[0] = fRec1201[1] + 2.0 * (fTemp30 * fTemp602 / fTemp31);
			double fRec1202 = fTemp33 * fTemp602 / fTemp31;
			double fTemp603 = fTemp35 * (fTemp599 - fRec1204[1]) + fRec1203[1];
			fRec1203[0] = 2.0 * (fTemp603 / fTemp36) - fRec1203[1];
			fRec1204[0] = fRec1204[1] + 2.0 * (fTemp35 * fTemp603 / fTemp36);
			double fRec1205 = fTemp38 * fTemp603 / fTemp36;
			double fTemp604 = fTemp40 * (fTemp599 - fRec1207[1]) + fRec1206[1];
			fRec1206[0] = 2.0 * (fTemp604 / fTemp41) - fRec1206[1];
			fRec1207[0] = fRec1207[1] + 2.0 * (fTemp40 * fTemp604 / fTemp41);
			double fRec1208 = fTemp43 * fTemp604 / fTemp41;
			double fTemp605 = fTemp45 * (fTemp599 - fRec1210[1]) + fRec1209[1];
			fRec1209[0] = 2.0 * (fTemp605 / fTemp46) - fRec1209[1];
			fRec1210[0] = fRec1210[1] + 2.0 * (fTemp45 * fTemp605 / fTemp46);
			double fRec1211 = fTemp48 * fTemp605 / fTemp46;
			double fTemp606 = fTemp50 * (fTemp599 - fRec1213[1]) + fRec1212[1];
			fRec1212[0] = 2.0 * (fTemp606 / fTemp51) - fRec1212[1];
			fRec1213[0] = fRec1213[1] + 2.0 * (fTemp50 * fTemp606 / fTemp51);
			double fRec1214 = fTemp53 * fTemp606 / fTemp51;
			double fTemp607 = fTemp55 * (fTemp599 - fRec1216[1]) + fRec1215[1];
			fRec1215[0] = 2.0 * (fTemp607 / fTemp56) - fRec1215[1];
			fRec1216[0] = fRec1216[1] + 2.0 * (fTemp55 * fTemp607 / fTemp56);
			double fRec1217 = fTemp58 * fTemp607 / fTemp56;
			double fTemp608 = fTemp60 * (fTemp599 - fRec1219[1]) + fRec1218[1];
			fRec1218[0] = 2.0 * (fTemp608 / fTemp61) - fRec1218[1];
			fRec1219[0] = fRec1219[1] + 2.0 * (fTemp60 * fTemp608 / fTemp61);
			double fRec1220 = fTemp63 * fTemp608 / fTemp61;
			double fTemp609 = fTemp65 * (fTemp599 - fRec1222[1]) + fRec1221[1];
			fRec1221[0] = 2.0 * (fTemp609 / fTemp66) - fRec1221[1];
			fRec1222[0] = fRec1222[1] + 2.0 * (fTemp65 * fTemp609 / fTemp66);
			double fRec1223 = fTemp68 * fTemp609 / fTemp66;
			double fTemp610 = fTemp71 * (fTemp599 - fRec1225[1]) + fRec1224[1];
			fRec1224[0] = 2.0 * (fTemp610 / fTemp72) - fRec1224[1];
			fRec1225[0] = fRec1225[1] + 2.0 * (fTemp71 * fTemp610 / fTemp72);
			double fRec1226 = fTemp74 * fTemp610 / fTemp72;
			double fTemp611 = fTemp76 * (fTemp599 - fRec1228[1]) + fRec1227[1];
			fRec1227[0] = 2.0 * (fTemp611 / fTemp77) - fRec1227[1];
			fRec1228[0] = fRec1228[1] + 2.0 * (fTemp76 * fTemp611 / fTemp77);
			double fRec1229 = fTemp79 * fTemp611 / fTemp77;
			double fTemp612 = fTemp81 * (fTemp599 - fRec1231[1]) + fRec1230[1];
			fRec1230[0] = 2.0 * (fTemp612 / fTemp82) - fRec1230[1];
			fRec1231[0] = fRec1231[1] + 2.0 * (fTemp81 * fTemp612 / fTemp82);
			double fRec1232 = fTemp84 * fTemp612 / fTemp82;
			double fTemp613 = fTemp86 * (fTemp599 - fRec1234[1]) + fRec1233[1];
			fRec1233[0] = 2.0 * (fTemp613 / fTemp87) - fRec1233[1];
			fRec1234[0] = fRec1234[1] + 2.0 * (fTemp86 * fTemp613 / fTemp87);
			double fRec1235 = fTemp89 * fTemp613 / fTemp87;
			double fTemp614 = fTemp91 * (fTemp599 - fRec1237[1]) + fRec1236[1];
			fRec1236[0] = 2.0 * (fTemp614 / fTemp92) - fRec1236[1];
			fRec1237[0] = fRec1237[1] + 2.0 * (fTemp91 * fTemp614 / fTemp92);
			double fRec1238 = fTemp94 * fTemp614 / fTemp92;
			double fTemp615 = fTemp96 * (fTemp599 - fRec1240[1]) + fRec1239[1];
			fRec1239[0] = 2.0 * (fTemp615 / fTemp97) - fRec1239[1];
			fRec1240[0] = fRec1240[1] + 2.0 * (fTemp96 * fTemp615 / fTemp97);
			double fRec1241 = fTemp99 * fTemp615 / fTemp97;
			double fTemp616 = fTemp101 * (fTemp599 - fRec1243[1]) + fRec1242[1];
			double fTemp617 = fTemp616 / fTemp102;
			fRec1242[0] = 2.0 * fTemp617 - fRec1242[1];
			fRec1243[0] = fRec1243[1] + 2.0 * (fTemp101 * fTemp616 / fTemp102);
			double fRec1244 = fTemp617;
			double fTemp618 = fTemp106 * (fTemp599 - fRec1246[1]) + fRec1245[1];
			fRec1245[0] = 2.0 * (fTemp618 / fTemp107) - fRec1245[1];
			fRec1246[0] = fRec1246[1] + 2.0 * (fTemp106 * fTemp618 / fTemp107);
			double fRec1247 = fTemp109 * fTemp618 / fTemp107;
			double fTemp619 = fTemp111 * (fTemp599 - fRec1249[1]) + fRec1248[1];
			fRec1248[0] = 2.0 * (fTemp619 / fTemp112) - fRec1248[1];
			fRec1249[0] = fRec1249[1] + 2.0 * (fTemp111 * fTemp619 / fTemp112);
			double fRec1250 = fTemp114 * fTemp619 / fTemp112;
			double fTemp620 = fTemp116 * (fTemp599 - fRec1252[1]) + fRec1251[1];
			fRec1251[0] = 2.0 * (fTemp620 / fTemp117) - fRec1251[1];
			fRec1252[0] = fRec1252[1] + 2.0 * (fTemp116 * fTemp620 / fTemp117);
			double fRec1253 = fTemp119 * fTemp620 / fTemp117;
			double fTemp621 = fTemp121 * (fTemp599 - fRec1255[1]) + fRec1254[1];
			fRec1254[0] = 2.0 * (fTemp621 / fTemp122) - fRec1254[1];
			fRec1255[0] = fRec1255[1] + 2.0 * (fTemp121 * fTemp621 / fTemp122);
			double fRec1256 = fTemp124 * fTemp621 / fTemp122;
			double fTemp622 = fTemp126 * (fTemp599 - fRec1258[1]) + fRec1257[1];
			fRec1257[0] = 2.0 * (fTemp622 / fTemp127) - fRec1257[1];
			fRec1258[0] = fRec1258[1] + 2.0 * (fTemp126 * fTemp622 / fTemp127);
			double fRec1259 = fTemp129 * fTemp622 / fTemp127;
			double fTemp623 = fTemp131 * (fTemp599 - fRec1261[1]) + fRec1260[1];
			fRec1260[0] = 2.0 * (fTemp623 / fTemp132) - fRec1260[1];
			fRec1261[0] = fRec1261[1] + 2.0 * (fTemp131 * fTemp623 / fTemp132);
			double fRec1262 = fTemp134 * fTemp623 / fTemp132;
			double fTemp624 = fTemp136 * (fTemp599 - fRec1264[1]) + fRec1263[1];
			fRec1263[0] = 2.0 * (fTemp624 / fTemp137) - fRec1263[1];
			fRec1264[0] = fRec1264[1] + 2.0 * (fTemp136 * fTemp624 / fTemp137);
			double fRec1265 = fTemp139 * fTemp624 / fTemp137;
			double fTemp625 = fTemp141 * (fTemp599 - fRec1267[1]) + fRec1266[1];
			fRec1266[0] = 2.0 * (fTemp625 / fTemp142) - fRec1266[1];
			fRec1267[0] = fRec1267[1] + 2.0 * (fTemp141 * fTemp625 / fTemp142);
			double fRec1268 = fTemp144 * fTemp625 / fTemp142;
			double fTemp626 = fTemp146 * (fTemp599 - fRec1270[1]) + fRec1269[1];
			fRec1269[0] = 2.0 * (fTemp626 / fTemp147) - fRec1269[1];
			fRec1270[0] = fRec1270[1] + 2.0 * (fTemp146 * fTemp626 / fTemp147);
			double fRec1271 = fTemp149 * fTemp626 / fTemp147;
			double fTemp627 = fTemp151 * (fTemp599 - fRec1273[1]) + fRec1272[1];
			fRec1272[0] = 2.0 * (fTemp627 / fTemp152) - fRec1272[1];
			fRec1273[0] = fRec1273[1] + 2.0 * (fTemp151 * fTemp627 / fTemp152);
			double fRec1274 = fTemp154 * fTemp627 / fTemp152;
			double fTemp628 = fTemp156 * (fTemp599 - fRec1276[1]) + fRec1275[1];
			fRec1275[0] = 2.0 * (fTemp628 / fTemp157) - fRec1275[1];
			fRec1276[0] = fRec1276[1] + 2.0 * (fTemp156 * fTemp628 / fTemp157);
			double fRec1277 = fTemp159 * fTemp628 / fTemp157;
			double fTemp629 = fTemp161 * (fTemp599 - fRec1279[1]) + fRec1278[1];
			fRec1278[0] = 2.0 * (fTemp629 / fTemp162) - fRec1278[1];
			fRec1279[0] = fRec1279[1] + 2.0 * (fTemp161 * fTemp629 / fTemp162);
			double fRec1280 = fTemp164 * fTemp629 / fTemp162;
			double fTemp630 = fTemp166 * (fTemp599 - fRec1282[1]) + fRec1281[1];
			fRec1281[0] = 2.0 * (fTemp630 / fTemp167) - fRec1281[1];
			fRec1282[0] = fRec1282[1] + 2.0 * (fTemp166 * fTemp630 / fTemp167);
			double fRec1283 = fTemp169 * fTemp630 / fTemp167;
			double fTemp631 = fTemp171 * (fTemp599 - fRec1285[1]) + fRec1284[1];
			fRec1284[0] = 2.0 * (fTemp631 / fTemp172) - fRec1284[1];
			fRec1285[0] = fRec1285[1] + 2.0 * (fTemp171 * fTemp631 / fTemp172);
			double fRec1286 = fTemp174 * fTemp631 / fTemp172;
			double fTemp632 = fTemp176 * (fTemp599 - fRec1288[1]) + fRec1287[1];
			fRec1287[0] = 2.0 * (fTemp632 / fTemp177) - fRec1287[1];
			fRec1288[0] = fRec1288[1] + 2.0 * (fTemp176 * fTemp632 / fTemp177);
			double fRec1289 = fTemp179 * fTemp632 / fTemp177;
			double fTemp633 = 0.03125 * fTemp180 * (fRec1289 + fRec1286 + fRec1283 + fRec1280 + fRec1277 + fRec1274 + fRec1271 + fRec1268 + fRec1265 + fRec1262 + fRec1259 + fRec1256 + fRec1253 + fRec1250 + fRec1247 + fRec1244 + fRec1241 + fRec1238 + fRec1235 + fRec1232 + fRec1229 + fRec1226 + fRec1223 + fRec1220 + fRec1217 + fRec1214 + fRec1211 + fRec1208 + fRec1205 + fRec1202 + fRec1199 + fRec1196) + fRec38[0] * fTemp599;
			fRec1190[0] = std::max<double>(fConst1 * fRec1190[1], std::fabs(fTemp633));
			fVbargraph47 = FAUSTFLOAT(fRec1190[0]);
			fRec981[0] = fTemp633;
			double fTemp634 = (fRec981[0] + fRec979[0] + fRec980[0]) / fTemp4;
			fVec19[IOTA0 & 4194303] = fTemp634;
			double fTemp635 = ((fRec1290[1] != 0.0) ? (((fRec1291[1] > 0.0) & (fRec1291[1] < 1.0)) ? fRec1290[1] : 0.0) : (((fRec1291[1] == 0.0) & (fSlow25 != fRec1292[1])) ? 0.0009765625 : (((fRec1291[1] == 1.0) & (fSlow25 != fRec1293[1])) ? -0.0009765625 : 0.0)));
			fRec1290[0] = fTemp635;
			fRec1291[0] = std::max<double>(0.0, std::min<double>(1.0, fRec1291[1] + fTemp635));
			fRec1292[0] = (((fRec1291[1] >= 1.0) & (fRec1293[1] != fSlow25)) ? fSlow25 : fRec1292[1]);
			fRec1293[0] = (((fRec1291[1] <= 0.0) & (fRec1292[1] != fSlow25)) ? fSlow25 : fRec1293[1]);
			double fTemp636 = fVec19[(IOTA0 - int(std::min<double>(fConst5, std::max<double>(0.0, fRec1292[0])))) & 4194303];
			fRec978[0] = 0.3333333333333333 * fTemp636 + fRec1291[0] * (0.0 - 0.3333333333333333 * (fTemp636 - fVec19[(IOTA0 - int(std::min<double>(fConst5, std::max<double>(0.0, fRec1293[0])))) & 4194303]));
			fRec12[0] = 0.25 * (fRec978[1] + fRec662[1] + fRec346[1] + fRec17[1]);
			double fRec13 = 0.3333333333333333 * fTemp510;
			double fRec14 = 0.3333333333333333 * fTemp262;
			double fRec15 = 0.3333333333333333 * fTemp386;
			double fRec16 = 0.3333333333333333 * fTemp634;
			double fTemp637 = (fRec13 - fRec9[1]) * fTemp2 / fTemp3;
			fRec9[0] = fRec9[1] + 2.0 * fTemp637;
			double fTemp638 = fRec9[1] + fTemp637;
			double fRec10 = fRec13 - fTemp638;
			double fTemp639 = (fRec10 - fRec6[1]) * fTemp0 / fTemp1;
			fRec6[0] = fRec6[1] + 2.0 * fTemp639;
			double fTemp640 = fRec6[1] + fTemp639;
			fRec7[IOTA0 & 511] = fTemp640;
			double fTemp641 = std::fabs(fRec7[IOTA0 & 511]);
			int iTemp642 = (fTemp641 >= fRec5[1]) | (double(iRec4[1]) >= fConst2);
			iRec4[0] = ((iTemp642) ? 0 : iRec4[1] + 1);
			fRec5[0] = ((iTemp642) ? fTemp641 : fRec5[1]);
			double fTemp643 = fRec5[0] - fRec2[1];
			fRec2[0] = fRec2[1] + fConst8 * fTemp643;
			double fTemp644 = fRec2[1] + fConst7 * fTemp643;
			double fRec3 = fTemp644;
			fRec1[0] = std::max<double>(fConst1 * fRec1[1], std::fabs(fRec3));
			fRec1294[0] = fSlow27 + fSlow0 * fRec1294[1];
			double fTemp645 = fRec1294[0] * fRec7[(IOTA0 - iConst9) & 511] / fRec1[0];
			fRec0[0] = std::max<double>(fConst1 * fRec0[1], std::fabs(fTemp645));
			fVbargraph48 = FAUSTFLOAT(fRec0[0]);
			output0[i0] = FAUSTFLOAT(fTemp645);
			double fTemp646 = fTemp2 * (fRec14 - fRec1303[1]) / fTemp3;
			fRec1303[0] = fRec1303[1] + 2.0 * fTemp646;
			double fTemp647 = fRec1303[1] + fTemp646;
			double fRec1304 = fRec14 - fTemp647;
			double fTemp648 = fTemp0 * (fRec1304 - fRec1301[1]) / fTemp1;
			fRec1301[0] = fRec1301[1] + 2.0 * fTemp648;
			double fTemp649 = fRec1301[1] + fTemp648;
			fRec1302[IOTA0 & 511] = fTemp649;
			double fTemp650 = std::fabs(fRec1302[IOTA0 & 511]);
			int iTemp651 = (fTemp650 >= fRec1300[1]) | (double(iRec1299[1]) >= fConst2);
			iRec1299[0] = ((iTemp651) ? 0 : iRec1299[1] + 1);
			fRec1300[0] = ((iTemp651) ? fTemp650 : fRec1300[1]);
			double fTemp652 = fRec1300[0] - fRec1297[1];
			fRec1297[0] = fRec1297[1] + fConst8 * fTemp652;
			double fTemp653 = fRec1297[1] + fConst7 * fTemp652;
			double fRec1298 = fTemp653;
			fRec1296[0] = std::max<double>(fConst1 * fRec1296[1], std::fabs(fRec1298));
			double fTemp654 = fRec1294[0] * fRec1302[(IOTA0 - iConst9) & 511] / fRec1296[0];
			fRec1295[0] = std::max<double>(fConst1 * fRec1295[1], std::fabs(fTemp654));
			fVbargraph49 = FAUSTFLOAT(fRec1295[0]);
			output1[i0] = FAUSTFLOAT(fTemp654);
			double fTemp655 = fTemp2 * (fRec15 - fRec1313[1]) / fTemp3;
			fRec1313[0] = fRec1313[1] + 2.0 * fTemp655;
			double fTemp656 = fRec1313[1] + fTemp655;
			double fRec1314 = fRec15 - fTemp656;
			double fTemp657 = fTemp0 * (fRec1314 - fRec1311[1]) / fTemp1;
			fRec1311[0] = fRec1311[1] + 2.0 * fTemp657;
			double fTemp658 = fRec1311[1] + fTemp657;
			fRec1312[IOTA0 & 511] = fTemp658;
			double fTemp659 = std::fabs(fRec1312[IOTA0 & 511]);
			int iTemp660 = (fTemp659 >= fRec1310[1]) | (double(iRec1309[1]) >= fConst2);
			iRec1309[0] = ((iTemp660) ? 0 : iRec1309[1] + 1);
			fRec1310[0] = ((iTemp660) ? fTemp659 : fRec1310[1]);
			double fTemp661 = fRec1310[0] - fRec1307[1];
			fRec1307[0] = fRec1307[1] + fConst8 * fTemp661;
			double fTemp662 = fRec1307[1] + fConst7 * fTemp661;
			double fRec1308 = fTemp662;
			fRec1306[0] = std::max<double>(fConst1 * fRec1306[1], std::fabs(fRec1308));
			double fTemp663 = fRec1294[0] * fRec1312[(IOTA0 - iConst9) & 511] / fRec1306[0];
			fRec1305[0] = std::max<double>(fConst1 * fRec1305[1], std::fabs(fTemp663));
			fVbargraph50 = FAUSTFLOAT(fRec1305[0]);
			output2[i0] = FAUSTFLOAT(fTemp663);
			double fTemp664 = fTemp2 * (fRec16 - fRec1323[1]) / fTemp3;
			fRec1323[0] = fRec1323[1] + 2.0 * fTemp664;
			double fTemp665 = fRec1323[1] + fTemp664;
			double fRec1324 = fRec16 - fTemp665;
			double fTemp666 = fTemp0 * (fRec1324 - fRec1321[1]) / fTemp1;
			fRec1321[0] = fRec1321[1] + 2.0 * fTemp666;
			double fTemp667 = fRec1321[1] + fTemp666;
			fRec1322[IOTA0 & 511] = fTemp667;
			double fTemp668 = std::fabs(fRec1322[IOTA0 & 511]);
			int iTemp669 = (fTemp668 >= fRec1320[1]) | (double(iRec1319[1]) >= fConst2);
			iRec1319[0] = ((iTemp669) ? 0 : iRec1319[1] + 1);
			fRec1320[0] = ((iTemp669) ? fTemp668 : fRec1320[1]);
			double fTemp670 = fRec1320[0] - fRec1317[1];
			fRec1317[0] = fRec1317[1] + fConst8 * fTemp670;
			double fTemp671 = fRec1317[1] + fConst7 * fTemp670;
			double fRec1318 = fTemp671;
			fRec1316[0] = std::max<double>(fConst1 * fRec1316[1], std::fabs(fRec1318));
			double fTemp672 = fRec1294[0] * fRec1322[(IOTA0 - iConst9) & 511] / fRec1316[0];
			fRec1315[0] = std::max<double>(fConst1 * fRec1315[1], std::fabs(fTemp672));
			fVbargraph51 = FAUSTFLOAT(fRec1315[0]);
			output3[i0] = FAUSTFLOAT(fTemp672);
			fRec8[1] = fRec8[0];
			fRec11[1] = fRec11[0];
			fRec18[1] = fRec18[0];
			fVec0[1] = fVec0[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec28[1] = fRec28[0];
			fRec29[1] = fRec29[0];
			fRec30[1] = fRec30[0];
			fRec31[1] = fRec31[0];
			fRec33[1] = fRec33[0];
			IOTA0 = IOTA0 + 1;
			fRec34[1] = fRec34[0];
			fRec35[1] = fRec35[0];
			fRec36[1] = fRec36[0];
			fRec37[1] = fRec37[0];
			fRec32[1] = fRec32[0];
			fVec2[1] = fVec2[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec38[1] = fRec38[0];
			fRec42[1] = fRec42[0];
			fRec43[1] = fRec43[0];
			fRec44[1] = fRec44[0];
			fRec45[1] = fRec45[0];
			fRec39[1] = fRec39[0];
			fRec40[1] = fRec40[0];
			fRec46[1] = fRec46[0];
			fRec47[1] = fRec47[0];
			fRec49[1] = fRec49[0];
			fRec50[1] = fRec50[0];
			fRec52[1] = fRec52[0];
			fRec53[1] = fRec53[0];
			fRec55[1] = fRec55[0];
			fRec56[1] = fRec56[0];
			fRec58[1] = fRec58[0];
			fRec59[1] = fRec59[0];
			fRec61[1] = fRec61[0];
			fRec62[1] = fRec62[0];
			fRec64[1] = fRec64[0];
			fRec65[1] = fRec65[0];
			fRec67[1] = fRec67[0];
			fRec68[1] = fRec68[0];
			fRec70[1] = fRec70[0];
			fRec71[1] = fRec71[0];
			fRec73[1] = fRec73[0];
			fRec74[1] = fRec74[0];
			fRec76[1] = fRec76[0];
			fRec77[1] = fRec77[0];
			fRec79[1] = fRec79[0];
			fRec80[1] = fRec80[0];
			fRec82[1] = fRec82[0];
			fRec83[1] = fRec83[0];
			fRec85[1] = fRec85[0];
			fRec86[1] = fRec86[0];
			fRec88[1] = fRec88[0];
			fRec89[1] = fRec89[0];
			fRec91[1] = fRec91[0];
			fRec92[1] = fRec92[0];
			fRec94[1] = fRec94[0];
			fRec95[1] = fRec95[0];
			fRec97[1] = fRec97[0];
			fRec98[1] = fRec98[0];
			fRec100[1] = fRec100[0];
			fRec101[1] = fRec101[0];
			fRec103[1] = fRec103[0];
			fRec104[1] = fRec104[0];
			fRec106[1] = fRec106[0];
			fRec107[1] = fRec107[0];
			fRec109[1] = fRec109[0];
			fRec110[1] = fRec110[0];
			fRec112[1] = fRec112[0];
			fRec113[1] = fRec113[0];
			fRec115[1] = fRec115[0];
			fRec116[1] = fRec116[0];
			fRec118[1] = fRec118[0];
			fRec119[1] = fRec119[0];
			fRec121[1] = fRec121[0];
			fRec122[1] = fRec122[0];
			fRec124[1] = fRec124[0];
			fRec125[1] = fRec125[0];
			fRec127[1] = fRec127[0];
			fRec128[1] = fRec128[0];
			fRec130[1] = fRec130[0];
			fRec131[1] = fRec131[0];
			fRec133[1] = fRec133[0];
			fRec134[1] = fRec134[0];
			fRec136[1] = fRec136[0];
			fRec137[1] = fRec137[0];
			fRec22[1] = fRec22[0];
			fRec19[1] = fRec19[0];
			fVec3[1] = fVec3[0];
			fRec143[1] = fRec143[0];
			fRec144[1] = fRec144[0];
			fVec4[1] = fVec4[0];
			fRec142[1] = fRec142[0];
			fRec141[1] = fRec141[0];
			fRec140[1] = fRec140[0];
			fRec145[1] = fRec145[0];
			fRec146[1] = fRec146[0];
			fRec148[1] = fRec148[0];
			fRec149[1] = fRec149[0];
			fRec151[1] = fRec151[0];
			fRec152[1] = fRec152[0];
			fRec154[1] = fRec154[0];
			fRec155[1] = fRec155[0];
			fRec157[1] = fRec157[0];
			fRec158[1] = fRec158[0];
			fRec160[1] = fRec160[0];
			fRec161[1] = fRec161[0];
			fRec163[1] = fRec163[0];
			fRec164[1] = fRec164[0];
			fRec166[1] = fRec166[0];
			fRec167[1] = fRec167[0];
			fRec169[1] = fRec169[0];
			fRec170[1] = fRec170[0];
			fRec172[1] = fRec172[0];
			fRec173[1] = fRec173[0];
			fRec175[1] = fRec175[0];
			fRec176[1] = fRec176[0];
			fRec178[1] = fRec178[0];
			fRec179[1] = fRec179[0];
			fRec181[1] = fRec181[0];
			fRec182[1] = fRec182[0];
			fRec184[1] = fRec184[0];
			fRec185[1] = fRec185[0];
			fRec187[1] = fRec187[0];
			fRec188[1] = fRec188[0];
			fRec190[1] = fRec190[0];
			fRec191[1] = fRec191[0];
			fRec193[1] = fRec193[0];
			fRec194[1] = fRec194[0];
			fRec196[1] = fRec196[0];
			fRec197[1] = fRec197[0];
			fRec199[1] = fRec199[0];
			fRec200[1] = fRec200[0];
			fRec202[1] = fRec202[0];
			fRec203[1] = fRec203[0];
			fRec205[1] = fRec205[0];
			fRec206[1] = fRec206[0];
			fRec208[1] = fRec208[0];
			fRec209[1] = fRec209[0];
			fRec211[1] = fRec211[0];
			fRec212[1] = fRec212[0];
			fRec214[1] = fRec214[0];
			fRec215[1] = fRec215[0];
			fRec217[1] = fRec217[0];
			fRec218[1] = fRec218[0];
			fRec220[1] = fRec220[0];
			fRec221[1] = fRec221[0];
			fRec223[1] = fRec223[0];
			fRec224[1] = fRec224[0];
			fRec226[1] = fRec226[0];
			fRec227[1] = fRec227[0];
			fRec229[1] = fRec229[0];
			fRec230[1] = fRec230[0];
			fRec232[1] = fRec232[0];
			fRec233[1] = fRec233[0];
			fRec235[1] = fRec235[0];
			fRec236[1] = fRec236[0];
			fRec238[1] = fRec238[0];
			fRec239[1] = fRec239[0];
			fRec139[1] = fRec139[0];
			fRec20[1] = fRec20[0];
			fVec5[1] = fVec5[0];
			fRec245[1] = fRec245[0];
			fVec6[1] = fVec6[0];
			fRec244[1] = fRec244[0];
			fRec243[1] = fRec243[0];
			fRec242[1] = fRec242[0];
			fRec246[1] = fRec246[0];
			fRec247[1] = fRec247[0];
			fRec249[1] = fRec249[0];
			fRec250[1] = fRec250[0];
			fRec252[1] = fRec252[0];
			fRec253[1] = fRec253[0];
			fRec255[1] = fRec255[0];
			fRec256[1] = fRec256[0];
			fRec258[1] = fRec258[0];
			fRec259[1] = fRec259[0];
			fRec261[1] = fRec261[0];
			fRec262[1] = fRec262[0];
			fRec264[1] = fRec264[0];
			fRec265[1] = fRec265[0];
			fRec267[1] = fRec267[0];
			fRec268[1] = fRec268[0];
			fRec270[1] = fRec270[0];
			fRec271[1] = fRec271[0];
			fRec273[1] = fRec273[0];
			fRec274[1] = fRec274[0];
			fRec276[1] = fRec276[0];
			fRec277[1] = fRec277[0];
			fRec279[1] = fRec279[0];
			fRec280[1] = fRec280[0];
			fRec282[1] = fRec282[0];
			fRec283[1] = fRec283[0];
			fRec285[1] = fRec285[0];
			fRec286[1] = fRec286[0];
			fRec288[1] = fRec288[0];
			fRec289[1] = fRec289[0];
			fRec291[1] = fRec291[0];
			fRec292[1] = fRec292[0];
			fRec294[1] = fRec294[0];
			fRec295[1] = fRec295[0];
			fRec297[1] = fRec297[0];
			fRec298[1] = fRec298[0];
			fRec300[1] = fRec300[0];
			fRec301[1] = fRec301[0];
			fRec303[1] = fRec303[0];
			fRec304[1] = fRec304[0];
			fRec306[1] = fRec306[0];
			fRec307[1] = fRec307[0];
			fRec309[1] = fRec309[0];
			fRec310[1] = fRec310[0];
			fRec312[1] = fRec312[0];
			fRec313[1] = fRec313[0];
			fRec315[1] = fRec315[0];
			fRec316[1] = fRec316[0];
			fRec318[1] = fRec318[0];
			fRec319[1] = fRec319[0];
			fRec321[1] = fRec321[0];
			fRec322[1] = fRec322[0];
			fRec324[1] = fRec324[0];
			fRec325[1] = fRec325[0];
			fRec327[1] = fRec327[0];
			fRec328[1] = fRec328[0];
			fRec330[1] = fRec330[0];
			fRec331[1] = fRec331[0];
			fRec333[1] = fRec333[0];
			fRec334[1] = fRec334[0];
			fRec336[1] = fRec336[0];
			fRec337[1] = fRec337[0];
			fRec339[1] = fRec339[0];
			fRec340[1] = fRec340[0];
			fRec241[1] = fRec241[0];
			fRec21[1] = fRec21[0];
			fRec342[1] = fRec342[0];
			fRec343[1] = fRec343[0];
			fRec344[1] = fRec344[0];
			fRec345[1] = fRec345[0];
			fRec17[1] = fRec17[0];
			fRec354[1] = fRec354[0];
			fRec355[1] = fRec355[0];
			fRec357[1] = fRec357[0];
			fRec358[1] = fRec358[0];
			fRec359[1] = fRec359[0];
			fRec360[1] = fRec360[0];
			fRec356[1] = fRec356[0];
			fVec8[1] = fVec8[0];
			fRec353[1] = fRec353[0];
			fRec352[1] = fRec352[0];
			fRec351[1] = fRec351[0];
			fRec361[1] = fRec361[0];
			fRec362[1] = fRec362[0];
			fRec364[1] = fRec364[0];
			fRec365[1] = fRec365[0];
			fRec367[1] = fRec367[0];
			fRec368[1] = fRec368[0];
			fRec370[1] = fRec370[0];
			fRec371[1] = fRec371[0];
			fRec373[1] = fRec373[0];
			fRec374[1] = fRec374[0];
			fRec376[1] = fRec376[0];
			fRec377[1] = fRec377[0];
			fRec379[1] = fRec379[0];
			fRec380[1] = fRec380[0];
			fRec382[1] = fRec382[0];
			fRec383[1] = fRec383[0];
			fRec385[1] = fRec385[0];
			fRec386[1] = fRec386[0];
			fRec388[1] = fRec388[0];
			fRec389[1] = fRec389[0];
			fRec391[1] = fRec391[0];
			fRec392[1] = fRec392[0];
			fRec394[1] = fRec394[0];
			fRec395[1] = fRec395[0];
			fRec397[1] = fRec397[0];
			fRec398[1] = fRec398[0];
			fRec400[1] = fRec400[0];
			fRec401[1] = fRec401[0];
			fRec403[1] = fRec403[0];
			fRec404[1] = fRec404[0];
			fRec406[1] = fRec406[0];
			fRec407[1] = fRec407[0];
			fRec409[1] = fRec409[0];
			fRec410[1] = fRec410[0];
			fRec412[1] = fRec412[0];
			fRec413[1] = fRec413[0];
			fRec415[1] = fRec415[0];
			fRec416[1] = fRec416[0];
			fRec418[1] = fRec418[0];
			fRec419[1] = fRec419[0];
			fRec421[1] = fRec421[0];
			fRec422[1] = fRec422[0];
			fRec424[1] = fRec424[0];
			fRec425[1] = fRec425[0];
			fRec427[1] = fRec427[0];
			fRec428[1] = fRec428[0];
			fRec430[1] = fRec430[0];
			fRec431[1] = fRec431[0];
			fRec433[1] = fRec433[0];
			fRec434[1] = fRec434[0];
			fRec436[1] = fRec436[0];
			fRec437[1] = fRec437[0];
			fRec439[1] = fRec439[0];
			fRec440[1] = fRec440[0];
			fRec442[1] = fRec442[0];
			fRec443[1] = fRec443[0];
			fRec445[1] = fRec445[0];
			fRec446[1] = fRec446[0];
			fRec448[1] = fRec448[0];
			fRec449[1] = fRec449[0];
			fRec451[1] = fRec451[0];
			fRec452[1] = fRec452[0];
			fRec454[1] = fRec454[0];
			fRec455[1] = fRec455[0];
			fRec350[1] = fRec350[0];
			fRec347[1] = fRec347[0];
			fRec461[1] = fRec461[0];
			fVec9[1] = fVec9[0];
			fRec460[1] = fRec460[0];
			fRec459[1] = fRec459[0];
			fRec458[1] = fRec458[0];
			fRec462[1] = fRec462[0];
			fRec463[1] = fRec463[0];
			fRec465[1] = fRec465[0];
			fRec466[1] = fRec466[0];
			fRec468[1] = fRec468[0];
			fRec469[1] = fRec469[0];
			fRec471[1] = fRec471[0];
			fRec472[1] = fRec472[0];
			fRec474[1] = fRec474[0];
			fRec475[1] = fRec475[0];
			fRec477[1] = fRec477[0];
			fRec478[1] = fRec478[0];
			fRec480[1] = fRec480[0];
			fRec481[1] = fRec481[0];
			fRec483[1] = fRec483[0];
			fRec484[1] = fRec484[0];
			fRec486[1] = fRec486[0];
			fRec487[1] = fRec487[0];
			fRec489[1] = fRec489[0];
			fRec490[1] = fRec490[0];
			fRec492[1] = fRec492[0];
			fRec493[1] = fRec493[0];
			fRec495[1] = fRec495[0];
			fRec496[1] = fRec496[0];
			fRec498[1] = fRec498[0];
			fRec499[1] = fRec499[0];
			fRec501[1] = fRec501[0];
			fRec502[1] = fRec502[0];
			fRec504[1] = fRec504[0];
			fRec505[1] = fRec505[0];
			fRec507[1] = fRec507[0];
			fRec508[1] = fRec508[0];
			fRec510[1] = fRec510[0];
			fRec511[1] = fRec511[0];
			fRec513[1] = fRec513[0];
			fRec514[1] = fRec514[0];
			fRec516[1] = fRec516[0];
			fRec517[1] = fRec517[0];
			fRec519[1] = fRec519[0];
			fRec520[1] = fRec520[0];
			fRec522[1] = fRec522[0];
			fRec523[1] = fRec523[0];
			fRec525[1] = fRec525[0];
			fRec526[1] = fRec526[0];
			fRec528[1] = fRec528[0];
			fRec529[1] = fRec529[0];
			fRec531[1] = fRec531[0];
			fRec532[1] = fRec532[0];
			fRec534[1] = fRec534[0];
			fRec535[1] = fRec535[0];
			fRec537[1] = fRec537[0];
			fRec538[1] = fRec538[0];
			fRec540[1] = fRec540[0];
			fRec541[1] = fRec541[0];
			fRec543[1] = fRec543[0];
			fRec544[1] = fRec544[0];
			fRec546[1] = fRec546[0];
			fRec547[1] = fRec547[0];
			fRec549[1] = fRec549[0];
			fRec550[1] = fRec550[0];
			fRec552[1] = fRec552[0];
			fRec553[1] = fRec553[0];
			fRec555[1] = fRec555[0];
			fRec556[1] = fRec556[0];
			fRec457[1] = fRec457[0];
			fRec348[1] = fRec348[0];
			fVec10[1] = fVec10[0];
			fRec561[1] = fRec561[0];
			fRec560[1] = fRec560[0];
			fRec559[1] = fRec559[0];
			fRec562[1] = fRec562[0];
			fRec563[1] = fRec563[0];
			fRec565[1] = fRec565[0];
			fRec566[1] = fRec566[0];
			fRec568[1] = fRec568[0];
			fRec569[1] = fRec569[0];
			fRec571[1] = fRec571[0];
			fRec572[1] = fRec572[0];
			fRec574[1] = fRec574[0];
			fRec575[1] = fRec575[0];
			fRec577[1] = fRec577[0];
			fRec578[1] = fRec578[0];
			fRec580[1] = fRec580[0];
			fRec581[1] = fRec581[0];
			fRec583[1] = fRec583[0];
			fRec584[1] = fRec584[0];
			fRec586[1] = fRec586[0];
			fRec587[1] = fRec587[0];
			fRec589[1] = fRec589[0];
			fRec590[1] = fRec590[0];
			fRec592[1] = fRec592[0];
			fRec593[1] = fRec593[0];
			fRec595[1] = fRec595[0];
			fRec596[1] = fRec596[0];
			fRec598[1] = fRec598[0];
			fRec599[1] = fRec599[0];
			fRec601[1] = fRec601[0];
			fRec602[1] = fRec602[0];
			fRec604[1] = fRec604[0];
			fRec605[1] = fRec605[0];
			fRec607[1] = fRec607[0];
			fRec608[1] = fRec608[0];
			fRec610[1] = fRec610[0];
			fRec611[1] = fRec611[0];
			fRec613[1] = fRec613[0];
			fRec614[1] = fRec614[0];
			fRec616[1] = fRec616[0];
			fRec617[1] = fRec617[0];
			fRec619[1] = fRec619[0];
			fRec620[1] = fRec620[0];
			fRec622[1] = fRec622[0];
			fRec623[1] = fRec623[0];
			fRec625[1] = fRec625[0];
			fRec626[1] = fRec626[0];
			fRec628[1] = fRec628[0];
			fRec629[1] = fRec629[0];
			fRec631[1] = fRec631[0];
			fRec632[1] = fRec632[0];
			fRec634[1] = fRec634[0];
			fRec635[1] = fRec635[0];
			fRec637[1] = fRec637[0];
			fRec638[1] = fRec638[0];
			fRec640[1] = fRec640[0];
			fRec641[1] = fRec641[0];
			fRec643[1] = fRec643[0];
			fRec644[1] = fRec644[0];
			fRec646[1] = fRec646[0];
			fRec647[1] = fRec647[0];
			fRec649[1] = fRec649[0];
			fRec650[1] = fRec650[0];
			fRec652[1] = fRec652[0];
			fRec653[1] = fRec653[0];
			fRec655[1] = fRec655[0];
			fRec656[1] = fRec656[0];
			fRec558[1] = fRec558[0];
			fRec349[1] = fRec349[0];
			fRec658[1] = fRec658[0];
			fRec659[1] = fRec659[0];
			fRec660[1] = fRec660[0];
			fRec661[1] = fRec661[0];
			fRec346[1] = fRec346[0];
			fRec674[1] = fRec674[0];
			fRec675[1] = fRec675[0];
			fRec676[1] = fRec676[0];
			fRec677[1] = fRec677[0];
			fRec673[1] = fRec673[0];
			fRec678[1] = fRec678[0];
			fRec679[1] = fRec679[0];
			fVec12[1] = fVec12[0];
			fRec672[1] = fRec672[0];
			fRec671[1] = fRec671[0];
			fRec670[1] = fRec670[0];
			fRec667[1] = fRec667[0];
			fRec668[1] = fRec668[0];
			fRec680[1] = fRec680[0];
			fRec681[1] = fRec681[0];
			fRec683[1] = fRec683[0];
			fRec684[1] = fRec684[0];
			fRec686[1] = fRec686[0];
			fRec687[1] = fRec687[0];
			fRec689[1] = fRec689[0];
			fRec690[1] = fRec690[0];
			fRec692[1] = fRec692[0];
			fRec693[1] = fRec693[0];
			fRec695[1] = fRec695[0];
			fRec696[1] = fRec696[0];
			fRec698[1] = fRec698[0];
			fRec699[1] = fRec699[0];
			fRec701[1] = fRec701[0];
			fRec702[1] = fRec702[0];
			fRec704[1] = fRec704[0];
			fRec705[1] = fRec705[0];
			fRec707[1] = fRec707[0];
			fRec708[1] = fRec708[0];
			fRec710[1] = fRec710[0];
			fRec711[1] = fRec711[0];
			fRec713[1] = fRec713[0];
			fRec714[1] = fRec714[0];
			fRec716[1] = fRec716[0];
			fRec717[1] = fRec717[0];
			fRec719[1] = fRec719[0];
			fRec720[1] = fRec720[0];
			fRec722[1] = fRec722[0];
			fRec723[1] = fRec723[0];
			fRec725[1] = fRec725[0];
			fRec726[1] = fRec726[0];
			fRec728[1] = fRec728[0];
			fRec729[1] = fRec729[0];
			fRec731[1] = fRec731[0];
			fRec732[1] = fRec732[0];
			fRec734[1] = fRec734[0];
			fRec735[1] = fRec735[0];
			fRec737[1] = fRec737[0];
			fRec738[1] = fRec738[0];
			fRec740[1] = fRec740[0];
			fRec741[1] = fRec741[0];
			fRec743[1] = fRec743[0];
			fRec744[1] = fRec744[0];
			fRec746[1] = fRec746[0];
			fRec747[1] = fRec747[0];
			fRec749[1] = fRec749[0];
			fRec750[1] = fRec750[0];
			fRec752[1] = fRec752[0];
			fRec753[1] = fRec753[0];
			fRec755[1] = fRec755[0];
			fRec756[1] = fRec756[0];
			fRec758[1] = fRec758[0];
			fRec759[1] = fRec759[0];
			fRec761[1] = fRec761[0];
			fRec762[1] = fRec762[0];
			fRec764[1] = fRec764[0];
			fRec765[1] = fRec765[0];
			fRec767[1] = fRec767[0];
			fRec768[1] = fRec768[0];
			fRec770[1] = fRec770[0];
			fRec771[1] = fRec771[0];
			fRec666[1] = fRec666[0];
			fRec663[1] = fRec663[0];
			fRec777[1] = fRec777[0];
			fVec13[1] = fVec13[0];
			fRec776[1] = fRec776[0];
			fRec775[1] = fRec775[0];
			fRec774[1] = fRec774[0];
			fRec778[1] = fRec778[0];
			fRec779[1] = fRec779[0];
			fRec781[1] = fRec781[0];
			fRec782[1] = fRec782[0];
			fRec784[1] = fRec784[0];
			fRec785[1] = fRec785[0];
			fRec787[1] = fRec787[0];
			fRec788[1] = fRec788[0];
			fRec790[1] = fRec790[0];
			fRec791[1] = fRec791[0];
			fRec793[1] = fRec793[0];
			fRec794[1] = fRec794[0];
			fRec796[1] = fRec796[0];
			fRec797[1] = fRec797[0];
			fRec799[1] = fRec799[0];
			fRec800[1] = fRec800[0];
			fRec802[1] = fRec802[0];
			fRec803[1] = fRec803[0];
			fRec805[1] = fRec805[0];
			fRec806[1] = fRec806[0];
			fRec808[1] = fRec808[0];
			fRec809[1] = fRec809[0];
			fRec811[1] = fRec811[0];
			fRec812[1] = fRec812[0];
			fRec814[1] = fRec814[0];
			fRec815[1] = fRec815[0];
			fRec817[1] = fRec817[0];
			fRec818[1] = fRec818[0];
			fRec820[1] = fRec820[0];
			fRec821[1] = fRec821[0];
			fRec823[1] = fRec823[0];
			fRec824[1] = fRec824[0];
			fRec826[1] = fRec826[0];
			fRec827[1] = fRec827[0];
			fRec829[1] = fRec829[0];
			fRec830[1] = fRec830[0];
			fRec832[1] = fRec832[0];
			fRec833[1] = fRec833[0];
			fRec835[1] = fRec835[0];
			fRec836[1] = fRec836[0];
			fRec838[1] = fRec838[0];
			fRec839[1] = fRec839[0];
			fRec841[1] = fRec841[0];
			fRec842[1] = fRec842[0];
			fRec844[1] = fRec844[0];
			fRec845[1] = fRec845[0];
			fRec847[1] = fRec847[0];
			fRec848[1] = fRec848[0];
			fRec850[1] = fRec850[0];
			fRec851[1] = fRec851[0];
			fRec853[1] = fRec853[0];
			fRec854[1] = fRec854[0];
			fRec856[1] = fRec856[0];
			fRec857[1] = fRec857[0];
			fRec859[1] = fRec859[0];
			fRec860[1] = fRec860[0];
			fRec862[1] = fRec862[0];
			fRec863[1] = fRec863[0];
			fRec865[1] = fRec865[0];
			fRec866[1] = fRec866[0];
			fRec868[1] = fRec868[0];
			fRec869[1] = fRec869[0];
			fRec871[1] = fRec871[0];
			fRec872[1] = fRec872[0];
			fRec773[1] = fRec773[0];
			fRec664[1] = fRec664[0];
			fVec14[1] = fVec14[0];
			fRec877[1] = fRec877[0];
			fRec876[1] = fRec876[0];
			fRec875[1] = fRec875[0];
			fRec878[1] = fRec878[0];
			fRec879[1] = fRec879[0];
			fRec881[1] = fRec881[0];
			fRec882[1] = fRec882[0];
			fRec884[1] = fRec884[0];
			fRec885[1] = fRec885[0];
			fRec887[1] = fRec887[0];
			fRec888[1] = fRec888[0];
			fRec890[1] = fRec890[0];
			fRec891[1] = fRec891[0];
			fRec893[1] = fRec893[0];
			fRec894[1] = fRec894[0];
			fRec896[1] = fRec896[0];
			fRec897[1] = fRec897[0];
			fRec899[1] = fRec899[0];
			fRec900[1] = fRec900[0];
			fRec902[1] = fRec902[0];
			fRec903[1] = fRec903[0];
			fRec905[1] = fRec905[0];
			fRec906[1] = fRec906[0];
			fRec908[1] = fRec908[0];
			fRec909[1] = fRec909[0];
			fRec911[1] = fRec911[0];
			fRec912[1] = fRec912[0];
			fRec914[1] = fRec914[0];
			fRec915[1] = fRec915[0];
			fRec917[1] = fRec917[0];
			fRec918[1] = fRec918[0];
			fRec920[1] = fRec920[0];
			fRec921[1] = fRec921[0];
			fRec923[1] = fRec923[0];
			fRec924[1] = fRec924[0];
			fRec926[1] = fRec926[0];
			fRec927[1] = fRec927[0];
			fRec929[1] = fRec929[0];
			fRec930[1] = fRec930[0];
			fRec932[1] = fRec932[0];
			fRec933[1] = fRec933[0];
			fRec935[1] = fRec935[0];
			fRec936[1] = fRec936[0];
			fRec938[1] = fRec938[0];
			fRec939[1] = fRec939[0];
			fRec941[1] = fRec941[0];
			fRec942[1] = fRec942[0];
			fRec944[1] = fRec944[0];
			fRec945[1] = fRec945[0];
			fRec947[1] = fRec947[0];
			fRec948[1] = fRec948[0];
			fRec950[1] = fRec950[0];
			fRec951[1] = fRec951[0];
			fRec953[1] = fRec953[0];
			fRec954[1] = fRec954[0];
			fRec956[1] = fRec956[0];
			fRec957[1] = fRec957[0];
			fRec959[1] = fRec959[0];
			fRec960[1] = fRec960[0];
			fRec962[1] = fRec962[0];
			fRec963[1] = fRec963[0];
			fRec965[1] = fRec965[0];
			fRec966[1] = fRec966[0];
			fRec968[1] = fRec968[0];
			fRec969[1] = fRec969[0];
			fRec971[1] = fRec971[0];
			fRec972[1] = fRec972[0];
			fRec874[1] = fRec874[0];
			fRec665[1] = fRec665[0];
			fRec974[1] = fRec974[0];
			fRec975[1] = fRec975[0];
			fRec976[1] = fRec976[0];
			fRec977[1] = fRec977[0];
			fRec662[1] = fRec662[0];
			fRec986[1] = fRec986[0];
			fRec987[1] = fRec987[0];
			fRec989[1] = fRec989[0];
			fRec990[1] = fRec990[0];
			fRec991[1] = fRec991[0];
			fRec992[1] = fRec992[0];
			fRec988[1] = fRec988[0];
			fVec16[1] = fVec16[0];
			fRec985[1] = fRec985[0];
			fRec984[1] = fRec984[0];
			fRec983[1] = fRec983[0];
			fRec993[1] = fRec993[0];
			fRec994[1] = fRec994[0];
			fRec996[1] = fRec996[0];
			fRec997[1] = fRec997[0];
			fRec999[1] = fRec999[0];
			fRec1000[1] = fRec1000[0];
			fRec1002[1] = fRec1002[0];
			fRec1003[1] = fRec1003[0];
			fRec1005[1] = fRec1005[0];
			fRec1006[1] = fRec1006[0];
			fRec1008[1] = fRec1008[0];
			fRec1009[1] = fRec1009[0];
			fRec1011[1] = fRec1011[0];
			fRec1012[1] = fRec1012[0];
			fRec1014[1] = fRec1014[0];
			fRec1015[1] = fRec1015[0];
			fRec1017[1] = fRec1017[0];
			fRec1018[1] = fRec1018[0];
			fRec1020[1] = fRec1020[0];
			fRec1021[1] = fRec1021[0];
			fRec1023[1] = fRec1023[0];
			fRec1024[1] = fRec1024[0];
			fRec1026[1] = fRec1026[0];
			fRec1027[1] = fRec1027[0];
			fRec1029[1] = fRec1029[0];
			fRec1030[1] = fRec1030[0];
			fRec1032[1] = fRec1032[0];
			fRec1033[1] = fRec1033[0];
			fRec1035[1] = fRec1035[0];
			fRec1036[1] = fRec1036[0];
			fRec1038[1] = fRec1038[0];
			fRec1039[1] = fRec1039[0];
			fRec1041[1] = fRec1041[0];
			fRec1042[1] = fRec1042[0];
			fRec1044[1] = fRec1044[0];
			fRec1045[1] = fRec1045[0];
			fRec1047[1] = fRec1047[0];
			fRec1048[1] = fRec1048[0];
			fRec1050[1] = fRec1050[0];
			fRec1051[1] = fRec1051[0];
			fRec1053[1] = fRec1053[0];
			fRec1054[1] = fRec1054[0];
			fRec1056[1] = fRec1056[0];
			fRec1057[1] = fRec1057[0];
			fRec1059[1] = fRec1059[0];
			fRec1060[1] = fRec1060[0];
			fRec1062[1] = fRec1062[0];
			fRec1063[1] = fRec1063[0];
			fRec1065[1] = fRec1065[0];
			fRec1066[1] = fRec1066[0];
			fRec1068[1] = fRec1068[0];
			fRec1069[1] = fRec1069[0];
			fRec1071[1] = fRec1071[0];
			fRec1072[1] = fRec1072[0];
			fRec1074[1] = fRec1074[0];
			fRec1075[1] = fRec1075[0];
			fRec1077[1] = fRec1077[0];
			fRec1078[1] = fRec1078[0];
			fRec1080[1] = fRec1080[0];
			fRec1081[1] = fRec1081[0];
			fRec1083[1] = fRec1083[0];
			fRec1084[1] = fRec1084[0];
			fRec1086[1] = fRec1086[0];
			fRec1087[1] = fRec1087[0];
			fRec982[1] = fRec982[0];
			fRec979[1] = fRec979[0];
			fRec1093[1] = fRec1093[0];
			fVec17[1] = fVec17[0];
			fRec1092[1] = fRec1092[0];
			fRec1091[1] = fRec1091[0];
			fRec1090[1] = fRec1090[0];
			fRec1094[1] = fRec1094[0];
			fRec1095[1] = fRec1095[0];
			fRec1097[1] = fRec1097[0];
			fRec1098[1] = fRec1098[0];
			fRec1100[1] = fRec1100[0];
			fRec1101[1] = fRec1101[0];
			fRec1103[1] = fRec1103[0];
			fRec1104[1] = fRec1104[0];
			fRec1106[1] = fRec1106[0];
			fRec1107[1] = fRec1107[0];
			fRec1109[1] = fRec1109[0];
			fRec1110[1] = fRec1110[0];
			fRec1112[1] = fRec1112[0];
			fRec1113[1] = fRec1113[0];
			fRec1115[1] = fRec1115[0];
			fRec1116[1] = fRec1116[0];
			fRec1118[1] = fRec1118[0];
			fRec1119[1] = fRec1119[0];
			fRec1121[1] = fRec1121[0];
			fRec1122[1] = fRec1122[0];
			fRec1124[1] = fRec1124[0];
			fRec1125[1] = fRec1125[0];
			fRec1127[1] = fRec1127[0];
			fRec1128[1] = fRec1128[0];
			fRec1130[1] = fRec1130[0];
			fRec1131[1] = fRec1131[0];
			fRec1133[1] = fRec1133[0];
			fRec1134[1] = fRec1134[0];
			fRec1136[1] = fRec1136[0];
			fRec1137[1] = fRec1137[0];
			fRec1139[1] = fRec1139[0];
			fRec1140[1] = fRec1140[0];
			fRec1142[1] = fRec1142[0];
			fRec1143[1] = fRec1143[0];
			fRec1145[1] = fRec1145[0];
			fRec1146[1] = fRec1146[0];
			fRec1148[1] = fRec1148[0];
			fRec1149[1] = fRec1149[0];
			fRec1151[1] = fRec1151[0];
			fRec1152[1] = fRec1152[0];
			fRec1154[1] = fRec1154[0];
			fRec1155[1] = fRec1155[0];
			fRec1157[1] = fRec1157[0];
			fRec1158[1] = fRec1158[0];
			fRec1160[1] = fRec1160[0];
			fRec1161[1] = fRec1161[0];
			fRec1163[1] = fRec1163[0];
			fRec1164[1] = fRec1164[0];
			fRec1166[1] = fRec1166[0];
			fRec1167[1] = fRec1167[0];
			fRec1169[1] = fRec1169[0];
			fRec1170[1] = fRec1170[0];
			fRec1172[1] = fRec1172[0];
			fRec1173[1] = fRec1173[0];
			fRec1175[1] = fRec1175[0];
			fRec1176[1] = fRec1176[0];
			fRec1178[1] = fRec1178[0];
			fRec1179[1] = fRec1179[0];
			fRec1181[1] = fRec1181[0];
			fRec1182[1] = fRec1182[0];
			fRec1184[1] = fRec1184[0];
			fRec1185[1] = fRec1185[0];
			fRec1187[1] = fRec1187[0];
			fRec1188[1] = fRec1188[0];
			fRec1089[1] = fRec1089[0];
			fRec980[1] = fRec980[0];
			fVec18[1] = fVec18[0];
			fRec1193[1] = fRec1193[0];
			fRec1192[1] = fRec1192[0];
			fRec1191[1] = fRec1191[0];
			fRec1194[1] = fRec1194[0];
			fRec1195[1] = fRec1195[0];
			fRec1197[1] = fRec1197[0];
			fRec1198[1] = fRec1198[0];
			fRec1200[1] = fRec1200[0];
			fRec1201[1] = fRec1201[0];
			fRec1203[1] = fRec1203[0];
			fRec1204[1] = fRec1204[0];
			fRec1206[1] = fRec1206[0];
			fRec1207[1] = fRec1207[0];
			fRec1209[1] = fRec1209[0];
			fRec1210[1] = fRec1210[0];
			fRec1212[1] = fRec1212[0];
			fRec1213[1] = fRec1213[0];
			fRec1215[1] = fRec1215[0];
			fRec1216[1] = fRec1216[0];
			fRec1218[1] = fRec1218[0];
			fRec1219[1] = fRec1219[0];
			fRec1221[1] = fRec1221[0];
			fRec1222[1] = fRec1222[0];
			fRec1224[1] = fRec1224[0];
			fRec1225[1] = fRec1225[0];
			fRec1227[1] = fRec1227[0];
			fRec1228[1] = fRec1228[0];
			fRec1230[1] = fRec1230[0];
			fRec1231[1] = fRec1231[0];
			fRec1233[1] = fRec1233[0];
			fRec1234[1] = fRec1234[0];
			fRec1236[1] = fRec1236[0];
			fRec1237[1] = fRec1237[0];
			fRec1239[1] = fRec1239[0];
			fRec1240[1] = fRec1240[0];
			fRec1242[1] = fRec1242[0];
			fRec1243[1] = fRec1243[0];
			fRec1245[1] = fRec1245[0];
			fRec1246[1] = fRec1246[0];
			fRec1248[1] = fRec1248[0];
			fRec1249[1] = fRec1249[0];
			fRec1251[1] = fRec1251[0];
			fRec1252[1] = fRec1252[0];
			fRec1254[1] = fRec1254[0];
			fRec1255[1] = fRec1255[0];
			fRec1257[1] = fRec1257[0];
			fRec1258[1] = fRec1258[0];
			fRec1260[1] = fRec1260[0];
			fRec1261[1] = fRec1261[0];
			fRec1263[1] = fRec1263[0];
			fRec1264[1] = fRec1264[0];
			fRec1266[1] = fRec1266[0];
			fRec1267[1] = fRec1267[0];
			fRec1269[1] = fRec1269[0];
			fRec1270[1] = fRec1270[0];
			fRec1272[1] = fRec1272[0];
			fRec1273[1] = fRec1273[0];
			fRec1275[1] = fRec1275[0];
			fRec1276[1] = fRec1276[0];
			fRec1278[1] = fRec1278[0];
			fRec1279[1] = fRec1279[0];
			fRec1281[1] = fRec1281[0];
			fRec1282[1] = fRec1282[0];
			fRec1284[1] = fRec1284[0];
			fRec1285[1] = fRec1285[0];
			fRec1287[1] = fRec1287[0];
			fRec1288[1] = fRec1288[0];
			fRec1190[1] = fRec1190[0];
			fRec981[1] = fRec981[0];
			fRec1290[1] = fRec1290[0];
			fRec1291[1] = fRec1291[0];
			fRec1292[1] = fRec1292[0];
			fRec1293[1] = fRec1293[0];
			fRec978[1] = fRec978[0];
			fRec12[1] = fRec12[0];
			fRec9[1] = fRec9[0];
			fRec6[1] = fRec6[0];
			iRec4[1] = iRec4[0];
			fRec5[1] = fRec5[0];
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			fRec1294[1] = fRec1294[0];
			fRec0[1] = fRec0[0];
			fRec1303[1] = fRec1303[0];
			fRec1301[1] = fRec1301[0];
			iRec1299[1] = iRec1299[0];
			fRec1300[1] = fRec1300[0];
			fRec1297[1] = fRec1297[0];
			fRec1296[1] = fRec1296[0];
			fRec1295[1] = fRec1295[0];
			fRec1313[1] = fRec1313[0];
			fRec1311[1] = fRec1311[0];
			iRec1309[1] = iRec1309[0];
			fRec1310[1] = fRec1310[0];
			fRec1307[1] = fRec1307[0];
			fRec1306[1] = fRec1306[0];
			fRec1305[1] = fRec1305[0];
			fRec1323[1] = fRec1323[0];
			fRec1321[1] = fRec1321[0];
			iRec1319[1] = iRec1319[0];
			fRec1320[1] = fRec1320[0];
			fRec1317[1] = fRec1317[0];
			fRec1316[1] = fRec1316[0];
			fRec1315[1] = fRec1315[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "RITI_AutonomousNetwork_fixedVersion.dsp"
	#define FAUST_CLASS_NAME "mydsp"
	#define FAUST_COMPILATION_OPIONS "-a /usr/local/share/faust/juce/juce-plugin.cpp -lang cpp -i -scn base_dsp -es 1 -mcd 16 -uim -double -ftz 0"
	#define FAUST_INPUTS 8
	#define FAUST_OUTPUTS 4
	#define FAUST_ACTIVES 25
	#define FAUST_PASSIVES 52

	FAUST_ADDVERTICALSLIDER("[0]Mixer/Bandpass Filters Bank/BP Bypass", fVslider10, 0.0, 0.0, 1.0, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Bandpass Filters Bank/Bandwidth", fVslider14, 1.0, 1.0, 1e+02, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Bandpass Filters Bank/Frequency", fVslider13, 0.0, -1.0, 1.0, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Bandpass Filters Bank/Interpolations 1", fVslider11, 1.0, 0.0, 1.0, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Bandpass Filters Bank/Interpolations 2", fVslider12, 1.0, 0.0, 1.0, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Feedback Delay Network/Input Delays/Voice_0+1", fVslider20, 9.2528, 0.001, 12.0, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Feedback Delay Network/Input Delays/Voice_1+1", fVslider9, 6.9396, 0.001, 12.0, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Feedback Delay Network/Input Delays/Voice_2+1", fVslider18, 4.6264, 0.001, 12.0, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Feedback Delay Network/Input Delays/Voice_3+1", fVslider22, 2.3132, 0.001, 12.0, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Feedback Delay Network/Network FB", fVslider8, 1.0, 0.0, 1.0, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Feedback Delay Network/Output Delays/Voice_0+1", fVslider21, 2.8713, 0.001, 12.0, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Feedback Delay Network/Output Delays/Voice_1+1", fVslider17, 5.7426, 0.001, 12.0, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Feedback Delay Network/Output Delays/Voice_2+1", fVslider19, 8.613900000000001, 0.001, 12.0, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Feedback Delay Network/Output Delays/Voice_3+1", fVslider23, 11.4852, 0.001, 12.0, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Input-Output/Externals", fVslider5, -8e+01, -8e+01, 8e+01, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Input-Output/HP frequency", fVslider2, 1.0, 1.0, 2e+04, 1.0);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Input-Output/LP frequency", fVslider1, 2e+04, 1.0, 2e+04, 1.0);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Input-Output/Master", fVslider24, -8e+01, -8e+01, 0.0, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Interpolation/Smooth", fVslider0, 1.0, 0.001, 1e+01, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Lorenz Equation Parameters/Beta", fVslider16, 1.073, 0.2666, 5.066, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Lorenz Equation Parameters/Dt", fVslider6, 0.0, -6e+01, 6e+01, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Lorenz Equation Parameters/Lorenz FB", fVslider4, 1.0, 0.0, 1.0, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Lorenz Equation Parameters/Rho", fVslider15, 3.518, 2.8, 53.2, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Lorenz Equation Parameters/Sigma", fVslider7, 1e+01, 1.0, 19.0, 0.001);
	FAUST_ADDVERTICALSLIDER("[0]Mixer/Lorenz Equation Parameters/TanH", fVslider3, 5e+01, 1.0, 1e+02, 0.001);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Bandpass Filters/NetworkVoice_0[2]/X_1", fVbargraph28, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Bandpass Filters/NetworkVoice_0[2]/Y_1", fVbargraph32, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Bandpass Filters/NetworkVoice_0[2]/Z_1", fVbargraph35, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Bandpass Filters/NetworkVoice_1[2]/X_2", fVbargraph4, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Bandpass Filters/NetworkVoice_1[2]/Y_2", fVbargraph8, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Bandpass Filters/NetworkVoice_1[2]/Z_2", fVbargraph11, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Bandpass Filters/NetworkVoice_2[2]/X_3", fVbargraph16, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Bandpass Filters/NetworkVoice_2[2]/Y_3", fVbargraph20, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Bandpass Filters/NetworkVoice_2[2]/Z_3", fVbargraph23, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Bandpass Filters/NetworkVoice_3[2]/X_4", fVbargraph40, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Bandpass Filters/NetworkVoice_3[2]/Y_4", fVbargraph44, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Bandpass Filters/NetworkVoice_3[2]/Z_4", fVbargraph47, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/DC Blocker/NetworkVoice_0[2]/X_1", fVbargraph26, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/DC Blocker/NetworkVoice_0[2]/Y_1", fVbargraph30, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/DC Blocker/NetworkVoice_0[2]/Z_1", fVbargraph33, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/DC Blocker/NetworkVoice_1[2]/X_2", fVbargraph2, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/DC Blocker/NetworkVoice_1[2]/Y_2", fVbargraph6, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/DC Blocker/NetworkVoice_1[2]/Z_2", fVbargraph9, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/DC Blocker/NetworkVoice_2[2]/X_3", fVbargraph14, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/DC Blocker/NetworkVoice_2[2]/Y_3", fVbargraph18, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/DC Blocker/NetworkVoice_2[2]/Z_3", fVbargraph21, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/DC Blocker/NetworkVoice_3[2]/X_4", fVbargraph38, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/DC Blocker/NetworkVoice_3[2]/Y_4", fVbargraph42, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/DC Blocker/NetworkVoice_3[2]/Z_4", fVbargraph45, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Hyperbolic Tangent/NetworkVoice_0[2]/X_1", fVbargraph27, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Hyperbolic Tangent/NetworkVoice_0[2]/Y_1", fVbargraph31, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Hyperbolic Tangent/NetworkVoice_0[2]/Z_1", fVbargraph34, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Hyperbolic Tangent/NetworkVoice_1[2]/X_2", fVbargraph3, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Hyperbolic Tangent/NetworkVoice_1[2]/Y_2", fVbargraph7, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Hyperbolic Tangent/NetworkVoice_1[2]/Z_2", fVbargraph10, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Hyperbolic Tangent/NetworkVoice_2[2]/X_3", fVbargraph15, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Hyperbolic Tangent/NetworkVoice_2[2]/Y_3", fVbargraph19, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Hyperbolic Tangent/NetworkVoice_2[2]/Z_3", fVbargraph22, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Hyperbolic Tangent/NetworkVoice_3[2]/X_4", fVbargraph39, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Hyperbolic Tangent/NetworkVoice_3[2]/Y_4", fVbargraph43, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Hyperbolic Tangent/NetworkVoice_3[2]/Z_4", fVbargraph46, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Lorenz Feedback/NetworkVoice_0[2]/X_1", fVbargraph24, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Lorenz Feedback/NetworkVoice_0[2]/Y_1", fVbargraph25, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Lorenz Feedback/NetworkVoice_0[2]/Z_1", fVbargraph29, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Lorenz Feedback/NetworkVoice_1[2]/X_2", fVbargraph0, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Lorenz Feedback/NetworkVoice_1[2]/Y_2", fVbargraph1, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Lorenz Feedback/NetworkVoice_1[2]/Z_2", fVbargraph5, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Lorenz Feedback/NetworkVoice_2[2]/X_3", fVbargraph12, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Lorenz Feedback/NetworkVoice_2[2]/Y_3", fVbargraph13, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Lorenz Feedback/NetworkVoice_2[2]/Z_3", fVbargraph17, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Lorenz Feedback/NetworkVoice_3[2]/X_4", fVbargraph36, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Lorenz Feedback/NetworkVoice_3[2]/Y_4", fVbargraph37, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Lorenz Feedback/NetworkVoice_3[2]/Z_4", fVbargraph41, 0.0, 1e+03);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Output Channels/1", fVbargraph48, 0.0, 1.0);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Output Channels/2", fVbargraph49, 0.0, 1.0);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Output Channels/3", fVbargraph50, 0.0, 1.0);
	FAUST_ADDVERTICALBARGRAPH("[2]Inspectors/Output Channels/4", fVbargraph51, 0.0, 1.0);

	#define FAUST_LIST_ACTIVES(p) \
		p(VERTICALSLIDER, BP_Bypass, "[0]Mixer/Bandpass Filters Bank/BP Bypass", fVslider10, 0.0, 0.0, 1.0, 0.001) \
		p(VERTICALSLIDER, Bandwidth, "[0]Mixer/Bandpass Filters Bank/Bandwidth", fVslider14, 1.0, 1.0, 1e+02, 0.001) \
		p(VERTICALSLIDER, Frequency, "[0]Mixer/Bandpass Filters Bank/Frequency", fVslider13, 0.0, -1.0, 1.0, 0.001) \
		p(VERTICALSLIDER, Interpolations_1, "[0]Mixer/Bandpass Filters Bank/Interpolations 1", fVslider11, 1.0, 0.0, 1.0, 0.001) \
		p(VERTICALSLIDER, Interpolations_2, "[0]Mixer/Bandpass Filters Bank/Interpolations 2", fVslider12, 1.0, 0.0, 1.0, 0.001) \
		p(VERTICALSLIDER, Voice_0+1, "[0]Mixer/Feedback Delay Network/Input Delays/Voice_0+1", fVslider20, 9.2528, 0.001, 12.0, 0.001) \
		p(VERTICALSLIDER, Voice_1+1, "[0]Mixer/Feedback Delay Network/Input Delays/Voice_1+1", fVslider9, 6.9396, 0.001, 12.0, 0.001) \
		p(VERTICALSLIDER, Voice_2+1, "[0]Mixer/Feedback Delay Network/Input Delays/Voice_2+1", fVslider18, 4.6264, 0.001, 12.0, 0.001) \
		p(VERTICALSLIDER, Voice_3+1, "[0]Mixer/Feedback Delay Network/Input Delays/Voice_3+1", fVslider22, 2.3132, 0.001, 12.0, 0.001) \
		p(VERTICALSLIDER, Network_FB, "[0]Mixer/Feedback Delay Network/Network FB", fVslider8, 1.0, 0.0, 1.0, 0.001) \
		p(VERTICALSLIDER, Voice_0+1, "[0]Mixer/Feedback Delay Network/Output Delays/Voice_0+1", fVslider21, 2.8713, 0.001, 12.0, 0.001) \
		p(VERTICALSLIDER, Voice_1+1, "[0]Mixer/Feedback Delay Network/Output Delays/Voice_1+1", fVslider17, 5.7426, 0.001, 12.0, 0.001) \
		p(VERTICALSLIDER, Voice_2+1, "[0]Mixer/Feedback Delay Network/Output Delays/Voice_2+1", fVslider19, 8.613900000000001, 0.001, 12.0, 0.001) \
		p(VERTICALSLIDER, Voice_3+1, "[0]Mixer/Feedback Delay Network/Output Delays/Voice_3+1", fVslider23, 11.4852, 0.001, 12.0, 0.001) \
		p(VERTICALSLIDER, Externals, "[0]Mixer/Input-Output/Externals", fVslider5, -8e+01, -8e+01, 8e+01, 0.001) \
		p(VERTICALSLIDER, HP_frequency, "[0]Mixer/Input-Output/HP frequency", fVslider2, 1.0, 1.0, 2e+04, 1.0) \
		p(VERTICALSLIDER, LP_frequency, "[0]Mixer/Input-Output/LP frequency", fVslider1, 2e+04, 1.0, 2e+04, 1.0) \
		p(VERTICALSLIDER, Master, "[0]Mixer/Input-Output/Master", fVslider24, -8e+01, -8e+01, 0.0, 0.001) \
		p(VERTICALSLIDER, Smooth, "[0]Mixer/Interpolation/Smooth", fVslider0, 1.0, 0.001, 1e+01, 0.001) \
		p(VERTICALSLIDER, Beta, "[0]Mixer/Lorenz Equation Parameters/Beta", fVslider16, 1.073, 0.2666, 5.066, 0.001) \
		p(VERTICALSLIDER, Dt, "[0]Mixer/Lorenz Equation Parameters/Dt", fVslider6, 0.0, -6e+01, 6e+01, 0.001) \
		p(VERTICALSLIDER, Lorenz_FB, "[0]Mixer/Lorenz Equation Parameters/Lorenz FB", fVslider4, 1.0, 0.0, 1.0, 0.001) \
		p(VERTICALSLIDER, Rho, "[0]Mixer/Lorenz Equation Parameters/Rho", fVslider15, 3.518, 2.8, 53.2, 0.001) \
		p(VERTICALSLIDER, Sigma, "[0]Mixer/Lorenz Equation Parameters/Sigma", fVslider7, 1e+01, 1.0, 19.0, 0.001) \
		p(VERTICALSLIDER, TanH, "[0]Mixer/Lorenz Equation Parameters/TanH", fVslider3, 5e+01, 1.0, 1e+02, 0.001) \

	#define FAUST_LIST_PASSIVES(p) \
		p(VERTICALBARGRAPH, X_1, "[2]Inspectors/Bandpass Filters/NetworkVoice_0[2]/X_1", fVbargraph28, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Y_1, "[2]Inspectors/Bandpass Filters/NetworkVoice_0[2]/Y_1", fVbargraph32, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Z_1, "[2]Inspectors/Bandpass Filters/NetworkVoice_0[2]/Z_1", fVbargraph35, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, X_2, "[2]Inspectors/Bandpass Filters/NetworkVoice_1[2]/X_2", fVbargraph4, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Y_2, "[2]Inspectors/Bandpass Filters/NetworkVoice_1[2]/Y_2", fVbargraph8, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Z_2, "[2]Inspectors/Bandpass Filters/NetworkVoice_1[2]/Z_2", fVbargraph11, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, X_3, "[2]Inspectors/Bandpass Filters/NetworkVoice_2[2]/X_3", fVbargraph16, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Y_3, "[2]Inspectors/Bandpass Filters/NetworkVoice_2[2]/Y_3", fVbargraph20, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Z_3, "[2]Inspectors/Bandpass Filters/NetworkVoice_2[2]/Z_3", fVbargraph23, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, X_4, "[2]Inspectors/Bandpass Filters/NetworkVoice_3[2]/X_4", fVbargraph40, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Y_4, "[2]Inspectors/Bandpass Filters/NetworkVoice_3[2]/Y_4", fVbargraph44, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Z_4, "[2]Inspectors/Bandpass Filters/NetworkVoice_3[2]/Z_4", fVbargraph47, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, X_1, "[2]Inspectors/DC Blocker/NetworkVoice_0[2]/X_1", fVbargraph26, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Y_1, "[2]Inspectors/DC Blocker/NetworkVoice_0[2]/Y_1", fVbargraph30, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Z_1, "[2]Inspectors/DC Blocker/NetworkVoice_0[2]/Z_1", fVbargraph33, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, X_2, "[2]Inspectors/DC Blocker/NetworkVoice_1[2]/X_2", fVbargraph2, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Y_2, "[2]Inspectors/DC Blocker/NetworkVoice_1[2]/Y_2", fVbargraph6, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Z_2, "[2]Inspectors/DC Blocker/NetworkVoice_1[2]/Z_2", fVbargraph9, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, X_3, "[2]Inspectors/DC Blocker/NetworkVoice_2[2]/X_3", fVbargraph14, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Y_3, "[2]Inspectors/DC Blocker/NetworkVoice_2[2]/Y_3", fVbargraph18, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Z_3, "[2]Inspectors/DC Blocker/NetworkVoice_2[2]/Z_3", fVbargraph21, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, X_4, "[2]Inspectors/DC Blocker/NetworkVoice_3[2]/X_4", fVbargraph38, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Y_4, "[2]Inspectors/DC Blocker/NetworkVoice_3[2]/Y_4", fVbargraph42, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Z_4, "[2]Inspectors/DC Blocker/NetworkVoice_3[2]/Z_4", fVbargraph45, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, X_1, "[2]Inspectors/Hyperbolic Tangent/NetworkVoice_0[2]/X_1", fVbargraph27, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Y_1, "[2]Inspectors/Hyperbolic Tangent/NetworkVoice_0[2]/Y_1", fVbargraph31, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Z_1, "[2]Inspectors/Hyperbolic Tangent/NetworkVoice_0[2]/Z_1", fVbargraph34, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, X_2, "[2]Inspectors/Hyperbolic Tangent/NetworkVoice_1[2]/X_2", fVbargraph3, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Y_2, "[2]Inspectors/Hyperbolic Tangent/NetworkVoice_1[2]/Y_2", fVbargraph7, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Z_2, "[2]Inspectors/Hyperbolic Tangent/NetworkVoice_1[2]/Z_2", fVbargraph10, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, X_3, "[2]Inspectors/Hyperbolic Tangent/NetworkVoice_2[2]/X_3", fVbargraph15, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Y_3, "[2]Inspectors/Hyperbolic Tangent/NetworkVoice_2[2]/Y_3", fVbargraph19, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Z_3, "[2]Inspectors/Hyperbolic Tangent/NetworkVoice_2[2]/Z_3", fVbargraph22, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, X_4, "[2]Inspectors/Hyperbolic Tangent/NetworkVoice_3[2]/X_4", fVbargraph39, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Y_4, "[2]Inspectors/Hyperbolic Tangent/NetworkVoice_3[2]/Y_4", fVbargraph43, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Z_4, "[2]Inspectors/Hyperbolic Tangent/NetworkVoice_3[2]/Z_4", fVbargraph46, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, X_1, "[2]Inspectors/Lorenz Feedback/NetworkVoice_0[2]/X_1", fVbargraph24, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Y_1, "[2]Inspectors/Lorenz Feedback/NetworkVoice_0[2]/Y_1", fVbargraph25, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Z_1, "[2]Inspectors/Lorenz Feedback/NetworkVoice_0[2]/Z_1", fVbargraph29, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, X_2, "[2]Inspectors/Lorenz Feedback/NetworkVoice_1[2]/X_2", fVbargraph0, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Y_2, "[2]Inspectors/Lorenz Feedback/NetworkVoice_1[2]/Y_2", fVbargraph1, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Z_2, "[2]Inspectors/Lorenz Feedback/NetworkVoice_1[2]/Z_2", fVbargraph5, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, X_3, "[2]Inspectors/Lorenz Feedback/NetworkVoice_2[2]/X_3", fVbargraph12, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Y_3, "[2]Inspectors/Lorenz Feedback/NetworkVoice_2[2]/Y_3", fVbargraph13, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Z_3, "[2]Inspectors/Lorenz Feedback/NetworkVoice_2[2]/Z_3", fVbargraph17, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, X_4, "[2]Inspectors/Lorenz Feedback/NetworkVoice_3[2]/X_4", fVbargraph36, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Y_4, "[2]Inspectors/Lorenz Feedback/NetworkVoice_3[2]/Y_4", fVbargraph37, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, Z_4, "[2]Inspectors/Lorenz Feedback/NetworkVoice_3[2]/Z_4", fVbargraph41, 0.0, 0.0, 1e+03, 0.0) \
		p(VERTICALBARGRAPH, 1, "[2]Inspectors/Output Channels/1", fVbargraph48, 0.0, 0.0, 1.0, 0.0) \
		p(VERTICALBARGRAPH, 2, "[2]Inspectors/Output Channels/2", fVbargraph49, 0.0, 0.0, 1.0, 0.0) \
		p(VERTICALBARGRAPH, 3, "[2]Inspectors/Output Channels/3", fVbargraph50, 0.0, 0.0, 1.0, 0.0) \
		p(VERTICALBARGRAPH, 4, "[2]Inspectors/Output Channels/4", fVbargraph51, 0.0, 0.0, 1.0, 0.0) \

#endif

#if defined(JUCE_POLY)

struct FaustSound : public juce::SynthesiserSound {
    
    bool appliesToNote (int /*midiNoteNumber*/) override        { return true; }
    bool appliesToChannel (int /*midiChannel*/) override        { return true; }
};

// An hybrid JUCE and Faust voice

class FaustVoice : public juce::SynthesiserVoice, public dsp_voice {
    
    private:
        
        std::unique_ptr<juce::AudioBuffer<FAUSTFLOAT>> fBuffer;
        
    public:
        
        FaustVoice(base_dsp* base_dsp):dsp_voice(base_dsp)
        {
            // Allocate buffer for mixing
            fBuffer = std::make_unique<juce::AudioBuffer<FAUSTFLOAT>>(base_dsp->getNumOutputs(), 8192);
            fDSP->init(juce::SynthesiserVoice::getSampleRate());
        }
        
        bool canPlaySound (juce::SynthesiserSound* sound) override
        {
            return dynamic_cast<FaustSound*> (sound) != nullptr;
        }
        
        void startNote (int midiNoteNumber,
                        float velocity,
                        juce::SynthesiserSound* s,
                        int currentPitchWheelPosition) override
        {
            // Note is triggered
            keyOn(midiNoteNumber, velocity);
        }
        
        void stopNote (float velocity, bool allowTailOff) override
        {
            keyOff(!allowTailOff);
        }
        
        void pitchWheelMoved (int newPitchWheelValue) override
        {
            // not implemented for now
        }
        
        void controllerMoved (int controllerNumber, int newControllerValue) override
        {
            // not implemented for now
        }
        
        void renderNextBlock (juce::AudioBuffer<FAUSTFLOAT>& outputBuffer,
                              int startSample,
                              int numSamples) override
        {
            // Only plays when the voice is active
            if (isVoiceActive()) {
                
                // Play the voice
                compute(numSamples, nullptr, (FAUSTFLOAT**)fBuffer->getArrayOfWritePointers());
                
                // Mix it in outputs
                for (int i = 0; i < fDSP->getNumOutputs(); i++) {
                    outputBuffer.addFrom(i, startSample, *fBuffer, i, 0, numSamples);
                }
            }
        }
    
};

// Decorates the JUCE Synthesiser and adds Faust polyphonic code for GUI handling

class FaustSynthesiser : public juce::Synthesiser, public dsp_voice_group {
    
    private:
        
        juce::Synthesiser fSynth;
    
        static void panic(float val, void* arg)
        {
            static_cast<FaustSynthesiser*>(arg)->allNotesOff(0, false); // 0 stops all voices
        }
  
    public:
        
        FaustSynthesiser():dsp_voice_group(panic, this, true, true)
        {
            setNoteStealingEnabled(true);
        }
        
        virtual ~FaustSynthesiser()
        {
            // Voices will be deallocated by fSynth
            dsp_voice_group::clearVoices();
        }
        
        void addVoice(FaustVoice* voice)
        {
            fSynth.addVoice(voice);
            dsp_voice_group::addVoice(voice);
        }
        
        void addSound(juce::SynthesiserSound* sound)
        {
            fSynth.addSound(sound);
        }
        
        void allNotesOff(int midiChannel, bool allowTailOff)
        {
            fSynth.allNotesOff(midiChannel, allowTailOff);
        }
        
        void setCurrentPlaybackSampleRate (double newRate)
        {
            fSynth.setCurrentPlaybackSampleRate(newRate);
        }
        
        void renderNextBlock (juce::AudioBuffer<float>& outputAudio,
                              const juce::MidiBuffer& inputMidi,
                              int startSample,
                              int numSamples)
        {
            fSynth.renderNextBlock(outputAudio, inputMidi, startSample, numSamples);
        }
        
        void renderNextBlock (juce::AudioBuffer<double>& outputAudio,
                              const juce::MidiBuffer& inputMidi,
                              int startSample,
                              int numSamples)
        {
            fSynth.renderNextBlock(outputAudio, inputMidi, startSample, numSamples);
        }
    
};

#endif

// Using the PluginGuiMagic project (https://foleysfinest.com/developer/pluginguimagic/)

#if defined(PLUGIN_MAGIC)

class FaustPlugInAudioProcessor : public foleys::MagicProcessor, private juce::Timer
{
    
    public:
        FaustPlugInAudioProcessor();
        virtual ~FaustPlugInAudioProcessor() {}
        
        void prepareToPlay (double sampleRate, int samplesPerBlock) override;
        
        bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
        
        void processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) override
        {
            jassert (! isUsingDoublePrecision());
            process (buffer, midiMessages);
    #ifdef MAGIC_LEVEL_SOURCE
            fOutputMeter->pushSamples(buffer);
    #endif
        }
        
        void processBlock (juce::AudioBuffer<double>& buffer, juce::MidiBuffer& midiMessages) override
        {
            jassert (isUsingDoublePrecision());
            process (buffer, midiMessages);
        }
        
        const juce::String getName() const override;
        
        bool acceptsMidi() const override;
        bool producesMidi() const override;
        double getTailLengthSeconds() const override;
        
        int getNumPrograms() override;
        int getCurrentProgram() override;
        void setCurrentProgram (int index) override;
        const juce::String getProgramName (int index) override;
        void changeProgramName (int index, const juce::String& newName) override;
        
        void releaseResources() override
        {}
        
        void timerCallback() override;
        
        juce::AudioProcessor::BusesProperties getBusesProperties();
        bool supportsDoublePrecisionProcessing() const override;
      
    #ifdef MAGIC_LEVEL_SOURCE
        foleys::MagicLevelSource* fOutputMeter = nullptr;
    #endif
        juce::AudioProcessorValueTreeState treeState{ *this, nullptr };
    
    #ifdef JUCE_POLY
        std::unique_ptr<FaustSynthesiser> fSynth;
    #else
    #if defined(MIDICTRL)
        std::unique_ptr<juce_midi_handler> fMIDIHandler;
        std::unique_ptr<MidiUI> fMIDIUI;
    #endif
        std::unique_ptr<base_dsp> fDSP;
    #endif
        
    #if defined(OSCCTRL)
        std::unique_ptr<JuceOSCUI> fOSCUI;
    #endif
        
    #if defined(SOUNDFILE)
        std::unique_ptr<SoundUI> fSoundUI;
    #endif
        
        JuceStateUI fStateUI;
        JuceParameterUI fParameterUI;
        
        std::atomic<bool> fFirstCall = true;
        
    private:
        
        template <typename FloatType>
        void process (juce::AudioBuffer<FloatType>& buffer, juce::MidiBuffer& midiMessages);
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FaustPlugInAudioProcessor)
    
};

#else

class FaustPlugInAudioProcessor : public juce::AudioProcessor, private juce::Timer
{

    public:
        
        FaustPlugInAudioProcessor();
        virtual ~FaustPlugInAudioProcessor() {}
        
        void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    
        bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
        
        void processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) override
        {
            jassert (! isUsingDoublePrecision());
            process (buffer, midiMessages);
        }
        
        void processBlock (juce::AudioBuffer<double>& buffer, juce::MidiBuffer& midiMessages) override
        {
            jassert (isUsingDoublePrecision());
            process (buffer, midiMessages);
        }
    
        juce::AudioProcessorEditor* createEditor() override;
        bool hasEditor() const override;
        
        const juce::String getName() const override;
        
        bool acceptsMidi() const override;
        bool producesMidi() const override;
        double getTailLengthSeconds() const override;
        
        int getNumPrograms() override;
        int getCurrentProgram() override;
        void setCurrentProgram (int index) override;
        const juce::String getProgramName (int index) override;
        void changeProgramName (int index, const juce::String& newName) override;
        
        void getStateInformation (juce::MemoryBlock& destData) override;
        void setStateInformation (const void* data, int sizeInBytes) override;
    
        void releaseResources() override
        {}
        
        void timerCallback() override;
    
        juce::AudioProcessor::BusesProperties getBusesProperties();
        bool supportsDoublePrecisionProcessing() const override;
    
    #ifdef JUCE_POLY
        std::unique_ptr<FaustSynthesiser> fSynth;
    #else
    #if defined(MIDICTRL)
        std::unique_ptr<juce_midi_handler> fMIDIHandler;
        std::unique_ptr<MidiUI> fMIDIUI;
    #endif
        std::unique_ptr<base_dsp> fDSP;
    #endif
        
    #if defined(OSCCTRL)
        std::unique_ptr<JuceOSCUI> fOSCUI;
    #endif
    
    #if defined(SOUNDFILE)
        std::unique_ptr<SoundUI> fSoundUI;
    #endif
    
        JuceStateUI fStateUI;
        JuceParameterUI fParameterUI;
    
        std::atomic<bool> fFirstCall = true;
    
    private:
    
        template <typename FloatType>
        void process (juce::AudioBuffer<FloatType>& buffer, juce::MidiBuffer& midiMessages);
    
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FaustPlugInAudioProcessor)
    
};

#endif

class FaustPlugInAudioProcessorEditor : public juce::AudioProcessorEditor
{
    
    public:
        
        FaustPlugInAudioProcessorEditor (FaustPlugInAudioProcessor&);
        virtual ~FaustPlugInAudioProcessorEditor() {}
        
        void paint (juce::Graphics&) override;
        void resized() override;
        
    private:
        
        // This reference is provided as a quick way for your editor to
        // access the processor object that created it.
        FaustPlugInAudioProcessor& processor;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FaustPlugInAudioProcessorEditor)
#ifndef PLUGIN_MAGIC        
        JuceGUI fJuceGUI;
#endif    
};

#ifndef PLUGIN_MAGIC
FaustPlugInAudioProcessor::FaustPlugInAudioProcessor()
: juce::AudioProcessor (getBusesProperties()), fParameterUI(this)
#else
FaustPlugInAudioProcessor::FaustPlugInAudioProcessor()
: foleys::MagicProcessor (getBusesProperties()), fParameterUI(this)	
#endif
{
    bool midi_sync = false;
    int nvoices = 0;
    
    mydsp* tmp_dsp = new mydsp();
    MidiMeta::analyse(tmp_dsp, midi_sync, nvoices);
    delete tmp_dsp;
	
#ifdef PLUGIN_MAGIC
#ifdef MAGIC_LOAD_BINARY
    // change magic_xml and magic_xmlSize to match the name of your included
    // XML file from Plugin GUI Magic
    magicState.setGuiValueTree(BinaryData::magic_xml, BinaryData::magic_xmlSize);
#endif
// put other GUI Magic sources here, similar to expression below.
#ifdef MAGIC_LEVEL_SOURCE
    fOutputMeter = magicState.createAndAddObject<foleys::MagicLevelSource>("output");
#endif
#endif
   
#ifdef JUCE_POLY
    assert(nvoices > 0);
    fSynth = std::make_unique<FaustSynthesiser>();
    for (int i = 0; i < nvoices; i++) {
        fSynth->addVoice(new FaustVoice(new mydsp()));
    }
    fSynth->init();
    fSynth->addSound(new FaustSound());
#else
    
    bool group = true;
    
#ifdef POLY2
    assert(nvoices > 0);
    std::cout << "Started with " << nvoices << " voices\n";
    base_dsp* base_dsp = new mydsp_poly(new mydsp(), nvoices, true, group);
    
#if MIDICTRL
    if (midi_sync) {
        fDSP = std::make_unique<timed_dsp>(new dsp_sequencer(base_dsp, new effect()));
    } else {
        fDSP = std::make_unique<dsp_sequencer>(base_dsp, new effect());
    }
#else
    fDSP = std::make_unique<dsp_sequencer>(base_dsp, new effects());
#endif
    
#else
    if (nvoices > 0) {
        std::cout << "Started with " << nvoices << " voices\n";
        base_dsp* base_dsp = new mydsp_poly(new mydsp(), nvoices, true, group);
        
#if MIDICTRL
        if (midi_sync) {
            fDSP = std::make_unique<timed_dsp>(base_dsp);
        } else {
            fDSP = std::make_unique<decorator_dsp>(base_dsp);
        }
#else
        fDSP = std::make_unique<decorator_dsp>(base_dsp);
#endif
    } else {
#if MIDICTRL
        if (midi_sync) {
            fDSP = std::make_unique<timed_dsp>(new mydsp());
        } else {
            fDSP = std::make_unique<mydsp>();
        }
#else
        fDSP = std::make_unique<mydsp>();
#endif
    }
    
#endif
    
#if defined(MIDICTRL)
    fMIDIHandler = std::make_unique<juce_midi_handler>();
    fMIDIUI = std::make_unique<MidiUI>(fMIDIHandler.get());
    fDSP->buildUserInterface(fMIDIUI.get());
    if (!fMIDIUI->run()) {
        std::cerr << "JUCE MIDI handler cannot be started..." << std::endl;
    }
#endif
    
#endif
    
#if defined(OSCCTRL)
    fOSCUI = std::make_unique<JuceOSCUI>("127.0.0.1", 5510, 5511);
#ifdef JUCE_POLY
    fSynth->buildUserInterface(fOSCUI.get());
#else
    fDSP->buildUserInterface(fOSCUI.get());
#endif
    if (!fOSCUI->run()) {
        std::cerr << "JUCE OSC handler cannot be started..." << std::endl;
    }
#endif
    
#if defined(SOUNDFILE)
    // Use bundle path
    auto file = juce::File::getSpecialLocation(juce::File::currentExecutableFile)
        .getParentDirectory().getParentDirectory().getChildFile("Resources");
    fSoundUI = std::make_unique<SoundUI>(file.getFullPathName().toStdString());
    fDSP->buildUserInterface(fSoundUI.get());
#endif
    
#ifdef JUCE_POLY
    fSynth->buildUserInterface(&fStateUI);
    fSynth->buildUserInterface(&fParameterUI);
    // When no previous state was restored, init DSP controllers with their default values
    if (!fStateUI.fRestored) {
        fSynth->instanceResetUserInterface();
    }
#else
    fDSP->buildUserInterface(&fStateUI);
    fDSP->buildUserInterface(&fParameterUI);
    // When no previous state was restored, init DSP controllers with their default values
    if (!fStateUI.fRestored) {
        fDSP->instanceResetUserInterface();
    }
#endif
    
    startTimerHz(25);
}

juce::AudioProcessor::BusesProperties FaustPlugInAudioProcessor::getBusesProperties()
{
    if (juce::PluginHostType::getPluginLoadedAs() == wrapperType_Standalone) {
        if (FAUST_INPUTS == 0) {
            return BusesProperties().withOutput("Output", juce::AudioChannelSet::discreteChannels(std::min<int>(2, FAUST_OUTPUTS)), true);
        } else {
            return BusesProperties()
            .withInput("Input", juce::AudioChannelSet::discreteChannels(std::min<int>(2, FAUST_INPUTS)), true)
            .withOutput("Output", juce::AudioChannelSet::discreteChannels(std::min<int>(2, FAUST_OUTPUTS)), true);
        }
    } else {
        if (FAUST_INPUTS == 0) {
            return BusesProperties().withOutput("Output", juce::AudioChannelSet::discreteChannels(FAUST_OUTPUTS), true);
        } else {
            return BusesProperties()
            .withInput("Input", juce::AudioChannelSet::discreteChannels(FAUST_INPUTS), true)
            .withOutput("Output", juce::AudioChannelSet::discreteChannels(FAUST_OUTPUTS), true);
        }
    }
}

void FaustPlugInAudioProcessor::timerCallback()
{
    GUI::updateAllGuis();
}

//==============================================================================
const juce::String FaustPlugInAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool FaustPlugInAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool FaustPlugInAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

double FaustPlugInAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int FaustPlugInAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
    // so this should be at least 1, even if you're not really implementing programs.
}

int FaustPlugInAudioProcessor::getCurrentProgram()
{
    return 0;
}

void FaustPlugInAudioProcessor::setCurrentProgram (int index)
{}

const juce::String FaustPlugInAudioProcessor::getProgramName (int index)
{
    return juce::String();
}

void FaustPlugInAudioProcessor::changeProgramName (int index, const juce::String& newName)
{}

bool FaustPlugInAudioProcessor::supportsDoublePrecisionProcessing() const
{
    return sizeof(FAUSTFLOAT) == 8;
}

//==============================================================================
void FaustPlugInAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Reset DSP adaptation
    fFirstCall = true;
    
#ifdef JUCE_POLY
    fSynth->setCurrentPlaybackSampleRate (sampleRate);
#else
    
    // Setting the DSP control values has already been done
    // by 'buildUserInterface(&fStateUI)', using the saved values or the default ones.
    // What has to be done to finish the DSP initialization is done now.
    mydsp::classInit(int(sampleRate));
    fDSP->instanceConstants(int(sampleRate));
    fDSP->instanceClear();
    
    // Get latency metadata
    struct LatencyMeta : public Meta {
        
        float fLatencyFrames = -1.f;
        float fLatencySec = -1.f;
        
        void declare(const char* key, const char* value)
        {
            if (std::string(key) == "latency_frames" || std::string(key) == "latency_samples") {
                fLatencyFrames = std::atof(value);
            } else if (std::string(key) == "latency_sec") {
                fLatencySec = std::atof(value);
            }
        }
    };
    
    LatencyMeta meta;
    fDSP->metadata(&meta);
    if (meta.fLatencyFrames > 0) {
        setLatencySamples(meta.fLatencyFrames);
    } else if (meta.fLatencySec > 0) {
        setLatencySamples(meta.fLatencySec * sampleRate);
    }
    
#endif
#ifdef MAGIC_LEVEL_SOURCE
    magicState.prepareToPlay(sampleRate, samplesPerBlock);
    fOutputMeter->setupSource(getMainBusNumOutputChannels(), sampleRate, 500, 200);
#endif
}

bool FaustPlugInAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    // Always return true and have the DSP adapts its buffer layout with a dsp_adapter (see 'prepareToPlay' and 'process')
    return true;
}

template <typename FloatType>
void FaustPlugInAudioProcessor::process (juce::AudioBuffer<FloatType>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    
    /*
        prepareToPlay is possibly called several times with different values for sampleRate
        and isUsingDoublePrecision() state (this has been seen in particular with VTS3),
        making proper sample format (float/double) and the inputs/outputs layout adaptation
        more complex at this stage.
        
        So adapting the sample format (float/double) and the inputs/outputs layout is done
        once at first process call even if this possibly allocates memory, which is not RT safe.
    */
    if (fFirstCall) {
        fFirstCall = false;
        
        // Possible sample size adaptation
        if (supportsDoublePrecisionProcessing()) {
            if (isUsingDoublePrecision()) {
                // Nothing to do
            } else {
                fDSP = std::make_unique<dsp_sample_adapter<double, float>>(fDSP.release());
            }
        } else {
            if (isUsingDoublePrecision()) {
                fDSP = std::make_unique<dsp_sample_adapter<float, double>>(fDSP.release());
            } else {
                // Nothing to do
            }
        }
        
        // Possibly adapt DSP inputs/outputs number
        if (fDSP->getNumInputs() > getTotalNumInputChannels() || fDSP->getNumOutputs() > getTotalNumOutputChannels()) {
            fDSP = std::make_unique<dsp_adapter>(fDSP.release(), getTotalNumInputChannels(), getTotalNumOutputChannels(), 4096);
        }
    }
    
#ifdef JUCE_POLY
    fSynth->renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
#else
#if defined(MIDICTRL)
    // Read MIDI input events from midiMessages
    fMIDIHandler->decodeBuffer(midiMessages);
    // Then write MIDI output events to midiMessages
    fMIDIHandler->encodeBuffer(midiMessages);
#endif
    // MIDI timestamp is expressed in frames
    fDSP->compute(-1, buffer.getNumSamples(),
                  (FAUSTFLOAT**)buffer.getArrayOfReadPointers(),
                  (FAUSTFLOAT**)buffer.getArrayOfWritePointers());
#endif
}

//==============================================================================
#ifndef PLUGIN_MAGIC
bool FaustPlugInAudioProcessor::hasEditor() const
{
    return true;
}

juce::AudioProcessorEditor* FaustPlugInAudioProcessor::createEditor()
{
    return new FaustPlugInAudioProcessorEditor (*this);
}

//==============================================================================
void FaustPlugInAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    
    fStateUI.getStateInformation(destData);
}

void FaustPlugInAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    
    fStateUI.setStateInformation(data, sizeInBytes);
 }
#endif
//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FaustPlugInAudioProcessor();
}

//==============================================================================
#ifndef PLUGIN_MAGIC
FaustPlugInAudioProcessorEditor::FaustPlugInAudioProcessorEditor (FaustPlugInAudioProcessor& p)
: juce::AudioProcessorEditor (&p), processor (p)
{
#ifdef JUCE_POLY
    p.fSynth->buildUserInterface(&fJuceGUI);
#else
    p.fDSP->buildUserInterface(&fJuceGUI);
#endif
    
    addAndMakeVisible(fJuceGUI);
    
    juce::Rectangle<int> recommendedSize = fJuceGUI.getSize();
    setSize (recommendedSize.getWidth(), recommendedSize.getHeight());
}

//==============================================================================
void FaustPlugInAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::white);
}

void FaustPlugInAudioProcessorEditor::resized()
{
    fJuceGUI.setBounds(getLocalBounds());
}

#endif
// Globals
std::list<GUI*> GUI::fGuiList;
ztimedmap GUI::gTimedZoneMap;

#endif
