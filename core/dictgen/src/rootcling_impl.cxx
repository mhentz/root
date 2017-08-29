// Authors: Axel Naumann, Philippe Canal, Danilo Piparo

/*************************************************************************
 * Copyright (C) 1995-2016, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

const char *shortHelp =
   "Usage: rootcling [-v][-v0-4] [-f] [out.cxx] [opts] "
   "file1.h[+][-][!] file2.h[+][-][!] ...[LinkDef.h]\n";

// Write the help as a big string to have only one version of the documentation
const char *rootClingHelp =
   "This program generates the dictionaries needed for performing I/O of        \n"
   "classes. Rootcling can be used with an invocation like this one:            \n"
   "                                                                            \n"
   " rootcling [-v][-v0-4] [-f] [out.cxx] [opts] "
   "file1.h[+][-][!] file2.h[+][-][!] ...[LinkDef.h]\n"
   "                                                                            \n"
   "IMPORTANT:                                                                  \n"
   "1) LinkDef.h must be the last argument on the rootcling command line.       \n"
   "2) Note that the LinkDef file name must contain the string:                 \n"
   "   LinkDef.h, Linkdef.h or linkdef.h, i.e. NA49_LinkDef.h.                  \n"
   "                                                                            \n"
   "Before specifying the first header file one can also add include            \n"
   "file directories to be searched and preprocessor defines, like:             \n"
   "  -I$MYPROJECT/include -DDebug=1                                            \n"
   "                                                                            \n"
   "NOTA BENE: the dictionaries that will be used within the same project must  \n"
   "have unique names.                                                          \n"
   "                                                                            \n"
   "Options:                                                                    \n"
   "                                                                            \n"
   " -f\tOverwrite an existing output file.                                     \n"
   "  The output file must have the .cxx, .C, .cpp, .cc or .cp extension.       \n"
   "                                                                            \n"
   " -v\tThe verbose flags have the following meaning:                          \n"
   "  -v   Display all messages                                                 \n"
   "  -v0  Display no messages at all.                                          \n"
   "  -v1  Display only error messages (default).                               \n"
   "  -v2  Display error and warning messages.                                  \n"
   "  -v3  Display error, warning and note messages.                            \n"
   "  -v4  Display all messages                                                 \n"
   "                                                                            \n"
   " -m\tSpecify absolute or relative path Clang pcm file to be loaded.         \n"
   "  The pcm file (module) produced by this invocation of rootcling will       \n"
   "  not include any of the declarations already included in the pcm           \n"
   "  files loaded via -m.  There can be more than one -m.                      \n"
   "                                                                            \n"
   " -rmf\tRootmap file name.                                                   \n"
   "  Name of the rootmap file. In order to be picked up by ROOT it must have   \n"
   "  .rootmap extension.                                                       \n"
   "                                                                            \n"
   " -rml\tRootmap library name.                                                \n"
   "  Specify the name of the library which contains the autoload keys. This    \n"
   "  switch can be specified multiple times to autoload several libraries in   \n"
   "  presence of a particular key.                                             \n"
   "                                                                            \n"
   " -split\tSplit the dictionary.                                              \n"
   "  Split the dictionary in two, putting the ClassDef functions in a separate \n"
   "  file.                                                                     \n"
   "                                                                            \n"
   " -s\tTarget library name.                                                   \n"
   "  The flag -s must be followed by the name of the library that will         \n"
   "  contain the object file corresponding to the dictionary produced by       \n"
   "  this invocation of rootcling.                                             \n"
   "  The name takes priority over the one specified for the rootmapfile.       \n"
   "  The name influences the name of the created pcm:                          \n"
   "   1) If it is not specified, the pcm is called libINPUTHEADER_rdict.pcm    \n"
   "   2) If it is specified, the pcm is called libTARGETLIBRARY_rdict.pcm      \n"
   "      Any \"liblib\" occurence is transformed in the expected \"lib\".      \n"
   "   3) If this is specified in conjunction with --multiDict, the output is   \n"
   "      libTARGETLIBRARY_DICTIONARY_rdict.pcm                                 \n"
   "                                                                            \n"
   " -multiDict\tEnable support for multiple pcms in one library.               \n"
   "  Needs the -s flag. See its documentation.                                 \n"
   "                                                                            \n"
   " -inlineInputHeader\tAdd the argument header to the code of the dictionary. \n"
   "  This allows the header to be inlined within the dictionary.               \n"
   "                                                                            \n"
   " -interpreteronly\tNo IO information in the dictionary.                     \n"
   "                                                                            \n"
   " -noIncludePaths\tDo not store the headers' directories in the dictionary.  \n"
   "  Instead, rely on the environment variable $ROOT_INCLUDE_PATH at runtime.  \n"
   "                                                                            \n"
   " -excludePath\tSpecify a path to be excluded from the include paths         \n"
   "  specified for building this dictionary.                                   \n"
   "                                                                            \n"
   " --lib-list-prefix\t Specify libraries needed by the header files parsed.   \n"
   "  This feature is used by ACliC (the automatic library generator).          \n"
   "  Rootcling will read the content of xxx.in for a list of rootmap files (see\n"
   "  rlibmap). Rootcling will read these files and use them to deduce a list of\n"
   "  libraries that are needed to properly link and load this dictionary. This \n"
   "  list of libraries is saved in the first line of the file xxx.out; the     \n"
   "  remaining lines contains the list of classes for which this run of        \n"
   "  rootcling produced a dictionary.                                          \n"
   "                                                                            \n"
   "The options -p, -c, -l, -cint, -reflex and -gccxml are deprecated and       \n"
   "currently ignored.                                                          \n"
   "                                                                            \n"
   "The (optional) file LinkDef.h looks like:                                   \n"
   "                                                                            \n"
   "#ifdef __CLING__                                                            \n"
   "                                                                            \n"
   "#pragma link off all globals;                                               \n"
   "#pragma link off all classes;                                               \n"
   "#pragma link off all functions;                                             \n"
   "                                                                            \n"
   "#pragma link C++ class TAxis;                                               \n"
   "#pragma link C++ class TAttAxis-;                                           \n"
   "#pragma link C++ class TArrayC-!;                                           \n"
   "#pragma link C++ class AliEvent+;                                           \n"
   "                                                                            \n"
   "#pragma link C++ function StrDup;                                           \n"
   "#pragma link C++ function operator+(const TString&,const TString&);         \n"
   "                                                                            \n"
   "#pragma link C++ global gROOT;                                              \n"
   "#pragma link C++ global gEnv;                                               \n"
   "                                                                            \n"
   "#pragma link C++ enum EMessageTypes;                                        \n"
   "                                                                            \n"
   "#endif                                                                      \n"
   "                                                                            \n"
   "This file tells rootcling which classes will be persisted on disk and what  \n"
   "entities will trigger automatic load of the shared library which contains   \n"
   "it. A trailing - in the class name tells rootcling to not generate the      \n"
   "Streamer() method. This is necessary for those classes that need a          \n"
   "customized Streamer() method. A trailing ! in the class name tells rootcling\n"
   "to not generate the operator>>(TBuffer &b, MyClass *&obj) function. This is \n"
   "necessary to be able to write pointers to objects of classes not inheriting \n"
   "from TObject. See for an example the source of the TArrayF class.           \n"
   "If the class contains a ClassDef macro, a trailing + in the class           \n"
   "name tells rootcling to generate an automatic Streamer(), i.e. a            \n"
   "streamer that let ROOT do automatic schema evolution. Otherwise, a          \n"
   "trailing + in the class name tells rootcling to generate a ShowMember       \n"
   "function and a Shadow Class. The + option is mutually exclusive with        \n"
   "the - option. For legacy reasons it is not yet the default.                 \n"
   "When the linkdef file is not specified a default version exporting          \n"
   "the classes with the names equal to the include files minus the .h          \n"
   "is generated.                                                               \n"
   "                                                                            \n"
   "The default constructor used by the ROOT I/O can be customized by           \n"
   "using the rootcling pragma:                                                 \n"
   "   #pragma link C++ ioctortype UserClass;                                   \n"
   "For example, with this pragma and a class named MyClass,                    \n"
   "this method will called the first of the following 3                        \n"
   "constructors which exists and is public:                                    \n"
   "   MyClass(UserClass*);                                                     \n"
   "   MyClass(TRootIOCtor*);                                                   \n"
   "   MyClass(); // Or a constructor with all its arguments defaulted.         \n"
   "                                                                            \n"
   "When more than one pragma ioctortype is used, the first seen has            \n"
   "priority.  For example with:                                                \n"
   "   #pragma link C++ ioctortype UserClass1;                                  \n"
   "   #pragma link C++ ioctortype UserClass2;                                  \n"
   "                                                                            \n"
   "ROOT considers the constructors in this order:                              \n"
   "   MyClass(UserClass1*);                                                    \n"
   "   MyClass(UserClass2*);                                                    \n"
   "   MyClass(TRootIOCtor*);                                                   \n"
   "   MyClass(); // Or a constructor with all its arguments defaulted.         \n";


#include "rootcling_impl.h"

#include "RConfigure.h"
#include "RConfig.h"

#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <algorithm>
#include <stdio.h>

#include <errno.h>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <map>
#include <fstream>
#include <sys/stat.h>
#include <unordered_map>
#include <unordered_set>
#include <numeric>


#ifdef _WIN32
#ifdef system
#undef system
#endif
#include <windows.h>
#include <Tlhelp32.h> // for MAX_MODULE_NAME32
#include <process.h>
#define PATH_MAX _MAX_PATH
#ifdef interface
// prevent error coming from clang/AST/Attrs.inc
#undef interface
#endif
#endif

#ifdef __APPLE__
#include <libgen.h> // Needed for basename
#include <mach-o/dyld.h>
#endif

#if !defined(R__WIN32)
#include <limits.h>
#include <unistd.h>
#endif


#include "cling/Interpreter/Interpreter.h"
#include "cling/Interpreter/InterpreterCallbacks.h"
#include "cling/Interpreter/LookupHelper.h"
#include "cling/Interpreter/Value.h"
#include "clang/AST/CXXInheritance.h"
#include "clang/AST/Mangle.h"
#include "clang/Basic/Diagnostic.h"
#include "clang/Basic/MemoryBufferCache.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Lex/HeaderSearch.h"
#include "clang/Lex/Preprocessor.h"
#include "clang/Lex/ModuleMap.h"
#include "clang/Lex/Pragma.h"
#include "clang/Sema/Sema.h"
#include "clang/Serialization/ASTWriter.h"
#include "cling/Utils/AST.h"

#include "llvm/Bitcode/BitstreamWriter.h"
#include "llvm/Support/Path.h"

#include "RtypesCore.h"
#include "TModuleGenerator.h"
#include "TClassEdit.h"
#include "TClingUtils.h"
#include "RStl.h"
#include "XMLReader.h"
#include "LinkdefReader.h"
#include "DictSelectionReader.h"
#include "SelectionRules.h"
#include "Scanner.h"
#include "strlcpy.h"

#include "OptionParser.h"

#ifdef WIN32
const std::string gLibraryExtension(".dll");
#else
const std::string gLibraryExtension(".so");  // no dylib for the moment
#endif
const std::string gPathSeparator(ROOT::TMetaUtils::GetPathSeparator());

#ifdef __APPLE__
#include <libgen.h> // Needed for basename
#include <mach-o/dyld.h>
#endif

#if defined(R__WIN32)
#include "cygpath.h"
#define strcasecmp _stricmp
#define strncasecmp _strnicmp
#else
#include <unistd.h>
#endif

bool gBuildingROOT = false;
const ROOT::Internal::RootCling::DriverConfig* gDriverConfig = nullptr;

namespace {
   // Copy-pasted from TClass.h We cannot #include TClass.h because we are compiling in -fno-rtti mode
   template <typename T> struct IsPointerTClassCopy {
      enum { kVal = 0 };
   };
   template <typename T> struct IsPointerTClassCopy<T*> {
      enum { kVal = 1 };
   };
}

// Maybe too ugly? let's see how it performs.
using HeadersDeclsMap_t = std::map<std::string, std::list<std::string>>;

using namespace ROOT;
using namespace TClassEdit;

namespace std {}
using namespace std;

namespace genreflex {
   bool verbose = false;
}

////////////////////////////////////////////////////////////////////////////////

void SetRootSys();

ROOT::Internal::RootCling::TROOTSYSSetter::TROOTSYSSetter() {
   // rootcling's libCore needs "our" ROOTSYS:
   SetRootSys();
};

////////////////////////////////////////////////////////////////////////////////

void EmitStreamerInfo(const char *normName)
{
   if (gDriverConfig->fAddStreamerInfoToROOTFile)
      gDriverConfig->fAddStreamerInfoToROOTFile(normName);
}
static void EmitTypedefs(const std::vector<clang::TypedefNameDecl *> &tdvec)
{
   if (!gDriverConfig->fAddTypedefToROOTFile)
      return;
   for (const auto td : tdvec)
      gDriverConfig->fAddTypedefToROOTFile(td->getQualifiedNameAsString().c_str());
}
static void EmitEnums(const std::vector<clang::EnumDecl *> &enumvec)
{
   if (!gDriverConfig->fAddEnumToROOTFile)
      return;
   for (const auto en : enumvec) {
      // Enums within tag decls are processed as part of the tag.
      if (clang::isa<clang::TranslationUnitDecl>(en->getDeclContext())
            || clang::isa<clang::LinkageSpecDecl>(en->getDeclContext())
            || clang::isa<clang::NamespaceDecl>(en->getDeclContext()))
         gDriverConfig->fAddEnumToROOTFile(en->getQualifiedNameAsString().c_str());
   }
}

////////////////////////////////////////////////////////////////////////////////

static void GetCurrentDirectory(std::string &output)
{
   char fixedLength[1024];
   char *currWorkDir = fixedLength;
   size_t len = 1024;
   char *result = currWorkDir;

   do {
      if (result == 0) {
         len = 2 * len;
         if (fixedLength != currWorkDir) {
            delete [] currWorkDir;
         }
         currWorkDir = new char[len];
      }
#ifdef WIN32
      result = ::_getcwd(currWorkDir, len);
#else
      result = getcwd(currWorkDir, len);
#endif
   } while (result == 0 && errno == ERANGE);

   output = currWorkDir;
   output += '/';
#ifdef WIN32
   // convert backslashes into forward slashes
   std::replace(output.begin(), output.end(), '\\', '/');
#endif

   if (fixedLength != currWorkDir) {
      delete [] currWorkDir;
   }
}

////////////////////////////////////////////////////////////////////////////////
/// Returns the executable path name, used e.g. by SetRootSys().

const char *GetExePath()
{
  static std::string exepath;
  if (exepath == "") {
#ifdef __APPLE__
    exepath = _dyld_get_image_name(0);
#endif
#if defined(__linux) || defined(__linux__)
    char linkname[PATH_MAX];  // /proc/<pid>/exe
    char buf[PATH_MAX];     // exe path name
    pid_t pid;

    // get our pid and build the name of the link in /proc
    pid = getpid();
    snprintf(linkname, PATH_MAX, "/proc/%i/exe", pid);
    int ret = readlink(linkname, buf, 1024);
    if (ret > 0 && ret < 1024) {
      buf[ret] = 0;
      exepath = buf;
    }
#endif
#ifdef _WIN32
    char *buf = new char[MAX_MODULE_NAME32 + 1];
      ::GetModuleFileName(NULL, buf, MAX_MODULE_NAME32 + 1);
      char *p = buf;
      while ((p = strchr(p, '\\')))
         * (p++) = '/';
      exepath = buf;
      delete[] buf;
#endif
  }
  return exepath.c_str();
}



////////////////////////////////////////////////////////////////////////////////
/// Convert to path relative to $PWD
/// If that's not what the caller wants, she should pass -I to rootcling and a
/// different relative path to the header files.

static std::string GetRelocatableHeaderName(const std::string &header, const std::string &currentDirectory)
{
   std::string result(header);

   const char *currWorkDir = currentDirectory.c_str();
   size_t lenCurrWorkDir = strlen(currWorkDir);
   if (result.substr(0, lenCurrWorkDir) == currWorkDir) {
      // Convert to path relative to $PWD.
      // If that's not what the caller wants, she should pass -I to rootcling and a
      // different relative path to the header files.
      result.erase(0, lenCurrWorkDir);
   }
   if (gBuildingROOT) {
      // For ROOT, convert module directories like core/base/inc/ to include/
      int posInc = result.find("/inc/");
      if (posInc != -1) {
         result = /*std::string("include") +*/ result.substr(posInc + 5, -1);
      }
   }
   return result;
}

////////////////////////////////////////////////////////////////////////////////

bool Namespace__HasMethod(const clang::NamespaceDecl *cl, const char *name,
                          const cling::Interpreter &interp)
{
   return ROOT::TMetaUtils::ClassInfo__HasMethod(cl, name, interp);
}

////////////////////////////////////////////////////////////////////////////////

void AnnotateFieldDecl(clang::FieldDecl &decl,
                       const std::list<VariableSelectionRule> &fieldSelRules,
                       bool isGenreflex)
{
   using namespace ROOT::TMetaUtils;
   // See if in the VariableSelectionRules there are attributes and names with
   // which we can annotate.
   // We may look for a smarter algorithm.

   // Nothing to do then ...
   if (fieldSelRules.size() == 0) return;

   clang::ASTContext &C = decl.getASTContext();
   clang::SourceRange commentRange; // Empty: this is a fake comment

   const std::string declName(decl.getNameAsString());
   std::string varName;
   for (std::list<VariableSelectionRule>::const_iterator it = fieldSelRules.begin();
         it != fieldSelRules.end(); ++it) {
      if (! it->GetAttributeValue(propNames::name, varName)) continue;
      if (declName == varName) { // we have the rule!
         // Let's extract the attributes
         BaseSelectionRule::AttributesMap_t attrMap(it->GetAttributes());
         BaseSelectionRule::AttributesMap_t::iterator iter;
         std::string userDefinedProperty;
         for (iter = attrMap.begin(); iter != attrMap.end(); iter++) {
            const std::string &name = iter->first;
            const std::string &value = iter->second;

            if (name == propNames::name) continue;

            /* This test is here since in ROOT5, when using genreflex,
             * for pods, iotype is ignored */

            if (name == propNames::iotype &&
                  (decl.getType()->isArrayType() ||  decl.getType()->isPointerType())) {
               const char *msg = "Data member \"%s\" is an array or a pointer. "
                                 "It is not possible to assign to it the iotype \"%s\". "
                                 "This transformation is possible only with data members "
                                 "which are not pointers or arrays.\n";
               ROOT::TMetaUtils::Error("AnnotateFieldDecl",
                                       msg, varName.c_str(), value.c_str());
               continue;
            }


            // These lines are here to use the root pcms. Indeed we need to annotate the AST
            // before persisting the ProtoClasses in the root pcms.
            // BEGIN ROOT PCMS
            if (name == propNames::comment) {
               decl.addAttr(new(C) clang::AnnotateAttr(commentRange, C, value, 0));
            }
            // END ROOT PCMS

            if ((name == propNames::transient && value == "true") ||
                  (name == propNames::persistent && value == "false")) { // special case
               userDefinedProperty = propNames::comment + propNames::separator + "!";
               // This next line is here to use the root pcms. Indeed we need to annotate the AST
               // before persisting the ProtoClasses in the root pcms.
               // BEGIN ROOT PCMS
               decl.addAttr(new(C) clang::AnnotateAttr(commentRange, C, "!", 0));
               // END ROOT PCMS
               // The rest of the lines are not changed to leave in place the system which
               // works with bulk header parsing on library load.
            } else {
               userDefinedProperty = name + propNames::separator + value;
            }
            ROOT::TMetaUtils::Info(0, "%s %s\n", varName.c_str(), userDefinedProperty.c_str());
            decl.addAttr(new(C) clang::AnnotateAttr(commentRange, C, userDefinedProperty, 0));

         }
      }
   }
}

////////////////////////////////////////////////////////////////////////////////

void AnnotateDecl(clang::CXXRecordDecl &CXXRD,
                  const RScanner::DeclsSelRulesMap_t &declSelRulesMap,
                  cling::Interpreter &interpreter,
                  bool isGenreflex)
{
   // In order to store the meaningful for the IO comments we have to transform
   // the comment into annotation of the given decl.
   // This works only with comments in the headers, so no selection rules in an
   // xml file.

   using namespace clang;
   SourceLocation commentSLoc;
   llvm::StringRef comment;

   ASTContext &C = CXXRD.getASTContext();
   Sema &S = interpreter.getCI()->getSema();

   SourceRange commentRange;

   // Fetch the selection rule associated to this class
   clang::Decl *declBaseClassPtr = static_cast<clang::Decl *>(&CXXRD);
   auto declSelRulePair = declSelRulesMap.find(declBaseClassPtr->getCanonicalDecl());
   if (declSelRulePair == declSelRulesMap.end()){
      const std::string thisClassName(CXXRD.getName());
      ROOT::TMetaUtils::Error("AnnotateDecl","Cannot find class %s in the list of selected classes.\n",thisClassName.c_str());
      return;
   }
   const BaseSelectionRule *thisClassBaseSelectionRule = declSelRulePair->second;
   // If the rule is there
   if (thisClassBaseSelectionRule) {
      // Fetch and loop over Class attributes
      // if the name of the attribute is not "name", add attr to the ast.
      BaseSelectionRule::AttributesMap_t::iterator iter;
      std::string userDefinedProperty;
      for (auto const & attr : thisClassBaseSelectionRule->GetAttributes()) {
         const std::string &name = attr.first;
         if (name == ROOT::TMetaUtils::propNames::name) continue;
         const std::string &value = attr.second;
         userDefinedProperty = name + ROOT::TMetaUtils::propNames::separator + value;
         if (genreflex::verbose) std::cout << " * " << userDefinedProperty << std::endl;
         CXXRD.addAttr(new(C) AnnotateAttr(commentRange, C, userDefinedProperty, 0));
      }
   }

   // See if the rule is a class selection rule (FIX dynamic_cast)
   const ClassSelectionRule *thisClassSelectionRule = reinterpret_cast<const ClassSelectionRule *>(thisClassBaseSelectionRule);

   for (CXXRecordDecl::decl_iterator I = CXXRD.decls_begin(),
         E = CXXRD.decls_end(); I != E; ++I) {

      // CXXMethodDecl,FieldDecl and VarDecl inherit from NamedDecl
      // See: http://clang.llvm.org/doxygen/classclang_1_1DeclaratorDecl.html
      if (!(*I)->isImplicit()
            && (isa<CXXMethodDecl>(*I) || isa<FieldDecl>(*I) || isa<VarDecl>(*I))) {


         // For now we allow only a special macro (ClassDef) to have meaningful comments
         SourceLocation maybeMacroLoc = (*I)->getLocation();
         bool isClassDefMacro = maybeMacroLoc.isMacroID() && S.findMacroSpelling(maybeMacroLoc, "ClassDef");
         if (isClassDefMacro) {
            while (isa<NamedDecl>(*I) && cast<NamedDecl>(*I)->getName() != "DeclFileLine") {
               ++I;
            }
         }

         comment = ROOT::TMetaUtils::GetComment(**I, &commentSLoc);
         if (comment.size()) {
            // Keep info for the source range of the comment in case we want to issue
            // nice warnings, eg. empty comment and so on.
            commentRange = SourceRange(commentSLoc, commentSLoc.getLocWithOffset(comment.size()));
            // The ClassDef annotation is for the class itself
            if (isClassDefMacro) {
               CXXRD.addAttr(new(C) AnnotateAttr(commentRange, C, comment.str(), 0));
            } else if (!isGenreflex) {
               // Here we check if we are in presence of a selction file so that
               // the comment does not ends up as a decoration in the AST,
               // Nevertheless, w/o PCMS this has no effect, since the headers
               // are parsed at runtime and the information in the AST dumped by
               // rootcling is not relevant.
               (*I)->addAttr(new(C) AnnotateAttr(commentRange, C, comment.str(), 0));
            }
         }
         // Match decls with sel rules if we are in presence of a selection file
         // and the cast was successful
         if (isGenreflex && thisClassSelectionRule != 0) {
            const std::list<VariableSelectionRule> &fieldSelRules = thisClassSelectionRule->GetFieldSelectionRules();

            // This check is here to avoid asserts in debug mode (LLVMDEV env variable set)
            if (FieldDecl *fieldDecl  = dyn_cast<FieldDecl>(*I)) {
               AnnotateFieldDecl(*fieldDecl, fieldSelRules, isGenreflex);
            }
         } // End presence of XML selection file
      }
   }
}

////////////////////////////////////////////////////////////////////////////////

size_t GetFullArrayLength(const clang::ConstantArrayType *arrayType)
{
   llvm::APInt len = arrayType->getSize();
   while (const clang::ConstantArrayType *subArrayType = llvm::dyn_cast<clang::ConstantArrayType>(arrayType->getArrayElementTypeNoTypeQual())) {
      len *= subArrayType->getSize();
      arrayType = subArrayType;
   }
   return len.getLimitedValue();
}

////////////////////////////////////////////////////////////////////////////////

bool InheritsFromTObject(const clang::RecordDecl *cl,
                         const cling::Interpreter &interp)
{
   static const clang::CXXRecordDecl *TObject_decl
      = ROOT::TMetaUtils::ScopeSearch("TObject", interp, true /*diag*/, 0);

   const clang::CXXRecordDecl *clxx = llvm::dyn_cast<clang::CXXRecordDecl>(cl);
   return ROOT::TMetaUtils::IsBase(clxx, TObject_decl, nullptr, interp);
}

////////////////////////////////////////////////////////////////////////////////

bool InheritsFromTSelector(const clang::RecordDecl *cl,
                           const cling::Interpreter &interp)
{
   static const clang::CXXRecordDecl *TObject_decl
      = ROOT::TMetaUtils::ScopeSearch("TSelector", interp, false /*diag*/, 0);

   return ROOT::TMetaUtils::IsBase(llvm::dyn_cast<clang::CXXRecordDecl>(cl), TObject_decl, nullptr, interp);
}

////////////////////////////////////////////////////////////////////////////////

bool IsSelectionXml(const char *filename)
{
   size_t len = strlen(filename);
   size_t xmllen = 4; /* strlen(".xml"); */
   if (strlen(filename) >= xmllen) {
      return (0 == strcasecmp(filename + (len - xmllen), ".xml"));
   } else {
      return false;
   }
}

////////////////////////////////////////////////////////////////////////////////

bool IsLinkdefFile(const clang::PresumedLoc& PLoc)
{
   return ROOT::TMetaUtils::IsLinkdefFile(PLoc.getFilename());
}

////////////////////////////////////////////////////////////////////////////////

bool IsSelectionFile(const char *filename)
{
   return ROOT::TMetaUtils::IsLinkdefFile(filename) || IsSelectionXml(filename);
}

////////////////////////////////////////////////////////////////////////////////
/// Set the ROOTSYS env var based on the executable location.

void SetRootSys()
{
   const char *exepath = GetExePath();
   if (exepath && *exepath) {
#if !defined(_WIN32)
      char *ep = new char[PATH_MAX];
      if (!realpath(exepath, ep)) {
         fprintf(stderr, "rootcling: error getting realpath of rootcling!");
         strlcpy(ep, exepath, PATH_MAX);
      }
#else
      int nche = strlen(exepath) + 1;
      char *ep = new char[nche];
      strlcpy(ep, exepath, nche);
#endif
      char *s;

      if ((s = strrchr(ep, '/'))) {
         // $ROOTSYS/bin/rootcling
         int removesubdirs = 2;
         if (!strncmp(s + 1, "rootcling_stage1", 16)) {
            // $ROOTSYS/core/rootcling_stage1/src/rootcling_stage1
            removesubdirs = 4;
            gBuildingROOT = true;
         }
         for (int i = 1; s && i < removesubdirs; ++i) {
            *s = 0;
            s = strrchr(ep, '/');
         }
         if (s) *s = 0;
      } else {
         // There was no slashes at all let now change ROOTSYS
         return;
      }

      if (!gBuildingROOT)
         return; // don't mess with user's ROOTSYS.

      int ncha = strlen(ep) + 10;
      char *env = new char[ncha];
      snprintf(env, ncha, "ROOTSYS=%s", ep);

      if (gDriverConfig) {
         // After the putenv below, gRootDir might point to the old ROOTSYS
         // entry, i.e. to deleted memory. Update it.
         const char** pRootDir = gDriverConfig->fPRootDir;
         if (pRootDir) {
            *pRootDir = env + 8;
         }
      }

      putenv(env);
      delete [] ep;
   }
}

////////////////////////////////////////////////////////////////////////////////
/// Check whether the #pragma line contains expectedTokens (0-terminated array).

