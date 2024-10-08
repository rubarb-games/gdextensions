#include "nine_patch_sprite_2d.h"

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>


void NinePatchSprite2D::_bind_methods()
{
    ADD_GROUP("Texture", "texture_");
    ClassDB::bind_method(D_METHOD("set_texture", "p_texture"), &NinePatchSprite2D::set_texture);
    ClassDB::bind_method(D_METHOD("get_texture"), &NinePatchSprite2D::get_texture);
    ClassDB::add_property("NinePatchSprite2D", PropertyInfo(Variant::OBJECT, "texture", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"), "set_texture", "get_texture");
    ClassDB::bind_method(D_METHOD("set_texture_centered", "p_texture_centered"), &NinePatchSprite2D::set_texture_centered);
    ClassDB::bind_method(D_METHOD("is_texture_centered"), &NinePatchSprite2D::is_texture_centered);
    ClassDB::add_property("NinePatchSprite2D", PropertyInfo(Variant::BOOL, "texture_centered"), "set_texture_centered", "is_texture_centered");
    ClassDB::bind_method(D_METHOD("set_texture_offset", "p_texture_offset"), &NinePatchSprite2D::set_texture_offset);
    ClassDB::bind_method(D_METHOD("get_texture_offset"), &NinePatchSprite2D::get_texture_offset);
    ClassDB::add_property("NinePatchSprite2D", PropertyInfo(Variant::VECTOR2, "texture_offset"), "set_texture_offset", "get_texture_offset");
    ClassDB::bind_method(D_METHOD("set_texture_size", "p_texture_size"), &NinePatchSprite2D::set_texture_size);
    ClassDB::bind_method(D_METHOD("get_texture_size"), &NinePatchSprite2D::get_texture_size);
    ClassDB::add_property("NinePatchSprite2D", PropertyInfo(Variant::VECTOR2, "texture_size"), "set_texture_size", "get_texture_size");
    ADD_GROUP("Drawing", "");
    ClassDB::bind_method(D_METHOD("set_draw_center", "p_draw_center"), &NinePatchSprite2D::set_draw_center);
    ClassDB::bind_method(D_METHOD("is_draw_center"), &NinePatchSprite2D::is_draw_center);
    ClassDB::add_property("NinePatchSprite2D", PropertyInfo(Variant::BOOL, "draw_center"), "set_draw_center", "is_draw_center");
    ADD_GROUP("Region", "region_");
    ClassDB::bind_method(D_METHOD("set_region_rect", "p_region_rect"), &NinePatchSprite2D::set_region_rect);
    ClassDB::bind_method(D_METHOD("get_region_rect"), &NinePatchSprite2D::get_region_rect);
    ClassDB::add_property("NinePatchSprite2D", PropertyInfo(Variant::RECT2, "region_rect"), "set_region_rect", "get_region_rect");
    ADD_GROUP("Patch", "");
    ClassDB::bind_method(D_METHOD("set_x_patch_mode", "p_x_patch_mode"), &NinePatchSprite2D::set_x_patch_mode);
    ClassDB::bind_method(D_METHOD("get_x_patch_mode"), &NinePatchSprite2D::get_x_patch_mode);
    ClassDB::add_property("NinePatchSprite2D", PropertyInfo(Variant::INT, "x_patch_mode", PROPERTY_HINT_ENUM, "Stretch, Tile, Tile Fit"), "set_x_patch_mode", "get_x_patch_mode");
    ClassDB::bind_method(D_METHOD("set_y_patch_mode", "p_y_patch_mode"), &NinePatchSprite2D::set_y_patch_mode);
    ClassDB::bind_method(D_METHOD("get_y_patch_mode"), &NinePatchSprite2D::get_y_patch_mode);
    ClassDB::add_property("NinePatchSprite2D", PropertyInfo(Variant::INT, "y_patch_mode", PROPERTY_HINT_ENUM, "Stretch, Tile, Tile Fit"), "set_y_patch_mode", "get_y_patch_mode");
    ClassDB::bind_method(D_METHOD("set_margin_top_left", "p_margin_top_left"), &NinePatchSprite2D::set_margin_top_left);
    ClassDB::bind_method(D_METHOD("get_margin_top_left"), &NinePatchSprite2D::get_margin_top_left);
    ClassDB::add_property("NinePatchSprite2D", PropertyInfo(Variant::VECTOR2I, "margin_top_left"), "set_margin_top_left", "get_margin_top_left");
    ClassDB::bind_method(D_METHOD("set_margin_bottom_right", "p_margin_bottom_right"), &NinePatchSprite2D::set_margin_bottom_right);
    ClassDB::bind_method(D_METHOD("get_margin_bottom_right"), &NinePatchSprite2D::get_margin_bottom_right);
    ClassDB::add_property("NinePatchSprite2D", PropertyInfo(Variant::VECTOR2I, "margin_bottom_right"), "set_margin_bottom_right", "get_margin_bottom_right");
    ADD_GROUP("Frames", "");
    ClassDB::bind_method(D_METHOD("set_hframes", "p_hframes"), &NinePatchSprite2D::set_hframes);
    ClassDB::bind_method(D_METHOD("get_hframes"), &NinePatchSprite2D::get_hframes);    
    ClassDB::add_property("NinePatchSprite2D", PropertyInfo(Variant::INT, "hframes"), "set_hframes", "get_hframes");
    ClassDB::bind_method(D_METHOD("set_vframes", "p_vframes"), &NinePatchSprite2D::set_vframes);
    ClassDB::bind_method(D_METHOD("get_vframes"), &NinePatchSprite2D::get_vframes);
    ClassDB::add_property("NinePatchSprite2D", PropertyInfo(Variant::INT, "vframes"), "set_vframes", "get_vframes");
    ClassDB::bind_method(D_METHOD("set_frame", "p_frame"), &NinePatchSprite2D::set_frame);
    ClassDB::bind_method(D_METHOD("get_frame"), &NinePatchSprite2D::get_frame);
    ClassDB::add_property("NinePatchSprite2D", PropertyInfo(Variant::INT, "frame", PROPERTY_HINT_RANGE, "0,255,1"), "set_frame", "get_frame");
}


NinePatchSprite2D::NinePatchSprite2D() {
    _processed_drawn_delay = 0;
    _func_update_texture = create_custom_callable_function_pointer<NinePatchSprite2D>(this, &NinePatchSprite2D::_update_texture);

    texture = Ref<Texture2D>(nullptr);
    texture_centered = draw_center = true;
    texture_offset = texture_size = Vector2();
    mode_x = mode_y = RenderingServer::NINE_PATCH_TILE;
    margin_top_left = margin_bottom_right = Vector2i();
    region_rect = Rect2();
    hframes = vframes = 1;
    frame = 0;
}
NinePatchSprite2D::~NinePatchSprite2D() {}

/*
void NinePatchSprite2D::_input(const Ref<InputEvent> &p_event)
{
    // Drags the node to resize the texture and moves the node
    UtilityFunctions::print(p_event->as_text());
}
*/

void NinePatchSprite2D::_exit_tree()
{
    _processed_drawn_delay = 0; // Reset the number of times the texture has been processed
}
void NinePatchSprite2D::_process(double delta)
{
    /*
    NOTE: 3 frames is a magic number, which stands for the least frames that _ready() is required to be executed.
    This ensures that the texture is updated when the software is first started.
    */ 
    
    if (_processed_drawn_delay > 3) {
        return;
    }
    
    _processed_drawn_delay++;
    if (_processed_drawn_delay > 3) {
        queue_redraw();
    }
}
void NinePatchSprite2D::_draw()
{
    _update_texture();
}


void NinePatchSprite2D::_drag()
{
#ifdef TOOLS_ENABLED
#endif
}
void NinePatchSprite2D::_fresh_texture()
{
    _func_update_texture.call_deferred();
}
void NinePatchSprite2D::_update_texture()
{
    RID canvas_item_rid = get_canvas_item(); // Get the canvas item's RID

    if (texture.is_valid()) { // Draw the texture if there is one
        renderer->canvas_item_clear(canvas_item_rid); // Clear the canvas item to prevent artifacts from previous draws
        renderer->canvas_item_add_nine_patch(
            canvas_item_rid, 
            Rect2(texture_offset, texture_size), 
            region_rect, 
            texture->get_rid(), 
            margin_top_left, 
            margin_bottom_right, 
            (RenderingServer::NinePatchAxisMode)mode_x, 
            (RenderingServer::NinePatchAxisMode)mode_y, 
            draw_center
        );
        renderer->canvas_item_set_default_texture_filter(canvas_item_rid, RenderingServer::CanvasItemTextureFilter(get_texture_filter()));
        renderer->canvas_item_set_default_texture_repeat(canvas_item_rid, RenderingServer::CanvasItemTextureRepeat(get_texture_repeat()));
    }
}

void NinePatchSprite2D::_frame_changed()
{
    if (!texture.is_valid()) {
        return; // If there is no texture, there is no need to change the frame
    }
    
    int frame_max = hframes * vframes; // Total number of frames, which is the product of the texture size and the number of frames
    if (frame > frame_max) {
        frame = frame_max - 1; // Clamp the frame to the maximum number of frames
    }

    Vector2i frame_index = Vector2i(frame % hframes, (int)floor(frame / hframes)); // Get the index of the current frame
    Vector2 frame_texture_size = texture->get_size() / Vector2(hframes, vframes); // Get the size of the texture
    Rect2 frame_rect = Rect2(
        frame_index.x * frame_texture_size.x,
        frame_index.y * frame_texture_size.y,
        frame_texture_size.x,
        frame_texture_size.y
    );

    region_rect = frame_rect;
    
    _fresh_texture();
}
void NinePatchSprite2D::_clamp_frame()
{
    frame = CLAMP(frame, 0, hframes * vframes - 1);
}


void NinePatchSprite2D::set_texture(const Ref<Texture2D> &p_texture)
{
    texture = p_texture;

    if (texture.is_valid()) {
        texture_size = texture->get_size();
        _frame_changed();
        texture_offset = texture_centered ? -region_rect.get_size() / 2 : Vector2(); // Centered or not
    } else {
        texture_offset = texture_size = Vector2();
        texture_centered = draw_center = true;
        region_rect = Rect2();
        hframes = vframes = 1;
        frame = 0;
    }

    _fresh_texture();
}
Ref<Texture2D> NinePatchSprite2D::get_texture() const
{
    return texture;
}
void NinePatchSprite2D::set_texture_centered(const bool p_texture_centered)
{
    texture_centered = p_texture_centered;
    texture_offset = texture_centered ? -region_rect.get_size() / 2 : Vector2(); // Centered or not
    _fresh_texture();
}
bool NinePatchSprite2D::is_texture_centered() const
{
    return texture_centered;
}
void NinePatchSprite2D::set_texture_offset(const Vector2 &p_texture_offset)
{
    texture_offset = p_texture_offset;

    if (texture.is_valid() && texture_offset != -region_rect.get_size() / 2) {
        texture_centered = false; // Disable centered mode if the offset is set
    }

    _fresh_texture();
}
Vector2 NinePatchSprite2D::get_texture_offset() const
{
    return texture_offset;
}
void NinePatchSprite2D::set_texture_size(const Vector2 &p_texture_size)
{
    texture_size = p_texture_size;
    _fresh_texture();
}
Vector2 NinePatchSprite2D::get_texture_size() const
{
    return texture_size;
}
void NinePatchSprite2D::set_draw_center(const bool p_draw_center)
{
    draw_center = p_draw_center;
    _fresh_texture();
}
bool NinePatchSprite2D::is_draw_center() const
{
    return draw_center;
}
void NinePatchSprite2D::set_x_patch_mode(const uint8_t p_x_patch_mode)
{
    mode_x = p_x_patch_mode;
    _fresh_texture();
}
uint8_t NinePatchSprite2D::get_x_patch_mode() const
{
    return mode_x;
}
void NinePatchSprite2D::set_y_patch_mode(const uint8_t p_y_patch_mode)
{
    mode_y = p_y_patch_mode;
    _fresh_texture();
}
uint8_t NinePatchSprite2D::get_y_patch_mode() const
{
    return mode_y;
}
void NinePatchSprite2D::set_margin_top_left(const Vector2i &p_margin_top_left)
{
    margin_top_left = p_margin_top_left.abs();
    _fresh_texture();
}
Vector2i NinePatchSprite2D::get_margin_top_left() const
{
    return margin_top_left;
}
void NinePatchSprite2D::set_margin_bottom_right(const Vector2i &p_margin_bottom_right)
{
    margin_bottom_right = p_margin_bottom_right.abs();
    _fresh_texture();
}
Vector2i NinePatchSprite2D::get_margin_bottom_right() const
{
    return margin_bottom_right;
}
void NinePatchSprite2D::set_region_rect(const Rect2 &p_region_rect)
{
    Vector2 pos = p_region_rect.position.abs();
    Vector2 size = p_region_rect.size.abs();
    region_rect = Rect2(pos, size);
    _fresh_texture();
}
Rect2 NinePatchSprite2D::get_region_rect() const
{
    return region_rect;
}

void NinePatchSprite2D::set_hframes(const int p_hframes)
{
    // Prevent overflow of the frame counter
    if (p_hframes * vframes >= 256) {
        UtilityFunctions::printerr("Maximum number of frames reached 256!");
        return;
    }
    
    hframes = p_hframes;
    _clamp_frame();
    _frame_changed();
}
int NinePatchSprite2D::get_hframes() const
{
    return hframes;
}
void NinePatchSprite2D::set_vframes(const int p_vframes)
{
    // Prevent overflow of the frame counter
    if (hframes * p_vframes >= 256) {
        UtilityFunctions::printerr("Maximum number of frames reached 256!");
        return;
    }

    vframes = p_vframes;
    _clamp_frame();
    _frame_changed();
}
int NinePatchSprite2D::get_vframes() const
{
    return vframes;
}

void NinePatchSprite2D::set_frame(const int p_frame)
{
    frame = p_frame;
    _clamp_frame();
    _frame_changed();
}
int NinePatchSprite2D::get_frame() const
{
    return frame;
}