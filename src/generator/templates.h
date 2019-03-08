/*
 * MIT License
 *
 * Copyright (c) 2019 Alexey Edelev <semlanik@gmail.com>, Tatyana Borisova <tanusshhka@mail.ru>
 *
 * This file is part of qtprotobuf project https://git.semlanik.org/semlanik/qtprotobuf
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify,
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and
 * to permit persons to whom the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include <unordered_map>
#include <string>
#include <google/protobuf/descriptor.h>

namespace qtprotobuf {

static const char *PreambleTemplate = "/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */\n\n"
                                      "#pragma once\n\n"
                                      "#include <QObject>\n"
                                      "#include <protobufobject.h>\n"
                                      "#include <unordered_map>\n\n";

static const char *InternalIncludeTemplate =  "#include \"$type_lower$.h\"\n";
static const char *ExternalIncludeTemplate = "#include <$type$>\n";
static const char *ListModelsIncludeTemplate = "#include <QList>\n";

static const char *UsingQtPeotobufNamespaceTemplate = "\nusing namespace qtprotobuf;\n";
static const char *NamespaceTemplate = "\nnamespace $namespace$ {\n";

static const char *NonProtoClassDefinitionTemplate = "\nclass $classname$ : public QObject\n"
                                                     "{\n"
                                                     "    Q_OBJECT\n";
static const char *ClassDefinitionTemplate = "\nclass $classname$ : public ProtobufObject<$classname$>\n"
                                             "{\n"
                                             "    Q_OBJECT\n";

static const char *PropertyTemplate = "Q_PROPERTY($type$ $property_name$ READ $property_name$ WRITE set$property_name_cap$ NOTIFY $property_name$Changed)\n";
static const char *MessagePropertyTemplate = "Q_PROPERTY($type$ $property_name$ READ $property_name$ WRITE set$property_name_cap$ NOTIFY $property_name$Changed)\n";
static const char *MemberTemplate = "$type$ m_$property_name$;\n";
static const char *PublicBlockTemplate = "\npublic:\n";
static const char *EnumDefinitionTemplate = "enum $enum$ {\n";
static const char *EnumFieldTemplate = "$enumvalue$ = $value$,\n";
static const char *ConstructorTemplate = "$classname$(QObject *parent = nullptr) : ProtobufObject(parent)\n";
static const char *CopyConstructorTemplate = "$classname$(const $classname$ &other) : ProtobufObject() {\n";
static const char *MoveConstructorTemplate = "$classname$($classname$ &&other) : ProtobufObject() {\n";
static const char *CopyFieldTemplate = "m_$property_name$ = other.m_$property_name$;\n";
static const char *MoveComplexFieldTemplate = "m_$property_name$ = std::move(other.m_$property_name$);\n";
static const char *MoveFieldTemplate = "m_$property_name$ = std::exchange(other.m_$property_name$, 0);\n";
static const char *AssignmentOperatorTemplate = "$classname$ &operator =(const $classname$ &other) {\n";
static const char *AssignmentOperatorReturnTemplate = "return *this;\n";
static const char *MoveAssignmentOperatorTemplate = "$classname$ &operator =($classname$ &&other) {\n";
static const char *EqualOperatorTemplate = "bool operator ==(const $type$ &other) const {\n"
                                           "    return ";
static const char *EqualOperatorPropertyTemplate = "m_$property_name$ == other.m_$property_name$";
static const char *NotEqualOperatorTemplate = "bool operator !=(const $type$ &other) const {\n"
                                              "    return !this->operator ==(other);\n"
                                              "}\n\n";

static const char *GetterTemplate = "$type$ $property_name$() const {\n"
                                    "    return m_$property_name$;\n"
                                    "}\n\n";

static const char *SetterTemplateSimpleType = "void set$property_name_cap$($type$ $property_name$) {\n"
                                              "    if (m_$property_name$ != $property_name$) {\n"
                                              "        m_$property_name$ = $property_name$;\n"
                                              "        $property_name$Changed();\n"
                                              "    }\n"
                                              "}\n\n";

static const char *SetterTemplateComplexType = "void set$property_name_cap$(const $type$ &$property_name$) {\n"
                                               "    if (m_$property_name$ != $property_name$) {\n"
                                               "        m_$property_name$ = $property_name$;\n"
                                               "        $property_name$Changed();\n"
                                               "    }\n"
                                               "}\n\n";

static const char *SignalsBlockTemplate = "\nsignals:\n";
static const char *SignalTemplate = "void $property_name$Changed();\n";

static const char *FieldsOrderingDefinitionContainerTemplate = "static const std::unordered_map<int/*field number*/, int/*property number*/> propertyOrdering;\n";

static const char *FieldsOrderingContainerTemplate = "const std::unordered_map<int, int> $type$::propertyOrdering = {";
static const char *FieldOrderTemplate = "{$field_number$,$property_number$}";

static const char *EnumTemplate = "$type$";

static const char *SimpleBlockEnclosureTemplate = "}\n\n";
static const char *SemicolonBlockEnclosureTemplate = "};\n";
static const char *EmptyBlockTemplate = "{}\n\n";

static const char *DeclareMetaTypeTemplate = "#include <QMetaType>\n"
                                             "Q_DECLARE_METATYPE($namespaces$::$type$)\n";


static const std::unordered_map<::google::protobuf::FieldDescriptor::Type, std::string> TypeReflection = {
    {::google::protobuf::FieldDescriptor::TYPE_DOUBLE, "double"},
    {::google::protobuf::FieldDescriptor::TYPE_FLOAT, "float"},
    //        {FieldDescriptor::TYPE_INT64, "int"},//Not supported see https://doc.qt.io/qt-5/qtqml-typesystem-basictypes.html
    //        {FieldDescriptor::TYPE_UINT64,"int"},//Not supported see https://doc.qt.io/qt-5/qtqml-typesystem-basictypes.html
    {::google::protobuf::FieldDescriptor::TYPE_INT32, "int"},
    {::google::protobuf::FieldDescriptor::TYPE_FIXED64, "FixedInt64"},
    {::google::protobuf::FieldDescriptor::TYPE_FIXED32, "FixedInt32"},
    {::google::protobuf::FieldDescriptor::TYPE_BOOL, "bool"},
    {::google::protobuf::FieldDescriptor::TYPE_STRING, "QString"},
    {::google::protobuf::FieldDescriptor::TYPE_GROUP, ""},//Not supported and deprecated in protobuf
    //    {FieldDescriptor::TYPE_MESSAGE, ""},//Custom typename
    {::google::protobuf::FieldDescriptor::TYPE_BYTES, "QByteArray"},
    {::google::protobuf::FieldDescriptor::TYPE_UINT32, "int"},//Limited usage see https://doc.qt.io/qt-5/qtqml-typesystem-basictypes.html
    //    {FieldDescriptor::TYPE_ENUM, ""},//Custom typename
    {::google::protobuf::FieldDescriptor::TYPE_SFIXED32, "int"},
    //        {FieldDescriptor::TYPE_SFIXED64, "int"},//Not supported see https://doc.qt.io/qt-5/qtqml-typesystem-basictypes.html
    {::google::protobuf::FieldDescriptor::TYPE_SINT32, "int"},
    //        {FieldDescriptor::TYPE_SINT64, "int"},//Not supported see https://doc.qt.io/qt-5/qtqml-typesystem-basictypes.html
};

}