bool ParsePragmaLine(const std::string &line,
                     const char *expectedTokens[],
                     size_t *end = 0)
{
   if (end) *end = 0;
   if (line[0] != '#') return false;
   size_t pos = 1;
   for (const char **iToken = expectedTokens; *iToken; ++iToken) {
      while (isspace(line[pos])) ++pos;
      size_t lenToken = strlen(*iToken);
      if (line.compare(pos, lenToken, *iToken)) {
         if (end) *end = pos;
         return false;
      }
      pos += lenToken;
   }
   if (end) *end = pos;
   return true;
}


map<string, string> gAutoloads;
string gLibsNeeded;

////////////////////////////////////////////////////////////////////////////////

void RecordDeclCallback(const char *c)
{
   string need(gAutoloads[c]);
   if (need.length() && gLibsNeeded.find(need) == string::npos) {
      gLibsNeeded += " " + need;
   }
}

////////////////////////////////////////////////////////////////////////////////

void CheckClassNameForRootMap(const std::string &classname, map<string, string> &autoloads)
{
   if (classname.find(':') == std::string::npos) return;

   // We have a namespace and we have to check it first
   int slen = classname.size();
   for (int k = 0; k < slen; ++k) {
      if (classname[k] == ':') {
         if (k + 1 >= slen || classname[k + 1] != ':') {
            // we expected another ':'
            break;
         }
         if (k) {
            string base = classname.substr(0, k);
            if (base == "std") {
               // std is not declared but is also ignored by CINT!
               break;
            } else {
               autoloads[base] = ""; // We never load namespaces on their own.
            }
            ++k;
         }
      } else if (classname[k] == '<') {
         // We do not want to look at the namespace inside the template parameters!
         break;
      }
   }
}

////////////////////////////////////////////////////////////////////////////////
/// Parse the rootmap and add entries to the autoload map

void ParseRootMapFile(ifstream &file, map<string, string> &autoloads)
{
   std::string classname;
   std::string line;
   while (file >> line) {

      if (line.find("Library.") != 0) continue;

      int pos = line.find(":", 8);
      classname = line.substr(8, pos - 8);

      ROOT::TMetaUtils::ReplaceAll(classname, "@@", "::");
      ROOT::TMetaUtils::ReplaceAll(classname, "-", " ");

      getline(file, line, '\n');
      while (line[0] == ' ') line.replace(0, 1, "");

      CheckClassNameForRootMap(classname, autoloads);

      if (classname == "ROOT::TImpProxy") {
         // Do not register the ROOT::TImpProxy so that they can be instantiated.
         continue;
      }
      autoloads[classname] = line;
   }

}

////////////////////////////////////////////////////////////////////////////////
/// Parse the rootmap and add entries to the autoload map, using the new format

void ParseRootMapFileNewFormat(ifstream &file, map<string, string> &autoloads)
{
   std::string keyname;
   std::string libs;
   std::string line;

   // For "class ", "namespace " and "typedef " respectively
   const std::unordered_map<char, unsigned int> keyLenMap = {{'c', 6}, {'n', 10}, {'t', 8}};

   while (getline(file, line, '\n')) {
      if (line == "{ decls }") {
         while (getline(file, line, '\n')) {
            if (line[0] == '[') break;
         }
      }
      const char firstChar = line[0];
      if (firstChar == '[') {
         // new section
         libs = line.substr(1, line.find(']') - 1);
         while (libs[0] == ' ') libs.replace(0, 1, "");
      } else if (0 != keyLenMap.count(firstChar)) {
         unsigned int keyLen = keyLenMap.at(firstChar);
         keyname = line.substr(keyLen, line.length() - keyLen);
         CheckClassNameForRootMap(keyname, autoloads);
         autoloads[keyname] = libs;
      }
   }

}

////////////////////////////////////////////////////////////////////////////////
/// Fill the map of libraries to be loaded in presence of a class
/// Transparently support the old and new rootmap file format

void LoadLibraryMap(const std::string &fileListName, map<string, string> &autoloads)
{
   std::ifstream filelist(fileListName.c_str());

   std::string filename;
   std::string line;

   while (filelist >> filename) {

      if (llvm::sys::fs::is_directory(filename)) continue;

      ifstream file(filename.c_str());

      // Check which format is this
      file >> line;
      bool new_format = (line[0] == '[' || line[0] == '{') ;
      file.clear();
      file.seekg(0, std::ios::beg);

      // Now act
      if (new_format) {
         ParseRootMapFileNewFormat(file, autoloads);
      } else {
         ParseRootMapFile(file, autoloads);
      }

      file.close();

   } // end loop on files
   filelist.close();
}

////////////////////////////////////////////////////////////////////////////////
/// Check if the specificed operator (what) has been properly declared if the user has
/// resquested a custom version.

bool CheckInputOperator(const char *what,
                        const char *proto,
                        const string &fullname,
                        const clang::RecordDecl *cl,
                        cling::Interpreter &interp)
{

   const clang::FunctionDecl *method
      = ROOT::TMetaUtils::GetFuncWithProto(llvm::dyn_cast<clang::Decl>(cl->getDeclContext()), what, proto, interp,
                                           false /*diags*/);
   if (!method) {
      // This intended to find the global scope.
      clang::TranslationUnitDecl *TU =
         cl->getASTContext().getTranslationUnitDecl();
      method = ROOT::TMetaUtils::GetFuncWithProto(TU, what, proto, interp,
               false /*diags*/);
   }
   bool has_input_error = false;
   if (method != 0 && (method->getAccess() == clang::AS_public || method->getAccess() == clang::AS_none)) {
      std::string filename = ROOT::TMetaUtils::GetFileName(*method, interp);
      if (strstr(filename.c_str(), "TBuffer.h") != 0 ||
            strstr(filename.c_str(), "Rtypes.h") != 0) {

         has_input_error = true;
      }
   } else {
      has_input_error = true;
   }
   if (has_input_error) {
      // We don't want to generate duplicated error messages in several dictionaries (when generating temporaries)
      const char *maybeconst = "";
      const char *mayberef = "&";
      if (what[strlen(what) - 1] == '<') {
         maybeconst = "const ";
         mayberef = "";
      }
      ROOT::TMetaUtils::Error(0,
                              "in this version of ROOT, the option '!' used in a linkdef file\n"
                              "       implies the actual existence of customized operators.\n"
                              "       The following declaration is now required:\n"
                              "   TBuffer &%s(TBuffer &,%s%s *%s);\n", what, maybeconst, fullname.c_str(), mayberef);
   }
   return has_input_error;

}

////////////////////////////////////////////////////////////////////////////////
/// Check if the operator>> has been properly declared if the user has
/// resquested a custom version.

bool CheckInputOperator(const clang::RecordDecl *cl, cling::Interpreter &interp)
{
   string fullname;
   ROOT::TMetaUtils::GetQualifiedName(fullname, *cl);
   int ncha = fullname.length() + 13;
   char *proto = new char[ncha];
   snprintf(proto, ncha, "TBuffer&,%s*&", fullname.c_str());

   ROOT::TMetaUtils::Info(0, "Class %s: Do not generate operator>>()\n",
                          fullname.c_str());

   // We do want to call both CheckInputOperator all the times.
   bool has_input_error = CheckInputOperator("operator>>", proto, fullname, cl, interp);
   has_input_error = CheckInputOperator("operator<<", proto, fullname, cl, interp) || has_input_error;

   delete [] proto;

   return has_input_error;
}

////////////////////////////////////////////////////////////////////////////////
/// Return false if the class does not have ClassDef even-though it should.

bool CheckClassDef(const clang::RecordDecl &cl, const cling::Interpreter &interp)
{

   // Detect if the class has a ClassDef
   bool hasClassDef = ROOT::TMetaUtils::ClassInfo__HasMethod(&cl, "Class_Version", interp);

   const clang::CXXRecordDecl *clxx = llvm::dyn_cast<clang::CXXRecordDecl>(&cl);
   if (!clxx) {
      return false;
   }
   bool isAbstract = clxx->isAbstract();

   bool result = true;
   if (!isAbstract && InheritsFromTObject(clxx, interp) && !InheritsFromTSelector(clxx, interp) && !hasClassDef) {
      std::string qualName;
      ROOT::TMetaUtils::GetQualifiedName(qualName, cl);
      const char *qualName_c = qualName.c_str();
      ROOT::TMetaUtils::Error(qualName_c,
                              "%s inherits from TObject but does not have its own ClassDef\n",
                              qualName_c);
      // We do want to always output the message (hence the Error level)
      // but still want rootcling to succeed.
      result = true;
   }

   return result;
}

////////////////////////////////////////////////////////////////////////////////
/// Return the name of the data member so that it can be used
/// by non-const operation (so it includes a const_cast if necessary).

string GetNonConstMemberName(const clang::FieldDecl &m, const string &prefix = "")
{
   if (m.getType().isConstQualified()) {
      string ret = "const_cast< ";
      string type_name;
      ROOT::TMetaUtils::GetQualifiedName(type_name, m.getType(), m);
      if (type_name.substr(0,6)=="const ") {
         ret += type_name.c_str()+6;
      } else {
         ret += type_name;
      }
      ret += " &>( ";
      ret += prefix;
      ret += m.getName().str();
      ret += " )";
      return ret;
   } else {
      return prefix + m.getName().str();
   }
}

////////////////////////////////////////////////////////////////////////////////
/// Create Streamer code for an STL container. Returns 1 if data member
/// was an STL container and if Streamer code has been created, 0 otherwise.

int STLContainerStreamer(const clang::FieldDecl &m,
                         int rwmode,
                         const cling::Interpreter &interp,
                         const ROOT::TMetaUtils::TNormalizedCtxt &normCtxt,
                         std::ostream &dictStream)
{
   ROOT::ESTLType stltype = ROOT::TMetaUtils::IsSTLContainer(m);
   std::string mTypename;
   ROOT::TMetaUtils::GetQualifiedName(mTypename, m.getType(), m);

   const clang::CXXRecordDecl *clxx = llvm::dyn_cast_or_null<clang::CXXRecordDecl>(ROOT::TMetaUtils::GetUnderlyingRecordDecl(m.getType()));

   if (stltype == ROOT::kNotSTL) {
      return 0;
   }
   //        fprintf(stderr,"Add %s (%d) which is also %s\n",
   //                m.Type()->Name(), stltype, m.Type()->TrueName() );
   clang::QualType utype(ROOT::TMetaUtils::GetUnderlyingType(m.getType()), 0);
   Internal::RStl::Instance().GenerateTClassFor(utype, interp, normCtxt);

   if (clxx->getTemplateSpecializationKind() == clang::TSK_Undeclared) return 0;

   const clang::ClassTemplateSpecializationDecl *tmplt_specialization = llvm::dyn_cast<clang::ClassTemplateSpecializationDecl> (clxx);
   if (!tmplt_specialization) return 0;


   string stlType(ROOT::TMetaUtils::ShortTypeName(mTypename.c_str()));
   string stlName;
   stlName = ROOT::TMetaUtils::ShortTypeName(m.getName().str().c_str());

   string fulName1, fulName2;
   const char *tcl1 = 0, *tcl2 = 0;
   const clang::TemplateArgument &arg0(tmplt_specialization->getTemplateArgs().get(0));
   clang::QualType ti = arg0.getAsType();

   if (ROOT::TMetaUtils::ElementStreamer(dictStream, m, ti, 0, rwmode, interp)) {
      tcl1 = "R__tcl1";
      fulName1 = ti.getAsString(); // Should we be passing a context?
   }
   if (stltype == kSTLmap || stltype == kSTLmultimap) {
      const clang::TemplateArgument &arg1(tmplt_specialization->getTemplateArgs().get(1));
      clang::QualType tmplti = arg1.getAsType();
      if (ROOT::TMetaUtils::ElementStreamer(dictStream, m, tmplti, 0, rwmode, interp)) {
         tcl2 = "R__tcl2";
         fulName2 = tmplti.getAsString(); // Should we be passing a context?
      }
   }

   int isArr = 0;
   int len = 1;
   int pa = 0;
   const clang::ConstantArrayType *arrayType = llvm::dyn_cast<clang::ConstantArrayType>(m.getType().getTypePtr());
   if (arrayType) {
      isArr = 1;
      len =  GetFullArrayLength(arrayType);
      pa = 1;
      while (arrayType) {
         if (arrayType->getArrayElementTypeNoTypeQual()->isPointerType()) {
            pa = 3;
            break;
         }
         arrayType = llvm::dyn_cast<clang::ConstantArrayType>(arrayType->getArrayElementTypeNoTypeQual());
      }
   } else if (m.getType()->isPointerType()) {
      pa = 2;
   }
   if (rwmode == 0) {
      // create read code
      dictStream << "      {" << std::endl;
      if (isArr) {
         dictStream << "         for (Int_t R__l = 0; R__l < " << len << "; R__l++) {" << std::endl;
      }

      switch (pa) {
         case 0:         //No pointer && No array
            dictStream << "         " << stlType.c_str() << " &R__stl =  " << stlName.c_str() << ";" << std::endl;
            break;
         case 1:         //No pointer && array
            dictStream << "         " << stlType.c_str() << " &R__stl =  " << stlName.c_str() << "[R__l];" << std::endl;
            break;
         case 2:         //pointer && No array
            dictStream << "         delete *" << stlName.c_str() << ";" << std::endl
                       << "         *" << stlName.c_str() << " = new " << stlType.c_str() << ";" << std::endl
                       << "         " << stlType.c_str() << " &R__stl = **" << stlName.c_str() << ";" << std::endl;
            break;
         case 3:         //pointer && array
            dictStream << "         delete " << stlName.c_str() << "[R__l];" << std::endl
                       << "         " << stlName.c_str() << "[R__l] = new " << stlType.c_str() << ";" << std::endl
                       << "         " << stlType.c_str() << " &R__stl = *" << stlName.c_str() << "[R__l];" << std::endl;
            break;
      }

      dictStream << "         R__stl.clear();" << std::endl;

      if (tcl1) {
         dictStream << "         TClass *R__tcl1 = TBuffer::GetClass(typeid(" << fulName1.c_str() << "));" << std::endl
                    << "         if (R__tcl1==0) {" << std::endl
                    << "            Error(\"" << stlName.c_str() << " streamer\",\"Missing the TClass object for "
                    << fulName1.c_str() << "!\");"  << std::endl
                    << "            return;" << std::endl
                    << "         }" << std::endl;
      }
      if (tcl2) {
         dictStream << "         TClass *R__tcl2 = TBuffer::GetClass(typeid(" << fulName2.c_str() << "));" << std::endl
                    << "         if (R__tcl2==0) {" << std::endl
                    << "            Error(\"" << stlName.c_str() << " streamer\",\"Missing the TClass object for "
                    << fulName2.c_str() << "!\");" << std::endl
                    << "            return;" << std::endl
                    << "         }" << std::endl;
      }

      dictStream << "         int R__i, R__n;" << std::endl
                 << "         R__b >> R__n;" << std::endl;

      if (stltype == kSTLvector) {
         dictStream << "         R__stl.reserve(R__n);" << std::endl;
      }
      dictStream << "         for (R__i = 0; R__i < R__n; R__i++) {" << std::endl;

      ROOT::TMetaUtils::ElementStreamer(dictStream, m, arg0.getAsType(), "R__t", rwmode, interp, tcl1);
      if (stltype == kSTLmap || stltype == kSTLmultimap) {     //Second Arg
         const clang::TemplateArgument &arg1(tmplt_specialization->getTemplateArgs().get(1));
         ROOT::TMetaUtils::ElementStreamer(dictStream, m, arg1.getAsType(), "R__t2", rwmode, interp, tcl2);
      }

      /* Need to go from
         type R__t;
         R__t.Stream;
         vec.push_back(R__t);
         to
         vec.push_back(type());
         R__t_p = &(vec.last());
         *R__t_p->Stream;

      */
      switch (stltype) {

         case kSTLmap:
         case kSTLmultimap:
         case kSTLunorderedmap:
         case kSTLunorderedmultimap:{
               std::string keyName(ti.getAsString());
               dictStream << "            typedef " << keyName << " Value_t;" << std::endl
                          << "            std::pair<Value_t const, " << tmplt_specialization->getTemplateArgs().get(1).getAsType().getAsString() << " > R__t3(R__t,R__t2);" << std::endl
                          << "            R__stl.insert(R__t3);" << std::endl;
               //fprintf(fp, "            R__stl.insert(%s::value_type(R__t,R__t2));\n",stlType.c_str());
               break;
            }
         case kSTLset:
         case kSTLunorderedset:
         case kSTLunorderedmultiset:
         case kSTLmultiset:
            dictStream << "            R__stl.insert(R__t);" << std::endl;
            break;
         case kSTLvector:
         case kSTLlist:
         case kSTLdeque:
            dictStream << "            R__stl.push_back(R__t);" << std::endl;
            break;
         case kSTLforwardlist:
            dictStream << "            R__stl.push_front(R__t);" << std::endl;
            break;
         default:
            assert(0);
      }
      dictStream << "         }" << std::endl
                 << "      }" << std::endl;
      if (isArr) dictStream << "    }" << std::endl;

   } else {

      // create write code
      if (isArr) {
         dictStream << "         for (Int_t R__l = 0; R__l < " << len << "; R__l++) {" << std::endl;
      }
      dictStream << "      {" << std::endl;
      switch (pa) {
         case 0:         //No pointer && No array
            dictStream << "         " << stlType.c_str() << " &R__stl =  " << stlName.c_str() << ";" << std::endl;
            break;
         case 1:         //No pointer && array
            dictStream << "         " << stlType.c_str() << " &R__stl =  " << stlName.c_str() << "[R__l];" << std::endl;
            break;
         case 2:         //pointer && No array
            dictStream << "         " << stlType.c_str() << " &R__stl = **" << stlName.c_str() << ";" << std::endl;
            break;
         case 3:         //pointer && array
            dictStream << "         " << stlType.c_str() << " &R__stl = *" << stlName.c_str() << "[R__l];" << std::endl;
            break;
      }

      dictStream << "         int R__n=int(R__stl.size());" << std::endl
                 << "         R__b << R__n;" << std::endl
                 << "         if(R__n) {" << std::endl;

      if (tcl1) {
         dictStream << "         TClass *R__tcl1 = TBuffer::GetClass(typeid(" << fulName1.c_str() << "));" << std::endl
                    << "         if (R__tcl1==0) {" << std::endl
                    << "            Error(\"" << stlName.c_str() << " streamer\",\"Missing the TClass object for "
                    << fulName1.c_str() << "!\");" << std::endl
                    << "            return;" << std::endl
                    << "         }" << std::endl;
      }
      if (tcl2) {
         dictStream << "         TClass *R__tcl2 = TBuffer::GetClass(typeid(" << fulName2.c_str() << "));" << std::endl
                    << "         if (R__tcl2==0) {" << std::endl
                    << "            Error(\"" << stlName.c_str() << "streamer\",\"Missing the TClass object for " << fulName2.c_str() << "!\");" << std::endl
                    << "            return;" << std::endl
                    << "         }" << std::endl;
      }

      dictStream << "            " << stlType.c_str() << "::iterator R__k;" << std::endl
                 << "            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {" << std::endl;
      if (stltype == kSTLmap || stltype == kSTLmultimap) {
         const clang::TemplateArgument &arg1(tmplt_specialization->getTemplateArgs().get(1));
         clang::QualType tmplti = arg1.getAsType();
         ROOT::TMetaUtils::ElementStreamer(dictStream, m, ti, "((*R__k).first )", rwmode, interp, tcl1);
         ROOT::TMetaUtils::ElementStreamer(dictStream, m, tmplti, "((*R__k).second)", rwmode, interp, tcl2);
      } else {
         ROOT::TMetaUtils::ElementStreamer(dictStream, m, ti, "(*R__k)"         , rwmode, interp, tcl1);
      }

      dictStream << "            }" << std::endl
                 << "         }" << std::endl
                 << "      }" << std::endl;
      if (isArr) dictStream << "    }" << std::endl;
   }
   return 1;
}

////////////////////////////////////////////////////////////////////////////////
/// Create Streamer code for a standard string object. Returns 1 if data
/// member was a standard string and if Streamer code has been created,
/// 0 otherwise.

int STLStringStreamer(const clang::FieldDecl &m, int rwmode, std::ostream &dictStream)
{
   std::string mTypenameStr;
   ROOT::TMetaUtils::GetQualifiedName(mTypenameStr, m.getType(), m);
   // Note: here we could to a direct type comparison!
   const char *mTypeName = ROOT::TMetaUtils::ShortTypeName(mTypenameStr.c_str());
   if (!strcmp(mTypeName, "string")) {

      std::string fieldname =  m.getName().str();
      if (rwmode == 0) {
         // create read mode
         if (m.getType()->isConstantArrayType()) {
            if (m.getType().getTypePtr()->getArrayElementTypeNoTypeQual()->isPointerType()) {
               dictStream << "// Array of pointer to std::string are not supported (" << fieldname << "\n";
            } else {
               std::stringstream fullIdx;
               const clang::ConstantArrayType *arrayType = llvm::dyn_cast<clang::ConstantArrayType>(m.getType().getTypePtr());
               int dim = 0;
               while (arrayType) {
                  dictStream << "      for (int R__i" << dim << "=0; R__i" << dim << "<"
                             << arrayType->getSize().getLimitedValue() << "; ++R__i" << dim << " )" << std::endl;
                  fullIdx << "[R__i" << dim << "]";
                  arrayType = llvm::dyn_cast<clang::ConstantArrayType>(arrayType->getArrayElementTypeNoTypeQual());
                  ++dim;
               }
               dictStream << "         { TString R__str; R__str.Streamer(R__b); "
                          << fieldname << fullIdx.str() << " = R__str.Data();}" << std::endl;
            }
         } else {
            dictStream << "      { TString R__str; R__str.Streamer(R__b); ";
            if (m.getType()->isPointerType())
               dictStream << "if (*" << fieldname << ") delete *" << fieldname << "; (*"
                          << fieldname << " = new string(R__str.Data())); }" << std::endl;
            else
               dictStream << fieldname << " = R__str.Data(); }" << std::endl;
         }
      } else {
         // create write mode
         if (m.getType()->isPointerType())
            dictStream << "      { TString R__str; if (*" << fieldname << ") R__str = (*"
                       << fieldname << ")->c_str(); R__str.Streamer(R__b);}" << std::endl;
         else if (m.getType()->isConstantArrayType()) {
            std::stringstream fullIdx;
            const clang::ConstantArrayType *arrayType = llvm::dyn_cast<clang::ConstantArrayType>(m.getType().getTypePtr());
            int dim = 0;
            while (arrayType) {
               dictStream << "      for (int R__i" << dim << "=0; R__i" << dim << "<"
                          << arrayType->getSize().getLimitedValue() << "; ++R__i" << dim << " )" << std::endl;
               fullIdx << "[R__i" << dim << "]";
               arrayType = llvm::dyn_cast<clang::ConstantArrayType>(arrayType->getArrayElementTypeNoTypeQual());
               ++dim;
            }
            dictStream << "         { TString R__str(" << fieldname << fullIdx.str() << ".c_str()); R__str.Streamer(R__b);}" << std::endl;
         } else
            dictStream << "      { TString R__str = " << fieldname << ".c_str(); R__str.Streamer(R__b);}" << std::endl;
      }
      return 1;
   }
   return 0;
}

////////////////////////////////////////////////////////////////////////////////

bool isPointerToPointer(const clang::FieldDecl &m)
{
   if (m.getType()->isPointerType()) {
      if (m.getType()->getPointeeType()->isPointerType()) {
         return true;
      }
   }
   return false;
}

////////////////////////////////////////////////////////////////////////////////
/// Write "[0]" for all but the 1st dimension.

void WriteArrayDimensions(const clang::QualType &type, std::ostream &dictStream)
{
   const clang::ConstantArrayType *arrayType = llvm::dyn_cast<clang::ConstantArrayType>(type.getTypePtr());
   if (arrayType) {
      arrayType = llvm::dyn_cast<clang::ConstantArrayType>(arrayType->getArrayElementTypeNoTypeQual());
      while (arrayType) {
         dictStream << "[0]";
         arrayType = llvm::dyn_cast<clang::ConstantArrayType>(arrayType->getArrayElementTypeNoTypeQual());
      }
   }
}

////////////////////////////////////////////////////////////////////////////////
/// Write the code to set the class name and the initialization object.

void WriteClassFunctions(const clang::CXXRecordDecl *cl, std::ostream &dictStream, bool autoLoad = false)
{
   bool add_template_keyword = ROOT::TMetaUtils::NeedTemplateKeyword(cl);

   string fullname;
   string clsname;
   string nsname;
   int enclSpaceNesting = 0;

   if (ROOT::TMetaUtils::GetNameWithinNamespace(fullname, clsname, nsname, cl)) {
      enclSpaceNesting = ROOT::TMetaUtils::WriteNamespaceHeader(dictStream, cl);
   }

   if (autoLoad)
      dictStream << "#include \"TInterpreter.h\"\n";

   dictStream << "//_______________________________________"
              << "_______________________________________" << std::endl;
   if (add_template_keyword) dictStream << "template <> ";
   dictStream << "atomic_TClass_ptr " << clsname << "::fgIsA(0);  // static to hold class pointer" << std::endl
              << std::endl

              << "//_______________________________________"
              << "_______________________________________" << std::endl;
   if (add_template_keyword) dictStream << "template <> ";
   dictStream << "const char *" << clsname << "::Class_Name()" << std::endl << "{" << std::endl
              << "   return \"" << fullname << "\";"  << std::endl << "}" << std::endl << std::endl;

   dictStream << "//_______________________________________"
              << "_______________________________________" << std::endl;
   if (add_template_keyword) dictStream << "template <> ";
   dictStream << "const char *" << clsname << "::ImplFileName()"  << std::endl << "{" << std::endl
              << "   return ::ROOT::GenerateInitInstanceLocal((const ::" << fullname
              << "*)0x0)->GetImplFileName();" << std::endl << "}" << std::endl << std::endl

              << "//_______________________________________"
              << "_______________________________________" << std::endl;
   if (add_template_keyword) dictStream << "template <> ";
   dictStream << "int " << clsname << "::ImplFileLine()" << std::endl << "{" << std::endl
              << "   return ::ROOT::GenerateInitInstanceLocal((const ::" << fullname
              << "*)0x0)->GetImplFileLine();" << std::endl << "}" << std::endl << std::endl

              << "//_______________________________________"
              << "_______________________________________" << std::endl;
   if (add_template_keyword) dictStream << "template <> ";
   dictStream << "TClass *" << clsname << "::Dictionary()" << std::endl << "{" << std::endl;

   // Trigger autoloading if dictionary is split
   if (autoLoad)
      dictStream << "   gInterpreter->EnableAutoLoading();\n"
                 << "   gInterpreter->AutoLoad(\"" << fullname << "\");\n";
   dictStream    << "   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::" << fullname
                 << "*)0x0)->GetClass();" << std::endl
                 << "   return fgIsA;\n"
                 << "}" << std::endl << std::endl

                 << "//_______________________________________"
                 << "_______________________________________" << std::endl;
   if (add_template_keyword) dictStream << "template <> ";
   dictStream << "TClass *" << clsname << "::Class()" << std::endl << "{" << std::endl;
   if (autoLoad) {
      dictStream << "   Dictionary();\n";
   } else {
      dictStream << "   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::";
      dictStream << fullname << "*)0x0)->GetClass(); }" << std::endl;
   }
   dictStream    << "   return fgIsA;" << std::endl
                 << "}" << std::endl << std::endl;

   while (enclSpaceNesting) {
      dictStream << "} // namespace " << nsname << std::endl;
      --enclSpaceNesting;
   }
}

////////////////////////////////////////////////////////////////////////////////
/// Write the code to initialize the namespace name and the initialization object.

