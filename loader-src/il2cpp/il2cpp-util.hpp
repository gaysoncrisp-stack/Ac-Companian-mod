// inspired by BNM-Android's systems 
#include <stdint.h>
#include <cstddef>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <thread>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>
#include <mach-o/dyld.h>
#import <Foundation/Foundation.h>

#include "../il2cpp/il2cpp-types.h"
#include "KittyMemory.hpp"
#include "KittyUtils.hpp"
#include "KittyInclude.hpp"
#include <dobby.h>


#include <string>
#include <locale>
#include <codecvt>
#include <sstream>
#include <dlfcn.h>

namespace il2cpp_util {
    namespace internal {
        namespace methods {
            int(*il2cpp_init)(const char* domain_name);
            int(*il2cpp_init_utf16)(const Il2CppChar * domain_name);
            void(*il2cpp_shutdown)();
            void(*il2cpp_set_config_dir)(const char *config_path);
            void(*il2cpp_set_data_dir)(const char *data_path);
            void(*il2cpp_set_temp_dir)(const char *temp_path);
            void(*il2cpp_set_commandline_arguments)(int argc, const char* const argv[], const char* basedir);
            void(*il2cpp_set_commandline_arguments_utf16)(int argc, const Il2CppChar * const argv[], const char* basedir);
            void(*il2cpp_set_config_utf16)(const Il2CppChar * executablePath);
            void(*il2cpp_set_config)(const char* executablePath);
            void(*il2cpp_set_memory_callbacks)(Il2CppMemoryCallbacks * callbacks);
            const Il2CppImage*(*il2cpp_get_corlib)();
            void(*il2cpp_add_internal_call)(const char* name, Il2CppMethodPointer method);
            Il2CppMethodPointer(*il2cpp_resolve_icall)(const char* name);
            void*(*il2cpp_alloc)(size_t size);
            void(*il2cpp_free)(void* ptr);
            Il2CppClass*(*il2cpp_array_class_get)(Il2CppClass * element_class, uint32_t rank);
            uint32_t(*il2cpp_array_length)(Il2CppArray * array);
            uint32_t(*il2cpp_array_get_byte_length)(Il2CppArray * array);
            Il2CppArray*(*il2cpp_array_new)(Il2CppClass * elementTypeInfo, il2cpp_array_size_t length);
            Il2CppArray*(*il2cpp_array_new_specific)(Il2CppClass * arrayTypeInfo, il2cpp_array_size_t length);
            Il2CppArray*(*il2cpp_array_new_full)(Il2CppClass * array_class, il2cpp_array_size_t * lengths, il2cpp_array_size_t * lower_bounds);
            Il2CppClass*(*il2cpp_bounded_array_class_get)(Il2CppClass * element_class, uint32_t rank, bool bounded);
            int(*il2cpp_array_element_size)(const Il2CppClass * array_class);
            const Il2CppImage*(*il2cpp_assembly_get_image)(const Il2CppAssembly * assembly);
            void(*il2cpp_class_for_each)(void(*klassReportFunc)(Il2CppClass* klass, void* userData), void* userData);
            const Il2CppType*(*il2cpp_class_enum_basetype)(Il2CppClass * klass);
            bool(*il2cpp_class_is_generic)(const Il2CppClass * klass);
            bool(*il2cpp_class_is_inflated)(const Il2CppClass * klass);
            bool(*il2cpp_class_is_assignable_from)(Il2CppClass * klass, Il2CppClass * oklass);
            bool(*il2cpp_class_is_subclass_of)(Il2CppClass * klass, Il2CppClass * klassc, bool check_interfaces);
            bool(*il2cpp_class_has_parent)(Il2CppClass * klass, Il2CppClass * klassc);
            Il2CppClass*(*il2cpp_class_from_il2cpp_type)(const Il2CppType * type);
            Il2CppClass*(*il2cpp_class_from_name)(const Il2CppImage * image, const char* namespaze, const char *name);
            Il2CppClass*(*il2cpp_class_from_system_type)(Il2CppReflectionType * type);
            Il2CppClass*(*il2cpp_class_get_element_class)(Il2CppClass * klass);
            const EventInfo*(*il2cpp_class_get_events)(Il2CppClass * klass, void* *iter);
            FieldInfo*(*il2cpp_class_get_fields)(Il2CppClass * klass, void* *iter);
            Il2CppClass*(*il2cpp_class_get_nested_types)(Il2CppClass * klass, void* *iter);
            Il2CppClass*(*il2cpp_class_get_interfaces)(Il2CppClass * klass, void* *iter);
            const PropertyInfo*(*il2cpp_class_get_properties)(Il2CppClass * klass, void* *iter);
            const PropertyInfo*(*il2cpp_class_get_property_from_name)(Il2CppClass * klass, const char *name);
            FieldInfo*(*il2cpp_class_get_field_from_name)(Il2CppClass * klass, const char *name);
            const MethodInfo*(*il2cpp_class_get_methods)(Il2CppClass * klass, void* *iter);
            const MethodInfo*(*il2cpp_class_get_method_from_name)(Il2CppClass * klass, const char* name, int argsCount);
            const char*(*il2cpp_class_get_name)(Il2CppClass * klass);
            void(*il2cpp_type_get_name_chunked)(const Il2CppType * type, void(*chunkReportFunc)(void* data, void* userData), void* userData);
            const char*(*il2cpp_class_get_namespace)(Il2CppClass * klass);
            Il2CppClass*(*il2cpp_class_get_parent)(Il2CppClass * klass);
            Il2CppClass*(*il2cpp_class_get_declaring_type)(Il2CppClass * klass);
            int32_t(*il2cpp_class_instance_size)(Il2CppClass * klass);
            size_t(*il2cpp_class_num_fields)(const Il2CppClass * enumKlass);
            bool(*il2cpp_class_is_valuetype)(const Il2CppClass * klass);
            int32_t(*il2cpp_class_value_size)(Il2CppClass * klass, uint32_t * align);
            bool(*il2cpp_class_is_blittable)(const Il2CppClass * klass);
            int(*il2cpp_class_get_flags)(const Il2CppClass * klass);
            bool(*il2cpp_class_is_abstract)(const Il2CppClass * klass);
            bool(*il2cpp_class_is_interface)(const Il2CppClass * klass);
            int(*il2cpp_class_array_element_size)(const Il2CppClass * klass);
            Il2CppClass*(*il2cpp_class_from_type)(const Il2CppType * type);
            const Il2CppType*(*il2cpp_class_get_type)(Il2CppClass * klass);
            uint32_t(*il2cpp_class_get_type_token)(Il2CppClass * klass);
            bool(*il2cpp_class_has_attribute)(Il2CppClass * klass, Il2CppClass * attr_class);
            bool(*il2cpp_class_has_references)(Il2CppClass * klass);
            bool(*il2cpp_class_is_enum)(const Il2CppClass * klass);
            const Il2CppImage*(*il2cpp_class_get_image)(Il2CppClass * klass);
            const char*(*il2cpp_class_get_assemblyname)(const Il2CppClass * klass);
            int(*il2cpp_class_get_rank)(const Il2CppClass * klass);
            uint32_t(*il2cpp_class_get_data_size)(const Il2CppClass * klass);
            void*(*il2cpp_class_get_static_field_data)(const Il2CppClass * klass);
            size_t(*il2cpp_class_get_bitmap_size)(const Il2CppClass * klass);
            void(*il2cpp_class_get_bitmap)(Il2CppClass * klass, size_t * bitmap);
            bool(*il2cpp_stats_dump_to_file)(const char *path);
            uint64_t(*il2cpp_stats_get_value)(Il2CppStat stat);
            Il2CppDomain*(*il2cpp_domain_get)();
            const Il2CppAssembly*(*il2cpp_domain_assembly_open)(Il2CppDomain * domain, const char* name);
            const Il2CppAssembly**(*il2cpp_domain_get_assemblies)(const Il2CppDomain * domain, size_t * size);
            Il2CppException*(*il2cpp_exception_from_name_msg)(const Il2CppImage * image, const char *name_space, const char *name, const char *msg);
            Il2CppException*(*il2cpp_get_exception_argument_null)(const char *arg);
            void(*il2cpp_format_exception)(const Il2CppException * ex, char* message, int message_size);
            void(*il2cpp_format_stack_trace)(const Il2CppException * ex, char* output, int output_size);
            void(*il2cpp_unhandled_exception)(Il2CppException*);
            void(*il2cpp_native_stack_trace)(const Il2CppException * ex, uintptr_t** addresses, int* numFrames, char** imageUUID, char** imageName);
            int(*il2cpp_field_get_flags)(FieldInfo * field);
            const char*(*il2cpp_field_get_name)(FieldInfo * field);
            Il2CppClass*(*il2cpp_field_get_parent)(FieldInfo * field);
            size_t(*il2cpp_field_get_offset)(FieldInfo * field);
            const Il2CppType*(*il2cpp_field_get_type)(FieldInfo * field);
            void(*il2cpp_field_get_value)(Il2CppObject * obj, FieldInfo * field, void *value);
            Il2CppObject*(*il2cpp_field_get_value_object)(FieldInfo * field, Il2CppObject * obj);
            bool(*il2cpp_field_has_attribute)(FieldInfo * field, Il2CppClass * attr_class);
            void(*il2cpp_field_set_value)(Il2CppObject * obj, FieldInfo * field, void *value);
            void(*il2cpp_field_static_get_value)(FieldInfo * field, void *value);
            void(*il2cpp_field_static_set_value)(FieldInfo * field, void *value);
            void(*il2cpp_field_set_value_object)(Il2CppObject * instance, FieldInfo * field, Il2CppObject * value);
            bool(*il2cpp_field_is_literal)(FieldInfo * field);
            void(*il2cpp_gc_collect)(int maxGenerations);
            int32_t(*il2cpp_gc_collect_a_little)();
            void(*il2cpp_gc_start_incremental_collection)();
            void(*il2cpp_gc_disable)();
            void(*il2cpp_gc_enable)();
            bool(*il2cpp_gc_is_disabled)();
            void(*il2cpp_gc_set_mode)(Il2CppGCMode mode);
            int64_t(*il2cpp_gc_get_max_time_slice_ns)();
            void(*il2cpp_gc_set_max_time_slice_ns)(int64_t maxTimeSlice);
            bool(*il2cpp_gc_is_incremental)();
            int64_t(*il2cpp_gc_get_used_size)();
            int64_t(*il2cpp_gc_get_heap_size)();
            void(*il2cpp_gc_wbarrier_set_field)(Il2CppObject * obj, void **targetAddress, void *object);
            bool(*il2cpp_gc_has_strict_wbarriers)();
            void(*il2cpp_gc_set_external_allocation_tracker)(void(*func)(void*, size_t, int));
            void(*il2cpp_gc_set_external_wbarrier_tracker)(void(*func)(void**));
            void(*il2cpp_gc_foreach_heap)(void(*func)(void* data, void* userData), void* userData);
            void(*il2cpp_stop_gc_world)();
            void(*il2cpp_start_gc_world)();
            void*(*il2cpp_gc_alloc_fixed)(size_t size);
            void(*il2cpp_gc_free_fixed)(void* address);
            uint32_t(*il2cpp_gchandle_new)(Il2CppObject * obj, bool pinned);
            uint32_t(*il2cpp_gchandle_new_weakref)(Il2CppObject * obj, bool track_resurrection);
            Il2CppObject*(*il2cpp_gchandle_get_target)(uint32_t gchandle);
            void(*il2cpp_gchandle_free)(uint32_t gchandle);
            void(*il2cpp_gchandle_foreach_get_target)(void(*func)(void* data, void* userData), void* userData);
            uint32_t(*il2cpp_object_header_size)();
            uint32_t(*il2cpp_array_object_header_size)();
            uint32_t(*il2cpp_offset_of_array_length_in_array_object_header)();
            uint32_t(*il2cpp_offset_of_array_bounds_in_array_object_header)();
            uint32_t(*il2cpp_allocation_granularity)();
            void*(*il2cpp_unity_liveness_allocate_struct)(Il2CppClass * filter, int max_object_count, il2cpp_register_object_callback callback, void* userdata, il2cpp_liveness_reallocate_callback reallocate);
            void(*il2cpp_unity_liveness_calculation_from_root)(Il2CppObject * root, void* state);
            void(*il2cpp_unity_liveness_calculation_from_statics)(void* state);
            void(*il2cpp_unity_liveness_finalize)(void* state);
            void(*il2cpp_unity_liveness_free_struct)(void* state);
            const Il2CppType*(*il2cpp_method_get_return_type)(const MethodInfo * method);
            Il2CppClass*(*il2cpp_method_get_declaring_type)(const MethodInfo * method);
            const char*(*il2cpp_method_get_name)(const MethodInfo * method);
            const MethodInfo*(*il2cpp_method_get_from_reflection)(const Il2CppReflectionMethod * method);
            Il2CppReflectionMethod*(*il2cpp_method_get_object)(const MethodInfo * method, Il2CppClass * refclass);
            bool(*il2cpp_method_is_generic)(const MethodInfo * method);
            bool(*il2cpp_method_is_inflated)(const MethodInfo * method);
            bool(*il2cpp_method_is_instance)(const MethodInfo * method);
            uint32_t(*il2cpp_method_get_param_count)(const MethodInfo * method);
            const Il2CppType*(*il2cpp_method_get_param)(const MethodInfo * method, uint32_t index);
            Il2CppClass*(*il2cpp_method_get_class)(const MethodInfo * method);
            bool(*il2cpp_method_has_attribute)(const MethodInfo * method, Il2CppClass * attr_class);
            uint32_t(*il2cpp_method_get_flags)(const MethodInfo * method, uint32_t * iflags);
            uint32_t(*il2cpp_method_get_token)(const MethodInfo * method);
            const char*(*il2cpp_method_get_param_name)(const MethodInfo * method, uint32_t index);
            uint32_t(*il2cpp_property_get_flags)(PropertyInfo * prop);
            const MethodInfo*(*il2cpp_property_get_get_method)(PropertyInfo * prop);
            const MethodInfo*(*il2cpp_property_get_set_method)(PropertyInfo * prop);
            const char*(*il2cpp_property_get_name)(PropertyInfo * prop);
            Il2CppClass*(*il2cpp_property_get_parent)(PropertyInfo * prop);
            Il2CppClass*(*il2cpp_object_get_class)(Il2CppObject * obj);
            uint32_t(*il2cpp_object_get_size)(Il2CppObject * obj);
            const MethodInfo*(*il2cpp_object_get_virtual_method)(Il2CppObject * obj, const MethodInfo * method);
            Il2CppObject*(*il2cpp_object_new)(const Il2CppClass * klass);
            void*(*il2cpp_object_unbox)(Il2CppObject * obj);
            Il2CppObject*(*il2cpp_value_box)(Il2CppClass * klass, void* data);
            void(*il2cpp_monitor_enter)(Il2CppObject * obj);
            bool(*il2cpp_monitor_try_enter)(Il2CppObject * obj, uint32_t timeout);
            void(*il2cpp_monitor_exit)(Il2CppObject * obj);
            void(*il2cpp_monitor_pulse)(Il2CppObject * obj);
            void(*il2cpp_monitor_pulse_all)(Il2CppObject * obj);
            void(*il2cpp_monitor_wait)(Il2CppObject * obj);
            bool(*il2cpp_monitor_try_wait)(Il2CppObject * obj, uint32_t timeout);
            Il2CppObject*(*il2cpp_runtime_invoke)(const MethodInfo * method, void *obj, void **params, Il2CppException **exc);
            Il2CppObject*(*il2cpp_runtime_invoke_convert_args)(const MethodInfo * method, void *obj, Il2CppObject **params, int paramCount, Il2CppException **exc);
            void(*il2cpp_runtime_class_init)(Il2CppClass * klass);
            void(*il2cpp_runtime_object_init)(Il2CppObject * obj);
            void(*il2cpp_runtime_object_init_exception)(Il2CppObject * obj, Il2CppException** exc);
            void(*il2cpp_runtime_unhandled_exception_policy_set)(Il2CppRuntimeUnhandledExceptionPolicy value);
            int32_t(*il2cpp_string_length)(Il2CppString * str);
            Il2CppChar*(*il2cpp_string_chars)(Il2CppString * str);
            Il2CppString*(*il2cpp_string_new)(const char* str);
            Il2CppString*(*il2cpp_string_new_len)(const char* str, uint32_t length);
            Il2CppString*(*il2cpp_string_new_utf16)(const Il2CppChar * text, int32_t len);
            Il2CppString*(*il2cpp_string_new_wrapper)(const char* str);
            Il2CppString*(*il2cpp_string_intern)(Il2CppString * str);
            Il2CppString*(*il2cpp_string_is_interned)(Il2CppString * str);
            Il2CppThread*(*il2cpp_thread_current)();
            Il2CppThread*(*il2cpp_thread_attach)(Il2CppDomain * domain);
            void(*il2cpp_thread_detach)(Il2CppThread * thread);
            Il2CppThread**(*il2cpp_thread_get_all_attached_threads)(size_t * size);
            bool(*il2cpp_is_vm_thread)(Il2CppThread * thread);
            void(*il2cpp_current_thread_walk_frame_stack)(Il2CppFrameWalkFunc func, void* user_data);
            void(*il2cpp_thread_walk_frame_stack)(Il2CppThread * thread, Il2CppFrameWalkFunc func, void* user_data);
            bool(*il2cpp_current_thread_get_top_frame)(Il2CppStackFrameInfo * frame);
            bool(*il2cpp_thread_get_top_frame)(Il2CppThread * thread, Il2CppStackFrameInfo * frame);
            bool(*il2cpp_current_thread_get_frame_at)(int32_t offset, Il2CppStackFrameInfo * frame);
            bool(*il2cpp_thread_get_frame_at)(Il2CppThread * thread, int32_t offset, Il2CppStackFrameInfo * frame);
            int32_t(*il2cpp_current_thread_get_stack_depth)();
            int32_t(*il2cpp_thread_get_stack_depth)(Il2CppThread * thread);
            void(*il2cpp_override_stack_backtrace)(Il2CppBacktraceFunc stackBacktraceFunc);
            Il2CppObject*(*il2cpp_type_get_object)(const Il2CppType * type);
            int(*il2cpp_type_get_type)(const Il2CppType * type);
            Il2CppClass*(*il2cpp_type_get_class_or_element_class)(const Il2CppType * type);
            char*(*il2cpp_type_get_name)(const Il2CppType * type);
            bool(*il2cpp_type_is_byref)(const Il2CppType * type);
            uint32_t(*il2cpp_type_get_attrs)(const Il2CppType * type);
            bool(*il2cpp_type_equals)(const Il2CppType * type, const Il2CppType * otherType);
            char*(*il2cpp_type_get_assembly_qualified_name)(const Il2CppType * type);
            bool(*il2cpp_type_is_static)(const Il2CppType * type);
            bool(*il2cpp_type_is_pointer_type)(const Il2CppType * type);
            const Il2CppAssembly*(*il2cpp_image_get_assembly)(const Il2CppImage * image);
            const char*(*il2cpp_image_get_name)(const Il2CppImage * image);
            const char*(*il2cpp_image_get_filename)(const Il2CppImage * image);
            const MethodInfo*(*il2cpp_image_get_entry_point)(const Il2CppImage * image);
            size_t(*il2cpp_image_get_class_count)(const Il2CppImage * image);
            const Il2CppClass*(*il2cpp_image_get_class)(const Il2CppImage * image, size_t index);
            Il2CppManagedMemorySnapshot*(*il2cpp_capture_memory_snapshot)();
            void(*il2cpp_free_captured_memory_snapshot)(Il2CppManagedMemorySnapshot * snapshot);
            void(*il2cpp_set_find_plugin_callback)(Il2CppSetFindPlugInCallback method);
            void(*il2cpp_register_log_callback)(Il2CppLogCallback method);
            void(*il2cpp_debugger_set_agent_options)(const char* options);
            bool(*il2cpp_is_debugger_attached)();
            void(*il2cpp_register_debugger_agent_transport)(Il2CppDebuggerTransport * debuggerTransport);
            bool(*il2cpp_debug_get_method_info)(const MethodInfo*, Il2CppMethodDebugInfo * methodDebugInfo);
            void(*il2cpp_unity_install_unitytls_interface)(const void* unitytlsInterfaceStruct);
            Il2CppCustomAttrInfo*(*il2cpp_custom_attrs_from_class)(Il2CppClass * klass);
            Il2CppCustomAttrInfo*(*il2cpp_custom_attrs_from_method)(const MethodInfo * method);
            Il2CppObject*(*il2cpp_custom_attrs_get_attr)(Il2CppCustomAttrInfo * ainfo, Il2CppClass * attr_klass);
            bool(*il2cpp_custom_attrs_has_attr)(Il2CppCustomAttrInfo * ainfo, Il2CppClass * attr_klass);
            Il2CppArray*(*il2cpp_custom_attrs_construct)(Il2CppCustomAttrInfo * cinfo);
            void(*il2cpp_custom_attrs_free)(Il2CppCustomAttrInfo * ainfo);
            void(*il2cpp_class_set_userdata)(Il2CppClass * klass, void* userdata);
            int(*il2cpp_class_get_userdata_offset)();
            void(*il2cpp_set_default_thread_affinity)(int64_t affinity_mask);
        }

