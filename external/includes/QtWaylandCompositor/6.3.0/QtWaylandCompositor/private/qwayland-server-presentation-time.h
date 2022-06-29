// This file was generated by qtwaylandscanner
// source file is /home/ineo/Downloads/QT_app/qt5/qtwayland/src/compositor/../3rdparty/protocol/presentation-time.xml

#ifndef QT_WAYLAND_SERVER_PRESENTATION_TIME
#define QT_WAYLAND_SERVER_PRESENTATION_TIME

#include "wayland-server-core.h"
#include <QtWaylandCompositor/private/wayland-presentation-time-server-protocol.h>
#include <QByteArray>
#include <QMultiMap>
#include <QString>

#ifndef WAYLAND_VERSION_CHECK
#define WAYLAND_VERSION_CHECK(major, minor, micro) \
    ((WAYLAND_VERSION_MAJOR > (major)) || \
    (WAYLAND_VERSION_MAJOR == (major) && WAYLAND_VERSION_MINOR > (minor)) || \
    (WAYLAND_VERSION_MAJOR == (major) && WAYLAND_VERSION_MINOR == (minor) && WAYLAND_VERSION_MICRO >= (micro)))
#endif

QT_BEGIN_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_GCC("-Wmissing-field-initializers")
QT_WARNING_DISABLE_CLANG("-Wmissing-field-initializers")

#if !defined(Q_WAYLAND_SERVER_PRESENTATION_TIME_EXPORT)
#  if defined(QT_SHARED)
#    define Q_WAYLAND_SERVER_PRESENTATION_TIME_EXPORT Q_DECL_EXPORT
#  else
#    define Q_WAYLAND_SERVER_PRESENTATION_TIME_EXPORT
#  endif
#endif

namespace QtWaylandServer {
    class Q_WAYLAND_SERVER_PRESENTATION_TIME_EXPORT wp_presentation
    {
    public:
        wp_presentation(struct ::wl_client *client, uint32_t id, int version);
        wp_presentation(struct ::wl_display *display, int version);
        wp_presentation(struct ::wl_resource *resource);
        wp_presentation();

        virtual ~wp_presentation();

        class Resource
        {
        public:
            Resource() : wp_presentation_object(nullptr), handle(nullptr) {}
            virtual ~Resource() {}

            wp_presentation *wp_presentation_object;
            wp_presentation *object() { return wp_presentation_object; } 
            struct ::wl_resource *handle;

            struct ::wl_client *client() const { return wl_resource_get_client(handle); }
            int version() const { return wl_resource_get_version(handle); }

            static Resource *fromResource(struct ::wl_resource *resource);
        };

        void init(struct ::wl_client *client, uint32_t id, int version);
        void init(struct ::wl_display *display, int version);
        void init(struct ::wl_resource *resource);

        Resource *add(struct ::wl_client *client, int version);
        Resource *add(struct ::wl_client *client, uint32_t id, int version);
        Resource *add(struct wl_list *resource_list, struct ::wl_client *client, uint32_t id, int version);

        Resource *resource() { return m_resource; }
        const Resource *resource() const { return m_resource; }

        QMultiMap<struct ::wl_client*, Resource*> resourceMap() { return m_resource_map; }
        const QMultiMap<struct ::wl_client*, Resource*> resourceMap() const { return m_resource_map; }

        bool isGlobal() const { return m_global != nullptr; }
        bool isResource() const { return m_resource != nullptr; }

        static const struct ::wl_interface *interface();
        static QByteArray interfaceName() { return interface()->name; }
        static int interfaceVersion() { return interface()->version; }


        enum error {
            error_invalid_timestamp = 0, // invalid value in tv_nsec
            error_invalid_flag = 1, // invalid flag
        };

        void send_clock_id(uint32_t clk_id);
        void send_clock_id(struct ::wl_resource *resource, uint32_t clk_id);

    protected:
        virtual Resource *wp_presentation_allocate();

        virtual void wp_presentation_bind_resource(Resource *resource);
        virtual void wp_presentation_destroy_resource(Resource *resource);

        virtual void wp_presentation_destroy(Resource *resource);
        virtual void wp_presentation_feedback(Resource *resource, struct ::wl_resource *surface, uint32_t callback);

    private:
        static void bind_func(struct ::wl_client *client, void *data, uint32_t version, uint32_t id);
        static void destroy_func(struct ::wl_resource *client_resource);
        static void display_destroy_func(struct ::wl_listener *listener, void *data);

        Resource *bind(struct ::wl_client *client, uint32_t id, int version);
        Resource *bind(struct ::wl_resource *handle);