void WriteNamespaceInit(const clang::NamespaceDecl *cl,
                        cling::Interpreter &interp,
                        std::ostream &dictStream)
{
   if (cl->isAnonymousNamespace()) {
      // Don't write a GenerateInitInstance for the anonymous namespaces.
      return;
   }

   // coverity[fun_call_w_exception] - that's just fine.
   string classname = ROOT::TMetaUtils::GetQualifiedName(*cl).c_str();
   string mappedname;
   TMetaUtils::GetCppName(mappedname, classname.c_str());

   int nesting = 0;
   // We should probably unwind the namespace to properly nest it.
   if (classname != "ROOT") {
      nesting = ROOT::TMetaUtils::WriteNamespaceHeader(dictStream,cl);
   }

   dictStream << "   namespace ROOT {" << std::endl;

#if !defined(R__AIX)
   dictStream << "      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();" << std::endl;
#endif

   if (!Namespace__HasMethod(cl, "Dictionary", interp))
      dictStream << "      static TClass *" << mappedname.c_str() << "_Dictionary();" << std::endl;
   dictStream << std::endl

              << "      // Function generating the singleton type initializer" << std::endl

#if !defined(R__AIX)
              << "      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()" << std::endl
              << "      {" << std::endl
#else
              << "      ::ROOT::TGenericClassInfo *GenerateInitInstance()" << std::endl
              << "      {" << std::endl
#endif

              << "         static ::ROOT::TGenericClassInfo " << std::endl

              << "            instance(\"" << classname.c_str() << "\", ";

   if (Namespace__HasMethod(cl, "Class_Version", interp)) {
      dictStream << "::" << classname.c_str() << "::Class_Version(), ";
   } else {
      dictStream << "0 /*version*/, ";
   }

   std::string filename = ROOT::TMetaUtils::GetFileName(*cl, interp);
   for (unsigned int i = 0; i < filename.length(); i++) {
      if (filename[i] == '\\') filename[i] = '/';
   }
   dictStream << "\"" << filename << "\", " << ROOT::TMetaUtils::GetLineNumber(cl) << "," << std::endl
              << "                     ::ROOT::Internal::DefineBehavior((void*)0,(void*)0)," << std::endl
              << "                     ";

   if (Namespace__HasMethod(cl, "Dictionary", interp)) {
      dictStream << "&::" << classname.c_str() << "::Dictionary, ";
   } else {
      dictStream << "&" << mappedname.c_str() << "_Dictionary, ";
   }

   dictStream << 0 << ");" << std::endl

              << "         return &instance;" << std::endl
              << "      }" << std::endl
              << "      // Insure that the inline function is _not_ optimized away by the compiler\n"
              << "      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_DICT_(InitFunctionKeeper))() = &GenerateInitInstance;  " << std::endl
              << "      // Static variable to force the class initialization" << std::endl
              // must be one long line otherwise R__UseDummy does not work
              << "      static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstance();"
              << " R__UseDummy(_R__UNIQUE_DICT_(Init));" << std::endl;

   if (!Namespace__HasMethod(cl, "Dictionary", interp)) {
      dictStream <<  std::endl << "      // Dictionary for non-ClassDef classes" << std::endl
                 << "      static TClass *" << mappedname.c_str() << "_Dictionary() {" << std::endl
                 << "         return GenerateInitInstance()->GetClass();" << std::endl
                 << "      }" << std::endl << std::endl;
   }

   dictStream << "   }" << std::endl;
   while (nesting--) {
      dictStream << "}" << std::endl;
   }
   dictStream <<  std::endl;
}

////////////////////////////////////////////////////////////////////////////////
/// GrabIndex returns a static string (so use it or copy it immediatly, do not
/// call GrabIndex twice in the same expression) containing the size of the
/// array data member.
/// In case of error, or if the size is not specified, GrabIndex returns 0.

llvm::StringRef GrabIndex(const clang::FieldDecl &member, int printError)
{
   int error;
   llvm::StringRef where;

   llvm::StringRef index = ROOT::TMetaUtils::DataMemberInfo__ValidArrayIndex(member, &error, &where);
   if (index.size() == 0 && printError) {
      const char *errorstring;
      switch (error) {
         case TMetaUtils::NOT_INT:
            errorstring = "is not an integer";
            break;
         case TMetaUtils::NOT_DEF:
            errorstring = "has not been defined before the array";
            break;
         case TMetaUtils::IS_PRIVATE:
            errorstring = "is a private member of a parent class";
            break;
         case TMetaUtils::UNKNOWN:
            errorstring = "is not known";
            break;
         default:
            errorstring = "UNKNOWN ERROR!!!!";
      }

      if (where.size() == 0) {
         ROOT::TMetaUtils::Error(0, "*** Datamember %s::%s: no size indication!\n",
                                 member.getParent()->getName().str().c_str(), member.getName().str().c_str());
      } else {
         ROOT::TMetaUtils::Error(0, "*** Datamember %s::%s: size of array (%s) %s!\n",
                                 member.getParent()->getName().str().c_str(), member.getName().str().c_str(), where.str().c_str(), errorstring);
      }
   }
   return index;
}

////////////////////////////////////////////////////////////////////////////////

void WriteStreamer(const ROOT::TMetaUtils::AnnotatedRecordDecl &cl,
                   const cling::Interpreter &interp,
                   const ROOT::TMetaUtils::TNormalizedCtxt &normCtxt,
                   std::ostream &dictStream)
{
   const clang::CXXRecordDecl *clxx = llvm::dyn_cast<clang::CXXRecordDecl>(cl.GetRecordDecl());
   if (clxx == 0) return;

   bool add_template_keyword = ROOT::TMetaUtils::NeedTemplateKeyword(clxx);

   string fullname;
   string clsname;
   string nsname;
   int enclSpaceNesting = 0;

   if (ROOT::TMetaUtils::GetNameWithinNamespace(fullname, clsname, nsname, clxx)) {
      enclSpaceNesting = ROOT::TMetaUtils::WriteNamespaceHeader(dictStream, cl);
   }

   dictStream << "//_______________________________________"
              << "_______________________________________" << std::endl;
   if (add_template_keyword) dictStream << "template <> ";
   dictStream << "void " << clsname << "::Streamer(TBuffer &R__b)"  << std::endl << "{" << std::endl
              << "   // Stream an object of class " << fullname << "." << std::endl << std::endl;

   // In case of VersionID<=0 write dummy streamer only calling
   // its base class Streamer(s). If no base class(es) let Streamer
   // print error message, i.e. this Streamer should never have been called.
   int version = ROOT::TMetaUtils::GetClassVersion(clxx, interp);
   if (version <= 0) {
      // We also need to look at the base classes.
      int basestreamer = 0;
      for (clang::CXXRecordDecl::base_class_const_iterator iter = clxx->bases_begin(), end = clxx->bases_end();
            iter != end;
            ++iter) {
         if (ROOT::TMetaUtils::ClassInfo__HasMethod(iter->getType()->getAsCXXRecordDecl(), "Streamer", interp)) {
            string base_fullname;
            ROOT::TMetaUtils::GetQualifiedName(base_fullname, * iter->getType()->getAsCXXRecordDecl());

            if (strstr(base_fullname.c_str(), "::")) {
               // there is a namespace involved, trigger MS VC bug workaround
               dictStream << "   //This works around a msvc bug and should be harmless on other platforms" << std::endl
                          << "   typedef " << base_fullname << " baseClass" << basestreamer << ";" << std::endl
                          << "   baseClass" << basestreamer << "::Streamer(R__b);" << std::endl;
            } else {
               dictStream << "   " << base_fullname << "::Streamer(R__b);" << std::endl;
            }
            basestreamer++;
         }
      }
      if (!basestreamer) {
         dictStream << "   ::Error(\"" << fullname << "::Streamer\", \"version id <=0 in ClassDef,"
                    " dummy Streamer() called\"); if (R__b.IsReading()) { }" << std::endl;
      }
      dictStream << "}" << std::endl << std::endl;
      while (enclSpaceNesting) {
         dictStream << "} // namespace " << nsname.c_str() << std::endl;
         --enclSpaceNesting;
      }
      return;
   }

   // loop twice: first time write reading code, second time writing code
   string classname = fullname;
   if (strstr(fullname.c_str(), "::")) {
      // there is a namespace involved, trigger MS VC bug workaround
      dictStream << "   //This works around a msvc bug and should be harmless on other platforms" << std::endl
                 << "   typedef ::" << fullname << " thisClass;" << std::endl;
      classname = "thisClass";
   }
   for (int i = 0; i < 2; i++) {

      int decli = 0;

      if (i == 0) {
         dictStream << "   UInt_t R__s, R__c;" << std::endl;
         dictStream << "   if (R__b.IsReading()) {" << std::endl;
         dictStream << "      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }" << std::endl;
      } else {
         dictStream << "      R__b.CheckByteCount(R__s, R__c, " << classname.c_str() << "::IsA());" << std::endl;
         dictStream << "   } else {" << std::endl;
         dictStream << "      R__c = R__b.WriteVersion(" << classname.c_str() << "::IsA(), kTRUE);" << std::endl;
      }

      // Stream base class(es) when they have the Streamer() method
      int base = 0;
      for (clang::CXXRecordDecl::base_class_const_iterator iter = clxx->bases_begin(), end = clxx->bases_end();
            iter != end;
            ++iter) {
         if (ROOT::TMetaUtils::ClassInfo__HasMethod(iter->getType()->getAsCXXRecordDecl(), "Streamer", interp)) {
            string base_fullname;
            ROOT::TMetaUtils::GetQualifiedName(base_fullname, * iter->getType()->getAsCXXRecordDecl());

            if (strstr(base_fullname.c_str(), "::")) {
               // there is a namespace involved, trigger MS VC bug workaround
               dictStream << "      //This works around a msvc bug and should be harmless on other platforms" << std::endl
                          << "      typedef " << base_fullname << " baseClass" << base << ";" << std::endl
                          << "      baseClass" << base << "::Streamer(R__b);" << std::endl;
               ++base;
            } else {
               dictStream << "      " << base_fullname << "::Streamer(R__b);" << std::endl;
            }
         }
      }
      // Stream data members
      // Loop over the non static data member.
      for (clang::RecordDecl::field_iterator field_iter = clxx->field_begin(), end = clxx->field_end();
            field_iter != end;
            ++field_iter) {
         const char *comment = ROOT::TMetaUtils::GetComment(**field_iter).data();

         clang::QualType type = field_iter->getType();
         std::string type_name = type.getAsString(clxx->getASTContext().getPrintingPolicy());

         const clang::Type *underling_type = ROOT::TMetaUtils::GetUnderlyingType(type);

         // we skip:
         //  - static members
         //  - members with an ! as first character in the title (comment) field

         //special case for Float16_t
         int isFloat16 = 0;
         if (strstr(type_name.c_str(), "Float16_t")) isFloat16 = 1;

         //special case for Double32_t
         int isDouble32 = 0;
         if (strstr(type_name.c_str(), "Double32_t")) isDouble32 = 1;

         // No need to test for static, there are not in this list.
         if (strncmp(comment, "!", 1)) {

            // fundamental type: short, int, long, etc....
            if (underling_type->isFundamentalType() || underling_type->isEnumeralType()) {
               if (type.getTypePtr()->isConstantArrayType() &&
                     type.getTypePtr()->getArrayElementTypeNoTypeQual()->isPointerType()) {
                  const clang::ConstantArrayType *arrayType = llvm::dyn_cast<clang::ConstantArrayType>(type.getTypePtr());
                  int s = GetFullArrayLength(arrayType);

                  if (!decli) {
                     dictStream << "      int R__i;" << std::endl;
                     decli = 1;
                  }
                  dictStream << "      for (R__i = 0; R__i < " << s << "; R__i++)" << std::endl;
                  if (i == 0) {
                     ROOT::TMetaUtils::Error(0, "*** Datamember %s::%s: array of pointers to fundamental type (need manual intervention)\n", fullname.c_str(), field_iter->getName().str().c_str());
                     dictStream << "         ;//R__b.ReadArray(" << field_iter->getName().str() << ");" << std::endl;
                  } else {
                     dictStream << "         ;//R__b.WriteArray(" << field_iter->getName().str() << ", __COUNTER__);" << std::endl;
                  }
               } else if (type.getTypePtr()->isPointerType()) {
                  llvm::StringRef indexvar = GrabIndex(**field_iter, i == 0);
                  if (indexvar.size() == 0) {
                     if (i == 0) {
                        ROOT::TMetaUtils::Error(0, "*** Datamember %s::%s: pointer to fundamental type (need manual intervention)\n", fullname.c_str(), field_iter->getName().str().c_str());
                        dictStream << "      //R__b.ReadArray(" << field_iter->getName().str() << ");" << std::endl;
                     } else {
                        dictStream << "      //R__b.WriteArray(" << field_iter->getName().str() << ", __COUNTER__);" << std::endl;
                     }
                  } else {
                     if (i == 0) {
                        dictStream << "      delete [] " << field_iter->getName().str() << ";" << std::endl
                                   << "      " << GetNonConstMemberName(**field_iter) << " = new "
                                   << ROOT::TMetaUtils::ShortTypeName(**field_iter) << "[" << indexvar.str() << "];" << std::endl;
                        if (isFloat16) {
                           dictStream << "      R__b.ReadFastArrayFloat16(" <<  GetNonConstMemberName(**field_iter)
                                      << "," << indexvar.str() << ");" << std::endl;
                        } else if (isDouble32) {
                           dictStream << "      R__b.ReadFastArrayDouble32(" <<  GetNonConstMemberName(**field_iter)
                                      << "," << indexvar.str() << ");" << std::endl;
                        } else {
                           dictStream << "      R__b.ReadFastArray(" << GetNonConstMemberName(**field_iter)
                                      << "," << indexvar.str() << ");" << std::endl;
                        }
                     } else {
                        if (isFloat16) {
                           dictStream << "      R__b.WriteFastArrayFloat16("
                                      << field_iter->getName().str() << "," << indexvar.str() << ");" << std::endl;
                        } else if (isDouble32) {
                           dictStream << "      R__b.WriteFastArrayDouble32("
                                      << field_iter->getName().str() << "," << indexvar.str() << ");" << std::endl;
                        } else {
                           dictStream << "      R__b.WriteFastArray("
                                      << field_iter->getName().str() << "," << indexvar.str() << ");" << std::endl;
                        }
                     }
                  }
               } else if (type.getTypePtr()->isArrayType()) {
                  if (i == 0) {
                     if (type.getTypePtr()->getArrayElementTypeNoTypeQual()->isArrayType()) { // if (m.ArrayDim() > 1) {
                        if (underling_type->isEnumeralType())
                           dictStream << "      R__b.ReadStaticArray((Int_t*)" << field_iter->getName().str() << ");" << std::endl;
                        else {
                           if (isFloat16) {
                              dictStream << "      R__b.ReadStaticArrayFloat16((" << ROOT::TMetaUtils::TrueName(**field_iter)
                                         << "*)" << field_iter->getName().str() << ");" << std::endl;
                           } else if (isDouble32) {
                              dictStream << "      R__b.ReadStaticArrayDouble32((" << ROOT::TMetaUtils::TrueName(**field_iter)
                                         << "*)" << field_iter->getName().str() << ");" << std::endl;
                           } else {
                              dictStream << "      R__b.ReadStaticArray((" << ROOT::TMetaUtils::TrueName(**field_iter)
                                         << "*)" << field_iter->getName().str() << ");" << std::endl;
                           }
                        }
                     } else {
                        if (underling_type->isEnumeralType()) {
                           dictStream << "      R__b.ReadStaticArray((Int_t*)" << field_iter->getName().str() << ");" << std::endl;
                        } else {
                           if (isFloat16) {
                              dictStream << "      R__b.ReadStaticArrayFloat16(" << field_iter->getName().str() << ");" << std::endl;
                           } else if (isDouble32) {
                              dictStream << "      R__b.ReadStaticArrayDouble32(" << field_iter->getName().str() << ");" << std::endl;
                           } else {
                              dictStream << "      R__b.ReadStaticArray((" << ROOT::TMetaUtils::TrueName(**field_iter)
                                         << "*)" << field_iter->getName().str() << ");" << std::endl;
                           }
                        }
                     }
                  } else {
                     const clang::ConstantArrayType *arrayType = llvm::dyn_cast<clang::ConstantArrayType>(type.getTypePtr());
                     int s = GetFullArrayLength(arrayType);

                     if (type.getTypePtr()->getArrayElementTypeNoTypeQual()->isArrayType()) {// if (m.ArrayDim() > 1) {
                        if (underling_type->isEnumeralType())
                           dictStream << "      R__b.WriteArray((Int_t*)" << field_iter->getName().str() << ", "
                                      << s << ");" << std::endl;
                        else if (isFloat16) {
                           dictStream << "      R__b.WriteArrayFloat16((" << ROOT::TMetaUtils::TrueName(**field_iter)
                                      << "*)" << field_iter->getName().str() << ", " << s << ");" << std::endl;
                        } else if (isDouble32) {
                           dictStream << "      R__b.WriteArrayDouble32((" << ROOT::TMetaUtils::TrueName(**field_iter)
                                      << "*)" << field_iter->getName().str() << ", " << s << ");" << std::endl;
                        } else {
                           dictStream << "      R__b.WriteArray((" << ROOT::TMetaUtils::TrueName(**field_iter)
                                      << "*)" << field_iter->getName().str() << ", " << s << ");" << std::endl;
                        }
                     } else {
                        if (underling_type->isEnumeralType())
                           dictStream << "      R__b.WriteArray((Int_t*)" << field_iter->getName().str() << ", " << s << ");" << std::endl;
                        else if (isFloat16) {
                           dictStream << "      R__b.WriteArrayFloat16(" << field_iter->getName().str() << ", " << s << ");" << std::endl;
                        } else if (isDouble32) {
                           dictStream << "      R__b.WriteArrayDouble32(" << field_iter->getName().str() << ", " << s << ");" << std::endl;
                        } else {
                           dictStream << "      R__b.WriteArray(" << field_iter->getName().str() << ", " << s << ");" << std::endl;
                        }
                     }
                  }
               } else if (underling_type->isEnumeralType()) {
                  if (i == 0) {
                     dictStream << "      void *ptr_" << field_iter->getName().str() << " = (void*)&" << field_iter->getName().str() << ";\n";
                     dictStream << "      R__b >> *reinterpret_cast<Int_t*>(ptr_" << field_iter->getName().str() << ");" << std::endl;
                  } else
                     dictStream << "      R__b << (Int_t)" << field_iter->getName().str() << ";" << std::endl;
               } else {
                  if (isFloat16) {
                     if (i == 0)
                        dictStream << "      {float R_Dummy; R__b >> R_Dummy; " << GetNonConstMemberName(**field_iter)
                                   << "=Float16_t(R_Dummy);}" << std::endl;
                     else
                        dictStream << "      R__b << float(" << GetNonConstMemberName(**field_iter) << ");" << std::endl;
                  } else if (isDouble32) {
                     if (i == 0)
                        dictStream << "      {float R_Dummy; R__b >> R_Dummy; " << GetNonConstMemberName(**field_iter)
                                   << "=Double32_t(R_Dummy);}" << std::endl;
                     else
                        dictStream << "      R__b << float(" << GetNonConstMemberName(**field_iter) << ");" << std::endl;
                  } else {
                     if (i == 0)
                        dictStream << "      R__b >> " << GetNonConstMemberName(**field_iter) << ";" << std::endl;
                     else
                        dictStream << "      R__b << " << GetNonConstMemberName(**field_iter) << ";" << std::endl;
                  }
               }
            } else {
               // we have an object...

               // check if object is a standard string
               if (STLStringStreamer(**field_iter, i, dictStream))
                  continue;

               // check if object is an STL container
               if (STLContainerStreamer(**field_iter, i, interp, normCtxt, dictStream))
                  continue;

               // handle any other type of objects
               if (type.getTypePtr()->isConstantArrayType() &&
                     type.getTypePtr()->getArrayElementTypeNoTypeQual()->isPointerType()) {
                  const clang::ConstantArrayType *arrayType = llvm::dyn_cast<clang::ConstantArrayType>(type.getTypePtr());
                  int s = GetFullArrayLength(arrayType);

                  if (!decli) {
                     dictStream << "      int R__i;" << std::endl;
                     decli = 1;
                  }
                  dictStream << "      for (R__i = 0; R__i < " << s << "; R__i++)" << std::endl;
                  if (i == 0)
                     dictStream << "         R__b >> " << GetNonConstMemberName(**field_iter);
                  else {
                     if (ROOT::TMetaUtils::IsBase(**field_iter, "TObject", interp) && ROOT::TMetaUtils::IsBase(**field_iter, "TArray", interp))
                        dictStream << "         R__b << (TObject*)" << field_iter->getName().str();
                     else
                        dictStream << "         R__b << " << GetNonConstMemberName(**field_iter);
                  }
                  WriteArrayDimensions(field_iter->getType(), dictStream);
                  dictStream << "[R__i];" << std::endl;
               } else if (type.getTypePtr()->isPointerType()) {
                  // This is always good. However, in case of a pointer
                  // to an object that is guarenteed to be there and not
                  // being referenced by other objects we could use
                  //     xx->Streamer(b);
                  // Optimize this with control statement in title.
                  if (isPointerToPointer(**field_iter)) {
                     if (i == 0) {
                        ROOT::TMetaUtils::Error(0, "*** Datamember %s::%s: pointer to pointer (need manual intervention)\n", fullname.c_str(), field_iter->getName().str().c_str());
                        dictStream << "      //R__b.ReadArray(" << field_iter->getName().str() << ");" << std::endl;
                     } else {
                        dictStream << "      //R__b.WriteArray(" << field_iter->getName().str() << ", __COUNTER__);";
                     }
                  } else {
                     if (ROOT::TMetaUtils::GetQualifiedName(*ROOT::TMetaUtils::GetUnderlyingType(field_iter->getType()), **field_iter) == "TClonesArray") {
                        dictStream << "      " << field_iter->getName().str() << "->Streamer(R__b);" << std::endl;
                     } else {
                        if (i == 0) {
                           // The following:
                           //    if (strncmp(m.Title(),"->",2) != 0) fprintf(fp, "      delete %s;\n", GetNonConstMemberName(**field_iter).c_str());
                           // could be used to prevent a memory leak since the next statement could possibly create a new object.
                           // In the TStreamerInfo based I/O we made the previous statement conditional on TStreamerInfo::CanDelete
                           // to allow the user to prevent some inadvisable deletions.  So we should be offering this flexibility
                           // here to and should not (technically) rely on TStreamerInfo for it, so for now we leave it as is.
                           // Note that the leak should happen from here only if the object is stored in an unsplit object
                           // and either the user request an old branch or the streamer has been customized.
                           dictStream << "      R__b >> " << GetNonConstMemberName(**field_iter) << ";" << std::endl;
                        } else {
                           if (ROOT::TMetaUtils::IsBase(**field_iter, "TObject", interp) && ROOT::TMetaUtils::IsBase(**field_iter, "TArray", interp))
                              dictStream << "      R__b << (TObject*)" << field_iter->getName().str() << ";" << std::endl;
                           else
                              dictStream << "      R__b << " << GetNonConstMemberName(**field_iter) << ";" << std::endl;
                        }
                     }
                  }
               } else if (const clang::ConstantArrayType *arrayType = llvm::dyn_cast<clang::ConstantArrayType>(type.getTypePtr())) {
                  int s = GetFullArrayLength(arrayType);

                  if (!decli) {
                     dictStream << "      int R__i;" << std::endl;
                     decli = 1;
                  }
                  dictStream << "      for (R__i = 0; R__i < " << s << "; R__i++)" << std::endl;
                  std::string mTypeNameStr;
                  ROOT::TMetaUtils::GetQualifiedName(mTypeNameStr, field_iter->getType(), **field_iter);
                  const char *mTypeName = mTypeNameStr.c_str();
                  const char *constwd = "const ";
                  if (strncmp(constwd, mTypeName, strlen(constwd)) == 0) {
                     mTypeName += strlen(constwd);
                     dictStream << "         const_cast< " << mTypeName << " &>(" << field_iter->getName().str();
                     WriteArrayDimensions(field_iter->getType(), dictStream);
                     dictStream << "[R__i]).Streamer(R__b);" << std::endl;
                  } else {
                     dictStream << "         " << GetNonConstMemberName(**field_iter);
                     WriteArrayDimensions(field_iter->getType(), dictStream);
                     dictStream << "[R__i].Streamer(R__b);" << std::endl;
                  }
               } else {
                  if (ROOT::TMetaUtils::ClassInfo__HasMethod(ROOT::TMetaUtils::GetUnderlyingRecordDecl(field_iter->getType()), "Streamer", interp))
                     dictStream << "      " << GetNonConstMemberName(**field_iter) << ".Streamer(R__b);" << std::endl;
                  else {
                     dictStream << "      R__b.StreamObject(&(" << field_iter->getName().str() << "),typeid("
                                << field_iter->getName().str() << "));" << std::endl;               //R__t.Streamer(R__b);\n");
                     //VP                     if (i == 0)
                     //VP                        Error(0, "*** Datamember %s::%s: object has no Streamer() method (need manual intervention)\n",
                     //VP                                  fullname, field_iter->getName().str());
                     //VP                     fprintf(fp, "      //%s.Streamer(R__b);\n", m.Name());
                  }
               }
            }
         }
      }
   }
   dictStream << "      R__b.SetByteCount(R__c, kTRUE);" << std::endl
              << "   }" << std::endl
              << "}" << std::endl << std::endl;

   while (enclSpaceNesting) {
      dictStream << "} // namespace " << nsname.c_str() << std::endl;
      --enclSpaceNesting;
   }
}

////////////////////////////////////////////////////////////////////////////////

void WriteAutoStreamer(const ROOT::TMetaUtils::AnnotatedRecordDecl &cl,
                       const cling::Interpreter &interp,
                       const ROOT::TMetaUtils::TNormalizedCtxt &normCtxt,
                       std::ostream &dictStream)
{
   // Write Streamer() method suitable for automatic schema evolution.

   const clang::CXXRecordDecl *clxx = llvm::dyn_cast<clang::CXXRecordDecl>(cl.GetRecordDecl());
   if (clxx == 0) return;

   bool add_template_keyword = ROOT::TMetaUtils::NeedTemplateKeyword(clxx);

   // We also need to look at the base classes.
   for (clang::CXXRecordDecl::base_class_const_iterator iter = clxx->bases_begin(), end = clxx->bases_end();
         iter != end;
         ++iter) {
      int k = ROOT::TMetaUtils::IsSTLContainer(*iter);
      if (k != 0) {
         Internal::RStl::Instance().GenerateTClassFor(iter->getType(), interp, normCtxt);
      }
   }

   string fullname;
   string clsname;
   string nsname;
   int enclSpaceNesting = 0;

   if (ROOT::TMetaUtils::GetNameWithinNamespace(fullname, clsname, nsname, clxx)) {
      enclSpaceNesting = ROOT::TMetaUtils::WriteNamespaceHeader(dictStream, cl);
   }

   dictStream << "//_______________________________________"
              << "_______________________________________" << std::endl;
   if (add_template_keyword) dictStream << "template <> ";
   dictStream << "void " << clsname << "::Streamer(TBuffer &R__b)" << std::endl
              << "{" << std::endl
              << "   // Stream an object of class " << fullname << "." << std::endl << std::endl
              << "   if (R__b.IsReading()) {" << std::endl
              << "      R__b.ReadClassBuffer(" << fullname << "::Class(),this);" << std::endl
              << "   } else {" << std::endl
              << "      R__b.WriteClassBuffer(" << fullname << "::Class(),this);" << std::endl
              << "   }" << std::endl
              << "}" << std::endl << std::endl;

   while (enclSpaceNesting) {
      dictStream << "} // namespace " << nsname << std::endl;
      --enclSpaceNesting;
   }
}

////////////////////////////////////////////////////////////////////////////////

void CallWriteStreamer(const ROOT::TMetaUtils::AnnotatedRecordDecl &cl,
                       const cling::Interpreter &interp,
                       const ROOT::TMetaUtils::TNormalizedCtxt &normCtxt,
                       std::ostream &dictStream,
                       bool isAutoStreamer)
{
   if (isAutoStreamer) {
      WriteAutoStreamer(cl, interp, normCtxt, dictStream);
   } else {
      WriteStreamer(cl, interp, normCtxt, dictStream);
   }
}

////////////////////////////////////////////////////////////////////////////////

void GenerateLinkdef(int *argc, char **argv, int firstInputFile,
                     std::string &code_for_parser)
{
   code_for_parser += "#ifdef __CINT__\n\n";
   code_for_parser += "#pragma link off all globals;\n";
   code_for_parser += "#pragma link off all classes;\n";
   code_for_parser += "#pragma link off all functions;\n\n";

   for (int i = firstInputFile; i < *argc; i++) {
      char *s, trail[3];
      int   nostr = 0, noinp = 0, bcnt = 0, l = strlen(argv[i]) - 1;
      for (int j = 0; j < 3; j++) {
         if (argv[i][l] == '-') {
            argv[i][l] = '\0';
            nostr = 1;
            l--;
         }
         if (argv[i][l] == '!') {
            argv[i][l] = '\0';
            noinp = 1;
            l--;
         }
         if (argv[i][l] == '+') {
            argv[i][l] = '\0';
            bcnt = 1;
            l--;
         }
      }
      if (nostr || noinp) {
         trail[0] = 0;
         if (nostr) strlcat(trail, "-", 3);
         if (noinp) strlcat(trail, "!", 3);
      }
      if (bcnt) {
         strlcpy(trail, "+", 3);
         if (nostr)
            ROOT::TMetaUtils::Error(0, "option + mutual exclusive with -\n");
      }
      char *cls = strrchr(argv[i], '/');
      if (!cls) cls = strrchr(argv[i], '\\');
      if (cls)
         cls++;
      else
         cls = argv[i];
      if ((s = strrchr(cls, '.'))) * s = '\0';
      code_for_parser += "#pragma link C++ class ";
      code_for_parser += cls;
      if (nostr || noinp || bcnt)
         code_for_parser += trail;
      code_for_parser += ";\n";
      if (s) *s = '.';
   }

   code_for_parser += "\n#endif\n";

}