        std::unordered_map<std::string, std::unordered_map<std::string, Il2CppClass*>> classMap;
        std::unordered_map<std::string, Il2CppImage*> imageMap;
    }

    namespace hooking {
        void HookMethod(MethodInfo* info, void* new_method, void** old_method, bool invoker = false) {
            if (invoker) {
                if (old_method != nullptr) {
                    *old_method = (void*)info->methodPointer;
                }
                info->methodPointer = (Il2CppMethodPointer)new_method;
            } else {
                DobbyHook((void*)info->methodPointer, (void*)new_method, (void**)old_method);
            }
        }
    }

    std::string il2cpp_string_to_std(Il2CppString* str) {
        if (!str) return "";
        auto chars = internal::methods::il2cpp_string_chars(str);
        auto len = internal::methods::il2cpp_string_length(str);
        std::u16string u16(reinterpret_cast<const char16_t*>(chars), len);
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
        return convert.to_bytes(u16);
    }

    struct MethodBase {
        MethodInfo* _data;
        Il2CppObject* _instance;
        MethodBase(MethodInfo* method, Il2CppObject* instance = nullptr) {
            _data = method;
            _instance = instance;
        }
        MethodBase(const MethodInfo* method, Il2CppObject* instance = nullptr) {
            _data = const_cast<MethodInfo*>(method);
            _instance = instance;
        }
    };