        static const struct ::wp_presentation_interface m_wp_presentation_interface;

        static void handle_destroy(
            ::wl_client *client,
            struct wl_resource *resource);
        static void handle_feedback(
            ::wl_client *client,
            struct wl_resource *resource,
            struct ::wl_resource *surface,
            uint32_t callback);

        QMultiMap<struct ::wl_client*, Resource*> m_resource_map;
        Resource *m_resource;
        struct ::wl_global *m_global;
        struct DisplayDestroyedListener : ::wl_listener {
            wp_presentation *parent;
        };
        DisplayDestroyedListener m_displayDestroyedListener;
    };

    class Q_WAYLAND_SERVER_PRESENTATION_TIME_EXPORT wp_presentation_feedback
    {
    public:
        wp_presentation_feedback(struct ::wl_client *client, uint32_t id, int version);
        wp_presentation_feedback(struct ::wl_display *display, int version);
        wp_presentation_feedback(struct ::wl_resource *resource);
        wp_presentation_feedback();

        virtual ~wp_presentation_feedback();

        class Resource
        {
        public:
            Resource() : wp_presentation_feedback_object(nullptr), handle(nullptr) {}
            virtual ~Resource() {}

            wp_presentation_feedback *wp_presentation_feedback_object;
            wp_presentation_feedback *object() { return wp_presentation_feedback_object; } 
            struct ::wl_resource *handle;

            struct ::wl_client *client() const { return wl_resource_get_client(handle); }
            int version() const { return wl_resource_get_version(handle); }

            static Resource *fromResource(struct ::wl_resource *resource);
        };

        void init(struct ::wl_client *client, uint32_t id, int version);
        void init(struct ::wl_display *display, int version);
        void init(struct ::wl_resource *resource);

        Resource *add(struct ::wl_client *client, int version);
        Resource *add(struct ::wl_client *client, uint32_t id, int version);
        Resource *add(struct wl_list *resource_list, struct ::wl_client *client, uint32_t id, int version);

        Resource *resource() { return m_resource; }
        const Resource *resource() const { return m_resource; }

        QMultiMap<struct ::wl_client*, Resource*> resourceMap() { return m_resource_map; }
        const QMultiMap<struct ::wl_client*, Resource*> resourceMap() const { return m_resource_map; }

        bool isGlobal() const { return m_global != nullptr; }
        bool isResource() const { return m_resource != nullptr; }

        static const struct ::wl_interface *interface();
        static QByteArray interfaceName() { return interface()->name; }
        static int interfaceVersion() { return interface()->version; }


        enum kind {
            kind_vsync = 0x1, // presentation was vsync'd
            kind_hw_clock = 0x2, // hardware provided the presentation timestamp
            kind_hw_completion = 0x4, // hardware signalled the start of the presentation
            kind_zero_copy = 0x8, // presentation was done zero-copy
        };

        void send_sync_output(struct ::wl_resource *output);
        void send_sync_output(struct ::wl_resource *resource, struct ::wl_resource *output);
        void send_presented(uint32_t tv_sec_hi, uint32_t tv_sec_lo, uint32_t tv_nsec, uint32_t refresh, uint32_t seq_hi, uint32_t seq_lo, uint32_t flags);
        void send_presented(struct ::wl_resource *resource, uint32_t tv_sec_hi, uint32_t tv_sec_lo, uint32_t tv_nsec, uint32_t refresh, uint32_t seq_hi, uint32_t seq_lo, uint32_t flags);
        void send_discarded();
        void send_discarded(struct ::wl_resource *resource);

    protected:
        virtual Resource *wp_presentation_feedback_allocate();

        virtual void wp_presentation_feedback_bind_resource(Resource *resource);
        virtual void wp_presentation_feedback_destroy_resource(Resource *resource);

    private:
        static void bind_func(struct ::wl_client *client, void *data, uint32_t version, uint32_t id);
        static void destroy_func(struct ::wl_resource *client_resource);
        static void display_destroy_func(struct ::wl_listener *listener, void *data);

        Resource *bind(struct ::wl_client *client, uint32_t id, int version);
        Resource *bind(struct ::wl_resource *handle);

        QMultiMap<struct ::wl_client*, Resource*> m_resource_map;
        Resource *m_resource;
        struct ::wl_global *m_global;
        struct DisplayDestroyedListener : ::wl_listener {
            wp_presentation_feedback *parent;
        };
        DisplayDestroyedListener m_displayDestroyedListener;
    };
}

QT_WARNING_POP
QT_END_NAMESPACE

#endif