////////////////////////////////////////////////////////////////////////////////
/// Find file name in path specified via -I statements to Cling.
/// Return false if the file can not be found.
/// If the file is found, set pname to the full path name and return true.

bool Which(cling::Interpreter &interp, const char *fname, string &pname)
{
   FILE *fp = 0;

#ifdef WIN32
   static const char *fopenopts = "rb";
#else
   static const char *fopenopts = "r";
#endif

   pname = fname;
   fp = fopen(pname.c_str(), fopenopts);
   if (fp) {
      fclose(fp);
      return true;
   }

   llvm::SmallVector<std::string, 10> includePaths;//Why 10? Hell if I know.
   //false - no system header, false - with flags.
   interp.GetIncludePaths(includePaths, false, false);

   const size_t nPaths = includePaths.size();
   for (size_t i = 0; i < nPaths; i += 1 /* 2 */) {

      pname = includePaths[i].c_str() + gPathSeparator + fname;

      fp = fopen(pname.c_str(), fopenopts);
      if (fp) {
         fclose(fp);
         return true;
      }
   }
   pname = "";
   return false;
}

////////////////////////////////////////////////////////////////////////////////
/// If the argument starts with MODULE/inc, strip it
/// to make it the name we can use in #includes.

const char *CopyArg(const char *original)
{
   if (!gBuildingROOT)
      return original;

   if (IsSelectionFile(original))
      return original;

   const char *inc = strstr(original, "\\inc\\");
   if (!inc)
      inc = strstr(original, "/inc/");
   if (inc && strlen(inc) > 5)
      return inc + 5;
   return original;
}

////////////////////////////////////////////////////////////////////////////////
/// Copy the command line argument, stripping MODULE/inc if
/// necessary.

void StrcpyArg(string &dest, const char *original)
{
   dest = CopyArg(original);
}

////////////////////////////////////////////////////////////////////////////////
/// Write the extra header injected into the module:
/// umbrella header if (umbrella) else content header.

static bool InjectModuleUtilHeader(const char *argv0,
                                   TModuleGenerator &modGen,
                                   cling::Interpreter &interp,
                                   bool umbrella)
{
   std::ostringstream out;
   if (umbrella) {
      // This will duplicate the -D,-U from clingArgs - but as they are surrounded
      // by #ifndef there is no problem here.
      modGen.WriteUmbrellaHeader(out);
   } else {
      modGen.WriteContentHeader(out);
   }
   if (interp.declare(out.str()) != cling::Interpreter::kSuccess) {
      const std::string &hdrName
         = umbrella ? modGen.GetUmbrellaName() : modGen.GetContentName();
      ROOT::TMetaUtils::Error(0, "%s: compilation failure (%s)\n", argv0,
                              hdrName.c_str());
      return false;
   }
   return true;
}

////////////////////////////////////////////////////////////////////////////////
/// Write the AST of the given CompilerInstance to the given File while
/// respecting the given isysroot.
/// If module is not a null pointer, we only write the given module to the
/// given file and not the whole AST.
/// Returns true if the AST was succesfully written.
static bool WriteAST(StringRef fileName, clang::CompilerInstance *compilerInstance, StringRef iSysRoot,
                     clang::Module *module = nullptr)
{
   // From PCHGenerator and friends:
   llvm::SmallVector<char, 128> buffer;
   llvm::BitstreamWriter stream(buffer);
   clang::ASTWriter writer(stream, buffer, compilerInstance->getPCMCache(), /*Extensions=*/{});
   std::unique_ptr<llvm::raw_ostream> out =
      compilerInstance->createOutputFile(fileName, /*Binary=*/true,
                                         /*RemoveFileOnSignal=*/false, /*InFile*/ "",
                                         /*Extension=*/"", /*useTemporary=*/false,
                                         /*CreateMissingDirectories*/ false);
   if (!out) {
      ROOT::TMetaUtils::Error("WriteAST", "Couldn't open output stream to '%s'!\n", fileName.data());
      return false;
   }

   compilerInstance->getFrontendOpts().RelocatablePCH = true;

   writer.WriteAST(compilerInstance->getSema(), fileName, module, iSysRoot);

   // Write the generated bitstream to "Out".
   out->write(&buffer.front(), buffer.size());

   // Make sure it hits disk now.
   out->flush();
   bool deleteOutputFile = compilerInstance->getDiagnostics().hasErrorOccurred();
   compilerInstance->clearOutputFiles(deleteOutputFile);

   return true;
}

////////////////////////////////////////////////////////////////////////////////
/// Generates a PCH from the given ModuleGenerator and CompilerInstance.
/// Returns true iff the PCH was succesfully generated.
static bool GenerateAllDict(TModuleGenerator &modGen, clang::CompilerInstance *compilerInstance,
                            const std::string &currentDirectory)
{
   assert(modGen.IsPCH() && "modGen must be in PCH mode");

   std::string iSysRoot("/DUMMY_SYSROOT/include/");
   if (gBuildingROOT) iSysRoot = (currentDirectory + "/");
   return WriteAST(modGen.GetModuleFileName(), compilerInstance, iSysRoot);
}

////////////////////////////////////////////////////////////////////////////////
/// Returns true iff a given module (and its submodules) contains all headers
/// needed by the given ModuleGenerator.
/// The names of all header files that are needed by the ModuleGenerator but are
/// not in the given module will be inserted into the MissingHeader variable.
/// Returns true iff the PCH was succesfully generated.
static bool ModuleContainsHeaders(TModuleGenerator &modGen, clang::Module *module,
                                  std::vector<std::string> &missingHeaders)
{
   // Make a list of modules and submodules that we can check for headers.
   // We use a SetVector to prevent an infinite loop in unlikely case the
   // modules somehow are messed up and don't form a tree...
   llvm::SetVector<clang::Module *> modules;
   modules.insert(module);
   for (size_t i = 0; i < modules.size(); ++i) {
      clang::Module *M = modules[i];
      for (clang::Module *subModule : M->submodules()) modules.insert(subModule);
   }
   // Now we collect all header files from the previously collected modules.
   std::set<std::string> moduleHeaders;
   for (clang::Module *module : modules) {
      // Iterate over all header types in a module.
      // FIXME: We currently have to hardcode '4' to do this. Maybe we
      // will have a nicer way to do this in the future.
      // NOTE: This is on purpose '4', not '5' which is the size of the
      // vector. The last element is the list of excluded headers which we
      // obviously don't want to check here.
      for (int i = 0; i < 4; i++) {
         auto &headerList = module->Headers[i];
         for (const clang::Module::Header &moduleHeader : headerList) {
            moduleHeaders.insert(moduleHeader.NameAsWritten);
         }
      }
   }

   // Go through the list of headers that are required by the ModuleGenerator
   // and check for each header if it's in one of the modules we loaded.
   // If not, make sure we fail at the end and mark the header as missing.
   bool foundAllHeaders = true;
   for (const std::string &header : modGen.GetHeaders()) {
      if (moduleHeaders.find(header) == moduleHeaders.end()) {
         missingHeaders.push_back(header);
         foundAllHeaders = false;
      }
   }
   return foundAllHeaders;
}

////////////////////////////////////////////////////////////////////////////////
/// Generates a module from the given ModuleGenerator and CompilerInstance.
/// Returns true iff the PCM was succesfully generated.
static bool GenerateModule(TModuleGenerator &modGen, clang::CompilerInstance *CI)
{
   assert(!modGen.IsPCH() && "modGen must not be in PCH mode");

   std::string outputFile = modGen.GetModuleFileName();
   std::string includeDir = gDriverConfig->fTROOT__GetIncludeDir();
   clang::HeaderSearch &headerSearch = CI->getPreprocessor().getHeaderSearchInfo();
   auto &fileMgr = headerSearch.getFileMgr();

   // Load the modulemap from the ROOT include directory.
   clang::ModuleMap &moduleMap = headerSearch.getModuleMap();
   std::string moduleMapPath = includeDir + "/module.modulemap";
   auto moduleFile = fileMgr.getFile(moduleMapPath);

   // Check if we actually found the modulemap file...
   if (!moduleFile) {
      ROOT::TMetaUtils::Error("GenerateModule", "Couldn't find ROOT modulemap in"
                                                " %s! Ensure that cxxmodules=On is set in CMake.\n",
                              moduleMapPath.c_str());
      return false;
   }

   moduleMap.parseModuleMapFile(moduleFile, false, fileMgr.getDirectory(includeDir));

   // Try to get the module name in the modulemap based on the filepath.
   std::string moduleName = llvm::sys::path::filename(outputFile);
   // For module "libCore.so" we have the file name "libCore_rdict.pcm".
   // We replace this suffix with ".so" to get the name in the modulefile.
   if (StringRef(moduleName).endswith("_rdict.pcm")) {
      auto lengthWithoutSuffix = moduleName.size() - strlen("_rdict.pcm");
      moduleName = moduleName.substr(0, lengthWithoutSuffix) + ".so";
   }

   // Actually lookup the module on the computed module name.
   clang::Module *module = moduleMap.findModule(moduleName);

   // Inform the user and abort if we can't find a module with a given name.
   if (!module) {
      ROOT::TMetaUtils::Error("GenerateModule", "Couldn't find module with name '%s' in modulemap!\n",
                              moduleName.c_str());
      return false;
   }

   // Check if the loaded module covers all headers that were specified
   // by the user on the command line. This is an integrity check to
   // ensure that our used module map is
   std::vector<std::string> missingHeaders;
   if (!ModuleContainsHeaders(modGen, module, missingHeaders)) {
      // FIXME: Upgrade this to an error once modules are stable.
      std::stringstream msgStream;
      msgStream << "warning: Couldn't find the following specified headers in "
                << "the module " << module->Name << ":\n";
      for (auto &H : missingHeaders) {
         msgStream << "  " << H << "\n";
      }
      std::string warningMessage = msgStream.str();
      ROOT::TMetaUtils::Warning("GenerateModule", warningMessage.c_str());
   }

   return WriteAST(outputFile, CI, "", module);
}

////////////////////////////////////////////////////////////////////////////////

void AddPlatformDefines(std::vector<std::string> &clingArgs)
{
   char platformDefines[64] = {0};
#ifdef __INTEL_COMPILER
   snprintf(platformDefines, 64, "-DG__INTEL_COMPILER=%ld", (long)__INTEL_COMPILER);
   clingArgs.push_back(platformDefines);
#endif
#ifdef __xlC__
   snprintf(platformDefines, 64, "-DG__xlC=%ld", (long)__xlC__);
   clingArgs.push_back(platformDefines);
#endif
#ifdef __GNUC__
   snprintf(platformDefines, 64, "-DG__GNUC=%ld", (long)__GNUC__);
   snprintf(platformDefines, 64, "-DG__GNUC_VER=%ld", (long)__GNUC__ * 1000 + __GNUC_MINOR__);
   clingArgs.push_back(platformDefines);
#endif
#ifdef __GNUC_MINOR__
   snprintf(platformDefines, 64, "-DG__GNUC_MINOR=%ld", (long)__GNUC_MINOR__);
   clingArgs.push_back(platformDefines);
#endif
#ifdef __HP_aCC
   snprintf(platformDefines, 64, "-DG__HP_aCC=%ld", (long)__HP_aCC);
   clingArgs.push_back(platformDefines);
#endif
#ifdef __sun
   snprintf(platformDefines, 64, "-DG__sun=%ld", (long)__sun);
   clingArgs.push_back(platformDefines);
#endif
#ifdef __SUNPRO_CC
   snprintf(platformDefines, 64, "-DG__SUNPRO_CC=%ld", (long)__SUNPRO_CC);
   clingArgs.push_back(platformDefines);
#endif
#ifdef _STLPORT_VERSION
   // stlport version, used on e.g. SUN
   snprintf(platformDefines, 64, "-DG__STLPORT_VERSION=%ld", (long)_STLPORT_VERSION);
   clingArgs.push_back(platformDefines);
#endif
#ifdef __ia64__
   snprintf(platformDefines, 64, "-DG__ia64=%ld", (long)__ia64__);
   clingArgs.push_back(platformDefines);
#endif
#ifdef __x86_64__
   snprintf(platformDefines, 64, "-DG__x86_64=%ld", (long)__x86_64__);
   clingArgs.push_back(platformDefines);
#endif
#ifdef __i386__
   snprintf(platformDefines, 64, "-DG__i386=%ld", (long)__i386__);
   clingArgs.push_back(platformDefines);
#endif
#ifdef __arm__
   snprintf(platformDefines, 64, "-DG__arm=%ld", (long)__arm__);
   clingArgs.push_back(platformDefines);
#endif
#ifdef _WIN32
   snprintf(platformDefines, 64, "-DG__WIN32=%ld", (long)_WIN32);
   clingArgs.push_back(platformDefines);
#else
# ifdef WIN32
   snprintf(platformDefines, 64, "-DG__WIN32=%ld", (long)WIN32);
   clingArgs.push_back(platformDefines);
# endif
#endif
#ifdef _MSC_VER
   snprintf(platformDefines, 64, "-DG__MSC_VER=%ld", (long)_MSC_VER);
   clingArgs.push_back(platformDefines);
   snprintf(platformDefines, 64, "-DG__VISUAL=%ld", (long)_MSC_VER);
   clingArgs.push_back(platformDefines);
#endif
}

////////////////////////////////////////////////////////////////////////////////
/// Extract the filename from a fullpath

std::string ExtractFileName(const std::string &path)
{
   return llvm::sys::path::filename(path);
}

////////////////////////////////////////////////////////////////////////////////
/// Extract the path from a fullpath finding the last \ or /
/// according to the content in gPathSeparator

void ExtractFilePath(const std::string &path, std::string &dirname)
{
   const size_t pos = path.find_last_of(gPathSeparator);
   if (std::string::npos != pos) {
      dirname.assign(path.begin(), path.begin() + pos + 1);
   } else {
      dirname.assign("");
   }
}

////////////////////////////////////////////////////////////////////////////////
/// Check if file has a path

bool HasPath(const std::string &name)
{
   std::string dictLocation;
   ExtractFilePath(name, dictLocation);
   return !dictLocation.empty();
}

////////////////////////////////////////////////////////////////////////////////
/// A set of rules are applied in order to transform the name for the rootmap
/// file
/// * "::" becomes "@@"
/// * "{const,unsigned,signed} " become "{const,unsigned,signed}-"
/// * "*const" becomes "*-const"
/// * "short int" becomes "short"
/// * "long int" becomes "long"
/// * "long long" becomes "long-long"
/// * "long double" becomes "long-double"
/// * " " becomes ""
/// * ">>" becomes ">->" except for "operator>>"

void ManipForRootmap(std::string &name)
{
   using namespace ROOT::TMetaUtils;

   // * "::" becomes "@@"
   ReplaceAll(name, "::", "@@");


   // * "{const,unsigned,signed} " become "{const,unsigned,signed}-"
   // We do it in 2 steps: trim the spaces and replace
   // 1
   name.erase(name.find_last_not_of(" \n\r\t") + 1);
   // 2
   ReplaceAll(name, "const ", "const-");
   ReplaceAll(name, "signed ", "signed-");

   // * "*const" becomes "*-const"
   ReplaceAll(name, "*const", "*-const");

   // * "short int" becomes "short"
   ReplaceAll(name, "short int", "short");

   // * "long int" becomes "long"
   ReplaceAll(name, "long int", "long");

   // * "long long" becomes "long-long"
   ReplaceAll(name, "long long", "long-long");

   // * "long double" becomes "long-double"
   ReplaceAll(name, "long double", "long-double");

   // * " " becomes ""
   ReplaceAll(name, " ", "");
   // But this is could be more efficient
   //name.erase(std::remove_if(name.begin(), name.end(), isspace), name.end());

   // * ">>" becomes ">->" except for "operator>>"
   // We replace blindly and recursively and then roll back for operator>->
   // in other words "Better to Say Sorry than to Ask Permission"
   while (name.find(">>") != std::string::npos) {
      ReplaceAll(name, ">>", ">->");
   }
   ReplaceAll(name, "operator>->", "operator>>");

}

////////////////////////////////////////////////////////////////////////////////

void AdjustRootMapNames(std::string &rootmapFileName,
                        std::string &rootmapLibName)
{
   // If the rootmap file name does not exist, create one following the libname
   // I.E. put into the directory of the lib the rootmap and within the rootmap the normalised path to the lib
   if (rootmapFileName.empty()) {
      size_t libExtensionPos = rootmapLibName.find_last_of(gLibraryExtension) - gLibraryExtension.size() + 1;
      rootmapFileName = rootmapLibName.substr(0, libExtensionPos) + ".rootmap";
      size_t libCleanNamePos = rootmapLibName.find_last_of(gPathSeparator) + 1;
      rootmapLibName = rootmapLibName.substr(libCleanNamePos, std::string::npos);
      ROOT::TMetaUtils::Info(0, "Rootmap file name %s built from rootmap lib name %s",
                             rootmapLibName.c_str(),
                             rootmapFileName.c_str());
   }
}

////////////////////////////////////////////////////////////////////////////////
/// Extract the proper autoload key for nested classes
/// The routine does not erase the name, just updates it

void GetMostExternalEnclosingClassName(const clang::DeclContext &theContext,
                                       std::string &ctxtName,
                                       const cling::Interpreter &interpreter,
                                       bool treatParent = true)
{
   const clang::DeclContext *outerCtxt = treatParent ? theContext.getParent() : &theContext;
   // If the context has no outer context, we are finished
   if (!outerCtxt) return;
   // If the context is a class, we update the name
   if (const clang::RecordDecl *thisRcdDecl = llvm::dyn_cast<clang::RecordDecl>(outerCtxt)) {
      ROOT::TMetaUtils::GetNormalizedName(ctxtName, thisRcdDecl, interpreter);
   }
   // We recurse
   GetMostExternalEnclosingClassName(*outerCtxt, ctxtName, interpreter);
}

////////////////////////////////////////////////////////////////////////////////

void GetMostExternalEnclosingClassNameFromDecl(const clang::Decl &theDecl,
      std::string &ctxtName,
      const cling::Interpreter &interpreter)
{
   const clang::DeclContext *theContext = theDecl.getDeclContext();
   GetMostExternalEnclosingClassName(*theContext, ctxtName, interpreter, false);
}

////////////////////////////////////////////////////////////////////////////////
template<class COLL>
int ExtractAutoloadKeys(std::list<std::string> &names,
                        const COLL &decls,
                        const cling::Interpreter &interp)
{
   if (!decls.empty()) {
      std::string autoLoadKey;
      for (auto & d : decls) {
         autoLoadKey = "";
         GetMostExternalEnclosingClassNameFromDecl(*d, autoLoadKey, interp);
         // If there is an outer class, it is already considered
         if (autoLoadKey.empty()) {
            names.push_back(d->getQualifiedNameAsString());
         }
      }
   }
   return 0;
}

////////////////////////////////////////////////////////////////////////////////
/// Generate a rootmap file in the new format, like
/// { decls }
/// namespace A { namespace B { template <typename T> class myTemplate; } }
/// [libGpad.so libGraf.so libHist.so libMathCore.so]
/// class TAttCanvas
/// class TButton
/// (header1.h header2.h .. headerN.h)
/// class TMyClass

int CreateNewRootMapFile(const std::string &rootmapFileName,
                         const std::string &rootmapLibName,
                         const std::list<std::string> &classesDefsList,
                         const std::list<std::string> &classesNames,
                         const std::list<std::string> &nsNames,
                         const std::list<std::string> &tdNames,
                         const std::list<std::string> &enNames,
                         const std::list<std::string> &varNames,
                         const HeadersDeclsMap_t &headersClassesMap,
                         const std::unordered_set<std::string> headersToIgnore)
{
   // Create the rootmap file from the selected classes and namespaces
   std::ofstream rootmapFile(rootmapFileName.c_str());
   if (!rootmapFile) {
      ROOT::TMetaUtils::Error(0, "Opening new rootmap file %s\n", rootmapFileName.c_str());
      return 1;
   }

   // Keep track of the classes keys
   // This is done to avoid duplications of keys with typedefs
   std::unordered_set<std::string> classesKeys;


   // Add the "section"
   if (!classesNames.empty() || !nsNames.empty() || !tdNames.empty() ||
      !enNames.empty() || !varNames.empty()) {

      // Add the template definitions
      if (!classesDefsList.empty()) {
         rootmapFile << "{ decls }\n";
         for (auto & classDef : classesDefsList) {
            rootmapFile << classDef << std::endl;
         }
         rootmapFile << "\n";
      }
      rootmapFile << "[ " << rootmapLibName << " ]\n";

      // Loop on selected classes and insert them in the rootmap
      if (!classesNames.empty()) {
         rootmapFile << "# List of selected classes\n";
         for (auto & className : classesNames) {
            rootmapFile << "class " << className << std::endl;
            classesKeys.insert(className);
         }
         // And headers
         std::unordered_set<std::string> treatedHeaders;
         for (auto & className : classesNames) {
            // Don't treat templates
            if (className.find("<") != std::string::npos) continue;
            if (headersClassesMap.count(className)) {
               auto &headers = headersClassesMap.at(className);
               if (!headers.empty()){
                  auto &header = headers.front();
                  if (treatedHeaders.insert(header).second &&
                        headersToIgnore.find(header) == headersToIgnore.end() &&
                        ROOT::TMetaUtils::IsHeaderName(header)){
                        rootmapFile << "header " << header << std::endl;
                  }
               }
            }
         }
      }

      // Same for namespaces
      if (!nsNames.empty()) {
         rootmapFile << "# List of selected namespaces\n";
         for (auto & nsName : nsNames) {
            rootmapFile << "namespace " << nsName << std::endl;
         }
      }

      // And typedefs. These are used just to trigger the autoload mechanism
      if (!tdNames.empty()) {
         rootmapFile << "# List of selected typedefs and outer classes\n";
         for (const auto & autoloadKey : tdNames)
            if (classesKeys.insert(autoloadKey).second)
               rootmapFile << "typedef " << autoloadKey << std::endl;
      }

      // And Enums. There is no incomplete type for an enum but we can nevertheless
      // have the key for the cases where the root typesystem is interrogated.
      if (!enNames.empty()){
         rootmapFile << "# List of selected enums and outer classes\n";
         for (const auto & autoloadKey : enNames)
            if (classesKeys.insert(autoloadKey).second)
               rootmapFile << "enum " << autoloadKey << std::endl;
      }

      // And variables.
      if (!varNames.empty()){
         rootmapFile << "# List of selected vars\n";
         for (const auto & autoloadKey : varNames)
            if (classesKeys.insert(autoloadKey).second)
               rootmapFile << "var " << autoloadKey << std::endl;
      }

   }

   return 0;

}

////////////////////////////////////////////////////////////////////////////////
/// Performance is not critical here.

std::pair<std::string,std::string> GetExternalNamespaceAndContainedEntities(const std::string line)
{
   auto nsPattern = '{'; auto nsPatternLength = 1;
   auto foundNsPos = line.find_last_of(nsPattern);
   if (foundNsPos == std::string::npos) return {"",""};
   foundNsPos+=nsPatternLength;
   auto extNs = line.substr(0,foundNsPos);

   auto nsEndPattern = '}';
   auto foundEndNsPos = line.find(nsEndPattern);
   auto contained = line.substr(foundNsPos, foundEndNsPos-foundNsPos);

   return {extNs, contained};


}

////////////////////////////////////////////////////////////////////////////////
/// If two identical namespaces are there, just declare one only
/// Example:
/// namespace A { namespace B { fwd1; }}
/// namespace A { namespace B { fwd2; }}
/// get a namespace A { namespace B { fwd1; fwd2; }} line

std::list<std::string> CollapseIdenticalNamespaces(const std::list<std::string>& fwdDeclarationsList)
{
   // Temp data structure holding the namespaces and the entities therewith
   // contained
   std::map<std::string, std::string> nsEntitiesMap;
   std::list<std::string> optFwdDeclList;
   for (auto const & fwdDecl : fwdDeclarationsList){
      // Check if the decl(s) are contained in a ns and which one
      auto extNsAndEntities = GetExternalNamespaceAndContainedEntities(fwdDecl);
      if (extNsAndEntities.first.empty()) {
         // no namespace found. Just put this on top
         optFwdDeclList.push_front(fwdDecl);
      };
      auto currentVal = nsEntitiesMap[extNsAndEntities.first];
      nsEntitiesMap[extNsAndEntities.first] = currentVal +=extNsAndEntities.second;
   }

   // Now fill the new, optimised list
   std::string optFwdDecl;
   for (auto const & extNsAndEntities : nsEntitiesMap) {
      optFwdDecl = extNsAndEntities.first;
      optFwdDecl += extNsAndEntities.second;
      for (int i = 0; i < std::count(optFwdDecl.begin(), optFwdDecl.end(), '{'); ++i ){
         optFwdDecl += " }";
      }
      optFwdDeclList.push_front(optFwdDecl);
   }

   return optFwdDeclList;

}

////////////////////////////////////////////////////////////////////////////////
/// Separate multiline strings

bool ProcessAndAppendIfNotThere(const std::string &el,
                                std::list<std::string> &el_list,
                                std::unordered_set<std::string> &el_set)
{
   std::stringstream elStream(el);
   std::string tmp;
   while (getline(elStream, tmp, '\n')) {
      // Add if not there
      if (el_set.insert(tmp).second && !tmp.empty()) {
         el_list.push_back(tmp);
         return true;
      }
   }

   return false;
}

////////////////////////////////////////////////////////////////////////////////

int  ExtractClassesListAndDeclLines(RScanner &scan,
      std::list<std::string> &classesList,
      std::list<std::string> &classesListForRootmap,
      std::list<std::string> &fwdDeclarationsList,
      const cling::Interpreter &interpreter)
{
   // Loop on selected classes. If they don't have the attribute "rootmap"
   // set to "false", store them in the list of classes for the rootmap
   // Returns 0 in case of success and 1 in case of issues.

   // An unordered_set to keep track of the existing classes.
   // We want to avoid duplicates there as they may hint to a serious corruption
   std::unordered_set<std::string> classesSet;
   std::unordered_set<std::string> outerMostClassesSet;

   std::string attrName, attrValue;
   bool isClassSelected;
   std::unordered_set<std::string> availableFwdDecls;
   std::string fwdDeclaration;
   for (auto const & selVar : scan.fSelectedVariables) {
      fwdDeclaration = "";
      int retCode = ROOT::TMetaUtils::AST2SourceTools::EncloseInNamespaces(*selVar, fwdDeclaration);
      if (retCode == 0) ProcessAndAppendIfNotThere(fwdDeclaration, fwdDeclarationsList, availableFwdDecls);
   }

   for (auto const & selEnum : scan.fSelectedEnums) {
      fwdDeclaration = "";
      int retCode = ROOT::TMetaUtils::AST2SourceTools::EncloseInNamespaces(*selEnum, fwdDeclaration);
      if (retCode == 0) ProcessAndAppendIfNotThere(fwdDeclaration, fwdDeclarationsList, availableFwdDecls);
   }

   // Loop on selected classes and put them in a list
   for (auto const & selClass : scan.fSelectedClasses) {
      isClassSelected = true;
      const clang::RecordDecl *rDecl = selClass.GetRecordDecl();
      std::string normalizedName;
      normalizedName = selClass.GetNormalizedName();
      if (!normalizedName.empty() &&
            !classesSet.insert(normalizedName).second &&
            outerMostClassesSet.count(normalizedName) == 0) {
         std::cerr << "FATAL: A class with normalized name " << normalizedName
                   << " was already selected. This means that two different instances of"
                   << " clang::RecordDecl had the same name, which is not possible."
                   << " This can be a hint of a serious problem in the class selection."
                   << " In addition, the generated dictionary would not even compile.\n";
         return 1;
      }
      classesList.push_back(normalizedName);
      // Allow to autoload with the name of the class as it was specified in the
      // selection xml or linkdef
      const char *reqName(selClass.GetRequestedName());

      // Get always the containing namespace, put it in the list if not there
      fwdDeclaration = "";
      int retCode = ROOT::TMetaUtils::AST2SourceTools::EncloseInNamespaces(*rDecl, fwdDeclaration);
      if (retCode == 0) ProcessAndAppendIfNotThere(fwdDeclaration, fwdDeclarationsList, availableFwdDecls);

      // Get template definition and put it in if not there
      if (llvm::isa<clang::ClassTemplateSpecializationDecl>(rDecl)) {
         fwdDeclaration = "";
         retCode = ROOT::TMetaUtils::AST2SourceTools::FwdDeclFromRcdDecl(*rDecl, interpreter, fwdDeclaration);
         if (retCode == 0) ProcessAndAppendIfNotThere(fwdDeclaration, fwdDeclarationsList, availableFwdDecls);
      }


      // Loop on attributes, if rootmap=false, don't put it in the list!
      for (auto ait = rDecl->attr_begin(); ait != rDecl->attr_end(); ++ait) {
         if (0 == ROOT::TMetaUtils::extractPropertyNameVal(*ait, attrName, attrValue) &&
               attrName == "rootmap" &&
               attrValue == "false") {
            attrName = attrValue = "";
            isClassSelected = false;
            break;
         }
      }
      if (isClassSelected) {
         // Now, check if this is an internal class. If yes, we check the name of the outermost one
         // This is because of ROOT-6517. On the other hand, we exclude from this treatment
         // classes which are template instances which are nested in classes. For example:
         // class A{
         //   class B{};
         // };
         // selection: <class name="A::B" />
         // Will result in a rootmap entry like "class A"
         // On the other hand, taking
         // class A{
         //    public:
         //     template <class T> class B{};
         //  };
         // selection: <class name="A::B<int>" />
         // Would result in an entry like "class A::B<int>"
         std::string outerMostClassName;
         GetMostExternalEnclosingClassName(*rDecl, outerMostClassName, interpreter);
         if (!outerMostClassName.empty() &&
             !llvm::isa<clang::ClassTemplateSpecializationDecl>(rDecl) &&
             classesSet.insert(outerMostClassName).second &&
             outerMostClassesSet.insert(outerMostClassName).second) {
            classesListForRootmap.push_back(outerMostClassName);
         } else {
            classesListForRootmap.push_back(normalizedName);
            if (reqName != nullptr && 0 != strcmp(reqName, "") && reqName != normalizedName) {
               classesListForRootmap.push_back(reqName);
            }

            // Also register typeinfo::name(), unless we have pseudo-strong typedefs:
            if (normalizedName.find("Double32_t") == std::string::npos
                && normalizedName.find("Float16_t") == std::string::npos) {
               std::unique_ptr<clang::MangleContext> mangleCtx(rDecl->getASTContext().createMangleContext());
               std::string mangledName;
               {
                  llvm::raw_string_ostream sstr(mangledName);
                  if (const clang::TypeDecl* TD = llvm::dyn_cast<clang::TypeDecl>(rDecl)) {
                     mangleCtx->mangleTypeName(clang::QualType(TD->getTypeForDecl(), 0), sstr);
                  }
               }
               if (!mangledName.empty()) {
                  int errDemangle = 0;
                  char* demangledTIName = TClassEdit::DemangleName(mangledName.c_str(), errDemangle);
                  if (!errDemangle && demangledTIName) {
                     static const char typeinfoNameFor[] = "typeinfo name for ";
                     if (!strncmp(demangledTIName, typeinfoNameFor, strlen(typeinfoNameFor))) {
                        std::string demangledName = demangledTIName + strlen(typeinfoNameFor);
                        // See the operations in TCling::AutoLoad(type_info)
                        TClassEdit::TSplitType splitname( demangledName.c_str(), (TClassEdit::EModType)(TClassEdit::kLong64 | TClassEdit::kDropStd) );
                        splitname.ShortType(demangledName, TClassEdit::kDropStlDefault | TClassEdit::kDropStd);

                        if (demangledName != normalizedName && (!reqName || demangledName != reqName)) {
                           classesListForRootmap.push_back(demangledName);
                        } // if demangledName != other name
                     } else {
                        ROOT::TMetaUtils::Error("ExtractClassesListAndDeclLines",
                                                "Demangled typeinfo name '%s' does not start with 'typeinfo name for'\n",
                                                demangledTIName);
                     } // if demangled type_info starts with "typeinfo name for "
                  } // if demangling worked
                  free(demangledTIName);
               } // if mangling worked
            } // if no pseudo-strong typedef involved
         }
      }
   }
   classesListForRootmap.sort();

   // Disable for the moment
   // fwdDeclarationsList = CollapseIdenticalNamespaces(fwdDeclarationsList);

   return 0;
}