    template<typename RET>
    struct Method : public MethodBase {
        using MethodBase::MethodBase;

        template<typename ...Parameters>
        RET Call(Parameters ...parameters) {
            if ((_data->flags & 0x0010) == 0x0010) {
                return reinterpret_cast<RET(*)(Parameters...)>(_data->methodPointer)(parameters...);
            } else {
                if (!_instance) {
                    KITTY_LOGI("[Error] Missing instance. Returning empty");
                    return RET();
                }
                return reinterpret_cast<RET(*)(Il2CppObject*, Parameters...)>(_data->methodPointer)(_instance, parameters...);
            }
        }
    };

    struct Class {
        Il2CppClass* _data;
        Class(Il2CppClass* klass) {
            this->_data = klass;
        }
        Class(std::string namespaze, std::string name) : _data(nullptr) {
            if (internal::classMap.find(namespaze) == internal::classMap.end()) {
                NSLog(@"[Error] Namespace %s doesn't exit in the class map.", namespaze.c_str());
                return;
            }
            if (internal::classMap[namespaze].find(name) == internal::classMap[namespaze].end()) {
                NSLog(@"[Error] Class %s doesn't exit in the class map.", name.c_str());
                return;
            }
            _data = internal::classMap[namespaze][name];
        }

        MethodInfo* GetMethod(std::string name, int argCount = 0) {
            return const_cast<MethodInfo*>(internal::methods::il2cpp_class_get_method_from_name(_data, name.c_str(), argCount));
        }
    };

    void initClasses() {
        auto domain = internal::methods::il2cpp_domain_get();
        size_t size = 0;
        auto assemblies = internal::methods::il2cpp_domain_get_assemblies(domain, &size);

        int okRealClasses = 0;

        for (int i = 0; i < size; ++i) {
            auto assembly = assemblies[i];
            auto image = internal::methods::il2cpp_assembly_get_image(assembly);
            internal::imageMap[std::string(image->name)] = const_cast<Il2CppImage*>(image);

            size_t cc = internal::methods::il2cpp_image_get_class_count(image);
            for (size_t k = 0; k < cc; ++k) {
                okRealClasses++;
                Il2CppClass* klass = const_cast<Il2CppClass*>(internal::methods::il2cpp_image_get_class(image, k));
                internal::classMap[std::string(klass->namespaze)][std::string(klass->name)] = klass;
            }
        }
    }

