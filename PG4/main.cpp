#include <map>
#include <utility>
#include <iostream>

int main() {
	enum class WeaponId {
		Handgun = 100,
		SubmachineGun = 300,
		RocketLauncher = 900,
	};
	std::map<WeaponId, int> weaponBulletCounts;

	// 武器の登録
	weaponBulletCounts[WeaponId::Handgun] = 12;
	weaponBulletCounts[WeaponId::SubmachineGun] = 30;
	weaponBulletCounts[WeaponId::RocketLauncher] = 5;

	// 発射処理
	const WeaponId selectedWeapon = WeaponId::RocketLauncher;
	std::map<WeaponId, int>::iterator itWeapon = weaponBulletCounts.find(selectedWeapon);

	if (itWeapon == weaponBulletCounts.end()) {
		std::cout << "Weapon not owned\n";
	} else if (itWeapon->second == 0) {
		std::cout << "Out of bullets\n";
	} else {
		--itWeapon->second;
		std::cout << "Fired\n";
	}

	// 一覧表示
	for (const std::pair<const WeaponId, int>& entry : weaponBulletCounts) {
		const WeaponId weaponId = entry.first;
		const int bulletCount = entry.second;
		std::cout << static_cast<int>(weaponId) << ": " << bulletCount << '\n';
	}

}