////////////////////////////////////////////////////////////////////////////////
/// Loop on selected classes and put them in a list

void ExtractSelectedNamespaces(RScanner &scan, std::list<std::string> &nsList)
{
   for (RScanner::NamespaceColl_t::const_iterator selNsIter = scan.fSelectedNamespaces.begin();
         selNsIter != scan.fSelectedNamespaces.end(); selNsIter++) {
      nsList.push_back(ROOT::TMetaUtils::GetQualifiedName(* selNsIter->GetNamespaceDecl()));
   }
}

////////////////////////////////////////////////////////////////////////////////
/// We need annotations even in the PCH: // !, // || etc.

void AnnotateAllDeclsForPCH(cling::Interpreter &interp,
                            RScanner &scan)
{
   auto const & declSelRulesMap = scan.GetDeclsSelRulesMap();
   for (auto const & selClass : scan.fSelectedClasses) {
      // Very important: here we decide if we want to attach attributes to the decl.
      if (clang::CXXRecordDecl *CXXRD =
               llvm::dyn_cast<clang::CXXRecordDecl>(const_cast<clang::RecordDecl *>(selClass.GetRecordDecl()))) {
         AnnotateDecl(*CXXRD, declSelRulesMap, interp, false);
      }
   }
}

////////////////////////////////////////////////////////////////////////////////

int CheckClassesForInterpreterOnlyDicts(cling::Interpreter &interp,
                                        RScanner &scan)
{
   for (auto const & selClass : scan.fSelectedClasses) {
      if (!selClass.GetRecordDecl()->isCompleteDefinition() || selClass.RequestOnlyTClass()) {
         continue;
      }
      const clang::CXXRecordDecl *cxxdecl = llvm::dyn_cast<clang::CXXRecordDecl>(selClass.GetRecordDecl());
      if (cxxdecl && ROOT::TMetaUtils::ClassInfo__HasMethod(selClass, "Class_Name", interp)) {
         ROOT::TMetaUtils::Error("CheckClassesForInterpreterOnlyDicts",
                                 "Interactivity only dictionaries are not supported for classes with ClassDef\n");
         return 1;
      }
   }
   return 0;
}

////////////////////////////////////////////////////////////////////////////////
/// Make up for skipping RegisterModule, now that dictionary parsing
/// is done and these headers cannot be selected anymore.

int FinalizeStreamerInfoWriting(cling::Interpreter &interp, bool writeEmptyRootPCM=false)
{
   if (!gDriverConfig->fCloseStreamerInfoROOTFile)
      return 0;

   interp.parseForModule("#include \"TStreamerInfo.h\"\n"
                           "#include \"TFile.h\"\n"
                           "#include \"TObjArray.h\"\n"
                           "#include \"TVirtualArray.h\"\n"
                           "#include \"TStreamerElement.h\"\n"
                           "#include \"TProtoClass.h\"\n"
                           "#include \"TBaseClass.h\"\n"
                           "#include \"TListOfDataMembers.h\"\n"
                           "#include \"TListOfEnums.h\"\n"
                           "#include \"TListOfEnumsWithLock.h\"\n"
                           "#include \"TDataMember.h\"\n"
                           "#include \"TEnum.h\"\n"
                           "#include \"TEnumConstant.h\"\n"
                           "#include \"TDictAttributeMap.h\"\n"
                           "#include \"TMessageHandler.h\"\n"
                           "#include \"TArray.h\"\n"
                           "#include \"TRefArray.h\"\n"
                           "#include \"root_std_complex.h\"\n");
   if (!gDriverConfig->fCloseStreamerInfoROOTFile(writeEmptyRootPCM)) {
      return 1;
   }
   return 0;
}

////////////////////////////////////////////////////////////////////////////////

int GenerateFullDict(std::ostream &dictStream,
                     cling::Interpreter &interp,
                     RScanner &scan,
                     const ROOT::TMetaUtils::RConstructorTypes &ctorTypes,
                     bool isSplit,
                     bool isGenreflex,
                     bool writeEmptyRootPCM)
{
   ROOT::TMetaUtils::TNormalizedCtxt normCtxt(interp.getLookupHelper());

   bool needsCollectionProxy = false;

   //
   // We will loop over all the classes several times.
   // In order we will call
   //
   //     WriteClassInit (code to create the TGenericClassInfo)
   //     check for constructor and operator input
   //     WriteClassFunctions (declared in ClassDef)
   //     WriteClassCode (Streamer,ShowMembers,Auxiliary functions)
   //


   //
   // Loop over all classes and create Streamer() & Showmembers() methods
   //

   // SELECTION LOOP
   for (auto const & ns : scan.fSelectedNamespaces) {
      WriteNamespaceInit(ns, interp, dictStream);
      auto nsName = ns.GetNamespaceDecl()->getQualifiedNameAsString();
      if (nsName.find("(anonymous)") == std::string::npos)
         EmitStreamerInfo(nsName.c_str());
   }

   for (auto const & selClass : scan.fSelectedClasses) {
      if (!selClass.GetRecordDecl()->isCompleteDefinition()) {
         ROOT::TMetaUtils::Error(0, "A dictionary has been requested for %s but there is no declaration!\n", ROOT::TMetaUtils::GetQualifiedName(selClass).c_str());
         continue;
      }
      if (selClass.RequestOnlyTClass()) {
         // fprintf(stderr,"rootcling: Skipping class %s\n",R__GetQualifiedName(* selClass.GetRecordDecl()).c_str());
         // For now delay those for later.
         continue;
      }

      // Very important: here we decide if we want to attach attributes to the decl.

      if (clang::CXXRecordDecl *CXXRD =
               llvm::dyn_cast<clang::CXXRecordDecl>(const_cast<clang::RecordDecl *>(selClass.GetRecordDecl()))) {
         AnnotateDecl(*CXXRD, scan.GetDeclsSelRulesMap() , interp, isGenreflex);
      }

      const clang::CXXRecordDecl *CRD = llvm::dyn_cast<clang::CXXRecordDecl>(selClass.GetRecordDecl());

      if (CRD) {
         ROOT::TMetaUtils::Info(0, "Generating code for class %s\n", selClass.GetNormalizedName());
         if (TMetaUtils::IsStdClass(*CRD) && 0 != TClassEdit::STLKind(CRD->getName().str().c_str() /* unqualified name without template arguement */)) {
            // Register the collections
            // coverity[fun_call_w_exception] - that's just fine.
            Internal::RStl::Instance().GenerateTClassFor(selClass.GetNormalizedName(), CRD, interp, normCtxt);
         } else {
            ROOT::TMetaUtils::WriteClassInit(dictStream, selClass, CRD, interp, normCtxt, ctorTypes, needsCollectionProxy);
            EmitStreamerInfo(selClass.GetNormalizedName());
         }
      }
   }

   //
   // Write all TBuffer &operator>>(...), Class_Name(), Dictionary(), etc.
   // first to allow template specialisation to occur before template
   // instantiation (STK)
   //
   // SELECTION LOOP
   for (auto const & selClass : scan.fSelectedClasses) {

      if (!selClass.GetRecordDecl()->isCompleteDefinition() || selClass.RequestOnlyTClass()) {
         // For now delay those for later.
         continue;
      }
      const clang::CXXRecordDecl *cxxdecl = llvm::dyn_cast<clang::CXXRecordDecl>(selClass.GetRecordDecl());
      if (cxxdecl && ROOT::TMetaUtils::ClassInfo__HasMethod(selClass, "Class_Name", interp)) {
         WriteClassFunctions(cxxdecl, dictStream, isSplit);
      }
   }

   // LINKDEF SELECTION LOOP
   // Loop to get the shadow class for the class marked 'RequestOnlyTClass' (but not the
   // STL class which is done via Internal::RStl::Instance().WriteClassInit(0);
   // and the ClassInit

   for (auto const & selClass : scan.fSelectedClasses) {
      if (!selClass.GetRecordDecl()->isCompleteDefinition() || !selClass.RequestOnlyTClass()) {
         continue;
      }

      const clang::CXXRecordDecl *CRD = llvm::dyn_cast<clang::CXXRecordDecl>(selClass.GetRecordDecl());

      if (!ROOT::TMetaUtils::IsSTLContainer(selClass)) {
         ROOT::TMetaUtils::WriteClassInit(dictStream, selClass, CRD, interp, normCtxt, ctorTypes, needsCollectionProxy);
         EmitStreamerInfo(selClass.GetNormalizedName());
      }
   }
   // Loop to write all the ClassCode
   for (auto const & selClass : scan.fSelectedClasses) {
      ROOT::TMetaUtils::WriteClassCode(&CallWriteStreamer,
                                       selClass,
                                       interp,
                                       normCtxt,
                                       dictStream,
                                       ctorTypes,
                                       isGenreflex);
   }

   // Loop on the registered collections internally
   // coverity[fun_call_w_exception] - that's just fine.
   ROOT::Internal::RStl::Instance().WriteClassInit(dictStream, interp, normCtxt, ctorTypes, needsCollectionProxy, EmitStreamerInfo);

   if (!gDriverConfig->fBuildingROOTStage1) {
      EmitTypedefs(scan.fSelectedTypedefs);
      EmitEnums(scan.fSelectedEnums);
      // Make up for skipping RegisterModule, now that dictionary parsing
      // is done and these headers cannot be selected anymore.
      int finRetCode = FinalizeStreamerInfoWriting(interp, writeEmptyRootPCM);
      if (finRetCode != 0) return finRetCode;
   }

   return 0;
}

////////////////////////////////////////////////////////////////////////////////

void CreateDictHeader(std::ostream &dictStream, const std::string &main_dictname)
{
   dictStream  << "// Do NOT change. Changes will be lost next time file is generated\n\n"
               << "#define R__DICTIONARY_FILENAME " << main_dictname << std::endl

               // Now that CINT is not longer there to write the header file,
               // write one and include in there a few things for backward
               // compatibility.
               << "\n/*******************************************************************/\n"
               << "#include <stddef.h>\n"
               << "#include <stdio.h>\n"
               << "#include <stdlib.h>\n"
               << "#include <string.h>\n"
               << "#include <assert.h>\n"
               << "#define G__DICTIONARY\n"
               << "#include \"RConfig.h\"\n"
               << "#include \"TClass.h\"\n"
               << "#include \"TDictAttributeMap.h\"\n"
               << "#include \"TInterpreter.h\"\n"
               << "#include \"TROOT.h\"\n"
               << "#include \"TBuffer.h\"\n"
               << "#include \"TMemberInspector.h\"\n"
               << "#include \"TInterpreter.h\"\n"
               << "#include \"TVirtualMutex.h\"\n"
               << "#include \"TError.h\"\n\n"
               << "#ifndef G__ROOT\n"
               << "#define G__ROOT\n"
               << "#endif\n\n"
               << "#include \"RtypesImp.h\"\n"
               << "#include \"TIsAProxy.h\"\n"
               << "#include \"TFileMergeInfo.h\"\n"
               << "#include <algorithm>\n"
               << "#include \"TCollectionProxyInfo.h\"\n"
               << "/*******************************************************************/\n\n"
               << "#include \"TDataMember.h\"\n\n"; // To set their transiency
#ifndef R__SOLARIS
   dictStream  << "// Since CINT ignores the std namespace, we need to do so in this file.\n"
               << "namespace std {} using namespace std;\n\n";
#endif
}

////////////////////////////////////////////////////////////////////////////////

void GenerateNecessaryIncludes(std::ostream &dictStream,
                               const std::string &includeForSource,
                               const std::string &extraIncludes)
{
   dictStream << "// Header files passed as explicit arguments\n"
              << includeForSource << std::endl
              << "// Header files passed via #pragma extra_include\n"
              << extraIncludes << std::endl;
}

//______________________________________________________________________________

// cross-compiling for iOS and iOS simulator (assumes host is Intel Mac OS X)
#if defined(R__IOSSIM) || defined(R__IOS)
#ifdef __x86_64__
#undef __x86_64__
#endif
#ifdef __i386__
#undef __i386__
#endif
#ifdef R__IOSSIM
#define __i386__ 1
#endif
#ifdef R__IOS
#define __arm__ 1
#endif
#endif

////////////////////////////////////////////////////////////////////////////////
/// Little helper class to bookkeep the files names which we want to make
/// temporary.

class tempFileNamesCatalog {
public:
   //______________________________________________
   tempFileNamesCatalog(): m_size(0), m_emptyString("") {};

   std::string getTmpFileName(const std::string &filename) {
      return filename + "_tmp_" + std::to_string(getpid());
   }
   /////////////////////////////////////////////////////////////////////////////
   /// Adds the name and the associated temp name to the catalog.
   /// Changes the name into the temp name

   void addFileName(std::string &nameStr) {
      if (nameStr.empty()) return;

      std::string tmpNameStr(getTmpFileName(nameStr));

      // For brevity
      const char *name(nameStr.c_str());
      const char *tmpName(tmpNameStr.c_str());

      m_names.push_back(nameStr);
      m_tempNames.push_back(tmpNameStr);
      ROOT::TMetaUtils::Info(0, "File %s added to the tmp catalog.\n", name);

      // This is to allow update of existing files
      if (0 == std::rename(name , tmpName)) {
         ROOT::TMetaUtils::Info(0, "File %s existing. Preserved as %s.\n", name, tmpName);
      }

      // To change the name to its tmp version
      nameStr = tmpNameStr;

      m_size++;

   }

   /////////////////////////////////////////////////////////////////////////////

   int clean() {
      int retval = 0;
      // rename the temp files into the normal ones
      for (unsigned int i = 0; i < m_size; ++i) {
         const char *tmpName = m_tempNames[i].c_str();
         // Check if the file exists
         std::ifstream ifile(tmpName);
         if (!ifile)
            ROOT::TMetaUtils::Error(0, "Cannot find %s!\n", tmpName);

         if (0 != std::remove(tmpName)) {
            ROOT::TMetaUtils::Error(0, "Removing %s!\n", tmpName);
            retval++;
         }
      }
      return retval;
   }

   /////////////////////////////////////////////////////////////////////////////

   int commit() {
      int retval = 0;
      // rename the temp files into the normal ones
      for (unsigned int i = 0; i < m_size; ++i) {
         const char *tmpName = m_tempNames[i].c_str();
         const char *name = m_names[i].c_str();
         // Check if the file exists
         std::ifstream ifile(tmpName);
         if (!ifile)
            ROOT::TMetaUtils::Error(0, "Cannot find %s!\n", tmpName);
#ifdef WIN32
         // Sometimes files cannot be renamed on Windows if they don't have
         // been released by the system. So just copy them and try to delete
         // the old one afterwards.
         if (ifile.is_open())
            ifile.close();
         if (0 != std::rename(tmpName , name)) {
            if (llvm::sys::fs::copy_file(tmpName , name)) {
               llvm::sys::fs::remove(tmpName);
            }
         }
#else
         if (0 != std::rename(tmpName , name)) {
            ROOT::TMetaUtils::Error(0, "Renaming %s into %s!\n", tmpName, name);
            retval++;
         }
#endif
      }
      return retval;
   }

   /////////////////////////////////////////////////////////////////////////////

   const std::string &getFileName(const std::string &tmpFileName) {
      size_t i = std::distance(m_tempNames.begin(),
                               find(m_tempNames.begin(), m_tempNames.end(), tmpFileName));
      if (i == m_tempNames.size()) return m_emptyString;
      return m_names[i];
   }

   /////////////////////////////////////////////////////////////////////////////

   void dump() {
      std::cout << "Restoring files in temporary file catalog:\n";
      for (unsigned int i = 0; i < m_size; ++i) {
         std::cout <<  m_tempNames[i] << " --> " << m_names[i] << std::endl;
      }
   }

private:
   unsigned int m_size;
   const std::string m_emptyString;
   std::vector<std::string> m_names;
   std::vector<std::string> m_tempNames;
};

////////////////////////////////////////////////////////////////////////////////
/// Transform name of dictionary

std::ostream *CreateStreamPtrForSplitDict(const std::string &dictpathname,
      tempFileNamesCatalog &tmpCatalog)
{
   std::string splitDictName(tmpCatalog.getFileName(dictpathname));
   const size_t dotPos = splitDictName.find_last_of(".");
   splitDictName.insert(dotPos, "_classdef");
   tmpCatalog.addFileName(splitDictName);
   return new std::ofstream(splitDictName.c_str());
}

////////////////////////////////////////////////////////////////////////////////
/// Transform -W statements in diagnostic pragmas for cling reacting on "-Wno-"
/// For example
/// -Wno-deprecated-declarations --> #pragma clang diagnostic ignored "-Wdeprecated-declarations"

void CheckForMinusW(const char *arg,
                    std::list<std::string> &diagnosticPragmas)
{
   static const std::string pattern("-Wno-");

   std::string localArg(arg);
   if (localArg.find(pattern) != 0) return;
   if (localArg == "-Wno-noexcept-type") {
      // GCC7 warning not supported by clang 3.9
      return;
   }

   ROOT::TMetaUtils::ReplaceAll(localArg, pattern, "#pragma clang diagnostic ignored \"-W");
   localArg += "\"";
   diagnosticPragmas.push_back(localArg);
}

////////////////////////////////////////////////////////////////////////////////

std::string GetFwdDeclnArgsToKeepString(const ROOT::TMetaUtils::TNormalizedCtxt &normCtxt,
                                        cling::Interpreter &interp)
{
   using namespace ROOT::TMetaUtils::AST2SourceTools;
   std::string fwdDecl;
   std::string initStr("{");
   auto &fwdDeclnArgsToSkipColl = normCtxt.GetTemplNargsToKeepMap();
   for (auto & strigNargsToKeepPair : fwdDeclnArgsToSkipColl) {
      auto &clTemplDecl = *strigNargsToKeepPair.first;
      FwdDeclFromTmplDecl(clTemplDecl , interp, fwdDecl);
      initStr += "{\"" +
                 fwdDecl + "\", "
                 + std::to_string(strigNargsToKeepPair.second)
                 + "},";
   }
   if (!fwdDeclnArgsToSkipColl.empty())
      initStr.pop_back();
   initStr += "}";
   return initStr;
}

////////////////////////////////////////////////////////////////////////////////
/// Get the pointee type if possible

clang::QualType GetPointeeTypeIfPossible(const clang::QualType &qt)
{
   if (qt.isNull()) return qt;
   clang::QualType thisQt(qt);
   while (thisQt->isPointerType() ||
          thisQt->isReferenceType()) {
      thisQt = thisQt->getPointeeType();
   }
   return thisQt;

}

////////////////////////////////////////////////////////////////////////////////
/// Extract the list of headers necessary for the Decl

std::list<std::string> RecordDecl2Headers(const clang::CXXRecordDecl &rcd,
      const cling::Interpreter &interp,
      std::set<const clang::CXXRecordDecl *> &visitedDecls)
{
   std::list<std::string> headers;

   // Avoid infinite recursion
   if (!visitedDecls.insert(rcd.getCanonicalDecl()).second)
      return headers;

   // If this is a template
   if (const clang::ClassTemplateSpecializationDecl *tsd = llvm::dyn_cast<clang::ClassTemplateSpecializationDecl>(&rcd)) {

      // Loop on the template args
      for (auto & tArg : tsd->getTemplateArgs().asArray()) {
         if (clang::TemplateArgument::ArgKind::Type != tArg.getKind()) continue;
         auto tArgQualType = GetPointeeTypeIfPossible(tArg.getAsType());
         if (tArgQualType.isNull()) continue;
         if (const clang::CXXRecordDecl *tArgCxxRcd = tArgQualType->getAsCXXRecordDecl()) {
            headers.splice(headers.end(), RecordDecl2Headers(*tArgCxxRcd, interp, visitedDecls));
         }
      }

      if (!ROOT::TMetaUtils::IsStdClass(rcd) && rcd.hasDefinition()) {

         // Loop on base classes - with a newer llvm, range based possible
         for (auto baseIt = tsd->bases_begin(); baseIt != tsd->bases_end(); baseIt++) {
            auto baseQualType = GetPointeeTypeIfPossible(baseIt->getType());
            if (baseQualType.isNull()) continue;
            if (const clang::CXXRecordDecl *baseRcdPtr = baseQualType->getAsCXXRecordDecl()) {
               headers.splice(headers.end(), RecordDecl2Headers(*baseRcdPtr, interp, visitedDecls));
            }
         }

         // Loop on the data members - with a newer llvm, range based possible
         for (auto declIt = tsd->decls_begin(); declIt != tsd->decls_end(); ++declIt) {
            if (const clang::FieldDecl *fieldDecl = llvm::dyn_cast<clang::FieldDecl>(*declIt)) {
               auto fieldQualType = GetPointeeTypeIfPossible(fieldDecl->getType());
               if (fieldQualType.isNull()) continue ;
               if (const clang::CXXRecordDecl *fieldCxxRcd = fieldQualType->getAsCXXRecordDecl()) {
                  if (fieldCxxRcd->hasDefinition())
                     headers.splice(headers.end(), RecordDecl2Headers(*fieldCxxRcd, interp, visitedDecls));
               }
            }
         }

         // Loop on methods
         for (auto methodIt = tsd->method_begin(); methodIt != tsd->method_end(); ++methodIt) {
            // Check arguments
            for (auto & fPar : methodIt->parameters()) {
               auto fParQualType = GetPointeeTypeIfPossible(fPar->getOriginalType());
               if (fParQualType.isNull()) continue;
               if (const clang::CXXRecordDecl *fParCxxRcd = fParQualType->getAsCXXRecordDecl()) {
                  if (fParCxxRcd->hasDefinition())
                     headers.splice(headers.end(), RecordDecl2Headers(*fParCxxRcd, interp, visitedDecls));
               }
            }
            // Check return value
            auto retQualType = GetPointeeTypeIfPossible(methodIt->getReturnType());
            if (retQualType.isNull()) continue;
            if (const clang::CXXRecordDecl *retCxxRcd = retQualType->getAsCXXRecordDecl()) {
               if (retCxxRcd->hasDefinition())
                  headers.splice(headers.end(), RecordDecl2Headers(*retCxxRcd, interp, visitedDecls));
            }
         }
      }

   } // End template instance

   std::string header = ROOT::TMetaUtils::GetFileName(rcd, interp);
   headers.emplace_back(header);
   headers.reverse();
   return headers;

}

////////////////////////////////////////////////////////////////////////////////
/// Check if the class good for being an autoparse key.
/// We exclude from this set stl containers of pods/strings
/// TODO: we may use also __gnu_cxx::
bool IsGoodForAutoParseMap(const clang::RecordDecl& rcd){

   // If it's not an std class, we just pick it up.
   if (auto dclCtxt= rcd.getDeclContext()){
      if (! dclCtxt->isStdNamespace()){
         return true;
      }
   } else {
      return true;
   }

   // Now, we have a stl class. We now check if it's a template. If not, we
   // do not take it: bitset, string and so on.
   auto clAsTmplSpecDecl = llvm::dyn_cast<clang::ClassTemplateSpecializationDecl>(&rcd);
   if (!clAsTmplSpecDecl) return false;

   // Now we have a template in the stl. Let's see what the arguments are.
   // If they are not a POD or something which is good for autoparsing, we keep
   // them.
   auto& astCtxt = rcd.getASTContext();
   auto& templInstArgs = clAsTmplSpecDecl->getTemplateInstantiationArgs();
   for (auto&& arg : templInstArgs.asArray()){

      auto argKind = arg.getKind();
      if (argKind != clang::TemplateArgument::Type){
         if (argKind == clang::TemplateArgument::Integral) continue;
         else return true;
      }

      auto argQualType = arg.getAsType();
      auto isPOD = argQualType.isPODType(astCtxt);
      // This is a POD, we can inspect the next arg
      if (isPOD) continue;

      auto argType = argQualType.getTypePtr();
      if (auto recType = llvm::dyn_cast<clang::RecordType>(argType)){
         auto isArgGoodForAutoParseMap = IsGoodForAutoParseMap(*recType->getDecl());
         // The arg is a class but good for the map
         if (isArgGoodForAutoParseMap) continue;
      } else {
         // The class is not a POD nor a class we can skip
         return true;
      }
   }

   return false;
}

////////////////////////////////////////////////////////////////////////////////

