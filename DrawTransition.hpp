// don't ask why i do it in here bro

namespace DrawTransition {
   void Chams( ) {
     if ( settings::player::chams ) {
	    auto wireframe_material = UObject::FindObject<UMaterial>( "Material Wireframe_Mat.Wireframe_Mat" );
		//auto glass_material = UObject::FindObject<UMaterial>( "Material M_Metal_Chrome.M_Metal_Chrome" );
		wireframe_material->bDisableDepthTest = true;
		auto array = render::world->GameState->PlayerArray;
		for ( int32 i = 0; i < array.Num( ); i++ ) {
			auto players = array [ i ];
 
			auto mesh = players->PawnPrivate->Controller->Character->Mesh;
			if ( mesh ) {
				mesh->bOwnerNoSee = false;
				for ( int32 j = 0; j < mesh->GetNumMaterials( ); j++ ) {
					mesh->SetMaterial( j , wireframe_material );
				}
			}
 
  // weapon chams btw, the game im making my internal for, is a bit weird when it comes to their weapons
			auto & children = players->PawnPrivate->Controller->Character->Children;
			for ( int i = 0; i < children.Num( ); i++ ) {
				auto childactor = children [ i ];
				if ( !childactor ) continue;
 
				if ( childactor->IsA( Unreal::AWeapon_Base_C::StaticClass( ) ) ) {
					auto weapon = reinterpret_cast< Unreal::AWeapon_Base_C * >( childactor );
					if ( weapon->SkeletalMesh ) {
						weapon->SkeletalMesh->bOwnerNoSee = false;
 
						for ( int32 k = 0; k < weapon->SkeletalMesh->GetNumMaterials( ); k++ ) {
							weapon->SkeletalMesh->SetMaterial( k , wireframe_material );
						}
					}
				}
			}
		}
	}
   }
}