    void Init(void (*finishCallback)()) {
        std::thread([finishCallback]() {
            MemoryFileInfo framework;
            do
            {
                sleep(1);
                framework = KittyMemory::getMemoryFileInfo("UnityFramework");
            } while (!framework.address);
            
            internal::methods::il2cpp_init = (int(*)(const char* domain_name))KittyScanner::findSymbol(framework, "_il2cpp_init");
            internal::methods::il2cpp_init_utf16 = (int(*)(const Il2CppChar * domain_name))KittyScanner::findSymbol(framework, "_il2cpp_init_utf16");
            internal::methods::il2cpp_shutdown = (void(*)())KittyScanner::findSymbol(framework, "_il2cpp_shutdown");
            internal::methods::il2cpp_set_config_dir = (void(*)(const char *config_path))KittyScanner::findSymbol(framework, "_il2cpp_set_config_dir");
            internal::methods::il2cpp_set_data_dir = (void(*)(const char *data_path))KittyScanner::findSymbol(framework, "_il2cpp_set_data_dir");
            internal::methods::il2cpp_set_temp_dir = (void(*)(const char *temp_path))KittyScanner::findSymbol(framework, "_il2cpp_set_temp_dir");
            internal::methods::il2cpp_set_commandline_arguments = (void(*)(int argc, const char* const argv[], const char* basedir))KittyScanner::findSymbol(framework, "_il2cpp_set_commandline_arguments");
            internal::methods::il2cpp_set_commandline_arguments_utf16 = (void(*)(int argc, const Il2CppChar * const argv[], const char* basedir))KittyScanner::findSymbol(framework, "_il2cpp_set_commandline_arguments_utf16");
            internal::methods::il2cpp_set_config_utf16 = (void(*)(const Il2CppChar * executablePath))KittyScanner::findSymbol(framework, "_il2cpp_set_config_utf16");
            internal::methods::il2cpp_set_config = (void(*)(const char* executablePath))KittyScanner::findSymbol(framework, "_il2cpp_set_config");
            internal::methods::il2cpp_set_memory_callbacks = (void(*)(Il2CppMemoryCallbacks * callbacks))KittyScanner::findSymbol(framework, "_il2cpp_set_memory_callbacks");
            internal::methods::il2cpp_get_corlib = (const Il2CppImage*(*)())KittyScanner::findSymbol(framework, "_il2cpp_get_corlib");
            internal::methods::il2cpp_add_internal_call = (void(*)(const char* name, Il2CppMethodPointer method))KittyScanner::findSymbol(framework, "_il2cpp_add_internal_call");
            internal::methods::il2cpp_resolve_icall = (Il2CppMethodPointer(*)(const char* name))KittyScanner::findSymbol(framework, "_il2cpp_resolve_icall");
            internal::methods::il2cpp_alloc = (void*(*)(size_t size))KittyScanner::findSymbol(framework, "_il2cpp_alloc");
            internal::methods::il2cpp_free = (void(*)(void* ptr))KittyScanner::findSymbol(framework, "_il2cpp_free");
            internal::methods::il2cpp_array_class_get = (Il2CppClass*(*)(Il2CppClass * element_class, uint32_t rank))KittyScanner::findSymbol(framework, "_il2cpp_array_class_get");
            internal::methods::il2cpp_array_length = (uint32_t(*)(Il2CppArray * array))KittyScanner::findSymbol(framework, "_il2cpp_array_length");
            internal::methods::il2cpp_array_get_byte_length = (uint32_t(*)(Il2CppArray * array))KittyScanner::findSymbol(framework, "_il2cpp_array_get_byte_length");
            internal::methods::il2cpp_array_new = (Il2CppArray*(*)(Il2CppClass * elementTypeInfo, il2cpp_array_size_t length))KittyScanner::findSymbol(framework, "_il2cpp_array_new");
            internal::methods::il2cpp_array_new_specific = (Il2CppArray*(*)(Il2CppClass * arrayTypeInfo, il2cpp_array_size_t length))KittyScanner::findSymbol(framework, "_il2cpp_array_new_specific");
            internal::methods::il2cpp_array_new_full = (Il2CppArray*(*)(Il2CppClass * array_class, il2cpp_array_size_t * lengths, il2cpp_array_size_t * lower_bounds))KittyScanner::findSymbol(framework, "_il2cpp_array_new_full");
            internal::methods::il2cpp_bounded_array_class_get = (Il2CppClass*(*)(Il2CppClass * element_class, uint32_t rank, bool bounded))KittyScanner::findSymbol(framework, "_il2cpp_bounded_array_class_get");
            internal::methods::il2cpp_array_element_size = (int(*)(const Il2CppClass * array_class))KittyScanner::findSymbol(framework, "_il2cpp_array_element_size");
            internal::methods::il2cpp_assembly_get_image = (const Il2CppImage*(*)(const Il2CppAssembly * assembly))KittyScanner::findSymbol(framework, "_il2cpp_assembly_get_image");
            internal::methods::il2cpp_class_for_each = (void(*)(void(*klassReportFunc)(Il2CppClass* klass, void* userData), void* userData))KittyScanner::findSymbol(framework, "_il2cpp_class_for_each");
            internal::methods::il2cpp_class_enum_basetype = (const Il2CppType*(*)(Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_enum_basetype");
            internal::methods::il2cpp_class_is_generic = (bool(*)(const Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_is_generic");
            internal::methods::il2cpp_class_is_inflated = (bool(*)(const Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_is_inflated");
            internal::methods::il2cpp_class_is_assignable_from = (bool(*)(Il2CppClass * klass, Il2CppClass * oklass))KittyScanner::findSymbol(framework, "_il2cpp_class_is_assignable_from");
            internal::methods::il2cpp_class_is_subclass_of = (bool(*)(Il2CppClass * klass, Il2CppClass * klassc, bool check_interfaces))KittyScanner::findSymbol(framework, "_il2cpp_class_is_subclass_of");
            internal::methods::il2cpp_class_has_parent = (bool(*)(Il2CppClass * klass, Il2CppClass * klassc))KittyScanner::findSymbol(framework, "_il2cpp_class_has_parent");
            internal::methods::il2cpp_class_from_il2cpp_type = (Il2CppClass*(*)(const Il2CppType * type))KittyScanner::findSymbol(framework, "_il2cpp_class_from_il2cpp_type");
            internal::methods::il2cpp_class_from_name = (Il2CppClass*(*)(const Il2CppImage * image, const char* namespaze, const char *name))KittyScanner::findSymbol(framework, "_il2cpp_class_from_name");
            internal::methods::il2cpp_class_from_system_type = (Il2CppClass*(*)(Il2CppReflectionType * type))KittyScanner::findSymbol(framework, "_il2cpp_class_from_system_type");
            internal::methods::il2cpp_class_get_element_class = (Il2CppClass*(*)(Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_get_element_class");
            internal::methods::il2cpp_class_get_events = (const EventInfo*(*)(Il2CppClass * klass, void* *iter))KittyScanner::findSymbol(framework, "_il2cpp_class_get_events");
            internal::methods::il2cpp_class_get_fields = (FieldInfo*(*)(Il2CppClass * klass, void* *iter))KittyScanner::findSymbol(framework, "_il2cpp_class_get_fields");
            internal::methods::il2cpp_class_get_nested_types = (Il2CppClass*(*)(Il2CppClass * klass, void* *iter))KittyScanner::findSymbol(framework, "_il2cpp_class_get_nested_types");
            internal::methods::il2cpp_class_get_interfaces = (Il2CppClass*(*)(Il2CppClass * klass, void* *iter))KittyScanner::findSymbol(framework, "_il2cpp_class_get_interfaces");
            internal::methods::il2cpp_class_get_properties = (const PropertyInfo*(*)(Il2CppClass * klass, void* *iter))KittyScanner::findSymbol(framework, "_il2cpp_class_get_properties");
            internal::methods::il2cpp_class_get_property_from_name = (const PropertyInfo*(*)(Il2CppClass * klass, const char *name))KittyScanner::findSymbol(framework, "_il2cpp_class_get_property_from_name");
            internal::methods::il2cpp_class_get_field_from_name = (FieldInfo*(*)(Il2CppClass * klass, const char *name))KittyScanner::findSymbol(framework, "_il2cpp_class_get_field_from_name");
            internal::methods::il2cpp_class_get_methods = (const MethodInfo*(*)(Il2CppClass * klass, void* *iter))KittyScanner::findSymbol(framework, "_il2cpp_class_get_methods");
            internal::methods::il2cpp_class_get_method_from_name = (const MethodInfo*(*)(Il2CppClass * klass, const char* name, int argsCount))KittyScanner::findSymbol(framework, "_il2cpp_class_get_method_from_name");
            internal::methods::il2cpp_class_get_name = (const char*(*)(Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_get_name");
            internal::methods::il2cpp_type_get_name_chunked = (void(*)(const Il2CppType * type, void(*chunkReportFunc)(void* data, void* userData), void* userData))KittyScanner::findSymbol(framework, "_il2cpp_type_get_name_chunked");
            internal::methods::il2cpp_class_get_namespace = (const char*(*)(Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_get_namespace");
            internal::methods::il2cpp_class_get_parent = (Il2CppClass*(*)(Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_get_parent");
            internal::methods::il2cpp_class_get_declaring_type = (Il2CppClass*(*)(Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_get_declaring_type");
            internal::methods::il2cpp_class_instance_size = (int32_t(*)(Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_instance_size");
            internal::methods::il2cpp_class_num_fields = (size_t(*)(const Il2CppClass * enumKlass))KittyScanner::findSymbol(framework, "_il2cpp_class_num_fields");
            internal::methods::il2cpp_class_is_valuetype = (bool(*)(const Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_is_valuetype");
            internal::methods::il2cpp_class_value_size = (int32_t(*)(Il2CppClass * klass, uint32_t * align))KittyScanner::findSymbol(framework, "_il2cpp_class_value_size");
            internal::methods::il2cpp_class_is_blittable = (bool(*)(const Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_is_blittable");
            internal::methods::il2cpp_class_get_flags = (int(*)(const Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_get_flags");
            internal::methods::il2cpp_class_is_abstract = (bool(*)(const Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_is_abstract");
            internal::methods::il2cpp_class_is_interface = (bool(*)(const Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_is_interface");
            internal::methods::il2cpp_class_array_element_size = (int(*)(const Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_array_element_size");
            internal::methods::il2cpp_class_from_type = (Il2CppClass*(*)(const Il2CppType * type))KittyScanner::findSymbol(framework, "_il2cpp_class_from_type");
            internal::methods::il2cpp_class_get_type = (const Il2CppType*(*)(Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_get_type");
            internal::methods::il2cpp_class_get_type_token = (uint32_t(*)(Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_get_type_token");
            internal::methods::il2cpp_class_has_attribute = (bool(*)(Il2CppClass * klass, Il2CppClass * attr_class))KittyScanner::findSymbol(framework, "_il2cpp_class_has_attribute");
            internal::methods::il2cpp_class_has_references = (bool(*)(Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_has_references");
            internal::methods::il2cpp_class_is_enum = (bool(*)(const Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_is_enum");
            internal::methods::il2cpp_class_get_image = (const Il2CppImage*(*)(Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_get_image");
            internal::methods::il2cpp_class_get_assemblyname = (const char*(*)(const Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_get_assemblyname");
            internal::methods::il2cpp_class_get_rank = (int(*)(const Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_get_rank");
            internal::methods::il2cpp_class_get_data_size = (uint32_t(*)(const Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_get_data_size");
            internal::methods::il2cpp_class_get_static_field_data = (void*(*)(const Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_get_static_field_data");
            internal::methods::il2cpp_class_get_bitmap_size = (size_t(*)(const Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_class_get_bitmap_size");
            internal::methods::il2cpp_class_get_bitmap = (void(*)(Il2CppClass * klass, size_t * bitmap))KittyScanner::findSymbol(framework, "_il2cpp_class_get_bitmap");
            internal::methods::il2cpp_stats_dump_to_file = (bool(*)(const char *path))KittyScanner::findSymbol(framework, "_il2cpp_stats_dump_to_file");
            internal::methods::il2cpp_stats_get_value = (uint64_t(*)(Il2CppStat stat))KittyScanner::findSymbol(framework, "_il2cpp_stats_get_value");
            internal::methods::il2cpp_domain_get = (Il2CppDomain*(*)())KittyScanner::findSymbol(framework, "_il2cpp_domain_get");
            internal::methods::il2cpp_domain_assembly_open = (const Il2CppAssembly*(*)(Il2CppDomain * domain, const char* name))KittyScanner::findSymbol(framework, "_il2cpp_domain_assembly_open");
            internal::methods::il2cpp_domain_get_assemblies = (const Il2CppAssembly**(*)(const Il2CppDomain * domain, size_t * size))KittyScanner::findSymbol(framework, "_il2cpp_domain_get_assemblies");
            internal::methods::il2cpp_exception_from_name_msg = (Il2CppException*(*)(const Il2CppImage * image, const char *name_space, const char *name, const char *msg))KittyScanner::findSymbol(framework, "_il2cpp_exception_from_name_msg");
            internal::methods::il2cpp_get_exception_argument_null = (Il2CppException*(*)(const char *arg))KittyScanner::findSymbol(framework, "_il2cpp_get_exception_argument_null");
            internal::methods::il2cpp_format_exception = (void(*)(const Il2CppException * ex, char* message, int message_size))KittyScanner::findSymbol(framework, "_il2cpp_format_exception");
            internal::methods::il2cpp_format_stack_trace = (void(*)(const Il2CppException * ex, char* output, int output_size))KittyScanner::findSymbol(framework, "_il2cpp_format_stack_trace");
            internal::methods::il2cpp_unhandled_exception = (void(*)(Il2CppException*))KittyScanner::findSymbol(framework, "_il2cpp_unhandled_exception");
            internal::methods::il2cpp_native_stack_trace = (void(*)(const Il2CppException * ex, uintptr_t** addresses, int* numFrames, char** imageUUID, char** imageName))KittyScanner::findSymbol(framework, "_il2cpp_native_stack_trace");
            internal::methods::il2cpp_field_get_flags = (int(*)(FieldInfo * field))KittyScanner::findSymbol(framework, "_il2cpp_field_get_flags");
            internal::methods::il2cpp_field_get_name = (const char*(*)(FieldInfo * field))KittyScanner::findSymbol(framework, "_il2cpp_field_get_name");
            internal::methods::il2cpp_field_get_parent = (Il2CppClass*(*)(FieldInfo * field))KittyScanner::findSymbol(framework, "_il2cpp_field_get_parent");
            internal::methods::il2cpp_field_get_offset = (size_t(*)(FieldInfo * field))KittyScanner::findSymbol(framework, "_il2cpp_field_get_offset");
            internal::methods::il2cpp_field_get_type = (const Il2CppType*(*)(FieldInfo * field))KittyScanner::findSymbol(framework, "_il2cpp_field_get_type");
            internal::methods::il2cpp_field_get_value = (void(*)(Il2CppObject * obj, FieldInfo * field, void *value))KittyScanner::findSymbol(framework, "_il2cpp_field_get_value");
            internal::methods::il2cpp_field_get_value_object = (Il2CppObject*(*)(FieldInfo * field, Il2CppObject * obj))KittyScanner::findSymbol(framework, "_il2cpp_field_get_value_object");
            internal::methods::il2cpp_field_has_attribute = (bool(*)(FieldInfo * field, Il2CppClass * attr_class))KittyScanner::findSymbol(framework, "_il2cpp_field_has_attribute");
            internal::methods::il2cpp_field_set_value = (void(*)(Il2CppObject * obj, FieldInfo * field, void *value))KittyScanner::findSymbol(framework, "_il2cpp_field_set_value");
            internal::methods::il2cpp_field_static_get_value = (void(*)(FieldInfo * field, void *value))KittyScanner::findSymbol(framework, "_il2cpp_field_static_get_value");
            internal::methods::il2cpp_field_static_set_value = (void(*)(FieldInfo * field, void *value))KittyScanner::findSymbol(framework, "_il2cpp_field_static_set_value");
            internal::methods::il2cpp_field_set_value_object = (void(*)(Il2CppObject * instance, FieldInfo * field, Il2CppObject * value))KittyScanner::findSymbol(framework, "_il2cpp_field_set_value_object");
            internal::methods::il2cpp_field_is_literal = (bool(*)(FieldInfo * field))KittyScanner::findSymbol(framework, "_il2cpp_field_is_literal");
            internal::methods::il2cpp_gc_collect = (void(*)(int maxGenerations))KittyScanner::findSymbol(framework, "_il2cpp_gc_collect");
            internal::methods::il2cpp_gc_collect_a_little = (int32_t(*)())KittyScanner::findSymbol(framework, "_il2cpp_gc_collect_a_little");
            internal::methods::il2cpp_gc_start_incremental_collection = (void(*)())KittyScanner::findSymbol(framework, "_il2cpp_gc_start_incremental_collection");
            internal::methods::il2cpp_gc_disable = (void(*)())KittyScanner::findSymbol(framework, "_il2cpp_gc_disable");
            internal::methods::il2cpp_gc_enable = (void(*)())KittyScanner::findSymbol(framework, "_il2cpp_gc_enable");
            internal::methods::il2cpp_gc_is_disabled = (bool(*)())KittyScanner::findSymbol(framework, "_il2cpp_gc_is_disabled");
            internal::methods::il2cpp_gc_set_mode = (void(*)(Il2CppGCMode mode))KittyScanner::findSymbol(framework, "_il2cpp_gc_set_mode");
            internal::methods::il2cpp_gc_get_max_time_slice_ns = (int64_t(*)())KittyScanner::findSymbol(framework, "_il2cpp_gc_get_max_time_slice_ns");
            internal::methods::il2cpp_gc_set_max_time_slice_ns = (void(*)(int64_t maxTimeSlice))KittyScanner::findSymbol(framework, "_il2cpp_gc_set_max_time_slice_ns");
            internal::methods::il2cpp_gc_is_incremental = (bool(*)())KittyScanner::findSymbol(framework, "_il2cpp_gc_is_incremental");
            internal::methods::il2cpp_gc_get_used_size = (int64_t(*)())KittyScanner::findSymbol(framework, "_il2cpp_gc_get_used_size");
            internal::methods::il2cpp_gc_get_heap_size = (int64_t(*)())KittyScanner::findSymbol(framework, "_il2cpp_gc_get_heap_size");
            internal::methods::il2cpp_gc_wbarrier_set_field = (void(*)(Il2CppObject * obj, void **targetAddress, void *object))KittyScanner::findSymbol(framework, "_il2cpp_gc_wbarrier_set_field");
            internal::methods::il2cpp_gc_has_strict_wbarriers = (bool(*)())KittyScanner::findSymbol(framework, "_il2cpp_gc_has_strict_wbarriers");
            internal::methods::il2cpp_gc_set_external_allocation_tracker = (void(*)(void(*func)(void*, size_t, int)))KittyScanner::findSymbol(framework, "_il2cpp_gc_set_external_allocation_tracker");
            internal::methods::il2cpp_gc_set_external_wbarrier_tracker = (void(*)(void(*func)(void**)))KittyScanner::findSymbol(framework, "_il2cpp_gc_set_external_wbarrier_tracker");
            internal::methods::il2cpp_gc_foreach_heap = (void(*)(void(*func)(void* data, void* userData), void* userData))KittyScanner::findSymbol(framework, "_il2cpp_gc_foreach_heap");
            internal::methods::il2cpp_stop_gc_world = (void(*)())KittyScanner::findSymbol(framework, "_il2cpp_stop_gc_world");
            internal::methods::il2cpp_start_gc_world = (void(*)())KittyScanner::findSymbol(framework, "_il2cpp_start_gc_world");
            internal::methods::il2cpp_gc_alloc_fixed = (void*(*)(size_t size))KittyScanner::findSymbol(framework, "_il2cpp_gc_alloc_fixed");
            internal::methods::il2cpp_gc_free_fixed = (void(*)(void* address))KittyScanner::findSymbol(framework, "_il2cpp_gc_free_fixed");
            internal::methods::il2cpp_gchandle_new = (uint32_t(*)(Il2CppObject * obj, bool pinned))KittyScanner::findSymbol(framework, "_il2cpp_gchandle_new");
            internal::methods::il2cpp_gchandle_new_weakref = (uint32_t(*)(Il2CppObject * obj, bool track_resurrection))KittyScanner::findSymbol(framework, "_il2cpp_gchandle_new_weakref");
            internal::methods::il2cpp_gchandle_get_target = (Il2CppObject*(*)(uint32_t gchandle))KittyScanner::findSymbol(framework, "_il2cpp_gchandle_get_target");
            internal::methods::il2cpp_gchandle_free = (void(*)(uint32_t gchandle))KittyScanner::findSymbol(framework, "_il2cpp_gchandle_free");
            internal::methods::il2cpp_gchandle_foreach_get_target = (void(*)(void(*func)(void* data, void* userData), void* userData))KittyScanner::findSymbol(framework, "_il2cpp_gchandle_foreach_get_target");
            internal::methods::il2cpp_object_header_size = (uint32_t(*)())KittyScanner::findSymbol(framework, "_il2cpp_object_header_size");
            internal::methods::il2cpp_array_object_header_size = (uint32_t(*)())KittyScanner::findSymbol(framework, "_il2cpp_array_object_header_size");
            internal::methods::il2cpp_offset_of_array_length_in_array_object_header = (uint32_t(*)())KittyScanner::findSymbol(framework, "_il2cpp_offset_of_array_length_in_array_object_header");
            internal::methods::il2cpp_offset_of_array_bounds_in_array_object_header = (uint32_t(*)())KittyScanner::findSymbol(framework, "_il2cpp_offset_of_array_bounds_in_array_object_header");
            internal::methods::il2cpp_allocation_granularity = (uint32_t(*)())KittyScanner::findSymbol(framework, "_il2cpp_allocation_granularity");
            internal::methods::il2cpp_unity_liveness_allocate_struct = (void*(*)(Il2CppClass * filter, int max_object_count, il2cpp_register_object_callback callback, void* userdata, il2cpp_liveness_reallocate_callback reallocate))KittyScanner::findSymbol(framework, "_il2cpp_unity_liveness_allocate_struct");
            internal::methods::il2cpp_unity_liveness_calculation_from_root = (void(*)(Il2CppObject * root, void* state))KittyScanner::findSymbol(framework, "_il2cpp_unity_liveness_calculation_from_root");
            internal::methods::il2cpp_unity_liveness_calculation_from_statics = (void(*)(void* state))KittyScanner::findSymbol(framework, "_il2cpp_unity_liveness_calculation_from_statics");
            internal::methods::il2cpp_unity_liveness_finalize = (void(*)(void* state))KittyScanner::findSymbol(framework, "_il2cpp_unity_liveness_finalize");
            internal::methods::il2cpp_unity_liveness_free_struct = (void(*)(void* state))KittyScanner::findSymbol(framework, "_il2cpp_unity_liveness_free_struct");
            internal::methods::il2cpp_method_get_return_type = (const Il2CppType*(*)(const MethodInfo * method))KittyScanner::findSymbol(framework, "_il2cpp_method_get_return_type");
            internal::methods::il2cpp_method_get_declaring_type = (Il2CppClass*(*)(const MethodInfo * method))KittyScanner::findSymbol(framework, "_il2cpp_method_get_declaring_type");
            internal::methods::il2cpp_method_get_name = (const char*(*)(const MethodInfo * method))KittyScanner::findSymbol(framework, "_il2cpp_method_get_name");
            internal::methods::il2cpp_method_get_from_reflection = (const MethodInfo*(*)(const Il2CppReflectionMethod * method))KittyScanner::findSymbol(framework, "_il2cpp_method_get_from_reflection");
            internal::methods::il2cpp_method_get_object = (Il2CppReflectionMethod*(*)(const MethodInfo * method, Il2CppClass * refclass))KittyScanner::findSymbol(framework, "_il2cpp_method_get_object");
            internal::methods::il2cpp_method_is_generic = (bool(*)(const MethodInfo * method))KittyScanner::findSymbol(framework, "_il2cpp_method_is_generic");
            internal::methods::il2cpp_method_is_inflated = (bool(*)(const MethodInfo * method))KittyScanner::findSymbol(framework, "_il2cpp_method_is_inflated");
            internal::methods::il2cpp_method_is_instance = (bool(*)(const MethodInfo * method))KittyScanner::findSymbol(framework, "_il2cpp_method_is_instance");
            internal::methods::il2cpp_method_get_param_count = (uint32_t(*)(const MethodInfo * method))KittyScanner::findSymbol(framework, "_il2cpp_method_get_param_count");
            internal::methods::il2cpp_method_get_param = (const Il2CppType*(*)(const MethodInfo * method, uint32_t index))KittyScanner::findSymbol(framework, "_il2cpp_method_get_param");
            internal::methods::il2cpp_method_get_class = (Il2CppClass*(*)(const MethodInfo * method))KittyScanner::findSymbol(framework, "_il2cpp_method_get_class");
            internal::methods::il2cpp_method_has_attribute = (bool(*)(const MethodInfo * method, Il2CppClass * attr_class))KittyScanner::findSymbol(framework, "_il2cpp_method_has_attribute");
            internal::methods::il2cpp_method_get_flags = (uint32_t(*)(const MethodInfo * method, uint32_t * iflags))KittyScanner::findSymbol(framework, "_il2cpp_method_get_flags");
            internal::methods::il2cpp_method_get_token = (uint32_t(*)(const MethodInfo * method))KittyScanner::findSymbol(framework, "_il2cpp_method_get_token");
            internal::methods::il2cpp_method_get_param_name = (const char*(*)(const MethodInfo * method, uint32_t index))KittyScanner::findSymbol(framework, "_il2cpp_method_get_param_name");
            internal::methods::il2cpp_property_get_flags = (uint32_t(*)(PropertyInfo * prop))KittyScanner::findSymbol(framework, "_il2cpp_property_get_flags");
            internal::methods::il2cpp_property_get_get_method = (const MethodInfo*(*)(PropertyInfo * prop))KittyScanner::findSymbol(framework, "_il2cpp_property_get_get_method");
            internal::methods::il2cpp_property_get_set_method = (const MethodInfo*(*)(PropertyInfo * prop))KittyScanner::findSymbol(framework, "_il2cpp_property_get_set_method");
            internal::methods::il2cpp_property_get_name = (const char*(*)(PropertyInfo * prop))KittyScanner::findSymbol(framework, "_il2cpp_property_get_name");
            internal::methods::il2cpp_property_get_parent = (Il2CppClass*(*)(PropertyInfo * prop))KittyScanner::findSymbol(framework, "_il2cpp_property_get_parent");
            internal::methods::il2cpp_object_get_class = (Il2CppClass*(*)(Il2CppObject * obj))KittyScanner::findSymbol(framework, "_il2cpp_object_get_class");
            internal::methods::il2cpp_object_get_size = (uint32_t(*)(Il2CppObject * obj))KittyScanner::findSymbol(framework, "_il2cpp_object_get_size");
            internal::methods::il2cpp_object_get_virtual_method = (const MethodInfo*(*)(Il2CppObject * obj, const MethodInfo * method))KittyScanner::findSymbol(framework, "_il2cpp_object_get_virtual_method");
            internal::methods::il2cpp_object_new = (Il2CppObject*(*)(const Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_object_new");
            internal::methods::il2cpp_object_unbox = (void*(*)(Il2CppObject * obj))KittyScanner::findSymbol(framework, "_il2cpp_object_unbox");
            internal::methods::il2cpp_value_box = (Il2CppObject*(*)(Il2CppClass * klass, void* data))KittyScanner::findSymbol(framework, "_il2cpp_value_box");
            internal::methods::il2cpp_monitor_enter = (void(*)(Il2CppObject * obj))KittyScanner::findSymbol(framework, "_il2cpp_monitor_enter");
            internal::methods::il2cpp_monitor_try_enter = (bool(*)(Il2CppObject * obj, uint32_t timeout))KittyScanner::findSymbol(framework, "_il2cpp_monitor_try_enter");
            internal::methods::il2cpp_monitor_exit = (void(*)(Il2CppObject * obj))KittyScanner::findSymbol(framework, "_il2cpp_monitor_exit");
            internal::methods::il2cpp_monitor_pulse = (void(*)(Il2CppObject * obj))KittyScanner::findSymbol(framework, "_il2cpp_monitor_pulse");
            internal::methods::il2cpp_monitor_pulse_all = (void(*)(Il2CppObject * obj))KittyScanner::findSymbol(framework, "_il2cpp_monitor_pulse_all");
            internal::methods::il2cpp_monitor_wait = (void(*)(Il2CppObject * obj))KittyScanner::findSymbol(framework, "_il2cpp_monitor_wait");
            internal::methods::il2cpp_monitor_try_wait = (bool(*)(Il2CppObject * obj, uint32_t timeout))KittyScanner::findSymbol(framework, "_il2cpp_monitor_try_wait");
            internal::methods::il2cpp_runtime_invoke = (Il2CppObject*(*)(const MethodInfo * method, void *obj, void **params, Il2CppException **exc))KittyScanner::findSymbol(framework, "_il2cpp_runtime_invoke");
            internal::methods::il2cpp_runtime_invoke_convert_args = (Il2CppObject*(*)(const MethodInfo * method, void *obj, Il2CppObject **params, int paramCount, Il2CppException **exc))KittyScanner::findSymbol(framework, "_il2cpp_runtime_invoke_convert_args");
            internal::methods::il2cpp_runtime_class_init = (void(*)(Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_runtime_class_init");
            internal::methods::il2cpp_runtime_object_init = (void(*)(Il2CppObject * obj))KittyScanner::findSymbol(framework, "_il2cpp_runtime_object_init");
            internal::methods::il2cpp_runtime_object_init_exception = (void(*)(Il2CppObject * obj, Il2CppException** exc))KittyScanner::findSymbol(framework, "_il2cpp_runtime_object_init_exception");
            internal::methods::il2cpp_runtime_unhandled_exception_policy_set = (void(*)(Il2CppRuntimeUnhandledExceptionPolicy value))KittyScanner::findSymbol(framework, "_il2cpp_runtime_unhandled_exception_policy_set");
            internal::methods::il2cpp_string_length = (int32_t(*)(Il2CppString * str))KittyScanner::findSymbol(framework, "_il2cpp_string_length");
            internal::methods::il2cpp_string_chars = (Il2CppChar*(*)(Il2CppString * str))KittyScanner::findSymbol(framework, "_il2cpp_string_chars");
            internal::methods::il2cpp_string_new = (Il2CppString*(*)(const char* str))KittyScanner::findSymbol(framework, "_il2cpp_string_new");
            internal::methods::il2cpp_string_new_len = (Il2CppString*(*)(const char* str, uint32_t length))KittyScanner::findSymbol(framework, "_il2cpp_string_new_len");
            internal::methods::il2cpp_string_new_utf16 = (Il2CppString*(*)(const Il2CppChar * text, int32_t len))KittyScanner::findSymbol(framework, "_il2cpp_string_new_utf16");
            internal::methods::il2cpp_string_new_wrapper = (Il2CppString*(*)(const char* str))KittyScanner::findSymbol(framework, "_il2cpp_string_new_wrapper");
            internal::methods::il2cpp_string_intern = (Il2CppString*(*)(Il2CppString * str))KittyScanner::findSymbol(framework, "_il2cpp_string_intern");
            internal::methods::il2cpp_string_is_interned = (Il2CppString*(*)(Il2CppString * str))KittyScanner::findSymbol(framework, "_il2cpp_string_is_interned");
            internal::methods::il2cpp_thread_current = (Il2CppThread*(*)())KittyScanner::findSymbol(framework, "_il2cpp_thread_current");
            internal::methods::il2cpp_thread_attach = (Il2CppThread*(*)(Il2CppDomain * domain))KittyScanner::findSymbol(framework, "_il2cpp_thread_attach");
            internal::methods::il2cpp_thread_detach = (void(*)(Il2CppThread * thread))KittyScanner::findSymbol(framework, "_il2cpp_thread_detach");
            internal::methods::il2cpp_thread_get_all_attached_threads = (Il2CppThread**(*)(size_t * size))KittyScanner::findSymbol(framework, "_il2cpp_thread_get_all_attached_threads");
            internal::methods::il2cpp_is_vm_thread = (bool(*)(Il2CppThread * thread))KittyScanner::findSymbol(framework, "_il2cpp_is_vm_thread");
            internal::methods::il2cpp_current_thread_walk_frame_stack = (void(*)(Il2CppFrameWalkFunc func, void* user_data))KittyScanner::findSymbol(framework, "_il2cpp_current_thread_walk_frame_stack");
            internal::methods::il2cpp_thread_walk_frame_stack = (void(*)(Il2CppThread * thread, Il2CppFrameWalkFunc func, void* user_data))KittyScanner::findSymbol(framework, "_il2cpp_thread_walk_frame_stack");
            internal::methods::il2cpp_current_thread_get_top_frame = (bool(*)(Il2CppStackFrameInfo * frame))KittyScanner::findSymbol(framework, "_il2cpp_current_thread_get_top_frame");
            internal::methods::il2cpp_thread_get_top_frame = (bool(*)(Il2CppThread * thread, Il2CppStackFrameInfo * frame))KittyScanner::findSymbol(framework, "_il2cpp_thread_get_top_frame");
            internal::methods::il2cpp_current_thread_get_frame_at = (bool(*)(int32_t offset, Il2CppStackFrameInfo * frame))KittyScanner::findSymbol(framework, "_il2cpp_current_thread_get_frame_at");
            internal::methods::il2cpp_thread_get_frame_at = (bool(*)(Il2CppThread * thread, int32_t offset, Il2CppStackFrameInfo * frame))KittyScanner::findSymbol(framework, "_il2cpp_thread_get_frame_at");
            internal::methods::il2cpp_current_thread_get_stack_depth = (int32_t(*)())KittyScanner::findSymbol(framework, "_il2cpp_current_thread_get_stack_depth");
            internal::methods::il2cpp_thread_get_stack_depth = (int32_t(*)(Il2CppThread * thread))KittyScanner::findSymbol(framework, "_il2cpp_thread_get_stack_depth");
            internal::methods::il2cpp_override_stack_backtrace = (void(*)(Il2CppBacktraceFunc stackBacktraceFunc))KittyScanner::findSymbol(framework, "_il2cpp_override_stack_backtrace");
            internal::methods::il2cpp_type_get_object = (Il2CppObject*(*)(const Il2CppType * type))KittyScanner::findSymbol(framework, "_il2cpp_type_get_object");
            internal::methods::il2cpp_type_get_type = (int(*)(const Il2CppType * type))KittyScanner::findSymbol(framework, "_il2cpp_type_get_type");
            internal::methods::il2cpp_type_get_class_or_element_class = (Il2CppClass*(*)(const Il2CppType * type))KittyScanner::findSymbol(framework, "_il2cpp_type_get_class_or_element_class");
            internal::methods::il2cpp_type_get_name = (char*(*)(const Il2CppType * type))KittyScanner::findSymbol(framework, "_il2cpp_type_get_name");
            internal::methods::il2cpp_type_is_byref = (bool(*)(const Il2CppType * type))KittyScanner::findSymbol(framework, "_il2cpp_type_is_byref");
            internal::methods::il2cpp_type_get_attrs = (uint32_t(*)(const Il2CppType * type))KittyScanner::findSymbol(framework, "_il2cpp_type_get_attrs");
            internal::methods::il2cpp_type_equals = (bool(*)(const Il2CppType * type, const Il2CppType * otherType))KittyScanner::findSymbol(framework, "_il2cpp_type_equals");
            internal::methods::il2cpp_type_get_assembly_qualified_name = (char*(*)(const Il2CppType * type))KittyScanner::findSymbol(framework, "_il2cpp_type_get_assembly_qualified_name");
            internal::methods::il2cpp_type_is_static = (bool(*)(const Il2CppType * type))KittyScanner::findSymbol(framework, "_il2cpp_type_is_static");
            internal::methods::il2cpp_type_is_pointer_type = (bool(*)(const Il2CppType * type))KittyScanner::findSymbol(framework, "_il2cpp_type_is_pointer_type");
            internal::methods::il2cpp_image_get_assembly = (const Il2CppAssembly*(*)(const Il2CppImage * image))KittyScanner::findSymbol(framework, "_il2cpp_image_get_assembly");
            internal::methods::il2cpp_image_get_name = (const char*(*)(const Il2CppImage * image))KittyScanner::findSymbol(framework, "_il2cpp_image_get_name");
            internal::methods::il2cpp_image_get_filename = (const char*(*)(const Il2CppImage * image))KittyScanner::findSymbol(framework, "_il2cpp_image_get_filename");
            internal::methods::il2cpp_image_get_entry_point = (const MethodInfo*(*)(const Il2CppImage * image))KittyScanner::findSymbol(framework, "_il2cpp_image_get_entry_point");
            internal::methods::il2cpp_image_get_class_count = (size_t(*)(const Il2CppImage * image))KittyScanner::findSymbol(framework, "_il2cpp_image_get_class_count");
            internal::methods::il2cpp_image_get_class = (const Il2CppClass*(*)(const Il2CppImage * image, size_t index))KittyScanner::findSymbol(framework, "_il2cpp_image_get_class");
            internal::methods::il2cpp_capture_memory_snapshot = (Il2CppManagedMemorySnapshot*(*)())KittyScanner::findSymbol(framework, "_il2cpp_capture_memory_snapshot");
            internal::methods::il2cpp_free_captured_memory_snapshot = (void(*)(Il2CppManagedMemorySnapshot * snapshot))KittyScanner::findSymbol(framework, "_il2cpp_free_captured_memory_snapshot");
            internal::methods::il2cpp_set_find_plugin_callback = (void(*)(Il2CppSetFindPlugInCallback method))KittyScanner::findSymbol(framework, "_il2cpp_set_find_plugin_callback");
            internal::methods::il2cpp_register_log_callback = (void(*)(Il2CppLogCallback method))KittyScanner::findSymbol(framework, "_il2cpp_register_log_callback");
            internal::methods::il2cpp_debugger_set_agent_options = (void(*)(const char* options))KittyScanner::findSymbol(framework, "_il2cpp_debugger_set_agent_options");
            internal::methods::il2cpp_is_debugger_attached = (bool(*)())KittyScanner::findSymbol(framework, "_il2cpp_is_debugger_attached");
            internal::methods::il2cpp_register_debugger_agent_transport = (void(*)(Il2CppDebuggerTransport * debuggerTransport))KittyScanner::findSymbol(framework, "_il2cpp_register_debugger_agent_transport");
            internal::methods::il2cpp_debug_get_method_info = (bool(*)(const MethodInfo*, Il2CppMethodDebugInfo * methodDebugInfo))KittyScanner::findSymbol(framework, "_il2cpp_debug_get_method_info");
            internal::methods::il2cpp_unity_install_unitytls_interface = (void(*)(const void* unitytlsInterfaceStruct))KittyScanner::findSymbol(framework, "_il2cpp_unity_install_unitytls_interface");
            internal::methods::il2cpp_custom_attrs_from_class = (Il2CppCustomAttrInfo*(*)(Il2CppClass * klass))KittyScanner::findSymbol(framework, "_il2cpp_custom_attrs_from_class");
            internal::methods::il2cpp_custom_attrs_from_method = (Il2CppCustomAttrInfo*(*)(const MethodInfo * method))KittyScanner::findSymbol(framework, "_il2cpp_custom_attrs_from_method");
            internal::methods::il2cpp_custom_attrs_get_attr = (Il2CppObject*(*)(Il2CppCustomAttrInfo * ainfo, Il2CppClass * attr_klass))KittyScanner::findSymbol(framework, "_il2cpp_custom_attrs_get_attr");
            internal::methods::il2cpp_custom_attrs_has_attr = (bool(*)(Il2CppCustomAttrInfo * ainfo, Il2CppClass * attr_klass))KittyScanner::findSymbol(framework, "_il2cpp_custom_attrs_has_attr");
            internal::methods::il2cpp_custom_attrs_construct = (Il2CppArray*(*)(Il2CppCustomAttrInfo * cinfo))KittyScanner::findSymbol(framework, "_il2cpp_custom_attrs_construct");
            internal::methods::il2cpp_custom_attrs_free = (void(*)(Il2CppCustomAttrInfo * ainfo))KittyScanner::findSymbol(framework, "_il2cpp_custom_attrs_free");
            internal::methods::il2cpp_class_set_userdata = (void(*)(Il2CppClass * klass, void* userdata))KittyScanner::findSymbol(framework, "_il2cpp_class_set_userdata");
            internal::methods::il2cpp_class_get_userdata_offset = (int(*)())KittyScanner::findSymbol(framework, "_il2cpp_class_get_userdata_offset");
            internal::methods::il2cpp_set_default_thread_affinity = (void(*)(int64_t affinity_mask))KittyScanner::findSymbol(framework, "_il2cpp_set_default_thread_affinity");

            initClasses();

            finishCallback();
        }).detach();
    }
}