void ExtractHeadersForDecls(const RScanner::ClassColl_t &annotatedRcds,
                            const RScanner::TypedefColl_t tDefDecls,
                            const RScanner::FunctionColl_t funcDecls,
                            const RScanner::VariableColl_t varDecls,
                            const RScanner::EnumColl_t enumDecls,
                            HeadersDeclsMap_t &headersClassesMap,
                            HeadersDeclsMap_t &headersDeclsMap,
                            const cling::Interpreter &interp)
{
   std::set<const clang::CXXRecordDecl *> visitedDecls;
   std::unordered_set<std::string> buffer;
   std::string autoParseKey;

   // Add some manip of headers
   for (auto & annotatedRcd : annotatedRcds) {
      if (const clang::CXXRecordDecl *cxxRcd =
               llvm::dyn_cast_or_null<clang::CXXRecordDecl>(annotatedRcd.GetRecordDecl())) {
         autoParseKey = "";
         visitedDecls.clear();
         std::list<std::string> headers(RecordDecl2Headers(*cxxRcd, interp, visitedDecls));
         // remove duplicates, also if not subsequent
         buffer.clear();
         headers.remove_if([&buffer](const std::string & s) {
            return !buffer.insert(s).second;
         });
         GetMostExternalEnclosingClassName(*cxxRcd, autoParseKey, interp);
         if (autoParseKey.empty()) autoParseKey = annotatedRcd.GetNormalizedName();
         if (IsGoodForAutoParseMap(*cxxRcd)){
            headersDeclsMap[autoParseKey] = headers;
            headersDeclsMap[annotatedRcd.GetRequestedName()] = headers;
         } else {
            ROOT::TMetaUtils::Info(0, "Class %s is not included in the set of autoparse keys.\n", autoParseKey.c_str());
         }

         // Propagate to the classes map only if this is not a template.
         // The header is then used as autoload key and we want to avoid duplicates.
         if (!llvm::isa<clang::ClassTemplateSpecializationDecl>(cxxRcd)){
            headersClassesMap[autoParseKey] = headersDeclsMap[autoParseKey];
            headersClassesMap[annotatedRcd.GetRequestedName()] = headersDeclsMap[annotatedRcd.GetRequestedName()];
         }
      }
   }

   // The same for the typedefs:
   for (auto & tDef : tDefDecls) {
      if (clang::CXXRecordDecl *cxxRcd = tDef->getUnderlyingType()->getAsCXXRecordDecl()) {
         autoParseKey = "";
         visitedDecls.clear();
         std::list<std::string> headers(RecordDecl2Headers(*cxxRcd, interp, visitedDecls));
         headers.push_back(ROOT::TMetaUtils::GetFileName(*tDef, interp));
         // remove duplicates, also if not subsequent
         buffer.clear();
         headers.remove_if([&buffer](const std::string & s) {
            return !buffer.insert(s).second;
         });
         GetMostExternalEnclosingClassNameFromDecl(*tDef, autoParseKey, interp);
         if (autoParseKey.empty()) autoParseKey = tDef->getQualifiedNameAsString();
         headersDeclsMap[autoParseKey] = headers;
      }
   }

   // The same for the functions:
   for (auto & func : funcDecls) {
      std::list<std::string> headers = {ROOT::TMetaUtils::GetFileName(*func, interp)};
      headersDeclsMap[ROOT::TMetaUtils::GetQualifiedName(*func)] = headers;
   }

   // The same for the variables:
   for (auto & var : varDecls) {
      std::list<std::string> headers = {ROOT::TMetaUtils::GetFileName(*var, interp)};
      headersDeclsMap[ROOT::TMetaUtils::GetQualifiedName(*var)] = headers;
   }

   // The same for the enums:
   for (auto & en : enumDecls) {
      std::list<std::string> headers = {ROOT::TMetaUtils::GetFileName(*en, interp)};
      headersDeclsMap[ROOT::TMetaUtils::GetQualifiedName(*en)] = headers;
   }
}

////////////////////////////////////////////////////////////////////////////////
/// Generate the fwd declarations of the selected entities

std::string GenerateFwdDeclString(const RScanner &scan,
                                  const cling::Interpreter &interp)
{
   std::string newFwdDeclString;

   using namespace ROOT::TMetaUtils::AST2SourceTools;

   std::string fwdDeclString;
   std::string buffer;
   std::unordered_set<std::string> fwdDecls;

   // Classes
/*
   for (auto const & annRcd : scan.fSelectedClasses) {
      const auto rcdDeclPtr = annRcd.GetRecordDecl();

      int retCode = FwdDeclFromRcdDecl(*rcdDeclPtr, interp, buffer);
      if (-1 == retCode) {
         ROOT::TMetaUtils::Error("GenerateFwdDeclString",
                                 "Error generating fwd decl for class %s\n",
                                 annRcd.GetNormalizedName());
         return emptyString;
      }
      if (retCode == 0 && fwdDecls.insert(buffer).second)
         fwdDeclString += "\"" + buffer + "\"\n";
   }
*/
   // Build the input for a transaction containing all of the selected declarations
   // Cling will produce the fwd declaration payload.

   std::vector<const clang::Decl *> selectedDecls(scan.fSelectedClasses.size());

   // Pick only RecordDecls
   std::transform (scan.fSelectedClasses.begin(),
                   scan.fSelectedClasses.end(),
                   selectedDecls.begin(),
                   [](const ROOT::TMetaUtils::AnnotatedRecordDecl& rcd){return rcd.GetRecordDecl();});

   for (auto* TD: scan.fSelectedTypedefs)
      selectedDecls.push_back(TD);

//    for (auto* VAR: scan.fSelectedVariables)
//       selectedDecls.push_back(VAR);

   // The "R\"DICTFWDDCLS(\n" ")DICTFWDDCLS\"" pieces have been moved to
   // TModuleGenerator to be able to make the diagnostics more telling in presence
   // of an issue ROOT-6752.
   fwdDeclString += Decls2FwdDecls(selectedDecls,IsLinkdefFile,interp);

   // Functions
//    for (auto const& fcnDeclPtr : scan.fSelectedFunctions){
//       int retCode = FwdDeclFromFcnDecl(*fcnDeclPtr, interp, buffer);
//       newFwdDeclString += Decl2FwdDecl(*fcnDeclPtr,interp);
//       if (-1 == retCode){
//          ROOT::TMetaUtils::Error("GenerateFwdDeclString",
//                                  "Error generating fwd decl for function  %s\n",
//                                  fcnDeclPtr->getNameAsString().c_str());
//          return emptyString;
//       }
//       if (retCode == 0 && fwdDecls.insert(buffer).second)
//          fwdDeclString+="\""+buffer+"\"\n";
//    }

   if (fwdDeclString.empty()) fwdDeclString = "";
   return fwdDeclString;
}

////////////////////////////////////////////////////////////////////////////////
/// Generate a string for the dictionary from the headers-classes map.

const std::string GenerateStringFromHeadersForClasses(const HeadersDeclsMap_t &headersClassesMap,
      const std::string &detectedUmbrella,
      bool payLoadOnly = false)
{
   std::string headerName;

   if (genreflex::verbose)
      std::cout << "Class-headers Mapping:\n";
   std::string headersClassesMapString = "static const char* classesHeaders[]={\n";
   for (auto const & classHeaders : headersClassesMap) {
      if (genreflex::verbose)
         std::cout << " o " << classHeaders.first << " --> ";
      headersClassesMapString += "\"";
      headersClassesMapString += classHeaders.first + "\"";
      for (auto const & header : classHeaders.second) {
         headerName = (detectedUmbrella == header || payLoadOnly) ? "payloadCode" : "\"" + header + "\"";
         headersClassesMapString += ", " + headerName;
         if (genreflex::verbose)
            std::cout << ", " << headerName;
         if (payLoadOnly)
            break;
      }
      if (genreflex::verbose)
         std::cout << std::endl;
      headersClassesMapString += ", \"@\",\n";
   }
   headersClassesMapString += "nullptr};\n";
   return headersClassesMapString;
}

////////////////////////////////////////////////////////////////////////////////

bool IsImplementationName(const std::string &filename)
{
   return !ROOT::TMetaUtils::IsHeaderName(filename);
}

////////////////////////////////////////////////////////////////////////////////
/// Returns >0 if argument is to be ignored.
/// If 1, just skip that argument. If 2, that argument takes a parameter
/// "-arg param" thus skip both.

int ShouldIgnoreClingArgument(const std::string& argument)
{
   if (argument == "-pipe") return 1;
   if (argument == "-fPIC") return 1;
   if (argument == "-fpic") return 1;
   if (ROOT::TMetaUtils::BeginsWith(argument, "--gcc-toolchain="))
      return 1;

   return 0;
}

////////////////////////////////////////////////////////////////////////////////
/// Check if the argument is a sane cling argument. Performing the following checks:
/// 1) It does not start with "--" and is not the --param option.

bool IsCorrectClingArgument(const std::string& argument)
{
   if (ROOT::TMetaUtils::BeginsWith(argument,"--") && !ROOT::TMetaUtils::BeginsWith(argument,"--param")) return false;
   return true;
}

////////////////////////////////////////////////////////////////////////////////
bool NeedsSelection(const char* name)
{
   static const std::vector<std::string> namePrfxes {
      "array<",
      "unique_ptr<"};
   auto pos = find_if(namePrfxes.begin(),
                      namePrfxes.end(),
                      [&](const std::string& str){return ROOT::TMetaUtils::BeginsWith(name,str);});
   return namePrfxes.end() == pos;
}

////////////////////////////////////////////////////////////////////////////////

bool IsSupportedClassName(const char* name)
{
   static const std::vector<std::string> uclNamePrfxes {
      "chrono:",
      "ratio<",
      "shared_ptr<"};
   static const std::set<std::string> unsupportedClassesNormNames{
      "regex",
      "thread"};
   if ( unsupportedClassesNormNames.count(name) == 1) return false;
   auto pos = find_if(uclNamePrfxes.begin(),
                      uclNamePrfxes.end(),
                      [&](const std::string& str){return ROOT::TMetaUtils::BeginsWith(name,str);});
   return uclNamePrfxes.end() == pos;
}

////////////////////////////////////////////////////////////////////////////////
/// Check if the list of selected classes contains any class which is not
/// supported. Return the number of unsupported classes in the selection.

int CheckForUnsupportedClasses(const RScanner::ClassColl_t &annotatedRcds)
{
   int nerrors = 0;
   for (auto&& aRcd : annotatedRcds){
      auto clName = aRcd.GetNormalizedName();
      if (!IsSupportedClassName(clName)){
         std::cerr << "Error: Class " << clName << " has been selected but "
               << "currently the support for its I/O is not yet available. Note that "
               << clName << ", even if not selected, will be available for "
               << "interpreted code.\n";
         nerrors++;
      }
      if (!NeedsSelection(clName)){
         std::cerr << "Error: It is not necessary to explicitly select class "
                   << clName << ". I/O is supported for it transparently.\n";
         nerrors++;
      }
   }
   return nerrors;
}

////////////////////////////////////////////////////////////////////////////////

class TRootClingCallbacks : public cling::InterpreterCallbacks {
private:
    std::list<std::string>& fFilesIncludedByLinkdef;
    bool isLocked = false;
public:
    TRootClingCallbacks(cling::Interpreter* interp, std::list<std::string>& filesIncludedByLinkdef):
      InterpreterCallbacks(interp),
      fFilesIncludedByLinkdef(filesIncludedByLinkdef){};

   ~TRootClingCallbacks(){};

   virtual void InclusionDirective(clang::SourceLocation /*HashLoc*/,
                                   const clang::Token &/*IncludeTok*/,
                                   llvm::StringRef FileName,
                                   bool IsAngled,
                                   clang::CharSourceRange /*FilenameRange*/,
                                   const clang::FileEntry */*File*/,
                                   llvm::StringRef /*SearchPath*/,
                                   llvm::StringRef /*RelativePath*/,
                                   const clang::Module */*Imported*/) {
      if (isLocked) return;
      if (IsAngled) return;
      auto& PP = m_Interpreter->getCI()->getPreprocessor();
      auto curLexer = PP.getCurrentFileLexer();
      if (!curLexer) return;
      auto fileEntry = curLexer->getFileEntry();
      if (!fileEntry) return;
      auto thisFileName = fileEntry->getName();
      auto fileNameAsString = FileName.str();
      auto isThisLinkdef = ROOT::TMetaUtils::IsLinkdefFile(thisFileName.data());
      if (isThisLinkdef) {
         auto isTheIncludedLinkdef = ROOT::TMetaUtils::IsLinkdefFile(fileNameAsString.c_str());
         if (isTheIncludedLinkdef) {
            fFilesIncludedByLinkdef.clear();
            isLocked = true;
         } else {
            fFilesIncludedByLinkdef.emplace_back(fileNameAsString.c_str());
         }
      }
   }
};



////////////////////////////////////////////////////////////////////////////////

