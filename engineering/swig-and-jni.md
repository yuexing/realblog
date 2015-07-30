# Swig and JNI

## JNI

- nice articles:

[JNI tutorial](http://www.ibm.com/developerworks/java/tutorials/j-jni/j-jni.html)

[Best practices for using JNI](https://www.ibm.com/developerworks/library/j-jni/)

	- Java calls C: the 'native' function has to follow the convention
	- C calls Java: get the jvm, jenv, then find and invoke


Limit:

<pre>
	The simulator is limited to 2,000 grefs; hardware to about 52,000
</pre>

## Swig

- find out the where're the predefined '.i' files

<pre> swig -swiglib </pre>

- typename convention

<pre>
	%typemap(method [, modifiers]) typelist code ;

	typepattern :  type [ (parms) ]
            |  type name [ (parms) ]
            |  ( typelist ) [ (parms) ]
</pre>

for example:

<pre>
	%typemap(in) const std::string * (std::string temp), std::string * (std::string temp)
</pre>

- define function to avoid code bloat

<pre>
%{
static float *
convert_float_array(PyObject *input, int size) {...}
%}

%typemap(in) float [ANY] {
    $1 = convert_float_array($input, $1_dim0);
    if (!$1) return NULL;
}
</pre>

- types


java i[nter]m[ediate] class (params: jstype, arg: javain, return: javaout) -> jni java declaration (param: jtype) -> jni cpp implementation (param: jni, arg: in, return: out)

<pre>
	/* Get return types */
    if ((tm = Swig_typemap_lookup("jni", n, "", 0))) {
      Printf(c_return_type, "%s", tm);
    } else {
      Swig_warning(WARN_JAVA_TYPEMAP_JNI_UNDEF, input_file, line_number, "No jni typemap defined for %s\n", SwigType_str(t, 0));
    }

    if ((tm = Swig_typemap_lookup("jtype", n, "", 0))) {
      Printf(im_return_type, "%s", tm);
    } else {
      Swig_warning(WARN_JAVA_TYPEMAP_JTYPE_UNDEF, input_file, line_number, "No jtype typemap defined for %s\n", SwigType_str(t, 0));
    }


    /* Get the JNI C types of the parameter */
    if ((tm = Getattr(p, "tmap:jni"))) {
      Printv(c_param_type, tm, NIL);
    } else {
      Swig_warning(WARN_JAVA_TYPEMAP_JNI_UNDEF, input_file, line_number, "No jni typemap defined for %s\n", SwigType_str(pt, 0));
    }

    /* Get the intermediary class parameter types of the parameter */
    if ((tm = Getattr(p, "tmap:jtype"))) {
     Printv(im_param_type, tm, NIL);
    } else {
     Swig_warning(WARN_JAVA_TYPEMAP_JTYPE_UNDEF, input_file, line_number, "No jtype typemap defined for %s\n", SwigType_str(pt, 0));
    }

    // Get typemap for this argument
    if ((tm = Getattr(p, "tmap:in"))) {
     ...

    /* Insert constraint checking code */
    for (p = l; p;) {
      if ((tm = Getattr(p, "tmap:check"))) {
      ...

   	/* Insert cleanup code */
   	for (p = l; p;) {
      if ((tm = Getattr(p, "tmap:freearg"))) {
      ...

    /* Insert argument output code */
    for (p = l; p;) {
      if ((tm = Getattr(p, "tmap:argout"))) {
        addThrows(n, "tmap:argout", p);
        ...

    // Get any Java exception classes in the throws typemap
    if ((throw_parm_list = Getattr(n, "catchlist"))) {
      Swig_typemap_attach_parms("throws", throw_parm_list, f);

    /* Return value if necessary  */
    if ((tm = Swig_typemap_lookup_out("out", n, Swig_cresult_name(), f, actioncode))) {
       addThrows(n, "tmap:out", n);

    /* Get the Java parameter type */
    if ((tm = Getattr(p, "tmap:jstype"))) {

    // Use typemaps to transform type used in Java proxy wrapper (in proxy class) to type used in JNI function (in intermediary class)
    if ((tm = Getattr(p, "tmap:javain"))) {
        addThrows(n, "tmap:javain", p);

    // Transform return type used in JNI function (in intermediary class) to type used in Java wrapper function (in proxy class)
    if ((tm = Swig_typemap_lookup("javaout", n, "", 0))) {
      addThrows(n, "tmap:javaout", n);

    // 
</pre>