int RootClingMain(int argc,
              char **argv,
              bool isDeep = false,
              bool isGenreflex = false)
{
   if (argc < 2) {
      fprintf(stderr,
              shortHelp,
              argv[0]);
      fprintf(stderr, "For more extensive help type: %s -h\n", argv[0]);
      return 1;
   }

   std::string dictname;
   std::string dictpathname;
   int ic, force = 0, onepcm = 0;
   bool ignoreExistingDict = false;
   bool requestAllSymbols = isDeep;

   std::string currentDirectory;
   GetCurrentDirectory(currentDirectory);

   ic = 1;
   if (!gDriverConfig->fBuildingROOTStage1) {
      if (strcmp("-rootbuild", argv[ic]) == 0) {
         // running rootcling for ROOT itself.
         gBuildingROOT = true;
         ic++;
      }
   }
   if (!strcmp(argv[ic], "-v")) {
      ROOT::TMetaUtils::GetErrorIgnoreLevel() = ROOT::TMetaUtils::kError; // The default is kError
      ic++;
   } else if (!strcmp(argv[ic], "-v0")) {
      ROOT::TMetaUtils::GetErrorIgnoreLevel() = ROOT::TMetaUtils::kFatal; // Explicitly remove all messages
      ic++;
   } else if (!strcmp(argv[ic], "-v1")) {
      ROOT::TMetaUtils::GetErrorIgnoreLevel() = ROOT::TMetaUtils::kError; // Only error message (default)
      ic++;
   } else if (!strcmp(argv[ic], "-v2")) {
      ROOT::TMetaUtils::GetErrorIgnoreLevel() = ROOT::TMetaUtils::kWarning; // error and warning message
      ic++;
   } else if (!strcmp(argv[ic], "-v3")) {
      ROOT::TMetaUtils::GetErrorIgnoreLevel() = ROOT::TMetaUtils::kNote; // error, warning and note
      ic++;
   } else if (!strcmp(argv[ic], "-v4")) {
      ROOT::TMetaUtils::GetErrorIgnoreLevel() = ROOT::TMetaUtils::kInfo; // Display all information (same as -v)
      genreflex::verbose = true;
      ic++;
   }
   if (ic < argc) {
      if (!strcmp(argv[ic], "-cint")) {
         // Flag is ignored, should warn of deprecation.
         ic++;
      } else if (!strcmp(argv[ic], "-reflex")) {
         // Flag is ignored, should warn of deprecation.
         ic++;
      } else if (!strcmp(argv[ic], "-gccxml")) {
         // Flag is ignored, should warn of deprecation.
         ic++;
      }
   }

   const char *libprefixOption = "--lib-list-prefix=";
   std::string liblistPrefix;

   while (ic < argc && strncmp(argv[ic], "-", 1) == 0
          && strcmp(argv[ic], "-f") != 0  && strcmp(argv[ic], "-r") != 0)  {
      if (!strcmp(argv[ic], "-l")) {
         ic++;
      } else if (!strcmp(argv[ic], "-1")) {
         onepcm = 1;
         ic++;
      } else if (!strncmp(argv[ic], libprefixOption, strlen(libprefixOption))) {

         liblistPrefix = argv[ic] + strlen(libprefixOption);

         string filein = liblistPrefix + ".in";
         FILE *fp;
         if ((fp = fopen(filein.c_str(), "r")) == 0) {
            ROOT::TMetaUtils::Error(0, "%s: The input list file %s does not exist\n", argv[0], filein.c_str());
            return 1;
         }
         fclose(fp);

         ic++;
      } else {
         break;
      }
   }

   if (ic < argc && !strcmp(argv[ic], "-f")) {
      force = 1;
      ic++;
   } else if (ic < argc && !strcmp(argv[ic], "-r")) {
      ignoreExistingDict = true;
      ic++;
   } else if (argc > 1 && (!strcmp(argv[1], "-?") || !strcmp(argv[1], "-h"))) {
      fprintf(stderr, "%s\n", rootClingHelp);
      return 1;
   } else if (ic < argc && !strncmp(argv[ic], "-", 1)) {
      fprintf(stderr, shortHelp,
              argv[0]);
      fprintf(stderr, "Only one verbose flag is authorized (one of -v, -v0, -v1, -v2, -v3, -v4)\n"
              "and must be before the -f flags\n");
      fprintf(stderr, "For more extensive help type: %s -h\n", argv[0]);
      return 1;
   } else {
      force = 0;
   }

   if (argc == ic) { // Something wrong here
      ROOT::TMetaUtils::Error(0, "Insufficient number of arguments!\n");
      fprintf(stderr, "%s\n", shortHelp);
      return 1;
   }

#if defined(R__WIN32) && !defined(R__WINGCC)
   // cygwin's make is presenting us some cygwin paths even though
   // we are windows native. Convert them as good as we can.
   for (int iic = ic; iic < argc; ++iic) {
      std::string iiarg(argv[iic]);
      if (FromCygToNativePath(iiarg)) {
         size_t len = iiarg.length();
         // yes, we leak.
         char *argviic = new char[len + 1];
         strlcpy(argviic, iiarg.c_str(), len + 1);
         argv[iic] = argviic;
      }
   }
#endif

   // Store the temp files
   tempFileNamesCatalog tmpCatalog;

   if (ic < argc && IsImplementationName(argv[ic])) {
      FILE *fp;
      if (!ignoreExistingDict && (fp = fopen(argv[ic], "r")) != 0) {
         fclose(fp);
         if (!force) {
            ROOT::TMetaUtils::Error(0, "%s: output file %s already exists\n", argv[0], argv[ic]);
            return 1;
         }
      }

      // remove possible pathname to get the dictionary name
      if (strlen(argv[ic]) > (PATH_MAX - 1)) {
         ROOT::TMetaUtils::Error(0, "rootcling: dictionary name too long (more than %d characters): %s\n",
                                 (PATH_MAX - 1), argv[ic]);
         return 1;
      }

      dictpathname = argv[ic];
      dictname = llvm::sys::path::filename(dictpathname);
      ic++;

   } else if (!strcmp(argv[1], "-?") || !strcmp(argv[1], "-h")) {
      fprintf(stderr, "%s\n", rootClingHelp);
      return 1;
   } else {
      ic = 1;
      if (force) ic = 2;
   }

   if (force && dictname.empty()) {
      ROOT::TMetaUtils::Error(0, "Inconsistent set of arguments detected: overwrite of dictionary file forced but no filename specified.\n");
      fprintf(stderr, "%s\n", shortHelp);
      return 1;
   }

   std::vector<std::string> clingArgs;
   clingArgs.push_back(argv[0]);
   clingArgs.push_back("-iquote.");

   // Is this needed at all or just historical?
   if (! IsPointerTClassCopy<std::vector<int>::iterator>::kVal) {
      // Tell cling (for parsing pragma) that std::vector's iterator is a class
      clingArgs.push_back("-DG__VECTOR_HAS_CLASS_ITERATOR");
   }

   if (ic < argc && !strcmp(argv[ic], "-c")) {
      // Simply ignore the -c options.
      ic++;
   }

   std::vector<std::string> baseModules;
   std::string sharedLibraryPathName;
   std::vector<std::string> rootmapLibNames;
   std::string rootmapFileName;
   std::vector<std::string> excludePaths;

   bool inlineInputHeader = false;
   bool interpreteronly = false;
   bool doSplit = false;
   bool dictSelection = true;
   bool multiDict = false;
   bool writeEmptyRootPCM = false;
   bool selSyntaxOnly = false;
   bool noIncludePaths = false;

   // Collect the diagnostic pragmas linked to the usage of -W
   // Workaround for ROOT-5656
   std::list<std::string> diagnosticPragmas = {"#pragma clang diagnostic ignored \"-Wdeprecated-declarations\""};

   int nextStart = 0;
   while (ic < argc) {
      if (*argv[ic] == '-' || *argv[ic] == '+') {

         if (strcmp("-rml", argv[ic]) == 0 && (ic + 1) < argc) {
            // name of the lib for the rootmap
            rootmapLibNames.push_back(argv[ic + 1]);
            ic += 2;
            continue;
         }

         if (strcmp("-rmf", argv[ic]) == 0 && (ic + 1) < argc) {
            // name for the rootmap file
            rootmapFileName = argv[ic + 1];
            ic += 2;
            continue;
         }

         if (strcmp("-multiDict", argv[ic]) == 0) {
            // Generate a pcm name which contains the libname and the dict name
            multiDict = true;
            ic += 1;
            continue;
         }

         if (strcmp("-interpreteronly", argv[ic]) == 0) {
            // Generate dictionaries only for the interpreter
            interpreteronly = true;
            ic += 1;
            continue;
         }

         if (strcmp("-split", argv[ic]) == 0) {
            // Split the dict
            doSplit = true;
            ic += 1;
            continue;
         }

         if (strcmp("-noDictSelection", argv[ic]) == 0) {
            // Disable selection
            dictSelection = false;
            ic += 1;
            continue;
         }

         if (strcmp("-s", argv[ic]) == 0 && (ic + 1) < argc) {
            // Target shared library name
            sharedLibraryPathName = argv[ic + 1];
            ic += 2;
            continue;
         }


         if (strcmp("-m", argv[ic]) == 0 && (ic + 1) < argc) {
            // precompiled modules
            baseModules.push_back(argv[ic + 1]);
            ic += 2;
            continue;
         }

         if (strcmp("-excludePath", argv[ic]) == 0 && (ic + 1) < argc) {
            // Path to be excluded from the ones rememberd by the dictionary
            excludePaths.push_back(argv[ic + 1]);
            ic += 2;
            continue;
         }
         if (strcmp("+P", argv[ic]) == 0 ||
               strcmp("+V", argv[ic]) == 0 ||
               strcmp("+STUB", argv[ic]) == 0) {
            // Ignore CINT arguments.
            continue;
         }

         if (strcmp("-inlineInputHeader", argv[ic]) == 0) {
            // inline the input header
            inlineInputHeader = true;
            ic += 1;
            continue;
         }

         if (strcmp("-writeEmptyRootPCM", argv[ic]) == 0) {
            // inline the input header
            writeEmptyRootPCM = true;
            ic += 1;
            continue;
         }

         if (strcmp("-selSyntaxOnly", argv[ic]) == 0) {
            // validate the selection grammar w/o creating the dictionary
            selSyntaxOnly = true;
            ic += 1;
            continue;
         }

         if (strcmp("-failOnWarnings", argv[ic]) == 0) {
            // Fail on Warnings and Errors
            ROOT::TMetaUtils::GetErrorIgnoreLevel() = ROOT::TMetaUtils::kThrowOnWarning;
            ic += 1;
            continue;
         }

         if (strcmp("-noIncludePaths", argv[ic]) == 0) {
            noIncludePaths = true;
            ic += 1;
            continue;
         }

         if (int skip = ShouldIgnoreClingArgument(argv[ic])) {
            ic += skip;
            continue;
         } else {
            // filter out even more undesirable options
            if (strcmp("-p", argv[ic])) {
               CheckForMinusW(argv[ic], diagnosticPragmas);
               clingArgs.push_back(argv[ic]);
            }
         }
      } else if (nextStart == 0) {
         nextStart = ic;
      }
      ic++;
   }

   // Check if we have a multi dict request but no target library
   if (multiDict && sharedLibraryPathName.empty()) {
      ROOT::TMetaUtils::Error("", "Multidict requested but no target library. Please specify one with the -s argument.\n");
      return 1;
   }

   ic = nextStart;
   clingArgs.push_back(std::string("-I") + gDriverConfig->fTROOT__GetIncludeDir());

   std::vector<std::string> pcmArgs;
   for (size_t parg = 0, n = clingArgs.size(); parg < n; ++parg) {
      auto thisArg = clingArgs[parg];
      auto isInclude = ROOT::TMetaUtils::BeginsWith(thisArg,"-I");
      if (thisArg == "-c" ||
          (noIncludePaths && isInclude)) continue;
      // We now check if the include directories are not excluded
      if (isInclude) {
         unsigned int offset = 2; // -I is two characters. Now account for spaces
         char c = thisArg[offset];
         while (c == ' ') c = thisArg[++offset];
         auto excludePathsEnd = excludePaths.end();
         auto excludePathPos = std::find_if(excludePaths.begin(),
                                            excludePathsEnd,
                                            [&](const std::string& path){
                                               return ROOT::TMetaUtils::BeginsWith(&thisArg[offset], path);});
         if (excludePathsEnd != excludePathPos) continue;
      }
      pcmArgs.push_back(thisArg);
   }

   // cling-only arguments
   clingArgs.push_back(std::string("-I") + gDriverConfig->fTROOT__GetEtcDir());
   // We do not want __ROOTCLING__ in the pch!
   if (!onepcm) {
      clingArgs.push_back("-D__ROOTCLING__");
   }
   clingArgs.push_back("-fsyntax-only");
   clingArgs.push_back("-fPIC");
   clingArgs.push_back("-Xclang");
   clingArgs.push_back("-fmodules-embed-all-files");
   clingArgs.push_back("-Xclang");
   clingArgs.push_back("-main-file-name");
   clingArgs.push_back("-Xclang");
   clingArgs.push_back((dictname + ".h").c_str());

   ROOT::TMetaUtils::SetPathsForRelocatability(clingArgs);

   // Convert arguments to a C array and check if they are sane
   std::vector<const char *> clingArgsC;
   for (auto const & clingArg : clingArgs) {
      if (!IsCorrectClingArgument(clingArg)){
         std::cerr << "Argument \""<< clingArg << "\" is not a supported cling argument. "
                   << "This could be mistyped rootcling argument. Please check the commandline.\n";
         return 1;
      }
      clingArgsC.push_back(clingArg.c_str());
   }

#ifdef R__EXTERN_LLVMDIR
   std::string resourceDir = R__EXTERN_LLVMDIR;
#else
   std::string resourceDir = std::string(gDriverConfig->fTROOT__GetEtcDir()) + "/cling";
#endif

   std::unique_ptr<cling::Interpreter> owningInterpPtr;
   cling::Interpreter* interpPtr = nullptr;

   std::list<std::string> filesIncludedByLinkdef;
   if (!gDriverConfig->fBuildingROOTStage1) {
      // Pass the interpreter arguments to TCling's interpreter:
      clingArgsC.push_back("-resource-dir");
      clingArgsC.push_back(resourceDir.c_str());
      clingArgsC.push_back(0); // signal end of array
      const char ** &extraArgs = *gDriverConfig->fTROOT__GetExtraInterpreterArgs();
      extraArgs = &clingArgsC[1]; // skip binary name
      interpPtr = gDriverConfig->fTCling__GetInterpreter();
      if (!isGenreflex && !onepcm) {
         std::unique_ptr<TRootClingCallbacks> callBacks (new TRootClingCallbacks(interpPtr, filesIncludedByLinkdef));
         interpPtr->setCallbacks(std::move(callBacks));
      }
   } else {
      owningInterpPtr.reset(new cling::Interpreter(clingArgsC.size(), &clingArgsC[0],
                                                   resourceDir.c_str()));
      interpPtr = owningInterpPtr.get();
   }
   cling::Interpreter &interp = *interpPtr;
   // FIXME: Remove this once we switch cling to use the driver. This would handle  -fmodules-embed-all-files for us.
   interp.getCI()->getFrontendOpts().ModulesEmbedAllFiles = true;
   interp.getCI()->getSourceManager().setAllFilesAreTransient(true);

   if (ROOT::TMetaUtils::GetErrorIgnoreLevel() == ROOT::TMetaUtils::kInfo) {
      ROOT::TMetaUtils::Info(0, "\n");
      ROOT::TMetaUtils::Info(0, "==== INTERPRETER CONFIGURATION ====\n");
      ROOT::TMetaUtils::Info(0, "== Include paths\n");
      interp.DumpIncludePath();
      printf("\n\n");
      fflush(stdout);

      ROOT::TMetaUtils::Info(0, "== Included files\n");
      interp.printIncludedFiles(llvm::outs());
      llvm::outs() << "\n\n";
      llvm::outs().flush();

      ROOT::TMetaUtils::Info(0, "== Language Options\n");
      const clang::LangOptions& LangOpts
         = interp.getCI()->getASTContext().getLangOpts();
#define LANGOPT(Name, Bits, Default, Description) \
      ROOT::TMetaUtils::Info(0, "%s = %d // %s\n", #Name, (int)LangOpts.Name, Description);
#define ENUM_LANGOPT(Name, Type, Bits, Default, Description)
#include "clang/Basic/LangOptions.def"
      ROOT::TMetaUtils::Info(0, "==== END interpreter configuration ====\n\n");
   }

   interp.getOptions().ErrorOut = true;
   interp.enableRawInput(true);
   if (isGenreflex) {
      if (interp.declare("namespace std {} using namespace std;") != cling::Interpreter::kSuccess) {
         // There was an error.
         ROOT::TMetaUtils::Error(0, "Error loading the default header files.\n");
         return 1;
      }
   } else {
      // rootcling
      if (interp.declare("namespace std {} using namespace std;") != cling::Interpreter::kSuccess
            // CINT uses to define a few header implicitly, we need to do it explicitly.
            || interp.declare("#include <assert.h>\n"
                              "#include <stdlib.h>\n"
                              "#include <stddef.h>\n"
                              "#include <string.h>\n"
                             ) != cling::Interpreter::kSuccess
            || interp.declare("#include \"Rtypes.h\"\n"
                              "#include \"TClingRuntime.h\"\n"
                              "#include \"TObject.h\""
                             ) != cling::Interpreter::kSuccess
         ) {
         // There was an error.
         ROOT::TMetaUtils::Error(0, "Error loading the default header files.\n");
         return 1;
      }
   }

   // For the list of 'opaque' typedef to also include string, we have to include it now.
   interp.declare("#include <string>");

   // We are now ready (enough is loaded) to init the list of opaque typedefs.
   ROOT::TMetaUtils::TNormalizedCtxt normCtxt(interp.getLookupHelper());
   ROOT::TMetaUtils::TClingLookupHelper helper(interp, normCtxt, 0, 0);
   TClassEdit::Init(&helper);

   // flags used only for the pragma parser:
   clingArgs.push_back("-D__CINT__");
   clingArgs.push_back("-D__MAKECINT__");
#ifdef R__WIN32
   // Prevent the following #error: The C++ Standard Library forbids macroizing keywords.
   clingArgs.push_back("-D_XKEYCHECK_H");
#endif

   AddPlatformDefines(clingArgs);

   std::string interpPragmaSource;
   std::string includeForSource;
   std::string interpreterDeclarations;
   string esc_arg;
   int firstInputFile = 0;
   int linkdefLoc = 0;
   for (int i = ic; i < argc; i++) {
      if (strcmp("-m", argv[i]) == 0 && (i + 1) < argc) {
         // precompiled modules
         baseModules.push_back(argv[ic + 1]);
         ++i;
         continue;
      }
      if (!firstInputFile && *argv[i] != '-' && *argv[i] != '+') {
         firstInputFile = i;
      }
      if (IsSelectionFile(argv[i])) {
         linkdefLoc = i;
         if (i != argc - 1) {
            ROOT::TMetaUtils::Error(0, "%s: %s must be last file on command line\n", argv[0], argv[i]);
            return 1;
         }
      }
      if (!strcmp(argv[i], "-c")) {
         // Simply ignore the -c options.
         // ROOT::TMetaUtils::Error(0, "%s: option -c must come directly after the output file\n", argv[0]);
         // return 1;
      }
      if (int skip = ShouldIgnoreClingArgument(argv[ic])) {
         i += (skip - 1); // for-loop takes care of the extra 1.
         continue;
      } else {
         // filter out undesirable options

         if (*argv[i] != '-' && *argv[i] != '+') {
            // Looks like a file

            bool isSelectionFile = IsSelectionFile(argv[i]);

            // coverity[tainted_data] The OS should already limit the argument size, so we are safe here
            std::string fullheader(argv[i]);
            // Strip any trailing + which is only used by GeneratedLinkdef.h which currently
            // use directly argv.
            if (fullheader[fullheader.length() - 1] == '+') {
               fullheader.erase(fullheader.length() - 1);
            }
            std::string header(isSelectionFile ? fullheader : GetRelocatableHeaderName(fullheader, currentDirectory));

            interpPragmaSource += std::string("#include \"") + header + "\"\n";
            if (!isSelectionFile) {
               // In order to not have to add the equivelent to -I${PWD} to the
               // command line, include the complete file name, even if it is a
               // full pathname, when we write it down in the dictionary.
               // Note: have -I${PWD} means in that (at least in the case of
               // ACLiC) we inadvertently pick local file that have the same
               // name as system header (e.g. new or list) and -iquote has not
               // equivalent on some platforms.
               includeForSource += std::string("#include \"") + fullheader + "\"\n";
               pcmArgs.push_back(header);
            } else if (!IsSelectionXml(argv[i])) {
               interpreterDeclarations += std::string("#include \"") + header + "\"\n";
            }
         }
      }
   }

   if (gDriverConfig->fAddAncestorPCMROOTFile) {
      for (const auto & baseModule : baseModules)
         gDriverConfig->fAddAncestorPCMROOTFile(baseModule.c_str());
   }

   if (!firstInputFile) {
      ROOT::TMetaUtils::Error(0, "%s: no input files specified\n", argv[0]);
      return 1;
   }

   if (sharedLibraryPathName.empty()) {
      sharedLibraryPathName = dictpathname;
   }

   // We have a multiDict request. This implies generating a pcm which is of the form
   // dictName_libname_rdict.pcm
   if (multiDict) {

      std::string newName = llvm::sys::path::parent_path(sharedLibraryPathName).str();
      if (!newName.empty())
         newName += gPathSeparator;
      newName += llvm::sys::path::stem(sharedLibraryPathName);
      newName += "_";
      newName += llvm::sys::path::stem(dictpathname);
      newName += llvm::sys::path::extension(sharedLibraryPathName);
      sharedLibraryPathName = newName;
   }

   // Until the module are actually enabled in ROOT, we need to register
   // the 'current' directory to make it relocatable (i.e. have a way
   // to find the headers).
   if (!gBuildingROOT && !noIncludePaths){
      string incCurDir = "-I";
      incCurDir += currentDirectory;
      pcmArgs.push_back(incCurDir);
   }

   // Add the diagnostic pragmas distilled from the -Wno-xyz
   {
      std::stringstream res;
      const char* delim="\n";
      std::copy(diagnosticPragmas.begin(),
                diagnosticPragmas.end(),
                std::ostream_iterator<std::string>(res, delim));
      interp.declare(res.str());
   }

   class IgnoringPragmaHandler: public clang::PragmaNamespace {
   public:
      IgnoringPragmaHandler(const char* pragma):
         clang::PragmaNamespace(pragma) {}
      void HandlePragma(clang::Preprocessor &PP,
                        clang::PragmaIntroducerKind Introducer,
                        clang::Token &tok) {
         PP.DiscardUntilEndOfDirective();
      }
   };

   // Ignore these #pragmas to suppress "unknown pragma" warnings.
   // See LinkdefReader.cxx.
   clang::Preprocessor& PP = interp.getCI()->getPreprocessor();
   PP.AddPragmaHandler(new IgnoringPragmaHandler("link"));
   PP.AddPragmaHandler(new IgnoringPragmaHandler("extra_include"));
   PP.AddPragmaHandler(new IgnoringPragmaHandler("read"));
   PP.AddPragmaHandler(new IgnoringPragmaHandler("create"));

   if (!interpreterDeclarations.empty() &&
       interp.declare(interpreterDeclarations) != cling::Interpreter::kSuccess) {
      ROOT::TMetaUtils::Error(0, "%s: Linkdef compilation failure\n", argv[0]);
      return 1;
   }


   TModuleGenerator modGen(interp.getCI(),
                           inlineInputHeader,
                           sharedLibraryPathName);

   if (!gDriverConfig->fBuildingROOTStage1 && filesIncludedByLinkdef.size() !=0) {
      pcmArgs.push_back(argv[linkdefLoc]);
   }

   modGen.ParseArgs(pcmArgs);

   if (!gDriverConfig->fBuildingROOTStage1) {
      // Forward the -I, -D, -U
      for (const std::string & inclPath : modGen.GetIncludePaths()) {
         interp.AddIncludePath(inclPath);
      }
      std::stringstream definesUndefinesStr;
      modGen.WritePPDefines(definesUndefinesStr);
      modGen.WritePPUndefines(definesUndefinesStr);
      if (!definesUndefinesStr.str().empty())
         interp.declare(definesUndefinesStr.str());
   }

   if (!InjectModuleUtilHeader(argv[0], modGen, interp, true)
         || !InjectModuleUtilHeader(argv[0], modGen, interp, false)) {
      return 1;
   }

   if (!linkdefLoc) {
      // Generate autolinkdef
      GenerateLinkdef(&argc, argv, firstInputFile, interpPragmaSource);
   }

   // Check if code goes to stdout or rootcling file
   std::ofstream fileout;
   string main_dictname(dictpathname);
   std::ostream *dictStreamPtr = NULL;
   if (!ignoreExistingDict) {
      if (!dictpathname.empty()) {
         tmpCatalog.addFileName(dictpathname);
         fileout.open(dictpathname.c_str());
         dictStreamPtr = &fileout;
         if (!(*dictStreamPtr)) {
            ROOT::TMetaUtils::Error(0, "rootcling: failed to open %s in main\n",
                                    dictpathname.c_str());
            return 1;
         }
      } else {
         dictStreamPtr = &std::cout;
      }
   } else {
      fileout.open("/dev/null");
      dictStreamPtr = &fileout;
   }

   // Now generate a second stream for the split dictionary if it is necessary
   std::ostream *splitDictStreamPtr = doSplit ? CreateStreamPtrForSplitDict(dictpathname, tmpCatalog) : dictStreamPtr;
   std::ostream &dictStream = *dictStreamPtr;
   std::ostream &splitDictStream = *splitDictStreamPtr;

   size_t dh = main_dictname.rfind('.');
   if (dh != std::string::npos) {
      main_dictname.erase(dh);
   }
   // Need to replace all the characters not allowed in a symbol ...
   std::string main_dictname_copy(main_dictname);
   TMetaUtils::GetCppName(main_dictname, main_dictname_copy.c_str());

   CreateDictHeader(dictStream, main_dictname);
   if (doSplit)
      CreateDictHeader(splitDictStream, main_dictname);

   //---------------------------------------------------------------------------
   // Parse the linkdef or selection.xml file.
   /////////////////////////////////////////////////////////////////////////////

   string linkdefFilename;
   if (!linkdefLoc) {
      linkdefFilename = "in memory";
   } else {
      bool found = Which(interp, argv[linkdefLoc], linkdefFilename);
      if (!found) {
         ROOT::TMetaUtils::Error(0, "%s: cannot open linkdef file %s\n", argv[0], argv[linkdefLoc]);
         return 1;
      }
   }

   // Exclude string not to re-generatre the dictionary
   std::vector<std::pair<std::string, std::string>> namesForExclusion;
   if (!gBuildingROOT) {
      namesForExclusion.push_back(std::make_pair(ROOT::TMetaUtils::propNames::name, "std::string"));
      namesForExclusion.push_back(std::make_pair(ROOT::TMetaUtils::propNames::pattern, "ROOT::Meta::Selection*"));
   }

   SelectionRules selectionRules(interp, normCtxt, namesForExclusion);

   std::string extraIncludes;

   ROOT::TMetaUtils::RConstructorTypes constructorTypes;

   // Select using DictSelection
   clang::CompilerInstance *CI = interp.getCI();
   const unsigned int selRulesInitialSize = selectionRules.Size();
   if (dictSelection && !onepcm)
      DictSelectionReader dictSelReader(interp, selectionRules, CI->getASTContext(), normCtxt);

   bool dictSelRulesPresent = selectionRules.Size() > selRulesInitialSize;

   bool isSelXML = IsSelectionXml(linkdefFilename.c_str());

   if (requestAllSymbols && !isSelXML) {
      selectionRules.SetDeep(true);
   } else if (!linkdefLoc) {
      // There is no linkdef file, we added the 'default' #pragma to
      // interpPragmaSource.

      LinkdefReader ldefr(interp, constructorTypes);
      clingArgs.push_back("-Ietc/cling/cint"); // For multiset and multimap

      if (!ldefr.Parse(selectionRules, interpPragmaSource, clingArgs,
                       resourceDir.c_str())) {
         ROOT::TMetaUtils::Error(0, "Parsing #pragma failed %s\n", linkdefFilename.c_str());
      } else {
         ROOT::TMetaUtils::Info(0, "#pragma successfully parsed.\n");
      }

      if (!ldefr.LoadIncludes(extraIncludes)) {
         ROOT::TMetaUtils::Error(0, "Error loading the #pragma extra_include.\n");
         return 1;
      }
   } else if (isSelXML) {

      selectionRules.SetSelectionFileType(SelectionRules::kSelectionXMLFile);

      std::ifstream file(linkdefFilename.c_str());
      if (file.is_open()) {
         ROOT::TMetaUtils::Info(0, "Selection XML file\n");

         XMLReader xmlr(interp);
         if (!xmlr.Parse(linkdefFilename.c_str(), selectionRules)) {
            ROOT::TMetaUtils::Error(0, "Parsing XML file %s\n", linkdefFilename.c_str());
            return 1; // Return here to propagate the failure up to the build system
         } else {
            ROOT::TMetaUtils::Info(0, "XML file successfully parsed\n");
         }
         file.close();
      } else {
         ROOT::TMetaUtils::Error(0, "XML file %s couldn't be opened!\n", linkdefFilename.c_str());
      }

   } else if (ROOT::TMetaUtils::IsLinkdefFile(linkdefFilename.c_str())) {

      std::ifstream file(linkdefFilename.c_str());
      if (file.is_open()) {
         ROOT::TMetaUtils::Info(0, "Using linkdef file: %s\n", linkdefFilename.c_str());
         file.close();
      } else {
         ROOT::TMetaUtils::Error(0, "Linkdef file %s couldn't be opened!\n", linkdefFilename.c_str());
      }

      selectionRules.SetSelectionFileType(SelectionRules::kLinkdefFile);

      LinkdefReader ldefr(interp, constructorTypes);
      clingArgs.push_back("-Ietc/cling/cint"); // For multiset and multimap

      if (!ldefr.Parse(selectionRules, interpPragmaSource, clingArgs,
                       resourceDir.c_str())) {
         ROOT::TMetaUtils::Error(0, "Parsing Linkdef file %s\n", linkdefFilename.c_str());
      } else {
         ROOT::TMetaUtils::Info(0, "Linkdef file successfully parsed.\n");
      }

      if (! ldefr.LoadIncludes(extraIncludes)) {
         ROOT::TMetaUtils::Error(0, "Error loading the #pragma extra_include.\n");
         return 1;
      }
   } else {

      ROOT::TMetaUtils::Error(0, "Unrecognized selection file: %s\n", linkdefFilename.c_str());

   }

   // Speed up the operations with rules
   selectionRules.FillCache();
   selectionRules.Optimize();

   if (isGenreflex){
      if (0 != selectionRules.CheckDuplicates()){
         return 1;
      }
   }

   // If we want to validate the selection only, we just quit.
   if (selSyntaxOnly)
      return 0;

   //---------------------------------------------------------------------------
   // Write schema evolution related headers and declarations
   /////////////////////////////////////////////////////////////////////////////

   if (!gReadRules.empty() || !gReadRawRules.empty()) {
      dictStream << "#include \"TBuffer.h\"\n"
                 << "#include \"TVirtualObject.h\"\n"
                 << "#include <vector>\n"
                 << "#include \"TSchemaHelper.h\"\n\n";

      std::list<std::string> includes;
      GetRuleIncludes(includes);
      for (auto & incFile : includes) {
         dictStream << "#include <" << incFile << ">" << std::endl;
      }
      dictStream << std::endl;
   }

   selectionRules.SearchNames(interp);

   int scannerVerbLevel = 0;
   {
      using namespace ROOT::TMetaUtils;
      scannerVerbLevel = GetErrorIgnoreLevel() == kInfo; // 1 if true, 0 if false
      if (isGenreflex){
         scannerVerbLevel = GetErrorIgnoreLevel() < kWarning;
      }
   }

   // Select the type of scan
   auto scanType = RScanner::EScanType::kNormal;
   if (onepcm)
      scanType = RScanner::EScanType::kOnePCM;
   if (dictSelection)
      scanType = RScanner::EScanType::kTwoPasses;

   RScanner scan(selectionRules,
                 scanType,
                 interp,
                 normCtxt,
                 scannerVerbLevel);

   // If needed initialize the autoloading hook
   if (liblistPrefix.length()) {
      LoadLibraryMap(liblistPrefix + ".in", gAutoloads);
      scan.SetRecordDeclCallback(RecordDeclCallback);
   }

   if (requestAllSymbols) {
      selectionRules.SetDeep(true);
   }

   scan.Scan(CI->getASTContext());

   bool has_input_error = false;

   if (genreflex::verbose)
      selectionRules.PrintSelectionRules();

   if (ROOT::TMetaUtils::GetErrorIgnoreLevel() != ROOT::TMetaUtils::kFatal &&
         !onepcm &&
         !dictSelRulesPresent &&
         !selectionRules.AreAllSelectionRulesUsed()) {
      ROOT::TMetaUtils::Warning(0, "Not all selection rules are used!\n");
   }

   int rootclingRetCode(0);

   if (!onepcm){
      rootclingRetCode += CheckForUnsupportedClasses(scan.fSelectedClasses);
      if (rootclingRetCode) return rootclingRetCode;
   }

   // SELECTION LOOP
   // Check for error in the class layout before doing anything else.
   for (auto const & annRcd : scan.fSelectedClasses) {
      if (ROOT::TMetaUtils::ClassInfo__HasMethod(annRcd, "Streamer", interp)) {
         if (annRcd.RequestNoInputOperator()) {
            int version = ROOT::TMetaUtils::GetClassVersion(annRcd, interp);
            if (version != 0) {
               // Only Check for input operator is the object is I/O has
               // been requested.
               has_input_error |= CheckInputOperator(annRcd, interp);
            }
         }
      }
      has_input_error |= !CheckClassDef(*annRcd, interp);
   }

   if (has_input_error) {
      // Be a little bit makefile friendly and remove the dictionary in case of error.
      // We could add an option -k to keep the file even in case of error.
      exit(1);
   }

   //---------------------------------------------------------------------------
   // Write all the necessary #include
   /////////////////////////////////////////////////////////////////////////////
   if (!gDriverConfig->fBuildingROOTStage1) {
      for (auto &&includedFromLinkdef : filesIncludedByLinkdef) {
         includeForSource += "#include \"" + includedFromLinkdef + "\"\n";
      }
   }

   if (!onepcm) {
      GenerateNecessaryIncludes(dictStream, includeForSource, extraIncludes);
      if (doSplit) {
         GenerateNecessaryIncludes(splitDictStream, includeForSource, extraIncludes);
      }
      if (gDriverConfig->fInitializeStreamerInfoROOTFile) {
         gDriverConfig->fInitializeStreamerInfoROOTFile(modGen.GetModuleFileName().c_str());
      }

      // The order of addition to the list of constructor type
      // is significant.  The list is sorted by with the highest
      // priority first.
      if (!interpreteronly) {
         constructorTypes.push_back(ROOT::TMetaUtils::RConstructorType("TRootIOCtor", interp));
         constructorTypes.push_back(ROOT::TMetaUtils::RConstructorType("__void__", interp)); // ROOT-7723
         constructorTypes.push_back(ROOT::TMetaUtils::RConstructorType("", interp));
      }
   }

   if (onepcm) {
      AnnotateAllDeclsForPCH(interp, scan);
   } else if (interpreteronly) {
      rootclingRetCode += CheckClassesForInterpreterOnlyDicts(interp, scan);
      // generate an empty pcm nevertheless for consistency
      // Negate as true is 1 and true is returned in case of success.
      if (!gDriverConfig->fBuildingROOTStage1) {
         rootclingRetCode +=  FinalizeStreamerInfoWriting(interp);
      }
   } else {
      rootclingRetCode += GenerateFullDict(splitDictStream,
                                 interp,
                                 scan,
                                 constructorTypes,
                                 doSplit,
                                 isGenreflex,
                                 writeEmptyRootPCM);
   }

   if (rootclingRetCode != 0) {
      return rootclingRetCode;
   }

   if (doSplit && splitDictStreamPtr) delete splitDictStreamPtr;

   // Now we have done all our looping and thus all the possible
   // annotation, let's write the pcms.
   HeadersDeclsMap_t headersClassesMap;
   HeadersDeclsMap_t headersDeclsMap;
   if (!ignoreExistingDict) {
      const std::string fwdDeclnArgsToKeepString(GetFwdDeclnArgsToKeepString(normCtxt, interp));

      ExtractHeadersForDecls(scan.fSelectedClasses,
                             scan.fSelectedTypedefs,
                             scan.fSelectedFunctions,
                             scan.fSelectedVariables,
                             scan.fSelectedEnums,
                             headersClassesMap,
                             headersDeclsMap,
                             interp);

      std::string detectedUmbrella;
      for (auto & arg : pcmArgs) {
         if (inlineInputHeader && !ROOT::TMetaUtils::IsLinkdefFile(arg.c_str()) && ROOT::TMetaUtils::IsHeaderName(arg)) {
            detectedUmbrella = arg;
            break;
         }
      }

      if (writeEmptyRootPCM){
         headersDeclsMap.clear();
      }


      const std::string headersClassesMapString = GenerateStringFromHeadersForClasses(headersDeclsMap,
                                                                                      detectedUmbrella,
                                                                                      true);
      std::string fwdDeclsString = "\"\"";
      if (!gDriverConfig->fBuildingROOTStage1) {
         if (writeEmptyRootPCM) {
            fwdDeclsString = "nullptr";
         } else {
            fwdDeclsString = GenerateFwdDeclString(scan, interp);
         }
      }

      modGen.WriteRegistrationSource(dictStream, fwdDeclnArgsToKeepString, headersClassesMapString, fwdDeclsString);
      // If we just want to inline the input header, we don't need
      // to generate any files.
      if (!inlineInputHeader) {
         // Write the module/PCH depending on what mode we are on
         if (modGen.IsPCH()) {
            if (!GenerateAllDict(modGen, CI, currentDirectory)) return 1;
         } else if (getenv("ROOT_MODULES")) {
            if (!GenerateModule(modGen, CI)) return 1;
         }
      }
   }


   if (liblistPrefix.length()) {
      string liblist_filename = liblistPrefix + ".out";

      ofstream outputfile(liblist_filename.c_str(), ios::out);
      if (!outputfile) {
         ROOT::TMetaUtils::Error(0, "%s: Unable to open output lib file %s\n",
                                 argv[0], liblist_filename.c_str());
      } else {
         const size_t endStr = gLibsNeeded.find_last_not_of(" \t");
         outputfile << gLibsNeeded.substr(0, endStr + 1) << endl;
         // Add explicit delimiter
         outputfile << "# Now the list of classes\n";
         // SELECTION LOOP
         for (auto const & annRcd : scan.fSelectedClasses) {
            // Shouldn't it be GetLong64_Name( cl_input.GetNormalizedName() )
            // or maybe we should be normalizing to turn directly all long long into Long64_t
            outputfile << annRcd.GetNormalizedName() << endl;
         }
      }
   }

   // Check for errors in module generation
   rootclingRetCode += modGen.GetErrorCount();
   if (0 != rootclingRetCode) return rootclingRetCode;

   // Create the rootmap file
   std::string rootmapLibName = std::accumulate(rootmapLibNames.begin(),
                                rootmapLibNames.end(),
                                std::string(),
   [](const std::string & a, const std::string & b) -> std::string {
      if (a.empty()) return b;
      else return a + " " + b;
   });

   bool rootMapNeeded = !rootmapFileName.empty() || !rootmapLibName.empty();

   std::list<std::string> classesNames;
   std::list<std::string> classesNamesForRootmap;
   std::list<std::string> classesDefsList;

   rootclingRetCode = ExtractClassesListAndDeclLines(scan,
                                                     classesNames,
                                                     classesNamesForRootmap,
                                                     classesDefsList,
                                                     interp);

   std::list<std::string> enumNames;
   rootclingRetCode += ExtractAutoloadKeys(enumNames,
                                           scan.fSelectedEnums,
                                           interp);

   std::list<std::string> varNames;
   rootclingRetCode += ExtractAutoloadKeys(varNames,
                                           scan.fSelectedVariables,
                                           interp);

   if (0 != rootclingRetCode) return rootclingRetCode;

   // Create the rootmapfile if needed
   if (rootMapNeeded) {

      std::list<std::string> nsNames;

      ExtractSelectedNamespaces(scan, nsNames);

      AdjustRootMapNames(rootmapFileName,
                         rootmapLibName);

      ROOT::TMetaUtils::Info(0, "Rootmap file name %s and lib name(s) \"%s\"\n",
                             rootmapFileName.c_str(),
                             rootmapLibName.c_str());

      tmpCatalog.addFileName(rootmapFileName);
      std::unordered_set<std::string> headersToIgnore;
      if (inlineInputHeader) {
         for (int index = 0; index < argc; ++index) {
            if (*argv[index] != '-' && ROOT::TMetaUtils::IsHeaderName(argv[index])) {
               headersToIgnore.insert(argv[index]);
            }
         }
      }

      std::list<std::string> typedefsRootmapLines;
      rootclingRetCode += ExtractAutoloadKeys(typedefsRootmapLines,
                                              scan.fSelectedTypedefs,
                                              interp);

      rootclingRetCode = CreateNewRootMapFile(rootmapFileName,
                                          rootmapLibName,
                                          classesDefsList,
                                          classesNamesForRootmap,
                                          nsNames,
                                          typedefsRootmapLines,
                                          enumNames,
                                          varNames,
                                          headersClassesMap,
                                          headersToIgnore);

      if (0 != rootclingRetCode) return 1;
   }

   if (genreflex::verbose)
      tmpCatalog.dump();

   // Before returning, rename the files
   rootclingRetCode += tmpCatalog.commit();

   return rootclingRetCode;

}

namespace genreflex {

////////////////////////////////////////////////////////////////////////////////
/// Loop on arguments: stop at the first which starts with -

   unsigned int checkHeadersNames(std::vector<std::string> &headersNames)
   {
      unsigned int numberOfHeaders = 0;
      for (std::vector<std::string>::iterator it = headersNames.begin();
            it != headersNames.end(); it++) {
         const std::string headername(*it);
         if (ROOT::TMetaUtils::IsHeaderName(headername)) {
            numberOfHeaders++;
         } else {
            ROOT::TMetaUtils::Warning(0,
                                      "*** genreflex: %s is not a valid header name (.h and .hpp extensions expected)!\n",
                                      headername.c_str());
         }
      }
      return numberOfHeaders;
   }

////////////////////////////////////////////////////////////////////////////////
/// Extract the arguments from the command line

   unsigned int extractArgs(int argc, char **argv, std::vector<std::string> &args)
   {
      // loop on argv, spot strings which are not preceeded by something
      unsigned int argvCounter = 0;
      for (int i = 1; i < argc; ++i) {
         if (!ROOT::TMetaUtils::BeginsWith(argv[i - 1], "-") && // so, if preceeding element starts with -, this is a value for an option
               !ROOT::TMetaUtils::BeginsWith(argv[i], "-")) { // and the element itself is not an option
            args.push_back(argv[i]);
            argvCounter++;
         } else  if (argvCounter) {
            argv[i - argvCounter] = argv[i];
         }
      }

      // Some debug
      if (genreflex::verbose) {
         int i = 0;
         std::cout << "Args: \n";
         for (std::vector<std::string>::iterator it = args.begin();
               it < args.end(); ++it) {
            std::cout << i << ") " << *it << std::endl;
            ++i;
         }

      }

      return argvCounter;
   }

////////////////////////////////////////////////////////////////////////////////

   void changeExtension(std::string &filename, const std::string &newExtension)
   {
      size_t result = filename.find_last_of('.');
      if (std::string::npos != result) {
         filename.erase(result);
         filename.append(newExtension);
      }

   }

////////////////////////////////////////////////////////////////////////////////
/// The caller is responsible for deleting the string!

   char *string2charptr(const std::string &str)
   {
      const unsigned int size(str.size());
      char *a = new char[size + 1];
      a[size] = 0;
      memcpy(a, str.c_str(), size);
      return a;
   }

////////////////////////////////////////////////////////////////////////////////
/// Replace the extension with "_rflx.cpp"

   void header2outputName(std::string &fileName)
   {
      changeExtension(fileName, "_rflx.cpp");
   }

////////////////////////////////////////////////////////////////////////////////
/// Get a proper name for the output file

   void headers2outputsNames(const std::vector<std::string> &headersNames,
                             std::vector<std::string> &ofilesnames)
   {
      ofilesnames.reserve(headersNames.size());

      for (std::vector<std::string>::const_iterator it = headersNames.begin();
            it != headersNames.end(); it++) {
         std::string ofilename(*it);
         header2outputName(ofilename);
         ofilesnames.push_back(ofilename);
      }
   }

////////////////////////////////////////////////////////////////////////////////

   void AddToArgVector(std::vector<char *> &argvVector,
                       const std::vector<std::string> &argsToBeAdded,
                       const std::string &optName = "")
   {
      for (std::vector<std::string>::const_iterator it = argsToBeAdded.begin();
            it != argsToBeAdded.end(); it++) {
         argvVector.push_back(string2charptr(optName + *it));
      }
   }

////////////////////////////////////////////////////////////////////////////////

   void AddToArgVectorSplit(std::vector<char *> &argvVector,
                            const std::vector<std::string> &argsToBeAdded,
                            const std::string &optName = "")
   {
      for (std::vector<std::string>::const_iterator it = argsToBeAdded.begin();
            it != argsToBeAdded.end(); it++) {
         if (optName.length()) {
            argvVector.push_back(string2charptr(optName));
         }
         argvVector.push_back(string2charptr(*it));
      }
   }

////////////////////////////////////////////////////////////////////////////////

   int invokeRootCling(const std::string &verbosity,
                       const std::string &selectionFileName,
                       const std::string &targetLibName,
                       bool multiDict,
                       const std::vector<std::string> &pcmsNames,
                       const std::vector<std::string> &includes,
                       const std::vector<std::string> &preprocDefines,
                       const std::vector<std::string> &preprocUndefines,
                       const std::vector<std::string> &warnings,
                       const std::string &rootmapFileName,
                       const std::string &rootmapLibName,
                       bool interpreteronly,
                       bool doSplit,
                       bool isDeep,
                       bool writeEmptyRootPCM,
                       bool selSyntaxOnly,
                       bool noIncludePaths,
                       const std::vector<std::string> &headersNames,
                       bool failOnWarnings,
                       const std::string &ofilename)
   {
      // Prepare and invoke the commandline to invoke rootcling

      std::vector<char *> argvVector;

      argvVector.push_back(string2charptr("rootcling"));
      argvVector.push_back(string2charptr(verbosity));
      argvVector.push_back(string2charptr("-f"));
      argvVector.push_back(string2charptr(ofilename));

      // Extract the path to the dictionary
      std::string dictLocation;
      ExtractFilePath(ofilename, dictLocation);

      // Rootmaps

      // Prepare the correct rootmap libname if not already set.
      std::string newRootmapLibName(rootmapLibName);
      if (!rootmapFileName.empty() && newRootmapLibName.empty()) {
         if (headersNames.size() != 1) {
            ROOT::TMetaUtils::Warning(0,
                                      "*** genreflex: No rootmap lib and several header specified!\n");
         }
         std::string cleanHeaderName = ExtractFileName(headersNames[0]);
         newRootmapLibName = "lib";
         newRootmapLibName += cleanHeaderName;
         changeExtension(newRootmapLibName, gLibraryExtension);
      }

      // Prepend to the rootmap the designed directory of the dictionary
      // if no path is specified for the rootmap itself
      std::string newRootmapFileName(rootmapFileName);
      if (!newRootmapFileName.empty() && !HasPath(newRootmapFileName)) {
         newRootmapFileName = dictLocation + newRootmapFileName;
      }


      // RootMap filename
      if (!newRootmapFileName.empty()) {
         argvVector.push_back(string2charptr("-rmf"));
         argvVector.push_back(string2charptr(newRootmapFileName));
      }

      // RootMap Lib filename
      if (!newRootmapLibName.empty()) {
         argvVector.push_back(string2charptr("-rml"));
         argvVector.push_back(string2charptr(newRootmapLibName));
      }

      // Interpreter only dictionaries
      if (interpreteronly)
         argvVector.push_back(string2charptr("-interpreteronly"));

      // Split dictionaries
      if (doSplit)
         argvVector.push_back(string2charptr("-split"));

      // Targetlib
      if (!targetLibName.empty()) {
         argvVector.push_back(string2charptr("-s"));
         argvVector.push_back(string2charptr(targetLibName));
      }

      // Multidict support
      if (multiDict)
         argvVector.push_back(string2charptr("-multiDict"));


      AddToArgVectorSplit(argvVector, pcmsNames, "-m");

      // Inline the input header
      argvVector.push_back(string2charptr("-inlineInputHeader"));

      // Write empty root pcms
      if (writeEmptyRootPCM)
         argvVector.push_back(string2charptr("-writeEmptyRootPCM"));

      // Just test the syntax of the selection file
      if (selSyntaxOnly)
         argvVector.push_back(string2charptr("-selSyntaxOnly"));

      // No include paths
      if (noIncludePaths)
         argvVector.push_back(string2charptr("-noIncludePaths"));

      // Fail on warnings
      if (failOnWarnings)
         argvVector.push_back(string2charptr("-failOnWarnings"));

      // Clingargs
      AddToArgVector(argvVector, includes, "-I");
      AddToArgVector(argvVector, preprocDefines, "-D");
      AddToArgVector(argvVector, preprocUndefines, "-U");
      AddToArgVector(argvVector, warnings, "-W");

      AddToArgVector(argvVector, headersNames);

      if (!selectionFileName.empty()) {
         argvVector.push_back(string2charptr(selectionFileName));
      }

      const int argc = argvVector.size();

      // Output commandline for rootcling
      if (genreflex::verbose) {
         std::cout << "Rootcling commandline:\n";
         for (int i = 0; i < argc; i++)
            std::cout << i << ") " << argvVector[i] << std::endl;
      }

      char **argv =  & (argvVector[0]);
      int rootclingReturnCode = RootClingMain(argc,
                                              argv,
                                              isDeep,
                                              true);

      for (int i = 0; i < argc; i++)
         delete [] argvVector[i];

      return rootclingReturnCode;

   }

////////////////////////////////////////////////////////////////////////////////
/// Get the right ofilenames and invoke several times rootcling
/// One invokation per header

   int invokeManyRootCling(const std::string &verbosity,
                           const std::string &selectionFileName,
                           const std::string &targetLibName,
                           bool multiDict,
                           const std::vector<std::string> &pcmsNames,
                           const std::vector<std::string> &includes,
                           const std::vector<std::string> &preprocDefines,
                           const std::vector<std::string> &preprocUndefines,
                           const std::vector<std::string> &warnings,
                           const std::string &rootmapFileName,
                           const std::string &rootmapLibName,
                           bool interpreteronly,
                           bool doSplit,
                           bool isDeep,
                           bool writeEmptyRootPCM,
                           bool selSyntaxOnly,
                           bool noIncludePaths,
                           const std::vector<std::string> &headersNames,
                           bool failOnWarnings,
                           const std::string &outputDirName_const = "")
   {
      std::string outputDirName(outputDirName_const);

      std::vector<std::string> ofilesNames;
      headers2outputsNames(headersNames, ofilesNames);

      if (!outputDirName.empty() && !ROOT::TMetaUtils::EndsWith(outputDirName, gPathSeparator)) {
         outputDirName += gPathSeparator;
      }

      std::vector<std::string> namesSingleton(1);
      for (unsigned int i = 0; i < headersNames.size(); ++i) {
         namesSingleton[0] = headersNames[i];
         std::string ofilenameFullPath(ofilesNames[i]);
         if (llvm::sys::path::parent_path(ofilenameFullPath) == "")
            ofilenameFullPath = outputDirName + ofilenameFullPath;
         int returnCode = invokeRootCling(verbosity,
                                          selectionFileName,
                                          targetLibName,
                                          multiDict,
                                          pcmsNames,
                                          includes,
                                          preprocDefines,
                                          preprocUndefines,
                                          warnings,
                                          rootmapFileName,
                                          rootmapLibName,
                                          interpreteronly,
                                          doSplit,
                                          isDeep,
                                          writeEmptyRootPCM,
                                          selSyntaxOnly,
                                          noIncludePaths,
                                          namesSingleton,
                                          failOnWarnings,
                                          ofilenameFullPath);
         if (returnCode != 0)
            return returnCode;
      }

      return 0;
   }


} // end genreflex namespace

////////////////////////////////////////////////////////////////////////////////
/// Extract from options multiple values with the same option

int extractMultipleOptions(std::vector<ROOT::option::Option> &options,
                           int oIndex,
                           std::vector<std::string> &values)
{
   int nValues = 0;
   if (options[oIndex]) {
      const int nVals = options[oIndex].count();
      values.reserve(nVals);
      int optionIndex = 0;
      for (ROOT::option::Option *opt = options[oIndex]; opt; opt = opt->next()) {
         if (genreflex::verbose) std::cout << "Extracting multiple args: "
                                              << optionIndex << "/" << nVals << " "
                                              << opt->arg << std::endl;
         optionIndex++;
         values.push_back(opt->arg);
         nValues++;
      }
   }
   return nValues;
}

////////////////////////////////////////////////////////////////////////////////

void RiseWarningIfPresent(std::vector<ROOT::option::Option> &options,
                          int optionIndex,
                          const char *descriptor)
{
   if (options[optionIndex]) {
      ROOT::TMetaUtils::Warning(0,
                                "*** genereflex: %s is not supported anymore.\n",
                                descriptor);
   }
}

////////////////////////////////////////////////////////////////////////////////

bool IsGoodLibraryName(const std::string &name)
{


   auto isGood = ROOT::TMetaUtils::EndsWith(name, gLibraryExtension);
#ifdef __APPLE__
   isGood |= ROOT::TMetaUtils::EndsWith(name, ".dylib");
#endif
   return isGood;
}

////////////////////////////////////////////////////////////////////////////////
/// Translate the aruments of genreflex into rootcling ones and forward them
/// to the RootCling function.
/// These are two typical genreflex and rootcling commandlines
/// 1) genreflex header1.h [header2.h ...] [options] [preprocessor options]
/// 2) rootcling [-v] [-v0-4] [-f] [out.cxx] [-s sharedlib.so] [-m pcmfilename]
///     header1.h[{+,-}][!] ..headerN.h[{+,-}][!] [{LinkDef.h,selectionRules.xml}]
/// The rules with which the arguments are translated are (1st column genreflex):
/// --debug                             -v4
/// --quiet                             -v0
/// -o ofile                            positional arg after -f
/// -s selection file                   Last argument of the call
/// --fail_on_warning                   Wrap ROOT::TMetaUtils::Warning and throw if selected
///
/// New arguments:
/// -l --library targetLib name (new)   -s  targetLib name
/// -m pcmname (can be many -m) (new)   -m pcmname (can be many -m)
/// --rootmap                           -rmf (new)
/// --rootmap-lib                       -rml (new)
///
/// genreflex options which rise warnings (feedback is desirable)
/// --no_membertypedefs (it should be irrelevant)
/// --no_templatetypedefs (it should be irrelevant)
///
/// genreflex options which are ignored (know for sure they are not needed)
/// --pool, --dataonly
/// --interpreteronly
/// --gccxml{path,opt,post}
/// --reflex
///
///
/// Exceptions
/// The --deep option of genreflex is passed as function parameter to rootcling
/// since it's not needed at the moment there.

int GenReflexMain(int argc, char **argv)
{
   using namespace genreflex;

   // Setup the options parser
   enum  optionIndex { UNKNOWN,
                       OFILENAME,
                       TARGETLIB,
                       MULTIDICT,
                       SELECTIONFILENAME,
                       ROOTMAP,
                       ROOTMAPLIB,
                       PCMFILENAME,
                       DEEP,
                       DEBUG,
                       VERBOSE,
                       QUIET,
                       SILENT,
                       WRITEEMPTYROOTPCM,
                       HELP,
                       FAILONWARNINGS,
                       SELSYNTAXONLY,
                       INTERPRETERONLY,
                       SPLIT,
                       NOMEMBERTYPEDEFS,
                       NOTEMPLATETYPEDEFS,
                       NOINCLUDEPATHS,
                       // Don't show up in the help
                       PREPROCDEFINE,
                       PREPROCUNDEFINE,
                       INCLUDE,
                       WARNING
                     };

   enum  optionTypes { NOTYPE, STRING } ;

   // Some long help strings
   const char *genreflexUsage =
      "Generates dictionary sources and related ROOT pcm starting from an header.\n"
      "Usage: genreflex headerfile.h [opts] [preproc. opts]\n\n"
      "Options:\n";

   const char *selectionFilenameUsage =
      "-s, --selection_file\tSelection filename\n"
      "      Class selection file to specify for which classes the dictionary\n"
      "      will be generated. The final set can be crafted with exclusion and\n"
      "      exclusion rules.\n"
      "      Properties can be specified. Some have special meaning:\n"
      "      - name [string] name of the entity to select with an exact matching\n"
      "      - pattern [string] name with wildcards (*) to select entities\n"
      "      - file_name/file_pattern [string]: as name/pattern but referring to\n"
      "        file where the C++ entities reside and not to C++ entities themselves.\n"
      "      - transient/persistent [string: true/false] The fields to which they are\n"
      "        applied will not be persistified if requested.\n"
      "      - comment [string]: what you could write in code after an inline comment\n"
      "        without \"//\". For example comment=\"!\" or \"||\".\n"
      "      - noStreamer [true/false]: turns off streamer generation if set to 'true.'\n"
      "        Default value is 'false'\n"
      "      - noInputOperator [true/false]: turns off input operator generation if set\n"
      "        to 'true'. Default value is 'false'\n"
      "      Example XML:\n"
      "        <lcgdict>\n"
      "        [<selection>]\n"
      "          <class [name=\"classname\"] [pattern=\"wildname\"]\n"
      "                 [file_name=\"filename\"] [file_pattern=\"wildname\"]\n"
      "                 [id=\"xxxx\"] [noStreamer=\"true/false\"]\n"
      "                 [noInputOperator=\"true/false\"] />\n"
      "          <class name=\"classname\" >\n"
      "            <field name=\"m_transient\" transient=\"true\"/>\n"
      "            <field name=\"m_anothertransient\" persistent=\"false\"/>\n"
      "            <field name=\"m_anothertransient\" comment=\"||\"/>\n"
      "            <properties prop1=\"value1\" [prop2=\"value2\"]/>\n"
      "          </class>\n"
      "          <function [name=\"funcname\"] [pattern=\"wildname\"] />\n"
      "          <enum [name=\"enumname\"] [pattern=\"wildname\"] />\n"
      "          <variable [name=\"varname\"] [pattern=\"wildname\"] />\n"
      "        [</selection>]\n"
      "        <exclusion>\n"
      "          <class [name=\"classname\"] [pattern=\"wildname\"] />\n"
      "            <method name=\"unwanted\" />\n"
      "          </class>\n"
      "        ...\n"
      "        </lcgdict>\n"
      "\n"
      "      If no selection file is specified, the class with the filename without\n"
      "      extension will be selected, i.e. myClass.h as argument without any\n"
      "      selection xml comes with an implicit selection rule for class \"myClass\".\n";

   const char *outputFilenameUsage =
      "-o, --output\tOutput filename\n"
      "      Output file name. If an existing directory is specified instead of a file,\n"
      "      then a filename will be build using the name of the input file and will\n"
      "      be placed in the given directory. <headerfile>_rflx.cpp.\n"
      "      NOTA BENE: the dictionaries that will be used within the same project must\n"
      "      have unique names.\n";


   const char *targetLib =
      "-l, --library\tTarget library\n"
      "      The flag -l must be followed by the name of the library that will\n"
      "      contain the object file corresponding to the dictionary produced by\n"
      "      this invocation of genreflex.\n"
      "      The name takes priority over the one specified for the rootmapfile.\n"
      "      The name influences the name of the created pcm:\n"
      "       1) If it is not specified, the pcm is called libINPUTHEADER_rdict.pcm\n"
      "       2) If it is specified, the pcm is called libTARGETLIBRARY_rdict.pcm\n"
      "          Any \"liblib\" occurence is transformed in the expected \"lib\".\n"
      "       3) If this is specified in conjunction with --multiDict, the output is\n"
      "          libTARGETLIBRARY_DICTIONARY_rdict.pcm\n";

   const char *rootmapUsage =
      "--rootmap\tGenerate the rootmap file to be used by ROOT.\n"
      "      This file lists the autoload keys. For example classes for which the\n"
      "      reflection information is provided.\n"
      "      The format of the rootmap is the following:\n"
      "        - Forward declarations section\n"
      "        - Libraries sections\n"
      "      Rootmaps can be concatenated together, for example with the cat util.\n"
      "      In order for ROOT to pick up the information in the rootmaps, they\n"
      "      have to be located in the library path and have the .rootmap extension.\n"
      "      An example rootmap file could be:\n"
      "      { decls }\n"
      "      template <class T> class A;\n"
      "      [ libMyLib.so ]\n"
      "      class A<double>\n"
      "      class B\n"
      "      typedef C\n"
      "      header H.h\n";

   const char *rootmapLibUsage =
      "--rootmap-lib\tLibrary name for the rootmap file.\n";

   // The Descriptor
   const ROOT::option::Descriptor genreflexUsageDescriptor[] = {
      {
         UNKNOWN,
         NOTYPE,
         "", "",
         ROOT::option::Arg::None,
         genreflexUsage
      },

      {
         OFILENAME,
         STRING ,
         "o" , "output" ,
         ROOT::option::FullArg::Required,
         outputFilenameUsage
      },

      {
         TARGETLIB,
         STRING ,
         "l" , "library" ,
         ROOT::option::FullArg::Required,
         targetLib
      },

      {
         MULTIDICT,
         NOTYPE ,
         "" , "multiDict" ,
         ROOT::option::FullArg::None,
         "--multiDict\tSupport for many dictionaries in one library\n"
         "      Form correct pcm names if multiple dictionaries will be in the same\n"
         "      library (needs target library switch. See its documentation).\n"
      },

      {
         SELECTIONFILENAME,
         STRING ,
         "s" , "selection_file" ,
         ROOT::option::FullArg::Required,
         selectionFilenameUsage
      },

      {
         ROOTMAP,
         STRING ,
         "" , "rootmap" ,
         ROOT::option::FullArg::Required,
         rootmapUsage
      },

      {
         ROOTMAPLIB,
         STRING ,
         "" , "rootmap-lib" ,
         ROOT::option::FullArg::Required,
         rootmapLibUsage
      },

      {
         INTERPRETERONLY,
         NOTYPE,
         "" , "interpreteronly",
         ROOT::option::Arg::None,
         "--interpreteronly\tDo not generate I/O related information.\n"
         "      Generate minimal dictionary required for interactivity.\n"
      },

      {
         SPLIT,
         NOTYPE,
         "" , "split",
         ROOT::option::Arg::None,
         "--split\tSplit the dictionary\n"
         "      Split in two the dictionary, isolating the part with\n"
         "      ClassDef related functions in a separate file.\n"
      },

      {
         PCMFILENAME,
         STRING ,
         "m" , "" ,
         ROOT::option::FullArg::Required,
         "-m \tPcm file loaded before any header (option can be repeated).\n"
      },

      {
         DEEP,  // Not active. Will be removed for 6.2
         NOTYPE ,
         "" , "deep",
         ROOT::option::Arg::None,
         ""
      },
      //"--deep\tGenerate dictionaries for all dependent classes (ignored).\n"

      {
         VERBOSE,
         NOTYPE ,
         "-v" , "verbose",
         ROOT::option::Arg::None,
         "-v, --verbose\tPrint some debug information.\n"
      },

      {
         DEBUG,
         NOTYPE ,
         "" , "debug",
         ROOT::option::Arg::None,
         "--debug\tPrint all debug information.\n"
      },

      {
         QUIET,
         NOTYPE ,
         "" , "quiet",
         ROOT::option::Arg::None,
         "--quiet\tPrint only warnings and errors (default).\n"
      },

      {
         SILENT,
         NOTYPE ,
         "" , "silent",
         ROOT::option::Arg::None,
         "--silent\tPrint no information at all.\n"
      },

      {
         WRITEEMPTYROOTPCM,
         NOTYPE ,
         "" , "writeEmptyPCM",
         ROOT::option::Arg::None,
         "--writeEmptyPCM\tWrite an empty ROOT pcm.\n"
      },

      {
         HELP,
         NOTYPE,
         "h" , "help",
         ROOT::option::Arg::None,
         "--help\tPrint usage and exit.\n"
      },

      {
         FAILONWARNINGS,
         NOTYPE,
         "", "fail_on_warnings",
         ROOT::option::Arg::None,
         "--fail_on_warnings\tFail on warnings and errors.\n"
      },

      {
         SELSYNTAXONLY,
         NOTYPE,
         "", "selSyntaxOnly",
         ROOT::option::Arg::None,
         "--selSyntaxOnly\tValidate selection file w/o generating the dictionary.\n"
      },

      {
         NOINCLUDEPATHS,
         NOTYPE ,
         "" , "noIncludePaths",
         ROOT::option::Arg::None,
         "--noIncludePaths\tDo not store the headers' directories in the dictionary. Instead, rely on the environment variable $ROOT_INCLUDE_PATH at runtime.\n"
      },

      // Left intentionally empty not to be shown in the help, like in the first genreflex
      {
         INCLUDE,
         STRING ,
         "I" , "" ,
         ROOT::option::FullArg::Required,
         ""
      },

      {
         PREPROCDEFINE,
         STRING ,
         "D" , "" ,
         ROOT::option::FullArg::Required,
         ""
      },

      {
         PREPROCUNDEFINE,
         STRING ,
         "U" , "" ,
         ROOT::option::FullArg::Required,
         ""
      },

      {
         WARNING,
         STRING ,
         "W" , "" ,
         ROOT::option::FullArg::Required,
         ""
      },

      {
         NOMEMBERTYPEDEFS, // Option which is not meant for the user: deprecated
         STRING ,
         "" , "no_membertypedefs" ,
         ROOT::option::FullArg::None,
         ""
      },

      {
         NOTEMPLATETYPEDEFS, // Option which is not meant for the user: deprecated
         STRING ,
         "" , "no_templatetypedefs" ,
         ROOT::option::FullArg::None,
         ""
      },

      {0, 0, 0, 0, 0, 0}
   };

   std::vector<std::string> headersNames;
   const int originalArgc = argc;
   // The only args are the headers here
   const int extractedArgs = extractArgs(argc, argv, headersNames);

   const int offset = 1; // skip argv[0]
   argc -= offset + extractedArgs;
   argv += offset;

   // Parse the options
   ROOT::option::Stats  stats(genreflexUsageDescriptor,  argc, argv);
   std::vector<ROOT::option::Option> options(stats.options_max);// non POD var size arrays are not C++!
   std::vector<ROOT::option::Option> buffer(stats.buffer_max);
   // The 4 is the minimum size of the abbreviation lenght.
   // For example, --selction_file can be abbreviated with --sele at least.

   ROOT::option::Parser parse(genreflexUsageDescriptor, argc, argv, &options[0], &buffer[0], 5);

   if (parse.error()) {
      ROOT::TMetaUtils::Error(0, "Argument parsing error!\n");
      return 1;
   }

   // Print help if needed
   if (options[HELP] || originalArgc == 1) {
      ROOT::option::printUsage(std::cout, genreflexUsageDescriptor);
      return 0;
   }
   // See if no header was provided
   int numberOfHeaders = checkHeadersNames(headersNames);
   if (0 == numberOfHeaders) {
      ROOT::TMetaUtils::Error(0, "No valid header was provided!\n");
      return 1;
   }

   ROOT::TMetaUtils::GetErrorIgnoreLevel() = ROOT::TMetaUtils::kNote;

   // The verbosity: debug wins over quiet
   //std::string verbosityOption("-v4"); // To be uncommented for the testing phase. It should be -v
   std::string verbosityOption("-v2");
   if (options[SILENT]) verbosityOption = "-v0";
   if (options[VERBOSE] || getenv ("VERBOSE")) verbosityOption = "-v3";
   if (options[DEBUG]) verbosityOption = "-v4";

   genreflex::verbose = verbosityOption == "-v4";

   // The selection file
   std::string selectionFileName;
   if (options[SELECTIONFILENAME]) {
      selectionFileName = options[SELECTIONFILENAME].arg;
      if (!ROOT::TMetaUtils::EndsWith(selectionFileName, ".xml")) {
         ROOT::TMetaUtils::Error(0,
                                 "Invalid selection file extension: filename is %s and extension .xml is expected!\n",
                                 selectionFileName.c_str());
         return 1;
      }
   }

//    // Warn if a selection file is not present and exit
//    if (NULL==options[SELECTIONFILENAME].arg){
//       ROOT::TMetaUtils::Warning(0,"The usage of genreflex without a selection file is not yet supported.\n");
//       return 1;
//    }


   // Set the parameters for the rootmap file. If the libname is not set,
   // it will be set according to the header in invokeRootCling.
   // FIXME: treatment of directories
   std::string rootmapFileName(options[ROOTMAP].arg ? options[ROOTMAP].arg : "");
   std::string rootmapLibName(options[ROOTMAPLIB].arg ? options[ROOTMAPLIB].arg : "");

   // The target lib name
   std::string targetLibName;
   if (options[TARGETLIB]) {
      targetLibName = options[TARGETLIB].arg;
      if (!IsGoodLibraryName(targetLibName)) {
         ROOT::TMetaUtils::Error("",
                                 "Invalid target library extension: filename is %s and extension %s is expected!\n",
                                 targetLibName.c_str(),
                                 gLibraryExtension.c_str());
      }
      // Target lib has precedence over rootmap lib
      if (options[ROOTMAP]) {
         rootmapLibName = ExtractFileName(options[TARGETLIB].arg);
      }
   }

   bool multidict = false;
   if (options[MULTIDICT]) multidict = true;

   if (multidict && targetLibName.empty()) {
      ROOT::TMetaUtils::Error("",
                              "Multilib support is requested but no target lib is specified. A sane pcm name cannot be formed.\n");
      return 1;
   }

   bool interpreteronly = false;
   if (options[INTERPRETERONLY])
      interpreteronly = true;

   bool doSplit = false;
   if (options[SPLIT])
      doSplit = true;

   bool writeEmptyRootPCM = false;
   if (options[WRITEEMPTYROOTPCM])
      writeEmptyRootPCM = true;

   bool selSyntaxOnly = false;
   if (options[SELSYNTAXONLY]) {
      selSyntaxOnly = true;
   }

   bool noIncludePaths = false;
   if (options[NOINCLUDEPATHS]) {
      noIncludePaths = true;
   }

   bool failOnWarnings = false;
   if (options[FAILONWARNINGS]) {
      failOnWarnings = true;
   }

   // Add the .so extension to the rootmap lib if not there
   if (!rootmapLibName.empty() && !IsGoodLibraryName(rootmapLibName)) {
      rootmapLibName += gLibraryExtension;
   }

   // The list of pcms to be preloaded
   std::vector<std::string> pcmsNames;
   extractMultipleOptions(options, PCMFILENAME, pcmsNames);

   // Preprocessor defines
   std::vector<std::string> preprocDefines;
   extractMultipleOptions(options, PREPROCDEFINE, preprocDefines);

   // Preprocessor undefines
   std::vector<std::string> preprocUndefines;
   extractMultipleOptions(options, PREPROCUNDEFINE, preprocUndefines);

   // Includes
   std::vector<std::string> includes;
   extractMultipleOptions(options, INCLUDE, includes);

   // Warnings
   std::vector<std::string> warnings;
   extractMultipleOptions(options, WARNING, warnings);

   // The outputfilename(s)
   // There are two cases:
   // 1) The outputfilename is specified
   //   -->  The information of all headers will be in one single dictionary
   //     (1 call to rootcling)
   // 2) The outputfilename is not specified
   //   --> There will be a dictionary per header
   //     (N calls to rootcling)
   int returnValue = 0;
   std::string ofileName(options[OFILENAME] ? options[OFILENAME].arg : "");

   // Now check if the --deep option was selected
   bool isDeep = false; //options[DEEP];

   // If not empty and not a directory (therefore it's a file)
   // call rootcling directly. The number of headers files is irrelevant.
   if (!ofileName.empty() && !llvm::sys::fs::is_directory(ofileName)) {
      returnValue = invokeRootCling(verbosityOption,
                                    selectionFileName,
                                    targetLibName,
                                    multidict,
                                    pcmsNames,
                                    includes,
                                    preprocDefines,
                                    preprocUndefines,
                                    warnings,
                                    rootmapFileName,
                                    rootmapLibName,
                                    interpreteronly,
                                    doSplit,
                                    isDeep,
                                    writeEmptyRootPCM,
                                    selSyntaxOnly,
                                    noIncludePaths,
                                    headersNames,
                                    failOnWarnings,
                                    ofileName);
   } else {
      // Here ofilename is either "" or a directory: this is irrelevant.
      returnValue = invokeManyRootCling(verbosityOption,
                                        selectionFileName,
                                        targetLibName,
                                        multidict,
                                        pcmsNames,
                                        includes,
                                        preprocDefines,
                                        preprocUndefines,
                                        warnings,
                                        rootmapFileName,
                                        rootmapLibName,
                                        interpreteronly,
                                        doSplit,
                                        isDeep,
                                        writeEmptyRootPCM,
                                        selSyntaxOnly,
                                        noIncludePaths,
                                        headersNames,
                                        failOnWarnings,
                                        ofileName);
   }

   return returnValue;
}


////////////////////////////////////////////////////////////////////////////////

extern "C"
int ROOT_rootcling_Driver(int argc, char **argv, const ROOT::Internal::RootCling::DriverConfig& config)
{

   assert(!gDriverConfig && "Driver configuration already set!");
   gDriverConfig = &config;

   gBuildingROOT = config.fBuildingROOTStage1; // gets refined later

   std::string exeName = ExtractFileName(GetExePath());

   // Select according to the name of the executable the procedure to follow:
   // 1) RootCling
   // 2) GenReflex
   // The default is rootcling

   int retVal = 0;

   if (std::string::npos != exeName.find("rootcling")) {
      retVal = RootClingMain(argc, argv);
   } else if (std::string::npos != exeName.find("genreflex")) {
      retVal = GenReflexMain(argc, argv);
   } else { //default
      retVal = RootClingMain(argc, argv);
   }

   gDriverConfig = nullptr;

   auto nerrors = ROOT::TMetaUtils::GetNumberOfWarningsAndErrors();
   if (nerrors > 0){
      ROOT::TMetaUtils::Info(0,"Problems have been detected during the generation of the dictionary.\n");
      return 1;
   }
   return retVal;
}